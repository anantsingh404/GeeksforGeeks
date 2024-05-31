//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// UNASSIGNED is used for empty cells in sudoku grid 
#define UNASSIGNED 0  

// N is used for the size of Sudoku grid.  
// Size will be NxN  
#define N 9  


// } Driver Code Ends
class Solution 
{
    public:
    bool valid(int num,int grid[N][N],int x,int y)
    {
        for(int i = 0;i<N;i++){
            if(i!=x and grid[i][y] == num)return false;
        }   
        for(int j = 0;j<N;j++){
            if(j!=y and grid[x][j] == num) return false;
        }
        int s_row = (x/3)*3;
        int s_col = (y/3)*3;
        for(int i = s_row ; i<=s_row+2 ; i++)
        {
            for(int j = s_col ; j<=s_col+2 ; j++)
            {
                if(i!=x and y!=j and grid[i][j] == num) return false;
            }
        }
        return true;
    }
    //Function to find a solved Sudoku. 
    bool SolveSudoku(int grid[N][N])  
    { 
        // Your code here
        for(int i=0;i<N;i++)
        {
            for(int j=0;j<N;j++)
            {
                if(grid[i][j]==0)
                {
                    for(int flag=1;flag<=9;flag++)
                    {
                        if(valid(flag,grid,i,j))
                        {
                            grid[i][j]=flag;
                            bool np=SolveSudoku(grid);
                            if(np)
                            {
                                return true;
                            }
                             grid[i][j]=0;
                        }
                    }
                    return false;
                   
                }
            }
           
        }
         return true;
        
    }
    
    //Function to print grids of the Sudoku.
    void printGrid (int grid[N][N]) 
    {
        // Your code here 
        for(int i = 0;i<N;i++){
            for(int j = 0;j<N;j++){
                cout << grid[i][j] << " ";
            }
        }
    }
};


//{ Driver Code Starts.

int main() {
	int t;
	cin>>t;
	while(t--)
	{
		int grid[N][N];
		
		for(int i=0;i<9;i++)
		    for(int j=0;j<9;j++)
		        cin>>grid[i][j];
		        
		Solution ob;
		
		if (ob.SolveSudoku(grid) == true)  
            ob.printGrid(grid);  
        else
            cout << "No solution exists";  
        
        cout<<endl;
	}
	
	return 0;
}
// } Driver Code Ends