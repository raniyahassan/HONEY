#include "Constants.h"
#include "Player.h"
#include "Platform.h"

int main()
{
	RenderWindow window(VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "jumpingGame", Style::Default);

	Texture playerTexture;
	Texture *platTexture = new Texture; 
	playerTexture.loadFromFile("images/pinky.png");
	// platTexture.loadFromFile(PLAT_TEXTURE);
    platTexture->loadFromFile("images/bar.png"); 
	

	View view(Vector2f(0.0f, 0.0f), Vector2f(1000.0f, 1300.0f));
	
	Player player(&playerTexture, PLAYER_SPEED, PLAYER_JUMP_HEIGHT);

	Platform plat1(platTexture, Vector2f(PLAT_WIDTH, PLAT_HEIGHT), Vector2f(350.0f, 150.0f));
    vector<Sprite> platforms = plat1.generator(WINDOW_WIDTH, WINDOW_HEIGHT); 
	Platform ground(platTexture, Vector2f(1000.0f, 200.0f), Vector2f(500.0f, 500.0f));

	float deltaTime = 0.0f;
	Clock clock;

	while (window.isOpen())
	{
		deltaTime = clock.restart().asSeconds();
		if (deltaTime > 1.0f / 20.0f)
			deltaTime = 1.0f / 20.0f;
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
			if (Keyboard::isKeyPressed(Keyboard::Escape))
				window.close();
		}
		player.Update(deltaTime);
        player.winBounds(); 
		FloatRect pCol = player.GetHitbox();

		for (int i = 0; i < platforms.size(); i++)
		{
			if (platforms[i].getGlobalBounds().intersects(pCol) && player.getY() > 0)
				player.OnCollision();
		}
		
		window.clear(Color(255, 255, 191));
		window.setView(view);

		//drawing
		player.Draw(window);
		//draw all platforms (honestly sick)
		for (int i = 0; i < platforms.size(); i++)
			window.draw(platforms[i]);
		view.setCenter(WINDOW_WIDTH/2, player.GetPosition().y);
		window.display();
	}
	return 0;

	}