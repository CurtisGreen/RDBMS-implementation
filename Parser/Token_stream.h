#ifndef TOKEN_STREAM_H_
#define TOKEN_STREAM_H_

#include <iostream>
#include <string>

using namespace std;

struct Token 
{
  char kind;
  char value;
  double num;
  Token(char ch) : kind(ch), value('0'), num(0){}	//This is for symbols
  Token(char ch, char val) : kind(ch), value(val), num(0){} //This is for characters
  Token(char ch, double val) : kind(ch), value('0'), num(val) {} //This is for conditionals for floating point numbers
};

class Token_stream 
{
  string buffer;
  
public:

  Token_stream() : buffer("") {}
  
void putback(Token t)
  {
    buffer.push_back(t.value);
  }
  
Token get() 
  {
    cout<<"\nIn get()"<<endl;
	
    char ch;
    cin >> ch;
    switch(ch) 
	{
    case '(': case ')': case '+': case '-': 
    case '*': case '/': case ';': case ' ':
    return Token(ch);	//look up previous item as a command/expression, kind (0) = symbols
    case '.':
    case '0': case '1': case '2': case '3': case '4': 
    case '5': case '6': case '7': case '8': case '9': 
	{
      cin.putback(ch);  // put digit back into the input stream
      double val;
      cin >> val;       // let C++ do the work of reading a floating-point num
      return Token('8',val);	//kind (8) = numbers
    }
	case 'a': case 'b': case 'c': case 'd': case 'e': 
    case 'f': case 'g': case 'h': case 'i': case 'j':
	case 'k': case 'l': case 'm': case 'n': case 'o': 
    case 'p': case 'q': case 'r': case 's': case 't':
	case 'u': case 'v': case 'w': case 'x': case 'y': 
    case 'z':
	{
	   return Token('a',ch);	//kind (a) = lowercase letters
	}
	case 'A': case 'B': case 'C': case 'D': case 'E': 
    case 'F': case 'G': case 'H': case 'I': case 'J':
	case 'K': case 'L': case 'M': case 'N': case 'O': 
    case 'P': case 'Q': case 'R': case 'S': case 'T':
	case 'U': case 'V': case 'W': case 'X': case 'Y': 
    case 'Z': 
	{
		return Token('A',ch);	//kind (A) = uppercase letters
	}
    //default : error("Bad token");


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