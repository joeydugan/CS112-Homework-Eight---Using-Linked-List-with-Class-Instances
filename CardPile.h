/*----
  header file for Class: CardPile

  A pile of cards created using a linked list

  by: Joey Dugan
  last modified: 4/13/22
----*/

#ifndef CARDPILE_H    
#define CARDPILE_H
#include <string>
#include "GameCard.h"
#include "Node.h"

class CardPile
{
    public: 

    // constructors

        CardPile();
        CardPile(string init_name);

    // accessors

        string get_name() const;
        int get_size() const;
        GameCard get_top_card() const;

    // mutators
    
        void set_name(string new_name);

    // copy constructor 

        CardPile(const CardPile& a_card);

    // overloaded assignment operator

        CardPile& operator=(const CardPile& rhs);

    // destructor
    
        ~CardPile();

    // other methods

        /*
            function: display: void -> void
            purpose: Expects nothing and returns nothing, has 
                     side effect of printing the card pile

            tests: 
            for 
            CardPile test;

            should display: CardPile is Empty

            test.add_card(GameCard("Rick", "Magic", 14, 80))

            should display: 
            Name: Rick
            Ability: Magic
            Power: 14
            Summoning Cost: 80
        */

        void display() const;

        /*
            function: add_card: GameCard -> void
            purpose: adding a gamecard to the top of the card 
                     pile while returning nothing.
            
            tests:
            
            for 
            CardPile test;

            should display: CardPile is Empty

            test.add_card(GameCard("Rick", "Magic", 14, 80))

            should display: 
            Name: Rick
            Ability: Magic
            Power: 14
            Summoning Cost: 80
        */

        void add_card(GameCard a_card);

        /*
            function: remove_card: void -> GameCard
            purpose: removes the top card from the card pile and
                     returns the object of the card removed.

            tests:

            for 
            CardPile test;
            test.add_card(GameCard("Rick", "Magic", 14, 80))
            test.add_card(GameCard("Never", "Ever", 4, 0))
            test.add_card(GameCard("Wow", "Great", 8, 9))

            should display three cards

            test.remove_card()

            should display two cards

            test.remove_card()

            should display one card
        */

        GameCard remove_card();


    private:

        string name;
        int size;
        Node* cards;

};

#endif