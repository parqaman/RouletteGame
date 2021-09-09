#ifndef GAME_H
#define GAME_H


class Game
{
    int balance;
    int stake, radPos, radSpalte;
    char radFarbe;

    void gamestate(bool win);
    void farbemodus();
    void spaltemodus();
    void einzelnzahlmodus();


public:
    Game();
    void spielmodus();

    int getBalance(){
        return balance;
    }

    char input;

    void eingabe();
};

#endif // GAME_H
