//
//  main.cpp
//  BlackJack_3
//
//  Created by Lex Huismans on 25-04-17.
//  Copyright © 2017 Lex Huismans. All rights reserved.
//

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
using namespace std;

class game {
private:
    int decks;
    int amountOfCards;

public:

    game (int amountOfDecks){
        setDeck(amountOfDecks);
        setAmountOfCards(amountOfDecks);
        createDeck(amountOfDecks);
    }
    void setDeck(int k){decks = k;}
    void setAmountOfCards(int k){amountOfCards = k*52;}
    void createDeck(int k){
        for (int i = 0; i <= 4*k-1; i++){
            for (int j = 0; j < 13; j++){
                deck [i][j] = 1;
            }
        }
    }
    void getCards (int amount){
        while (amountOfCards > amountOfCards-amount){

            bool gotCard = false;
            int type;
            int number;
            //picking a card
            while (gotCard == false) {

                //selecting a card
                type = 1 + rand()%(4*decks);
                number = 1 + rand()%13;

                //checking if it still in the deck
                if (deck [type-1][number-1] == 1) {

                    deck [type-1][number-1]--;
                    gotCard = true;
                    break;
                }else{continue;}
            }

            //returning the card value
            if (number == 1 || number == 11 || number == 12 || number == 13){
                //setting the type of card
                switch (number){
                    case 1 :
                        cout<<'A'<<", ";
                        break;
                    case 11:
                        cout << 'J' << ", ";
                        break;
                    case 12:
                        cout << 'Q' <<", ";
                        break;
                    case 13:
                        cout << 'K' <<", ";
                        break;
                }

            }else {
                cout << number <<", ";
            }
            amountOfCards--;


        }
        cout << "we are done" <<endl;
    }

};

int main (){

    srand (time(NULL));
    //creating a class with 3 decks;
    game one(1);
    one.getCards(1);

    return 0;
}
