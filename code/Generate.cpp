#include <iostream>
#include "Generate.h"
using namespace std;


Generate::Generate(string platType)
{
    platformType = platType; 
}

string Generate::getType()
{
    return platformType;
}


general::general() : Generate("General") {}

vector<Sprite> general::generator() const
{
    Texture *texture = new Texture;  
    texture->loadFromFile("images/bar.png");
    srand(time(0)); 
    vector<Sprite> x(12); 
    for (int i = 0; i < x.size(); i++)
    {
        x[i].setTexture(*texture);
        x[i].setScale(0.1, 0.1);
        x[i].setPosition(10 + (rand() % 900), (1000) - (rand() % (2000)));
    }
    Sprite defaultPlatform(*texture); 
    defaultPlatform.setScale(0.1, 0.1); 
    defaultPlatform.setPosition(PLAYER_START_X, PLAYER_START_Y-30);
    x.push_back(defaultPlatform); 
    Sprite defaultPlatform2(*texture); 
    defaultPlatform2.setScale(0.1, 0.1); 
    defaultPlatform2.setPosition(PLAYER_START_X+400, PLAYER_START_Y+100);
    x.push_back(defaultPlatform2); 

   return x;
}

void general::update(vector<Sprite> &x, float PlayerPosY) const
{
    for (int i = 0; i < x.size(); i++)
    {
        if (x[i].getPosition().y - (PlayerPosY) > 500)
        {
            x[i].move(-200 + rand() % 400, -800 - (rand() % 500));
        }
    }
}

fakePlat::fakePlat() : Generate("Fake") {}

vector<Sprite> fakePlat::generator() const
{
    Texture *texture = new Texture;  
    texture->loadFromFile("images/bar.png");
    srand(time(0)); 
    vector<Sprite> x(6); 
    for (int i = 0; i < x.size(); i++)
    {
        x[i].setColor(Color(255,255,225,145)); 
        x[i].setTexture(*texture);
        x[i].setScale(0.1, 0.1);
        x[i].setPosition(10 + (rand() % 900), (1000) - (rand() % (2000)));
    }
   return x;
}

void fakePlat::update(vector<Sprite> &x, float PlayerPosY) const
{
    for (int i = 0; i < x.size(); i++)
    {
        if (x[i].getPosition().y - (PlayerPosY) > 500)
        {
            x[i].move(-200 + rand() % 400, -800 - (rand() % 500));
        }
    }
}