#include "alien.hpp"
Texture2D Alien::images={};

Alien::Alien(Vector2 position)
{
    this -> position=position;
    if(images.id==0)
    {

    
    images=LoadTexture("graphics/alien.png");
    }
     newWidth = images.width * scaleFactor;
    newHeight = images.height * scaleFactor;

}



void Alien::Draw()
{
    DrawTextureEx(images, position, 0.0f, scaleFactor, WHITE);
}

void Alien::unload()
{
    UnloadTexture(images);
}

Rectangle Alien::getrect()
{
    return {position.x,position.y,float(newWidth),float(newHeight)};
}
