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

    
    // Returns if the word is in the trie.
    bool search(string word) {
	TrieNode * iter = root;
	for( int i = 0; i < word.length() ; i++){
	    int idx = (int) word[i] - (int) 'a';
	    if( iter->next[idx] ) iter=iter->next[idx];
	    else {
		//cout<<"NOT FOUND"<<endl;
		return false;
	    }
	}
	if( iter->isWord ) 
	{
	    //cout<<"FOUND"<<endl;
	    return true;
	}
	return false;
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
	TrieNode * iter = root;
	for( int i =  0 ; i < prefix.length(); i++){
	    int idx = (int) prefix[i] - (int) 'a';
	    if( iter->next[idx] ) iter=iter->next[idx]; 
	    else {
	//	cout<<"NOT FOUND"<<endl;
		return false;
	    }
	}

	//cout<<"FOUND"<<endl;
	return true;
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



