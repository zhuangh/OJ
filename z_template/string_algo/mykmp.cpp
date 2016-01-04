
#include <iostream>
#include <string>
#include <vector> 

using namespace std;

// typedef vector<int> VI;
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
    buildTable(pattern, t);
    while( m + i < orig.length()){
	if( pattern[i] == orig[m+i] ) {
	    i++;
	    cout<<" m "<<m<<" ; ";
	    cout<<" i "<<i<<endl;
	    if( i == pattern.length()) return m;
	}
	else{
	    m += (i - t[i]);
	    if( i > 0 ) i = t[i];
	}
    } 
    return -1;
}



int main(){
    string a = "ababacdabc";
    string b = "abac";
    vector<int> t (b.length());
    int p = KMP(a,b, t);
    cout<<"offset of the matched strings = "<< p <<endl;
    return 0;
}

