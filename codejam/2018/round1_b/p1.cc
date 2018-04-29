#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int getNum(int a, int n){
    int b = a * 1000 / n;
    return b/10 + (b%10 >= 5);
}

int getNeeds(int x, int n){
    for(int i = 0; i<=n; i++){
        if( ((x+i)*1000/n)% 10 >= 5)
            return i;
    }
    return n;
}

int solve(){
    int n, l;
    cin>>n>>l;       
    //vector<int> dist(l, 0);
    vector<pair<int, int>> arr;
    
    int sm = 0;
    int x;

    for(int j=0; j<l; j++){
        cin>>x;
        //dist[j] = x;
        int r = getNum(x, n);
        //cout<<r<<"@"<< getNeeds(x, n)<< " ";
        sm += x;
        arr.push_back({getNeeds(x, n), x});
    }
    //cout<<endl;

    int delta = getNeeds(0, n);
    for(int i = 0; i < n - sm; i++){
        arr.push_back({delta, 0});
    }

    sort(arr.begin(), arr.end());
    for(int i = 0; i < arr.size(); i++){
        if(sm + arr[i].first <= n){
            sm += arr[i].first;            
            arr[i].second += arr[i].first;
        }
        else break;
    }
    arr[0].second += n - sm;

    int res = 0;
    for(int i = 0; i < arr.size(); i++){
        res += getNum(arr[i].second, n);
    }

    return res;
}


int main(){
    int t;
    cin >> t;
    for(int i = 1; i <= t; i++){        
        //int res = solve(l, n, dist);
        int res = solve();
        cout<<"Case #"<<i<<": "<<res<<endl;        
    }
    return 0;
}