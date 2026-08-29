class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        vector<int> sortedNums = nums;
        sort(sortedNums.begin(), sortedNums.end());

        int currGroup =0;
        unordered_map<int, int> numToGroup;
        numToGroup[sortedNums[0]] = currGroup;

        unordered_map<int, queue<int>> groupToList;
        groupToList[currGroup].push(sortedNums[0]);

        for(int i=1; i<nums.size(); i++){
            if(abs(sortedNums[i] - sortedNums[i-1])>limit){
                currGroup++;
            }
            numToGroup[sortedNums[i]] = currGroup;
            groupToList[currGroup].push(sortedNums[i]);
        }

        for(int i=0; i<nums.size(); i++){
            int num = nums[i];
            int group = numToGroup[num];
            nums[i] = groupToList[group].front();
            groupToList[group].pop();
        }
        return nums;
    }
};