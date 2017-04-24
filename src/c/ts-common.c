/**
  Pebble Common
  Common functions and structures for a pebble app/watchface.

  Author: Tschrock (tschrock123@gmail.com)
  Version: 1.1 10/30/15
  
  This Source Code Form is subject to the terms of the Mozilla Public
  License, v. 2.0. If a copy of the MPL was not distributed with this
  file, You can obtain one at http://mozilla.org/MPL/2.0/
*/

#include <pebble.h>
#include "ts-common.h"

//
// Spritesheet functions
//

GBitmap* ts_common_getIconFromSheet(const GBitmap * iconSheet, const int xIndex, const int yIndex, const GRect iconSize) {
  return gbitmap_create_as_sub_bitmap(iconSheet, GRect(iconSize.origin.x + (xIndex * iconSize.size.w), iconSize.origin.y + (yIndex * iconSize.size.h), iconSize.size.w, iconSize.size.h));
}

void ts_common_swapSubBitmap(GBitmap ** oldBitmapPtr, GBitmap * newBitmap, BitmapLayer * bitmapLayer) {
  bitmap_layer_set_bitmap(bitmapLayer, newBitmap);  
  gbitmap_destroy(*oldBitmapPtr);
  *oldBitmapPtr = newBitmap;
}