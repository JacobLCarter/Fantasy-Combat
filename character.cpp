/*******************************************************************************
 * Class Name: Character
 * Description: Handles all functionality related to creating a new character.
 * Functionality includes get and set functions, makeAtt, makeDef, applyDam,
 * recovery, and diceRoll.
 * Abstract base class for all specific character types.
 ******************************************************************************/

#include "character.hpp"
#include <iostream>

Character::Character()
    : attack(-1), defense(-1), armor(-1), NUM_ATT_DICE(-1), NUM_DEF_DICE(-1)
{
    this->strength = this->strMax = -1;
    setName("No Name");
    this->type = NONE;
}

Character::Character(int a, int d, int ar, int s, int numAD, int numD)
    : attack(a), defense(d), armor(ar), NUM_ATT_DICE(numAD), NUM_DEF_DICE(numD)
{
    this->strength = this->strMax = s;
    setName(getString());
    this->type = NONE;
}

Character::~Character()
{
}

int Character::getStr()
{
    return this->strength;
}

int Character::getArmor() const
{
    return this->armor;
}

CharType Character::getType()
{
    return this->type;
}

std::string Character::getName()
{
    return this->name;
}

void Character::setCharType(CharType tIn)
{
    this->type = tIn;
}

void Character::setName(std::string nameIn)
{
    this->name = nameIn;
}

/*******************************************************************************
 * Name: applyDam
 * Description: Subtracts the amount of damage from an attack from the 
 * characters current strength
 ******************************************************************************/
int Character::applyDam(int damIn, int defIn)
{
    int adjDam = damIn - defIn - armor;
   
    //if damage is not 0 or negative, subtract it from strength
    if (adjDam >= 0)
    {
        this->strength -= adjDam;
        return adjDam;
    }
    else
    {
        return 0;
    }
}

/*******************************************************************************
 * Name: recovery
 * Description: Fighter recovers a random portion of strength 
 ******************************************************************************/
void Character::recovery()
{
    //random roll for recovery percentage
    int recovery = (rand() % 10 + 1) / 10;
   
    //if added recovery is not greater than character's max strength
    if ((this->strength += strength * recovery) < strMax)
    {
        this->strength += strength *recovery;
    }
    //else set strength to max allowed value
    else
    {
        strength = strMax; 
    }
}

/*******************************************************************************
 * Name: diceRoll
 * Description: Randomly rolls a specified number of dice 
 ******************************************************************************/
int Character::diceRoll(int numRolls, int numSides)
{
    if (numRolls == 0)
    {
        return 0;
    }
    else
    {
        //while rolls are not 0, roll again and add prior roll to total
        return (rand() % numSides + 1) + diceRoll(numRolls - 1, numSides);
    }
}
