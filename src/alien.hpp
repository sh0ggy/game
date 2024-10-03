#pragma once
#include <raylib.h>

class Alien {
    public:
        Alien( Vector2 position);
        

        void Update(int direction);
        void Draw();
        static Texture2D images;
        static void unload();
        Vector2 position;
        float scaleFactor = 0.10f; 
        Rectangle getrect();
    int newWidth ;
    int newHeight;
   

private:

};