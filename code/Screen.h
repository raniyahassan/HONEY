#ifndef SCREEN
#define SCREEN

#include <iostream>
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

class Screen 
{
    private:
        Texture texture; 
        Texture texture2; 
        Texture texture3;
        Sprite beginningbackground; 
        Sprite button; 
        Sprite logo; 
    public:
        Screen(double,double); 
        void start(RenderWindow&); 
        void move(); 
        FloatRect getBounds(); 
};

#endif