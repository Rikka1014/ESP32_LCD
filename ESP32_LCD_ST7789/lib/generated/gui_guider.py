# Copyright 2025 NXP
# NXP Proprietary. This software is owned or controlled by NXP and may only be used strictly in
# accordance with the applicable license terms. By expressly accepting such terms or by downloading, installing,
# activating and/or otherwise using the software, you are agreeing that you have read, and that you agree to
# comply with and are bound by, such license terms.  If you do not agree to be bound by the applicable license
# terms, then you may not retain, install, activate or otherwise use the software.

import utime as time
import usys as sys
import lvgl as lv
import ustruct
import fs_driver

lv.init()

# Register display driver.
disp_drv = lv.sdl_window_create(240, 240)
lv.sdl_window_set_resizeable(disp_drv, False)
lv.sdl_window_set_title(disp_drv, "Simulator (MicroPython)")

# Regsiter input driver
mouse = lv.sdl_mouse_create()

# Add default theme for bottom layer
bottom_layer = lv.layer_bottom()
lv.theme_apply(bottom_layer)

fs_drv = lv.fs_drv_t()
fs_driver.fs_register(fs_drv, 'Z')

def anim_x_cb(obj, v):
    obj.set_x(v)

def anim_y_cb(obj, v):
    obj.set_y(v)

def anim_width_cb(obj, v):
    obj.set_width(v)

def anim_height_cb(obj, v):
    obj.set_height(v)

def anim_img_zoom_cb(obj, v):
    obj.set_scale(v)

def anim_img_rotate_cb(obj, v):
    obj.set_rotation(v)

global_font_cache = {}
def test_font(font_family, font_size):
    global global_font_cache
    if font_family + str(font_size) in global_font_cache:
        return global_font_cache[font_family + str(font_size)]
    if font_size % 2:
        candidates = [
            (font_family, font_size),
            (font_family, font_size-font_size%2),
            (font_family, font_size+font_size%2),
            ("montserrat", font_size-font_size%2),
            ("montserrat", font_size+font_size%2),
            ("montserrat", 16)
        ]
    else:
        candidates = [
            (font_family, font_size),
            ("montserrat", font_size),
            ("montserrat", 16)
        ]
    for (family, size) in candidates:
        try:
            if eval(f'lv.font_{family}_{size}'):
                global_font_cache[font_family + str(font_size)] = eval(f'lv.font_{family}_{size}')
                if family != font_family or size != font_size:
                    print(f'WARNING: lv.font_{family}_{size} is used!')
                return eval(f'lv.font_{family}_{size}')
        except AttributeError:
            try:
                load_font = lv.binfont_create(f"Z:MicroPython/lv_font_{family}_{size}.fnt")
                global_font_cache[font_family + str(font_size)] = load_font
                return load_font
            except:
                if family == font_family and size == font_size:
                    print(f'WARNING: lv.font_{family}_{size} is NOT supported!')

global_image_cache = {}
def load_image(file):
    global global_image_cache
    if file in global_image_cache:
        return global_image_cache[file]
    try:
        with open(file,'rb') as f:
            data = f.read()
    except:
        print(f'Could not open {file}')
        sys.exit()

    img = lv.image_dsc_t({
        'data_size': len(data),
        'data': data
    })
    global_image_cache[file] = img
    return img

def calendar_event_handler(e,obj):
    code = e.get_code()

    if code == lv.EVENT.VALUE_CHANGED:
        source = lv.calendar.__cast__(e.get_current_target())
        date = lv.calendar_date_t()
        if source.get_pressed_date(date) == lv.RESULT.OK:
            source.set_highlighted_dates([date], 1)

def spinbox_increment_event_cb(e, obj):
    code = e.get_code()
    if code == lv.EVENT.SHORT_CLICKED or code == lv.EVENT.LONG_PRESSED_REPEAT:
        obj.increment()
def spinbox_decrement_event_cb(e, obj):
    code = e.get_code()
    if code == lv.EVENT.SHORT_CLICKED or code == lv.EVENT.LONG_PRESSED_REPEAT:
        obj.decrement()

def digital_clock_cb(timer, obj, current_time, show_second, use_ampm):
    hour = int(current_time[0])
    minute = int(current_time[1])
    second = int(current_time[2])
    ampm = current_time[3]
    second = second + 1
    if second == 60:
        second = 0
        minute = minute + 1
        if minute == 60:
            minute = 0
            hour = hour + 1
            if use_ampm:
                if hour == 12:
                    if ampm == 'AM':
                        ampm = 'PM'
                    elif ampm == 'PM':
                        ampm = 'AM'
                if hour > 12:
                    hour = hour % 12
    hour = hour % 24
    if use_ampm:
        if show_second:
            obj.set_text("%d:%02d:%02d %s" %(hour, minute, second, ampm))
        else:
            obj.set_text("%d:%02d %s" %(hour, minute, ampm))
    else:
        if show_second:
            obj.set_text("%d:%02d:%02d" %(hour, minute, second))
        else:
            obj.set_text("%d:%02d" %(hour, minute))
    current_time[0] = hour
    current_time[1] = minute
    current_time[2] = second
    current_time[3] = ampm

def analog_clock_cb(timer, obj):
    datetime = time.localtime()
    hour = datetime[3]
    if hour >= 12: hour = hour - 12
    obj.set_time(hour, datetime[4], datetime[5])

def datetext_event_handler(e, obj):
    code = e.get_code()
    datetext = lv.label.__cast__(e.get_target())
    if code == lv.EVENT.FOCUSED:
        if obj is None:
            bg = lv.layer_top()
            bg.add_flag(lv.obj.FLAG.CLICKABLE)
            obj = lv.calendar(bg)
            scr = lv.screen_active()
            scr_height = scr.get_height()
            scr_width = scr.get_width()
            obj.set_size(int(scr_width * 0.8), int(scr_height * 0.8))
            datestring = datetext.get_text()
            year = int(datestring.split('/')[0])
            month = int(datestring.split('/')[1])
            day = int(datestring.split('/')[2])
            obj.set_showed_date(year, month)
            highlighted_days=[lv.calendar_date_t({'year':year, 'month':month, 'day':day})]
            obj.set_highlighted_dates(highlighted_days, 1)
            obj.align(lv.ALIGN.CENTER, 0, 0)
            lv.calendar_header_arrow(obj)
            obj.add_event_cb(lambda e: datetext_calendar_event_handler(e, datetext), lv.EVENT.ALL, None)
            scr.update_layout()

def datetext_calendar_event_handler(e, obj):
    code = e.get_code()
    calendar = lv.calendar.__cast__(e.get_current_target())
    if code == lv.EVENT.VALUE_CHANGED:
        date = lv.calendar_date_t()
        if calendar.get_pressed_date(date) == lv.RESULT.OK:
            obj.set_text(f"{date.year}/{date.month}/{date.day}")
            bg = lv.layer_top()
            bg.remove_flag(lv.obj.FLAG.CLICKABLE)
            bg.set_style_bg_opa(lv.OPA.TRANSP, 0)
            calendar.delete()

# Create screen_0
screen_0 = lv.obj()
screen_0.set_size(240, 240)
screen_0.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
# Set style for screen_0, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
screen_0.set_style_bg_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_0.set_style_bg_color(lv.color_hex(0x000000), lv.PART.MAIN|lv.STATE.DEFAULT)
screen_0.set_style_bg_grad_dir(lv.GRAD_DIR.NONE, lv.PART.MAIN|lv.STATE.DEFAULT)

# Create screen_0_label_1
screen_0_label_1 = lv.label(screen_0)
screen_0_label_1.set_text("CPU")
screen_0_label_1.set_long_mode(lv.label.LONG.WRAP)
screen_0_label_1.set_width(lv.pct(100))
screen_0_label_1.set_pos(13, 14)
screen_0_label_1.set_size(79, 32)
# Set style for screen_0_label_1, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
screen_0_label_1.set_style_border_width(3, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_0_label_1.set_style_border_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_0_label_1.set_style_border_color(lv.color_hex(0xfb934f), lv.PART.MAIN|lv.STATE.DEFAULT)
screen_0_label_1.set_style_border_side(lv.BORDER_SIDE.FULL, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_0_label_1.set_style_radius(10, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_0_label_1.set_style_text_color(lv.color_hex(0xffffff), lv.PART.MAIN|lv.STATE.DEFAULT)
screen_0_label_1.set_style_text_font(test_font("Abel_regular", 24), lv.PART.MAIN|lv.STATE.DEFAULT)
screen_0_label_1.set_style_text_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_0_label_1.set_style_text_letter_space(0, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_0_label_1.set_style_text_line_space(0, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_0_label_1.set_style_text_align(lv.TEXT_ALIGN.CENTER, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_0_label_1.set_style_bg_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_0_label_1.set_style_bg_color(lv.color_hex(0x27b3fb), lv.PART.MAIN|lv.STATE.DEFAULT)
screen_0_label_1.set_style_bg_grad_dir(lv.GRAD_DIR.NONE, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_0_label_1.set_style_pad_top(1, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_0_label_1.set_style_pad_right(0, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_0_label_1.set_style_pad_bottom(0, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_0_label_1.set_style_pad_left(0, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_0_label_1.set_style_shadow_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)

# Create screen_0_label_2
screen_0_label_2 = lv.label(screen_0)
screen_0_label_2.set_text("GPU")
screen_0_label_2.set_long_mode(lv.label.LONG.WRAP)
screen_0_label_2.set_width(lv.pct(100))
screen_0_label_2.set_pos(13, 50)
screen_0_label_2.set_size(79, 32)
# Set style for screen_0_label_2, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
screen_0_label_2.set_style_border_width(3, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_0_label_2.set_style_border_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_0_label_2.set_style_border_color(lv.color_hex(0xfb934f), lv.PART.MAIN|lv.STATE.DEFAULT)
screen_0_label_2.set_style_border_side(lv.BORDER_SIDE.FULL, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_0_label_2.set_style_radius(10, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_0_label_2.set_style_text_color(lv.color_hex(0xffffff), lv.PART.MAIN|lv.STATE.DEFAULT)
screen_0_label_2.set_style_text_font(test_font("Abel_regular", 24), lv.PART.MAIN|lv.STATE.DEFAULT)
screen_0_label_2.set_style_text_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_0_label_2.set_style_text_letter_space(0, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_0_label_2.set_style_text_line_space(0, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_0_label_2.set_style_text_align(lv.TEXT_ALIGN.CENTER, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_0_label_2.set_style_bg_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_0_label_2.set_style_bg_color(lv.color_hex(0x27b3fb), lv.PART.MAIN|lv.STATE.DEFAULT)
screen_0_label_2.set_style_bg_grad_dir(lv.GRAD_DIR.NONE, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_0_label_2.set_style_pad_top(1, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_0_label_2.set_style_pad_right(0, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_0_label_2.set_style_pad_bottom(0, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_0_label_2.set_style_pad_left(0, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_0_label_2.set_style_shadow_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)

# Create screen_0_label_3
screen_0_label_3 = lv.label(screen_0)
screen_0_label_3.set_text("RAM")
screen_0_label_3.set_long_mode(lv.label.LONG.WRAP)
screen_0_label_3.set_width(lv.pct(100))
screen_0_label_3.set_pos(13, 86)
screen_0_label_3.set_size(79, 32)
# Set style for screen_0_label_3, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
screen_0_label_3.set_style_border_width(3, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_0_label_3.set_style_border_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_0_label_3.set_style_border_color(lv.color_hex(0xfb934f), lv.PART.MAIN|lv.STATE.DEFAULT)
screen_0_label_3.set_style_border_side(lv.BORDER_SIDE.FULL, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_0_label_3.set_style_radius(10, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_0_label_3.set_style_text_color(lv.color_hex(0xffffff), lv.PART.MAIN|lv.STATE.DEFAULT)
screen_0_label_3.set_style_text_font(test_font("Abel_regular", 24), lv.PART.MAIN|lv.STATE.DEFAULT)
screen_0_label_3.set_style_text_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_0_label_3.set_style_text_letter_space(0, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_0_label_3.set_style_text_line_space(0, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_0_label_3.set_style_text_align(lv.TEXT_ALIGN.CENTER, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_0_label_3.set_style_bg_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_0_label_3.set_style_bg_color(lv.color_hex(0x27b3fb), lv.PART.MAIN|lv.STATE.DEFAULT)
screen_0_label_3.set_style_bg_grad_dir(lv.GRAD_DIR.NONE, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_0_label_3.set_style_pad_top(1, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_0_label_3.set_style_pad_right(0, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_0_label_3.set_style_pad_bottom(0, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_0_label_3.set_style_pad_left(0, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_0_label_3.set_style_shadow_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)

# Create screen_0_label_cpu
screen_0_label_cpu = lv.label(screen_0)
screen_0_label_cpu.set_text("Label")
screen_0_label_cpu.set_long_mode(lv.label.LONG.WRAP)
screen_0_label_cpu.set_width(lv.pct(100))
screen_0_label_cpu.set_pos(112, 14)
screen_0_label_cpu.set_size(100, 30)
# Set style for screen_0_label_cpu, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
screen_0_label_cpu.set_style_border_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_0_label_cpu.set_style_radius(0, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_0_label_cpu.set_style_text_color(lv.color_hex(0xf9ffb6), lv.PART.MAIN|lv.STATE.DEFAULT)
screen_0_label_cpu.set_style_text_font(test_font("Antonio_Regular", 26), lv.PART.MAIN|lv.STATE.DEFAULT)
screen_0_label_cpu.set_style_text_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_0_label_cpu.set_style_text_letter_space(0, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_0_label_cpu.set_style_text_line_space(0, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_0_label_cpu.set_style_text_align(lv.TEXT_ALIGN.CENTER, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_0_label_cpu.set_style_bg_opa(0, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_0_label_cpu.set_style_pad_top(3, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_0_label_cpu.set_style_pad_right(0, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_0_label_cpu.set_style_pad_bottom(0, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_0_label_cpu.set_style_pad_left(0, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_0_label_cpu.set_style_shadow_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)

# Create screen_0_label_gpu
screen_0_label_gpu = lv.label(screen_0)
screen_0_label_gpu.set_text("Label")
screen_0_label_gpu.set_long_mode(lv.label.LONG.WRAP)
screen_0_label_gpu.set_width(lv.pct(100))
screen_0_label_gpu.set_pos(112, 50)
screen_0_label_gpu.set_size(100, 30)
# Set style for screen_0_label_gpu, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
screen_0_label_gpu.set_style_border_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_0_label_gpu.set_style_radius(0, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_0_label_gpu.set_style_text_color(lv.color_hex(0xf9ffb6), lv.PART.MAIN|lv.STATE.DEFAULT)
screen_0_label_gpu.set_style_text_font(test_font("Antonio_Regular", 26), lv.PART.MAIN|lv.STATE.DEFAULT)
screen_0_label_gpu.set_style_text_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_0_label_gpu.set_style_text_letter_space(0, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_0_label_gpu.set_style_text_line_space(0, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_0_label_gpu.set_style_text_align(lv.TEXT_ALIGN.CENTER, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_0_label_gpu.set_style_bg_opa(0, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_0_label_gpu.set_style_pad_top(3, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_0_label_gpu.set_style_pad_right(0, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_0_label_gpu.set_style_pad_bottom(0, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_0_label_gpu.set_style_pad_left(0, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_0_label_gpu.set_style_shadow_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)

# Create screen_0_label_ram
screen_0_label_ram = lv.label(screen_0)
screen_0_label_ram.set_text("Label")
screen_0_label_ram.set_long_mode(lv.label.LONG.WRAP)
screen_0_label_ram.set_width(lv.pct(100))
screen_0_label_ram.set_pos(112, 86)
screen_0_label_ram.set_size(100, 30)
# Set style for screen_0_label_ram, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
screen_0_label_ram.set_style_border_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_0_label_ram.set_style_radius(0, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_0_label_ram.set_style_text_color(lv.color_hex(0xf9ffb6), lv.PART.MAIN|lv.STATE.DEFAULT)
screen_0_label_ram.set_style_text_font(test_font("Antonio_Regular", 26), lv.PART.MAIN|lv.STATE.DEFAULT)
screen_0_label_ram.set_style_text_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_0_label_ram.set_style_text_letter_space(0, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_0_label_ram.set_style_text_line_space(0, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_0_label_ram.set_style_text_align(lv.TEXT_ALIGN.CENTER, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_0_label_ram.set_style_bg_opa(0, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_0_label_ram.set_style_pad_top(3, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_0_label_ram.set_style_pad_right(0, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_0_label_ram.set_style_pad_bottom(0, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_0_label_ram.set_style_pad_left(0, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_0_label_ram.set_style_shadow_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)

# Create screen_0_label_log
screen_0_label_log = lv.label(screen_0)
screen_0_label_log.set_text("Label")
screen_0_label_log.set_long_mode(lv.label.LONG.WRAP)
screen_0_label_log.set_width(lv.pct(100))
screen_0_label_log.set_pos(13, 165)
screen_0_label_log.set_size(214, 63)
# Set style for screen_0_label_log, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
screen_0_label_log.set_style_border_width(2, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_0_label_log.set_style_border_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_0_label_log.set_style_border_color(lv.color_hex(0x2195f6), lv.PART.MAIN|lv.STATE.DEFAULT)
screen_0_label_log.set_style_border_side(lv.BORDER_SIDE.FULL, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_0_label_log.set_style_radius(0, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_0_label_log.set_style_text_color(lv.color_hex(0xD01FBB), lv.PART.MAIN|lv.STATE.DEFAULT)
screen_0_label_log.set_style_text_font(test_font("montserratMedium", 16), lv.PART.MAIN|lv.STATE.DEFAULT)
screen_0_label_log.set_style_text_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_0_label_log.set_style_text_letter_space(0, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_0_label_log.set_style_text_line_space(0, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_0_label_log.set_style_text_align(lv.TEXT_ALIGN.CENTER, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_0_label_log.set_style_bg_opa(0, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_0_label_log.set_style_pad_top(23, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_0_label_log.set_style_pad_right(0, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_0_label_log.set_style_pad_bottom(0, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_0_label_log.set_style_pad_left(0, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_0_label_log.set_style_shadow_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)

# Create screen_0_label_FAN
screen_0_label_FAN = lv.label(screen_0)
screen_0_label_FAN.set_text("FAN")
screen_0_label_FAN.set_long_mode(lv.label.LONG.WRAP)
screen_0_label_FAN.set_width(lv.pct(100))
screen_0_label_FAN.set_pos(13, 122)
screen_0_label_FAN.set_size(79, 32)
# Set style for screen_0_label_FAN, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
screen_0_label_FAN.set_style_border_width(3, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_0_label_FAN.set_style_border_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_0_label_FAN.set_style_border_color(lv.color_hex(0xfb934f), lv.PART.MAIN|lv.STATE.DEFAULT)
screen_0_label_FAN.set_style_border_side(lv.BORDER_SIDE.FULL, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_0_label_FAN.set_style_radius(10, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_0_label_FAN.set_style_text_color(lv.color_hex(0xffffff), lv.PART.MAIN|lv.STATE.DEFAULT)
screen_0_label_FAN.set_style_text_font(test_font("Abel_regular", 24), lv.PART.MAIN|lv.STATE.DEFAULT)
screen_0_label_FAN.set_style_text_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_0_label_FAN.set_style_text_letter_space(0, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_0_label_FAN.set_style_text_line_space(0, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_0_label_FAN.set_style_text_align(lv.TEXT_ALIGN.CENTER, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_0_label_FAN.set_style_bg_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_0_label_FAN.set_style_bg_color(lv.color_hex(0x27b3fb), lv.PART.MAIN|lv.STATE.DEFAULT)
screen_0_label_FAN.set_style_bg_grad_dir(lv.GRAD_DIR.NONE, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_0_label_FAN.set_style_pad_top(1, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_0_label_FAN.set_style_pad_right(0, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_0_label_FAN.set_style_pad_bottom(0, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_0_label_FAN.set_style_pad_left(0, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_0_label_FAN.set_style_shadow_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)

# Create screen_0_label_fan
screen_0_label_fan = lv.label(screen_0)
screen_0_label_fan.set_text("Label")
screen_0_label_fan.set_long_mode(lv.label.LONG.WRAP)
screen_0_label_fan.set_width(lv.pct(100))
screen_0_label_fan.set_pos(112, 122)
screen_0_label_fan.set_size(100, 30)
# Set style for screen_0_label_fan, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
screen_0_label_fan.set_style_border_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_0_label_fan.set_style_radius(0, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_0_label_fan.set_style_text_color(lv.color_hex(0xf9ffb6), lv.PART.MAIN|lv.STATE.DEFAULT)
screen_0_label_fan.set_style_text_font(test_font("Antonio_Regular", 26), lv.PART.MAIN|lv.STATE.DEFAULT)
screen_0_label_fan.set_style_text_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_0_label_fan.set_style_text_letter_space(0, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_0_label_fan.set_style_text_line_space(0, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_0_label_fan.set_style_text_align(lv.TEXT_ALIGN.CENTER, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_0_label_fan.set_style_bg_opa(0, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_0_label_fan.set_style_pad_top(3, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_0_label_fan.set_style_pad_right(0, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_0_label_fan.set_style_pad_bottom(0, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_0_label_fan.set_style_pad_left(0, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_0_label_fan.set_style_shadow_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)

# Create screen_0_btn_1
screen_0_btn_1 = lv.button(screen_0)
screen_0_btn_1_label = lv.label(screen_0_btn_1)
screen_0_btn_1_label.set_text("Button")
screen_0_btn_1_label.set_long_mode(lv.label.LONG.WRAP)
screen_0_btn_1_label.set_width(lv.pct(100))
screen_0_btn_1_label.align(lv.ALIGN.CENTER, 0, 0)
screen_0_btn_1.set_style_pad_all(0, lv.STATE.DEFAULT)
screen_0_btn_1.set_pos(180, 128)
screen_0_btn_1.set_size(55, 29)
# Set style for screen_0_btn_1, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
screen_0_btn_1.set_style_bg_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_0_btn_1.set_style_bg_color(lv.color_hex(0x2195f6), lv.PART.MAIN|lv.STATE.DEFAULT)
screen_0_btn_1.set_style_bg_grad_dir(lv.GRAD_DIR.NONE, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_0_btn_1.set_style_border_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_0_btn_1.set_style_radius(5, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_0_btn_1.set_style_shadow_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_0_btn_1.set_style_text_color(lv.color_hex(0xffffff), lv.PART.MAIN|lv.STATE.DEFAULT)
screen_0_btn_1.set_style_text_font(test_font("montserratMedium", 16), lv.PART.MAIN|lv.STATE.DEFAULT)
screen_0_btn_1.set_style_text_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_0_btn_1.set_style_text_align(lv.TEXT_ALIGN.CENTER, lv.PART.MAIN|lv.STATE.DEFAULT)

screen_0.update_layout()
# Create screen_1
screen_1 = lv.obj()
screen_1.set_size(240, 240)
screen_1.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
# Set style for screen_1, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
screen_1.set_style_bg_opa(254, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_1.set_style_bg_color(lv.color_hex(0x2FDAAE), lv.PART.MAIN|lv.STATE.DEFAULT)
screen_1.set_style_bg_grad_dir(lv.GRAD_DIR.NONE, lv.PART.MAIN|lv.STATE.DEFAULT)

# Create screen_1_label_1
screen_1_label_1 = lv.label(screen_1)
screen_1_label_1.set_text("HAha")
screen_1_label_1.set_long_mode(lv.label.LONG.WRAP)
screen_1_label_1.set_width(lv.pct(100))
screen_1_label_1.set_pos(71, 49)
screen_1_label_1.set_size(100, 32)
# Set style for screen_1_label_1, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
screen_1_label_1.set_style_border_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_1_label_1.set_style_radius(0, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_1_label_1.set_style_text_color(lv.color_hex(0x000000), lv.PART.MAIN|lv.STATE.DEFAULT)
screen_1_label_1.set_style_text_font(test_font("montserratMedium", 16), lv.PART.MAIN|lv.STATE.DEFAULT)
screen_1_label_1.set_style_text_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_1_label_1.set_style_text_letter_space(0, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_1_label_1.set_style_text_line_space(0, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_1_label_1.set_style_text_align(lv.TEXT_ALIGN.CENTER, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_1_label_1.set_style_bg_opa(0, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_1_label_1.set_style_pad_top(0, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_1_label_1.set_style_pad_right(0, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_1_label_1.set_style_pad_bottom(0, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_1_label_1.set_style_pad_left(0, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_1_label_1.set_style_shadow_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)

screen_1.update_layout()

def screen_0_event_handler(e):
    code = e.get_code()
    if (code == lv.EVENT.KEY):
        pass
        lv.screen_load_anim(screen_1, lv.SCR_LOAD_ANIM.NONE, 200, 200, False)
    if (code == lv.EVENT.CLICKED):
        pass
screen_0.add_event_cb(lambda e: screen_0_event_handler(e), lv.EVENT.ALL, None)

def screen_1_event_handler(e):
    code = e.get_code()
    if (code == lv.EVENT.KEY):
        pass
        lv.screen_load_anim(screen_0, lv.SCR_LOAD_ANIM.NONE, 200, 200, False)
screen_1.add_event_cb(lambda e: screen_1_event_handler(e), lv.EVENT.ALL, None)

# content from custom.py

# Load the default screen
lv.screen_load(screen_0)

if __name__ == '__main__':
    while True:
        lv.task_handler()
        time.sleep_ms(5)
