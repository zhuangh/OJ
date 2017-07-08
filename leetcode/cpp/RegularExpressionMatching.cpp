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


class Solution{

void test_function( vector< vector<int> > ps){

	for(int i = 0 ; i < ps.size() ; i++){
	    for(int j = 0 ; j < ps[i].size()  ; j++){
		cout<<ps[i][j] << " " ;
	    }
	    cout<<endl;
	}
	cout<<endl;
}


public:
    bool isMatch(string s, string p){
	int sl = s.size()+1;
	int pl = p.size()+1;
	vector< vector<int> > ps ( pl, vector<int> (sl)  );
	ps[0][0] = 1;
//	for( int i = 0 ; i < sl ; i++) ps[0][i] = 1;

	// sp[i][j] = 1 means s[1:i] matches p[1:j] 
	for ( int i = 1 ; i < pl ; i++){
	    for ( int j = 0 ; j < sl ; j++){
		// scan s[j] 
		if (  p[i-1] != '*' ){
		    if( j>0 && ps[i-1][j-1] && ( p[i-1] == s[j-1] || p[i-1] == '.') )  ps[i][j] = 1;
		}
		else{
		    // p[i] == '*'
		    if( (i>1 && ps[i-2][j]) || // remove the previous p 
			(j> 0 &&( ps[i][j-1]) || ps[i-1][j-1] ) && (p[i-2] == s[j-1] || p[i-2] =='.')  ) // extend * with 0 to multiple copies 
			{
			    ps[i][j] = 1 ;  
			}
		}
	    // cout<<i<<j<<endl;
	    }
	}
//	test_function(ps);
	return ps[pl-1][sl-1];
    }
};


int main(){
    Solution a ; 

    cout<<   a.isMatch("aaa","aaaa")   <<endl; 
    cout<<   a.isMatch("aa","a")   <<endl; 
    cout<<   a.isMatch("aa","aa")  <<endl;  
    cout<<   a.isMatch("aaa","aa") <<endl;
    cout<<   a.isMatch("aa", "a*") <<endl;
    cout<<   a.isMatch("aa", ".*") <<endl;
    cout<<   a.isMatch("ab", ".*") <<endl;
    cout<<   a.isMatch("aab", "c*a*b") <<endl ;
    cout<<   a.isMatch("aaa", "ab*a") <<endl ;

    cout<<   a.isMatch("aaa", "ab*a*c*a") <<endl ;
    cout<<   a.isMatch("aaba", "ab*a*c*a") <<endl ;
    cout<<   a.isMatch("aaaa", ".*") <<endl ;
    return 0; 
}

