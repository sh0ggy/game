#include<raylib.h>
#include "game.hpp"


int main()
{
    Color grey = {29, 29, 27, 255};
    int windowwidth =750;
    int windowheight =700;

    InitWindow(windowwidth,windowheight,"shooter game");
    SetTargetFPS(60);
    game game;
  

 
   

    
    while(WindowShouldClose()==false)
    {
        game.handleinput();
        game.update();
       

        BeginDrawing();
        ClearBackground(grey);
        game.draw();
        
      


        EndDrawing();
    }



    CloseWindow();
    
    }