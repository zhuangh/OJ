#include <iostream>
#include <vector>
#include <utility>
#include <set>
#include <algorithm>
/*
For instance, the dimensions of all buildings in Figure A are recorded as: [ [2 9 10], [3 7 15], [5 12 12], [15 20 10], [19 24 8] ] .

The output is a list of "key points" (red dots in Figure B) in the format of [ [x1,y1], [x2, y2], [x3, y3], ... ] that uniquely defines a skyline. A key point is the left endpoint of a horizontal line segment. Note that the last key point, where the rightmost building ends, is merely used to mark the termination of the skyline, and always has zero height. Also, the ground in between any two adjacent buildings should be considered part of the skyline contour.

For instance, the skyline in Figure B should be represented as:[ [2 10], [3 15], [7 12], [12 0], [15 10], [20 8], [24, 0] ].
 
 */

using namespace std;

class Solution {
public:
    vector< pair<int, int> > getSkyline( vector<vector<int> > & buildings){

	vector< pair<int , int > > sides; 
	vector< pair<int , int > > result; 

	for( int i=0; i < buildings.size() ; i++){
	   int  left = buildings[i][0]; 
	   int  right = buildings[i][1]; 
	   int  height = buildings[i][2]; 
	   sides.push_back(make_pair(left, -height)); 
	   sides.push_back(make_pair(right, height)); 
	}
	sort(sides.begin(), sides.end());

	int prev_h = 0 ; 
	int cur_h = 0 ; 

	multiset<int> hmax ;
	hmax.insert(0);

	for( int i = 0  ; i < sides.size() ; i++){

	    if( sides[i].second< 0 ){
		hmax.insert(-sides[i].second);
	    } 
	    else{
		hmax.erase( hmax.find(sides[i].second)); 
	    }

	    cur_h = *(hmax.rbegin());
	    if( cur_h != prev_h) {
		result.push_back(make_pair( sides[i].first, cur_h)); 
		prev_h = cur_h;
	    }
	}

	return result;
    }
};

int main(){
    int mya[] = {2,9,10};
    int myb[] = {3,7,15};
    int mye[] = {5,12,12};
    int myc[] = {15,20,10};
    int myd[] = {19,24,8};

// [ [2 9 10], [3 7 15], [5 12 12], [15 20 10], [19 24 8] ] .

    vector<int> a (mya, mya+sizeof(mya)/sizeof(int) ) ; 
    vector<int> b (myb, myb+sizeof(myb)/sizeof(int) ) ;
    vector<int> c (myc, myc+sizeof(myc)/sizeof(int) ) ;
    vector<int> d (myd, myd+sizeof(mya)/sizeof(int) ) ;
    vector<int> e (mye, mye+sizeof(mye)/sizeof(int) ) ;

    vector< vector<int> > vin ; 
    vin.push_back(a); 
    vin.push_back(b); 
    vin.push_back(e); 
    vin.push_back(c); 
    vin.push_back(d); 

    /*
    for( int i = 0 ; i < vin.size();  i++){
	cout<<vin[i][0]<<" "<<vin[i][1]<<" "<<vin[i][2]<<endl;
    }
    */

    Solution sol ; 

    vector< pair<int, int> > res =  sol.getSkyline( vin); 

    for( int i = 0 ; i < res.size();  i++){
	cout<<res[i].first<<" "<<res[i].second<<endl;
    }

    return 0;
}

