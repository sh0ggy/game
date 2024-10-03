#include "obstacle.hpp"
#include <iostream>

obstacles::obstacles()
{
     obstacleWidth=70;
      obstacleHeight=50;
       obstacleCount=4;
     obstacle = new Rectangle[obstacleCount];  // Allocate memory for obstacles
      InitObstacles();
}

obstacles::~obstacles()
{
    delete[] obstacle;  // Free allocated memory
}

void obstacles::InitObstacles()
{
// Calculate spacing between obstacles
    int spaceBetweenObstacles = (GetScreenWidth()- obstacleCount * obstacleWidth) / (obstacleCount + 1);

    // Initialize obstacle positions
    for (int i = 0; i < obstacleCount; i++) {
        obstacle[i].width = obstacleWidth;
        obstacle[i].height = obstacleHeight;
        obstacle[i].x = spaceBetweenObstacles + i * (obstacleWidth + spaceBetweenObstacles);
        obstacle[i].y = GetScreenHeight() / 2 - obstacleHeight / 2+200;
    }
}

void obstacles::DrawObstacles()
{
     for (int i = 0; i < obstacleCount; i++) {
        DrawRectangleRec(obstacle[i], DARKGRAY);
    }
}


