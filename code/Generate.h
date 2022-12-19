#include <SFML/Graphics.hpp>
#include <iostream>
#include "Constants.h"
#include "Player.h"


using namespace sf;
using namespace std;

class Generate
{
protected:
    string platformType;

public:
    Generate(string m_platType);
    virtual vector<Sprite> generator() const = 0;
    virtual void update(vector<Sprite>&, float) const = 0; 
    string getType();
};

class general : public Generate
{
private:
public:
    general();
    vector<Sprite> generator() const override;
    void update(vector<Sprite>& x, float) const override; 
};

class fakePlat : public Generate
{
private:
public:
    fakePlat();
    vector<Sprite> generator() const override;
    void update(vector<Sprite>&, float) const override; 
};



