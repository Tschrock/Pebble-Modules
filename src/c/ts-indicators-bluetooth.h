/**
  Pebble Indicators - Bluetooth
  Bluetooth indicator for a pebble app/watchface.

  Author: Tschrock (tschrock123@gmail.com)
  Version: 1.1 10/30/15
  Depends: ts-indicators, ts-common
  
  This Source Code Form is subject to the terms of the Mozilla Public
  License, v. 2.0. If a copy of the MPL was not distributed with this
  file, You can obtain one at http://mozilla.org/MPL/2.0/
*/

#pragma once

#include <pebble.h>
#include "ts-indicators.h"

typedef struct ts_Indicator ts_BluetoothIndicator;

//
// Indicator Functions
//
  
ts_BluetoothIndicator * ts_indicator_bluetooth_create(GRect bounds, ts_SpriteRes spritesheet);
ts_BluetoothIndicator * ts_indicator_bluetooth_create_and_add(GRect bounds, ts_SpriteRes spritesheet, Layer * layer);

ts_BluetoothIndicator * ts_indicator_bluetooth_create_easy(GRect bounds);  
ts_BluetoothIndicator * ts_indicator_bluetooth_create_easy_and_add(GRect bounds, Layer * layer);

void ts_indicator_bluetooth_destroy(ts_BluetoothIndicator* indicator);

void ts_indicator_bluetooth_add_to_layer(ts_BluetoothIndicator* indicator, Layer * layer);

void ts_indicator_bluetooth_set_bounds(ts_BluetoothIndicator* indicator, GRect position);
GRect ts_indicator_bluetooth_get_bounds(ts_BluetoothIndicator* indicator);

void ts_indicator_bluetooth_update_state(ts_BluetoothIndicator* indicator);
void ts_indicator_bluetooth_set_state(ts_BluetoothIndicator* indicator, bool state);
bool ts_indicator_bluetooth_get_state(ts_BluetoothIndicator* indicator);