
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

#define INT int
using namespace std;
// g++ -ggdb -std=c++1y trapping-rain-water-ii.cpp -o trapping-rain-water-ii.exe
class tupleItem{
private:
    INT x = 0;
    INT y = 0;
    INT h = 0;
public:
    tupleItem(INT xx, INT yy, INT hh):x(xx),y(yy),h(hh){}
    INT get_x () const { return x;}
    INT get_y () const { return y;}
    INT get_h () const { return h;}
    /*
    bool operator > (const tupleItem &rhs) const{
        return h > rhs.h;
    }
    */
};



class Solution {
public:
    struct compareGreater{
        bool operator()(const tupleItem &lhs, const tupleItem &rhs){
            return (lhs.get_h() > rhs.get_h());
        }
    };

    INT trapRainWater(vector<vector<int>>& heightMap) {
        INT rlen = heightMap.size();
        INT clen = 0;
        INT res = 0; 
        if(rlen>0){
            clen = heightMap[0].size();
        }
        else return 0;
        // marked the visited map
        vector<vector<bool>> visited;
        visited.resize(rlen);
        //for(auto vi : visited){
        for(INT i = 0; i < rlen; i++)
            visited[i].resize(clen, false);
        //}
        // organize data
        int r_i = 0;
        //vector<tupleItem> vtmp;
        std::priority_queue<tupleItem, vector<tupleItem>, compareGreater> vtmp;

        for(int i = 0 ; i < clen; i++){ 
             tupleItem tmp0(0, i, heightMap[0][i]);
             vtmp.push(tmp0);
             visited[0][i]=true;
             tupleItem tmp1(rlen-1, i, heightMap[rlen-1][i]);
             vtmp.push(tmp1);
             visited[rlen-1][i]=true;
        }
        for(int i = 1 ; i < rlen-1; i++){ 
             tupleItem tmp0(i, 0, heightMap[i][0]);
             vtmp.push(tmp0);
             visited[i][0]=true;
             tupleItem tmp1(i, clen-1, heightMap[i][clen-1]);
             vtmp.push(tmp1);
             visited[i][clen-1]=true;
        }
       
        //std::make_heap(vtmp.begin(), vtmp.end());
        // heap
        //cout<<vtmp.size()<<endl;
        vector<std::pair<INT, INT>> direction = {{0,1},{0,-1},{1,0},{-1,0}};
        INT max_h = -1;
        INT store = 0;
        while(!vtmp.empty()){
            tupleItem tmp = vtmp.top(); 
            vtmp.pop();
            INT h = tmp.get_h();
            INT x = tmp.get_x();
            INT y = tmp.get_y();
            //cout<<h<<endl;
            if(max_h < h) {
                max_h = h;
            }
            //cout<<max_h<<endl;
            //store += (max_h - h);
            for( auto it : direction){
                INT xx = x + it.first;
                INT yy = y + it.second;
                if( !(xx < rlen && xx >= 0 && yy < clen && yy >= 0 ) || visited[xx][yy]) continue;
                if( heightMap[xx][yy] < max_h ) {
                    //cout<<"hdelta "<<max_h - heightMap[xx][yy]<<" store = "<<store<<endl;
                    store+=(max_h - heightMap[xx][yy]);
                }
                //cout<<"push "<<xx<<", "<<yy<<endl;
                visited[xx][yy] = true; 
                tupleItem tmp(xx, yy, heightMap[xx][yy]);
                vtmp.push(tmp);
            }
        }
        return store;
    }
};


int main(){
    Solution a;
    //vector<vector<int>> hm = {{12,13,1,12},{13,4,13,12},{13,8,10,12},{12,13,12,12},{13,13,13,13}};
    vector<vector<int>> hm = {{5,5,5,1},{5,1,1,5},{5,1,5,5},{5,2,5,8}};
    cout<<a.trapRainWater(hm)<<endl;
    return 0;
}