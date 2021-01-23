//
//  main.cpp
//  lineInterPreter
//
//  Created by Yusuke Tomatsu on 2021/01/22.
//

#include "util.h"
#include "gettoken.h"

Token prevTok;

int main(int argc, char *argv[]){
    string s;
    Token *tok = new Token();
    bool disptoken = true;
    while (true) {
        char buff[256];
        cout << "->";
        cin.getline(buff, 256);
        s = trim(string(buff));
        if (s.length() == 0) {
            continue;
        }
        //文字列がquitであればループを抜ける
        if (compareIgnCase(s, "quit")){
            break;
        }
        prevTok = Token(Start);
        //最初の文字列をトークンに切り分ける
        tok = getToken( s );
        while (tok != NULL) {
            if (disptoken)
                tok -> printToken();
            prevTok = *tok;
            tok = getToken( "" );
        }
    }
    return 0;
}
