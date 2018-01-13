class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, int> counter;
        for(char it : s){
            counter[it] += 1;
        }
        for(int i=0; i<s.size(); i++){
            if(counter[s[i]] == 1) return i;
        }
        return -1;
    }
};