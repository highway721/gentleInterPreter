//
//  util.cpp
//  interPractice
//
//  Created by Yusuke Tomatsu on 2021/01/19.
//

#include <stdio.h>
#include "util.h"


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
