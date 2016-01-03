#include<stdio>



int main(){
    int N, ML, MD;
    scanf("%d %d %d", &N,&ML,&MD);
    for(int i = 0 ; i < ML ; i++){

    }
    for(int i = 0 ; i < MD ; i++){

    }
    return 0; 
}

/*
Input

Line 1: Three space-separated integers: N, ML, and MD. 

Lines 2..ML+1: Each line contains three space-separated positive integers: A, B, and D, with 1 <= A < B <= N. Cows A and B must be at most D (1 <= D <= 1,000,000) apart. 

Lines ML+2..ML+MD+1: Each line contains three space-separated positive integers: A, B, and D, with 1 <= A < B <= N. Cows A and B must be at least D (1 <= D <= 1,000,000) apart.
Output

Line 1: A single integer. If no line-up is possible, output -1. If cows 1 and N can be arbitrarily far apart, output -2. Otherwise output the greatest possible distance between cows 1 and N.

Sample Input

4 2 1
1 3 10
2 4 20
2 3 3

Sample Output
27
 */
