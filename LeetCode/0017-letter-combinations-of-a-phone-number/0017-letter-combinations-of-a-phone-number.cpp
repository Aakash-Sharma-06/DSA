class Solution {
public:
    void backTrack(string digits,vector<string>& mapping,vector<string>& ans,string s,int i) {
        if(s.size()== digits.size()){
            ans.push_back(s);
            return;
        }

        string letters = mapping[digits[i] - '0'];
        for(int j=0;j<letters.size();j++){
            s+=letters[j];
            backTrack(digits,mapping,ans,s,i+1);
            s.pop_back();
        }

    }

    vector<string> letterCombinations(string digits) {
        vector<string> mapping = {
            "",     // 0
            "",     // 1
            "abc",  // 2
            "def",  // 3
            "ghi",  // 4
            "jkl",  // 5
            "mno",  // 6
            "pqrs", // 7
            "tuv",  // 8
            "wxyz"  // 9
        };
        vector<string> ans;
        string s;
        backTrack(digits,mapping,ans,s,0);
        return ans;
    }
};