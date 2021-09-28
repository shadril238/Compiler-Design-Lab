/*
	Midterm Lab Task-2
	Name: Shifat, Shadril Hassan
	ID: 20-42451-1
	Course Name: Compiler Design[A]
*/	

#include<iostream>
#include<string>

using namespace std;

bool isValidKey(string s){
	if( s=="asm" || s=="double" || s=="new" || s=="switch" || s=="auto" || s=="else" || s=="operator" || s=="template" || s=="break" || s=="enum" 
		|| s=="private" || s=="this" || s=="case" || s=="extern" || s=="protected" || s=="throw" || s=="catch" || s=="float" || s=="public" || s=="try" 
		|| s=="char" || s=="for" || s=="register" || s=="typedef" || s=="class" || s=="friend" || s=="return" || s=="union" || s=="const" || s=="goto" 
		|| s=="short" || s=="unsigned" || s=="continue" || s=="if" || s=="signed" || s=="virtual" || s=="default" || s=="inline" || s=="sizedof" || s=="void" 
		|| s=="delete" || s=="int" || s=="static" || s=="volatile" || s=="do" || s=="long" || s=="struct" || s=="while" ){
			return true;
		}
	return false;
}

int main(){
	
	string keyWord;
	for(int i=0;i<6;i++){
		cout<<"Enter keyword "<<i+1<<" : ";
		cin>>keyWord;
		if(isValidKey(keyWord)){
			cout<<keyWord<<" is a Valid keyword."<<endl;
		}
		else{
			cout<<keyWord<<" is an Invalid keyword."<<endl;
		}
		cout<<endl;
	}
	
	
	return 0;
}
