class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        
        int res = 1;//minimum smallest number
        
        for(int i =0;i<nums.size();i++)
        {
            if(nums[i] == res)
            {
                res++;
            }
            else if(nums[i]>res)
            {
                break;
            }
        }
        return res;
    }
};
