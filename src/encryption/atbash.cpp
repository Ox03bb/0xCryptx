#include "encryption/atbash.h"

#include <string>
#include <map>
#include <iostream>

using namespace std;


string atbash::encrypt(string raw){
	string result = "";
	for(char c : raw){
		result += miror(c);
	}
	return result;
}

string atbash::decrypt(string raw){
	return encrypt(raw);
}


char atbash::miror(char c){
	if(c >= 'a' && c <= 'z'){
		return char('z' - (c - 'a'));
	} else if(c >= 'A' && c <= 'Z'){
		return char('Z' - (c - 'A'));
	} else {
		return c;
	}
}