#include <iostream>
#include "update_game.h"
#include "demineur.h"
Game::Game(){}

int Game::update_game(Demineur *demineur){
    std::pair<int,int> p;
    std::cout << "Veuillez entrer quelque chose : ";
    std::cin >> p.first >> p.second;
    demineur->set_demineur(p.first,p.second);
    return 1;
}