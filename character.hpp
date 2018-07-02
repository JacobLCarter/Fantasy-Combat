#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <cstdlib>
#include <string>
#include "utils.hpp"

//defined type to identify fighters
enum CharType {NONE, VAMPIRE, BARBARIAN, BLUE_MEN, MEDUSA, HARRY_POTTER};

class Character
{
public:
    Character();
    Character(int, int, int, int, int, int);
    virtual ~Character();
    int getStr();
    int getArmor() const;
    CharType getType();
    std::string getName();
    void setCharType(CharType);
    void setName(std::string);
    virtual int makeAtt() = 0;
    virtual int makeDef() = 0;
    virtual int applyDam(int, int);
    virtual void recovery();
    int diceRoll(int, int);
protected:
    const int attack;
    const int defense;
    const int armor;
    int strength;
    int strMax;
    CharType type;
    const int NUM_ATT_DICE;
    const int NUM_DEF_DICE;
    std::string name;
};
#endif
