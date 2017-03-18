// https://leetcode.com/problems/roman-to-integer/#/description

class Solution {
public:
    int romanToInt(string s) {
        int result = 0;
        int last = 0;
        for (string::reverse_iterator it = s.rbegin(); it != s.rend(); ++it) {
            switch(*it) {
                case 'I':
                    if (last > 1) {
                        last = 0;
                        result -= 1;
                    }
                    else {
                        last = 1;
                        result += 1;
                    }
                    break;
                case 'V':
                    result += 5;
                    last = 5;
                    break;
                case 'X':
                    if (last > 10) {
                        last = 0;
                        result -= 10;
                    }
                    else {
                        last = 10;
                        result += 10;
                    }
                    break;
                case 'L':
                    result += 50;
                    last = 50;
                    break;
                case 'C':
                    if (last > 100) {
                        last = 0;
                        result -= 100;
                    }
                    else {
                        last = 100;
                        result += 100;
                    }
                    break;
                case 'D':
                    result += 500;
                    last = 500;
                    break;
                case 'M':
                    result += 1000;
                    last = 1000;
                    break;
            }
        }
        return result;
    }
};
