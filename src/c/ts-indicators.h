/**
  Pebble Indicators
  Indicators for a pebble app/watchface using spritesheets.

  Author: Tschrock (tschrock123@gmail.com)
  Version: 1.1 10/30/15
  Depends: ts-common
  
  This Source Code Form is subject to the terms of the Mozilla Public
  License, v. 2.0. If a copy of the MPL was not distributed with this
  file, You can obtain one at http://mozilla.org/MPL/2.0/
*/

#pragma once

#include <pebble.h>
#include "ts-common.h"

typedef struct ts_Indicator {
  int currState;
  int numStates;
  GRect spriteSize;
  
  Layer *rootLayer;

  BitmapLayer *bitmapLayer;
  GBitmap *bitmap;
  GBitmap *subbitmap;
  #ifdef PBL_BW
    BitmapLayer *bitmapLayer2;
    GBitmap *bitmap2;
    GBitmap *subbitmap2;
  #endif
} ts_Indicator;

//
// Indicator Functions
//

ts_Indicator * ts_indicator_create(GRect bounds, ts_SpriteRes ssRes, int startState, int numStates);
void ts_indicator_destroy(ts_Indicator* indicator);

void ts_indicator_add_to_layer(ts_Indicator* indicator, Layer * layer);

void ts_indicator_set_bounds(ts_Indicator* indicator, GRect position);
GRect ts_indicator_get_bounds(ts_Indicator* indicator);

void ts_indicator_set_state(ts_Indicator* indicator, int state);
int ts_indicator_get_state(ts_Indicator* indicator);