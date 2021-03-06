//
// Created by QiboLee on 2016/11/5 0005.
//

#ifndef LEETCODE_NO6_H
#define LEETCODE_NO6_H

#include "head.h"

class Solution {
public:
    std::string convert(std::string s, int numRows) {
        if (numRows == 1 || s.size() <= numRows) {
            return s;
        }
        std::string ret;
        ret.reserve(s.size());
        int step = (numRows << 1) - 2;
        for (int i = 0; i < s.size(); i += step) {
            ret.push_back(s[i]);
        }
        for (int i = 1; i < numRows - 1; ++i) {
            bool toggle = true;
            int p2 = i << 1;
            int p1 = step - p2;
            for (int j = i; j < s.size();) {
                ret.push_back(s[j]);
                if (toggle) {
                    j += p1;
                } else {
                    j += p2;
                }
                toggle = !toggle;
            }
        }
        for (int i = numRows - 1; i < s.size(); i += step) {
            ret.push_back(s[i]);
        }
        return ret;

    }
};

#endif //LEETCODE_NO6_H
