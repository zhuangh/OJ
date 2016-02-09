#include<iostream>
#include<unordered_set>
#include<unordered_map>
#include<string>
#include<vector>
#include<queue> 
#include<map> 

using namespace std;

class Solution {
public:
    bool wordPattern( string pattern , string str){
	if( pattern.size() == 0 ) return false;
	p_s.clear();
	s_p.clear();
	int j = 0 ; 
	int cnt = 0;
	for( int i = 0 ; i < str.length(); i++){
	    if( str[i] == ' ' || i == str.length() - 1) {
		string  tmp;
		if( str.length() - 1 == i) tmp = str.substr(j,i-j+1);
		else tmp = str.substr(j,i-j ); 
		if( s_p.find(tmp) != s_p.end()  )  {
		    if ( s_p[tmp] != pattern[cnt]) return false ;
		}
		else  s_p[tmp] = pattern[cnt];

		if( p_s.find( pattern[cnt]  ) != p_s.end()){
		    if ( p_s[pattern[cnt]] != tmp) return false ;
		}
		else  p_s[ pattern[cnt] ] = tmp;
		cnt++;
		j = i+1;
	    }
	}
	if(cnt == pattern.size() )  return true;
	return false;
    }


    bool helper( string pattern, int pst, int pen, string str , int st, int en){
	if ( st > en && pst != (pen + 1) ) return false; 
	else if( st == en+1 && pst == (pen + 1)  ) {
	    cout<<pst<<" @" << st<<endl;
	    for( auto it : s_p ) cout<< it.first<<" -- "<<it.second<<endl;
	    p_s.clear();
	    s_p.clear();
	    cout<<"hit!!!"<<endl;
	    return true;
	}
	else  {
	    bool t = false; 
	    if( p_s.find( pattern[pst] ) != p_s.end() ){
		string inhouse = p_s[ pattern[pst] ] ;
		if( st + inhouse.length() - 1  > en ) return false;
		string tmp = str.substr(st,  inhouse.length() ); 
		if( tmp != inhouse ) return false;
		if( helper( pattern, pst+1, pen, str, st+inhouse.length() , en ) ) return true; 
		else return false;
	    }
	    else{

		// no matched yet there 
		for( int i = st ; i <= en ; i++){
		    string tmp = str.substr(st, i-st+1);
		    p_s[ pattern[pst]] = tmp;
		    s_p[tmp] = pattern[pst];
		    if( helper( pattern, pst + 1 , pen, str,  i + 1, en) ) return true; 
		    s_p.erase( tmp );
		    p_s.erase( pattern[pst] );
		}

		return false;
	    }
//	    return false;
	}
    }

    bool wordPatternII( string pattern, string str){
         return helper( pattern, 0, pattern.length()-1, str, 0, str.length()-1);
    }

private:
    unordered_map<char, string> p_s;
    unordered_map<string, char> s_p;

};

int main(){

    Solution a ;
    string pattern = "abba";
    string str = "dogcatcatdog";
    bool tr = a.wordPatternII( pattern, str);
    cout<<tr<<endl;

    string str2 = "dogcatcatdog1";
    tr = a.wordPatternII( pattern, str2);
    cout<<tr<<endl;
 
    return 0;
}


/*

   Given a pattern and a string str, find if str follows the same pattern.
   Here follow means a full match, such that there is a bijection between a letter in pattern and a non-empty substring in str.
Examples:

pattern = "abab", str = "redblueredblue" should return true.
pattern = "aaaa", str = "asdasdasdasd" should return true.
pattern = "aabb", str = "xyzabcxzyabc" should return false.
Notes:
You may assume both pattern and str contains only lowercase letters.

 */


