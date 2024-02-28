#include <iostream>
#include <vector>
class Demineur{
    public:
    Demineur();
    void affiche();
    int parcours();
    void hide();
    private:
    int bombe;
    int drapeau;
    std::vector<std::vector<int>> tab;
    std::vector<std::vector<std::pair<std::string,int>>> tab2;
};