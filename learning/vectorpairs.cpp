#include<iostream>
#include<vector>
#include<string>

using namespace std;
 
int main(){
	
	pair<int , char> p1;
	p1.first=-1;
	p1.second='!';
	
	pair<int ,char > p3(p1);
	cout<<p3.first<<" >> "<< p3.second<<endl;
	
	pair<int,string> p4=make_pair(23,"aaltu");
	cout<<p4.first<<" >> "<< p4.second<<endl;

	
	
	pair<pair<int,int>,string> pcarxy=make_pair(make_pair(1,1),"audi");
	
	cout<<pcarxy.first.first<<" >> "<< pcarxy.second;
	
	//Vector pairs
	
	vector<pair<int ,int >>v;
	for(int i =0 ;i<7;i++){
	int x,y;
	cin>>x>>y;
	v.push_back(make_pair(x,y));
	}
	
	
	
}
