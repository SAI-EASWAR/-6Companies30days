class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_set<string> seen;
        unordered_set<string> result;

        int n = s.size();
        
        for(int i=0;i<n-9;i++){
            string check = s.substr(i,10);
            if(seen.find(check) != seen.end()){
                result.insert(check);
            }
            seen.insert(check);
        }

        vector<string> answer(result.begin(), result.end());

        return answer;
    }
};