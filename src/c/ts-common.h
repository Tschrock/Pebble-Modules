/**
  Pebble Common
  Common functions and structures for a pebble app/watchface.

  Author: Tschrock (tschrock123@gmail.com)
  Version: 1.1 10/30/15
  
  This Source Code Form is subject to the terms of the Mozilla Public
  License, v. 2.0. If a copy of the MPL was not distributed with this
  file, You can obtain one at http://mozilla.org/MPL/2.0/
*/

#pragma once

#include <pebble.h>

typedef struct ts_PngResourceId {
  uint32_t id;
  #ifdef PBL_BW
    uint32_t id2;
  #endif
} ts_PngResourceId;

typedef struct ts_SpriteRes {
  uint32_t id;
  #ifdef PBL_BW
    uint32_t id2;
  #endif
  GRect size;
} ts_SpriteRes;

GBitmap* ts_common_getIconFromSheet(const GBitmap * iconSheet, const int xIndex, const int yIndex, const GRect iconSize);
void ts_common_swapSubBitmap(GBitmap ** oldBitmapPtr, GBitmap * newBitmap, BitmapLayer * bitmapLayer);