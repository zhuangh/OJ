// recyled from website, not compiled 
class Solution{
public:
    int minCut(string s){
	int sz = s.size();
	vector<int> P(sz+1, 0);
	vector< vector<int> > DP(sz, vector<int>(sz,0) );

	for(int i = 0 ; i <= sz; i++){
	    P[i] = sz- 1 - i ;
	}

	for(int i = sz - 2; i >=0 ;i--){
	    for(int j = i ; j < sz ; j++){
		if(s[i] == s[j] && ( ( j - i <= 1) || ( DP[i+1][j-1] == 1) ))
		{
		    DP[i][j] = 1;
		    P[i] = min(P[i],P[j+1] + 1);
		}
	    }
	}
	return P[0];
    }

};
