/*******************************************************************************
 * Program Name: fantasy 
 * Author: Jacob Carter
 * Date Last Modified: 2/20/2018
 * Description: This program is a fantasy combat game in which two teams of five 
 * selectable characters fight in a tournament.
 * To run, create your team by choosing characters when prompted.
 ******************************************************************************/

#include "game.hpp"
#include <string>
#include <iostream>
#include <cstdlib>
#include <ctime>

int main()
{
    //seed random number generation
    unsigned seed = time(NULL);
    srand(seed);

    int menuChoice = mainMenu();

    if (menuChoice == 1)
    {
        do
        {
            int i, j;

            //set the number of player for each team
            for (int count = 0; count < 2; count++)
            {
                std::cout << "Enter the number of players for team " << count + 1
                    << ": ";
                if (count == 0)
                {
                    i = getInt(false);
                }
                else
                {
                    j = getInt(false);
                }
            }

            //create a new game
            Game *theGame = new Game(i, j);

            //try/catch block to handle any exceptions that bubble up
            try
            {
                //while both teams have remaining fighters, stage another fight
                do
                {
                    theGame->printLineups();

                    //while neither character is dead, play game 
                    while (!theGame->playRound())
                    {
                    }
                    theGame->fightResults();
                }
                while (!theGame->getLineup(1)->isEmpty() && 
                        !theGame->getLineup(2)->isEmpty());

                //print the final score
                theGame->printScore();

                //prompt to print the losers pile
                std::cout << "Would you like to see the losers? (y/n)"
                    << std::endl;
               
                if (selectionYN() == 'Y')
                {
                    theGame->getLosers()->printLosers();
                }
            }
            //catch any exceptions and display the specific error
            catch (UnderflowException const &exception)
            {
                std::cout << exception.what() << std::endl;
            }
       
            //free memory for the game
            delete theGame;
        }
        while (replay() != 'N');
    }
    else
    {
        std::cout << "Exiting the Program" << std::endl;
    }
}
