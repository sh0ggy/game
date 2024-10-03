#pragma once
#include <raylib.h>

class obstacles{
public:
obstacles();
~obstacles();
void InitObstacles();
void DrawObstacles();



private:
 int obstacleWidth ;
 int obstacleHeight ;
 int obstacleCount = 4;
 Rectangle* obstacle;


};