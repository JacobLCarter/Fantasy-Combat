#ifndef VAMPIRE_HPP
#define VAMPIRE_HPP

#include "character.hpp"

class Vampire : public Character
{
public:
    Vampire();
    ~Vampire();
    virtual int makeAtt();
    virtual int makeDef();
    virtual int applyDam(int, int);
private:
};
#endif
