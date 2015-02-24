#include<iostream>
#include<vector>

using namespace std;
int dp[2][50];
class ZigZag{
public:
    int longestZigZag(vector <int> sequence) {
	int res = 1;
	int N = sequence.size();
	dp[0][0] = dp[1][0] = 1;
	for (int i = 1; i < N; i++) {
	    dp[0][i] = dp[1][i] = 1;
	    for (int j = 0; j < i; j++) {
		if (sequence[i] > sequence[j]) {
		    if (dp[1][i] < dp[0][j] + 1) {
			dp[1][i] = dp[0][j] + 1;
		    }
		} else if (sequence[i] < sequence[j]) {
		    if (dp[0][i] < dp[1][j] + 1) {
			dp[0][i] = dp[1][j] + 1;
		    }
		}
	    }
	    res = max(res, dp[0][i]);
	    res = max(res, dp[1][i]);
	}

	return res;
    }
};


int main(){
    ZigZag zz;
    vector<int> seq =  { 1, 17, 5, 10, 13, 15, 10, 5, 16, 8 };
    cout<< zz.longestZigZag( seq) << endl;
    return 0; 
}

