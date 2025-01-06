class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        unordered_map<int,int> mp;

        int n = nums.size();
        int odds = 0, result = 0;
        mp[0] = 1;
        for(int i=0; i<n; i++){
            odds = (nums[i] % 2 != 0) ? odds+1 : odds;
            int find = odds - k;
            if(mp.find(find) != mp.end()){
                result += mp[find];
            }

            mp[odds]++;
        }

        return result;
    }
};