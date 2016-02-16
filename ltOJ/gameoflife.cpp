#include <vector> 
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class Solution {
public:
    int check_nb( int y , int x , vector<vector<int> >  board , int ys, int xs ){
        int sum = 0 ; 
        int is , ie, js, je;
        if( y > 0 ) is = y-1; 
        else is = y; 
        
        if (y < ys-1 ) ie = y+1;
        else ie = y;
        
        if( x > 0 ) js = x-1; 
        else js = x; 
        
        if (x < xs-1 ) je = x+1;
        else je = x;
        
        
        for( int i = is ; i  <= ie ; i++  ){
            for( int j = js ; j  <= je ; j++  ){
                sum += board[i][j] ;
            }    
        }
        
        if( board[y][x] == 1){
            sum--; 
            if( sum  < 2) return 0;
            if( sum == 2 || sum == 3 ) return 1;
            if( sum > 3 ) return 0;
        }
        else {
            if( sum == 3 ) return 1;
        }
        
    }
    
    
    void gameOfLife1(vector<vector<int>>& board) {
        int y = board.size();
        int x = board[0].size(); 
        
        vector<vector<int>> board_new ( y, vector<int> (x,0) );
        
        for( int i = 0 ; i < y ; i++ )   {
            for( int j = 0 ; j < x ; j++){
                int live = check_nb( i , j,   board , y , x); 
                board_new[i][j] = live;
            }
        }
        board = board_new; 
    }

    void gameOfLife2(vector<vector<int>>& board) {
	// buffer
        int y = board.size();
        int x = board[0].size(); 
	vector<int>  buf_cur (x, 0) ; 
	vector<int>  buf_old (x, 0) ; 
        
        
        for ( int i = 0 ; i < y ; i++ )   {
	    swap(buf_cur, buf_old);
            for ( int j = 0 ; j < x ; j++ ){
                int live = check_nb( i , j,   board , y , x); 
                buf_cur[j] = live;
            }

	    if( i > 0 ){
		for ( int j = 0 ; j < x ; j++ ){
		    board[i-1][j] = buf_old[j]; 
		}
	    }
        }

	for ( int j = 0 ; j < x ; j++ ){
	    board[y-1][j] = buf_cur[j]; 
	}
    }

    void gameOfLife(vector<vector<int>>& board) {
	// buffer

	ifstream fin("gameoflife.in");
	if( ! fin.is_open() ) {
	    cout<<endl;
	}
	else {
	    for( string line ; getline(fin, line) ; ) {
		cout<<line<<"\n";
	    }
	    cout<<"after reading"<<endl;
	}

	fin.close();
	// for dropbox 
	// (1) buffer reading and writing 
	// (2) multithread implementation 
	// how many threads or machines ,
	//   how to decide the  threads #
	//   how to communicate among threads
	//   how to communicate among machines

        int y = board.size();
        int x = board[0].size(); 
	vector<int>  buf_cur (x, 0) ; 
	vector<int>  buf_old (x, 0) ; 
        
        
        for ( int i = 0 ; i < y ; i++ )   {
	    swap(buf_cur, buf_old);
            for ( int j = 0 ; j < x ; j++ ){
                int live = check_nb( i , j,   board , y , x); 
                buf_cur[j] = live;
            }

	    if( i > 0 ){
		for ( int j = 0 ; j < x ; j++ ){
		    board[i-1][j] = buf_old[j]; 
		}
	    }
        }

	for ( int j = 0 ; j < x ; j++ ){
	    board[y-1][j] = buf_cur[j]; 
	}
    }



};

int main(){
    Solution a;
    vector<vector<int> > bd { 
	{1,1,0,0,0, 1,1,1,1,1 , 1,1,0,1,1, 1,1,1,1,1},
	{1,1,0,0,0, 1,1,1,0,1 , 1,1,0,1,1, 1,1,1,1,1},
	{1,1,0,1,0, 1,1,1,1,1 , 1,1,0,1,1, 1,1,1,1,1},
	{1,1,0,1,0, 1,1,1,0,1 , 1,1,0,1,1, 1,1,1,1,1},
	{1,1,0,0,0, 1,1,1,1,1 , 1,1,0,1,1, 1,1,1,1,1},
	{1,1,0,0,0, 1,1,1,1,1 , 1,1,0,1,1, 1,1,1,1,1},
	{1,1,0,0,0, 1,1,1,1,1 , 1,1,0,1,1, 1,1,1,1,1},
	{0,0,0,0,0, 1,1,1,1,1 , 1,1,0,1,1, 1,1,1,1,1}
    };
    vector<vector<int> > res = bd; 
    a.gameOfLife(bd);
    for( auto it : bd){
	for( auto itt : it){
	    cout<<itt<<" ";
	}
	cout<<endl;
    }

    cout<<"original"<<endl;
    a.gameOfLife1(res);
    for( auto it : res){
	for( auto itt : it){
	    cout<<itt<<" ";
	}
	cout<<endl;
    }



    return 0;
}


