class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n=nums.size();

        int minIdx = 0, maxIdx=0;

        for(int i=0; i<n; i++){
            if(nums[i] < nums[minIdx]) minIdx= i;
            if(nums[i] > nums[maxIdx]) maxIdx= i;
        }

        int left = min(maxIdx, minIdx);
        int right = max(maxIdx, minIdx);

        return min({right + 1, n - left, left+1 + n - right});
    }
};