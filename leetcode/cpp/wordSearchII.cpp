#include<iostream>
#include<vector>
#include<algorithm>

using namespace std; 

// #define CharToIndex(c) ( (int) c - (int) 'a') 
#define ALPHA_SIZE  26

class Trie{
public:
    bool exist ; 
    bool added;
    Trie * next[ALPHA_SIZE];


    Trie() {
	for( int i = 0 ; i < ALPHA_SIZE ; i++){
	    next[i] = NULL;
	}
	exist = false;
	added = false;
    }

    ~Trie(){
	for( int i = 0 ; i < ALPHA_SIZE ; i++){
	    delete  next[i] ;
	}
    }

    void insert(string key){
	Trie * it = this; 
	for( int i = 0 ; i < key.length(); i++){
	    if( it->next[ key[i] - 'a' ] == NULL){ 
		it->next[ key[i] - 'a' ] = new Trie () ;
	    }

	    it = it->next[key[i] - 'a']; 
	    it->added = false;
//	    char cc =  key[i];
//	    cout<< i <<endl;

//	    cout<<"go down to " << cc;
//	    cout<<" w/ "<<it->exist<<endl;
	}
	it->exist = true;


//	cout<<" change "<<it->exist<<endl;
    }

    void printTrie( Trie * t){
	for( int i = 0 ; i < ALPHA_SIZE ; i++){
	    if( t->next[i] != NULL) {
		char cc = 'a'+i;
		cout<<cc<< " w/ ";
		cout<<t->exist<< " ";
		printTrie( t->next[i] ); 
	    }
	}
	cout<<endl;
    }

};


class Solution{ 
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
	Trie * mytrie = new Trie ();
	for( auto it : words ) mytrie->insert(it); 
//	mytrie->printTrie( mytrie);

	vector<string> res ; 
	string buff;

	for( int x = 0 ; x < board.size() ; x++){
	    for( int y = 0 ; y < board[x].size() ; y++){
		for( int i = 0 ; i < ALPHA_SIZE ; i++){
		    if( mytrie->next[i] != NULL){
			string buf = buff + (char) (i+'a');
	//		cout<<buf<<endl;
			dfs( board , x, y , mytrie->next[i] , i, buf , res ); 
		    }
		}
	    }
	}
	return res;
    }


    void dfs(vector< vector<char> > & board, int x, int y , Trie * root , int from_i, string  buff, vector<string> & res){

	//cout<<x<<y<<board.size()<<board[y].size()<<endl;
	if( x < 0 || y <0 || board.size() <= x || board[y].size() <= y ) return ;

	if( board[x][y] == '*' ) return ;



	int idx = board[x][y] - 'a' ;
	if( idx == from_i ) { 

	    if( root->exist == true ) {
		if( root->added == false ) { 	//	cout<<" found "<<buff<<endl;
		    res.push_back( buff );
		    root->added = true;
		}
	    }

	    char old = board[x][y];
	    board[x][y] = '*';
	    for( int i = 0 ; i < ALPHA_SIZE ; i++){
		if( root->next[i] != NULL) { 
		    Trie * next_node = root->next[i];
		    char cc = (i +'a');
		    string buf = buff + cc;
	//	    cout<<"searching "<<buf<<endl;

		    dfs( board, x + 1,  y , next_node, i, buf ,res);
		    dfs( board, x - 1,  y , next_node, i, buf ,res);
		    dfs( board, x , y + 1 , next_node, i, buf ,res);
		    dfs( board, x , y - 1 , next_node, i, buf ,res);
		}
	    }
	    board[x][y] = old;
	}
	// else 
	return ;
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
    // vector<string> words = {"oaf","ok","oath","pet","pea","eat","rain"};
     vector<string> words = {"ooo","eat", "aaa", "aaaaaab", "rain", "eath", "oath", "ooooo","aan" };
    // vector<string> words = {"eat", "aaaaa", "aaaaaab" };
//    vector<string> words = {"oaaa"};

    vector<string> b = a.findWords( board, words);
    for( auto it : b) cout<<it<<endl;
    return 0; 
}

