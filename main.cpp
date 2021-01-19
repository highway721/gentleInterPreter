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
#include "util.h"

using namespace std;
//プロトタイプ宣言
int GetTop2Elem(stack<double> &stack, double *a, double *b);
void printstack(stack<double>);


int main(int argc, char *argv[]){
    stack<double> stck;
    double a,b;
    string s;
    
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
        switch (c) {
            case '+':
                if (GetTop2Elem(stck, &a, &b)) {
                    break;
                }
                cout << a + b << endl;
                stck.push(a + b);
                break;
            case '-':
                //負の値が入力されたか調べる
                if (s.size() != 0) {
                    //値をスタックにプッシュする
                    stck.push(atof(s.c_str()));
                    break;
                }
                if (GetTop2Elem(stck, &a, &b)) {
                    break;
                }
                cout << b - a << endl;
                stck.push(b - a);
                break;
            case '*':
                if (GetTop2Elem(stck, &a, &b)) {
                    break;
                }
                cout << a * b << endl;
                stck.push(a * b);
                break;
            case '/':
                if (GetTop2Elem(stck, &a, &b)) {
                    break;
                }
                cout << a * b << endl;
                stck.push(a * b);
                break;
            default:
                //入力された値は数値とみなしてスタックに値をプッシュする
                stck.push(atof(s.c_str()));
                break;
        }
    }
}
int GetTop2Elem(stack<double> &stck, double *a, double *b){
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

void printstack(stack<double> stck){
    stack<double> tmpstck;
    tmpstck = stck;
    cout << "--- stack top ---" << endl;
    int n = (int)tmpstck.size();
    for(int i = 0;i<n;i++){
        cout << tmpstck.top() << endl;
        tmpstck.pop();
    }
    cout << "--- stack bottom ---" << endl;
}


