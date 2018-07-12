#pragma once

#define SCREEN_WIDTH                768
#define SCREEN_HEIGHT               800
#define SPLASH_STATE_SHOW_TIME      3.0
#define PIPE_MOVE_SPEED             200.0f
#define PIPE_SPAWN_SPEED_FRECUENCY  1.5f
#define BIRD_ANIMATION_DURATION     0.4F
#define BIRD_STATE_STILL            1
#define BIRD_STATE_FALLING          2
#define BIRD_STATE_FLYING           3
#define GRAVITY                     350.0f
#define FLYING_SPEED                350.0f
#define FLYING_DURATION             0.25f
#define ROTATION_SPEED              100.0f
#define FLASH_SPEED                 1500.0F                  

enum GameStates
{
   eReady,
   ePlaying,
   eGameOver
};



#define SPLASH_SCENE_BG_PATH "\\Resources\\res\\Splash Background.png"
#define TITLE_SCENE_BG_PATH "\\Resources\\res\\title.png"
#define PLAYBUTTON_PATH "\\Resources\\res\\PlayButton.png"
#define MAIN_MENU_BACKGROUND "\\Resources\\res\\background.png"
#define GAME_OVER_BACKGROUND "\\Resources\\res\\background.png"
#define PIPE_UP "\\res\\PipeUp.png"
#define PIPE_DOWN "\\Resources\\res\\PipeDown.png"
#define LAND_IMG "\\Resources\\res\\Land.png"
#define BIRD_FRAME_1_PATH  "\\Resources\\res\\bird-01.png"
#define BIRD_FRAME_2_PATH  "\\Resources\\res\\bird-02.png"
#define BIRD_FRAME_3_PATH  "\\Resources\\res\\bird-03.png"
#define BIRD_FRAME_4_PATH  "\\Resources\\res\\bird-04.png"
#define GAME_OVER_MSG        "\\Resources\\res\\Game-Over-Title.png"
#define SCORE_PIPE_IMG  "\\Resources\\res\\InvisibleScoringPipe.png"
