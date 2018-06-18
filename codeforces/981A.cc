#include<iostream>
#include<string>
using namespace std;

bool pal(string & s){
    int j = s.size() - 1;
    int i = 0;
    while(i<j){
	if(s[i++] != s[j--]) return false;
    }
    return true;
}

int main(){
    string s;
    cin>>s;
    int n = s.size();
    for(int len = n; len >= 0; len--){
	for(int start = 0; start + len - 1< n; start++){
	    string sub = s.substr(start,len); 
	    if(pal(sub)) continue;
	    else {
		cout<<len<<endl;
		return 0;
	    }
	}
    }
    cout<<0<<endl;
    return 0;
}
