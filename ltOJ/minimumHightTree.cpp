#include<iostream>
#include<vector>
#include<queue>
#include<set>

using namespace std; 

class Solution {

public:
    vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
	vector<int> left_nodes ; 
	queue<int> cur_nodes;
	set<int> empty_set = {}; 
	vector< set<int> > edge_vector (n, empty_set);
	vector<int> degree(n,0);

	for( auto it : edges) {
	    edge_vector[it.first].insert(it.second);
	    degree[it.first]++; 
	    edge_vector[it.second].insert(it.first);
	    degree[it.second]++; 
	}

	if( n == 2 ) return vector<int>{0,1};
	if( n == 1 ) return vector<int>{0};

	int idx = 0; 
	for( auto it : degree ){
	    // cout<<idx<<" : " <<degree[idx]<<" with adj size = "<< edge_vector[idx].size() <<endl;
	    if(it==1 && degree[idx] != -1) {
		cur_nodes.push( idx );
		degree[idx] = -1; // remove from graph
	    }
	    else if (degree[idx] != -1){
		left_nodes.push_back(idx);
	    }
	    idx++;
	}
	// cout<<"current node "<<cur_nodes.size()<<endl;
	// cout<<"left node "<<left_nodes.size()<<endl;

	while( left_nodes.size() > 2){

	    while( !cur_nodes.empty()){
		int itt = cur_nodes.front();
		cur_nodes.pop();

		auto adj = edge_vector[itt].begin();  
		// cout<<"processing "<<itt<<endl; 
		// cout<<" -- processing "<< *adj <<endl;

		edge_vector[*adj].erase(itt); 
		degree[*adj]--;
		// cout<<" node decrease "<<cur_nodes.size()<<endl;
	    }

	    idx = 0 ;
	    left_nodes.resize(0);
	    for( auto it : degree ){
		// cout<<idx<<" : " <<degree[idx]<< " with adj size = "<< edge_vector[idx].size() <<endl;
		if(it == 1 && degree[idx] != -1) {
		    cur_nodes.push( idx );
		    degree[idx] = -1;
		}
		else if (degree[idx] != -1){
		    left_nodes.push_back(idx);
		}
		idx++;
	    }

	    // cout<<" update node "<<cur_nodes.size()<<endl;
	}

	/*
	while( !cur_nodes.empty() ) {
	    int it = cur_nodes.front();
	    cur_nodes.pop();
	    res.push_back(it);
	}
	*/
	return left_nodes ;

    }
};


int main(){
    Solution a ; 
    vector<pair<int, int> > edges = { {0,1}, {0,2},{2,3},{0,4},{2,5},{5,6},{3,7},{6,8},{8,9},{9,10} }; 
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
