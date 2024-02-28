#include <iostream>
#include "demineur.h"
#include <random>

Demineur::Demineur(){

    std::random_device rd;
    std::mt19937 engine(rd()); // Utiliser le générateur mersenne_twister_engine
    std::uniform_int_distribution<int> distribution(0, 1); 
    for (int i=0;i<10;i++){
        std::vector<int> vector;
        for (int i=0;i<10;i++){
            vector.push_back(distribution(engine));
            }
        tab.push_back(vector);
    }
    }
void Demineur::affiche(){
    for (auto const& row : tab) {
        for (auto const& elem : row) {
            std::cout << elem << " ";
        }
        std::cout << std::endl;
    }
}
