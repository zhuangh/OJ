
// my old submission 

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:



static bool myfunc( const Interval & lhs , const  Interval & rhs){
  // return ( a.start <= b.start);// ? a.end<b.end : a.start<b.start ;
     return (lhs.start==rhs.start) ? lhs.end < rhs.end : lhs.start < rhs.start;
}


vector<Interval> merge(vector<Interval> &intervals) {

/*
        vector<Interval> result;

    if (intervals.size() <= 0) return result;
    //sort the inervals. Note: using the customized comparing function.
    sort(intervals.begin(), intervals.end(), myfunc);
    for(int i=0; i<intervals.size(); i++) { 
        int size = result.size();
        // if the current intervals[i] is overlapped with previous interval.
        // merge them together
        if( size>0 && result[size-1].end >= intervals[i].start) {
            result[size-1].end = max(result[size-1].end, intervals[i].end); 
        }else{
            result.push_back(intervals[i]);
        }
    }
    
    return result;
    */
    
    
    if ( intervals.size() == 0 ) return {}; 
    
    sort( intervals.begin(), intervals.end() , myfunc);

    vector<Interval> ret ;
  

    ret.push_back(intervals[0]);

    for( int i = 1 ; i < intervals.size() ; i++ ){
	int size = ret.size(); 

	if( intervals[i].start <= ret[size-1].end ) {
	    ret[size-1].end = max( ret[size-1].end, intervals[i].end) ; 
	}
	else{
	    ret.push_back( intervals[i] );
	    // tmp = intervals[i];
	}
//	cout<<tmp.start<<":"<<tmp.end<<endl;
    }
//    ret.push_back(tmp);
    return ret;
}

    
};

