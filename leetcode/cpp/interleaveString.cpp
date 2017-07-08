// from my old submission 
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
	int len1 = s1.length(); 
	int len2 = s2.length();
	int len3 = s3.length();
	if ( (len1 + len2) != len3) return false;

	bool ** A = new bool * [len2+1] ;

	for ( int i = 0 ; i < len2 + 1; i++ ){
	    A[i] = new bool  [len1+1];
	    for(int j = 0 ; j < len1+1 ;j++){
		A[i][j]= false;
	    }
	}
	A[0][0] = true;
	for ( int i = 0 ; i < len2 + 1; i++ ){
	    for(int j = 0 ; j < len1+1 ;j++){
		if(i == 0 ){
		    if(j > 0 ) {
			if( A[ i ][j-1] == true && s1[ j-1 ] == s3[j-1] ) A[i][j] = true;
		    }
		}
		else{
		    if(j == 0 ){
		       if( A[i-1][j] == true && s2[i-1] == s3[i-1]  ) A[i][j] = true;	
		    }
		    else{
			//if( ( s2[i-1] == s3[ i+j-1] || s1[j-1] == s3[i+j-1] ) && (A[i-1][j] == true  || A[i][j-1] == true)) {
			    if( (A[i][j-1] == true &&  s1[j-1] == s3[ i+j-1]) || ( s2[i-1] == s3[i+j-1] && A[i-1][j] == true )){
			        A[i][j] = true;
			    }
		    }
		}
	    }
	}


	/*
	for(int i = 0 ; i < len3; i++){

		cout<<s1[i]<<endl;
		cout<<s3[i]<<endl;
		cout<<A[0][i]<<endl;
	    for 

	    if( s1[i] == s3[i]  && A[0][i] == true ) {
		A[0][i+1] = true;
	    }
	    if( s2[i] == s3[i]  && A[i][0] == true ) {
		A[i+1][0]= true
	    };
	}
	 */

	/*
	for ( int i = 0 ; i < len2 + 1; i++ ){
	    for(int j = 0 ; j < len1+1 ;j++){
		cout<<	A[i][j]<<" , ";
	    }
	    cout<<endl;
	}
	*/
	return A[len2][len1]; 
    }
};
