#include <iostream>
#include <vector>
class Demineur{
    public:
    Demineur();
    void affiche();
    int parcours();
    private:
    int bombe;
    int drapeau;
    std::vector<std::vector<int>> tab;
};