#include<iostream>
#include<cstring>
using namespace std;

int main(){
	
	char s[100]="today is a rainy day";
	// tokens array s based on delimitter string
	char *ptr = strtok(s," ");
	cout<<ptr<<endl;
	// to get the next token pass NULL in strtok
	ptr=strtok(NULL," ");
	cout<<ptr<<endl;
	
	
	//to cover all
	while(ptr!=NULL){
		ptr=strtok(NULL," ");
		cout<<ptr<<endl;
	}
	
	
	
	
	
	
	
	
	
	
	
	}
