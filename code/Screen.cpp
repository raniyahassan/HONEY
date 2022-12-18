#include "Screen.h"

Screen::Screen(double width, double height) 
{
    Texture *texture2 = new Texture; 
    texture2->loadFromFile("images/bg.jpg"); 
    beginningbackground.setTexture(*texture2); 
    beginningbackground.setScale(0.55, 0.25); 

    Texture *texture3 = new Texture;
    texture3->loadFromFile("images/start.png"); 
    button.setTexture(*texture3); 
    button.setScale(0.4,0.4);    
    FloatRect bound = button.getGlobalBounds();
    button.setPosition((width/4)-(bound.width/2), 400);  
    
    Texture *texture4 = new Texture;
    texture4->loadFromFile("images/logo.png");
    logo.setTexture(*texture4);
    logo.setScale(0.4, 0.4); 
    FloatRect bound2 = logo.getGlobalBounds();
    logo.setPosition((width/4)-(bound2.width/2), 50);  
    
    // logo.setPosition(800, 200);

}; 


void Screen::start(RenderWindow& window)
{
	window.draw(beginningbackground); 
    window.draw(button); 
    window.draw(logo); 
}

Sprite Screen::bg(RenderWindow& window)
{
    beginningbackground.setScale(0.95, 0.8); 
	return beginningbackground; 
}


FloatRect Screen::getBounds() { return button.getGlobalBounds(); }
