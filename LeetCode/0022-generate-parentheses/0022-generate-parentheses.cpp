class Solution {
public:
    void backTrack(vector<string>& ans, string s, int open, int close, int n) {
        if (s.length() == 2 * n) {
            ans.push_back(s);
            return;
        }

        if (open < n) {
            s.push_back('(');
            backTrack(ans, s, open + 1, close, n);
            s.pop_back();
        }

        if (close < open) {
            s.push_back(')');
            backTrack(ans, s, open, close + 1, n);
            s.pop_back();
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string s;
        backTrack(ans, s, 0, 0, n);
        return ans;
    }
};