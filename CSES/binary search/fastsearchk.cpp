#include <bits/stdc++.h>
using namespace std;

int closest_to_right(vector<int> &v, int x){
	
	int l = -1; // v[l] < x
	int r = v.size(); //v[r] >= x 
	while(r>l +1){
		int m = (l+r)/2;
		if(v[m] < x){
			l = m;
		}
		else{
			 r = m;
		}
		
	}
	return r+1;
}
int closest_to_left(vector<int> &v, int x){
	
	
	int l = -1; // v[l] <= x
	int r = v.size(); //v[r] > x 
	while(r>l +1){
		int m = (l+r)/2;
		if(v[m] <= x){
			l = m;
		}
		else{
			 r = m;
		}
		
	}
	return l+1;
}

int main() {
	int n,k;
	cin>>n;
	vector<int> v(n);
	for(int i=0;i<n;i++){
		cin>>v[i];// cout<<v[i]<<" "<<'\n';
	}
	sort(v.begin(),v.end());
//	for(int i=0;i<n;i++) cout<<v[i]<<" "<<'\n';
	cin>>k;
	while(k--){
		int l,r;
		cin>>l>>r;
        int ri=closest_to_left(v, r);
        int li=closest_to_right(v, l);
		 cout<<ri-li+1<<" ";

	}
	cout<<'\n';
	

	return 0;
}