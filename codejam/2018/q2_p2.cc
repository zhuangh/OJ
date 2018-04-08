#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stdio.h>

using namespace std;
//#define ZH_DBUG
 
/*
void troubleSort(vector<int> & L){
    bool done = false;
    int sz = L.size();
    while(!done){
        done = true;
        for(int i = 0; i < sz - 2; i++){
            if(L[i] > L[i+2]){
                done = false;
                swap(L[i], L[i+2]);
            }            
        }
    }    
}
*/

int main(){
    int t;
    cin>>t;
    for(int k = 1; k<=t; k++){
        long D;
        string s;
        cin>>D; 
        vector<int> arr_odd;//(D/2+1, 0);
        vector<int> arr_even;//(D/2+1, 0);        
        int tmp = 0;
        for(int i = 0; i < D; i++){            
            cin>>tmp;
            //scanf("%d", &tmp);
            if(i%2) arr_even.push_back(tmp);
            else arr_odd.push_back(tmp);            
        }

        sort(arr_odd.begin(), arr_odd.end());
        sort(arr_even.begin(), arr_even.end());
        #ifdef ZH_DBUG
        for(const auto & it : arr_odd) cout<<it<<" ";
        cout<<endl;
        for(const auto & it : arr_even) cout<<it<<" ";
        cout<<endl;
        #endif

        
        int idx = D;
        for(int i = 1; i < D; i++){
            
            if(i%2) {
                #ifdef ZH_DBUG
                cout<<i<<arr_odd[(i-1)/2]<<arr_even[(i)/2]<<endl;
                #endif
                if(arr_odd[(i-1)/2] > arr_even[i/2]) {
                    idx = i - 1; break;
                }
            }
            else{
                #ifdef ZH_DBUG
                cout<<i<<arr_even[(i-1)/2]<<arr_odd[(i)/2]<<endl;
                #endif
                if(arr_even[(i-1)/2] > arr_odd[i/2]) {
                    idx = i- 1; break;
                }
            }

        }
        cout<<"Case #"<<k<<": ";
        if(idx<D) cout<<idx<<endl;
        else cout<<"OK"<<endl;
    }

    return 0;    
}


