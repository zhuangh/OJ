#include<iostream>
//#include<string>
#include<vector>
#include<unordered_map>
#include<set>
#include<map>
#include<string>


using namespace std;

int INT_MAX = 200000000;
struct edge{int to, length;};

int dij(const vector<vector<edge> > &graph, int source, int target){
    vector<int> min_distance(graph.size(), INT_MAX);
    min_distance[source] = 0 ;
    set< pair<int, int> > active_vertices; // using a set to store the "priority queue" of active vertices. 
    active_vertices.insert({0, source});

    while(!active_vertices.empty()){
        int where = active_vertices.begin()->second;
        if(where == target) {
            return min_distance[where];
        }
        active_vertices.erase( active_vertices.begin() );
        for(auto ed: graph[where]){
            //cout<<where<<" -edge-> "<<ed.to<<" w/ "<<ed.length<< " : ";
            if(min_distance[ed.to] > min_distance[where] + ed.length){
                active_vertices.erase( {min_distance[ed.to], ed.to });
                min_distance[ed.to] = min_distance[where] + ed.length;
                //cout<<"from "<<where<<" w/ "<<min_distance[where]<<" with "<<ed.length<<"-->"<<min_distance[ed.to]<<"@"<<ed.to<<endl;
                active_vertices.insert({min_distance[ed.to], ed.to});
            }
        }
    }

    return INT_MAX;
}

int main(){
    int s;
    cin>>s;
    //cout<<s;
    for( int test = 0 ; test < s; test++){
        vector< vector<edge> > graph;
        int n;
        cin>>n;
        unordered_map<string, int> id;
        //map<string> id;
        //graph.resize(n);
        for( int i = 0 ; i < n; i++){
            //int nei = 0;
            //cin >> nei;
            string name;
            cin >> name;
            id[name] = i;
            vector<edge> edges;
            int nei;
            cin >> nei;
            for(int j = 0 ; j < nei; j++){
                int nr, cost;
                cin>>nr;
                cin>>cost;
                edge e ;
                e.to = nr-1;
                e.length = cost;
                edges.push_back(e);
            }
            graph.push_back(edges);
        }
        int r;
        cin>>r;

        for(int i = 0 ; i < r; i++){
            string source, target;
            cin>>source;
            cin>>target;
            //cout<<id[source]<<" <-> "<< id[target]<<endl;

            //cout<<&graph<<endl;
            cout<<dij( graph, id[source], id[target] )<<endl;
        }
    }    

    return 0;
}
/*
         for( auto it : graph){
               // cout<<j++<<endl;
                for(auto itt: it){
                 //   cout<<itt.to<<" "<<itt.length<<" ; ";
                }
                cout<<endl;
            }
            */