#include "Constants.h"
#include "Player.h"
#include "Generate.h"
#include "Screen.h"

Text texter(Font& font)
{
	Text text; 
	text.setFont(font);
	text.setPosition(190,550); 
	text.setString("click to start!");
	text.setCharacterSize(20);
	return text; 
}

int main()
{

	RectangleShape rect(Vector2f{WINDOW_WIDTH*2 , WINDOW_HEIGHT*2}); 
    rect.setFillColor(Color(0,0,0,100)); 

    enum STATE {START, PLAYING, END}; 
    STATE state = START; 

	RenderWindow window(VideoMode(WINDOW_WIDTH/2, WINDOW_HEIGHT/2), "jumpingGame", Style::Default);
	Font font;
	if (!font.loadFromFile("font/txt.otf")) { cout << "Error loading font"; }
	Text text = texter(font); 

	Texture playerTexture;
	Texture *platTexture = new Texture; 
	playerTexture.loadFromFile("images/pinky.png");
    platTexture->loadFromFile("images/bar.png"); 

	View view(Vector2f(0.0f, 0.0f), Vector2f(1000.0f, 1300.0f));

	Player player(&playerTexture, PLAYER_SPEED, PLAYER_JUMP_HEIGHT);

	Begin* set1 = new Begin(); 
	beginRemainder* set2 = new beginRemainder(); 
	general* set3 = new general(2); 
	vector<Sprite> v = set1->generator(window); 
	vector<Sprite> v2 = set2->generator(window); 
	vector<Sprite> v3 = set3->generator(window); 

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
            if (event.type == Event::MouseButtonPressed) {state = PLAYING; cout << "( " << Mouse::getPosition().x << ", " << Mouse::getPosition().y << ")" << endl; }
		}
		player.Update(deltaTime);
        player.winBounds(); 

		FloatRect pCol = player.GetHitbox();

		set3->update(v3, player.GetPosition().y); 


		for (int i = 0; i < v3.size(); i++)
		{
			if (v3[i].getGlobalBounds().intersects(pCol) && player.getY() > 0)
				player.OnCollision();
		}
		for (int i = 0; i < v2.size(); i++)
		{
			if (v2[i].getGlobalBounds().intersects(pCol) && player.getY() > 0)
				player.OnCollision();
		} 
		window.clear(Color(255, 255, 191));
		Sprite bg = screen.bg(window); 
		if (state == START) {screen.start(window); window.draw(text); }
        if (state == PLAYING)
        {
			cout << "(" << player.GetPosition().x << ", " << player.GetPosition().y << ")" << endl; 
			for (int i = 0; i < v2.size(); i++) {window.draw((v2[i]));}
			for (int i = 0; i < v3.size(); i++) {window.draw((v3[i]));}
            window.setView(view);
            player.Draw(window);
            view.setCenter(WINDOW_WIDTH/2, player.GetPosition().y-200);
			if (player.GetPosition().y > 2800) {view.setCenter(WINDOW_WIDTH/2, player.GetPosition().y); state = END;}
			
        }
		if (state == END)
		{
			player.Draw(window); 
			if (player.GetPosition().y > 3500){
			view.setCenter(500,750); 
			rect.setPosition(0,0);
			window.setView(view); 
			window.draw(rect); }
			//window.clear(); 
			//bg.setOrigin(0,0); 
			//window.draw(bg);
		}
		window.display();
	}
	return 0;

}