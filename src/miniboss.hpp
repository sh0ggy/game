#pragma once
#include <raylib.h>

class miniboss {
    public:
        miniboss();
        ~miniboss();
        void Update();
        void Draw();
        void Spawn();
        Rectangle getRect();
        bool alive;
        Vector2 position;
        
    private:
    Texture2D image;
        
        
        int speed;
        
};
