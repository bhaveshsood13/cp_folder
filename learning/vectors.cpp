#include<iostream>

// DYANAMIC ARRAY IN THE END
#include<vector>
#include<string>
using namespace std;

int main(){
	//array of size 7 , initialised with random values
	
	int ar[7];
	for(int i : ar){
	cout<<i<<"|";
	}
	cout<<endl;
	//DIFFERENT WAYS OF INITIALISING
	//vector of size 9 initialised with 0
	vector<int> a(9);	
	
	//all initialised with -1;
	vector<int> bab(9,-1);
	for(int i =0;i<7;i++){
		cout<<bab[i]<<",";
		}cout<<endl;
		
	vector<int> baaab{1,12,4,5,45,4,534};
	
	for(int i =0;i<7;i++){
		cout<<baaab[i]<<",";
		}
		cout<<endl;
		
	vector<int> copybaaab(baaab.begin(),baaab.end());
	
	for(int i =0;i<7;i++){
		cout<<copybaaab[i]<<",";
		}
	cout<<endl;
	vector <string> strarr(10,"hi");
	for(string i: strarr){
	cout<<i<<".";
	}
	cout<<endl<<"Enter array of size n : ";
	
	//Taking input
	vector <int> v;
	int n ;
	cin>>n;
	for(int i =0;i<n;i++){
		int no;
		cin>>no;
		v.push_back(no);
	} 
	for( int i : v){
	cout<<i<<",";
		}
	cout<<"vsize "<<v.size()<<"\n"<<" vcapacity "<<v.capacity()<<endl<<" maxsize possible "<<v.max_size();
	
	
	
	
	
	
	
	
	
	
	}
