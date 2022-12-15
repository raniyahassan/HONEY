#include "Constants.h"
#include "Player.h"
#include "Platform.h"
#include "Screen.h"

int main()
{
    enum STATE {START, PLAYING, END}; 
    STATE state = START; 
	RenderWindow window(VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "jumpingGame", Style::Default);
    int Ypos = 100; 

	Texture playerTexture;
	Texture *platTexture = new Texture; 
	playerTexture.loadFromFile("images/pinky.png");
    platTexture->loadFromFile("images/bar.png"); 

	View view(Vector2f(0.0f, 0.0f), Vector2f(1000.0f, 1300.0f));
	
	Player player(&playerTexture, PLAYER_SPEED, PLAYER_JUMP_HEIGHT);

	Platform plat1(platTexture, Vector2f(PLAT_WIDTH, PLAT_HEIGHT), Vector2f(350.0f, 150.0f));
    vector<Sprite> platforms = plat1.generator(WINDOW_WIDTH, WINDOW_HEIGHT); 

	float deltaTime = 0.0f;
	Clock clock;

    Screen screen(WINDOW_WIDTH, WINDOW_HEIGHT); 

	while (window.isOpen())
	{
		deltaTime = clock.restart().asSeconds();
		if (deltaTime > 1.0f / 20.0f) { deltaTime = 1.0f / 20.0f; }
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed) {window.close(); }
			if (Keyboard::isKeyPressed(Keyboard::Escape)) {window.close();}
            if (event.type == Event::MouseButtonPressed) 
            {
                Vector2i point = Mouse::getPosition(window);
                cout << "(" << point.x << ", " << point.y << ")\n"; 
                state = PLAYING; 
            }
		}
		player.Update(deltaTime);
        player.winBounds(); 
		FloatRect pCol = player.GetHitbox();

		for (int i = 0; i < platforms.size(); i++)
		{
			if (platforms[i].getGlobalBounds().intersects(pCol) && player.getY() > 0)
				player.OnCollision();
		}

        /*if (player.getY() < Ypos) 
        {
            plat1.shift(platforms, player); 
            Ypos -= WINDOW_HEIGHT; 
        }*/
		
		window.clear(Color(255, 255, 191));
        screen.start(window); 
        if (state == PLAYING)
        {
            screen.move(); 
            window.setView(view);
            player.Draw(window);
            for (int i = 0; i < platforms.size(); i++) {window.draw(platforms[i]);}
            view.setCenter(WINDOW_WIDTH/2, player.GetPosition().y-200);
        }
		window.display();
	}
	return 0;

	}