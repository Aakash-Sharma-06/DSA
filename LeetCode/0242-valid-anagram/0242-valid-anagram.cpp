class Solution {
public:
    bool isAnagram(string s, string t) {

        if (s.size() != t.size()) return false;

        unordered_map<char, int> mp1;
        unordered_map<char, int> mp2;

        for (char c : t) {
            mp1[c]++;
        }

        for (char c : s) {
            mp2[c]++;
        }

        for (int i = 0; i < s.size(); i++) {
            if (mp1[s[i]] != mp2[s[i]]) {
                return false;
            }
        }

        return true;
    }
};