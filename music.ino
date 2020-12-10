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
    tone(speaker, notes[i], noteDuration);
    delay(noteDuration * 1.30);
    noTone(speaker);
  }
}

void doorsClosing(int speaker) {
  // alarm sound
  double alarm = 4186.01;
  for (int i = 0; i < 13; i++) {
    tone(speaker, alarm, 90);
    delay(90 * 1.30);
    noTone(speaker);
  }
  delay(500);
  for (int i = 0; i < 13; i++) {
    tone(speaker, alarm, 90);
    delay(90 * 1.30);
    noTone(speaker);
  }

  delay(1000);

  double doors[5] = {D6, F5, D6, F5, D6};
  for (int i = 0; i < 5; i++) {
    tone(speaker, doors[i], 600);
    delay(600 * 1.30);
    noTone(speaker);
  }
}

// ESP32 does not have tone built in; solution = https://github.com/espressif/arduino-esp32/issues/1720
