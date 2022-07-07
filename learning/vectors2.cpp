#include<iostream>
#include<vector>

using namespace std;
 
int main(){
	vector<int> v{15,5,6,23,4};
	v.push_back(14);
	v.push_back(164);
	
	v.pop_back();
	v.insert(v.begin()+3,100);	
	for(int i : v){
	cout<<i<<",";
	}cout<<endl;
	
	// to preserve time in changing size of underlying array we use reserve
	v.reserve(100000);
	
	
	v.insert(v.begin()+2,2,-111);
	// to erase a range
	v.erase(v.begin());
	v.erase(v.begin()+4,v.end()-1);
	
	// we can resize the vector by
		v.resize(12);
	for(int i : v){
	cout<<i<<",";
	}
	
		
	
	
	//to clear ( size becomes 0 but capacity reamains same )
	v.clear();
	// to empty
	v.empty();
}
