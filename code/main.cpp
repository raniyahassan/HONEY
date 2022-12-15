#include "Constants.h"
#include "Player.h"
#include "Platform.h"
#include "Generate.h"
#include "Screen.h"

void texter(Text& text, Font& font)
{
	text.setFont(font);
	text.setOrigin(-400,-1000); 
	text.setString("click to start!");
	text.setCharacterSize(45);
}

int main()
{
    enum STATE {START, PLAYING, END}; 
    STATE state = START; 
	RenderWindow window(VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "jumpingGame", Style::Default);
	Font font;
	if (!font.loadFromFile("font/txt.otf")) { cout << "Error loading font"; }
	Text text;
	texter(text, font); 
	Texture playerTexture;
	Texture *platTexture = new Texture; 
	playerTexture.loadFromFile("images/pinky.png");
    platTexture->loadFromFile("images/bar.png"); 
	View view(Vector2f(0.0f, 0.0f), Vector2f(1000.0f, 1300.0f));
	Player player(&playerTexture, PLAYER_SPEED, PLAYER_JUMP_HEIGHT);
	Platform plat1(platTexture, Vector2f(PLAT_WIDTH, PLAT_HEIGHT), Vector2f(350.0f, 150.0f));
    vector<Sprite> platforms = plat1.generator(); 
	Begin* set1 = new Begin(); 
	beginRemainder* set2 = new beginRemainder(); 
	vector<Sprite> v = set1->generator(window); 
	vector<Sprite> v2 = set2->generator(window);  
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
            if (event.type == Event::MouseButtonPressed) {state = PLAYING;}
		}
		player.Update(deltaTime);
        player.winBounds(); 
		FloatRect pCol = player.GetHitbox();

		for (int i = 0; i < v.size(); i++)
		{
			if (v[i].getGlobalBounds().intersects(pCol) && player.getY() > 0)
				player.OnCollision();
			if (v2[i].getGlobalBounds().intersects(pCol) && player.getY() > 0)
				player.OnCollision();
		}
		for (int i = 0; i < v2.size(); i++)
		{
			if (v2[i].getGlobalBounds().intersects(pCol) && player.getY() > 0)
				player.OnCollision();
		}
		window.clear(Color(255, 255, 191));
		if (state == START) {screen.start(window); window.draw(text); }
        if (state == PLAYING)
        {
			for (int i = 0; i < 10; i++) {window.draw((v[i]));}
			for (int i = 0; i < 20; i++) {window.draw((v2[i]));}
            window.setView(view);
            player.Draw(window);
            view.setCenter(WINDOW_WIDTH/2, player.GetPosition().y-200);
        }
		window.display();
	}
	return 0;

}