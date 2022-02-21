class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 0, element = 0;
        for(int it : nums){
            if(count == 0) element = it;
            if(it == element) count++;
            else count--;
        }
        return element;
    }
};
