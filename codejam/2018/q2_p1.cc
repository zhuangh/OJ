#include<iostream>
#include<string>

using namespace std;
//#define ZH_DBUG

long eval(const string & s){
    long power = 1;
    long res = 0;
    for(int i = 0; i < s.size(); i++){
        if(s[i] == 'C') power *= 2;
        else res += power;
    }
    return res;
}


int sc_swap(string & s){
    int i = s.size()-1;
    for(; i > 0 ; i--){
        if(s[i] == 'S' && s[i-1] =='C') {
            swap(s[i], s[i-1]);
            break;
        }
    }
    return i;
}

int helper(const int & D, string & s){
    long res = eval(s);
    if(res<=D) return 0;
    int cnt = 0;
    int idx = s.size()-1;
    while(idx>0){
        idx = sc_swap(s);

    #ifdef ZH_DBUG
        cout<<s<<"=="<<eval(s)<<endl;
    #endif
        cnt++;
        if(eval(s)<=D) return cnt;
    }
    return -1;
}

int main(){
    int t;
    cin>>t;
    for(int k = 1; k<=t ; k++){
        long D;
        string s;
        cin>>D>>s;
    #ifdef ZH_DBUG
        cout<<s<<": "<<endl;
    #endif
        long res = helper(D, s);        
        cout<<"Case #"<<k<<": ";
        if(res==-1) cout<<"IMPOSSIBLE"<<endl;
        else cout<<res<<endl;
    }

    return 0;    
}