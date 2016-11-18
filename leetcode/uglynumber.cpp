
#include<algorithm>
#include<vector>
#include<iostream>

using namespace std;

class Solution {
public:
    bool isUgly( long n){
	if ( n < 0 ) return false;
	while ( n > 1){
	    if( n % 2 ==0  ) {
		n /=2;
	    }
	    else if (n %3 == 0 ) {
		n /=3;
	    }
	    else if (n%5 ==0) {
		n/=5;
	    }
	    else return false;

	}
	return true;
    
    }

    int nthUglyNumber ( int n){

	int f = 1;
	int f2 = 0, f3 = 0, f5 = 0;
	vector<int> vec; 
	vec.push_back(1);
	int ff5 , ff2, ff3;

	for ( int i = 1 ; i < n; i++){
	    ff2 = 2*vec[f2];
	    ff3 = 3*vec[f3];
	    ff5 = 5*vec[f5];
	    f = min( ff2, min(ff3,ff5));
//	    cout<<f<<endl;
	    if ( f == ff2 ) {f2++;}
	    if ( f == ff3 ) {f3++;}
	    if ( f == ff5 ) {f5++;}
	    if ( f != vec.back()) vec.push_back(f);
	}

	return f ; 
    }
};

int main(){

    Solution a;
    cout<<a.isUgly(8)<<endl;
    cout<<a.isUgly(-9)<<endl;
    cout<<a.isUgly(-14)<<endl;
    cout<<a.isUgly(-2147483648)<<endl;


    cout<<a.nthUglyNumber(1)<<endl;
    cout<<a.nthUglyNumber(2)<<endl;
    cout<<a.nthUglyNumber(3)<<endl;
    cout<<a.nthUglyNumber(4)<<endl;
    cout<<a.nthUglyNumber(5)<<endl;

    cout<<a.nthUglyNumber(10)<<endl;

    return 0;
}

