
#include<iostream>
#include<unordered_set>
#include<unordered_map>
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

    int findMin_Linear(vector<int>& nums) {
	if(nums.size() == 1) return nums[0];
	for( int i = 1 ; i < nums.size()  ; i++)
	    if( nums[i-1] > nums[i] ) return nums[i];
	return nums[0];
    }

    int findMin(vector<int>& nums) {

    }

    int longestConsecutive_Onlogn(vector<int>& nums) {
	// 
	// 100 4 10 1 2 3 
	// --> 1 2 3 4
	if( nums.size() == 0 ) return 0;
	if( nums.size() == 1 ) return 1;

	sort(nums.begin(), nums.end() ) ;
//	vector<int> cnt;
	int lst = 1, cnt = 1;
	for( int i = 1 ; i < nums.size() ; i++){
	    if( nums[i-1]+1 == nums[i])//  || nums[i-1] == nums[i]) 
	    {
		cnt++;
	    }
	    else if (nums[i-1] == nums[i]) {
		cnt = cnt; // coverity trick?
	    }
	    else{
		cnt=1;
	    }
	    lst = cnt>lst ? cnt:lst;
	}
	return lst;
    }

    int longestConsecutive_RS(vector<int>& nums) {
	// radix sort

	return 0;
    }

    int longestConsecutive_UF(vector<int>& nums) {
	// union-find 
	return 0;
    }

    void reverseWords11(string &s) {
        if(s.length()<=0) return ;

        vector<string> mm_s ;
        string tmp="";
 
        for( int i = 0 ; i < s.length() ; i++ ){
 
            if( isspace(s[i])  ) {
                if( !tmp.empty() ){ 
                    mm_s.push_back(tmp);
                    tmp ="";
                }
            }   
            else  if (  i == s.length() -1) { 
                if( !tmp.empty() || !isspace(s[i]) ){
                    tmp += s[i]; 
                    mm_s.push_back(tmp);
                }
            }
            else tmp+= s[i];
        }    
        if(mm_s.size() == 0 ) {s=""; return;}
        reverse(mm_s.begin(), mm_s.end());
        
        s = mm_s[0];
        for( int i = 1 ; i < mm_s.size(); i++){
            s += (" " + mm_s[i]);
        }
    }

    void reverseWords(string &s) {
        if(s.length()<=0) return ;

        reverse(s.begin(), s.end());
	int r = -1, l=-1;
	for( int i = 0 ; i < s.length() ; i++)
	{
		if( s[i]!=' ' ){
		    if(l == -1) { l = i; r=i; }
		    else{ r++;} 
		}
		if ( (s[i] == ' ' || i == s.length()-1) && r !=-1 ) {
		    reverse(s.begin()+l,s.begin()+r+1);
		    r=-1;l=-1;
		}
	}
	return;
    }
    void subsets(vector<int>& nums, int k, vector< vector<int> > & res){
        int res_num = res.size();
        for( int i = 0; i < res_num ;i++){
            vector<int> tmp = res[i];
            if( res[i].size() <= 2){
                tmp.push_back(nums[k]);
                res.push_back(tmp);
            }
        }
    }
    /*
    vector<vector<int>> threeSumLTE(vector<int>& nums) {
        
        vector<int> sn ;
        vector< vector<int> > res, res_gl ;
        if (nums.size() < 3) return res_gl;
        res.push_back(sn);
        sn.push_back(nums[0]);
        res.push_back(sn);
        // S_i = S_i-1 + (S_i-1 union num_i)
        

        
        for( int i = 1 ; i < nums.size() ; i++){
            subsets(nums, i, res);
        }
         
        for( auto it : res ){
            for(auto itt : it) cout<<itt<<" ";
            cout<<endl;
        } 
        
        set< vector<int>  > mm;
        for( int i = 0 ; i < res.size() ;i++){
            if( res[i].size() == 3 ) {
                int sum = 0; 
                for(auto it : res[i]) sum+= it;
                if(sum == 0 ) {
                    
                    sort(res[i].begin(), res[i].end());
                    if( mm.find(res[i]) == mm.end() ){
                        mm.insert( res[i] );
                        res_gl.push_back(res[i]);
                    }
                }
            }
        }
        return res_gl;
    }
  */
	vector<vector<int>> threeSum(vector<int>& nums) {
        
        vector<vector<int> > res;
        sort(nums.begin(), nums.end());
        int sz = nums.size();
        
        if( sz<=2  ) return res;
        
        int prev;
        
        for( int i = 0; i < sz - 2 ; i++){
              if( i>0) {
                while( prev == nums[i] ){ 
                    i++;
                  //  cout<<i<<endl;
                    if (i >= sz - 2 ) goto L1;
                }
              }
                
            int sum = -nums[i];
            int j = i + 1; 
            int k = sz - 1; 
            while ( j < k  ){
                int trip2 = nums[j];
                int trip3 = nums[k];
                if( nums[j] + nums[k] == sum){
                    res.push_back(vector<int> {nums[i],nums[j],nums[k]});
                    while( nums[k] == trip3 && k>j) k--;
                    while( nums[j] == trip2 && k>j) j++;
                }
                else if( nums[j] + nums[k] > sum) { 
                    while( nums[k] == trip3 && k>j) k--;
                }
                else {
                    while( nums[j] == trip2 && k>j) j++;
                }
                
            
            }
            prev= nums[i];
        }
L1:
        return res;
    }
/*
  vector<int> twoSum(vector<int>& nums, int target) {
        // sort(nums.begin(),nums.end());
        // int j = 0, k = nums.size()-1;
	// O(n^2)
        for( int i = 0 ; i < nums.size() ; i++){
            int t = target - nums[i];
            int k = nums.size()-1;
            while ( k> i){
                if( nums[k] == t) return vector<int>{1+i,1+k};
                k--;
            }
        }
        return vector<int>{};
    }

    vector<int> twoSumMap(vector<int>& nums, int target) {
        // sort(nums.begin(),nums.end());
        // int j = 0, k = nums.size()-1;
        unordered_map<int,int> ms;
        // unordered_map<int,int> id;
	// O(2n) 
        for( int i = 0 ; i < nums.size() ; i++){
            ms[nums[i]] = i+1;
            // id[i+1] = nums[i];
        }
        for( int i = 0 ; i < nums.size() ; i++){
            int idd =  ms[target - nums[i]] ;
            if(idd > 0 && idd!=i+1) return vector<int> {i+1,idd};
        }
    }
*/
  vector<char> gencand( char ss ){
        if((ss - '9') == 0 ) return vector<char>{'w','x','y','z'};
         if((ss - '8') == 0 ) return vector<char>{'t','u','v'};
        if((ss - '7') == 0 )  return vector<char>{'p','q','r','s'};
	int of =  (int) (ss-'2');
//	cout<<of<<endl;
        return vector<char>{ (char) ('a' + 3*of) ,  (char) ('b'+ 3*of),  (char) ('c'+ 3*of)};
        
    }
    void gen( int st, int en,  string digits, vector<string> &ss ){
        if( st > en) {
            return; 
        }
        int sz = ss.size();
        vector<char> c_t = gencand( digits[st] );
        for( int i = 0 ; i < sz  ; i++){
            for ( auto it : c_t ){
                string tmp = ss[i];
                tmp += it ;
//		cout<<tmp<<endl;
                ss.push_back(tmp);
            }
        }
        gen(st+1, en, digits, ss);
    }

    vector<string> letterCombinations11(string digits) {
	int sz = digits.length();
	if (sz < 1 ) return {};
	vector<string> ss ;
	vector<char> c_t = gencand( digits[0] ); 
	for( auto it : c_t ){
	    string tmp = "";
	    tmp+=it;
//	    cout<<it<<endl;
	    ss.push_back( tmp ); 
//	    printf("%s\n",tmp.c_str() );
	}            
	gen(1, sz-1 , digits, ss);
	vector<string> sss;	
	for( auto it : ss ) {if(it.size() == digits.length() ) sss.push_back(it);}

	return sss;
    }



    vector<string> letterCombinations(string digits) {
	unordered_map<char, vector<char> > mm{
	    {'2', {'a','b','c' }},
	    {'3', {'d','e','f' }},
	    {'4', {'g','h','i' }},
	    {'5', {'j','k','l' }},
	    {'6', {'m','n','o' }},
	    {'7', {'p','q','r','s' }},
	    {'8', {'t','u','v' }},
	    {'9', {'w','x','y','z' }}
	}; 
	vector<string> mms;
	int n = digits.size()-1;
	string path = "";
	//auto it = mm['2'];
	//	cout<<it[0]<<endl;
	//	cout<<digits.size()<<endl;
	dfs_gen( mm, mms, digits, 0 , n, path);
	return mms;
    }

    void dfs_gen( unordered_map<char, vector<char> > mm, 
		  vector<string> & mms, string digits, 
		  int st, int en, string  path){
	if(st>en) {
	    mms.push_back( path );
	    return;
	}

	char c = digits[st]; 
//	vector<char> ss = mms[ c ] ;
	auto ss = mm[c];
	for( int i = 0 ; i < ss.size() ; i++){
	    string tmp_path = path+ ss[i]; 
	    dfs_gen( mm , mms, digits, st+1, en, tmp_path);
	} 
	return ;
    }

    // Programming Perl page 77
    int longestConSum( vector<int> nums){
	vector<int> key(nums.size() , -1);
	vector<int> sol(nums.size() , 0);
	// sol (0 , n-1 ) = 
	// max ( nums[n-1], 
	//  sol(0,n-2) + nums[n-1] when key[n-2] == n-2 
	//  sol(0,n-2) when key [n-2] != n-2

	if( nums[0] >= 0 ) {
	    key[0] =0;  
	    sol[0] = nums[0];
	}

	int maxval = nums[0];
	for( int i = 1 ; i < nums.size() ;i++){
	    
	    if( key[i-1] == i-1) {
		sol[i] = max( nums[i] + sol[i-1], nums[i]);
		key[i] = i;
	    }
	    else{
		sol[i] = max( nums[i] , sol[i-1]);
		key[i] = nums[i] > sol[i-1] ? i : key[i-1]; 
	    }
	    maxval = maxval < sol[i] ? sol[i] : maxval;
	}
	for( auto it : sol)
	cout<<it<<" ";
	cout<<endl;

	return maxval;//sol[nums.size()-1];
    }

    int longestConsecutiveUnionFind(vector<int>& nums) {
        if( nums.size() < 2) return nums.size(); 
        
        vector<int> id (nums.size(), -1);
        vector<int> ss (nums.size(), 1);
        
        unordered_map<int,int> record; 
        
        for(int i = 0 ; i < nums.size(); i++){
            id[i] = i ; 
        }
        
        for( int i = 0 ; i < nums.size() ;i++){
            if ( record.find(nums[i]) != record.end() ) continue;
            
            record[ nums[i] ] = i ;
            if ( record.find(nums[i]-1) != record.end() ) union_find( i, record[ nums[i] -1 ] , ss , id);
            if ( record.find(nums[i]+1) != record.end() ) union_find( i, record[ nums[i] +1 ] , ss , id);
        }

        int maxval = 1;        
        for( auto it : ss ) maxval = maxval < it ? it : maxval;
        return maxval;
    }
    
    int find_root( int idx , vector<int> & id ){
        while( idx != id[idx]){
            idx = id[idx]; 
        }
        return idx;
    }
    
    void union_find( int id1, int id2 , vector<int> & ss, vector<int> & id){
         int i = find_root(id1,id); 
         int j = find_root(id2,id);
         if(i==j) return;
         if( ss[i] > ss[j]) {
             id[j] = i ;
             ss[i] += ss[j];
         }else{
             id[i] = j;
             ss[j] += ss[i];
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
     vector<int> nums = {1,2,0,1};
     for(auto it : a.subsets(nums))
     {
	 for(auto itt : it)
	     cout<<itt<<" ";
	 cout<<endl;
     }
//     cout<<endl<<" lcs "<< a.longestConsecutive(nums)<<endl;
     string ss = " ";//"hello kitty";// " ; 
     a.reverseWords(ss );
     cout<<ss<<endl;


     for( auto it : a.letterCombinations("23"))
	 cout<<it<<endl;

     vector<int> nums1 = {1,2,0,1, -2 ,1};
     cout<<a.longestConSum(nums1)<<endl;

    return 0;

}

