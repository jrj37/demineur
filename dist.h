#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <cmath>

// Structure pour stocker les coordonnées d'une cellule
class Distance {
    public:
    Distance();
    Distance(int x,int y,int d);
    // Fonction pour vérifier si les coordonnées sont valides dans la matrice
    bool is_valid(int x,int y,int rows, int cols);
    Distance findNearestOne(std::vector<std::vector<int>>& matrix,int start_x, int start_y);
    void set_data(int x, int y, int d);
    int get_x();
    int get_y();
    int get_distance();
   
    private:
    int x;
    int y;
    int distance; // Distance par rapport à la coordonnée de départ
};