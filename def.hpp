#pragma once

#define SCREEN_WIDTH                768
#define SCREEN_HEIGHT               800
#define SPLASH_STATE_SHOW_TIME      3.0
#define PIPE_MOVE_SPEED             200.0f
#define PIPE_SPAWN_SPEED_FRECUENCY  0.5f
#define BIRD_ANIMATION_DURATION     0.4F
#define BIRD_STATE_STILL            1
#define BIRD_STATE_FALLING          2
#define BIRD_STATE_FLYING           3
#define GRAVITY                     350.0f
#define FLYING_SPEED                350.0f
#define FLYING_DURATION             0.25f
#define ROTATION_SPEED              100.0f


enum GameStates
{
   eReady,
   ePlaying,
   eGameOver
};



#define SPLASH_SCENE_BG_PATH "C:\\Aneury\\Flappy-bird-clone\\bin\\Debug\\Resources\\res\\Splash Background.png"
#define TITLE_SCENE_BG_PATH "C:\\Aneury\\Flappy-bird-clone\\bin\\Debug\\Resources\\res\\title.png"
#define PLAYBUTTON_PATH "C:\\Aneury\\Flappy-bird-clone\\bin\\Debug\\Resources\\res\\PlayButton.png"
#define MAIN_MENU_BACKGROUND "C:\\Aneury\\Flappy-bird-clone\\bin\\Debug\\Resources\\res\\background.png"
#define GAME_OVER_BACKGROUND "C:\\Aneury\\Flappy-bird-clone\\bin\\Debug\\Resources\\res\\background.png"
#define PIPE_UP "C:\\Aneury\\Flappy-bird-clone\\bin\\Debug\\Resources\\res\\PipeUp.png"
#define PIPE_DOWN "C:\\Aneury\\Flappy-bird-clone\\bin\\Debug\\Resources\\res\\PipeDown.png"
#define LAND_IMG "C:\\Aneury\\Flappy-bird-clone\\bin\\Debug\\Resources\\res\\Land.png"
#define BIRD_FRAME_1_PATH  "C:\\Aneury\\Flappy-bird-clone\\bin\\Debug\\Resources\\res\\bird-01.png"
#define BIRD_FRAME_2_PATH  "C:\\Aneury\\Flappy-bird-clone\\bin\\Debug\\Resources\\res\\bird-02.png"
#define BIRD_FRAME_3_PATH  "C:\\Aneury\\Flappy-bird-clone\\bin\\Debug\\Resources\\res\\bird-03.png"
#define BIRD_FRAME_4_PATH  "C:\\Aneury\\Flappy-bird-clone\\bin\\Debug\\Resources\\res\\bird-04.png"