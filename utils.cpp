/*******************************************************************************
 * Name: Utils
 * Description: A set of utilities for checking user input and printing menus.
 * Functionality includes getString, getInt, getDouble, getChar, setRange,
 * fillArray, mainMenu, replay, and selectionYN
 ******************************************************************************/

#include "utils.hpp"
#include <iostream>
#include <string>
#include <cstdlib>

/***********************************************************************
 * Name: getString
 * Description: Promts the user to input a string 
 **********************************************************************/
std::string getString()
{
    std::string input;
   
    std::cout << "Enter a character name: ";
    std::getline(std::cin, input);

    //remprompt if input is empty string
    while (input == "")
    {
        std::cout << "Empty string -- enter at least one character: ";
        std::getline(std::cin, input);
    }
    
    return input;
}

/***********************************************************************
 * Name: getInt 
 * Description: Prompts the user to input an int and validates it
 **********************************************************************/
int getInt(bool prompt)
{
    std::string input;

    //causes the function to output a generic prompt
    if (prompt == true)
    {
        std::cout << "Enter an integer: ";
    }

    //get the users input
    std::getline(std::cin, input);

    //reprompt if the input is blank or not made up of int values 
    while (input.find_first_not_of("0123456789-") != std::string::npos ||
            input == "")
    {
        std::cout << "Not an integer -- please enter an int: "; 
        std::getline(std::cin, input);
    }
       
    //convert the input to an integer
    int i = std::atoi(input.c_str());
    
    return i;
}

/***********************************************************************
 * Name: getDouble
 * Description: Prompts the user to input a double and validates it
 **********************************************************************/
double getDouble(bool prompt)
{
    std::string input;
  
    //causes the function to output a generic prompt
    if (prompt == true)
    {
        std::cout << "Enter a double: ";
    }
    
    std::getline(std::cin, input);

    while (input.find_first_not_of("0123456789.-") != std::string::npos ||
            input == "")
    {
        std::cout << "Not a double -- enter a double: ";
        std::getline(std::cin, input);
    }
        
    double d = std::atof(input.c_str());
    
    return d;
}

/************************************************************************
 * Name: getChar
 * Description: Prompts the user for a char and validates it 
 ***********************************************************************/
char getChar(bool prompt)
{
    
    std::string input;
  
    //causes the function to output a generic prompt
    if (prompt == true)
    {
        std::cout << "Enter a single alpha character: ";
    }

    std::getline(std::cin, input);

    while (input.length() == 0 || input.length() > 1 || !std::isalpha(input[0]))
    {
        std::cout << "Not a single alpha character -- enter another char: "; 
        std::getline(std::cin, input);
    }
    input[0] = toupper(input[0]);

    return input[0];
}

/************************************************************************
 * Name: setRange
 * Description: used to limit user input to a specific range
 ***********************************************************************/
int setRange(int size, int lowerRange, int upperRange)
{
    int status = -1;

    //if the input is within the desired range and 0 is
    //allowed, set status to 0
    if (size >= lowerRange && size <= upperRange)
    {
        status = 0;
    }

    return status;
}


/************************************************************************
 * Name: fillArray
 * Description: Fills an array with integers specified by the user
 ***********************************************************************/
void fillArray(int *array, int s)
{
    for (int i = 0; i < s; i++)
    {
        std::cout << "Please enter an integer for element " << i+1 << std::endl;
        array[i] = getInt(false);
    }
}

/*************************************************************************
 * Name: mainMenu
 * Description: Prints the main  menu to the screen, allows the user to make
 * one of the choices listed, and returns the choice to main.
 ************************************************************************/
int mainMenu()
{
    int choice;
    std::string mainPrompt = "Fantasy Combat Tournament 2018 Main Menu";
    
    //display the menu with a title, choices, and a user prompt
    do
    {
        std::cout << std::endl;
        std::cout << mainPrompt << std::endl << std::endl;
        std::cout << std::string(mainPrompt.length(), '-') << std::endl;
        std::cout << std::string(mainPrompt.length() / 4, ' ') << 
            "1. Start Tournament" << std::endl;
        std::cout << std::string(mainPrompt.length() / 4, ' ') << 
            "2. Exit the Program" << std::endl;
        std::cout << std::string(mainPrompt.length(), '-') 
            <<std::endl << std::endl;
        std::cout << "Please enter a choice 1-2: ";
        
        choice = getInt(false);
        
        std::cout << std::endl;
    }
    while (setRange(choice, 1, 2) != 0);

    return choice;
}

/*************************************************************************
 * Name: charSelection
 * Description: Allows the user to select a character type 
 ************************************************************************/
int charSelection()
{
    int choice;
    std::string mainPrompt = "Please select the number corresponding to the "
        "character you would like to use: ";
    do
    {
        std::cout << std::endl;
        std::cout << std::string(17, '-') << std::endl;
        std::cout << "1. Vampire" <<  std::endl;
        std::cout << "2. Barbarian" << std::endl;
        std::cout << "3. Blue Men" << std::endl;
        std::cout << "4. Medusa" << std::endl;
        std::cout << "5. Harry Potter" << std::endl;
        std::cout << std::string(17, '-') 
            <<std::endl << std::endl;
        std::cout << mainPrompt;
        
        choice = getInt(false);
        
        std::cout << std::endl;
    }
    while (setRange(choice, 1, 5) != 0);

    return choice;
}

/*************************************************************************
 * Name: replay
 * Description: Prompts the user for a replay 
 ************************************************************************/
char replay()
{
    char choice;

    std::cout << "Would you like to play again? (y/n): ";
    choice = selectionYN();
    
    return choice;
}

/*************************************************************************
 * Name: selectionYN
 * Description: Allows the user to enter 'y' or 'n' for choice 
 ************************************************************************/
char selectionYN()
{
    char choice;

    choice = getChar(false);

    while (choice != 'Y' && choice != 'N')
    {
        std::cout << "Please enter either 'y' or 'n': ";
        choice = getChar(false);
    }

    return choice;
}
