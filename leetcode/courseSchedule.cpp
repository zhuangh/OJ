#include<vector>
#include<map>
#include<iostream>

using namespace std;

class Solution {
public:
    void DFS( vector< vector<int> > & adj,  vector<bool> & visited, vector<bool> & path, int where, int from, bool & cycle){
	for( auto it : adj[where]) {  
	    if( path[it] == true ) {
		cycle = true;
		return ;
	    }
	    if( cycle == true) return; 
	    if( visited[it] == false)   {
		visited[it] = true;
		path[it] = true;
		// cout<<"Processing " << it <<endl;
		DFS(adj, visited, path,  it , from, cycle);
		// visited[it] = false; // <---- cause TLE 
		path[it] = false;
	    }
	}
    }


    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
	vector<bool> visited (numCourses, false);
	vector<bool> path (numCourses, false);
	vector< vector<int> > adj( numCourses) ;
	bool cycle = false;
	for( auto it : prerequisites){
	   // cout<<it.first<<endl;
	    adj[it.first].push_back(it.second);
	    visited[ it.first ] = false; 
	    path[ it.first ] = false; 
	    visited[ it.second ] = false; 
	    path[ it.second ] = false; 
	}

	for( int it =0 ; it < numCourses; it++){
//	    vector<int> towhereset = adj[it];
//	    for( auto towhere: towhereset){ 
		// cout<<"Process " << it <<endl;
	    if( visited[it] == false )  DFS( adj, visited, path, it , it , cycle); 
		// cout<<" cycle deteced "<<cycle<<endl;
	    if( cycle == true ) return false;
	}
	return true;
    }
};

int main(){
    Solution a ;
    // vector<pair< int , int > > prep = {{0,1},{1,2},{2,3}, {2,4},{3,0} };
    vector<pair< int , int > > prep = {{1,0},{2,0}};
    cout<<a.canFinish( 5 , prep)<<endl;
    return 0;
}
