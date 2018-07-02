#ifndef BLUE_MEN_HPP
#define BLUE_MEN_HPP

#include "character.hpp"

class Blue_Men : public Character
{
public:
    Blue_Men();
    ~Blue_Men();
    virtual int makeAtt();
    virtual int makeDef();
private:
};
#endif
