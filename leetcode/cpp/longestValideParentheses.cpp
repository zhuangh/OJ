class Solution {
public:
    int longestValidParentheses(string s) {
           int sz = s.size();
    if(sz==0|| sz==1){ return 0;}

    stack<pair<char, int> > stk; 
//    vector<int> retv(sz,0);

    // int maxval = 0 ;
    //stk.push( make_pair( s[0],0 ) ) ;
    int len = 0 ; 
    int tmp = 0 ;
    int t = 0;

    for(int i = 0 ; i < sz ; i++){
	if( s[i] == '('){
	    stk.push(make_pair(s[i],i));
	} 
	else{
	    if ( stk.empty()){
		t = i+1;
	    }
	    else{
		pair<char, int> tmp = stk.top();
		stk.pop();
		if( tmp.first == '(' ){
		    if( !stk.empty() ){
			len = max(len, i-(stk.top() ).second); 
		    } 
		    else{
			len = max( len, i + 1 -t ); 
		    }
		}
	    }
	}
    }


    return len;


    }
};

