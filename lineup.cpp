/*******************************************************************************
 * Class Name: lineup
 * Description: Handles all functionality related to creating and using a 
 * lineup of all fighters in the tournament. Functionality includes isEmpty,
 * addBack, getFront, removeFront, and printLineup
 ******************************************************************************/

#include "lineup.hpp"
#include <iostream>

Lineup::Lineup()
{
    front = back = NULL;
}

Lineup::~Lineup()
{
    //pointer to traverse the list
    QueueNode *nodePtr = front;

    //while not at end of list
    while (nodePtr != NULL)
    {
        //delete the character held in the node
        delete nodePtr->fighter;
        nodePtr->fighter = NULL;

        //traverse the list with nodePtr and trail with cleanUp
        QueueNode *cleanUp = nodePtr;
        nodePtr = nodePtr->next;
        delete cleanUp;
    }
    front = back = NULL;
}

/*******************************************************************************
 * Name: isEmpty
 * Description: Checks if the lineup is empty 
 ******************************************************************************/
bool Lineup::isEmpty()
{
    if (front == NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
}

/*******************************************************************************
 * Name: addBack
 * Description: Adds a new node to the back of the lineup with a user 
 * specified value
 ******************************************************************************/
void Lineup::addBack(Character *charIn)
{
    QueueNode *nodePtr = new QueueNode(charIn);
    //if lineup if empty, insert node 
    if (isEmpty())
    {
        front = nodePtr; 
        back = front;
    }
    //if lineup is not empty, add a fighter
    else
    {
        back->next = nodePtr;
        back = nodePtr;
    }
}

/*******************************************************************************
 * Name: getFront 
 * Description: gets the character contained in the front node 
 ******************************************************************************/
Character* Lineup::getFront()
{
    //if lineup is empty, throw exception 
    if (isEmpty())
    {
        throw UnderflowException("Underflow error -- empty lineup"); 
    }
    //if lineup is not empty, return front value
    return front->fighter; 
}

/*******************************************************************************
 * Name: removeFront
 * Description: Removes the node at the front of the lineup
 ******************************************************************************/
void Lineup::removeFront()
{
    //if lineup is empty, throw exception
    if (isEmpty())
    {
        throw UnderflowException("Underflow error -- empty lineup"); 
    }
    //if lineup is not empty, remove first fighter
    else
    {
        QueueNode *nodePtr = front;
        
        front = front->next;
        delete nodePtr;
    }
}

/*******************************************************************************
 * Name: printLineup
 * Description: Prints the values contained in the lineup 
 ******************************************************************************/
void Lineup::printLineup()
{
    //if lineup is empty, throw exception
    if (isEmpty())
    {
        throw UnderflowException("Underflow error -- empty lineup"); 
    }
    else
    {
        QueueNode *nodePtr = front;
    
        //print each node value from front to back-1
        while (nodePtr != NULL) 
        {
            std::cout << nodePtr->fighter->getName() << " ";
            //traverse the lineup with nodePtr
            nodePtr = nodePtr->next;
        }
        std::cout << std::endl;
    }
}
