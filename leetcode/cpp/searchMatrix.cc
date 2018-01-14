class Solution {
public:
    bool searchHelper(vector<vector<int>> & matrix, int xs, 
                      int ys, int xe, int ye, int target){
        if( xs > xe || ys > ye) return false;
        
        int xmid = (xs+xe)/2;
        int ymid = (ys+ye)/2;
        
        if(target == matrix[xmid][ymid] ) return true;
        else{
            if(target < matrix[xmid][ymid]){
                return (searchHelper(matrix, xs, ys, xmid-1 , ye, target) 
                        || searchHelper(matrix, xs, ys, xe, ymid-1, target));
            }
            else{
                return (searchHelper(matrix, xmid+1, ys, xe , ye, target) 
                        || searchHelper(matrix, xs, ymid+1, xe, ye, target));
            }
        }
    }
    
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int hlen = matrix.size();
        if( hlen == 0 ) return false;
        int wlen = matrix[0].size();
        if( wlen == 0 ) return false;
        return searchHelper(matrix, 0, 0, hlen-1, wlen-1, target);
    }
};
