//
//  main.h
//  interPractice
//
//  Created by Yusuke Tomatsu on 2021/01/21.
//

#ifndef main_h
#define main_h
#include <iostream>
#include <stack>//stackのため
#include <cmath>//atof()のため
#include <cstdlib>//atof()のため
#include <cctype>//isDigit()のため

//列挙型を使う理由としては演算子や値を数値として識別できるようにするため
enum tokenType{Value,Plus,Minus,Mult,Divide,LParen,Rparen};
typedef tokenType tokenType;

class Token{
    double value;
    tokenType type;
public:
    //コンストラクタ
    Token(){};
    Token(double v, tokenType t){
        value = v;
        type = t;
    };
    Token(double v){
        value = v;
        type = Value;
    };
    Token(tokenType t){
        value = 0.0;
        type = t;
    };
    //メンバー関数
    double getValue(){return value;};
    tokenType getType(){return type;};
};
//プロトタイプ宣言
int GetTop2Elem(stack<Token>&, Token* , Token*);
void printstack(stack<Token>);
int isNumberString(string);
void syntaxError();
int processRparen(stack<Token>&);


#endif /* main_h */
