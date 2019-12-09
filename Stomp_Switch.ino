/*
  Hands-Free Music Control

  Sends Play/Pause or Next keyboard command to control music

*/

// HID-Project - Version: Latest 
#include <HID-Project.h>
#include <HID-Settings.h>

const int playPause = 2;
const int next = 3;

void setup() {
  pinMode(playPause, INPUT_PULLUP);
  pinMode(next, INPUT_PULLUP);

  // Sends a clean report to the host. This is important on any Arduino type.
  Consumer.begin();
}

void loop() {
  
  if (!digitalRead(playPause)) {
    // Send the Play/Pause Command
    Consumer.write(MEDIA_PLAY_PAUSE);
    // Slight debounce
    delay(300);
    }

  if (!digitalRead(next)) {
    // Send the Next command
    Consumer.write(MEDIA_NEXT);
    // Slight debounce
    delay(300);
  }
}

