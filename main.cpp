#include "Game.h"
#include <iostream>

using namespace std;

int main()
{
    cout << endl;
    Game start;

    while (start.getBalance() > 0) {
        start.eingabe();
        start.spielmodus();
    }

    cout << endl;
}