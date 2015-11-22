#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>

using namespace std;

struct UndirectedGraphNode{
    int label; 
    vector<UndirectedGraphNode *> neighbors;
    UndirectedGraphNode(int x ): label(x){}
};

class Solution{
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
	if( NULL == node ) return NULL;               
	queue<UndirectedGraphNode *> q;       
	q.push(node);

	UndirectedGraphNode * newNode = new UndirectedGraphNode ( node->label) ; 
	unordered_map<UndirectedGraphNode *  , UndirectedGraphNode * > qmap;
	qmap[node] = newNode; 
	while(!q.empty()){       
	    UndirectedGraphNode * cur = q.front();
	    q.pop();
	    int sz = cur->neighbors.size();
	    for(int i = 0; i< sz;i++)
	    {
		UndirectedGraphNode * n = cur->neighbors[i];                
		if( qmap.find(n) == qmap.end() ){                   
		    UndirectedGraphNode * newn = new UndirectedGraphNode(n->label);
		    q.push(n);                    
		    qmap[n] = newn;                   
		    qmap[cur]->neighbors.push_back(newn);
		}               
		else{                    
		    qmap[cur]->neighbors.push_back(qmap[n]);  
		}            
	    }        
	}       
	return newNode;   
    }
};

int main(){
    Solution sol;
    UndirectedGraphNode * node = new UndirectedGraphNode(1);

    /*
    node->neighbors.push(new UndirectedGraphNode(2));
    node->neighbors.push(new UndirectedGraphNode(3));
    node->neighbors.push(new UndirectedGraphNode(4));
    */


    sol.cloneGraph( node );
    return 0;
}
