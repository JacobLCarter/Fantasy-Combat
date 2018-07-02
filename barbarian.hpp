#ifndef BARBARIAN_HPP
#define BARBARIAN_HPP

#include "character.hpp"

class Barbarian : public Character
{
public:
    Barbarian();
    ~Barbarian();
    virtual int makeAtt();
    virtual int makeDef();
private:
};
#endif
