class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        int r = nums.size()-1, l = 0;
        while(l < r){
            if(nums[l] + nums[r] == target)
            return {l+1, r+1};
            else if(nums[l] + nums[r] > target) r--;
            else l++;
        }
        return {};
    }
};
