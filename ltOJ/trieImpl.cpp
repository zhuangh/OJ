#include<iostream>
#include<string>

using namespace std; 

class TrieNode {
    
public:
    TrieNode * next[26]; 
    bool isWord;
    
    // Initialize your data structure here.
    TrieNode(  ) {
        isWord=false;
        for( int i = 0 ; i < 26 ;i++) next[i] = NULL;
    }
    ~TrieNode(){
	for( int i = 0 ; i < 26 ;i++) {
		if( next[i]) delete next[i];
		next[i] = NULL;
	}
	// delete [] next; 
    }
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }
    ~Trie() {	 
	delete root;
    }

    // Inserts a word into the trie.
    void insert(string word) {
        TrieNode * iter = root ; 
        for( int i = 0 ; i < word.length(); i++){
            int idx = (int) word[i] - (int) 'a'; 
            if(! iter->next[ idx ] )  iter->next[idx] = new TrieNode( );
            iter = iter->next[idx]; 
	   // cout<<"insert "<< word[i]<<endl;
        }
        iter->isWord = true;
    }

    bool search(TrieNode * rt, string word, int i ){
        if( !rt ) return false;
        if( i == word.length() ){
            if( rt->isWord ) {
	//	cout<<"word Found!"<<endl;
		return true;
	    }
	    else{
	//	cout<<"word NOT Found!"<<endl;
		return false;
	    }
        }
        int idx = (int) word[i] - (int) 'a';
        return search(rt->next[ idx ], word , i+1);
    }
    // Returns if the word is in the trie.
    bool search(string word) {
        return search(root, word, 0);
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith( TrieNode * rt , string word, int i){
        if( !rt ) return false;
        if( i == word.length())  {
	 //   cout<<"word prefix FOUND"<<endl;
	    return true;
	}
	else{ 
	  //  cout<<"word prefix NO FOUND!"<<endl;
	    return false;
	}
        int idx = (int) word[i] - (int) 'a';
        return startsWith(rt->next[ idx ], word , i+1);
    }
    bool startsWith(string prefix) {
        return startsWith( root, prefix, 0) ; 
    }

private:
    TrieNode* root;
};

// Your Trie object will be instantiated and called as such:
int main(){
    Trie trie;
    trie.insert("somestring");
    trie.insert("key");
    trie.insert("kit");
    trie.search("key");
    trie.startsWith("cat");
    trie.insert("catcat");
    trie.startsWith("cat");
    return 0;
}



