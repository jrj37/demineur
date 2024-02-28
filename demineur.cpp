#include <iostream>
#include "demineur.h"
#include <random>

Demineur::Demineur(){

    std::random_device rd;
    std::mt19937 engine(rd());
    std::uniform_int_distribution<int> distribution(0, 1); 
    for (int i=0;i<10;i++){
        std::vector<int> vector;
        std::vector<std::pair<std::string,int>> vector2;
        for (int i=0;i<10;i++){
            int rd=distribution(engine);
            vector.push_back(rd);
            std::pair<std::string,int> p("#",rd);
            vector2.push_back(p);
            }
        tab.push_back(vector);
        tab2.push_back(vector2);
    }
    }
void Demineur::affiche(){
    for (auto const& row : tab2) {
        for (auto const& elem : row) {
            std::cout << elem.first << " ";
        }
        std::cout << std::endl;
    }
}
int Demineur::parcours(){
    for (auto const& row: tab2){
        for (auto const&elem :row){
            if (elem.second==1){
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
