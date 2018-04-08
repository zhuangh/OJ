#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
//#define PI 3.14159265

// only for test 1 

void solve_space(const double & s, vector<vector<double>> & res){
    double L = sqrt(2);
    //cout<<s/L<<endl;
    double theta = acos(s/L);// * 180/PI;    
    double alpha = acos(0.0)/2.0 - theta;
    //cout<<alpha/M_PI*180.0<<endl;
    double y = 0.5*sin(alpha);
    double x = -0.5*cos(alpha);
    res.push_back({x, y, 0});
    res.push_back({y, -x, 0});
    res.push_back({0, 0, 0.5});
}

int main(){
    int t;
    cin >> t;
    for(int i = 1; i <= t; i++){
        double s;
        cin>>s;
        vector<vector<double>> res;
        solve_space(s, res);
        cout<<"Case #"<<i<<": "<<endl;
        for(const auto & it : res){
            //cout<<it[0]<<" "<<it[1]<<" "<<it[2]<<endl;
            printf("%.16lf %.16lf %.16lf\n", it[0], it[1], it[2]);
        }
    }
    return 0;
}