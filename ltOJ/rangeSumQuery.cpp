#include<iostream>
#include<vector>

using namespace std;

class NumArray {
    vector<int> * num;
    
public:
    NumArray(vector<int> &nums) {
	num = &nums;
    }

    void update(int i, int val) {
	if ( i< num->size() ) (*num)[i] = val;
    }

    int sumRange(int i, int j) {
	if( j<num->size() ) {
	    int sum =  (*num)[i];
	    for(int s = i+1 ; s < j ; s++){
		sum+= (*num)[s];
	    } 
	    return sum;
	}
	else return 0;
    }

    void print(){
	for( int i = 0 ; i < num->size() ;i++){
	    cout<< (*num)[i]<<" ";
	}
	cout<<endl;
    }
};

int main(){

    vector<int> num;
    num = {0 ,1 ,2,3};
    NumArray a (num) ; 

    a.print();
    cout<<a.sumRange(3,3)<<endl;
    a.update(0,1);
    a.print();
    cout<<a.sumRange(3,3)<<endl;
    return 0;
}
