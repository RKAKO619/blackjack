#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;


int generateRandomNumber(int min, int max) {
    return min + (rand() % (max - min + 1));
}


int playertotal = 0;
int dealertotal = 0;
int playerscards[10];
int dealerscards[10];
int playerCardCount = 2;
int dealerCardCount = 2;

int main() {
    srand(static_cast<unsigned int>(time(0)));

    char start, hs;
    cout << "Start Blackjack?(y/n): ";
    cin >> start;

    if (start == 'y') {
        cout << "Starting Blackjack!" << endl;


        playerscards[0] = generateRandomNumber(1, 11);
        playerscards[1] = generateRandomNumber(1, 11);
        playertotal = playerscards[0] + playerscards[1];


        dealerscards[0] = generateRandomNumber(1, 11);
        dealerscards[1] = generateRandomNumber(1, 11);
        dealertotal = dealerscards[0] + dealerscards[1];


        cout << "Your cards: " << playerscards[0] << " and " << playerscards[1] << endl;
        cout << "Your total: " << playertotal << endl;
        cout << "Dealer's visible card: " << dealerscards[0] << endl;

        if (dealertotal == 21) {
            cout << "Dealer has Blackjack! You lose." << endl;
            return 0;
        }


        while (true) {
            cout << "Hit or stand?(h/s): ";
            cin >> hs;

            if (hs == 'h') {

                int newCard = generateRandomNumber(1, 11);
                playerscards[playerCardCount++] = newCard;
                playertotal += newCard;

                cout << "You drew a " << newCard << ". Your total is now: " << playertotal << endl;


                if (playertotal > 21) {
                    cout << "You bust! Your total is " << playertotal << ". You lose." << endl;
                    return 0;
                }
            } else if (hs == 's') {

                break;
            } else {
                cout << "Invalid input. Please enter 'h' or 's'." << endl;
            }
        }


        cout << "Dealer's turn..." << endl;
        cout << "Dealer's hidden card was: " << dealerscards[1] << endl;
        cout << "Dealer's total: " << dealertotal << endl;

        while (dealertotal < 17) {
            int newCard = generateRandomNumber(1, 11);
            dealerscards[dealerCardCount++] = newCard;
            dealertotal += newCard;

            cout << "Dealer drew a " << newCard << ". Dealer's total is now: " << dealertotal << endl;
        }

        if (dealertotal > 21) {
            cout << "Dealer busts! You win!" << endl;
        } else if (playertotal > dealertotal) {
            cout << "You win with " << playertotal << " against the dealer's " << dealertotal << "!" << endl;
        } else if (playertotal < dealertotal) {
            cout << "Dealer wins with " << dealertotal << " against your " << playertotal << "." << endl;
        } else {
            cout << "It's a tie at " << playertotal << "!" << endl;
        }

    } else {
        cout << "Why are you here then?" << endl;
    }

    return 0;
}
