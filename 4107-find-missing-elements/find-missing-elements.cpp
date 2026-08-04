class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        vector<int> missing;
        sort(nums.begin(), nums.end());
        int start = nums[0];
        int end = nums.back();

        for(int i=start+1; i<end; i++){
            if(binary_search(nums.begin(), nums.end(), i)){
                continue;
            }else{
                missing.push_back(i);
            }
        }

        return missing;
    }
};