#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>
using namespace std;


int main()
{
    int N, M, S;
    double V;
    vector<vector<double>> R(101, vector<double>(101, 0));
    vector<vector<double>> C(101, vector<double>(101, 0));
    vector<vector<int>> toNxt(101, vector<int>());
    cin>>N>>M>>S>>V;
    int a, b; 
    double Rab, Rba, Cab, Cba;

    for (int i = 0; i < M; ++i) {
	cin>>a>>b>>Rab>>Cab>>Rba>>Cba;
        R[a][b] = Rab; 
	R[b][a] = Rba;
        C[a][b] = Cab; 
	C[b][a] = Cba;
        toNxt[a].push_back(b);
        toNxt[b].push_back(a);
    }

    // SPFA
    vector<double> Dist(101, 0);
    queue<int> Q;
    vector<bool> inQueue(101, false);

    Dist[S] = V;
    Q.push(S);
    inQueue[S] = true;

    while (!Q.empty()) {
        int now = Q.front();
        inQueue[now] = false;
        Q.pop();
        for (int i = 0; i < toNxt[now].size(); ++i) {
            int nxt = toNxt[now][i];
            if (Dist[nxt] < (Dist[now]-C[now][nxt])*R[now][nxt]) {
                Dist[nxt] = (Dist[now]-C[now][nxt])*R[now][nxt];
                if (!inQueue[nxt]) {
		    // relax candidate
                    Q.push(nxt);
                    inQueue[nxt] = true;
                }
            }
        }
    }
    if (Dist[S] > V) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    return 0;
}

