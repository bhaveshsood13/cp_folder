
#include<iostream>
using namespace std;
int main() {
    int t;
    cin>>t;
    int p=t;
    while(t--){
        int n;
        int ar[n];
        for(int i=0;i<n;i++)
            cin>>ar[i];
        int cnt=0;
        for(int i=1;i<n-1;i++){
            if(ar[i]>ar[i-1] && ar[i]>ar[i+1])
                {   cout<<"cnt ";
                    cnt++;}
                    
        }
        cout<<"Case #"<<p-t<<":"<<" "<<cnt<<endl;
    }
    
}
