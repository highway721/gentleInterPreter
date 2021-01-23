//
//  gettoken.h
//  lineInterPreter
//
//  Created by Yusuke Tomatsu on 2021/01/22.
//

#ifndef gettoken_h
#define gettoken_h
#include <iostream>
#include <algorithm>
#include <string>
#include <cctype>//isDigit()のため
using namespace std;
//列挙型を使う理由としては演算子や値を数値として識別できるようにするため
enum tokenType {Value,Plus,Minus,Mult,Divide,Assign,LParen,RParen,Symbol, Invalid,Start};
typedef tokenType TokenType;

class Token{
    string symbol;
    double value;
    TokenType type;
public:
    //コンストラクタ
    Token(){};
    Token(double v, TokenType t){
        value = v;
        type =t;
    };
    Token(double v){
        value = v;
        type = Value;
    };
    Token(string s){
        symbol = s;
        type = Symbol;
    };
    Token(TokenType t){
        value = 0.0;
        type = t;
    };
    string getSymbol(){return symbol;};
    double getValue(){return value;};
    TokenType getType(){return type;};
    bool isStartToken();
    void printToken();
};

Token *getToken(string s);
bool isStartToken(TokenType tt);

extern Token prevTok;

#endif /* gettoken_h */
