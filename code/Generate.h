#include <SFML/Graphics.hpp>
#include <iostream>
#include "Constants.h"

using namespace sf;
using namespace std;

class Generate
{
protected:
    string platformType;

public:
    Generate(string m_platType);
    virtual vector<Sprite> generator(RenderWindow& win) const = 0;
    string getType();
};

class Begin : public Generate
{
private:
public:
    Begin();
    vector<Sprite> generator(RenderWindow& win) const override;
};

class beginRemainder : public Generate
{
private:
public:
    beginRemainder();
    vector<Sprite> generator(RenderWindow& win) const override;
};

class general : public Generate
{
private:
    int count;
public:
    general(int i);
    vector<Sprite> generator(RenderWindow& win) const override;
};


