#include "encryption/caesar.h"

#include <algorithm>
#include <iostream>

using namespace std;


string caesar::encrypt(string raw, int shift){
	double lnt = raw.length();
	string enc;
	for (double cnt = 0 ; cnt <= lnt ; cnt ++){
		enc += caesar::shift(raw[cnt], shift);
	}
	return enc;
}

string caesar::decrypt(string raw, int shift){
	double lnt = raw.length();
	string dec;
	for (double cnt = 0 ; cnt <= lnt ; cnt ++){
		dec += caesar::shift(raw[cnt], -shift);
	}
	return dec;
}


char caesar::overlap(char init ,int val , char start ,char end){
	char temp = init + val;

	if (temp >= start && temp <= end){
		return temp;
	}

	if ( val >= 0){
		return temp + start - end;
	}

	return temp + end - start;
			
}

char caesar::shift(char c, int val){
	if (c >= 97 && c <= 122 ){
		return overlap(c , val , 97 , 122);
	}else if( c >= 65 && c <= 90 ){
		return overlap(c , val , 65 , 90);
	}
	return c;
}