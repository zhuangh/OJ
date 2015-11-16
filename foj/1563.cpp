#include<cmath>
#include<iostream>
using namespace std;

#define MAX 1000001
bool prime[MAX];
int num[MAX];
void searchprime()
{
	int i,j;
	memset(prime, true, sizeof(prime));
	prime[1]=prime[0]=false;
	for(i=2; i<=sqrt((double)MAX ); i++){
	    if(prime[i]){
	        for(j=i; i*j<MAX; ++j){
		    prime[i*j]=false;
		}
	    }
	}
	num[0]=num[1]=0;
	for(i=2;i<MAX;i++)
      {if(prime[i])num[i]=num[i-1]+1;
	else num[i]=num[i-1];}
	
	//for(j=0;j<=100;j++)
 //cout<<num[j]<<" ";
	
}


int main()
{
    searchprime();
    int a, b, s, i;
	int times;
cin>>times;
while(times--){
   cin>>a>>b;
    
        s=0;
        if(a>b)swap(a, b);
         
	      if(prime[a]) s=num[b]-num[a]+1;
        else s=num[b]-num[a];
        cout<<s<<endl;
    }
    return 0;
}
