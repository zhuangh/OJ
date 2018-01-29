using pairType = std::pair<int, int>;
//using std::unordered_map<int, std::unordered_map<int, int> > = graphType;
using graphType = std::unordered_map<int, vector<pairType> >; // std::unordered_map<int, int> > graphType;
using heapType = std::priority_queue<pairType, vector<pairType> >;

class Solution {

private:
    
    int dijkstra(const int & K, const int &N, std::vector<int> &delay, graphType & graph, const int &TIMEOUT ){
        int d = -1;
        heapType Q;
        delay[K]=0;
        Q.push(std::make_pair(0, K));
        while(Q.size()>0){
            const std::pair<int, int> dnode = Q.top();
            int node = dnode.second;
            Q.pop();
            const vector<pairType> vec_link = graph[node];
            for(const auto & vw : vec_link){
                    int v = vw.first;
                    int w = vw.second;
                    if(delay[node] + w < delay[v]){
                        delay[v] = delay[node] + w;
                        Q.push(std::make_pair(-w, v));
                    }
                } 
            /*
            cout<<"size "<<Q.size()<<endl;
            for(auto it : delay){
                cout<<it<<endl;
            }
            */
            
        }
        for(const auto & it : delay){
            if( it > d ) d = it;
            if( it == TIMEOUT) return -1; //delay = -1;
        }
        return d;
    }
    
public:
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        const int TIMEOUT = 10000;
        std::vector<int> delay(N, TIMEOUT);
        graphType graph;
        
        for(int i=0; i < times.size(); i++){ 
            int u = times[i][0] -1;
            int v = times[i][1] -1;
            int w = times[i][2];
            graph[u].push_back(make_pair(v, w));
        }
        
        return dijkstra(K-1, N, delay, graph, TIMEOUT); 
    }
};
