class Solution {
public:
    int minimumPushes(string word) {
        int total_pushes =0;
        for(int i=0; i<word.length(); ++i){
            total_pushes += (i/8)+1;
        }
        return total_pushes;
    }
};