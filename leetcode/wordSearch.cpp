#include<iostream>
#include<vector>

// remember the in-place mark in board is way more efficient than using table visited 

using namespace std; 

class Solution {

    bool searchBoard( // vector<vector<bool> > &visited,
		      string it , int i,
		      vector< vector<char> > & board, int x, int y , int xcol, int ycol
		    ){

	if( i >= it.length() ) return false;
	if( x < 0 || y < 0 || x >= xcol || y >= ycol ) return false;

	if( board[x][y] == it[i] ) {
	    if( i == (it.length() -1)) {
		return true;
	    }
	    else{
		char c = board[x][y] ;
		board[x][y]='*';
		bool res =  searchBoard(  it, i+1, board, x+1, y , xcol, ycol )
		    || searchBoard(   it, i+1, board, x-1, y, xcol, ycol  )
		    || searchBoard(   it, i+1, board, x, y+1 , xcol, ycol )
		    || searchBoard(   it, i+1, board, x, y-1 , xcol, ycol ); 

		board[x][y] = c;
		return res;
	    }
	}
	else return false;


    }

public:
    bool exist(vector<vector<char>>& board, string words) {
	// vector<vector<bool> > visited( board.size(), vector<bool>(board[0].size(), false));
	int ycol = board[0].size();
	int xcol = board.size();
	for( int x = 0 ; x < xcol;  x++){
	    for( int y = 0 ; y < ycol ; y++){
		if ( true == searchBoard(   words , 0,  board , x, y , xcol, ycol )) return true; 
	    }
	}
	return false;

    }

};



int main(){
    vector<vector<char> > board = {
	{'o', 'a', 'a','n'},
	{'e', 't', 'a','e'},
	{'i', 'h', 'k','r'},
	{'i', 'f', 'l','v'}
    };
    Solution a; 
    string words = "oath";
    cout << a.exist( board, words ) <<endl;

    return 0; 
}

