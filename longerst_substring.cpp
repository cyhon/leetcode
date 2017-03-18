// https://leetcode.com/problems/longest-substring-without-repeating-characters/#/description
//
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int result  = 0;
        for (int i = 0; i < s.size(); ++i) {
            int len ;
            int j = i;
            for (; j < s.size(); ++j) {
                len = j - i + 1;
                int pos = s.find(s[j], i);
                if (-1 < pos && pos < j) {
                    // all character before pos will less than current len
                    len -= 1;
                    i = pos;
                    break;
                }
                
            }
            if (len > result)
                result = len;
            if (j >= s.size())
                break;
        }
        return result;
    }
};
