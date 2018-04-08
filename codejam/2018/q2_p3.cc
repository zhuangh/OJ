#include <iostream>
#include <vector>

using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        vector<vector<bool>> mem(1000, vector<bool>(1000, false));
        int a;
        cin>>a;
        int x, y, x_done, y_done;
        x = 2; y = 2;
        while(1){
            cout<<x<<" "<<y<<endl;
            cout.flush();                                    
            cin>>x_done>>y_done;
            cout.flush();                  
            bool finished = true;
            if(!x_done && !y_done)  break;
            mem[x_done][y_done] = true;
            for(int i = -1; i <= 1; i++) {
                for(int j = -1; j <= 1; j++){
                    if(!mem[x+i][y+j]) {finished = false; break;}                                
                }
            }
            if(finished){
                if(y <= 997) {
                    y += 2;
                }
                else{
                    x += 2;
                    y = 2;
                }                            
            }
        }
        //cout<<
    }
    return 0;
}
