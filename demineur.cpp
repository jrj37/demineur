#include <iostream>
#include "demineur.h"
#include <random>

Demineur::Demineur(){

    std::random_device rd;
    std::mt19937 engine(rd());
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
int Demineur::parcours(){
    for (auto const& row: tab){
        for (auto const&elem :row){
            if (elem==1){
                std::cout<< "FIN DU JEU"<<std::endl;
                return 1;
            }
            else{
               std::cout<< "Jeu continue"<<std::endl; 
               return 0;
            }
        }
    }
    return 0;
}
