// Program to find minimum number of platforms
// required on a railway station
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends

typedef pair<int,int> pi;

class Solution

{


    public:
    //Function to find the minimum number of platforms required at the
    //railway station such that no train waits.
    int findPlatform(int arr[], int dep[], int n)
    {
    	// Your code here
    	
    // 	{vector<pi> vi;
    // 	for(int i=0;i<n;i++){
    // 	    vi.push_back({arr[i],dep[i]});
    // 	}
    // 	sort(vi.begin(),vi.end());
    // 	int l=vi[0].first;
    // 	int r=vi[0].second;
    // 	int count=1;
    // 	int maxcount=1;
    // 	priority_queue<int,vector<int> , greater<int>> pq;
    // 	pq.push(r);
    // 	for(int i=1;i<n;i++){
    // 	    pi cur=vi[i];
    // 	    if(cur.first<=r){
    // 	        count++;
    // 	        maxcount=max(maxcount,count);
    // 	        pq.push(cur.second);
    // 	        r=pq.top();
    // 	    }
    // 	    else {
    // 	        pq.pop();
    // 	        if(!pq.empty()){
    //     	        r=pq.top();
    //     	        while(cur.first>r and !pq.empty()){
    //     	            r=pq.top();
    //     	            pq.pop();
    //     	            count--; 
    //     	        }
    // 	        }
    // 	        if(pq.empty()){
    // 	            r=cur.second;
    // 	            count=1;
    // 	            pq.push(r);
    // 	        }
    // 	    }
    // 	}}  //wrong ans;
    
    sort(arr,arr+n);
    sort(dep,dep+n);
    int i=0,j=0;
    int count=0;
    int ans=1;
    while(i<n-1 || j<n-1 ){
        if(arr[i]<=dep[j]){
            count++;
            cout<<" i "<< i <<" arr[i] "<< arr[i] <<" count "<<count<<"\n";
            ans=max(count, ans);
            i++;
        }
        else {
              cout<<" j "<< j <<" count "<<count<<"\n";
            count--;
            j++;
        }
    }
    return ans;
    
    	
    }
};


// { Driver Code Starts.
// Driver code
int main()
{
    int t;
    cin>>t;
    while(t--) 
    {
        int n;
        cin>>n;
        int arr[n];
        int dep[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];}
        for(int j=0;j<n;j++){
            cin>>dep[j];
        }
        Solution ob;
        cout <<ob.findPlatform(arr, dep, n)<<endl;
    } 
   return 0;
}  // } Driver Code Ends