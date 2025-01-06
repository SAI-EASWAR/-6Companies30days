class Solution {
public:
    int maxProduct(string s) {
        int n = s.length();

        int result = 0;
        unordered_map<int, int> mp;

        for (int mask = 1; mask < 1 << n; mask++) {
            string x = "";
            for (int i = 0; i < n; i++) {
                if (mask & (1 << i)) { // Corrected condition
                    x += s[i];
                }
            }
            string temp = x;
            reverse(temp.begin(), temp.end());
            if (x == temp)
                mp[mask] = x.size();
        }

        for (auto& a : mp) {
            for (auto& b : mp) {
                if ((a.first & b.first) == 0) {
                    result = max(result, a.second * b.second);
                }
            }
        }

        return result;
    }
};