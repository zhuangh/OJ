#include<iostream>
#include<vector>

using namespace std;

template <typename T> 
void print( vector<vector<T> > & grid){
    for( int i = 0 ; i < grid.size() ; i++){
	for( int j = 0 ; j < grid[i].size() ; j++){
	    cout<<grid[i][j]<<" ";
	}
	cout<<endl;
    }
}

// 1. BFS , DFS: recursive and iteraitive 
// 2. Union-find？ How 

class Solution {
    int num ; 
public:
    // int numIslands(vector<vector<char> >& grid) {
    int numIslands(vector<vector<char> >& grid) {
	int num = 0 ; 
	if( grid.size() <= 0 ) return 0;

	vector<vector< int > > visited ( grid.size(), vector< int > ( grid[0].size(), 0));
	/*
	cout<<visited.size() <<endl;
	cout<<visited[2].size() <<endl;
	cout<<grid[3][4]<<endl;
	*/

	for( int i = 0 ; i < grid.size() ; i++){
	    for( int j = 0 ; j < grid[i].size() ; j++){
//		cout<< i << " , " <<j << " ";
//		cout<<visited[i][j]<<" grid " << grid[i][j] <<endl;
		if(visited[i][j] != 1 && grid[i][j] == '1' ) {
		    num++;
		    DFS( grid, visited , i , j );
		}
		else continue; 
	    }
	}
//	print(visited);
	return num;
    }

    void DFS( vector<vector<char> > & grid , vector<vector<int> > & visited , int i , int j ){
	if ( visited[i][j] != 0 || grid[i][j] != '1'  ) return ;

	if ( grid[i][j]  == '1' ){
	    visited[i][j] = 1; 
	    if( i > 0 ) DFS(grid, visited, i-1, j); 
	    if( i < grid.size() -1 ) DFS(grid, visited, i+1, j); 
	    if( j > 0 ) DFS(grid, visited, i, j-1); 
	    if( j < grid[i].size()-1 ) DFS(grid, visited, i, j+1); 
	}
    }
};

int main(){
    Solution  a; 
    vector<vector<char> > grid;
    grid = {{'1','1','0','0','0'}, {'1','1','0','0','0'}, {'0','0','1','1','0'}, {'0','0','0','1','1'} };
    grid = {{'1','1','0','0','0'} };
    grid = {{'1'}};
    // grid = { {'1','1','0','0','0'}, {'1','1','1','0','0'}, {'0','0','1','1','0'}, {'0','0','0','1','1'} };
    print(grid);
    cout<<a.numIslands( grid )<<endl;; 
    return 0; 
}


