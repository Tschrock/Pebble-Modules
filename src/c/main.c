/**
  Pebble Modules Example
  Example watchface using ts-* modules

  Author: Tschrock (tschrock123@gmail.com)
  Version: 1.1 11/1/15
  
  This Source Code Form is subject to the terms of the Mozilla Public
  License, v. 2.0. If a copy of the MPL was not distributed with this
  file, You can obtain one at http://mozilla.org/MPL/2.0/
*/

#include <pebble.h>
#include "ts-indicators-bluetooth.h"
#include "ts-indicators-battery.h"
#include "ts-clock.h"

static Window *s_main_window;
static ts_BluetoothIndicator * blueIndicator;
static ts_BatteryIndicator * battIndicator;
static ts_Clock * theclock;

//
// Event Listeners
//

void onBluetoothUpdate(bool connected) {
  ts_indicator_bluetooth_set_state(blueIndicator, connected);
}

void onBatteryUpdate(BatteryChargeState batState){
  ts_indicator_battery_set_battState(battIndicator, batState);
}

//
// Window functions
//

static void main_window_load(Window *window) {
  blueIndicator =  ts_indicator_bluetooth_create_easy_and_add(GRect(3, 3, 13, 12), window_get_root_layer(window));
  ts_indicator_bluetooth_update_state(blueIndicator);
  
  battIndicator =  ts_indicator_battery_create_easy_and_add(GRect(123, 3, 17, 10), window_get_root_layer(window));
  ts_indicator_battery_update_state(battIndicator);
  
  theclock = ts_clock_create_easy_and_add(GRect(0, 110, 144, 50), fonts_load_custom_font(resource_get_handle(RESOURCE_ID_TS_CLOCK_FONT_42)), window_get_root_layer(window));
  ts_clock_set_seperator(theclock, ' ');
  ts_clock_update_time(theclock);
}

static void main_window_unload(Window *window) {
  ts_indicator_bluetooth_destroy(blueIndicator);
  ts_indicator_battery_destroy(battIndicator);
}


//
// Main App Setup/Loop
//
  
static void init() {
  s_main_window = window_create();
  
  window_set_window_handlers(s_main_window, (WindowHandlers) {
    .load = main_window_load,
    .unload = main_window_unload
  });

  bluetooth_connection_service_subscribe(onBluetoothUpdate);
  battery_state_service_subscribe(onBatteryUpdate);
  
  window_stack_push(s_main_window, true);
  
}

static void deinit() {
  window_destroy(s_main_window);
}
  
int main(void) {
  init();
  app_event_loop();
  deinit();
}