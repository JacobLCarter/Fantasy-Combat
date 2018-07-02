#ifndef LINEUP_HPP
#define LINEUP_HPP

#include "character.hpp"
#include "underflowException.hpp"

class Lineup
{
protected:
    //struct declaration for QueueNode
    struct QueueNode
    {
        Character *fighter;
        QueueNode *next;
        QueueNode(Character *c) { fighter = c; next = NULL; }
    };
    QueueNode *front;
    QueueNode *back;
public:
    Lineup();
    ~Lineup();
    bool isEmpty();
    void addBack(Character*);
    Character* getFront();
    void removeFront();
    void printLineup();
};
#endif
