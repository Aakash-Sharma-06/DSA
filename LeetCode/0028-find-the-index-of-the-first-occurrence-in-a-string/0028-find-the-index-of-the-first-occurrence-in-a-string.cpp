class Solution {
public:
    int strStr(string haystack, string needle) {
        int n1 = haystack.size();
        int n2 = needle.size();

        for (int j = 0; j <= n1 - n2; j++) {
            int i = 0;

            while (i < n2 && haystack[j + i] == needle[i]) {
                i++;
            }

            if (i == n2) {
                return j;
            }
        }

        return -1;
    }
};