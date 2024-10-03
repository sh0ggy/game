#include "playership.hpp"

playership::playership()
{
    image = LoadTexture("graphics/playership.png"); 
      newWidth = image.width * scaleFactor;
    newHeight = image.height * scaleFactor;
   
     
    position.x=(GetScreenWidth()-newWidth)/2;
    position.y=GetScreenHeight()-newHeight;
    lastfiretime=0.0;

}


playership::~playership()
{
    UnloadTexture(image);
}

void playership::draw()
{
    DrawTextureEx(image, position, 0.0f, scaleFactor, WHITE);
}
void playership::moveleft()
{
    position.x-=7;
    if(position.x<0)
    {
        position.x=0;
    }
   
}
void playership::moveright()
{
    position.x+=7;
     if(position.x>GetScreenWidth()-newWidth)
    {
        position.x=GetScreenWidth()-newWidth;
    }
}

void playership::fireLaser()
{
    if(GetTime()-lastfiretime>=0.30)
    {
    pewpew.push_back(Laser({position.x+newWidth/2-2, position.y},-6));
    lastfiretime=GetTime();
    }

}

Rectangle playership::getreact()
{

    return {position.x,position.y,float(newWidth),float(newHeight)};
}
