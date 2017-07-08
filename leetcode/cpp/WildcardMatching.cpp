#include<stdio.h>
#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Solution{

void test_function( vector<int> ps){

	for(int i = 0 ; i < ps.size() ; i++){
		cout<<ps[i] << " " ;
	}
	cout<<endl;
}


public:
    bool isMatch(string s, string p){
//	cout<< s<< " vs "<< p <<endl;
	int sl = s.size()+1;
	int pl = p.size()+1;
	//	vector< vector<int> > ps ( 2, vector<int> (sl)  );
	vector< int > ps0 ( sl);
	vector< int > ps1 ( sl);
	//	vector< int > ps2 ( sl);
	ps1[0]=1;
	for ( int i = 1 ; i < pl ; i++){
	    for ( int j = 0 ; j < sl ; j++){
		if (  p[i-1] != '*' ){
		    if( ps1[j-1] && ( p[i-1] == s[j-1] || p[i-1] == '?') )  { 
			ps0[j] = 1;
		    }
		    else ps0[j]=0; // remember to set 0 , this is very different if we use two dimensional array, which has the initialized value 0; 
		}
		else{
//		    cout<<"---"<<p[i-1]<<" with ps1["<<i-1<<","<<j-1<<"] "<<ps1[j-1]<<endl;
		    if( ps1[j] || ps0[j-1] ||ps1[j-1] ) {
			ps0[j] = 1 ;  
		    }
		    else ps0[j]=0;
		}
	    }

//	    test_function(ps1);
	    swap( ps1 , ps0);
	    ps0[0] = 0 ;
//	    ps1[0] = 0 ;
	}
	return ps1[sl-1];
    }
};


int main(){
    Solution a ; 

    cout<<   a.isMatch("b","?*?")   <<endl; 
    cout<<   a.isMatch("aa","*")   <<endl; 
    cout<<   a.isMatch("a","*")   <<endl; 
    cout<<   a.isMatch("a","?")   <<endl; 
    cout<<   a.isMatch("aaa","aaaa")   <<endl; 
    cout<<   a.isMatch("aa","a")   <<endl; 
    cout<<   a.isMatch("aa","aa")  <<endl;  
    cout<<   a.isMatch("aaa","aa") <<endl;
    cout<<   a.isMatch("aa", "a*") <<endl;
    cout<<   a.isMatch("aa", "?*") <<endl;
    cout<<   a.isMatch("ab", "?*") <<endl;
    cout<<   a.isMatch("aab", "c*a*b") <<endl ;
    cout<<   a.isMatch("aaa", "ab*a") <<endl ;

    cout<<   a.isMatch("aaa", "ab*a*c*a") <<endl ;
    cout<<   a.isMatch("aaba", "ab*a*c*a") <<endl ;
    cout<<   a.isMatch("aaaa", "?*") <<endl ;
    cout<<   a.isMatch("", "*") <<endl ;
    return 0; 
}

