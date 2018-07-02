#ifndef HARRY_POTTER_HPP
#define HARRY_POTTER_HPP

#include "character.hpp"

class Harry_Potter : public Character
{
public:
    Harry_Potter();
    ~Harry_Potter();
    virtual int makeAtt();
    virtual int makeDef();
    virtual int applyDam(int, int);
    virtual void recovery();
private:
    bool hasDied;
};
#endif
