/*----
  header file for class: GameCard

  by: Joey Dugan
  last modified: 4/13/22 - Added Overloaded == operator
                 2/25/22 - created header file
----*/

#ifndef GAMECARD_H    
#define GAMECARD_H
#include <string>
using namespace std;

class GameCard
{
    public:

    //constructors

    GameCard();
    GameCard(string init_name, string init_ability, int init_power, int init_summoningCost);

    //accessors

    string get_name() const;
    string get_ability() const;
    int get_power() const;
    int get_summoningCost() const;

    //mutators

    void set_name(string new_name);
    void set_ability(string new_ability);
    void set_power(int new_power);
    void set_summoningCost(int new_summoningCost);

    //overloaded == operator

    bool operator==(const GameCard& rhs);


    //other methods:

    /* signature: void -> void
       purpose: expects nothing and returns nothing while having the
                side effect of printing the data fields of the class
    */
    void display() const;

    /* signature: void -> string
       purpose: expects nothing and returns a string version of the 
                data fields of the class
    */
    string to_string() const;

    


    private:
    string name;
    string ability;
    int power;
    int summoningCost;



};

#endif