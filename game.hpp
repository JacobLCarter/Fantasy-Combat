#ifndef GAME_HPP
#define GAME_HPP

#include "vampire.hpp"
#include "barbarian.hpp"
#include "blue_men.hpp"
#include "medusa.hpp"
#include "harry_potter.hpp"
#include "lineup.hpp"
#include "losers.hpp"

class Game
{
public:
    Game();
    Game(int, int);
    ~Game();
    bool getDeath();
    Lineup* getLineup(int);
    Losers* getLosers();
    Character* charCreation();
    bool playRound();
    void checkDeath(Character*);
    void fightResults();
    void printLineups();
    void printRound(int, int, int);
    void printScore();
private:
    Lineup *l1;
    Lineup *l2;
    Losers *lose;
    bool deadChar;
    int l1Score;
    int l2Score;
};
#endif
