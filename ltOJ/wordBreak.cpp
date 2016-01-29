
#include<iostream>
#include<unordered_set>
#include<map>
#include<vector>
#include<algorithm>

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

    bool wordBreakI( string s, unordered_set<string> & wordDict){
	vector< int > mm ( s.length() ); 

	for( int i = 0 ; i <= s.length() - 1 ; i++){
	    if(  wordDict.find( s.substr(0 , i +1) )   != wordDict.end()  
		 && wbHelper ( mm, s, i+1, s.length() - 1 , wordDict)  == true ) 
		return true;
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



    bool wbHelperII ( vector<string> & res, string tmp, 
		      vector<int>  & mm, string s,  
		      int st , int en , 
		      unordered_set<string> wordDict ){

	if( st > en ){
	    res.push_back(tmp);
	    return true;
	}
	if( mm[st] == -1 ) return false;

	bool flag = false;
	for( int i = st ; i <=  en   ; i++){
	    string tmpp;
	    if( wordDict.find( s.substr( st, i - st+1)) != wordDict.end() ){
		tmpp = tmp +" "+s.substr(st,i-st+1); 
		if( true == wbHelperII ( res, tmpp ,  mm, s, i+1, en , wordDict) ) {
		    flag = true; 
		}   
	    }
	}
	if( flag == false  ) {
	    mm[st]  = -1; 
	    return false;
	}   
	return true;
    }   

    vector<string> wordBreakII( string s, unordered_set<string> & wordDict){
	vector<string> res; 
	vector< int > mm ( s.length(),  0   );
	for( int i = 0 ; i <= s.length() - 1 ; i++){
	    string tmp = s.substr(0,i+1) ; 
	    if(  wordDict.find( s.substr(0 , i +1) )   != wordDict.end()){
		wbHelperII (res, tmp, mm, s, i+1, s.length() - 1 , wordDict) ;
	    }   
	}   
	return res;
    }

    // ------- 
    bool wbHelperIII ( vector<string> & res, string tmp, vector<int>   mm, string s,  
		       int st , int en , unordered_set<string> wordDict ){
	if( st >= en ){
	    res.push_back(tmp);
	    return true;
	}
	for( int i = st ; i <=  en   ; i++){
	    if( mm[i] ==1 ) {
		string tmpp;
		if( tmp.empty () ){ tmpp =  s.substr(st,i-st+1);}
		else   tmpp = tmp + " " + s.substr(st,i-st+1); 
		if( wordDict.find( s.substr(st,i-st+1) ) != wordDict.end() ) { 
		    wbHelperIII( res, tmpp, mm, s, i+1, en, wordDict);
		}
	    }
	}
	return true;
    }   

    vector<string> wordBreak( string s, unordered_set<string> & wordDict){
	vector<string> res; 
	vector< int > mm ( s.length(),  0);
	// preprocessing via DP ?
	for ( int i = 0 ; i < s.length() ; i++){
	    for( int j = i ; j  >= 0 && !mm[i] ; j--){
		if( j > 0 ) mm[i] = mm[j-1] && ( wordDict.find(s.substr( j  , i - j + 1 )) != wordDict.end() ) ; 
		else mm[i] = ( wordDict.find(s.substr( j  , i - j + 1 )) != wordDict.end() ) ; 
	    }
	}
//	for( auto it : mm ) 	cout<<it<<" ";
//	cout<<endl;
	if( mm[s.length()-1] == 0 ) return res;
	wbHelperIII (res, "", mm, s, 0 , s.length() - 1 , wordDict) ;
	return res;
    }

    void gameOfLife(vector<vector<int>>& board) {

    }

    vector<vector<int> > subsets( vector<int> & nums){
	 vector<vector<int> > res;
	 
	 vector<int> sn; 
	 res.push_back(sn); 
	 if( nums.size() == 0 ) return res;

	 sort(nums.begin(), nums.end());
	 sn.push_back( nums[0]);
	 res.push_back(sn);

	 if( nums.size() == 1) return res;

	 for( int i = 1; i < nums.size() ;i++){
	     subsetHelper( nums, i , res );
	 }
	 return res;
    }


    void subsetHelper( vector<int> nums, int l , vector< vector<int> > & res){
	vector< vector<int> > tmp_set;
	for( int i = 0 ; i < res.size(); i++ ){
	    vector<int> tmp = res[i];
	    tmp.push_back( nums[l]);
	    tmp_set.push_back(tmp);

	}

	for( auto it : tmp_set ){
	    res.push_back(it);
	}
    }
};

int main(){
    Solution a;
    unordered_set<string> wd ;
    wd.insert("leet");
    wd.insert("code");
    wd.insert("cat");
    wd.insert("cats");
    wd.insert("sand");
    wd.insert("and");
    wd.insert("dog");
    wd.insert("aaaa");
    wd.insert("aa");
    wd.insert("a");

    //   wd.insert("leetcode");
//    cout<<a.wordBreakI("catsanddog", wd )<<endl;
     for( auto it : a.wordBreak("catsanddog", wd))
//    for( auto it : a.wordBreak("aaaaaaa", wd))
	cout<<it<<endl;

//     a.gameOfLife(board);
     vector<int> nums = {1,2,3};
     for(auto it : a.subsets(nums))
     {
	 for(auto itt : it)
	     cout<<itt<<" ";
	 cout<<endl;
     }




    return 0;

}

