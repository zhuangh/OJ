#include<iostream>
#include<vector>
#include<string>

// Expression Add Operators 

using namespace std;

class Solution{

    string bufferConstruct( vector<string> & buffer){
	string res ="";
	for( auto it : buffer) {
	    res += it;
	}
	return res; 
    }

    void addOptDFS(vector<string> & result, string num, long target , vector<string> & buffer,
		  int sep,  long op1,  long op2){

	if ( num.length() == sep &&  op1 + op2 == target){
	    result.push_back( bufferConstruct( buffer));
	} 

	long op3 =  0 ;
	for( int i = 0 ; i < num.length() - sep ; i++){
	    op3 = 10*op3+ ( (char) num[sep + i] - '0');
	    string val = std::to_string(op3);
    
	    buffer.push_back("+"+val);
	    addOptDFS( result, num, target, buffer, sep+i+1, op1+op2 , op3 );
	    buffer.pop_back();

	    buffer.push_back("-"+val);
	    addOptDFS( result, num, target, buffer, sep+i+1, op1+op2, -op3);
	    buffer.pop_back();

	    buffer.push_back("*"+val);
	    addOptDFS( result, num, target, buffer, sep+i+1,  op1 , op2*op3 );
	    buffer.pop_back();

	    if ( op3 == 0 )  break; // num[sep] = 0 , illegal merge  
	}
    }

public:
    vector<string> addOperators(string num, long target){
	vector<string> results;
	vector<string> buffer;
	long op3 = 0;

	for( int i =  0 ; i <  num.length() ; i++){ 
	    op3 = 10*op3+ ( (char) num[i] -  '0');
	    string val = std::to_string(op3);
	    buffer.push_back(val);
	    addOptDFS( results, num, target, buffer, i+1 , 0 , op3 );
	    buffer.pop_back();
	    if ( op3 == 0 )  break; // num[sep] = 0 , illegal merge  
	}
	return results;
    }
};

int main(){
    Solution a;
    //vector<string> b = a.addOperators("3456237490", 0);
    vector<string> b = a.addOperators("2147483648", -2147483648);

    for( auto it : b )
	cout<<it<<endl;

    return 0;
}

