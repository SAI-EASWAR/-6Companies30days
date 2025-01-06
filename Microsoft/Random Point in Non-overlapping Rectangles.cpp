class Solution {
public:
    vector<vector<int>> rects;
    vector<long long> areas;
    Solution(vector<vector<int>>& rects) {
        this->rects = rects;
        long long sum = 0;
        for(vector<int>& one : rects){
            long long a = one[2] - one[0] + 1;
            long long b = one[3] - one[1] + 1;
            sum += a * b; // all point in the area of the rectangle cummulative sum
            areas.push_back(sum);
        }
    }
    
    vector<int> pick() {
        long long likelihood = 1 + (rand() % areas.back());

        int idx = lower_bound(areas.begin(), areas.end(), likelihood) - areas.begin();

        int x = rects[idx][0] + (rand() % (rects[idx][2] - rects[idx][0] + 1));
        int y = rects[idx][1] + (rand() % (rects[idx][3] - rects[idx][1] + 1));

        return {x,y};
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(rects);
 * vector<int> param_1 = obj->pick();
 */

// time complexity - O(log n) space complexity - O(n)