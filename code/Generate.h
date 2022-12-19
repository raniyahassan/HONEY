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
    virtual vector<Sprite> generator( ) const = 0;
    string getType();
};

class Begin : public Generate
{
private:
public:
    Begin();
    vector<Sprite> generator( ) const override;
};

class beginRemainder : public Generate
{
private:
public:
    beginRemainder();
    vector<Sprite> generator( ) const override;
};

class general : public Generate
{
private:
public:
    general();
    vector<Sprite> generator( ) const override;
    void update(vector<Sprite>& x, float); 
};



