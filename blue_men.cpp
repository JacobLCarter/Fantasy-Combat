/*******************************************************************************
 * Class Name: Blue_Men
 * Description: Derived character type Blue Men. Functions include makeAtt,
 * makeDef.
 ******************************************************************************/

#include "blue_men.hpp"

Blue_Men::Blue_Men()
    : Character(10, 6, 3, 12, 2, 3)
{
}

Blue_Men::~Blue_Men()
{
}

/*******************************************************************************
 * Name: makeAtt
 * Description: Roll the dice for an attack 
 ******************************************************************************/
int Blue_Men::makeAtt()
{
    return diceRoll(NUM_ATT_DICE, attack);
}

/*******************************************************************************
 * Name: makeDef
 * Description: Roll the dice for defence 
 ******************************************************************************/
int Blue_Men::makeDef()
{
    //conditionals to select the number of dice the Blue Men will roll based
    //on current strength
    if (strength <= 12 && strength >= 9) 
    {
        return diceRoll(NUM_DEF_DICE, defense);
    }
    else if (strength <= 8 && strength >= 5)
    {
        return diceRoll(NUM_DEF_DICE - 1, defense);
    }
    else
    {
        return diceRoll(NUM_DEF_DICE - 2, defense);
    }
}
