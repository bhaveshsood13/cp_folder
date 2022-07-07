#include<iostream>
#include<string>
using namespace std;

int main(){
	string s0;
	string s1="hello0";
	string s2(s1);
	string s3=s1+s2;
	
	cout<<s0<<endl;
	cout<<s1<<endl;
	cout<<s2<<endl;
	cout<<s3<<endl;
	cout<<s0.length()<<endl;
	cout<<s2.length()<<endl;
	if(s0.empty()) cout<<"empty string"<<endl;
	s0.append("I love c++");
	cout<<s0<<endl;
	
	if(s2==s1)cout<<"same string "<<endl;
	
	s2="mango";
	s3="apple";
	if(s3<s2)cout<<s3<<" is lexicographically smaller "<<s2;
	
	cout<<endl;
	for(unsigned int i=0;i<s2.length();i++){
	cout<<i<<" "<<s2[i]<<endl;
	}
	
	// find substrings
	string s="i love apple juice ";
	int id=s.find("apple");
	cout<<s<<endl<<id<<endl;
	
	// erase function
	s.erase(id,6);
	cout<<s<<endl;
	
	
	//Iterators
	for(auto it = s.begin();it!=s.end();it++){
	cout<<(*it)<<":: ";
	}
	cout<<endl;
	
	//For each loop;
	for(char c:s) cout<<c<<",";
	// instead of defining the type we can use auto
	cout<<endl;
	char ar[6]="HEllo";
	for(auto c: ar) cout<<c<<"?";
	
	}
