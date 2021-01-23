//
//  util.cpp
//  lineInterPreter
//
//  Created by Yusuke Tomatsu on 2021/01/22.
//

#include <stdio.h>
#include "util.h"
#include <string>
#include <sstream>
#include <iostream>

bool compCharIgnCase(char c1, char c2){
    //tolowerは文字cを、ロケールに基いて小文字に変換する。
    return (tolower(c1)==tolower(c2));
}
bool compareIgnCase(string s1, string s2){
    if (s1.length()!= s2.length()) {
        return false;
    }
    return equal(s1.begin(), s1.end(), s2.begin(), s2.end());
}
string trim(string s)
{
    string ss = "";
    int len = s.length();
    for (int i=0; i<len; i++) {
        int c = s[i];
        if ( c == 0x20 || c == 0x8)
            continue;
        else
            ss += c;
    }
    return ss;
}
string trimStart(string s)
{
    string ss = "";
    int len = s.length();
    bool notspace = false;
    for (int i=0; i<len; i++) {
        int c = s[i];
        if ( !notspace && (c == 0x20 || c == 0x8))
            continue;
        else {
            ss += c;
            notspace = true;
        }
    }
    return ss;
}
int isNumberString(string ss)
{
    string s = trim(ss);
    char c = s[0];
    if ( c != '.' &&  c != '-' && !isdigit(c))
        return 0;
    if ( s.length() == 1 && !isdigit(c))
        return 0;
    int len = s.length();
    int nPeriod = 0;
    if ( c == '.')
        nPeriod = 1;
    if ( len > 1 ) {
        for (int i=1; i<len; i++) {
            char c = s[i];
            if ( c != '.' && !isdigit(c))
                return 0;
            if ( c == '.')
                if (++nPeriod > 1)
                    return 0;
        }
        return 1;
    }
    return 1;
}

void syntaxError()
{
    cerr << "シンタックスエラー" << endl;
}

bool isOparator(char c){
    if (c == '-' || c == '+'){
        return true;
    }
    if (c == '*' || c == '/'){
        return true;
    }
    if (c == '='){
        return true;
    }
    return false;
}

bool isParen(char c){
    if (c == '(' || c == ')'){
        return true;
    }
    return false;
}
