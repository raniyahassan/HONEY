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

vector<Sprite> Begin::generator(RenderWindow& win) const
{
    Texture *texture = new Texture;  
    texture->loadFromFile("images/bar.png");
    srand(time(0));
    vector<Sprite> x(10); 
    for (int i = 0; i < x.size(); i++)
    {
        x[i].setTexture(*texture);
        x[i].setScale(0.1, 0.1);
        x[i].setPosition(10 + (rand() % 900), 700 + (rand() % 1000)); 
    }
    return x; 
}

beginRemainder::beginRemainder() : Generate("Remainder") { }

vector<Sprite> beginRemainder::generator(RenderWindow& win) const
{
    Texture *texture = new Texture;  
    texture->loadFromFile("images/bar.png");
    srand(time(0));
    vector<Sprite> x(20); 
    for (int i = 0; i < x.size(); i++)
    {
        x[i].setTexture(*texture);
        x[i].setScale(0.1, 0.1);
        x[i].setPosition(10 + (rand() % 900), (rand() % 500));
        
    }

   return x;
}

general::general(int i) : Generate("General") 
{
    count = i;
}

vector<Sprite> general::generator(RenderWindow& win) const
{
    Texture *texture = new Texture;  
    texture->loadFromFile("images/bar.png");
    srand(time(0));
    vector<Sprite> x(25); 
    for (int i = 0; i < x.size(); i++)
    {
        x[i].setTexture(*texture);
        x[i].setScale(0.1, 0.1);
        float newY = (WINDOW_HEIGHT *(i-1) + (rand() % (WINDOW_HEIGHT*i)));
        x[i].setPosition(10 + (rand() % 900), -newY);
    }

    return x; 
}
