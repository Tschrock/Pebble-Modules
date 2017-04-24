/**
  Pebble Clock
  Clock for a pebble app/watchface.

  Author: Tschrock (tschrock123@gmail.com)
  Version: 1.1 11/1/15
  
  This Source Code Form is subject to the terms of the Mozilla Public
  License, v. 2.0. If a copy of the MPL was not distributed with this
  file, You can obtain one at http://mozilla.org/MPL/2.0/
*/

#pragma once

typedef struct ts_Clock {
  ResHandle font;
  char seperator;
  char * buffer;
  bool showLeadingZero;
  bool is24HrFormat;
  
  Layer * rootLayer;
  TextLayer *timeLayer;
} ts_Clock;


ts_Clock * ts_clock_create(GRect bounds, GFont font, char seperator, char * buffer, bool showLeadingZero, bool is24HrFormat);
ts_Clock * ts_clock_create_easy(GRect bounds, GFont font);

ts_Clock * ts_clock_create_and_add(GRect bounds, GFont font, char seperator, char * buffer, bool showLeadingZero, bool is24HrFormat, Layer * layer);
ts_Clock * ts_clock_create_easy_and_add(GRect bounds, GFont font, Layer * layer);


void ts_clock_destroy(ts_Clock * clock);

void ts_clock_add_to_layer(ts_Clock* clock, Layer * layer);

void ts_clock_set_seperator(ts_Clock * clock, char seperator);
char ts_clock_get_seperator(ts_Clock * clock);

void ts_clock_set_showLeadingZero(ts_Clock * clock, bool showLeadingZero);
bool ts_clock_get_showLeadingZero(ts_Clock * clock);

void ts_clock_set_is24HrFormat(ts_Clock * clock, bool is24HrFormat);
bool ts_clock_get_is24HrFormat(ts_Clock * clock);

void ts_clock_set_bounds(ts_Clock* clock, GRect bounds);
GRect ts_clock_get_bounds(ts_Clock* clock);

void ts_clock_update_time(ts_Clock* clock);
void ts_clock_set_time(ts_Clock* clock, struct tm * time);

TextLayer * ts_clock_get_text_layer(ts_Clock* clock);