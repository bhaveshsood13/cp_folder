#include<bits/stdc++.h>
using namespace std;
//#define int long long
inline int read()
{
	int sum=0,nega=1;char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')nega=-1;ch=getchar();}
	while(ch<='9'&&ch>='0')sum=sum*10+ch-'0',ch=getchar();
	return sum*nega;
}
const int n=2e5;
int main()
{
	srand(3333333);
	//freopen("hack.in","w",stdout);
	cout<<1<<endl;
	cout<<n<<endl;
	for(int i=1;i<=n/2;i++)printf("1 ");
	for(int i=n/2+1;i<=n;i++)printf("%d%c",i-n/2+1," \n"[i==n]);
	for(int i=1;i<=n;i++)printf("%d%c",rand()%10000000+1," \n"[i==n]);
	return 0;
}
