#pragma once
#include <iostream>
#include <vector>
class Demineur{
    public:
    Demineur();
    void affiche();
    int parcours();
    void set_demineur(long unsigned int i,long unsigned int j);
    int distance(long unsigned int x, long unsigned int y);
    void parcours_distance();
    private:
    std::vector<int>dist;
    int bombe;
    int drapeau;
    std::vector<std::vector<std::pair<std::string,int>>> tab;
};