/*
* Copyright 2025 NXP
* NXP Proprietary. This software is owned or controlled by NXP and may only be used strictly in
* accordance with the applicable license terms. By expressly accepting such terms or by downloading, installing,
* activating and/or otherwise using the software, you are agreeing that you have read, and that you agree to
* comply with and are bound by, such license terms.  If you do not agree to be bound by the applicable license
* terms, then you may not retain, install, activate or otherwise use the software.
*/

#include "lvgl.h"
#include <stdio.h>
#include "gui_guider.h"
#include "events_init.h"
#include "widgets_init.h"
#include "custom.h"



void setup_scr_screen(lv_ui *ui)
{
    //Write codes screen
    ui->screen = lv_obj_create(NULL);
    lv_obj_set_size(ui->screen, 128, 128);
    lv_obj_set_scrollbar_mode(ui->screen, LV_SCROLLBAR_MODE_OFF);

    //Write style for screen, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_label_1
    ui->screen_label_1 = lv_label_create(ui->screen);
    lv_obj_set_pos(ui->screen_label_1, 4, 4);
    lv_obj_set_size(ui->screen_label_1, 46, 36);
    lv_label_set_text(ui->screen_label_1, "T");
    lv_label_set_long_mode(ui->screen_label_1, LV_LABEL_LONG_WRAP);

    //Write style for screen_label_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_label_1, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->screen_label_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->screen_label_1, lv_color_hex(0xff9600), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->screen_label_1, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_label_1, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_label_1, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_label_1, &lv_font_Alatsi_Regular_27, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_label_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_label_1, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_label_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_label_1, lv_color_hex(0x2F35DA), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_label_1, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_label_1, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_label_1, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_label_2
    ui->screen_label_2 = lv_label_create(ui->screen);
    lv_obj_set_pos(ui->screen_label_2, 4, 46);
    lv_obj_set_size(ui->screen_label_2, 46, 36);
    lv_label_set_text(ui->screen_label_2, "T-SET");
    lv_label_set_long_mode(ui->screen_label_2, LV_LABEL_LONG_WRAP);

    //Write style for screen_label_2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_label_2, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->screen_label_2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->screen_label_2, lv_color_hex(0xff9600), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->screen_label_2, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_label_2, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_label_2, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_label_2, &lv_font_Antonio_Regular_21, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_label_2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_label_2, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_label_2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_label_2, lv_color_hex(0x2F35DA), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_label_2, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_label_2, 7, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_label_2, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_label_
    ui->screen_label_ = lv_label_create(ui->screen);
    lv_obj_set_pos(ui->screen_label_, 4, 88);
    lv_obj_set_size(ui->screen_label_, 46, 36);
    lv_label_set_text(ui->screen_label_, "FAN");
    lv_label_set_long_mode(ui->screen_label_, LV_LABEL_LONG_WRAP);

    //Write style for screen_label_, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_label_, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->screen_label_, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->screen_label_, lv_color_hex(0xff9600), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->screen_label_, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_label_, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_label_, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_label_, &lv_font_Antonio_Regular_21, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_label_, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_label_, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_label_, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_label_, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_label_, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_label_, lv_color_hex(0x2F35DA), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_label_, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_label_, 6, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_label_, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_label_, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_label_, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_label_, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_label_T_value
    ui->screen_label_T_value = lv_label_create(ui->screen);
    lv_obj_set_pos(ui->screen_label_T_value, 55, 4);
    lv_obj_set_size(ui->screen_label_T_value, 68, 36);
    lv_label_set_text(ui->screen_label_T_value, "00.0°");
    lv_label_set_long_mode(ui->screen_label_T_value, LV_LABEL_LONG_WRAP);

    //Write style for screen_label_T_value, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_label_T_value, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->screen_label_T_value, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->screen_label_T_value, lv_color_hex(0xf3ff00), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->screen_label_T_value, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_label_T_value, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_label_T_value, lv_color_hex(0xfaff23), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_label_T_value, &lv_font_Adventpro_regular_25, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_label_T_value, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_label_T_value, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_label_T_value, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_label_T_value, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_label_T_value, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_label_T_value, lv_color_hex(0x2F35DA), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_label_T_value, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_label_T_value, 3, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_label_T_value, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_label_T_value, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_label_T_value, 4, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_label_T_value, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_label_T_SET_value
    ui->screen_label_T_SET_value = lv_label_create(ui->screen);
    lv_obj_set_pos(ui->screen_label_T_SET_value, 68, 46);
    lv_obj_set_size(ui->screen_label_T_SET_value, 42, 36);
    lv_label_set_text(ui->screen_label_T_SET_value, "16.8°");
    lv_label_set_long_mode(ui->screen_label_T_SET_value, LV_LABEL_LONG_WRAP);

    //Write style for screen_label_T_SET_value, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_label_T_SET_value, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->screen_label_T_SET_value, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->screen_label_T_SET_value, lv_color_hex(0xf3ff00), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->screen_label_T_SET_value, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_label_T_SET_value, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_label_T_SET_value, lv_color_hex(0xfaff23), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_label_T_SET_value, &lv_font_Adventpro_regular_18, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_label_T_SET_value, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_label_T_SET_value, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_label_T_SET_value, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_label_T_SET_value, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_label_T_SET_value, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_label_T_SET_value, lv_color_hex(0x2F35DA), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_label_T_SET_value, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_label_T_SET_value, 6, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_label_T_SET_value, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_label_T_SET_value, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_label_T_SET_value, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_label_T_SET_value, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_label_FAN_value
    ui->screen_label_FAN_value = lv_label_create(ui->screen);
    lv_obj_set_pos(ui->screen_label_FAN_value, 55, 88);
    lv_obj_set_size(ui->screen_label_FAN_value, 68, 36);
    lv_label_set_text(ui->screen_label_FAN_value, "520r");
    lv_label_set_long_mode(ui->screen_label_FAN_value, LV_LABEL_LONG_WRAP);

    //Write style for screen_label_FAN_value, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_label_FAN_value, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->screen_label_FAN_value, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->screen_label_FAN_value, lv_color_hex(0xf3ff00), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->screen_label_FAN_value, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_label_FAN_value, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_label_FAN_value, lv_color_hex(0xfaff23), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_label_FAN_value, &lv_font_Adventpro_regular_24, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_label_FAN_value, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_label_FAN_value, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_label_FAN_value, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_label_FAN_value, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_label_FAN_value, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_label_FAN_value, lv_color_hex(0x2F35DA), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_label_FAN_value, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_label_FAN_value, 3, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_label_FAN_value, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_label_FAN_value, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_label_FAN_value, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_label_FAN_value, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_btn_1
    ui->screen_btn_1 = lv_button_create(ui->screen);
    lv_obj_set_pos(ui->screen_btn_1, 55, 46);
    lv_obj_set_size(ui->screen_btn_1, 10, 36);
    ui->screen_btn_1_label = lv_label_create(ui->screen_btn_1);
    lv_label_set_text(ui->screen_btn_1_label, "-");
    lv_label_set_long_mode(ui->screen_btn_1_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->screen_btn_1_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->screen_btn_1, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->screen_btn_1_label, LV_PCT(100));

    //Write style for screen_btn_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen_btn_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_btn_1, lv_color_hex(0x2F92DA), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_btn_1, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->screen_btn_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_btn_1, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_btn_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_btn_1, lv_color_hex(0xfafafa), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_btn_1, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_btn_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_btn_1, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_btn_2
    ui->screen_btn_2 = lv_button_create(ui->screen);
    lv_obj_set_pos(ui->screen_btn_2, 113, 46);
    lv_obj_set_size(ui->screen_btn_2, 10, 36);
    ui->screen_btn_2_label = lv_label_create(ui->screen_btn_2);
    lv_label_set_text(ui->screen_btn_2_label, "+");
    lv_label_set_long_mode(ui->screen_btn_2_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->screen_btn_2_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->screen_btn_2, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->screen_btn_2_label, LV_PCT(100));

    //Write style for screen_btn_2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen_btn_2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_btn_2, lv_color_hex(0x2F92DA), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_btn_2, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->screen_btn_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_btn_2, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_btn_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_btn_2, lv_color_hex(0xfafafa), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_btn_2, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_btn_2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_btn_2, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //The custom code of screen.


    //Update current screen layout.
    lv_obj_update_layout(ui->screen);

}
