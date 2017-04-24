/**
  Pebble Indicators - Battery
  Battery indicator for a pebble app/watchface.

  Author: Tschrock (tschrock123@gmail.com)
  Version: 1.1 11/1/15
  
  This Source Code Form is subject to the terms of the Mozilla Public
  License, v. 2.0. If a copy of the MPL was not distributed with this
  file, You can obtain one at http://mozilla.org/MPL/2.0/
*/

#include <pebble.h>
#include "ts-clock.h"

ts_Clock * ts_clock_create(GRect bounds, GFont font, char seperator, char * buffer, bool showLeadingZero, bool is24HrFormat) {
  
  ts_Clock * clock = (ts_Clock*)malloc(sizeof(ts_Clock));
  
  clock->font = font;
  clock->seperator = seperator;
  clock->buffer = buffer;
  clock->showLeadingZero = showLeadingZero;
  clock->is24HrFormat = is24HrFormat;
  
  clock->rootLayer = layer_create(bounds);
  clock->timeLayer = text_layer_create(GRect(0, 0, bounds.size.w, bounds.size.h));
  
  text_layer_set_font(clock->timeLayer, font);
  text_layer_set_text_alignment(clock->timeLayer, GTextAlignmentCenter);
  
  layer_add_child(clock->rootLayer, text_layer_get_layer(clock->timeLayer));
  
  return clock;
}


ts_Clock * ts_clock_create_easy(GRect bounds, GFont font) {
  return ts_clock_create(bounds, font, ':', "00:00", true, clock_is_24h_style());
}


ts_Clock * ts_clock_create_and_add(GRect bounds, GFont font, char seperator, char * buffer, bool showLeadingZero, bool is24HrFormat, Layer * layer){
  ts_Clock * clock = ts_clock_create(bounds, font, seperator, buffer, showLeadingZero, is24HrFormat);
  ts_clock_add_to_layer(clock, layer);
  return clock;
}

ts_Clock * ts_clock_create_easy_and_add(GRect bounds, GFont font, Layer * layer){
  ts_Clock * clock = ts_clock_create_easy(bounds, font);
  ts_clock_add_to_layer(clock, layer);
  return clock;
}

void ts_clock_destroy(ts_Clock * clock){
  text_layer_destroy(clock->timeLayer);
  layer_destroy(clock->rootLayer);
  free(clock);
}

void ts_clock_add_to_layer(ts_Clock* clock, Layer * layer) {
  layer_add_child(layer, clock->rootLayer);
}

void ts_clock_set_seperator(ts_Clock * clock, char seperator) {
  clock->seperator = seperator;
  ts_clock_update_time(clock);
}

char ts_clock_get_seperator(ts_Clock * clock) {
  return clock->seperator;
}

void ts_clock_set_showLeadingZero(ts_Clock * clock, bool showLeadingZero) {
  clock->showLeadingZero = showLeadingZero;
  ts_clock_update_time(clock);
}

bool ts_clock_get_showLeadingZero(ts_Clock * clock) {
  return clock->showLeadingZero;
}

void ts_clock_set_is24HrFormat(ts_Clock * clock, bool is24HrFormat) {
  clock->is24HrFormat = is24HrFormat;
  ts_clock_update_time(clock);
}

bool ts_clock_get_is24HrFormat(ts_Clock * clock) {
  return clock->is24HrFormat;
}

void ts_clock_set_bounds(ts_Clock* clock, GRect bounds) {
  layer_set_bounds(clock->rootLayer, bounds);
  layer_set_bounds(text_layer_get_layer(clock->timeLayer), GRect(0, 0, bounds.size.w, bounds.size.h));
}

GRect ts_clock_get_bounds(ts_Clock* clock) {
  return layer_get_bounds(clock->rootLayer);
}

void ts_clock_update_time(ts_Clock* clock) {
  time_t temp = time(NULL); 
  struct tm *tick_time = localtime(&temp);
  ts_clock_set_time(clock, tick_time);
}


void ts_clock_set_time(ts_Clock* clock, struct tm * time) {
  static char formatBuffer[5];
  char hourFormat = clock->showLeadingZero ? (clock->is24HrFormat ? 'H' : 'I') : (clock->is24HrFormat ? 'k' : 'l');
  char minuteFormat = 'M';
  
  snprintf(formatBuffer, sizeof(formatBuffer), "%%%c%c%%%c", hourFormat, clock->seperator, minuteFormat);
  APP_LOG(APP_LOG_LEVEL_INFO, formatBuffer);
  
  strftime(
    clock->buffer,
    sizeof(clock->buffer), 
    formatBuffer,
    time
  );
  
  text_layer_set_text(clock->timeLayer, clock->buffer);
}

TextLayer * ts_clock_get_text_layer(ts_Clock* clock) {
  return clock->timeLayer;
}