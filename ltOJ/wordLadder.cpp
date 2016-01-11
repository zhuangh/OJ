#include<iostream>
#include<unordered_set>
#include<string>
#include<vector>
#include<queue> 
#include<map> 

using namespace std;

class Solution {
public:
    // solution 1 
    int ladderLength1(string beginWord, string endWord, unordered_set<string>& wordList) {
	vector<string> q_cur, q_next;
	q_cur.push_back(beginWord);
	int level = 0;

//	cout<<beginWord<<" --> " << endWord<<endl;
	do{

	    //	for( auto it : q_cur) cout<<it<<endl;
	    level++;
	    while(q_cur.size()>0){
		//	    cout<<level<<endl;
		string cur_element = q_cur.back(); 
		q_cur.pop_back();
		for( int j = 0 ; j < cur_element.length() ; j++){
		    string tmp = cur_element ; 
		    for( int i = 0 ; i < 26 ; i++){
			tmp[j] = 'a'+i;
			if ( tmp == endWord ) return level + 1;
			unordered_set<string>::iterator it= wordList.find( tmp ); 
			if( it != wordList.end() ) 
			{
			    wordList.erase(it);
			    q_next.push_back( tmp);
			}
		    }
		}
	    }


//	   	for( auto it : q_next) cout<<it<<" " ;
	//	cout<<endl;
	    // cout<<q_cur.size()<< " "<< q_next.size() <<endl;
//	    q_cur.swap(q_next);
	    swap( q_cur,q_next);
	    // cout<<q_cur.size()<< " "<< q_next.size() <<endl;
	}while(q_cur.size() > 0); 

	return 0;
    }

    // solution 2 using Dijkstra's algorithm


    int ladderLength(string beginWord, string endWord, unordered_set<string>& wordList) {
	typedef pair<int, int> PII;
	int n = wordList.size();


	//cout<<"word list size = "<<n+2<<endl;

	map<string, int> index_mapping ; 
	int cnt  = 0 ; 
	index_mapping[beginWord] = cnt++;
	index_mapping[endWord] = cnt++;


	for( auto it : wordList ){
	    index_mapping[it] = cnt++;
	}

	vector<vector<PII> > edges(cnt);  
	// cout<<cnt<<endl;
	map< PII, bool> visited_edge;


	
	wordList.insert( beginWord ); 
	wordList.insert( endWord ); 

	for( auto it : wordList ){
	    for( int  i = 0; i<26;i++){
		int a = index_mapping[it];
		char ch = i + 'a'; 
		for( int j = 0 ; j < it.length(); j++){
		    string target = it;   
		    target[j] = ch;
		    visited_edge[ make_pair(a,a)] = true;
		    if(
		       wordList.find( target ) != wordList.end() 
		      ){ 
			int b = index_mapping[target];
			visited_edge[ make_pair(b,b)] = true;
			if ( visited_edge[make_pair(a,b)] == false){ 
			    edges[a].push_back( make_pair(b, 1));
			    edges[b].push_back( make_pair(a, 1) );
			    visited_edge[ make_pair(a,b) ] = true;
			    visited_edge[ make_pair(b,a) ] = true;
			}
		    }
		}
	    }
	}



	/*

	int iter = 0 ;
	for(auto it : edges){
	    cout<<iter<<" --- "<<" : ";
	    for(auto jt : it){
		cout<<jt.first<<" distance "<<jt.second <<"; ";
	    }
	    iter++;
	    cout<<endl;
	}
	*/


	// after graph constrauction 

	priority_queue<PII, vector<PII>, greater<PII> > Q; 
	int INF = 100000000;
	vector<int> dist (cnt, INF) ;
	vector<int> dad (cnt, -1);
	dist[0] = 0;

	Q.push ( make_pair ( 0 , 1 ));  
	while( ! Q.empty() ){
	    PII p = Q.top();
	    if ( p.first == 1 )  break;
	    Q.pop();
	    int here = p.first; 
	    for( auto it : edges[here] ){
		if( dist[it.first] > dist[here] + it.second){
		dist[ it.first ] = dist[here] + it.second;
		dad[ it.first ]= here;
		Q.push(make_pair ( it.first, it.second ));
		}
	    }
	}

	/*
	for( int i = 0 ; i < cnt ;i++){
	    cout<<dist[i]<<endl;
	}
	*/

	if( dist[1] < INF) { return 1; } 
	return 0;
    }

};

int main(){
//    unordered_set<string> wlist( {"hot", "dot" , "dog", "lot"} );
    unordered_set<string> wlist( {} );
    // unordered_set<string> wlist;
    Solution a;
    
    //cout<<a.ladderLength("hot","dog",wlist)<<endl;
    // cout<<a.ladderLength("hit","cog",wlist)<<endl;
    cout<<a.ladderLength("cot","hot",wlist)<<endl;
    return 0;
}



