/*
	Midterm Lab Task-3
	Name: Shifat, Shadril Hassan
	ID: 20-42451-1
	Course Name: Compiler Design[A]
*/

#include <iostream>
#include <string>
//#include <sstream>
#include <cstring> // To import string functions
#include<vector>
#include<map>
#include <boost/algorithm/string.hpp> // for detail: https://www.boost.org/

using namespace std;


map<string,int> cnt; // declaring a map to keep the track of identifier
//Structure for tokens
struct token
{
    string token_type; //identifier, operator/symbol, digits/constant
    //int position;
    string value; // to store symbols/constant/identifiers
};

// Symbols
const string symbols = "=+-*/";
//c_str() converts the string into character array
const char *symbols_arr = symbols.c_str(); //Take character pointer to convert the string into character

// Output structure array
struct token out_tokens[100];
int out_tokens_count = 0;

// Function to check if a character is a number
bool is_constant(string s)
{
    return !s.empty() && std::all_of(s.begin(), s.end(), ::isdigit);
}

// Function to check if a character is a symbol
//symbol=operator
void parse_symbol(string input)
{
    // Parse for symbols
    int symbol_pos = 1; //symbol will be present at position 1 //a=b+c*10
    for (int i = 0; i < input.length(); i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (input[i] == symbols_arr[j])
            {
                out_tokens[symbol_pos].token_type = "symbol";
                //out_tokens[symbol_pos].position = i; //stores array index where symbol is found
                out_tokens[symbol_pos].value = symbols_arr[j];

                symbol_pos = symbol_pos + 2; //a=b+c-d
                out_tokens_count++;
            }

        }
    }
}

// Function to print output
void print_result(){
    // Print out_tokens
    int id_counter = 1; //id1, id2...
    for (int i = 0; i < out_tokens_count; i++)
    {
        if (out_tokens[i].token_type == "identifier")
        {
            if(cnt[out_tokens[i].value]==0){  //my modified code
            	cout << "(id" << id_counter++ << ")";
            	cnt[out_tokens[i].value]++;
			}
			else{
				cout << "(id" << cnt[out_tokens[i].value]<< ")";
			}
        }
        else if (out_tokens[i].token_type == "constant")
        {
            cout << "(" << out_tokens[i].value << ")";
        }
        else if (out_tokens[i].token_type == "symbol")
        {
            cout << "(" << out_tokens[i].value << ")";
        }
    }
    cout << endl;
}


int main()
{
    // Input
    string input; //a=b+c*20

    // Ask for input
    cout << "Enter a string: ";
    // Get input
    getline(cin, input);

    ///my modified code
    int sz=input.size();

    if(input[sz-1]==';'){
            input.pop_back();
            sz=input.size();
    }

    if(input[sz-1]=='+' && input[sz-2]=='+'){ //a++
        input.pop_back();
        input.pop_back();
        input=input+"="+input+"+1";
    }
    else if(input[0]=='+' && input[1]=='+'){ //++a
        input.erase(input.begin());
        input.erase(input.begin());
        input=input+"="+input+"+1";
    }
    else if(input[sz-1]=='-' && input[sz-2]=='-'){ //a--
        input.pop_back();
        input.pop_back();
        input=input+"="+input+"-1";
    }
    else if(input[0]=='-' && input[1]=='-'){ //--a
        input.erase(input.begin());
        input.erase(input.begin());
        input=input+"="+input+"-1";
    }


    // Parse for symbols
    parse_symbol(input);

    // Tokenize input
    vector<string> tokens; //just like string tokens[5] but vector is dynamic

    //tokens is destination and should be a vector
    boost::split(tokens, input, boost::is_any_of(symbols));//boost is a namespace and split is a function in that namespace
    //for(auto u:tokens)cout<<u<<endl;
    // print tokens
    int non_symbol_pos = 0; //a=b+c;
    // cout << "Tokens: ";
    for (int i = 0; i < tokens.size(); i++)
    {
        //cout << tokens[i] << " ";
        if (is_constant(tokens[i])) //var1=var2+var3*50
        {
            // cout << "constant ";
            out_tokens[non_symbol_pos].token_type = "constant";
            //out_tokens[non_symbol_pos].position = non_symbol_pos;
            out_tokens[non_symbol_pos].value = tokens[i];
            non_symbol_pos = non_symbol_pos + 2;
            out_tokens_count++;
        }
        else
        {
            // cout << "identifier";
            out_tokens[non_symbol_pos].token_type = "identifier";
            //out_tokens[non_symbol_pos].position = non_symbol_pos;
            out_tokens[non_symbol_pos].value = tokens[i];
            non_symbol_pos = non_symbol_pos + 2;
            out_tokens_count++;
        }
    }

    // Print out_tokens
    print_result();
    return 0;
}
