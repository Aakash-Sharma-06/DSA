class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n = nums.size();
        int sum = 0;
        int count = 0;
        unordered_map<int, int> freq;
        freq[0] = 1;

        // prefix[j]-prefix[i] % k == 0

        for (int i = 0; i < n; i++) {
            sum += nums[i];
            int rem = sum % k;

            if (rem < 0)
                rem += k;

            if (freq.find(rem) != freq.end()) {
                count += freq[rem];
            }

            freq[rem]++;
        }
        return count;
    }
};