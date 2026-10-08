class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        unordered_map<char,int> mp;

        for(int i=0;i<26;i++){
            mp[order[i]] = i;
        }

        int n=words.size();

        for(int i = 0; i < n - 1; i++){
            string word1 = words[i];
            string word2 = words[i + 1];

            int len = min(word1.size(), word2.size());
            bool found = false;

            for(int j=0;j<len;j++){
                if(mp[word1[j]] < mp[word2[j]]){
                    found=true;
                    break;
                }
                else if(mp[word1[j]] > mp[word2[j]]){
                    return false;
                }
            }
            if(!found && word1.size() > word2.size()){
                return false;
            }

        }
        return true;

    }
};