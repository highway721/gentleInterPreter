//
//  main.cpp
//  interPractice
//
//  Created by Yusuke Tomatsu on 2021/01/19.
//

#include <iostream>
#include "util.h"


int main(int argc, char *argv[]){
    string s;
    //ユーザーの入力を受け取って出力するループ
    while (true) {
        cout << "->";
        cin >> s;
        //文字列がquitであればループを抜ける
        if (compareIgnCase(s, "quit")){
            break;
        }
        cout << s << endl;
    }
    return 0;
}
