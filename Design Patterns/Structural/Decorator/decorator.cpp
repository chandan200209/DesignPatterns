#include <iostream>
#include <string>
using namespace std;

// component interface : defines a common interface for Mario and all power-up decorators
class Character
{
public:
    virtual string getAbilities() const = 0;
    virtual ~Character() {}; // virtual destructor
};
// concrete component : basic mario character with no power ups
class Mario : public Character
{
public:
    string getAbilities() const override
    {
        return "Mario";
    }
};
// abstract decorator : CharacterDecorator 'is-a' Character and 'has-a' Character
class CharacterDecorator : public Character
{
public:
    Character *character; // wrapped component
    CharacterDecorator(Character *c)
    {
        this->character = c;
    }
};
// concrete Decorator : Height increasing power-up
class HeightUp : public CharacterDecorator
{
public:
    HeightUp(Character *c) : CharacterDecorator(c) {}
    string getAbilities() const override
    {
        return character->getAbilities() + " with height-up";
    }
};
// concrete Decorator : Gun shooting power-up
class GunPowerUp : public CharacterDecorator
{
public:
    GunPowerUp(Character *c) : CharacterDecorator(c) {}
    string getAbilities() const override
    {
        return character->getAbilities() + " with Gun";
    }
};
// concrete Decorator : Star power-up (temporary ability)
class StarPowerUp : public CharacterDecorator
{
public:
    StarPowerUp(Character *c) : CharacterDecorator(c) {}
    string getAbilities() const override
    {
        return character->getAbilities() + " with Star Power [limited time]";
    }
    ~StarPowerUp()
    {
        cout << "Destroying star power decorator" << endl;
    }
};
int main()
{
    // creating a basic mario character
    Character *mario = new Mario();
    cout << "Basic Character : " << mario->getAbilities() << endl;
    // decorate mario with HeightUp power up ability
    mario = new HeightUp(mario);
    cout << "After height-up : " << mario->getAbilities() << endl;
    // decorate mario further with GunPowerUp
    mario = new GunPowerUp(mario);
    cout << "After GunPowerUp : " << mario->getAbilities() << endl;
    // finally, add a StarPowerUp Decoration
    mario = new StarPowerUp(mario);
    cout << "After StarPowerUp : " << mario->getAbilities() << endl;
    delete mario;
    return 0;
}