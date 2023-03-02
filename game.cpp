#include <bits/stdc++.h>
using namespace std;

//Rows and columns of grid
int rows = 8;
int columns  = 8;
//Number of gen we want the game to play
int gen = 50;

void showgrid( vector<vector<int>>& grid_state) {
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < columns; j++) {
            if(grid_state[i][j]) {
                cout << " 1 ";
            } 
            else {
                cout << " 0 ";
            }
        }
        cout << endl;
    }
    cout << endl;
}

//Function to count neighbors
int no_of_neighbors( vector<vector<int>>& grid_state, int row, int col) {
    int count = 0;
    int validrow;
    int validcolumn;
    //Iterating throgh 8 possible neihbors indexes
    for(int i = -1; i <= 1; i++) {
        for(int j = -1; j <= 1; j++) {
             validrow = row + i;
             validcolumn = col + j;

         //Index out of grid
         if(validrow < 0 || validcolumn < 0 || validrow >= rows || validcolumn >= columns) {
                continue;
            }
            //Same element
            else if(i == 0 && j == 0) {
                continue;
            }
         //Increase number of neighbors
            else if(grid_state[validrow][validcolumn]) {
                count++;
            }
        }
    }
    return count;
}


void new_grid_state( vector<vector<int>>& grid_state) {
    //New grid for the active state of universe
    bool newgrid_state[rows][columns];

    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < columns; j++) {
       //Getting the number of neighbors
        int neighbours = no_of_neighbors(grid_state, i, j);

        //If cell is alive
            if(grid_state[i][j]) {
        // Cell with 2 or 3 neighbors stay alive
                if(neighbours == 2 || neighbours == 3) {
                    newgrid_state[i][j] = 1;
                }
         //Dead otherwise of more neighbors or less neighbors
                else {
                    newgrid_state[i][j] = 0;
                }
            }
         // If cell is dead
            else {
         //Dead Cell with  3 neighbors becomes alive
                if(neighbours == 3) {
                    newgrid_state[i][j] = 1;
                } else {
                    newgrid_state[i][j] = 0;
                }
            }
        }
    }

    //Changing the old state of universe to new state
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < columns; j++) {
            grid_state[i][j] = newgrid_state[i][j];
        }
    }
}

int main() {

    //Initializing the grid with all dead
    vector<vector<int>> grid( rows , vector<int> (columns, 0));

    // Glider pattern
    grid[1][2] = 1;
    grid[2][3] = 1;
    grid[3][2] = 1;
    grid[3][3] = 1;
    grid[3][1] = 1;

    for(int i = 0; i < gen; i++) {
        //Showing the universe state
        cout<<" Universe state: "<<i<<endl;
        showgrid(grid);
        new_grid_state(grid);
    }
    return 0;
}