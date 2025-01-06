class Solution {
public:
    int OptimalSolve(vector<vector<int>>& envelopes){
        int n = envelopes.size();
        if(n == 0)
        return 0;

        vector<int> result;
        result.push_back(envelopes[0][0]);

        for(int i=1; i<n; i++){
            if(envelopes[i][0] > result.back())
            result.push_back(envelopes[i][0]);

            else{
                int index = lower_bound(result.begin(), result.end(), envelopes[i][0]) - result.begin();
                result[index] = envelopes[i][0];
            }
        }
        return result.size();

    }
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        
        auto lambda = [](vector<int> &a, vector<int>&b){
            if(a[1] == b[1]){
                return a[0] > b[0];
            }
            else{
                return a[1] < b[1];
            }
        };

        sort(envelopes.begin(), envelopes.end(), lambda);


        return OptimalSolve(envelopes);
    }
};