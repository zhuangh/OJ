//leetcode.com/problems/shortest-palindrome/

#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {

public:

    string shortestPalindrome(string s) {
	
	string rev (s) ;


	int pos = -1;
	// cout<<s.length()<<endl;
	// cout<<rev<<endl;
	for( int i = 0 ; i < s.length() ; i++){
	    rev[i] = s[s.length()-1-i]; 
	}

	string w = s + "@" + rev;
	vector<int> t ( w.length(), 0 );

	int i = 2; 
	int j = 0;
	t[0] = -1;
	t[1] = 0;
	while( i <= w.length()){
	    if ( w[i-1] == w[j] ) {
		// first case: the substring continues
		t[i] = j+1;
		i++;
		j++;
	    } 
	    else if (j > 0) {
		// second case: it does not, but we can fall back 
		j = t[j];
	    }
	    else { 
		// third case: we have run out of candidates. set to 0 
		t[i] = 0 ; 
		i++;
	    }
	}
	/*
	cout<<t[t.size()-1]<<endl;
	
	cout<<t[0]<<endl;
	for(int i = 0; i < w.length() ; i++){
	    cout<< w[i] << " "<< t[i+1] <<endl;
	}
	*/
	
	return rev.substr(0, rev.length() - t[w.length()] )+s;
    }

    // -- KMP below -- 
    void buildTable ( string & w , vector<int> & t ){
	int i = 2; 
	int j = 0;
	t[0] = -1;
	t[1] = 0;
	while( i < w.length()){
	    if ( w[i-1] == w[j] ) {
		// first case: the substring continues
		t[i] = j+1;
		i++;
		j++;
	    } 
	    else if (j > 0) {
		// second case: it does not, but we can fall back 
		j = t[j];
	    }
	    else { 
		// third case: we have run out of candidates. set to 0 
		t[i] = 0 ; 
		i++;
	    }
	}
    }

    int KMP( string orig, string pattern, vector<int> & t) {
	

	int m =0, i = 0;

	while( m + i < orig.length()){
	    if( pattern[i] == orig[m+i] ) {
		i++;
	//	cout<<" m "<<m<<" ; ";
	//	cout<<" i "<<i<<endl;
		
		if( i == pattern.length()) return m;
	    }
	    else{
		m += (i - t[i]);
		if( i > 0 ) i = t[i];
	    }
	} 
	return -1;
    }

    string shortestPalindrome1(string s) {
	string rev (s) ;

	int pos = -1;
	// cout<<s.length()<<endl;
	// cout<<rev<<endl;
	for( int i = 0 ; i < s.length() ; i++){
	    rev[i] = s[s.length()-1-i]; 
	}

        vector<int> pif( s.length() ); 
	buildTable ( s , pif ) ;

	for( int i = s.length(); i > 0 ; i--){
	    string stmp = s.substr(0,i);

	    // cout<<" processing "<< stmp<<endl;
	    //cout<<i<<endl;
	    pos = KMP(rev, stmp , pif) ; 
	    // cout<<pos<<endl;
	    if ( -1 != pos ) break; 
	}

	string res = rev.substr(0,pos) + s ;
	//cout<<"reverse : "<<rev<<endl;
	return res;
    }

};

int main(){

    Solution a;
    string b = "aacecaaa";
    cout<<b<<endl;
    cout<<a.shortestPalindrome(b)<<endl;
    b = "abcd";
    cout<<b<<endl;
    cout<<a.shortestPalindrome(b)<<endl;
    b = "";
    cout<<a.shortestPalindrome(b)<<endl;
    return 0;
}

