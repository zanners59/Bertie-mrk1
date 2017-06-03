
//Moving Bertie Demo
#include <Arduboy.h>
Arduboy arduboy;
int playerx = 5;
int playery = 10;
const unsigned char player [] PROGMEM = {
 0x00, 0x00, 0x00, 0x00, 0x80, 0x40, 0x40, 0x80, 0x70, 0x08, 0x04, 0x94, 0x48, 0x30, 0x30, 0x20,
0x10, 0x0c, 0x0a, 0xb1, 0xd0, 0x94, 0x94, 0x14, 0xb2, 0xd1, 0x88, 0x84, 0x03, 0x00, 0x00, 0x00, 
};
const unsigned char background[] PROGMEM  = {
};
void setup() {
  arduboy.begin();
  arduboy.clear();
}
void loop() {
  arduboy.clear();
  if(arduboy.pressed(LEFT_BUTTON)){
    playerx = playerx - 1;
  }
  if(arduboy.pressed(RIGHT_BUTTON)) {
      playerx = playerx + 1;
  }
  if(arduboy.pressed(UP_BUTTON)) {
     playery = playery - 1;
  }
  if(arduboy.pressed(DOWN_BUTTON)) {
    playery = playery +1;
  }
    //Draw black square
    arduboy.fillRect(playerx, playery, 16, 16, BLACK);
    //Draw player sprite
    arduboy.drawBitmap(playerx, playery, player, 16, 16, WHITE);
    arduboy.display();
  arduboy.drawBitmap(playerx, playery, player, 16, 16, WHITE);
  arduboy.display();
} 


