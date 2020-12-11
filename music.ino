#define E4 329.63
#define Fsharp4 369.99
#define A4 440
#define B4 493.88
#define C5 523.25
#define Csharp5 554.37
#define D5 587.33
#define E5 659.26
#define F5 698.46
#define Fsharp5 739.99
#define G5 783.99
#define A5 880
#define B5 987.77
#define C6 1046.5
#define D6 1174.66
#define E6 1318.51
#define A7 3520
#define BUZZER_CHANNEL 0

#include <Tone32.h>

// sheet music from https://www.youtube.com/watch?v=n5XrDwuomoE
void enterStationTune(int speaker) {
  // each line = 1 measure in 5/4 time
  double notes[40] = {
    A5, E5, A5, B5, E6, A7,
    Csharp5, E5, A4, B4, D5,
    Csharp5, E5, A4, B4, Fsharp5,
    Csharp5, E5, A4, B4, Fsharp4,
    E4,
    E5, G5, C5, D5, F5,
    E5, G5, C5, D5, A5,
    G5, C6, E5, F5, G5,
    E5, G5, E6
  };

  // note durations: 4 = quarter note, 8 = eighth note, etc.:
  double durations[40] = {
    8, 8, 8, 8, 4, 2,
    4, 4, 4, 4, 4,
    4, 4, 4, 4, 4,
    4, 4, 4, 4, 4,
    0.80,
    4, 4, 4, 4, 4,
    4, 4, 4, 4, 4,
    4, 4, 4, 4, 4,
    8, 8, 1
  };

  // adapted from https://www.arduino.cc/en/Tutorial/BuiltInExamples/toneMelody
  for (int i = 0; i < 40; i++) {
    double noteDuration = 1000 / durations[i];
    tone(speaker, notes[i], noteDuration, BUZZER_CHANNEL);
    delay(noteDuration * 0.30);
  }
}

void doorsClosing(int speaker) {
  // alarm sound
  double alarm = 4186.01;
  for (int i = 0; i < 13; i++) {
    digitalWrite(ledPins[curr_station], HIGH);
    tone(speaker, alarm, 90, BUZZER_CHANNEL);
    digitalWrite(ledPins[curr_station], LOW);
    delay(90 * 0.30);
  }
  delay(500);
  for (int i = 0; i < 13; i++) {
    digitalWrite(ledPins[curr_station], HIGH);
    tone(speaker, alarm, 90, BUZZER_CHANNEL);
    digitalWrite(ledPins[curr_station], LOW);
    delay(90 * 0.30);
  }

  delay(1000);

  double doors[7] = {D6, F5, D6, F5, D6, F5, D6};
  for (int i = 0; i < 7; i++) {
    if (i % 2 == 0) {
      digitalWrite(ledPins[curr_station], HIGH);
    } else {
      digitalWrite(ledPins[curr_station], LOW);
    }
    tone(speaker, doors[i], 600, BUZZER_CHANNEL);
    delay(600 * 0.30);
  }
}

// ESP32 does not have tone built in; solution = https://github.com/espressif/arduino-esp32/issues/1720
