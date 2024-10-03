#include "miniboss.hpp"

miniboss::miniboss()
{
    image = LoadTexture("Graphics/mini2.png");
    
    alive = false;
}

miniboss::~miniboss() {
    UnloadTexture(image);
}

void miniboss::Spawn() {
    position.y = 20;
    int side = GetRandomValue(0, 1);

    if(side == 0) {
        position.x = 30;
        speed = 5;
    } else {
        position.x = GetScreenWidth() - image.width - 30;
        speed = -5;
    }
    alive = true;
}

Rectangle miniboss::getRect()
{
    if(alive){
        return {position.x, position.y, float(image.width), float(image.height)};
    } else {
        return {position.x, position.y, 0, 0};
    }
}

void miniboss::Update() {
    if(alive) {
        position.x += speed;
        if(position.x > GetScreenWidth() - image.width -30 || position.x < 30) {
            alive = false;
        }
    }
}

void miniboss::Draw() {
    if(alive) {
        DrawTextureV(image, position, WHITE);
    }
}