class Solution {
public:
    string longestPalindrome(string s) {
        std::vector< std::vector<int> > mm;
        int tmp = 1;
        int e = 1;
        int r = s.length();
        if(r<=1) return s;
        for(int i = 0 ; i < r+1 ;i++){
            std::vector<int> m;
            for(int j = 0 ; j < r+1 ; j++){
                if (i==j) m.push_back(1);
                else m.push_back(0);
            }
            mm.push_back(m);
        }
        
        for(int k = 2 ; k <= r; k++){ // k is the length of string to check
            if(tmp > k) continue; // no need to compute the length small than the tmp 
            for(int i = 1; i <= r - k + 1; i++ ){
                int j = i + k -1;
                if(s[i-1] == s[j-1]){
                    if(mm[i+1][j-1] != 0 || j - i <= 2) mm[i][j] = j - i + 1;
                    if(mm[i][j] > tmp) {tmp = mm[i][j]; e = i;}
                }
            }
        } 
        return s.substr(e-1, tmp);
    }
};

