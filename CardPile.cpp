/*----
  header file for Class: CardPile

  A pile of cards created using a linked list

  by: Joey Dugan
  last modified: 4/13/22
----*/

#include <cstdlib>
#include <iostream>
#include <string>
#include <cmath>
#include "Node.h" 
#include "GameCard.h"   
#include "CardPile.h"
using namespace std;

// constructors

CardPile::CardPile()
{
    name = "Unnamed";
    size = 0;
    cards = NULL;
}

CardPile::CardPile(string init_name)
{
    name = init_name;
    size = 0;
    cards = NULL;
}


// accessors

string CardPile::get_name() const
{
    return name;
}

int CardPile::get_size() const
{
    return size;
}

GameCard CardPile::get_top_card() const
{
    if(cards == NULL)
    {
        return GameCard("The Card Pile is empty, there is nothing to return", "x", 0, 0);
    }
    else
    {
        return cards->get_data();
    }
}


// mutators

void CardPile::set_name(string new_name)
{
    name = new_name;
}


// copy constructor 

CardPile::CardPile(const CardPile& a_cardpile)
{
    name = a_cardpile.name;
    size = a_cardpile.size;
    
    Node* curr_pile = a_cardpile.cards;
    Node* curr = cards;

    if(curr_pile == NULL)
    {
        cards = NULL;
    }

    else
    {
        cards = new Node();
        curr = cards;
        curr->set_data(curr_pile->get_data());
        curr_pile = curr_pile->get_next();
        
        while(curr_pile != NULL)
        {
            curr->set_next(new Node(curr_pile->get_data()));
            curr = curr->get_next();
            curr_pile = curr_pile->get_next();
        }
    }
    
}


// overloaded assignment operator

CardPile& CardPile::operator=(const CardPile& rhs)
{
    if (this == &rhs)
    {
        return *this;
    }
    
    name = rhs.name;
    
    Node* curr = NULL;
    Node* rhs_pile = rhs.cards;
    size = rhs.size;

    if(cards != NULL)
        cards = NULL;

    else
    {
        cards = new Node();
        curr = cards;
        curr->set_data(rhs_pile->get_data());
        rhs_pile = rhs_pile->get_next();
        
        while(rhs_pile != NULL)
        {
            curr->set_next(new Node(rhs_pile->get_data()));
            curr = curr->get_next();
            rhs_pile = rhs_pile->get_next();
        }
    }
    
    return *this;
    
}


// destructor

CardPile::~CardPile()
{
    Node* curr_ptr = cards;

    while (curr_ptr != NULL)
    {
       cards = cards->get_next();

       delete curr_ptr;

       curr_ptr = cards;
    }
}


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

void CardPile::display() const
{
    Node *curr_node_ptr = cards;

    cout << "CardPile " << name << ": " << endl;

    if (curr_node_ptr == NULL)
    {
        cout << "Card Pile is Empty" << endl;
    }

    while (curr_node_ptr != NULL)
    {
        cout << curr_node_ptr->get_data().to_string() << endl << endl;
        curr_node_ptr = curr_node_ptr->get_next();
    }

}


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

void CardPile::add_card(GameCard a_card)
{
    Node* new_node_ptr;

    new_node_ptr = new Node(a_card);

    if (cards == NULL)
    {
        cards = new_node_ptr;
        size += 1;
    }

    else
    {
        new_node_ptr->set_next(cards);
        cards = new_node_ptr;
        size += 1;
    }
}



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

GameCard CardPile::remove_card()
{
    Node* curr = cards;
    
    GameCard top = cards->get_data();

    cards = cards->get_next();

    curr->set_next(NULL);
    curr = NULL;

    delete curr;

    size -= 1;

    return top;
}

