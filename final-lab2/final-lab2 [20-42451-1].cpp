/*
	Shifat, Shadril Hassan [20-42451-1]
	Compiler Design Lab
*/
#include<iostream>
#include<string.h>
#include<string>
using namespace std;

string ex,str="";

int main(){
    cout<<"Input regular expression : ";
    cin>>ex;
    string s1="",s2="";
    int esz=ex.size();
    bool f=1;
    
    //union
    if(ex[1]=='U' and ex[2]!='*' and ex[2]!='+' and ex[2]!='U'){
    	cout<<"Enter a string to verify [$ for empty string]: ";
    	cin>>str;
    	int sz=str.size();
    	s1+=ex[0];
    	s2+=ex[2];
    	if(str==s1 or str==s2)cout<<"status: valid"<<endl;
    	else cout<<"status: invalid"<<endl;
	}
	//star
	else if(ex[1]=='*'){
		if(esz==2){
			cout<<"Enter a string to verify [$ for empty string]: ";
	    	cin>>str;
	    	int sz=str.size();
			if(str[0]=='$')cout<<"status: valid"<<endl;
			else{
				for(int i=0;i<sz;i++){
					if(str[i]!=ex[0]){
						f=0;
						break;
					}
				}
				if(f)cout<<"status: valid"<<endl;
				else cout<<"status: invalid"<<endl;
			}
		}
		else if(esz>2 and ex[2]!='U' and ex[2]!='+' and ex[2]!='*'){
			cout<<"Enter a string to verify [$ for empty string]: ";
	    	cin>>str;
	    	int sz=str.size();
			sz--;
			if(sz==0 and str[0]==ex[2])cout<<"status: valid"<<endl;
			else{
				if(str[sz]!=ex[2])f=0;
				if(f){
					for(int i=0;i<sz;i++){
						if(str[i]!=ex[0]){
							f=0;
							break;
						}
					}
				}
				if(f)cout<<"status: valid"<<endl;
				else cout<<"status: invalid"<<endl;
			}
		}
		else cout<<"status: invalid expression"<<endl;
	}
	//star 
	else if(esz==3 and ex[2]=='*' and ex[1]!='U' and ex[1]!='+' and ex[1]!='*'){
		cout<<"Enter a string to verify [$ for empty string]: ";
    	cin>>str;
    	int sz=str.size();
    	
		if(str[0]!=ex[0])f=0;
		if(f){
			for(int i=1;i<sz;i++){
				if(str[i]!=ex[1]){
					f=0;
					break;
				}
			}
		}
		if(f)cout<<"status: valid"<<endl;
		else cout<<"status: invalid"<<endl;
	}
	//plus
	else if(ex[1]=='+'){
		
		if(esz==2){
			cout<<"Enter a string to verify [$ for empty string]: ";
    		cin>>str;
    		int sz=str.size();
			for(int i=0;i<sz;i++){
				if(str[i]!=ex[0]){
					f=0;
					break;
				}
			}
			if(f)cout<<"status: valid"<<endl;
			else cout<<"status: invalid"<<endl;
		}
		else if(esz>2 and ex[2]!='*' and ex[2]!='U' and ex[2]!='+'){
			cout<<"Enter a string to verify [$ for empty string]: ";
	    	cin>>str;
	    	int sz=str.size();
			for(int i=0;i<sz-1;i++){
				if(str[i]!=ex[0]){
					f=0;
					break;
				}
			}
			if(f and str[sz-1]==ex[2])cout<<"status: valid"<<endl;
			else cout<<"status: invalid"<<endl;
		}
		else cout<<"status: invalid expression"<<endl;
	}
	//plus
	else if(esz==3 and ex[2]=='+' and ex[1]!='*' and ex[1]!='U' and ex[1]!='+'){
		cout<<"Enter a string to verify [$ for empty string]: ";
    	cin>>str;
    	int sz=str.size();
    	
		if(ex[0]!=str[0] or sz==1)f=0;
		if(f){
			for(int i=1;i<sz;i++){
				if(str[i]!=ex[1]){
					f=0;
					break;
				}
			}
		}
		if(f)cout<<"status: valid"<<endl;
		else cout<<"status: invalid"<<endl;
	}
	else if(ex[0]=='U' or ex[0]=='*' or ex[0]=='+')cout<<"status: invalid expression"<<endl;
	else cout<<"status: invalid expression"<<endl;
	
	return 0;
}
