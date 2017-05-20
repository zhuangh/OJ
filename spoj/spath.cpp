#include<iostream> 
#include<vector>
#include<unordered_map>
#include<set> 
#include<string>


// g++ spath.cpp --std=c++11

using namespace std;


/*
Defined in header <set>
template<
    class Key,
    class Compare = std::less<Key>,
    class Allocator = std::allocator<Key>
> class set;
(1)	
namespace pmr {
    template <class Key, class Compare = std::less<Key>>
    using set = std::set<Key, Compare, std::pmr::polymorphic_allocator<Key>>;
}
(2)	(since C++17)
std::set is an associative container that contains a sorted set of unique objects of type Key. Sorting is done using the key comparison function Compare. Search, removal, and insertion operations have logarithmic complexity. Sets are usually implemented as red-black trees.
Everywhere the standard library uses the Compare concept, uniqueness is determined by using the equivalence relation. In imprecise terms, two objects a and b are considered equivalent if neither compares less than the other: !comp(a, b) && !comp(b, a).
std::set meets the requirements of Container, AllocatorAwareContainer, AssociativeContainer and ReversibleContainer.

*/

int INT_MAX = 200000000;
struct edge{int to, length;};

int dijkstra(const vector<vector<edge> > &graph, int source, int target){
    vector<int> min_distance(graph.size(), INT_MAX);
    min_distance[source] = 0 ;
    set< pair<int, int> > active_vertices; // using a set to store the "priority queue" of active vertices. 
    active_vertices.insert({0, source}); 
    while(!active_vertices.empty()){
        int where = active_vertices.begin()->second; // get the index of the graph node
        if(where == target) return min_distance[where];
        active_vertices.erase( active_vertices.begin() ); // remove the smallest edge
        for(auto ed: graph[where]){
            if(min_distance[ed.to] > min_distance[where] + ed.length){
                active_vertices.erase( {min_distance[ed.to], ed.to });
                min_distance[ed.to] = min_distance[where] + ed.length;
                active_vertices.insert({min_distance[ed.to], ed.to});
            }
        }
    }
    return INT_MAX;
}

int main(){
    int s;
    cin>>s; 
    for( int test = 0 ; test < s; test++){
        vector< vector<edge> > graph;
        int n;
        cin>>n;
        unordered_map<string, int> id;
        for( int i = 0 ; i < n; i++){
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
            cout<<dijkstra( graph, id[source], id[target] )<<endl;
        }
    }    
    return 0;
}