/*******************************************************************************
 * Class Name: game
 * Description: Handles all functionality related to the execution of the 
 * game steps. Functionality includes get and set methods, charCreation,
 * playRound, checkDeath, fightResults, printLineups, and printScore.
 ******************************************************************************/

#include "game.hpp"
#include <iostream>

Game::Game()
{
    l1 = l2 = NULL; 
    lose = NULL; 
    this->deadChar = false;
}

Game::Game(int num1, int num2)
{
    this->l1 = new Lineup;
    this->l2 = new Lineup;
    this->lose = new Losers;

    //create characters for each team and add them to the lineup
    for (int i = 0; i < num1; i++)
    {
        l1->addBack(charCreation());
    }

    for (int i = 0; i < num2; i++)
    {
        l2->addBack(charCreation());
    }

    this->deadChar = false;
    this->l1Score = this->l2Score = 0;
}

Game::~Game()
{
    delete l1;
    delete l2;
    delete lose;
    l1 = l2 = NULL;
    lose = NULL;
}

bool Game::getDeath()
{
    return this->deadChar;
}

Lineup* Game::getLineup(int i)
{
    if (i == 1)
    {
        return l1;
    }

    return l2;
}

Losers* Game::getLosers()
{
    return lose;
}

/*******************************************************************************
 * Name: charCreation 
 * Description: Creates a character with attributes from the specific types 
 ******************************************************************************/
Character* Game::charCreation()
{
    Character *c;
    
    //allow the user to choose a character and create an object based
    //on the choice
    switch(charSelection())
    {
        case 1: c = new Vampire;
                c->setCharType(VAMPIRE);
                break;
        case 2: c = new Barbarian;
                c->setCharType(BARBARIAN);
                break;
        case 3: c = new Blue_Men;
                c->setCharType(BLUE_MEN);
                break;
        case 4: c = new Medusa;
                c->setCharType(MEDUSA);
                break;
        case 5: c = new Harry_Potter;
                c->setCharType(HARRY_POTTER);
                break;
    }
    
    return c;
}
    
/*******************************************************************************
 * Name: playRound
 * Description: Runs through the game, consisting of attacks by
 * each player, until one player is dead
 ******************************************************************************/
bool Game::playRound()
{
    for (int i = 0; i < 2; i++)
    {
        if (i == 0)
        {
            //set strength, attack, defense, and damage values for the round
            l2->getFront()->getStr();
            int att = l1->getFront()->makeAtt();
            int def = l2->getFront()->makeDef();
            int dam = l2->getFront()->applyDam(att, def);
            
            //check if player two has died
            checkDeath(l2->getFront());
        
            printRound(att, def, dam);
        }
        else
        {
            l1->getFront()->getStr();
            int att = l2->getFront()->makeAtt();
            int def = l1->getFront()->makeDef();
            int dam = l1->getFront()->applyDam(att, def);

            checkDeath(l1->getFront());

            printRound(att, def, dam);
        }

        std::cout << "Press enter to continue play" << std::endl;
        std::cin.get();
    }
    
    return deadChar;
}

/*******************************************************************************
 * Name: checkDeath
 * Description: Check if the passed in character is dead
 ******************************************************************************/
void Game::checkDeath(Character *c)
{
    //if strength is less than or equal to 0, character is dead
    if (c->getStr() <= 0)
    {
        deadChar = true;
    }
}

/*******************************************************************************
 * Name: fightResults
 * Description: Prints the final results of the fight to the screen and moves
 * characters to the appropriate positions
 ******************************************************************************/
void Game::fightResults()
{
    std::cout << std::string(25, '-') << std::endl;
    std::cout << l1->getFront()->getName() << " vs. ";
    std::cout << l2->getFront()->getName() << std::endl;

    //if character 1 is dead, character 2 wins
    if (l1->getFront()->getStr() <= 0)
    {
        std::cout << "Winner: " << l2->getFront()->getName() << "!" << std::endl;
        //winner recovers a portion of strength
        l2->getFront()->recovery();
        //winner goes to the back of the lineup
        l2->addBack(l2->getFront());
        l2->removeFront();
        l2Score++;

        //loser goes to the top of the losers pile
        lose->push(l1->getFront());
        l1->removeFront();

    }
    //if character 2 is dead, character 1 wins
    else
    {
        std::cout << "Winner: " << l1->getFront()->getName() << "!" << std::endl; 
        l1->getFront()->recovery();
        l1->addBack(l1->getFront());
        l1->removeFront();
        l1Score++;

        lose->push(l2->getFront());
        l2->removeFront();
    }
    std::cout << std::string(25, '-') << std::endl;

    deadChar = false;
}

/*******************************************************************************
 * Name: printLineups
 * Description: Prints the lineups for both teams 
 ******************************************************************************/
void Game::printLineups()
{
    std::cout << std::endl << "Team 1 available fighters: ";
    l1->printLineup();
    std::cout << "Team 2 available fighters: ";
    l2->printLineup();
    std::cout << std::endl;
}

/*******************************************************************************
 * Name: printRound
 * Description: Print the results of the round to the screen
 ******************************************************************************/
void Game::printRound(int att, int def, int dam)
{
    std::cout << std::endl;
    
    std::cout << "Attacking Character: " << l1->getFront()->getName() << std::endl;
        
    std::cout << "Defending Character: " << l2->getFront()->getName() << std::endl;
   
    std::cout << l2->getFront()->getName() << "'s Armor: " << l2->getFront()->getArmor() << std::endl;

    std::cout << l2->getFront()->getName() << "'s Strength: " << l2->getFront()->getStr() << std::endl;
    
    std::cout << l1->getFront()->getName() << "'s roll: " << att << std::endl;

    std::cout << l2->getFront()->getName() << "'s roll: " << def << std::endl;

    std::cout << "Total damage taken: " << dam << std::endl;
    
    std::cout << l2->getFront()->getName() << "'s new strength: " << l2->getFront()->getStr() << std::endl;
    
    std::cout << std::endl;
}

/*******************************************************************************
 * Name: printScore
 * Description: Prints the game's final score 
 ******************************************************************************/
void Game::printScore()
{
    std::cout << std::endl << "Final Score:" << std::endl;
    std::cout << std::string(12, '-') << std::endl; 
    std::cout << "Team 1: " << l1Score << std::endl;
    std::cout << "Team 2: " << l2Score << std::endl;

    if (l1Score > l2Score)
    {
        std::cout << "The winner is Team 1!" << std::endl;
    }
    else
    {
        std::cout << "The winner is Team 2!" << std::endl;
    }
    std::cout << std::endl;
}
