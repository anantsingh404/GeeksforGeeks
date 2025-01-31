//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
   bool valid(int num, vector<vector<int>>& grid, int x, int y) {  
    int N = grid.size();
    
    // Check row
    for(int i = 0; i < N; i++) {
        if(i != x && grid[i][y] == num) return false;
    }   

    // Check column
    for(int j = 0; j < N; j++) {
        if(j != y && grid[x][j] == num) return false;
    }

    // Check 3x3 subgrid
    int s_row = (x / 3) * 3;
    int s_col = (y / 3) * 3;
    for(int i = s_row; i < s_row + 3; i++) {
        for(int j = s_col; j < s_col + 3; j++) {
            if(i != x && j != y && grid[i][j] == num) return false;
        }
    }

    return true;
}

void printGrid(vector<vector<int>>& grid) {
    int N = grid.size();
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }
}

bool solve(vector<vector<int>>& grid) {
    int N = grid.size();
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            if(grid[i][j] == 0) { 
                for(int k = 1; k <= 9; k++) {   
                    if(valid(k, grid, i, j)) {  
                        grid[i][j] = k;
                        if(solve(grid)) {
                            return true;
                        }
                        grid[i][j] = 0;
                    }
                }
                return false; // Backtrack if no number fits
            }
        }
    }
    return true; // Solution found
}

void solveSudoku(vector<vector<int>>& mat) {
    solve(mat);
   // printGrid(mat);
}
};

//{ Driver Code Starts.

vector<int> inputLine() {
    string str;
    getline(cin, str);
    stringstream ss(str);
    int num;
    vector<int> res;
    while (ss >> num) {
        res.push_back(num);
    }
    return res;
}

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<vector<int>> grid;
        for (int i = 0; i < 9; i++) {
            vector<int> v = inputLine();
            grid.push_back(v);
        }

        Solution ob;

        ob.solveSudoku(grid);

        for (auto v : grid) {
            for (auto elem : v) {
                cout << elem << " ";
            }
            cout << endl;
        }

        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends