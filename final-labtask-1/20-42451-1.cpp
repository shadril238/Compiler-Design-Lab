/*
	Final Term Lab Task-1
	Name: Shifat, Shadril Hassan
	ID: 20-42451-1
	Course Name: Compiler Design[A]
*/

#include<iostream>
#include<fstream>

using namespace std;

void readFile(string filename, string arr[], int n){
	fstream file;
	string word;
	file.open(filename);
	
	int i=0;
	while(file>>word){
		arr[i]=word;
		i++;
	}
	file.close();
}

void inputWords(string arr[], int n){
	string word;
	for(int i=0;i<n;i++){
		cout<<"Enter a word : ";
		cin>>word;
		arr[i]=word;
	}
}

bool checkWord(string word, string arr[], int n){
	for(int i=0;i<n;i++)
		if(word==arr[i])return 1;
	return 0;
}

int main(){
	string inp[6];
	string keywords[50];
	string filename="inp_20-42451-1.txt";
	
	readFile(filename,keywords,50);
	inputWords(inp,6); //taking 6 inputs from user
	for(int i=0;i<6;i++){
		if(checkWord(inp[i],keywords,50)){
			cout<<inp[i]<<" is a keyword."<<endl;
		}
		else{
			cout<<inp[i]<<" is not a keyword."<<endl;
		}
	}
}
