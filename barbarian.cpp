/*******************************************************************************
 * Class Name: Barbarian
 * Description: Derived character type Barbarian. Functions include makeAtt,
 * makeDef.
 ******************************************************************************/
#include "barbarian.hpp"

Barbarian::Barbarian()
    : Character(6, 6, 0, 12, 2, 2)
{
}

Barbarian::~Barbarian()
{
}

/*******************************************************************************
 * Name: makeAtt
 * Description: Roll the dice for an attack 
 ******************************************************************************/
int Barbarian::makeAtt()
{
    return diceRoll(NUM_ATT_DICE, attack);
}

/*******************************************************************************
 * Name: makeDef
 * Description: Roll the dice for defence 
 ******************************************************************************/
int Barbarian::makeDef()
{
    return diceRoll(NUM_DEF_DICE, defense);
}
