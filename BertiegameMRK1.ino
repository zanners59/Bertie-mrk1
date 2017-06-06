
#include"BITMAP.H"
#include <Arduboy2.h>
Arduboy2 arduboy;


//Variables declared here
int spritestate = 0;
int playerX = 5;
int playerY = 10;
int justpressed = 0;
boolean playeriswalking = false;
boolean playerisjumping = false;
boolean playerisstill = false;
boolean playerisflying = false;

enum {
  STAND_STILL,
  WALK_RIGHT,
  FLY_RIGHT,
  JUMP
};


Sprites sprite;
byte frame = 0;

void setup() {
  arduboy.begin();
  //Set-up here
  arduboy.clear();
  arduboy.setFrameRate(30);
}
void loop() {
  if (!(arduboy.nextFrame())) return;
  arduboy.clear();
  sprite.drawSelfMasked(playerX, playerY, Bertie_idle_R , frame);
  if (arduboy.everyXFrames(3)) frame++;
  spritestate = STAND_STILL;
  if (arduboy.justPressed(RIGHT_BUTTON)) {
    playeriswalking = true;
    playerX --;
    if (arduboy.justPressed(B_BUTTON) and (RIGHT_BUTTON)) {
      playerY--;
      spritestate = FLY_RIGHT;
      playerisflying = true;
    }
    else spritestate = WALK_RIGHT;
    playeriswalking = true;
  }
  //else if JUMP AND WALK LEFT
  if (arduboy.justPressed(B_BUTTON)) {
    playerY--;
    spritestate = JUMP;
    playerisflying = true;
  }
  switch (spritestate) {
    case STAND_STILL :
      sprite.drawPlusMask(playerX, playerY, Bertie_idle_R, frame );
      playerisstill = true;
      break;
    case WALK_RIGHT:
      sprite.drawPlusMask(playerX, playerY, Bertie_walk_animated_R, frame);
      playeriswalking = true;
      break;
    case FLY_RIGHT:
      sprite.drawPlusMask(playerX, playerY, Bertie_fly_animate_R, frame);
      playerisflying = true;
      //case walk left&jumpleft

  }
}


