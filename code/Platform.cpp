#include "Platform.h"
#include "Player.h"
#include <time.h>

Platform::Platform(Texture* texture, Vector2f size, Vector2f position)
{
	body.setSize(size);
	body.setTexture(texture);
	body.setPosition(position);
	body.setOrigin(size / 2.0f);
}

Platform::~Platform() {}

void Platform::Draw(RenderWindow& window)
{
	window.draw(body);
}

FloatRect Platform::GetHitbox()
{
	return body.getGlobalBounds();
}

Vector2f Platform::GetPosition()
{
	return body.getPosition();
}

vector<Sprite> Platform::generator()
{
    Texture *texture = new Texture;  
    texture->loadFromFile("images/bar.png");
    srand(time(0));
    vector<Sprite> x(10); 
    for (int i = 0; i < x.size(); i++)
    {
        x[i].setTexture(*texture);
        x[i].setScale(0.1, 0.1);
        x[i].setPosition(10 + (rand() % 900), (700 + rand() % 1000));
        cout << "(" << x[i].getPosition().x << ", " << x[i].getPosition().y << ")" << endl; 
    }
    Sprite y(*texture); 
    y.setScale(0.1,0.1);
    y.setPosition(450, 1220); 
    x.push_back(y); 
    
    return x; 
}

void Platform::shift(vector<Sprite>& vec, Player P)
{
    srand(time(0));
    for (int i = 0; i < vec.size(); i++)
    {
        vec[i].setPosition(10 + (rand() % 900), (i*(-600) + (rand() % 1000)));

    }
}

