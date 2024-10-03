#include "game.hpp"
#include <iostream>
using namespace std;



game::game()
{
   aliens=createaliens(); 
   lastlasertimealien=0;
   timeLastSpawn=0;
   lastlasertimemini=0;
   miniSpawnInterval=GetRandomValue(2,4);
  
    
}
game::~game()
{
    Alien::unload();

}
void game::update()
{
    double currtime= GetTime();
    if(currtime-timeLastSpawn>miniSpawnInterval)
    {
        mini.Spawn();
        timeLastSpawn=GetTime();
         miniSpawnInterval=GetRandomValue(7,12);

    }
    mini.Update();
    for(auto& laser: playership.pewpew)
    {
        laser.update();
    }
    randalien();
    for(auto& laser: alienlasers)
    {
        laser.update();
    }
    minishootlaser();
    for(auto& laser: minilasers)
    {
        laser.update();
    }
    
    deletefinishedlasers();
   
    checkforcollisions();
}
void game::draw()
{
    playership.draw();
    mini.Draw();
    for(auto& laser: playership.pewpew)
    {
        laser.draw();
    }
    obstacle.DrawObstacles();
    for(auto& alien: aliens)
    {
        alien.Draw();
    }
    for(auto& laser: alienlasers)
    {
        laser.draw();
    }
     for(auto& laser: minilasers)
    {
        laser.draw();
    }
    


}
void game::handleinput()
{
   if( IsKeyDown(KEY_LEFT)){
    playership.moveleft();
   }
   else if(IsKeyDown(KEY_RIGHT))
   {
    playership.moveright();
   }
   else if(IsKeyDown(KEY_SPACE))
   {
    playership.fireLaser();
   }
}

void game::deletefinishedlasers()
{
    for(auto it= playership.pewpew.begin(); it!=playership.pewpew.end();){

        if(!it -> active)
        {
            it = playership.pewpew.erase(it);
        }else{++it;}
    }
    for(auto it= alienlasers.begin(); it!=alienlasers.end();){

        if(!it -> active)
        {
            it = alienlasers.erase(it);
        }else{++it;}
    }
    for(auto it= minilasers.begin(); it!=minilasers.end();){

        if(!it -> active)
        {
            it = minilasers.erase(it);
        }else{++it;}
    }
    
    
}

vector<Alien> game::createaliens()
{
    vector<Alien> aliens;
    for(int i=0;i<5;i++)
    {
        for(int j=0;j<12;j++){
            if(j!=1&&j!=4&&j!=7&&j!=10)
            {float x= 50+j*55;
            float y= 100+i*55;
            aliens.push_back(Alien({x, y}));
            }
            }
    }
    return aliens;
}

void game::randalien()
{
    double currtime=GetTime();
    if(currtime-lastlasertimealien>=alieninterval && !aliens.empty())
    {int randindex=GetRandomValue(0,aliens.size());
        Alien& alien = aliens[randindex];
        alienlasers.push_back(Laser({alien.position.x +alien.newWidth/2,
        alien.position.y+alien.newHeight}, 7));
        lastlasertimealien=GetTime();
        }
    }
void game::minishootlaser()
    {
         double currtime=GetTime();
         if(currtime-lastlasertimemini>=miniinterval && mini.alive)
    {
       
        minilasers.push_back(Laser({mini.position.x +58,
        mini.position.y+58}, 10));
        lastlasertimemini=GetTime();
        }
        
    }




    void game::checkforcollisions()
    {
 //skill issue:creatin obstacle array again 
                            int obstacleWidth=70;
                            int obstacleHeight=50;
                            int obstacleCount=4;
                            int spaceBetweenObstacles = (GetScreenWidth()- 4* 70) / (4 + 1);
                             Rectangle obstacle[4];
                            for (int i = 0; i < obstacleCount; i++) {
                            obstacle[i].width = obstacleWidth;
                            obstacle[i].height = obstacleHeight;
                            obstacle[i].x = spaceBetweenObstacles + i * (obstacleWidth + spaceBetweenObstacles);
                             obstacle[i].y = GetScreenHeight() / 2 - obstacleHeight / 2+200;
                            }
        //playership lasers interaction
        for(auto& laser: playership.pewpew)
        {
            //checking playerships lasers interaction with the aliens
            auto it=aliens.begin();
            while(it!=aliens.end())
            {
                if(CheckCollisionRecs(it -> getrect(),laser.getrect()))
                {
                   it=aliens.erase(it); //erases the alien "it" points to andmakes it poin to the next element in aliens vector
                    laser.active=false;

                }else{
                    ++it;
                }

            }
            //colisions of playership lasers and obstacles
            
                            
            for(int i=0;i<4;i++)
            {
                if(CheckCollisionRecs(obstacle[i],laser.getrect()))
                    {
                        laser.active=false;
                    }


            }
            //collision of playership lasers and miniboss
             if(CheckCollisionRecs(mini.getRect(), laser.getrect())){
            mini.alive = false;
            laser.active = false;
           
        }

         }


        //alien laser interaction 
        for(auto& laser:alienlasers)
        {
            //interaction with playerhsip
            if(CheckCollisionRecs(laser.getrect(),playership.getreact()))
            {
                laser.active=false;
                cout<<"player hit"<<endl;
                
            }

            
        }
        //mini boss laser interaction
        for(auto& laser: minilasers)
        {
            //interaction with playerhsip
            if(CheckCollisionRecs(laser.getrect(),playership.getreact()))
            {
                laser.active=false;
                cout<<"player hit"<<endl;
                
            }

            //interaction with obstacles
            for(int i=0;i<4;i++)
            {
                if(CheckCollisionRecs(obstacle[i],laser.getrect()))
                    {
                        laser.active=false;
                    }
            }


        }
    }

    
