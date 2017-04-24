/**
  Pebble Indicators - Battery
  Battery indicator for a pebble app/watchface.

  Author: Tschrock (tschrock123@gmail.com)
  Version: 1.1 11/1/15
  Depends: ts-indicators, ts-common
  
  This Source Code Form is subject to the terms of the Mozilla Public
  License, v. 2.0. If a copy of the MPL was not distributed with this
  file, You can obtain one at http://mozilla.org/MPL/2.0/
*/

#include <pebble.h>
#include "ts-indicators-battery.h"

/*
  Battery States:
  0             => 0%
  ...
  numLevels-2   => 100%
  numLevels-1   => Charging
*/

ts_BatteryIndicator * ts_indicator_battery_create(GRect bounds, ts_SpriteRes ssRes, int numLevels){
  return ts_indicator_create(bounds, ssRes, ts_indicator_battery_calcBattState(battery_state_service_peek(), numLevels), numLevels);
}

ts_BatteryIndicator * ts_indicator_battery_create_easy(GRect bounds) {
  #ifdef PBL_COLOR
  return ts_indicator_battery_create(bounds, (ts_SpriteRes) {RESOURCE_ID_TS_INDICATOR_BATTERY, {{0, 0}, {17, 10}}}, 12);
  #else
    return ts_indicator_battery_create(bounds, (ts_SpriteRes) {RESOURCE_ID_TS_INDICATOR_BATTERY_BLACK, RESOURCE_ID_TS_INDICATOR_BATTERY_WHITE, {{0, 0}, {17, 10}}}, 12);
  #endif
}

ts_BatteryIndicator * ts_indicator_battery_create_easy_and_add(GRect bounds, Layer * layer){
  ts_BatteryIndicator *  indic = ts_indicator_battery_create_easy(bounds);
  ts_indicator_battery_add_to_layer(indic, layer);
  return indic;
}

ts_BatteryIndicator * ts_indicator_battery_create_and_add(GRect bounds, ts_SpriteRes ssRes, int numLevels, Layer * layer){
  ts_BatteryIndicator * indic = ts_indicator_battery_create(bounds, ssRes, numLevels);
  ts_indicator_battery_add_to_layer(indic, layer);
  return indic;
}

void ts_indicator_battery_destroy(ts_BatteryIndicator* indicator) {
  ts_indicator_destroy(indicator);
}

void ts_indicator_battery_add_to_layer(ts_BatteryIndicator* indicator, Layer * layer){
  ts_indicator_add_to_layer(indicator, layer);
}

void ts_indicator_battery_set_bounds(ts_BatteryIndicator* indicator, GRect position) {
  ts_indicator_set_bounds(indicator, position);
}
GRect ts_indicator_battery_get_bounds(ts_BatteryIndicator* indicator) {
  return ts_indicator_get_bounds(indicator);
}

void ts_indicator_battery_set_state(ts_BatteryIndicator* indicator, int state){
  ts_indicator_set_state(indicator, state);
}

void ts_indicator_battery_update_state(ts_BatteryIndicator* indicator) {
  ts_indicator_battery_set_battState(indicator, battery_state_service_peek());
}

void ts_indicator_battery_set_battState(ts_BatteryIndicator* indicator, BatteryChargeState batState){
  ts_indicator_set_state(indicator, ts_indicator_battery_calcBattState(batState, indicator->numStates));
}

int ts_indicator_battery_get_state(ts_BatteryIndicator* indicator){
  return ts_indicator_get_state(indicator);
}

int ts_indicator_battery_calcBattState(BatteryChargeState batState, int numLevels) {
  //assert(numLevels > 2);
  return batState.is_charging ? numLevels - 1 : batState.charge_percent / 100.0 * (numLevels - 2);
}