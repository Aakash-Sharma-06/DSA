class Solution {
public:
    void givePermutation(vector<int>& nums, vector<vector<int>>& ans, int i) {
        if (i == nums.size()) {
            ans.push_back(nums);
            return;
        }

        set<int> used;

        for (int j = i; j < nums.size(); j++) {

            if(used.count(nums[j])){
                continue;
            }

            used.insert(nums[j]);

            swap(nums[i], nums[j]);

            givePermutation(nums, ans, i + 1);

            swap(nums[i], nums[j]);
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> ds;
        sort(nums.begin(), nums.end());
        givePermutation(nums, ans, 0);
        return ans;
    }
};