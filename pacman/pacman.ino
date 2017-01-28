#include <HT1632.h>
#include <images.h>

// Pacman
byte PACMAN1 [] = { 0b00001111, 0b10000000, 0b00111111, 0b11100000, 0b01111111, 0b11110000, 0b01111111, 0b11110000, 0b11111101, 0b11111000, 0b11111101, 0b11111000, 0b11111101, 0b11111000, 0b11111000, 0b11111000, 0b11111000, 0b11111000, 0b01111000, 0b11110000, 0b01110000, 0b01110000, 0b00110000, 0b01100000 };
byte PACMAN2 [] = { 0b00001111, 0b10000000, 0b00111111, 0b11100000, 0b01111111, 0b11110000, 0b01111111, 0b11110000, 0b11111101, 0b11111000, 0b11111000, 0b11111000, 0b11110000, 0b01111000, 0b11100000, 0b00111000, 0b11000000, 0b00011000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000 };
const uint8_t PACMAN_WIDTH = 12;
const uint8_t PACMAN_HEIGHT = 13;

byte * current;
uint8_t pacman_offset = -PACMAN_HEIGHT;
uint8_t frame = 1;
uint8_t channel = 0;


void setup() {
  HT1632.setCLK(D0);
  HT1632.begin(D1, D2, D3);
}

void loop() {
  if (pacman_offset > OUT_SIZE + PACMAN_WIDTH) {
    pacman_offset = -PACMAN_WIDTH;
  }
  HT1632.clear();
  frame = (frame + 1) % 2;
  current = frame == 0 ? PACMAN1 : PACMAN2;
  for (channel = 0; channel < 2; channel++) {
    HT1632.selectChannel(channel);
    HT1632.drawImage(current, PACMAN_WIDTH, PACMAN_HEIGHT, pacman_offset - PACMAN_WIDTH, 1);
  }
  HT1632.render();
  delay(200);
  pacman_offset = (pacman_offset + 1) % (PACMAN_WIDTH + OUT_SIZE);
}
