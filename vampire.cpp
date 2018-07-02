/*******************************************************************************
 * Class Name: Vampire
 * Description: Derived character type Vampire. Functions include makeAtt,
 * makeDef, and applyDam.
 ******************************************************************************/

#include "vampire.hpp"
#include <iostream>

Vampire::Vampire()
    : Character(12, 6, 1, 18, 1, 1)
{
}

Vampire::~Vampire()
{
}

/*******************************************************************************
 * Name: makeAtt
 * Description: Roll the dice for an attack 
 ******************************************************************************/
int Vampire::makeAtt()
{
    return diceRoll(NUM_ATT_DICE, attack);
}

/*******************************************************************************
 * Name: makeDef
 * Description: Roll the dice for defence 
 ******************************************************************************/
int Vampire::makeDef()
{
    int charm = rand() % 2;

    //if vampire rolls for charm, no damage is taken for the round
    if (charm == 1)
    {
        return -1;
    }
        
    return diceRoll(NUM_DEF_DICE, defense);
}

/*******************************************************************************
 * Name: applyDam
 * Description: Applies the attack damage to the defenders roll and armor
 ******************************************************************************/
int Vampire::applyDam(int attIn, int defIn)
{
    //if opponent is charmed, damage is 0
    if (defIn == -1)
    {
        return 0;
    }

    return Character::applyDam(attIn, defIn);
}
