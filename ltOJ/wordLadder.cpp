#include<iostream>
#include<unordered_set>
#include<string>
#include<vector>

using namespace std;

class Solution {
public:
    int ladderLength(string beginWord, string endWord, unordered_set<string>& wordList) {
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
};

int main(){
    unordered_set<string> wlist( {"hot", "dot" , "dog", "lot"} );
//    unordered_set<string> wlist( {"hot",  "dog"} );
    // unordered_set<string> wlist;
    Solution a;
    
    //cout<<a.ladderLength("hot","dog",wlist)<<endl;
    cout<<a.ladderLength("hit","cog",wlist)<<endl;
    return 0;
}



