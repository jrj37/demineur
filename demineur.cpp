#include <iostream>
#include "demineur.h"
#include <random>
#include <utility>

Demineur::Demineur(){

    std::random_device rd;
    std::mt19937 engine(rd());
    std::uniform_int_distribution<int> distribution(0,1); 
    for (int i=0;i<10;i++){
        std::vector<std::pair<std::string,int>> vector;
        for (int i=0;i<10;i++){
            int rd=distribution(engine);
            std::pair<std::string,int> p("#",rd);
            vector.push_back(p);
            }
        tab.push_back(vector);
    }
}
void Demineur::affiche(){
    for (auto const& row : tab) {
        for (auto const& elem : row) {
            std::cout << elem.first << " ";
            std::cout <<elem.second << " ";
        }
        std::cout << std::endl;
    }
}
int Demineur::parcours(){
    for (auto const& row: tab){
        for (auto const&elem :row){
            //std::cout << elem.second <<std::endl;
            if (elem.second==0){
                std::cout << "Fin du jeu" <<std::endl;
                return 1;
            }
        }
    }
    return 0;
}

int Demineur::distance(long unsigned int x, long unsigned int y){
    for (long unsigned int i=x;i<tab.size();i++){
        int d=0;
        for (long unsigned int j=y;j<tab.size();j++){
            if (tab[i][j].second!=1){
                d++;
            }
            else{
                break;
            }
        }
        dist.push_back(d);
    }
    std::cout<< "la"<<std::endl;
    for (const auto& elem:dist ){
        std::cout<< "La distance est de: "<<elem<<std::endl;
    }
    return 1;
}

void Demineur::parcours_distance(){
    int min=10;
    int marqueur=0;
    for (long unsigned int i=0;i<dist.size();i++){
       if (dist[i]<min){
        min=dist[i]+i;
        marqueur=i;
       } 
    }
    std::cout<<"Marqueur"<<marqueur<<std::endl;
}
void Demineur::set_demineur(long unsigned int i,long unsigned int j){
    if (i<tab.size() && j<tab.size() ){
        tab[i][j].second=0;
    }
    else{
        std::cout <<"Erreur, les coordonnées sont incorrectes"<<std::endl;
    }
}