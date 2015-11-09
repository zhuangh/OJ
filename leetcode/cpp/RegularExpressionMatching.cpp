#include<stdio.h>
#include<iostream>
#include<vector>
#include<string>
using namespace std;

/*
'.' Matches any single character.
'*' Matches zero or more of the preceding element.

The matching should cover the entire input string (not partial).

The function prototype should be:
bool isMatch(const char *s, const char *p)

Some examples:
isMatch("aa","a") → false
isMatch("aa","aa") → true
isMatch("aaa","aa") → false
isMatch("aa", "a*") → true
isMatch("aa", ".*") → true
isMatch("ab", ".*") → true
isMatch("aab", "c*a*b") → true
*/

// #define DEBUG

class Solution{
public:
    bool isMatch(string s, string p){
	int sl = s.size()+1;
	int pl = p.size()+1;
	vector< vector<int> > sp ( sl, vector<int> (pl)  );
	sp[0][0] = 1;

	// sp[i][j] = 1 means s[1:i] matches p[1:j] 
	// sp[0][j] = 1 means empty s matches p[1:j]  

	// pay attention to the initialization 
	for(int j = 1 ; j < pl; j++){
	    sp[0][j] = 1;
	}

	/*
	for(int i = 0 ; i < sl; i++){
	    sp[i][0] = 1;
	}
	*/

	for ( int i = 1 ; i < sl ; i++){
	    for ( int j = 1 ; j < pl ; j++){
		if( p[j] == s[i] && sp[i-1][j-1] == 1) sp[i][j] = 1;
		if( p[j] == '.' && sp[i-1][j-1] == 1) sp[i][j] =1;
		if( p[j] == '*' && (sp[i-1][j-1] == 1 || sp[i-1][j-2] == 1)) sp[i][j] =1;
	    }
	}
#ifdef DEBUG
	for(int i = 0 ; i < sl; i++){
	    for(int j = 0 ; j < pl; j++){
		cout<<sp[i][j] << " " ;
	    }
	    cout<<endl;
	}
#endif
	return sp[sl-1][pl-1];
    }
};

int main(){
    Solution a ; 
    cout<<   a.isMatch("aa","a")   <<endl; 
    cout<<   a.isMatch("aa","aa")  <<endl;  
    cout<<   a.isMatch("aaa","aa") <<endl;
    cout<<   a.isMatch("aa", "a*") <<endl;
    cout<<   a.isMatch("aa", ".*") <<endl;
    cout<<   a.isMatch("ab", ".*") <<endl;
    cout<<   a.isMatch("aab", "c*a*b") <<endl ;
    return 0; 
}

