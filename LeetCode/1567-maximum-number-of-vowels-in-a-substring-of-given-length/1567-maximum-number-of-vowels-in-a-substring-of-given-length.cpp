class Solution {
public:

    bool isVowel(char c){
        if(c=='a' || c=='e' || c=='i' || c=='o' ||c=='u'){
            return true;
        }
        else{
            return false;
        }
    }

    int maxVowels(string s, int k) {
        int i=0;
        int count=0;
        int ans=0;
        int n=s.size();
        
        for(int j=0;j<n;j++){
            if(isVowel(s[j])){
                count++;
            }

            if(j-i+1==k){
                ans=max(ans,count);

                if(isVowel(s[i])){
                    count--;
                }
            i++;
            }
        }

        return ans;
    }
};