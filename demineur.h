#include <iostream>
#include <vector>
class Demineur{
    public:
    Demineur();
    void affiche();
    private:
    int bombe;
    int drapeau;
    std::vector<std::vector<int>> tab;
};