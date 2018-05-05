#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <unordered_set>
using namespace std;

string dfs( unordered_set<string> & sset, vector<vector<char>> & cand,
            int n, int l, int start, string path){
    //cout<<path<<endl;
    if(path.size() == l){
        if(sset.find(path) == sset.end()) return path;
        return "-";
    }
    //cout<<cand[start].size()<<endl;
    for(int j = 0; j < cand[start].size(); j++){
        //path += cand[start][j];        
        string tmp_path = path + cand[start][j];
        //cout<<tmp_path<<endl;
        string res = dfs(sset, cand, n, l, start+1, tmp_path);
        if(res != "-") return res;
    }
    return "-";
}
 
string solve(){
    int n, l;
    cin>>n>>l;    
    //if(l==1) return "-";

    vector<string> s(n);  
    unordered_set<string> sset; 
    vector<vector<char>> cand(l);
    for(int i = 0; i < n; i++) {
        cin>>s[i];
        for(int j = 0; j < l; j++){
            cand[j].push_back(s[i][j]);
        }
        sset.insert(s[i]);
    }
	for (int j = 0; j < l; j++) {
	    sort(cand[j].begin(), cand[j].end());
		cand[j].erase(unique(cand[j].begin(), cand[j].end()), cand[j].end());
	}    
    string path = "";
    string res = dfs(sset, cand, n, l, 0, path);    
    return res;
}


int main(){
    int t;
    cin >> t;
    for(int i = 1; i <= t; i++){                
        string res = solve();
        cout<<"Case #"<<i<<": "<<res<<endl;        
    }
    return 0;
}
