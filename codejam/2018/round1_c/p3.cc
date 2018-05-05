#include <iostream>
#include <vector>
using namespace std;

// dp[s]: the minimum weight sum when s ants forming the stack

void solve(){
    int n;        
    cin>>n;
    int s=0;
    vector<long long> dp(200000);    
    for(int j=0; j<(n); ++j){
        long long w;
        cin>>w;
        if(dp[s]<=6*w){
            s++;
            dp[s] = dp[s-1]+w;            
        }
        for(int i = s; i > 0; i--){
             if(dp[i-1]<=6*w) dp[i]= min(dp[i], dp[i-1]+w);
        }
    }    
    cout<<s<<endl;
}

int main(){
    int T;
    cin >> T;
    for(int t = 1; t <= T; t++) {
        cout<<"Case #"<<t<<": ";
        solve();
    }
    return 0;
}