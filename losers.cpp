/*******************************************************************************
 * Class Name: losers
 * Description: Handles all functionality related to creating and using a 
 * stack to hold the losing fighters in the tournament. Functionality includes
 * isEmpty, push, and printLosers 
 ******************************************************************************/

#include "losers.hpp"
#include <iostream>

Losers::Losers()
{
    top = NULL;
}

Losers::~Losers()
{
    //pointer to traverse the list
    StackNode *nodePtr = top;

    //while not at end of list
    while (nodePtr != NULL)
    {
        //delete the character held in the node
        delete nodePtr->fighter;
        nodePtr->fighter = NULL;

        //traverse the list with nodePtr and trail with cleanUp
        StackNode *cleanUp = nodePtr;
        nodePtr = nodePtr->next;
        delete cleanUp;
    }
    top = NULL;
}

/*******************************************************************************
 * Name: isEmpty
 * Description: Checks if the lineup is empty 
 ******************************************************************************/
bool Losers::isEmpty()
{
    if (top == NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
}

/*******************************************************************************
 * Name: push
 * Description: Pushes a new node onto the stack 
 ******************************************************************************/
void Losers::push(Character *c)
{
    StackNode *nodePtr = new StackNode(c);
    nodePtr->next = top;
    top = nodePtr;
}

/*******************************************************************************
 * Name: printLosers
 * Description: Prints the values contained in the lineup 
 ******************************************************************************/
void Losers::printLosers()
{
    //if lineup is empty throw exception
    if (isEmpty())
    {
        throw UnderflowException("Underflow error -- empty lineup"); 
    }
    else
    {
        StackNode *nodePtr = top;
    
        std::cout << std::endl << "The losers are: ";
        
        //print each node value
        while (nodePtr != NULL) 
        {
            std::cout << nodePtr->fighter->getName() << " ";
            //traverse the lineup with nodePtr
            nodePtr = nodePtr->next;
        }
        std::cout << std::endl;
    }
}
