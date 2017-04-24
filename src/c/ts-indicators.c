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

#include <pebble.h>
#include "ts-indicators.h"


ts_Indicator * ts_indicator_create(GRect bounds, ts_SpriteRes ssRes, int startState, int numStates) {
  
  ts_Indicator *indicator = (ts_Indicator*)malloc(sizeof(ts_Indicator));
  
  indicator->currState = startState;
  indicator->numStates = numStates;
  indicator->spriteSize = ssRes.size;
  
  indicator->rootLayer = layer_create(bounds);
  
  indicator->bitmapLayer = bitmap_layer_create(GRect(0, 0, bounds.size.w, bounds.size.h));
  indicator->bitmap = gbitmap_create_with_resource(ssRes.id);
  indicator->subbitmap = ts_common_getIconFromSheet(indicator->bitmap, 0, indicator->currState, indicator->spriteSize);
  
  bitmap_layer_set_compositing_mode(indicator->bitmapLayer, GCompOpSet);
  bitmap_layer_set_bitmap(indicator->bitmapLayer, indicator->bitmap);
  
  layer_add_child(indicator->rootLayer, bitmap_layer_get_layer(indicator->bitmapLayer));
  
  #ifdef PBL_BW
    indicator->bitmapLayer2 = bitmap_layer_create(GRect(0, 0, bounds.size.w, bounds.size.h));
    indicator->bitmap2 = gbitmap_create_with_resource(ssRes.id2);
    indicator->subbitmap2 = ts_common_getIconFromSheet(indicator->bitmap, 0, indicator->currState, indicator->spriteSize);
    
    bitmap_layer_set_compositing_mode(indicator->bitmapLayer, GCompOpClear);  
    bitmap_layer_set_compositing_mode(indicator->bitmapLayer2, GCompOpOr);
    bitmap_layer_set_bitmap(indicator->bitmapLayer2, indicator->bitmap2);
    
    layer_add_child(indicator->rootLayer, bitmap_layer_get_layer(indicator->bitmapLayer2));
  #endif
  
  return indicator;
}


void ts_indicator_destroy(ts_Indicator* indicator) {
  
  bitmap_layer_destroy(indicator->bitmapLayer);
  gbitmap_destroy(indicator->bitmap);
  gbitmap_destroy(indicator->subbitmap);
  
  #ifdef PBL_BW
    bitmap_layer_destroy(indicator->bitmapLayer2);
    gbitmap_destroy(indicator->bitmap2);
    gbitmap_destroy(indicator->subbitmap2);
  #endif
  
  layer_destroy(indicator->rootLayer);
  
  free(indicator);
}


void ts_indicator_add_to_layer(ts_Indicator* indicator, Layer * layer) {
  layer_add_child(layer, indicator->rootLayer);
}




void ts_indicator_set_bounds(ts_Indicator* indicator, GRect bounds) {
  layer_set_bounds(indicator->rootLayer, bounds);
  layer_set_bounds(bitmap_layer_get_layer(indicator->bitmapLayer), GRect(0, 0, bounds.size.w, bounds.size.h));
  #ifdef PBL_BW
    layer_set_bounds(bitmap_layer_get_layer(indicator->bitmapLayer2), GRect(0, 0, bounds.size.w, bounds.size.h));
  #endif
}

GRect ts_indicator_get_bounds(ts_Indicator* indicator) {
  return layer_get_bounds(indicator->rootLayer);
}



void ts_indicator_set_state(ts_Indicator* indicator, int state) {
  indicator->currState = state;
  ts_common_swapSubBitmap(&(indicator->subbitmap), ts_common_getIconFromSheet(indicator->bitmap, 0, indicator->currState, indicator->spriteSize), indicator->bitmapLayer);
  #ifdef PBL_BW
    ts_common_swapSubBitmap(&(indicator->subbitmap2), ts_common_getIconFromSheet(indicator->bitmap2, 0, indicator->currState, indicator->spriteSize), indicator->bitmapLayer2);
  #endif
}

int ts_indicator_get_state(ts_Indicator* indicator) {
  return indicator->currState;
}