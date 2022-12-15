#include "Screen.h"

Screen::Screen(double width, double height) 
{
    Texture *texture2 = new Texture; 
    texture2->loadFromFile("images/bg.jpg"); 
    beginningbackground.setTexture(*texture2); 
    beginningbackground.setScale(0.95, 0.7); 

    Texture *texture3 = new Texture;
    texture3->loadFromFile("images/start.png"); 
    button.setTexture(*texture3); 
    button.setScale(0.8,0.8);    
    FloatRect bound = button.getGlobalBounds();
    button.setPosition((width/2)-(bound.width/2), 841);  
    
    /*Texture *texture4 = new Texture;
    texture4->loadFromFile("images/i.png");
    logo.setTexture(*texture4);
    logo.setScale(0.9, 0.9); 
    FloatRect bound2 = logo.getGlobalBounds();
    logo.setPosition((width/2)-(bound2.width/2), 200);  */
    
    //logo.setPosition(800, 200);
}; 


void Screen::start(RenderWindow& window)
{
	window.draw(beginningbackground); 
    window.draw(button); 
    //window.draw(logo); 
}

void Screen::move()
{
    beginningbackground.setScale(0,0); 
    button.setScale(0,0) ;
}

FloatRect Screen::getBounds()
{
    return button.getGlobalBounds(); 
}
