#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
using namespace std;

//#define BZ
const int N = 124;
int ans_h[N];
int ans_v[N];
int rows[N];
int cols[N];
int m[N][N];

bool solve(){
    int r, c, h, v;
    //cin>>r>>c>>h>>v;
    scanf("%d%d%d%d", &r, &c, &h, &v);
    //vector<int> rows(r+1, 0);
    //vector<int> cols(c+1, 0);
    //vector<vector<int>> m(r, vector<int>(c, 0));
    int target = 0;
    char s [124];
    for (int i = 0; i <= r; i++)
		rows[i] = 0;
	for (int i = 0; i <= c; i++)
		cols[i] = 0;
    for(int i = 0; i < r; i++){
        scanf("%s", s);
        for(int j = 0; j < c; j++){
            char tmp = s[j];            
            if(tmp=='@') {
                m[i][j] = 1;
                rows[i+1]++;
                cols[j+1]++;
                target++;
            }
            else{
                m[i][j] = 0;
            }

        }
    }
    
    
    //cout<<target<<" "<<r<<" "<<c<<endl;
#ifdef BZZ
    cout<<"target "<<target<<endl;
#endif

    for(int i = 1; i <= r; i++)
        rows[i] += rows[i-1];
    
    for(int j = 1; j <= c; j++)
        cols[j] += cols[j-1];
    
#ifdef BZ
    for(const auto &it: rows) cout<<it<< " ";
    cout<<endl;
    for(const auto &it: cols) cout<<it<< " ";
    cout<<endl;
#endif

    h++;
    v++;
    target = target / (h*v);
    //vector<int> ans_h(h+1, -1);
    for(int i = 0; i <= h; i++){
        ans_h[i] = -1;
        for(int j = 0; j <= r; j++){
            if(rows[r]*i==rows[j]*h) ans_h[i] = j;
        }
        if(ans_h[i] == -1) return false;
    }


    //vector<int> ans_v(v+1, -1);
    for(int i = 0; i <= v; i++){
        ans_v[i] = -1;
        for(int j = 0; j <= c; j++){
            if(cols[c]*i==cols[j]*v) ans_v[i] = j;
        }
        if(ans_v[i]==-1) return false;
    }

#ifdef BZ
    //cout<<ans_h.size()<<endl;
    for(const auto &it: ans_h) cout<<it<< " ";
    cout<<endl;
    for(const auto &it: ans_v) cout<<it<< " ";
    cout<<endl;
#endif

    for(int i = 0; i < v; i++){
        for(int j = 0; j < h; j++){
            int s = 0;
            for(int x = ans_h[i]; x < ans_h[i+1]; x++){
                for(int y = ans_v[j]; y < ans_v[j+1]; y++){
                    #ifdef BZZ
                    cout<<x<<" "<<y<<" "<<m[x][y]<<endl;
                    #endif
                    s += m[x][y];                    
                }
            }
            //cout<<s<<endl;
            if(s!=target) return false;
        }
    }
    return true;

}


int main(){
    int t;
    cin >> t;
    for(int i = 1; i <= t; i++){        
        //int res = solve(l, n, dist);
        bool res = solve();
        if(res==true)
        cout<<"Case #"<<i<<": "<<"POSSIBLE"<<endl;        
        else
        cout<<"Case #"<<i<<": "<<"IMPOSSIBLE"<<endl;        
    }
}
