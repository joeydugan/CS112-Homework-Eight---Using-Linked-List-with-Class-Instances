/*----
  signature: main: void -> int
  purpose: Testing the class CardPile

  by: Joey Dugan
  last modified: 4/14/22
----*/

#include <cstdlib>
#include <iostream>
#include <string>
#include <cmath>
#include "CardPile.h"
#include "GameCard.h"
#include "Node.h"
using namespace std;

int main()
{
    cout << boolalpha;


    // testing constructors


    cout << "\n*** testing constructors ***" << endl;

    CardPile pile1;
    CardPile pile2("Named");

    
    pile2.add_card(GameCard("Testing", "Testing", 1, 1));
    pile2.add_card(GameCard("Testing", "Testing", 2, 2));
    pile2.add_card(GameCard("Testing", "Testing", 3, 3));
    pile2.add_card(GameCard("Testing", "Testing", 4, 4));


    // testing add card and display method


    cout << "\n*** testing add card and display method" << endl << endl;

    cout << "Should Display: Card Pile is Empty and four cards that say testing"
         << " under name and ability with numbers that descend from 4 to 1 in power "
         << "and summoning cost.\n\n";

    pile1.display();

    cout << "\n";

    pile2.display();


    // testing accesors


    cout << "\n*** testing accessors ***\n\n";

    cout << (pile1.get_name() == "Unnamed") << endl;
    cout << (pile2.get_name() == "Named") << endl;

    cout << (pile1.get_size() == 0) << endl;
    cout << (pile2.get_size() == 4) << endl;

    cout << (pile1.get_top_card() == GameCard("The Card Pile is empty, there is nothing to return", "x", 0, 0)) << endl;
    cout << (pile2.get_top_card() == GameCard("Testing", "Testing", 4, 4)) << endl;


    // testing mutators


    cout << "\n*** testing mutators ***\n\n";

    pile1.set_name("Pile1 the first of Piles");
    cout << (pile1.get_name() == "Pile1 the first of Piles") << endl;

    cout << (pile2.remove_card().to_string() == "Name: Testing\nAbility: Testing\nPower: 4\nSummoning Cost: 4") << endl;
    cout << (pile2.get_size() == 3) << endl;


    // testing copy construtor


    cout << "\n*** testing copy constructor ***\n\n";

    cout << "Should display true, true, then false: \n";

    CardPile pile3(pile2);

    cout << (pile2.get_top_card() == pile3.get_top_card()) << endl;

    pile3.add_card(GameCard("This is a distinctively different card", "Being different", 100000, 1000000000));

    cout << (pile2.get_size() != pile3.get_size()) << endl;
    cout << (pile2.get_top_card() == pile3.get_top_card()) << endl;

    cout << "\nDisplaying pile2 and pile3 just to show that pile3 is a deep copy and that it has an extra top card\n" << endl;

    pile2.display();
    pile3.display();

    cout << "\n";


    // testing overloaded assignment operator


    cout << "\n*** testing overloaded assignment operator\n\n";

    pile1 = pile3;

    cout << (pile1.get_size() == pile3.get_size()) << endl;

    pile1.add_card(GameCard("This is a distinctively different card from what is in pile 3", "Being different", 100000, 1000000000));
    
    cout << "\nPile 1 should be the same as Pile 3 except for a different top card\n" << endl;

    pile1.display();
    pile3.display();

    return EXIT_SUCCESS;
}