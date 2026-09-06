class Solution {
public:
    bool isPalindrome(string s, int left, int right) {
        while (left < right) {
            if (s[left] != s[right]) {
                return false;
            }

            left++;
            right--;
        }

        return true;
    }

    void backTrack(string s, vector<vector<string>>& ans, vector<string>& ds, int start){

        int totalLength = 0;
        if (start == s.size()) {
            ans.push_back(ds);
            return;
        }

        for (int i = start; i < s.size(); i++) {
            if (isPalindrome(s,start,i)){
                ds.push_back(s.substr(start,i - start + 1));
                backTrack(s,ans,ds,i+1);
                ds.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> ds;
        int size = s.size();
        backTrack(s, ans, ds, 0);
        return ans;
    }
};