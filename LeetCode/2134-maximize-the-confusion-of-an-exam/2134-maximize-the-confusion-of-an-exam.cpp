class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        int n=answerKey.size(),l=0,r=0,maxFreq=0;
        int ct=0,cf=0;
        for(r=0;r<n;r++){
            if(answerKey[r]=='T') ct++;
            else cf++;

            while(min(ct,cf)>k){
                if(answerKey[l] == 'T'){
                    ct--;
                }else{
                    cf--;
                }
                l++;
            }
            maxFreq = max(maxFreq, r - l + 1);
        }
        return maxFreq;
    }
};