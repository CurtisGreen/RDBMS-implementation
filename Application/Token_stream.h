#ifndef TOKEN_STREAM_H_
#define TOKEN_STREAM_H_

#include <iostream>
#include <string>
#include <sstream>

using namespace std;

struct Token 
{
  char kind;
  char value;
  Token(char ch) : kind('0'), value(ch){}	//This is for symbols
  Token(char ch, char val) : kind(ch), value(val){} //This is for characters
};

class Token_stream 
{
public:
  string input;
  string buffer;
  int index;
  string output;
  


  Token_stream(string in) : buffer(""), input(in), index(0){}
  Token_stream() : buffer(""), input(""), index(0){}
  
void putback(Token t)
  {
    buffer.push_back(t.value);
  }
  
Token get() 
  {
	
    char ch;
	if (index < input.size()){
	
	ch = input[index];
	index++;
    //if (cin >> noskipws >> ch){
        //cout << "HERE" << endl;;
    switch(ch) 
	{
    case '(': case ')': case '+': case '-': case '\n': case '=': case '<': case '!':
    case '*': case '/': case ';': case ' ': case '.': case ',': case '>': case '&': case '|':{
	//cout << ch << "text"<< endl;
    return Token(ch);	//look up previous item as a command/expression, kind (0) = symbols
	}
    case '0': case '1': case '2': case '3': case '4': 
    case '5': case '6': case '7': case '8': case '9': 
	{
      return Token('8',ch);	//kind (8) = numbers
    }
	case 'a': case 'b': case 'c': case 'd': case 'e': 
    case 'f': case 'g': case 'h': case 'i': case 'j':
	case 'k': case 'l': case 'm': case 'n': case 'o': 
    case 'p': case 'q': case 'r': case 's': case 't':
	case 'u': case 'v': case 'w': case 'x': case 'y': 
    case 'z': case '_':
	{
	   return Token('a',ch);	//kind (a) = lowercase letters
	}
	case 'A': case 'B': case 'C': case 'D': case 'E': 
    case 'F': case 'G': case 'H': case 'I': case 'J':
	case 'K': case 'L': case 'M': case 'N': case 'O': 
    case 'P': case 'Q': case 'R': case 'S': case 'T':
	case 'U': case 'V': case 'W': case 'X': case 'Y': 
    case 'Z': case '"': 
	{
		return Token('A',ch);	//kind (A) = uppercase letters
	}
    default : cout<< "Bad token: "<< ch <<endl;


    }
	index++;
  }
  else{
	  //cout << "eof" << endl;
	  return Token('`','`');
  }
  }
  string out_buff()//returns buffer & clears it
  {	
      string temp = buffer;
      buffer = "";
      return temp;
    }
};

#endif
