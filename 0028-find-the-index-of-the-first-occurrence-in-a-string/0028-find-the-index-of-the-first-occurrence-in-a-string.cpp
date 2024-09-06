class Solution {
public:
    int strStr(string haystack, string needle) {
        int index=haystack.find(needle,0);
        return index;
    }
};