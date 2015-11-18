#include<stdio.h>
#include<iostream>
using namespace std;

class Solution {

public:

        bool canWinNim(int n) {
	    if(n%4==0) return false;
	    return true;
	}

};

int main( ){
    Solution a;
    cout<<a.canWinNim(4)<<endl;
    cout<<a.canWinNim(1)<<endl;
    cout<<a.canWinNim(12)<<endl;
    return 0;
}
