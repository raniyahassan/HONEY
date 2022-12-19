#include "Constants.h"
#include "Player.h"
#include "Generate.h"
#include "Screen.h"

int main()
{
    enum STATE {START, PLAYING, END}; 
    STATE state = START; 
	RenderWindow window(VideoMode(WINDOW_WIDTH/2, WINDOW_HEIGHT/2), "jumpingGame", Style::Default);
	Font font;
	if (!font.loadFromFile("font/txt.otf")) { cout << "Error loading font"; }
	Texture playerTexture;
	Texture *platTexture = new Texture; 
	playerTexture.loadFromFile("images/pinky.png");
    platTexture->loadFromFile("images/bar.png"); 
	View view(Vector2f(0.0f, 0.0f), Vector2f(1000.0f, 1300.0f));
	Player player(&playerTexture, PLAYER_SPEED, PLAYER_JUMP_HEIGHT);
	general* platformGen = new general(); 
	vector<Sprite> platforms = platformGen->generator(); 
	fakePlat* fakeGen = new fakePlat();
	vector<Sprite> fakePlatforms = fakeGen->generator(); 
	float deltaTime = 0.0f;
	Clock clock;
	int pointCount = 0; 
    Screen screen(WINDOW_WIDTH, WINDOW_HEIGHT); 
	while (window.isOpen()) {
		deltaTime = clock.restart().asSeconds();
		if (deltaTime > 1.0f / 20.0f) { deltaTime = 1.0f / 20.0f; }
		Event event;
		while (window.pollEvent(event)) {
			if (event.type == Event::Closed) {window.close(); }
			if (Keyboard::isKeyPressed(Keyboard::Escape)) {window.close();}
            if (event.type == Event::MouseButtonPressed) {if (state != PLAYING) {state = PLAYING;}}
		}
		player.Update(deltaTime);
        player.winBounds(); 
		FloatRect pCol = player.GetHitbox();
		platformGen->update(platforms, player.GetPosition().y); 
		fakeGen->update(fakePlatforms, player.GetPosition().y);
		for (int i = 0; i < platforms.size(); i++) {
			if (platforms[i].getGlobalBounds().intersects(pCol) && player.getY() > 0) {
				player.OnCollision();
				pointCount++; 
			}
		}
		window.clear(Color(255, 255, 191));
		if (state == START) {screen.start(window, font);}
        if (state == PLAYING) {
			screen.playScreen(player, view, window, platforms, fakePlatforms, font, pointCount); 
			if (player.GetPosition().y > 2800) {state = END;}
        }
		if (state == END) { screen.endScreen(player, window, view, font, pointCount); }
		window.display();
	}
	return 0;
}