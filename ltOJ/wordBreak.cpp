
#include<iostream>
#include<unordered_set>
#include<map>
#include<vector>

using namespace std;

class Solution {
public:

    /*
    bool wbhelper(map< pair<int,int>,int> & mm, unordered_set<string> & wordDict, string s, int st, int en ){
	if( st >= en) return true;
	for( int i = st ; i < en  ; i++){

	   if ( mm[make_pair ( st, i-st+1 )] == 1 ) continue;
	   bool res = ( wordDict.find( s.substr( st, i - st + 1 )) != wordDict.end());

	   if (res == false) {
	       mm[ make_pair(st, i - st + 1)] = 1 ;
	   }

    	   if( res == true && wbhelper(mm, wordDict, s, i+ 1 , en ) ) { 
	       return true;
	   }
	}
	return false;
    } 

    bool wordBreak1( string s, unordered_set<string> & wordDict){
	map< pair<int, int> , int > mm ; 
	for( int i = 0 ; i < s.length()  ; i++){

	   if ( mm[make_pair ( 0, i +1 )] == 1 ) continue;
	   bool res = ( wordDict.find( s.substr( 0 , i + 1 )) != wordDict.end());
	   if (res == false) {
	       mm[make_pair( 0 , i  + 1) ] = 1; ;
	   }
    	   if( true ==  res && wbhelper(mm, wordDict, s, i+1, s.length() ) ) {
	       return true;
	   }
	}
	return false;
    } 
    */

    bool wordBreak( string s, unordered_set<string> & wordDict){
	vector< int > mm ( s.length() ); 

	for( int i = 0 ; i <= s.length() - 1 ; i++){
	    if(  wordDict.find( s.substr(0 , i +1) )   != wordDict.end()  && wbHelper ( mm, s, i+1, s.length() - 1 , wordDict)  == true ) return true;
	}
	return false;
    }

    bool wbHelper ( vector< int > & mm, string s,  int st , int en , unordered_set<string> wordDict ){

	if( mm[st] == 1 ) return false;
	if( st > en ) return true;
	for( int i = st ; i <=  en   ; i++){
	    if( wordDict.find( s.substr( st, i - st+1)) != wordDict.end()  && wbHelper ( mm, s, i+1, en , wordDict)  == true ) return true;
	}
	mm[st] = 1;
	return false;
    }
};

int main(){
    Solution a;
    unordered_set<string> wd ;
    wd.insert("leet");
//    wd.insert("cod");
    wd.insert("code");
 //   wd.insert("leetcode");
    cout<<a.wordBreak("leetcode", wd )<<endl;
    return 0;
}
