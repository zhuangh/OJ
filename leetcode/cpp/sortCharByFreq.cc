 
bool ccmp(const std::pair<char, int> & a, const std::pair<char, int> & b)  {
    return a.second > b.second;
}

class Solution {
public:

   
   string frequencySort(string s) {
       string str="";
       unordered_map<char, int> counter;
       for(char it : s){
           counter[it] += 1;
       }
       
       std::vector< std::pair<char, int> > arr;
       
       for(auto it : counter){
           arr.push_back(std::make_pair(it.first, it.second));
       }
       
       sort(arr.begin(), arr.end(), ccmp);
       
       for(std::pair<char, int> it : arr){
           for(int i = 0; i < it.second; i++){
               str += it.first;
           }
       }
       
       return str;
   }
}; 


class Solution2 {
public:

    
    string frequencySort(string s) {
        string str=""; 
        unordered_map<char, int> counter;
        vector< vector<char> > bucket(s.size()+1);
        for(char it : s){
            counter[it] += 1; 
        }
        
        for(auto & it : counter){
            bucket[it.second].push_back(it.first);
        } 
        
        for(int i = s.size(); i >= 1 ; i--){ 
            for(auto it : bucket[i]){
                for(int j = 0; j < i; j++)
                    str += it;
            }
        }
        
          
        return str;
    }
}; 
