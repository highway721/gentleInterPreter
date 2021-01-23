//
//  gettoken.cpp
//  lineInterPreter
//
//  Created by Yusuke Tomatsu on 2021/01/23.
//

#include <stdio.h>
#include "gettoken.h"
#include "util.h"
using namespace std;

//トークンに切り分ける
Token *getToken(string s)
{
    static string srcstr;
    string tokenstr;

    //文字列の前の空白を取り除く
    string ss = trimStart(s);
    srcstr += ss;
    if (srcstr.length() == 0)
        return NULL;

    int pos = 0;  //現在の文字位置を保存する
    char c = srcstr[pos++];  //先頭の文字
    char c2 = 0;             //先頭の次の文字
    if (srcstr.length()>2)
        c2 = srcstr[pos];    //先頭の次の文字
    if ( c == '-' && !(prevTok.isStartToken()) ) {
        srcstr = srcstr.substr(1, srcstr.length()-1);
        return new Token ( Minus ) ;
    }
    if ( c == '+' && !(prevTok.isStartToken()) ) {
        srcstr = srcstr.substr(1, srcstr.length()-1);
        return new Token ( Plus ) ;
    }
    if ( c == '/') {
        srcstr = srcstr.substr(1, srcstr.length()-1);
        return new Token ( Divide ) ;
    }
    if ( c == '*') {
        srcstr = srcstr.substr(1, srcstr.length()-1);
        return new Token ( Mult ) ;
    }
    if ( c == '=') {
        srcstr = srcstr.substr(1, srcstr.length()-1);
        return new Token ( Assign ) ;
    }
    if ( c == ')') {
        srcstr = srcstr.substr(1, srcstr.length()-1);
        return new Token ( RParen ) ;
    }
    if ( c == '(') {
        srcstr = srcstr.substr(1, srcstr.length()-1);
        return new Token ( LParen ) ;
    }
    if ( c == '-' ||  c == '+' ||  c == '.' || isdigit(c) ) { 
   
        tokenstr = c;
        while (true) {
            if (srcstr.length() == pos) {  // âêÕï∂éöóÒÇÃèIÇÌÇË
                srcstr = "";
                return new Token( atof(tokenstr.c_str()) );
            }
            c = srcstr[pos++];
            if ( c == '.' || isdigit(c) )
                tokenstr += c;
            else {
                --pos;
                int len = srcstr.length() - pos;
                srcstr = srcstr.substr(pos, len);
                return new Token( atof(tokenstr.c_str()) );
            }
        }
    }
    //名前
    tokenstr = c;
    while (true) {
        if (srcstr.length() == pos) {  //解析文字の終わり
            srcstr = "";
            return new Token( tokenstr );
        }
        c = srcstr[pos++];
        if ( c == ' ' || isOparator(c) || isParen(c)) {
            --pos;
            int len = srcstr.length() - pos;
            srcstr = srcstr.substr(pos, len);
            return new Token( tokenstr );
        } else {
            tokenstr += c;
        }
    }
    return new Token(Invalid);
}

bool Token::isStartToken()
{
    if (type == Start)
        return true;
    if (type == LParen)
        return true;
    if (type == Assign)
        return true;
    return false;
}

string TokenTypeName[]={
    "Value", "+(Plus)","-(Minus)",
    "*(Mult)", "/(Divide)", "=(Assign)",
    "LParen", "RParen", "Symbol"
};

void Token::printToken()
{
    if (type == Value) {
        cout << "Value:" << value << endl;
        return;
    }
    if (type == Symbol) {
        cout << "Symbol:" << symbol << endl;
        return;
    }
    if (type == LParen) {
        cout << "Paren:(" << endl;
        return;
    }
    if (type == RParen) {
        cout << "Paren:)" << endl;
        return;
    }
    cout << "Oparator:" << TokenTypeName[type] << endl;
}
