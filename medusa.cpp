/*******************************************************************************
 * Class Name: Medusa
 * Description: Derived character type Medusa. Functions include makeAtt and
 * makeDef.
 ******************************************************************************/

#include "medusa.hpp"
#include <iostream>

Medusa::Medusa()
    : Character(6, 6, 3, 8, 2, 1)
{
}

Medusa::~Medusa()
{
}

/*******************************************************************************
 * Name: makeAtt
 * Description: Roll the dice for an attack 
 ******************************************************************************/
int Medusa::makeAtt()
{
    int temp = diceRoll(NUM_ATT_DICE, attack);

    //if Medusa rolls a 12, she instantly kills the enemy
    if (temp == 12)
    {
        return 21;
    }

    return temp; 
}

/*******************************************************************************
 * Name: makeDef
 * Description: Roll the dice for defence 
 ******************************************************************************/
int Medusa::makeDef()
{
    return diceRoll(NUM_DEF_DICE, defense);
}
