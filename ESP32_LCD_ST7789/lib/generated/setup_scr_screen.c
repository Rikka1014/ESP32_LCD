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
    lv_obj_set_size(ui->screen, 240, 240);
    lv_obj_set_scrollbar_mode(ui->screen, LV_SCROLLBAR_MODE_OFF);

    //Write style for screen, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_label_1
    ui->screen_label_1 = lv_label_create(ui->screen);
    lv_obj_set_pos(ui->screen_label_1, 12, 10);
    lv_obj_set_size(ui->screen_label_1, 70, 35);
    lv_label_set_text(ui->screen_label_1, "TEMP\n");
    lv_label_set_long_mode(ui->screen_label_1, LV_LABEL_LONG_WRAP);

    //Write style for screen_label_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_label_1, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->screen_label_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->screen_label_1, lv_color_hex(0xf67500), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->screen_label_1, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_label_1, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_label_1, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_label_1, &lv_font_Antonio_Regular_25, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_label_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_label_1, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_label_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_label_1, lv_color_hex(0x2F35DA), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_label_1, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_label_1, 3, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_label_2
    ui->screen_label_2 = lv_label_create(ui->screen);
    lv_obj_set_pos(ui->screen_label_2, 12, 54);
    lv_obj_set_size(ui->screen_label_2, 70, 35);
    lv_label_set_text(ui->screen_label_2, "T-LOW");
    lv_label_set_long_mode(ui->screen_label_2, LV_LABEL_LONG_WRAP);

    //Write style for screen_label_2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_label_2, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->screen_label_2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->screen_label_2, lv_color_hex(0xf67500), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->screen_label_2, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_label_2, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_label_2, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_label_2, &lv_font_Antonio_Regular_25, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_label_2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_label_2, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_label_2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_label_2, lv_color_hex(0x2F35DA), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_label_2, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_label_2, 3, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_label_3
    ui->screen_label_3 = lv_label_create(ui->screen);
    lv_obj_set_pos(ui->screen_label_3, 12, 142);
    lv_obj_set_size(ui->screen_label_3, 70, 35);
    lv_label_set_text(ui->screen_label_3, "FAN");
    lv_label_set_long_mode(ui->screen_label_3, LV_LABEL_LONG_WRAP);

    //Write style for screen_label_3, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_label_3, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->screen_label_3, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->screen_label_3, lv_color_hex(0xf67500), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->screen_label_3, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_label_3, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_label_3, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_label_3, &lv_font_Antonio_Regular_25, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_label_3, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_label_3, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_label_3, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_label_3, lv_color_hex(0x2F35DA), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_label_3, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_label_3, 3, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_label_FAN_SPEED_VAL
    ui->screen_label_FAN_SPEED_VAL = lv_label_create(ui->screen);
    lv_obj_set_pos(ui->screen_label_FAN_SPEED_VAL, 92, 142);
    lv_obj_set_size(ui->screen_label_FAN_SPEED_VAL, 70, 31);
    lv_label_set_text(ui->screen_label_FAN_SPEED_VAL, "202 ");
    lv_label_set_long_mode(ui->screen_label_FAN_SPEED_VAL, LV_LABEL_LONG_WRAP);

    //Write style for screen_label_FAN_SPEED_VAL, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_label_FAN_SPEED_VAL, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_label_FAN_SPEED_VAL, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_label_FAN_SPEED_VAL, lv_color_hex(0xffdb00), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_label_FAN_SPEED_VAL, &lv_font_Antonio_Regular_28, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_label_FAN_SPEED_VAL, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_label_FAN_SPEED_VAL, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_label_FAN_SPEED_VAL, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_label_FAN_SPEED_VAL, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_label_FAN_SPEED_VAL, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_label_FAN_SPEED_VAL, 3, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_label_FAN_SPEED_VAL, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_label_FAN_SPEED_VAL, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_label_FAN_SPEED_VAL, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_label_FAN_SPEED_VAL, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_label_TEMP_LOW_VAL
    ui->screen_label_TEMP_LOW_VAL = lv_label_create(ui->screen);
    lv_obj_set_pos(ui->screen_label_TEMP_LOW_VAL, 88, 57);
    lv_obj_set_size(ui->screen_label_TEMP_LOW_VAL, 70, 31);
    lv_label_set_text(ui->screen_label_TEMP_LOW_VAL, "25.5°");
    lv_label_set_long_mode(ui->screen_label_TEMP_LOW_VAL, LV_LABEL_LONG_WRAP);

    //Write style for screen_label_TEMP_LOW_VAL, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_label_TEMP_LOW_VAL, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_label_TEMP_LOW_VAL, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_label_TEMP_LOW_VAL, lv_color_hex(0xffdb00), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_label_TEMP_LOW_VAL, &lv_font_Antonio_Regular_28, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_label_TEMP_LOW_VAL, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_label_TEMP_LOW_VAL, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_label_TEMP_LOW_VAL, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_label_TEMP_LOW_VAL, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_label_TEMP_LOW_VAL, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_label_TEMP_LOW_VAL, 3, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_label_TEMP_LOW_VAL, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_label_TEMP_LOW_VAL, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_label_TEMP_LOW_VAL, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_label_TEMP_LOW_VAL, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_label_TEMP_VAL
    ui->screen_label_TEMP_VAL = lv_label_create(ui->screen);
    lv_obj_set_pos(ui->screen_label_TEMP_VAL, 88, 13);
    lv_obj_set_size(ui->screen_label_TEMP_VAL, 70, 31);
    lv_label_set_text(ui->screen_label_TEMP_VAL, "30.5°");
    lv_label_set_long_mode(ui->screen_label_TEMP_VAL, LV_LABEL_LONG_WRAP);

    //Write style for screen_label_TEMP_VAL, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_label_TEMP_VAL, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_label_TEMP_VAL, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_label_TEMP_VAL, lv_color_hex(0xffdb00), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_label_TEMP_VAL, &lv_font_Antonio_Regular_28, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_label_TEMP_VAL, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_label_TEMP_VAL, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_label_TEMP_VAL, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_label_TEMP_VAL, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_label_TEMP_VAL, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_label_TEMP_VAL, 3, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_label_TEMP_VAL, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_label_TEMP_VAL, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_label_TEMP_VAL, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_label_TEMP_VAL, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_label_7
    ui->screen_label_7 = lv_label_create(ui->screen);
    lv_obj_set_pos(ui->screen_label_7, 162, 165);
    lv_obj_set_size(ui->screen_label_7, 25, 16);
    lv_label_set_text(ui->screen_label_7, "RPM");
    lv_label_set_long_mode(ui->screen_label_7, LV_LABEL_LONG_WRAP);

    //Write style for screen_label_7, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_label_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_label_7, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_label_7, lv_color_hex(0xffdb00), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_label_7, &lv_font_Antonio_Regular_12, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_label_7, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_label_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_label_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_label_7, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_label_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_label_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_label_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_label_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_label_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_label_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_btn_T_LOW_sub
    ui->screen_btn_T_LOW_sub = lv_button_create(ui->screen);
    lv_obj_set_pos(ui->screen_btn_T_LOW_sub, 165, 57);
    lv_obj_set_size(ui->screen_btn_T_LOW_sub, 30, 30);
    ui->screen_btn_T_LOW_sub_label = lv_label_create(ui->screen_btn_T_LOW_sub);
    lv_label_set_text(ui->screen_btn_T_LOW_sub_label, "-");
    lv_label_set_long_mode(ui->screen_btn_T_LOW_sub_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->screen_btn_T_LOW_sub_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->screen_btn_T_LOW_sub, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->screen_btn_T_LOW_sub_label, LV_PCT(100));

    //Write style for screen_btn_T_LOW_sub, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen_btn_T_LOW_sub, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_btn_T_LOW_sub, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_btn_T_LOW_sub, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->screen_btn_T_LOW_sub, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_btn_T_LOW_sub, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_btn_T_LOW_sub, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_color(ui->screen_btn_T_LOW_sub, lv_color_hex(0x909090), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_opa(ui->screen_btn_T_LOW_sub, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(ui->screen_btn_T_LOW_sub, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_offset_x(ui->screen_btn_T_LOW_sub, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_offset_y(ui->screen_btn_T_LOW_sub, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_btn_T_LOW_sub, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_btn_T_LOW_sub, &lv_font_Adventpro_regular_35, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_btn_T_LOW_sub, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_btn_T_LOW_sub, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_btn_T_LOW_add
    ui->screen_btn_T_LOW_add = lv_button_create(ui->screen);
    lv_obj_set_pos(ui->screen_btn_T_LOW_add, 204, 57);
    lv_obj_set_size(ui->screen_btn_T_LOW_add, 30, 30);
    ui->screen_btn_T_LOW_add_label = lv_label_create(ui->screen_btn_T_LOW_add);
    lv_label_set_text(ui->screen_btn_T_LOW_add_label, "+");
    lv_label_set_long_mode(ui->screen_btn_T_LOW_add_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->screen_btn_T_LOW_add_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->screen_btn_T_LOW_add, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->screen_btn_T_LOW_add_label, LV_PCT(100));

    //Write style for screen_btn_T_LOW_add, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen_btn_T_LOW_add, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_btn_T_LOW_add, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_btn_T_LOW_add, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->screen_btn_T_LOW_add, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_btn_T_LOW_add, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_btn_T_LOW_add, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_color(ui->screen_btn_T_LOW_add, lv_color_hex(0x909090), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_opa(ui->screen_btn_T_LOW_add, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(ui->screen_btn_T_LOW_add, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_offset_x(ui->screen_btn_T_LOW_add, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_offset_y(ui->screen_btn_T_LOW_add, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_btn_T_LOW_add, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_btn_T_LOW_add, &lv_font_Adventpro_regular_35, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_btn_T_LOW_add, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_btn_T_LOW_add, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_label_8
    ui->screen_label_8 = lv_label_create(ui->screen);
    lv_obj_set_pos(ui->screen_label_8, 12, 98);
    lv_obj_set_size(ui->screen_label_8, 70, 35);
    lv_label_set_text(ui->screen_label_8, "T-HIGH");
    lv_label_set_long_mode(ui->screen_label_8, LV_LABEL_LONG_WRAP);

    //Write style for screen_label_8, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_label_8, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->screen_label_8, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->screen_label_8, lv_color_hex(0xf67500), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->screen_label_8, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_label_8, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_label_8, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_label_8, &lv_font_Antonio_Regular_25, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_label_8, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_label_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_label_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_label_8, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_label_8, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_label_8, lv_color_hex(0x2F35DA), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_label_8, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_label_8, 3, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_label_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_label_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_label_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_label_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_label_TEMP_HIGH_VAL
    ui->screen_label_TEMP_HIGH_VAL = lv_label_create(ui->screen);
    lv_obj_set_pos(ui->screen_label_TEMP_HIGH_VAL, 88, 101);
    lv_obj_set_size(ui->screen_label_TEMP_HIGH_VAL, 70, 31);
    lv_label_set_text(ui->screen_label_TEMP_HIGH_VAL, "35.5°");
    lv_label_set_long_mode(ui->screen_label_TEMP_HIGH_VAL, LV_LABEL_LONG_WRAP);

    //Write style for screen_label_TEMP_HIGH_VAL, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_label_TEMP_HIGH_VAL, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_label_TEMP_HIGH_VAL, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_label_TEMP_HIGH_VAL, lv_color_hex(0xffdb00), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_label_TEMP_HIGH_VAL, &lv_font_Antonio_Regular_28, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_label_TEMP_HIGH_VAL, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_label_TEMP_HIGH_VAL, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_label_TEMP_HIGH_VAL, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_label_TEMP_HIGH_VAL, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_label_TEMP_HIGH_VAL, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_label_TEMP_HIGH_VAL, 3, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_label_TEMP_HIGH_VAL, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_label_TEMP_HIGH_VAL, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_label_TEMP_HIGH_VAL, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_label_TEMP_HIGH_VAL, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_btn_T_HIGH_add
    ui->screen_btn_T_HIGH_add = lv_button_create(ui->screen);
    lv_obj_set_pos(ui->screen_btn_T_HIGH_add, 204, 101);
    lv_obj_set_size(ui->screen_btn_T_HIGH_add, 30, 30);
    ui->screen_btn_T_HIGH_add_label = lv_label_create(ui->screen_btn_T_HIGH_add);
    lv_label_set_text(ui->screen_btn_T_HIGH_add_label, "+");
    lv_label_set_long_mode(ui->screen_btn_T_HIGH_add_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->screen_btn_T_HIGH_add_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->screen_btn_T_HIGH_add, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->screen_btn_T_HIGH_add_label, LV_PCT(100));

    //Write style for screen_btn_T_HIGH_add, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen_btn_T_HIGH_add, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_btn_T_HIGH_add, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_btn_T_HIGH_add, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->screen_btn_T_HIGH_add, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_btn_T_HIGH_add, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_btn_T_HIGH_add, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_color(ui->screen_btn_T_HIGH_add, lv_color_hex(0x909090), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_opa(ui->screen_btn_T_HIGH_add, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(ui->screen_btn_T_HIGH_add, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_offset_x(ui->screen_btn_T_HIGH_add, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_offset_y(ui->screen_btn_T_HIGH_add, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_btn_T_HIGH_add, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_btn_T_HIGH_add, &lv_font_Adventpro_regular_35, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_btn_T_HIGH_add, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_btn_T_HIGH_add, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_btn_T_HIGH_sub
    ui->screen_btn_T_HIGH_sub = lv_button_create(ui->screen);
    lv_obj_set_pos(ui->screen_btn_T_HIGH_sub, 165, 104);
    lv_obj_set_size(ui->screen_btn_T_HIGH_sub, 30, 30);
    ui->screen_btn_T_HIGH_sub_label = lv_label_create(ui->screen_btn_T_HIGH_sub);
    lv_label_set_text(ui->screen_btn_T_HIGH_sub_label, "-");
    lv_label_set_long_mode(ui->screen_btn_T_HIGH_sub_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->screen_btn_T_HIGH_sub_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->screen_btn_T_HIGH_sub, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->screen_btn_T_HIGH_sub_label, LV_PCT(100));

    //Write style for screen_btn_T_HIGH_sub, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen_btn_T_HIGH_sub, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_btn_T_HIGH_sub, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_btn_T_HIGH_sub, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->screen_btn_T_HIGH_sub, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_btn_T_HIGH_sub, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_btn_T_HIGH_sub, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_color(ui->screen_btn_T_HIGH_sub, lv_color_hex(0x909090), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_opa(ui->screen_btn_T_HIGH_sub, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(ui->screen_btn_T_HIGH_sub, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_offset_x(ui->screen_btn_T_HIGH_sub, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_offset_y(ui->screen_btn_T_HIGH_sub, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_btn_T_HIGH_sub, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_btn_T_HIGH_sub, &lv_font_Adventpro_regular_35, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_btn_T_HIGH_sub, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_btn_T_HIGH_sub, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_sw_MASTER_POWER
    ui->screen_sw_MASTER_POWER = lv_switch_create(ui->screen);
    lv_obj_set_pos(ui->screen_sw_MASTER_POWER, 16, 198);
    lv_obj_set_size(ui->screen_sw_MASTER_POWER, 40, 20);
    lv_obj_add_flag(ui->screen_sw_MASTER_POWER, LV_OBJ_FLAG_CLICK_FOCUSABLE);

    //Write style for screen_sw_MASTER_POWER, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen_sw_MASTER_POWER, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_sw_MASTER_POWER, lv_color_hex(0xe6e2e6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_sw_MASTER_POWER, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->screen_sw_MASTER_POWER, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_sw_MASTER_POWER, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_sw_MASTER_POWER, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for screen_sw_MASTER_POWER, Part: LV_PART_INDICATOR, State: LV_STATE_CHECKED.
    lv_obj_set_style_bg_opa(ui->screen_sw_MASTER_POWER, 255, LV_PART_INDICATOR|LV_STATE_CHECKED);
    lv_obj_set_style_bg_color(ui->screen_sw_MASTER_POWER, lv_color_hex(0x2195f6), LV_PART_INDICATOR|LV_STATE_CHECKED);
    lv_obj_set_style_bg_grad_dir(ui->screen_sw_MASTER_POWER, LV_GRAD_DIR_NONE, LV_PART_INDICATOR|LV_STATE_CHECKED);
    lv_obj_set_style_border_width(ui->screen_sw_MASTER_POWER, 0, LV_PART_INDICATOR|LV_STATE_CHECKED);

    //Write style for screen_sw_MASTER_POWER, Part: LV_PART_KNOB, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen_sw_MASTER_POWER, 255, LV_PART_KNOB|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_sw_MASTER_POWER, lv_color_hex(0xffffff), LV_PART_KNOB|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_sw_MASTER_POWER, LV_GRAD_DIR_NONE, LV_PART_KNOB|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->screen_sw_MASTER_POWER, 0, LV_PART_KNOB|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_sw_MASTER_POWER, 10, LV_PART_KNOB|LV_STATE_DEFAULT);

    //Write codes screen_led_NORMAL
    ui->screen_led_NORMAL = lv_led_create(ui->screen);
    lv_obj_set_pos(ui->screen_led_NORMAL, 195, 21);
    lv_obj_set_size(ui->screen_led_NORMAL, 9, 21);
    lv_obj_add_flag(ui->screen_led_NORMAL, LV_OBJ_FLAG_HIDDEN);
    lv_led_set_brightness(ui->screen_led_NORMAL, 255);
    lv_led_set_color(ui->screen_led_NORMAL, lv_color_hex(0x00ff2b));

    //Write codes screen_led_HEAT
    ui->screen_led_HEAT = lv_led_create(ui->screen);
    lv_obj_set_pos(ui->screen_led_HEAT, 172, 21);
    lv_obj_set_size(ui->screen_led_HEAT, 9, 21);
    lv_obj_add_flag(ui->screen_led_HEAT, LV_OBJ_FLAG_HIDDEN);
    lv_led_set_brightness(ui->screen_led_HEAT, 255);
    lv_led_set_color(ui->screen_led_HEAT, lv_color_hex(0xff0027));

    //Write codes screen_led_COOL
    ui->screen_led_COOL = lv_led_create(ui->screen);
    lv_obj_set_pos(ui->screen_led_COOL, 218, 21);
    lv_obj_set_size(ui->screen_led_COOL, 9, 21);
    lv_obj_add_flag(ui->screen_led_COOL, LV_OBJ_FLAG_HIDDEN);
    lv_led_set_brightness(ui->screen_led_COOL, 255);
    lv_led_set_color(ui->screen_led_COOL, lv_color_hex(0x00d2ff));


    //The custom code of screen.
    lv_group_add_obj(group0, ui->screen_btn_T_LOW_sub);
    lv_group_add_obj(group0, ui->screen_btn_T_LOW_add);
    lv_group_add_obj(group0, ui->screen_btn_T_HIGH_sub);
    lv_group_add_obj(group0, ui->screen_btn_T_HIGH_add);
    lv_group_add_obj(group0, ui->screen_sw_MASTER_POWER);
    lv_obj_add_state(ui->screen_sw_MASTER_POWER, LV_STATE_CHECKED);

    //Update current screen layout.
    lv_obj_update_layout(ui->screen);

    //Init events for screen.
    events_init_screen(ui);
}
