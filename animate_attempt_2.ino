//get bertie to animate
#include <Arduboy2.h>

int playerx = 5;
int playery = 10;
const unsigned char player [] PROGMEM =
{
  16, 16,
  0x00, 0x00, 0x00, 0x00, 0x80, 0x40, 0x40, 0x80, 0x70, 0x08, 0x04, 0x94, 0x48, 0x30, 0x30, 0x20,
0x10, 0x0c, 0x0a, 0xb1, 0xd0, 0x94, 0x94, 0x14, 0xb2, 0xd1, 0x88, 0x84, 0x03, 0x00, 0x00, 0x00, // still
  0x00, 0x00, 0x00, 0x00, 0x80, 0x40, 0x40, 0x80, 0x70, 0x08, 0x04, 0x94, 0x48, 0x30, 0x30, 0x20,
0x10, 0x8c, 0xca, 0xb1, 0x90, 0x14, 0x94, 0xd4, 0xb2, 0x91, 0x08, 0x04, 0x03, 0x00, 0x00, 0x00, // walk 1
0x00, 0x00, 0x00, 0x00, 0x80, 0x40, 0x40, 0x80, 0x70, 0x08, 0x04, 0x94, 0x48, 0x30, 0x30, 0x20,
0x10, 0x4c, 0xca, 0xb1, 0x90, 0x14, 0x14, 0x14, 0x32, 0xd1, 0x48, 0x24, 0x13, 0x00, 0x00, 0x00, // walk2
// fly 0x00, 0x60, 0x90, 0x10, 0x20, 0x30, 0x08, 0x10, 0x30, 0x08, 0x04, 0x94, 0x48, 0x70, 0xb0, 0x20,
0x06, 0x0c, 0x1a, 0x11, 0x10, 0x10, 0x10, 0x08, 0x04, 0x02, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00,  
};

Arduboy2 arduboy;
Sprites sprites;
byte frame = 0;


void setup()
{
  arduboy.begin();
  arduboy.clear();
  arduboy.setFrameRate(30);
}
void loop() {
  if (!(arduboy.nextFrame())) return;
  arduboy.clear();
  sprites.drawSelfMasked(0, 0, player, frame);
  if (arduboy.everyXFrames(3)) frame++;
  if (frame > 2) frame = 0;
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
   arduboy.display();
}

