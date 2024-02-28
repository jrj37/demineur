#include <iostream>
#include "demineur.h"
int main(){
    Demineur demineur= Demineur();
    demineur.affiche();
    if (demineur.parcours()==1){
        return 1;
    }
    return 0;
}