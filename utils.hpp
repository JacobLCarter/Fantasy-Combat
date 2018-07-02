#ifndef UTILS_HPP
#define UTILS_HPP

#include <string>
using std::string;

string getString();
int getInt(bool);
double getDouble(bool);
char getChar(bool);
int setRange(int size, int lowerRange, int upperRange);
void fillArray(int*, int); 
int mainMenu();
int charSelection();
char replay();
char selectionYN();

#endif
