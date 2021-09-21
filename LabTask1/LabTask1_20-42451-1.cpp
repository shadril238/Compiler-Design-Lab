/*
	Midterm Lab Task-1
	Name: Shifat, Shadril Hassan
	ID: 20-42451-1
	Course Name: Compiler Design[A]
*/	
	
#include<iostream>
#include<cstring>
#include<stack>

using namespace std;

bool isOperator(char ch){
	if(ch=='+' || ch=='-' || ch=='*' ||  ch=='/' || ch=='^' || ch=='='){
		return true;
	}
	return false;
}

bool isNumber(char ch){
	if(ch>='0' && ch<='9'){
		return true;
	}
	return false;
}

int main(){
	string exp,temp="";
	stack<string> op1,op2;	
	cout<<"Input Expression: ";
	getline(cin,exp);
	cout<<"Output Expression: ";
	int sz=exp.size();
	for(int i=0;i<sz;i++){
		exp[i]=tolower(exp[i]);
		if(isOperator(exp[i])){
			if(temp!="") op1.push(temp);
			temp="";
			temp+=exp[i];
			if(temp!="") op1.push(temp);
			temp="";
		}
		else if(isspace(exp[i])){
			if(temp!="") op1.push(temp);
			temp="";
		}
		else{
			temp+=exp[i];
		}
	}
	if(temp!=""){
		op1.push(temp);
		temp="";
	}
	
	bool f=1;
	while(!op1.empty()){
		string top=op1.top();
		if(op2.empty()){
			if(isOperator(top[0])){
				cout<<"ERROR!"<<endl;
				f=0;
				break;
			}
			else{
				op2.push(top);
			}
		}
		else if(!isOperator(op2.top()[0])){
			if(!isOperator(top[0])){
				cout<<"ERROR!"<<endl;
				f=0;
				break;
			}
			else{
				op2.push(top);
			} 
		}
		else if(isOperator(op2.top()[0])){
			if(isOperator(top[0])){
				cout<<"ERROR!"<<endl;
				f=0;
				break;
			}
			else{
				op2.push(top);
			}
		}
		op1.pop();
	}
	if(isOperator(op2.top()[0]) && f==1){
		cout<<"ERROR!"<<endl;
		f=0;
	}
	if(f){
		string res="";
		int cnt=1;
		while(!op2.empty()){
			res+='(';
			string top=op2.top();
			if(!isNumber(top[0]) && !isOperator(top[0])){
				res+="id";
				res+=to_string(cnt);
				cnt++;
			}
			else{
				res+=top;
			}
			res+=") ";
			op2.pop();
		}
		cout<<res<<endl;
	}
	
	return 0;
}
