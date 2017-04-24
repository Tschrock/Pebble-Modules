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

#pragma once

#include <pebble.h>
#include "ts-indicators.h"

typedef struct ts_Indicator ts_BatteryIndicator;
  
//
// Indicator Functions
//
  
ts_BatteryIndicator * ts_indicator_battery_create(GRect bounds, ts_SpriteRes spritesheet, int numLevels);
ts_BatteryIndicator * ts_indicator_battery_create_and_add(GRect bounds, ts_SpriteRes spritesheet, int numLevels, Layer * layer);

ts_BatteryIndicator * ts_indicator_battery_create_easy(GRect bounds);  
ts_BatteryIndicator * ts_indicator_battery_create_easy_and_add(GRect bounds, Layer * layer);

void ts_indicator_battery_destroy(ts_BatteryIndicator* indicator);

void ts_indicator_battery_add_to_layer(ts_BatteryIndicator* indicator, Layer * layer);

void ts_indicator_battery_set_bounds(ts_BatteryIndicator* indicator, GRect position);
GRect ts_indicator_battery_get_bounds(ts_BatteryIndicator* indicator);

void ts_indicator_battery_update_state(ts_BatteryIndicator* indicator);
void ts_indicator_battery_set_battState(ts_BatteryIndicator* indicator, BatteryChargeState batState);
void ts_indicator_battery_set_state(ts_BatteryIndicator* indicator, int state);
int ts_indicator_battery_get_state(ts_BatteryIndicator* indicator);

int ts_indicator_battery_calcBattState(BatteryChargeState batState, int numLevels);