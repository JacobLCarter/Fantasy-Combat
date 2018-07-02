#ifndef MEDUSA_HPP
#define MEDUSA_HPP

#include "character.hpp"

class Medusa : public Character
{
public:
    Medusa();
    ~Medusa();
    virtual int makeAtt();
    virtual int makeDef();
private:
};
#endif
