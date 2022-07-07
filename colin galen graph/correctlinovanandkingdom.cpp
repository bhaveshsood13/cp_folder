#include<bits/stdc++.h>
using namespace std;
 
vector<int> v[200005];
int s[200005];
 
int dfs(int x,int p,int d){
	int l=0;
	for(auto y:v[x]){
		if(y==p)continue;
		l+=dfs(y,x,d+1);
	}
	s[x]=d-l;
	return l+1;
}
 
int main(){
	int n,k,i,x,y;
	long long a=0;
	for(scanf("%d%d",&n,&k),i=1;i<n;i++){
		scanf("%d%d",&x,&y);
		v[x].push_back(y),v[y].push_back(x);
	}
	dfs(1,0,0);
	sort(s+1,s+n+1);
	for(i=0;i<k;i++)
	{a+=s[n-i];
	}
	cout<<"\n";
	printf("%lld\n",a);
	return 0;
}