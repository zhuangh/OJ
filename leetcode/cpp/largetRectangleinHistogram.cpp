// my old submission 
class Solution {
    public:
        int largestRectangleArea(vector<int> &height) {
            int len = height.size();
            if(len<=0) return 0;
            stack<int> s;
            height.push_back(0);
            int result = height[0];

            for(int i = 0 ; i < len + 1 ; i++){
                if( s.empty() || height[i] > height[s.top()] )
                {
                    s.push(i);
                }
                else{
                    int tmp  = s.top();
                    s.pop();
                    result = max(result, height[tmp] * ( s.empty() ? i : i - s.top() -1 ));
                    i--;
                }
            
            }
            return result;

        }
};
