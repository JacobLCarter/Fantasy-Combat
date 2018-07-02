#ifndef LOSERS_HPP
#define LOSERS_HPP

#include "character.hpp"
#include "underflowException.hpp"

class Losers
{
protected:
    //struct declaration for StackNode
    struct StackNode
    {
        Character *fighter;
        StackNode *next;
        StackNode(Character *c) { fighter = c; next = NULL; }
    };
    StackNode *top;
public:
    Losers();
    ~Losers();
    bool isEmpty();
    void push(Character*);
    void printLosers();
};
#endif
