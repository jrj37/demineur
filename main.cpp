#include <iostream>
#include "demineur.h"
#include "update_game.h"

int main(){
    Demineur demineur= Demineur();
    //demineur.affiche();
    //Game game=Game();
    //game.update_game(&demineur);
    demineur.set_demineur(0,0);
    demineur.set_demineur(1,0);
    demineur.affiche();
    demineur.distance(0,0);
    demineur.parcours_distance();
    if (demineur.parcours()==1){
        return 1;
    }
    return 0;
}