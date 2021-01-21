//
//  main.cpp
//  interPractice
//
//  Created by Yusuke Tomatsu on 2021/01/19.
//

#include <iostream>
#include <stack>//stackのため
#include <cmath>//atof()のため
#include <cstdlib>//atof()のため
#include <cctype>//isDigit()のため
#include "util.h"
#include "main.h"
using namespace std;
//スタック（グローバル）
stack<Token> stck;

int main(int argc, char *argv[]){
    Token top, top_1;
    string s;
    double a,b;
    //ユーザーの入力を受け取って出力するループ
    while (true) {
        cout << "->";
        cin >> s;
        //文字列がquitであればループを抜ける
        if (compareIgnCase(s, "quit")){
            break;
        }
        if (compareIgnCase(s, "printstack")) {
            printstack(stck);
            continue;
        }
        char c = s[0];
        //演算子とみなす
        if (s.size() == 1 && !isdigit(int(c))) {
            switch (c) {
                case '+':
                    stck.push(Token(Plus));
                    break;
                case '-':
                    stck.push(Token(Minus));
                    break;
                    
                case '*':
                    stck.push(Token(Mult));
                    break;
                case '/':
                    stck.push(Token(Divide));
                    break;
                case '(':
                    stck.push(Token(LParen));
                    break;
                case ')':
                    processRparen(stck);
                    break;
                default:
                    syntaxError();
                    break;
            }
            continue;
        }
        //値が入力されたか調べる
        if (isNumberString(s)) {
            //スタックの中身は2個未満の場合、値をスタックにプッシュする
            if (stck.size() < 2) {
                stck.push(Token(atof(s.c_str())));
            }else{
                //スタックの２つの要素を取り出す
                GetTop2Elem(stck, &top, &top_1);
                tokenType tt = top.getType();
                if (tt > Value && tt < LParen) {
                    tt = top_1.getType();
                    if (tt == Value) {
                        a = atof(s.c_str());
                        b = top_1.getValue();
                        switch (top.getType()) {
                            case Plus:
                                cout << a + b << endl;
                                stck.push(Token(a + b));
                                break;
                            case Minus:
                                cout << b - a << endl;
                                stck.push(Token(b - a));
                                break;
                            case Mult:
                                cout << a * b << endl;
                                stck.push(Token(a * b ));
                                break;
                            case Divide:
                                cout << b / a << endl;
                                stck.push(Token(b / a));
                                break;
                            default:
                                syntaxError();
                                break;
                        }
                    }
                }
                if (tt == LParen) {
                    stck.push(top_1);
                    stck.push(top);
                    stck.push(Token(atof(s.c_str())));
                }
            }
        }else{
            syntaxError();
        }
    }
    return 0;
}
//右括弧)の処理
int processRparen(stack<Token> &stck){
    int n = stck.size();
    if (n < 4) {
        double v = stck.top().getValue();
        cout << v << endl;
        for (int i = 0; i < n; i++) {
            stck.pop();
        }
        stck.push(Token(v));
        return 0;
    }
    //スタックの４つの要素を取り出す
    Token top, top_1, top_2, top_3;
    GetTop2Elem(stck, &top, &top_1);
    GetTop2Elem(stck, &top_2, &top_3);
    double a = top.getValue();
    double b = top_3.getValue();
    tokenType tt = top_2.getType();
    switch (tt) {
        case Plus:
            cout << a + b << endl;
            stck.push(Token(a + b));
            break;
        case Minus:
            cout << b - a << endl;
            stck.push(Token(b - a));
            break;
        case Mult:
            cout << a * b << endl;
            stck.push(Token(a * b ));
            break;
        case Divide:
            cout << b / a << endl;
            stck.push(Token(b / a));
            break;
        default:
            syntaxError();
            break;
    }
    return 0;
}


int GetTop2Elem(stack<Token> &stck, Token *a, Token *b){
    if (stck.size() < 2) {
        cout << "オペランドが足りません" << endl;
        return -1;
    }
    *a = stck.top();
    stck.pop();
    *b = stck.top();
    stck.pop();
    return 0;
}

string tokenTypeName[]= {"Value","Plus","Minus","Mult","Divide"};

void printstack(stack<Token> stck){
    stack<Token> tmpstck;
    tmpstck = stck;
    cout << "--- stack top ---" << endl;
    int n = (int)tmpstck.size();
    for(int i = 0;i<n;i++){
        Token t = tmpstck.top();
        cout << tokenTypeName[t.getType()] << ":" << t.getValue() << endl;
        tmpstck.pop();
    }
    cout << "--- stack bottom ---" << endl;
}
string trim(string ss)
{
  ss.erase(std::remove(ss.begin(),ss.end(),' '),ss.end());
  return ss;
}


int isNumberString(string ss){
    string s = trim(ss);
    //最初の文字は-か.か数字
    char c = s[0];
    if (c != '.' && c != '-' && !isdigit(c)) {
        //先頭が上記以外ならエラーを返す
        return 0;
    }
    //長さが１で数字でなければエラー
    if (s.length()== 1 && !isdigit(c) ) {
        return 0;
    }
    //長さが１以上で2文字以降に数字文字か.以外があればエラー
    int len = s.length();
    int nPeriod = 0; //.の数
    if (c == '.') {
        nPeriod = 1;
    }
    if (len > 1){
        for (int i = 0; i < len; i++) {
            char c = s[i];
            if (c != '.' && !isdigit(c)) {
                return 0;
            }
            //.が2個以上ならエラー
            if (c == '.') {
                if (++nPeriod > 1) {
                    return 0;
                }
            }
        }
        return 1;
    }
    return 1;
}

void syntaxError(){
    cerr << "シンタックスエラー" << endl;
}

