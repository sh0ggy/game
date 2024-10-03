#pragma once

#include "playership.hpp"
#include "obstacle.hpp"
#include "alien.hpp"
#include "miniboss.hpp"
using namespace std;
class game{
    public:
        game();
        ~game();
        void draw();
        void update();
        void handleinput();

    private:
    void deletefinishedlasers();
    playership playership;
    vector<Alien> createaliens();
    void randalien();
    void checkforcollisions();
    void minishootlaser();
    obstacles obstacle;
    vector<Alien> aliens;
    vector<Laser> alienlasers;
    constexpr static float alieninterval=0.35;
    float lastlasertimealien;
    miniboss mini;
     float miniSpawnInterval;
        float timeLastSpawn;
 vector<Laser> minilasers;
 constexpr static float miniinterval=0.20;
    float lastlasertimemini;
    


    

};