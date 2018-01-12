using hq_type = priority_queue<int, vector<int>, greater<int> > ;
using map_q_type = unordered_map<int, shared_ptr<hq_type> >; 

class Solution {
public:
    void print(map_q_type mm){
        for(map_q_type::iterator kv = mm.begin(); kv != mm.end(); kv++)
            printf("%d : %d\n", kv->first, (kv->second)->size());
    }
    
    bool isPossible(vector<int>& nums) {

        map_q_type mm;
        for(auto it : nums){
            if(mm.find(it-1) == mm.end() || mm[it-1]->size() == 0){
                if (mm.find(it) == mm.end()) mm[it] = std::make_shared<hq_type>();
                mm[it]->push(1);
            }
            else{
                if(mm[it-1]->size() > 0){
                    int l = mm[it-1]->top();  
                    mm[it-1]->pop(); 
                    if(mm.find(it) == mm.end()) mm[it] = std::make_shared<hq_type>();
                    mm[it]->push(l+1);
                }
            }
        } 
        for(map_q_type::iterator kv = mm.begin(); kv != mm.end(); kv++){
            while(kv->second->size()>0){
                int l = kv->second->top();
                if(l<3) return false;
                kv->second->pop();
            }
        }
 
        return true;
    }
};