#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
//for player card
class Player {
    int tot;
    bool bj; //to check weather the player is black jack or not
public:
    void play()
    {
        srand(time(0)); //for random number generator
        //generating first two cards
        int a = rand() % 10 + 1; //generating random card 1-10
        int b = rand() % 10 + 1;
        cout << "first cards" << a << "," << b << endl;
        tot = a + b; //calculating total
        cout << "Total:" << tot << endl; //displaying total
        if (tot == 21) //if total of first two cards are 21 then he is blackjack
        {
            bj = true;
        }
        else
            bj = false;
        char op;
        while (tot <= 21) //loop continues until total>21
        {
            if (tot >= 17) { //our program will ask to take card when total >17 as the player has to go upto 17
                cout << "do you want another card?(y/n):";
                cin >> op;
                if (op != 'y') {
                    break;
                }
            }
            int c = rand() % 10 + 1; //generating another random card
            cout << "Card:" << c << endl; //displaying card
            tot += c; //adding to total
            cout << "Total:" << tot << endl; //displaying total
        }
    }
    int getTotal() //method to get total
    {
        return tot;
    }
    bool isBlackJack() //method to check player is black jack or not
    {
        return bj;
    }
};
//for dealer class
class Dealer {
    int tot;
    bool bj;

public:
    void play()
    {
        srand(time(0));
        int a = rand() % 10 + 1;
        int b = rand() % 10 + 1;
        cout << "first cards" << a << "," << b << endl;
        tot = a + b;
        cout << "Total:" << tot << endl;
        if (tot == 21) {
            bj = true;
        }
        else
            bj = false;
        while (tot < 17) {
            int c = rand() % 10 + 1;
            cout << "Card:" << c << endl;
            tot += c;
            cout << "Total:" << tot << endl;
        }
    }
    int getTotal()
    {
        return tot;
    }
    bool isBlackJack()
    {
        return bj;
    }
};
int main()
{
    //creating objects
    Player p;
    Dealer d;
    char op;
    do {
        //player playing game and displays his total
        p.play();
        cout << "Player Cards in hand:" << p.getTotal() << endl;
        //dealer playing game and displays his total
        d.play();
        cout << "Dealer Cards in hand:" << d.getTotal() << endl;
        //checking who wins the game
        if (p.getTotal() > 21) {
            cout << "Game Result:Player Bursts" << endl;
        }
        else if (p.isBlackJack()) {
            cout << "Game Result:Player BlackJack" << endl;
        }
        else if (d.isBlackJack()) {
            cout << "Game Result:Dealer BlackJack" << endl;
        }
        else if (p.getTotal() > 21 && d.getTotal() <= 21) {
            cout << "Game Result:Player Burst" << endl;
        }
        else if (d.getTotal() > 21 && p.getTotal() <= 21) {
            cout << "Game Result:Player Wins" << endl;
        }
        else if (d.getTotal() == p.getTotal()) {
            cout << "Game Result:Push" << endl;
        }
        else if (d.getTotal() < p.getTotal()) {
            cout << "Game Result:Player Wins" << endl;
        }
        else if (d.getTotal() > p.getTotal()) {
            cout << "Game Result:Player Bursts" << endl;
        }
        //checking if player want to continue or not
        cout << "Do you want to continue?(y/n):";
        cin >> op;
        if (op != 'y') {
            break;
        }
    } while (true);
}