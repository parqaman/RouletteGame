#include "Game.h"
#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

Game::Game()
{
    balance = 10000;
}


void Game::eingabe()
{
        srand(time(0));
        cout << "Aktuelles Vermoegen: " << balance << endl << endl;

        cout << "Geben Sie Ihren Einsatz ein: ";
        cin >> stake;
        while (stake < 0) {
            cout << "Einsatz muss groesser als 0 sein." << endl << "Geben Sie Ihren Einsatz: ";
            cin >> stake;
        }

        radPos = rand() % 27;

        if(radPos%2 == 0){
            radFarbe = 'r';
        }
        else {
            radFarbe = 's';
        }

        if(radPos%3 == 0){
            radSpalte = 1;
        }
        else if(radPos%3 == 1){
            radSpalte = 2;
        }
        else if(radPos%3 == 2){
            radSpalte = 3;
        }

        cout << endl << "pos: " << radPos << endl << "farbe: " << radFarbe << endl << "spalte: " << radSpalte << endl << endl;

}

void Game::gamestate(bool win)
{
    cout << endl;
    if(win){
        cout << "Herzlichen Glueckwunsch!" << endl;
        balance = balance + (2*stake);
    }
    else {
        cout << "Sie haben verloren!" << endl;
        balance = balance - stake;
        if(balance <= 0){
            cout << "Game over" << endl;
        }
    }
}

void Game::spielmodus()
{
    cout << "Waehlen Sie ein Spielmodus ein!" << endl
         << "f fuer farbe" << endl << "s fuer Spalte" << endl << "z fuer einzelne Zahl" << endl
         << "Spielmodus: ";
    cin >> input;
    cout << endl;
    switch (input) {
    case 'f' : farbemodus(); break;
    case 's' : spaltemodus(); break;
    case 'z' : einzelnzahlmodus(); break;
    default : cout << "Falsche Eingabe!"; spielmodus();
    }
}

void Game::farbemodus()
{
    char farbe;

    cout << "r fuer rot" << endl << "s fuer schwarz" << endl << "Waehlen Sie eine Farbe ein: ";
    cin >> farbe;

    if(radFarbe == farbe){
        gamestate(true);
    }
    else {
        gamestate(false);
    }
}

void Game::spaltemodus()
{
    int spalte;

    cout << "Waehlen Sie eine Spalte ein: ";
    cin >> spalte;

    if(radSpalte == spalte){
        gamestate(true);
    }
    else {
        gamestate(false);
    }
}

void Game::einzelnzahlmodus()
{
    int bet;
    cout << "Geben Sie die Zahl, auf die Sie wetten (0 bis 26): ";
    cin >> bet;
    bet = bet%27;

    if(bet == radPos){
        gamestate(true);
    }
    else {
        gamestate(false);
    }
}