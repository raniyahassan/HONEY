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

Begin::Begin() : Generate("Begin") { }

vector<Sprite> Begin::generator() const
{
    Texture *texture = new Texture;  
    texture->loadFromFile("images/bar.png");
    srand(time(0));
    vector<Sprite> x(10); 
    for (int i = 0; i < x.size(); i++)
    {
        x[i].setTexture(*texture);
        x[i].setScale(0.1, 0.1);
        x[i].setPosition(10 + (rand() % 900), 10 + (rand() % 700)); 
    }
    return x; 
}

beginRemainder::beginRemainder() : Generate("Remainder") { }

vector<Sprite> beginRemainder::generator() const
{
    Texture *texture = new Texture;  
    texture->loadFromFile("images/bar.png");
    srand(time(0));
    vector<Sprite> x(20); 
    for (int i = 0; i < x.size(); i++)
    {
        x[i].setTexture(*texture);
        x[i].setScale(0.1, 0.1);
        x[i].setPosition(10 + (rand() % 900), 600 - (rand() % 2000));
        cout << "(" << x[i].getPosition().x << ", " << x[i].getPosition().y << ")" << endl; 
        
    }

   return x;
}

general::general() : Generate("General") 
{}

vector<Sprite> general::generator() const
{
    Texture *texture = new Texture;  
    texture->loadFromFile("images/bar.png");
    srand(time(0)); 
    vector<Sprite> x(14); 
    for (int i = 0; i < x.size(); i++)
    {
        x[i].setTexture(*texture);
        x[i].setScale(0.1, 0.1);
        x[i].setPosition(10 + (rand() % 900), (1000) - (rand() % (2000)));
        cout << "(" << x[i].getPosition().x << ", " << x[i].getPosition().y << ")" << endl; 

    }
    Sprite start(*texture); 
    start.setScale(0.1, 0.1); 
    start.setPosition(PLAYER_START_X, PLAYER_START_Y-30);
    x.push_back(start); 
   return x;
}

void general::update(vector<Sprite> &x, float PlayerPosY)
{
    for (int i = 0; i < x.size(); i++)
    {
        if (x[i].getPosition().y - (PlayerPosY) > 500)
        {
            x[i].move(-200 + rand() % 400, -800 - (rand() % 500));
        }
    }
}