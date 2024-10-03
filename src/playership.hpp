#pragma once
#include<raylib.h>
#include "laser.hpp"
#include <vector>

class playership{
    public:
            playership();
            ~playership();
            void draw();
            void moveleft();
            void moveright();
            void fireLaser();
            Rectangle getreact();
            std::vector<Laser> pewpew;


    private:
    Texture2D image;
    Vector2 position;
    float scaleFactor = 0.15f; 
    int newWidth ;
    int newHeight;
    double lastfiretime;
   


};