#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <cmath>
#include "dist.h"

using namespace std;

// Structure pour stocker les coordonnées d'une cellule
struct Point {
    int x;
    int y;
    int distance; // Distance par rapport à la coordonnée de départ
};

int Distance::get_x(){
    return this->x;
}
int Distance::get_y(){
    return this->y;
}
int Distance::get_distance(){
    return this->distance;
}
Distance::Distance(){}
Distance::Distance(int x,int y,int d):x(x),y(y),distance(d){}

// Fonction pour vérifier si les coordonnées sont valides dans la matrice
bool Distance::is_valid(int a,int b,int rows, int cols){
    return (a >= 0 && a < rows && b >= 0 && b < cols);
}

void Distance::set_data(int x, int y, int d){
    this->x=x;
    this->y=y;
    this->distance=d;
}

Distance Distance::findNearestOne(vector<vector<int>>& matrix, int start_x, int start_y) {
    int rows = matrix.size();
    if (rows == 0) return Distance(-1, -1, -1);
    int cols = matrix[0].size();

    vector<vector<bool>> visited(rows, vector<bool>(cols, false));
    queue<Distance> q;
    q.push(Distance(start_x, start_y, 0));
    visited[start_x][start_y] = true;

    while (!q.empty()) {
        Distance curr = q.front();
        q.pop();

        if (matrix[curr.x][curr.y] == 1) {
            return curr;
        }

        // Déplacements possibles : haut, bas, gauche, droite, diagonales
        int dx[] = {-1, 1, 0, 0, -1, -1, 1, 1};
        int dy[] = {0, 0, -1, 1, -1, 1, -1, 1};

        for (int i = 0; i < 8; ++i) { // On parcourt les 8 directions possibles
            int new_x = curr.x + dx[i];
            int new_y = curr.y + dy[i];
            if (is_valid(new_x, new_y, rows, cols) && !visited[new_x][new_y]) {
                q.push(Distance(new_x, new_y, curr.distance + 1));
                visited[new_x][new_y] = true;
            }
        }
    }
    return Distance(-1, -1, -1);
}

int main() {
    // Exemple de matrice
    vector<vector<int>> matrix = {
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 1},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0}
    };
    
    int start_x = 0; // Coordonnée x de départ
    int start_y = 0; // Coordonnée y de départ
    
    Distance nearestOne = Distance().findNearestOne(matrix, start_x, start_y);
    
    if (nearestOne.get_x() != -1 && nearestOne.get_y() != -1) {
        cout << "Le 1 le plus proche est à la position : (" << nearestOne.get_x() << ", " << nearestOne.get_y() << ")" << endl;
        cout << "La distance est : " << nearestOne.get_distance() << endl;
    } else {
        cout << "Aucun 1 trouvé dans la matrice." << endl;
    }
    
    return 0;
}
