class KV{
public:
    string word;
    int count;
    KV(string k, int v):word(k),count(v){}
};

class compare_KV{ // customiz for the max-heap to min-heap
public:
  bool operator() (KV &a, KV &b){
      if (a.count > b.count){
          return true;
      }
      else{
          if(a.count == b.count){
              if(a.word < b.word){
                  return true;
              }
          }
      }
      return false;
  }  
};

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        std::map<string, int> counter;
        for(auto it : words){
            if(counter.find(it) == counter.end()){
                counter[it] = 1;
            }
            else counter[it]++;
        } 
        // min-heap
        std::priority_queue<KV, std::vector<KV>, compare_KV> hp; // use max_heap in std c++
        for(auto it : counter){
            KV kv_it(it.first, it.second); 
            hp.push(kv_it);
            int sz = hp.size();
            //std::cout<<sz<<endl;
            if( hp.size() > k) {
                 hp.pop();
            }
        }
        vector<string> res;
        for(int kit = 0; kit < k; kit++){
            KV kv_it = hp.top();
            hp.pop();
            res.push_back(kv_it.word);
        }
        std::reverse(res.begin(), res.end());
        return res;
    }
};

