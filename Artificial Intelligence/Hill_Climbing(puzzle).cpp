#include<bits/stdc++.h>
using namespace std;

void initialize(int mat[3][3]) {
    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) {
            if(i==1 && j==1) {
                mat[i][j] = 0;
            }
            else {
                cin >> mat[i][j];
            }
        }
    }
}

void displayGrid(int mat[3][3]) {
    cout << "\n+-----------+";
    for(int i=0; i<3; i++) {
        cout << "\n|";
        for(int j=0; j<3; j++) {
            if(i==1 && j==1) {
                cout << setw(2) << " " << setw(2) << "|";    
            }
            else
                cout << setw(2) << mat[i][j] << setw(2) << "|";
        }
    }
    cout << "\n+-----------+\n";
}

int heuristic(int mat[3][3],int fstate[3][3]) {
    int cost = 0;
    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) {
            if(mat[i][j] != fstate[i][j])
                cost++;
        }
    }
    return cost;
}

pair<int, int> searchEmpty(int mat[3][3]) {
    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) {
            if(mat[i][j] == 0)
                return {i, j};
        }
    }
}

void hillClimbing(int mat[3][3],int fstate[3][3], int initialCost) {
    int bestcost = initialCost, newcost = 0;
    pair<int, int> l;

    while(bestcost > 0) {
        l = searchEmpty(mat);
        int x = l.first;
        int y = l.second;
        if(bestcost > 0 && y+1 < 3) {
            swap(mat[x][y], mat[x][y+1]);
            newcost = heuristic(mat, fstate);
            if(newcost > bestcost)
                swap(mat[x][y], mat[x][y+1]);
            else
                bestcost = newcost;
        }
        if(bestcost > 0 && y-1 >= 0) {
            swap(mat[x][y], mat[x][y-1]);
            newcost = heuristic(mat, fstate);
            if(newcost > bestcost)
                swap(mat[x][y], mat[x][y-1]);
            else
                bestcost = newcost;
        }
        if(bestcost > 0 && x+1 < 3) {
            swap(mat[x][y], mat[x+1][y]);
            newcost = heuristic(mat, fstate);
            if(newcost > bestcost)
                swap(mat[x][y], mat[x+1][y]);
            else
                bestcost = newcost;
        }
        if(bestcost > 0 && x-1 >= 0) {
            swap(mat[x][y], mat[x-1][y]);
            newcost = heuristic(mat, fstate);
            if(newcost > bestcost)
                swap(mat[x][y], mat[x-1][y]);
            else
                bestcost = newcost;
        }
    }
}


int main() {
    cout << "Enter intial arrangement of 8 box puzzle : \n";
    
    int mat[3][3];
    initialize(mat);

    displayGrid(mat);

    int fstate[3][3] = {{1,2,3},{4,0,5},{6,7,8}};

    int initialCost = heuristic(mat, fstate); 
    hillClimbing(mat, fstate, initialCost);

}