class Solution {
public:
    int thirdMax(vector<int>& nums) {
        set<int> s(nums.begin(),
                   nums.end()); // Directly construct a set from nums

        if (s.size() < 3) {
            return *s.rbegin(); // Largest element
        }

        auto it = s.rbegin(); // Reverse iterator (greatest element first)
        advance(it, 2);       // Move to the third greatest element
        return *it;
    }
};
