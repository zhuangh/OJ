
#include<iostream>
#include<unordered_set>
#include<unordered_map>
#include<map>
#include<vector>

#include<stack>
#include<algorithm>

#include<string>
#include<queue>


using namespace std;

struct ListNode {
int val ; 
ListNode * next;
ListNode (int dat) : val(dat), next(NULL){}
};


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
    int getmax( vector<int> nums)    {
	int mx = nums[0];
	for( int i = 1 ; i < nums.size(); i++ )
	    mx = nums[i]>mx? nums[i]: mx;
	return mx;
    }

    void count_sort( vector<int> & nums, int num_base){

	vector<int> count (10, 0);
	vector<int> output( nums.size(), 0);
	int n = nums.size() ; 
	for(int i = 0 ; i < n ; i++ ) {
	    count[ (nums[i]/num_base) %10  ]++;
	}

	for( int i = 1 ; i < 10 ; i++){
	    count[i] += count[i-1];    
	}

	for( int i = n-1; i >= 0 ; i--){
	    output[ count[ (nums[i] / num_base) %10 ] -1 ] = nums[i];
	    count[ (nums[i]/num_base)%10 ]--;
	}

	for( int i = 0 ; i < n ; i++)
	    nums[i] = output[i];

    }

    void pass( vector<int> & nums, vector<int> & pos, vector<int> & neg ){
	for(auto it : nums){
	    if(it>=0 ) pos.push_back(it);
	    else neg.push_back(-it);
	}
    }

    void union_pass( vector<int> & nums, vector<int> & pos, vector<int> & neg ){
	int cnt = 0 ; 	
	if( neg.size() >0) {
	    reverse(neg.begin(), neg.end());
	    for(auto it : neg){
		nums[cnt] = -it;
		cnt++;
	    }
	}
	if( pos.size()>0) {
	    for(auto it : pos){
		nums[cnt] = it;
		cnt++;
	    }
	}
    }

    void radix_sort( vector<int> & nums){
	if(nums.size() > 0 ) {
	    int mx = getmax(nums);
	    for( int num_base = 1 ; mx/num_base > 0 ;  num_base*=10 )  count_sort( nums, num_base);
	}
	// return nums;
    }

    int longestConsecutiveRadix(vector<int>& nums) {
	if( nums.size() == 0 ) return 0;
	if( nums.size() == 1 ) return 1;
	int cnt = 1; 
	vector<int> pos ; 
	vector<int> neg ; 
	pass(nums, pos,neg);

	cout<<pos.size()<<endl;
	cout<<neg.size()<<endl;
	radix_sort(pos) ;
	radix_sort(neg) ; 
	union_pass(nums, pos, neg); 
	//      vector<int> cnt;
	int lst = 1; 
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



    int power( int a, int b){

	int result = 1;

	while( b  ){
	    cout<<a<<endl;
	    if( b & 1 ) { 
		cout<<b<<" b & 1 "<< (b&1) <<endl;
		result *= a;
	    }
	    b  >>= 1;
	    a *= a;
	}

	cout<<result<<endl;
	return result;

	/*
	   int prod = a;
	   int i = 0;
	   int iter = (int) ( log(b) / log(2));
	   int lf = b% (1<<iter) ;
	   cout<<iter<<endl;
	   cout<<lf<<endl;
	   while( i < iter ){
	   prod = prod * prod;
	   i++;
	   }
	   for( int i = 0 ; i < lf ;i++) prod *= a;
	   return prod;
	 */
    }

    void product( string & res, string p1, string p2){


    }

    string power_via_string( int a, int b){
	string prod ;
	int i = 0;
	int iter = (int) ( log(b) / log(2));
	int lf = b% (1<<iter) ;
	cout<<iter<<endl;
	cout<<lf<<endl;
	while( i < iter ){
	    product(prod, prod, prod);
	    i++;
	}
	for( int i = 0 ; i < lf ;i++) product( prod, prod, std::to_string(a) );
	return prod;
    }

    int numSquares(int n) {
	// vector<int> nums(n+1, 1000000);
	vector<int> qq;
	vector<int> smallest_sq ( n+1, 0 ); 
	queue<int> q_result, q_result_next; 

	for( int i = 1 ; i*i <= n ;i++)   { 
	    //cout<<i*i<<endl;
	    qq.push_back( i*i );
	    //		smallest_sq[i*i] = 1; 
	}
	int sz = qq.size();

	q_result_next.push( n);
	int level = 0 ; 

	while(!q_result_next.empty()){
	    swap( q_result, q_result_next);
	    level++;
	    //	    cout<<"----"<<level<<endl;
	    while(!q_result.empty()){
		int target = q_result.front();
		q_result.pop();
		//		cout<<target<<" : "<<endl;
		//		cout<<level<<endl;
		for( int j = 0  ; j < qq.size() ; j++){
		    int i = qq[j];
		    if( target - i > 0 ) { 
			if( smallest_sq[target- i ] == 0 ){// || smallest_sq[target-i] == 1) {
			    q_result_next.push( target - i ) ;
			    smallest_sq[ target - i ] = -1 ;
			}
			//			else if( smallest_sq[ target - i ] == 1 ){ 
			//			    return level +1 ;
			//			}
			}
			else if ( target == i ) {
			    return level;
			} else {
			    break;
			}
		    }
		}
	    } // while for q_result_next
	    return 0;
	}




	int numSquares1(int n) {
	    static vector<int> _s_nums(1,0);
	    /*
	       _s_nums.push_back(0);
	       _s_nums.push_back(1);
	       _s_nums.push_back(2);
	       _s_nums.push_back(3);
	     */
	    int m = _s_nums.size() - 1;
	    if( n <= m ) return  _s_nums[n];
	    else{
		for( int i = m+1; i <= n ; i++){
		    int res = sqrt(i);
		    int min_res = _s_nums[i-1] + 1; 
		    for( int j = 1 ; j*j<=i ;j++){
			min_res = min (  min_res ,  _s_nums[i-j*j] + 1 ) ;
		    }
		    _s_nums.push_back(min_res);
		}

	    }
	    return  _s_nums[n];
	}
	vector<int> grayCode(int n) {
	    vector<int> res; 
	    if ( n == 0 ) return res;
	    int level = n;
	    gcHelper( res , 0 , 0 , level , 0);
	    return res;
	}

	void gcHelper( vector<int> & res,  int val , int cur , int tot_level, int flip ){
	    if( cur == tot_level ){
		res.push_back(val );
		cout<<val<<endl;
		return;
	    }
	    if( flip == 0) {
		gcHelper( res, 2*val   , cur+1, tot_level, 0);
		gcHelper( res, 2*val+1 , cur+1, tot_level, 1);
	    }
	    else  {
		gcHelper( res, 2*val+1  , cur+1, tot_level, 0);
		gcHelper( res, 2*val , cur+1, tot_level, 1);
	    }
	    return;
	}

	int maximalRectangle(vector<vector<char>>& matrix) {
	    int xdim = matrix.size();
	    if(xdim <= 0 ) return 0;
	    int ydim = matrix[0].size();
	    vector<int> xopt0 ( ydim, 0);    
	    vector<int> xopt1 ( ydim, 0);    
	    vector<int> yopt0 ( ydim, 0);
	    vector<int> yopt1 ( ydim, 0);
	    int area = 0 ; 
	    xopt0[0] = ( matrix[0][0]=='1'?1:0);
	    yopt0[0] = ( matrix[0][0]=='1'?1:0);

	    //	    cout<<"area "<<area<<endl;
	    for( int j = 1 ; j < ydim; j++){
		if(matrix[0][j]=='1') {
		    xopt0[j] = 1; 
		    yopt0[j] = yopt0[j-1]+1; 
		    area = max(area, yopt0[j]);
		}
		else {
		    xopt0[j] = 0;
		    yopt0[j] = 0; 
		}
	    } 
	    //	    cout<<"area "<<area<<endl;
	    for( int i = 1 ; i < xdim; i++){ 
		if( matrix[i][0] == '1'){
		    xopt1[0] = xopt0[0]+1 ; 
		    yopt1[0] = 1;
		    area = max(area, xopt1[0]);
		}
		else{
		    xopt1[0] = 0 ; 
		    yopt1[0] = 0;
		}
		for( int j = 1 ; j<ydim;j++){
		    //		    cout<<matrix[i][j]<<" matrix ";
		    if( matrix[i][j]=='1'){

			int xtmp = 1+min( xopt0[j-1], xopt0[j]); 
			int ytmp = 1+min( yopt0[j-1], yopt1[j-1]); 
			// x direction


			int area1 = (1+xopt0[j]) * (1+min(yopt0[j] , yopt0[j-1]));
//			cout<<endl;
//			cout<<area1<<endl;

			int area_tmp = area1; 
			int area2 = (1+yopt1[j-1]) * (min(xopt1[j-1] , xopt0[j-1]));

//			cout<<area2<<endl;

			if( area1 > area2 ) {
			    xopt1[j] = 1+xopt0[j];
			    yopt1[j] = (1+min(yopt0[j] , yopt0[j-1]));
			}
			else{
			    xopt1[j] = 1+min(xopt1[j-1] , xopt0[j-1]);
			    yopt1[j] = 1+yopt1[j-1];
			    area_tmp = area2;
			} 
			int area3 = xtmp * ytmp; 
			if( area3 > xopt1[j]*yopt1[j]) {
			    xopt1[j] = xtmp;
			    yopt1[j] = ytmp;
			    area_tmp = area3;
			} 
//			cout<<area3<<endl;

			// y direction
			// x y direction 
			area = area> area_tmp ? area : area_tmp;  
		    }
		    else {
			xopt1[j] = 0; 
			yopt1[j] = 0;
		    } 
		    cout<<yopt1[j]<<",";
		    cout<<xopt1[j]<<" ";
		}
		cout<<endl;
		swap(xopt1, xopt0);
		swap(yopt1, yopt0);
	    }
	    return area ; 
	}
 
void output(vector< vector<string> > & res ,  vector<string> & buffer,  unordered_map<string, vector<string> > prev_map , string start, string end ){
    if( start == end  ){
        reverse(buffer.begin(), buffer.end());
        res.push_back(  buffer ) ; 
        reverse(buffer.begin(), buffer.end());
    }
    vector<string> tmp = prev_map[end];
    for( auto it : tmp ){
       //vector<string> buffer_new = buffer;
       buffer.push_back( it );
       output( res, buffer, prev_map, start , it )  ;
       buffer.pop_back( );
    }
}

 

vector<vector<string> > findLadders(string start, string end, unordered_set<string> &dict) {
        // BFS 
        unordered_map<string, int > visited; 
        unordered_map<string, vector<string> > prev_map; 

        queue<string> cur,next;
        next.push( start );
        vector<vector < string> > res; 
        bool flag = false;
        while( !next.empty()  && !flag){
            swap(next,cur);
            while(!cur.empty()){
                string tmp = cur.front();
                cur.pop();
                for( int i = 0 ; i < tmp.length() ; i++){
                    string st = tmp;
                    for( char c = 'a' ; c <= 'z'; c++){
                        //char old = st[i];
                        st[i] = c;
                        if( end == st ){
                            // hit the end word
                            prev_map[ st ].push_back(tmp);
                            flag = true;
                        }
                        else if( dict.find(st) != dict.end() &&  visited[st] == 0 ) {
                            visited[st] = 1;
                            // found the changed word
                            next.push(st); 
                            prev_map[ st ].push_back(tmp);
                        }
                        // st[i] = old;
                    }
                }
            }
        }
        vector<string> buf ; 
        output(res, buf , prev_map, start, end);
        
        return res; 
    }

    };

struct TreeNode{
	int val;
	TreeNode *left, *right;
	TreeNode( int dat ) : val(dat), left(NULL), right(NULL) {}
};

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        
        if( root == NULL ) return "#";
        string st = to_string(root->val) + "," + serialize(root->left) +"," + serialize(root->right);
        return st;
    }

    TreeNode* des ( vector<string> vec , int & i ) {
        
        if( i >= vec.size() ) {  return NULL;}
        if( vec[i]=="#") {  return NULL;}
        cout<<i<<endl;
        TreeNode * head = new TreeNode (stoi(vec[i]));
         cout<<head->val<<" i = ";
        cout<<i<<endl;
        i++;
        head->left = des (vec, i);
        head->right = des (vec, i);
        
        return head;
    }
    
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        
        vector<string> vec;
        for( int j = 0, i = 0 ; i < data.length() ; i++){
            if(data[i] == ',' ) {
                vec.push_back(data.substr(j,i-j));
                j = i+1;
            }
            else if( i == data.length() - 1 ) {
                vec.push_back(data.substr(j,1+i-j));
            }
            
        }
          for( auto it : vec) cout<<it<<endl;
    // cout<<vec.size()<<endl;
    int i = 0;
        TreeNode * head = des ( vec, i);
        return head ;
        
    }
};


    int main(){
	Solution a;
	/*
	   unordered_set<string> wd ;e
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
	 */

	//   wd.insert("leetcode");
	//    cout<<a.wordBreakI("catsanddog", wd )<<endl;
	//     for( auto it : a.wordBreak("catsanddog", wd))
	//	cout<<it<<endl;
	//    for( auto it : a.wordBreak("aaaaaaa", wd))
	//    a.gameOfLife(board);
	/*
	   vector<int> nums = {1,2,0,1};
	   for(auto it : a.subsets(nums))
	   {
	   for(auto itt : it)
	   cout<<itt<<" ";
	   cout<<endl;
	   }
	 */
	/*
	   vector<int> nums = {100,4,1,2,3,0,200};
	   cout<<endl<<"lcs -- "<< a.longestConsecutiveRadix(nums)<<endl;
	   cout<<a.power(2,10)<<endl;
	 */
	// cout<<a.numSquares1(1535)<<endl;
	/*
	cout<<a.numSquares1(13)<<endl;
	cout<<a.numSquares1(12)<<endl;
	vector<int> vec =  a.grayCode(3) ;
	cout<<"\nsz: "<<vec.size();
	for( auto it : vec) cout<<endl<<it;
	cout<<endl;

	*/

	// vector<vector<char> > mat = { {'0','0','0'} ,  {'1','1','1'} };
//	vector<vector<char> > mat = { {'1','0','1','0','0'} ,  {'1','0','1','1','1'} , {'1','1','1','1','1'}, {'1','0','0','1','0'} };
//	cout<<"area "<< a.maximalRectangle( mat )<<endl;
	
	ListNode aa (3);
	ListNode b (2);
	ListNode c (1);

	ListNode d (10);
	aa.next = &b;
	b.next = &c;	
	c.next = &d;
	ListNode * aaa = &aa;
        ListNode * tmp = NULL;//  = a.insertionSortList(aaa); 
	cout<<tmp<<endl;
	while( tmp){
		cout<<tmp->val<<" ";
		tmp = tmp->next;
	}
	cout<<endl;

		string start = "a";
  string end = "c";
  unordered_set<string> dict;
dict.insert("a");dict.insert("b");dict.insert("c");
vector<vector <string> > tttt = a.findLadders(  start, end, dict );
for(auto it : tttt) { 
	for(auto itt : it ) cout<<itt<<" "; 
cout<<endl;
}
	return 0;

    }

