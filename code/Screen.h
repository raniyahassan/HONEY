#ifndef SCREEN
#define SCREEN

#include <iostream>
#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Constants.h"

using namespace std;
using namespace sf;

class Screen 
{
    private:
        Sprite beginningbackground; 
        Sprite button; 
        Sprite logo; 
        int totalPoints; 
    public:
        Screen(double,double); 
        void start(RenderWindow&, Font&); 
        Sprite bg(RenderWindow&); 
        FloatRect getBounds(); 
        void endScreen(Player&, RenderWindow&, View&, Font&, int&);
        void playScreen(Player&, View&, RenderWindow&, vector<Sprite>&, vector<Sprite>&, Font&, int&);
};

#endif