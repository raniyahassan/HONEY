#include "Platform.h"
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

vector<Sprite> Platform::generator(double width, double height)
{
    Texture *texture = new Texture;  
    texture->loadFromFile("images/bar.png");

    srand(time(0));
    vector<Sprite> x(15); 
    for (int i = 0; i < x.size(); i++)
    {
        x[i].setTexture(*texture);
        x[i].setPosition(10 + (rand() % 900), 10 + (rand() % 1000));
        x[i].setScale(0.1, 0.1);
    }

    return x; 
}