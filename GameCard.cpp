/*----
  signature: GameCard: Class
  purpose: A class for game cards for any particular card game
           in which they could be used

  by: Joey Dugan
  last modified: 4/13/22 - Added Overloaded == operator
                 2/25/22 - created implementation file
----*/

#include <cstdlib>
#include <iostream>
#include <string>
#include <cmath>
#include "GameCard.h"
using namespace std;

// constructors

GameCard::GameCard()
{
    name = "Beholder";
    ability = "Magic Powers";
    power = 18;
    summoningCost = 100;
}

GameCard::GameCard(string init_name, string init_ability, int init_power, int init_summoningCost)
{
    name = init_name;
    ability = init_ability;
    power = init_power;
    summoningCost = init_summoningCost;
}

// accesors

string GameCard::get_name() const
{
    return name;
}

string GameCard::get_ability() const
{
    return ability;
}

int GameCard::get_power() const
{
    return power;
}

int GameCard::get_summoningCost() const
{
    return summoningCost;
}

// mutators

void GameCard::set_name(string new_name)
{
    name = new_name;
}

void GameCard::set_ability(string new_ability)
{
    ability = new_ability;
}

void GameCard::set_power(int new_power)
{
    power = new_power;
}

void GameCard::set_summoningCost(int new_summoningCost)
{
    summoningCost = new_summoningCost;
}

// overloaded == operator

bool GameCard::operator==(const GameCard& rhs)
{
    if(name == rhs.name && ability == rhs.ability && power == rhs.power && summoningCost == rhs.summoningCost)
    {
        return true;
    }
    else
    {
        return false;
    }
}

// other methods

/* signature: void -> void
       purpose: expects nothing and returns nothing while having the
                side effect of printing the data fields of the class

        tests: 
        GameCard John("Skeleton", "Rattling Bones", 10, 25);
        if John.display()
        Screen should print, Skeleton, Rattling Bones, 10, 25 all on their
        own lines

        GameCard Leslie("Ghoul", "Screaming", 8, 10);
        Screen should print, Ghoul, Screaming, 8, 10 all on thier own
        lines
 */

void GameCard::display() const
{
    cout << name << endl;
    cout << ability << endl;
    cout << power << endl;
    cout << summoningCost << endl;
}

/* signature: void -> string
        purpose: expects nothing and returns a string formatted to display
                 each data field of the card on its own line. There are
                 no printing side effects.
        
        tests:
        GameCard Frank:
        if John.to_string()
        string should be:
        Name: Beholder
        Ability: Magic Powers
        Power: 18
        Summoning Cost: 100

        GameCard Leslie("Picture Frame", "Hanging Out", 50, 45);
        if Leslie.to_string()
        string should be:
        Name: Picture Frame
        Ability: Hanging Out
        Power: 50
        Summoning Cost: 45
*/

string GameCard::to_string() const
{
    return "Name: " + name + "\nAbility: " + ability + "\nPower: " + std::to_string(power)
           + "\nSummoning Cost: " + std::to_string(summoningCost);
}