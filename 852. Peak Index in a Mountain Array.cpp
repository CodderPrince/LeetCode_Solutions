class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int mx = arr[0], pos = 0;
        for (int i = 1; i < arr.size(); i++) {
            if (arr[i] > mx) {
                mx = arr[i];
                pos = i;
            }
        }
        return pos;
    }
};
