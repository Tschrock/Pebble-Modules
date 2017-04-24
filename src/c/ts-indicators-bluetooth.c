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

#include <pebble.h>
#include "ts-indicators-bluetooth.h"


ts_BluetoothIndicator * ts_indicator_bluetooth_create(GRect bounds, ts_SpriteRes ssRes){
  return ts_indicator_create(bounds, ssRes, !bluetooth_connection_service_peek(), 2);
}

ts_BluetoothIndicator * ts_indicator_bluetooth_create_easy(GRect bounds) {
  #ifdef PBL_COLOR
    return ts_indicator_bluetooth_create(bounds, (ts_SpriteRes) {RESOURCE_ID_TS_INDICATOR_BLUETOOTH, GRect(0, 0, 13, 12)});
  #else
    return ts_indicator_bluetooth_create(bounds, (ts_SpriteRes) {RESOURCE_ID_TS_INDICATOR_BLUETOOTH_BLACK, RESOURCE_ID_TS_INDICATOR_BLUETOOTH_WHITE, GRect(0, 0, 13, 12)});
  #endif
}
ts_BluetoothIndicator * ts_indicator_bluetooth_create_easy_and_add(GRect bounds, Layer * layer){
  ts_BluetoothIndicator *  indic = ts_indicator_bluetooth_create_easy(bounds);
  ts_indicator_bluetooth_add_to_layer(indic, layer);
  return indic;
}

ts_BluetoothIndicator * ts_indicator_bluetooth_create_and_add(GRect bounds, ts_SpriteRes ssRes, Layer * layer){
  ts_BluetoothIndicator * indic = ts_indicator_bluetooth_create(bounds, ssRes);
  ts_indicator_bluetooth_add_to_layer(indic, layer);
  return indic;
}


void ts_indicator_bluetooth_destroy(ts_BluetoothIndicator* indicator) {
  ts_indicator_destroy(indicator);
}

void ts_indicator_bluetooth_add_to_layer(ts_BluetoothIndicator* indicator, Layer * layer){
  ts_indicator_add_to_layer(indicator, layer);
}

void ts_indicator_bluetooth_set_bounds(ts_BluetoothIndicator* indicator, GRect position) {
  ts_indicator_set_bounds(indicator, position);
}
GRect ts_indicator_bluetooth_get_bounds(ts_BluetoothIndicator* indicator) {
  return ts_indicator_get_bounds(indicator);
}

void ts_indicator_bluetooth_update_state(ts_BluetoothIndicator* indicator) {
  ts_indicator_set_state(indicator, !bluetooth_connection_service_peek());
}

void ts_indicator_bluetooth_set_state(ts_BluetoothIndicator* indicator, bool state){
  ts_indicator_set_state(indicator, !state);
}
bool ts_indicator_bluetooth_get_state(ts_BluetoothIndicator* indicator){
  return ts_indicator_get_state(indicator) == 0;
}