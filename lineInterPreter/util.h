//
//  util.h
//  lineInterPreter
//
//  Created by Yusuke Tomatsu on 2021/01/22.
//

#ifndef util_h
#define util_h
#include <stack>//stackのため
#include <cmath>//atof()のため
#include <cstdlib>//atof()のため
using namespace std;

//プロトタイプ宣言
bool compCharIgnCase(char c1, char c2);
bool compareIgnCase(string s1, string s2);
string trim(string s);
string trimStart(string s);
int isNumberString(string ss);
void syntaxError();
bool isOparator(char c);
bool isParen(char c);
#endif /* util_h */
