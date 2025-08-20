/*
* Copyright 2025 NXP
* NXP Proprietary. This software is owned or controlled by NXP and may only be used strictly in
* accordance with the applicable license terms. By expressly accepting such terms or by downloading, installing,
* activating and/or otherwise using the software, you are agreeing that you have read, and that you agree to
* comply with and are bound by, such license terms.  If you do not agree to be bound by the applicable license
* terms, then you may not retain, install, activate or otherwise use the software.
*/

#include "events_init.h"

#include <Arduino.h>
#include <stdio.h>
#include "lvgl.h"
#include "temperature.h"
#include "power_switch.h"

#if LV_USE_GUIDER_SIMULATOR && LV_USE_FREEMASTER
#include "freemaster_client.h"
#endif


static void screen_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_KEY:
    {
        break;
    }
    case LV_EVENT_CLICKED:
    {
        break;
    }
    default:
        break;
    }
}

static void screen_btn_T_LOW_sub_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    case LV_EVENT_LONG_PRESSED_REPEAT:
    {
        set_temperature_set_low(get_temperature_set_low() - 0.5f);
        lv_label_set_text_fmt(guider_ui.screen_label_TEMP_LOW_VAL, "%.1f°", get_temperature_set_low());
        break;
    }
    default:
        break;
    }
}

static void screen_btn_T_LOW_add_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    case LV_EVENT_LONG_PRESSED_REPEAT:
    {
        set_temperature_set_low(get_temperature_set_low() + 0.5f);
        lv_label_set_text_fmt(guider_ui.screen_label_TEMP_LOW_VAL, "%.1f°", get_temperature_set_low());
        break;
    }
    default:
        break;
    }
}

static void screen_btn_T_HIGH_sub_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    case LV_EVENT_LONG_PRESSED_REPEAT:
    {
        set_temperature_set_high(get_temperature_set_high() - 0.5f);
        lv_label_set_text_fmt(guider_ui.screen_label_TEMP_HIGH_VAL, "%.1f°", get_temperature_set_high());
        break;
    }
    default:
        break;
    }
}

static void screen_btn_T_HIGH_add_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    case LV_EVENT_LONG_PRESSED_REPEAT:
    {
        set_temperature_set_high(get_temperature_set_high() + 0.5f);
        lv_label_set_text_fmt(guider_ui.screen_label_TEMP_HIGH_VAL, "%.1f°", get_temperature_set_high());
        break;
    }
    default:
        break;
    }
}

static void screen_sw_MASTER_POWER_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_VALUE_CHANGED:
    {
        lv_obj_t * status_obj = lv_event_get_target(e);
        bool status = lv_obj_has_state(status_obj, LV_STATE_CHECKED) ? true : false;
        power_switch_set_master(status);
        break;
    }
    default:
        break;
    }
}

void events_init_screen (lv_ui *ui)
{
    lv_obj_add_event_cb(ui->screen, screen_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->screen_btn_T_LOW_sub, screen_btn_T_LOW_sub_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->screen_btn_T_LOW_add, screen_btn_T_LOW_add_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->screen_btn_T_HIGH_sub, screen_btn_T_HIGH_sub_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->screen_btn_T_HIGH_add, screen_btn_T_HIGH_add_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->screen_sw_MASTER_POWER, screen_sw_MASTER_POWER_event_handler, LV_EVENT_ALL, ui);
}


void events_init(lv_ui *ui)
{

}
