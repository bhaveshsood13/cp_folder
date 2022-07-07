#include <iostream>
using namespace std;

int dpmin (int n , int dp[] ){
    if(n==1 or n==0){
        return 0;
    }
    int a,b,c;
    if(dp[n-1]!=0){
        a=dp[n-1];
    }
    else{
        a=dpmin(n-1,dp);
    }
    if(dp[n/2]!=0){
        b=dp[n/2];
    }
    else{
        b=dpmin(n/2,dp);
    }

    if(dp[n/3]!=0){
        c=dp[n/3];
    }
    else{
        c=dpmin(n/3,dp);
    }
     int steps=-1;
    if(n%2==0 and n%3==0)
    steps=min(a , min(b,c));
    else if(n%2==0){
        steps=min(a , b);
    }
    else if(n%3==0){
        steps=min(a, c);
    }
    else {
        steps= a;
    }

	dp[n]=steps+1;
    return steps+1;
}



int min_steps1 (int n ){
    if(n==1){
        return 0;
    }
    int steps=-1;
    if(n%2==0 and n%3==0)
    steps=min(min_steps1(n-1) , min(min_steps1(n/2) ,min_steps1(n/3)) );
    else if(n%2==0){
        steps=min(min_steps1(n-1) , min_steps1(n/2));
    }
    else if(n%3==0){
        steps=min(min_steps1(n-1), min_steps1(n/3));
    }
    else {
        steps= min_steps1(n-1 );
    }
    return steps+1;
}

int main() {
    cout<<"Hello World"<<endl;
    int dp[2000000]={0};
    cout<<"Min steps for n = 10 is "<< dpmin(1000,dp);
    
}
