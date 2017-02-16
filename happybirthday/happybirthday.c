/*
 * Copyright (C) 2017 - Riccardo Finazzi, ITIS P.Hensemberger
 * Happy Birthday Theme Song for Arduino UNO tested on a 8ohm buzzer
 * 
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>
 */

#include "pitches.h"

// setup hw
int SPEAKER_PIN = 10;
int SPEAKER = SPEAKER_PIN;
// end of setuphw

// code related to the melody itself
#define NUM_OF_NOTES 28
int   NOTE_SEQ[NUM_OF_NOTES] = {
      NOTE_C5, NOTE_C5, NOTE_D5, NOTE_C5, NOTE_F5, NOTE_E5, PAUSE,
      NOTE_C5, NOTE_C5, NOTE_D5, NOTE_C5, NOTE_G5, NOTE_F5, PAUSE,
      NOTE_C5, NOTE_C5, NOTE_C6, NOTE_A5, NOTE_F5, NOTE_E5, NOTE_D5, PAUSE,
      NOTE_AS5, NOTE_AS5, NOTE_A5, NOTE_F5, NOTE_G5, NOTE_F5 };
/* 
 * beware that I choosed to reproduce pauses in milliseconds.
 */
int   NOTE_LEN[NUM_OF_NOTES]   = {
      4,2,8,8,8,16,   50,     //50  millis for the first pause
      4,2,8,8,8,16,   100,    //100 millis for the second pause
      4,2,8,8,8,8,16, 150,    //150 millis for the third pause
      4,2,8,8,8,20 };

/*
 * increase or reduce this value if you want to speed up or slow down the song.
 * This won't affect pause duration, which is defined in the array right above 
 * and expressed in milliseconds
 */
int   TEMPO = 65;

void playNote(int pitch,int duration) {
    tone( SPEAKER, pitch);
    delay( duration);
    noTone( SPEAKER);
}
// end of the code related to the melody itself

/*
 * arduino's standard setup() and loop() methods section. I had no need to repe
 * at so I put it in setup()
 */

void setup() {
    for (int i = 0; i < NUM_OF_NOTES; i++) {
        if ( NOTE_SEQ[i] != PAUSE) {
            playNote( NOTE_SEQ[i], NOTE_LEN[i] * TEMPO);
      // delay after note reproduction following TEMPO variable's diktat
            delay( TEMPO);
        } else {
            // delay if this is a pause. (it will be in millis, check NOTE_LEN)
            delay( NOTE_LEN[i]);
        }
    }
}

void loop() {
}
