#include<iostream>
#include<vector>
#include<map>
using namespace std;

//#define SDEBUG 1

class Solution {
private:
    bool check_left(const vector<int> & needs){
        for(auto it : needs)
            if(it < 0) return false;
        return true;
    }
    
    void print_vec(const vector<int> vec){
        for(const auto it : vec)
        cout<<it<<", ";
        cout<<endl;
    }
    
    bool check_final(const vector<int> & needs){
        for(auto it : needs)
        {   
            //cout<<it<<" | ";
            if(it != 0) return false;
        }
        return true;
    }
    
    vector<int> substract_purchase(const vector<int> & needs, const vector<int> & choice){
        vector<int> needs_ret;
        for(int i=0; i<needs.size(); i++){
            needs_ret.push_back(needs[i]-choice[i]);
        }
        return needs_ret;
    }
    
    int DFS(vector<int> &needs, vector<vector<int>> special, 
             int & pay, int progress, map<vector<int>, int> &mem ){           
        if(mem.find(needs) != mem.end()) return mem[needs]; 
        int len = special.size();
        int sz = special[0].size();
        for(int i = progress; i < len; i++) {           
            vector<int> choice = special[i];
            vector<int> needs_tmp = substract_purchase(needs, choice); 
            if (check_left(needs_tmp) == false) break;
            cout<<special[i][sz-1]<<endl;
            if(pay == 0) 
                pay = min(pay, special[i][sz-1] + DFS(needs_tmp, special, pay, progress, mem));
            cout<<pay<<endl;
        }
        mem[needs] = pay;
        return pay;
    }
    
public:
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        int sz = price.size();
        for(int i = 0; i < sz; i++){
            vector<int> tmp_price;
            for(int j =0; j < sz; j++){
                tmp_price.push_back(0);
            }
            tmp_price[i] = 1;
            tmp_price.push_back(price[i]);
            special.push_back(tmp_price);
        }
        int pay = 10000000;
        map<vector<int>, int> mem;
        pay = DFS(needs, special, pay, 0,  mem);
        if(pay == 10000000) pay = 0;
        return pay;  
    }
};

int main(){

  Solution a; // = new Solution();
     
  vector<int> price = {2, 5};
  vector<int> needs = {3, 2};
  vector<vector<int>> special = {{3,0,5},{1,2,10}};
   /*
  vector<int> price = {2,3,4};
  vector<vector<int>> special =  {{1,1,0,4},{2,2,1,9}};
  vector<int> needs = {1,2,1};   
  
  vector<int> price = {2,3,4};
  vector<vector<int>> special = {{1,1,0,4},{2,2,1,9}};
  vector<int> needs = {0,0,0};

  vector<int> price  {4,3,2,9,8,8};
  vector<vector<int>> special = {{1,5,5,1,4,0,18},{3,3,6,6,4,2,32}};
  vector<int> needs = {6,5,5,6,4,1};
  */
  cout<<a.shoppingOffers(price, special, needs)<<endl;
  
  return 0;
}
