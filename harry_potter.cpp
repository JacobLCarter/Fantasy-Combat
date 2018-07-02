/*******************************************************************************
 * Class Name: Harry_Potter
 * Description: Derived character type Harry Potter. Functions include makeAtt,
 * makeDef, applyDam, and recovery.
 ******************************************************************************/

#include "harry_potter.hpp"
#include <iostream>

Harry_Potter::Harry_Potter()
    : Character(6, 6, 0, 10, 2, 2)
{
    this->hasDied = false;
}

Harry_Potter::~Harry_Potter()
{
}

/*******************************************************************************
 * Name: makeAtt
 * Description: Roll the dice for an attack 
 ******************************************************************************/
int Harry_Potter::makeAtt()
{
    return diceRoll(NUM_ATT_DICE, attack); 
}

/*******************************************************************************
 * Name: makeDef
 * Description: Roll the dice for defence 
 ******************************************************************************/
int Harry_Potter::makeDef()
{
    return diceRoll(NUM_DEF_DICE, defense);
}

/*******************************************************************************
 * Name: applyDam
 * Description: Applies the attack damage to the defenders roll and armor
 ******************************************************************************/
int Harry_Potter::applyDam(int attIn, int defIn)
{
    int dam = Character::applyDam(attIn, defIn);

    //if Harry has not yet died, regenerate double health upon being killed
    if (strength <= 0 && hasDied == false)
    {
        strength = 20;
        hasDied = true;
    }

    return dam;
}

/*******************************************************************************
 * Name: recovery
 * Description: Fighter recovers a random portion of strength 
 ******************************************************************************/
void Harry_Potter::recovery()
{
    //if Harry has already died, increase max strength
    if (hasDied)
    {
        strMax = 20;    
    }
        
    Character::recovery();
}
