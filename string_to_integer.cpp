// https://leetcode.com/problems/string-to-integer-atoi/#/description
//
class Solution {
public:
    int myAtoi(string str) {
        int64_t result = 0;
        bool hasFlag = false;
        int flag = 1;
        string::iterator it = str.begin();
        
        while (isspace(*it))
            ++it;
        
        for (; it != str.end(); ++it) {
            if (*it == '-') {
                if (hasFlag)
                    return 0;
                else {
                    flag = -1;
                    hasFlag = true;
                }
            }
            else if (*it == '+') {
                if (hasFlag)
                    return 0;
                else {
                    flag = 1;
                    hasFlag = true;
                }
            }
            else if ('0' <= *it && *it <= '9') {
                result = result * 10 + *it - '0';
                if (result*flag > INT_MAX ) {
                    return INT_MAX;
                }
                else if (result*flag < INT_MIN) {
                    return INT_MIN;
                }
            }
            else {
                break;
            }
        }
        
        return result*flag;
    }
};
