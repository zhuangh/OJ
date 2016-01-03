#include<iostream>
#include<vector>
#include<queue>
#include<set>

using namespace std; 

class Solution {

public:
    vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
	int original_size = n ;
	vector< vector<int> > edge_vector(n);
	vector<int> degree(n,0);
	queue<int> cur_nodes; 
	for( auto it : edges) {
	    edge_vector[it.first].push_back(it.second);
	    degree[it.first]++; 
	    edge_vector[it.second].push_back(it.first);
	    degree[it.second]++; 
	}

	int idx = 0;
	for( auto it : degree){
	    if( it == 1 ) cur_nodes.push(idx);
	    idx++;
	}

	while( n > 2 ){
	    int sz = cur_nodes.size();
	    
		// cout<<"size = "<<sz<<endl;

	    for( int i = 0 ;  i < sz ; i++){
		int di = cur_nodes.front();
		cur_nodes.pop();
		n--;
//cout<<"processing "<< di<<":"<<endl;
		for( auto j : edge_vector[ di ] ){
		    degree[j]--;
		    if(degree[j]==1) {
			cur_nodes.push(j);
//cout<<" -- adding "<< j <<" "<<endl;
		    }
		}
	    }

	  //  cout<<"update size = "<<cur_nodes.size()<<endl;
	}

	vector<int> res; 
	if(  original_size == 1) res.push_back(0);
	while( !cur_nodes.empty()){
	    res.push_back( cur_nodes.front());
	    cur_nodes.pop();
	}
	return res;
    }
};


int main(){
    Solution a ; 
    // vector<pair<int, int> > edges = { {0,1}, {0,2},{2,3},{0,4},{2,5},{5,6},{3,7},{6,8},{8,9},{9,10} }; 
    vector<pair<int, int> > edges = { {1,0},{1,2},{1,3}   }; 
/*
    edges.push_back(make_pair<int,int>(0,3));
    edges.push_back(make_pair<int,int>(1,3));
    edges.push_back(make_pair<int,int>(2,3));
    edges.push_back(make_pair<int,int>(3,4));
    edges.push_back(make_pair<int,int>(4,5));
    edges.push_back(make_pair<int,int>(5,6));
    edges.push_back(make_pair<int,int>(5,7));
*/
    int n = edges.size()+1 ;
    cout<<"result: "<< n <<endl;
    vector<int> b = a.findMinHeightTrees( n , edges);

    for(auto it : b) cout<<it<<endl;

    return 0; 
}
