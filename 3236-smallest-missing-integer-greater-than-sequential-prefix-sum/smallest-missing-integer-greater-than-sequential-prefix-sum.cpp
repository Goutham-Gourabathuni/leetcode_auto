#include<unordered_set>

class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int total = nums[0];
        for (int i = 1; i<nums.size(); ++i){
            if(nums[i] == nums[i-1]+1){
                total += nums[i];
            }else{
                break;
            }
        }

        unordered_set<int> num_set(nums.begin(), nums.end());
        while(num_set.count(total)){
            total++; 
        }
        return total;
    }
};

// class Solution {
// public:
//     int missingInteger(vector<int>& nums) {
//         int total = nums[0];
//         for (int i = 1; i < nums.size(); ++i) {
//             if (nums[i] == nums[i-1] + 1) {
//                 total += nums[i];
//             } else {
//                 break;
//             }
//         }
//         unordered_set<int> num_set(nums.begin(), nums.end());
//         while (num_set.count(total)) {
//             total++;
//         }
//         return total;
//     }
// };