class Solution {
public:
    // Helper function to calculate the minimum cost recursively
    int dfs(vector<int>& price, vector<vector<int>>& special, vector<int>& needs, unordered_map<string, int>& memo) {

        // Generate a unique key for the current state of needs by converting it to a string
        string key = "";
        for (int need : needs) 
            key += to_string(need) + ",";

        // If the current state is already computed, return the stored result (memoization)
        if (memo.count(key)) 
            return memo[key];

        // Base case: Calculate the cost without using any special offers
        int cost = 0;
        for (int i = 0; i < needs.size(); i++) 
            cost += needs[i] * price[i];

        // Explore all the special offers and combinations
        for (auto& offer : special) {
            vector<int> newNeeds = needs; // Copy the current needs
            bool valid = true;           // Check if the offer is valid
            for (int i = 0; i < needs.size(); i++) {
                if (newNeeds[i] < offer[i]) { // If the offer requires more items than available, skip it
                    valid = false;
                    break;
                }
                newNeeds[i] -= offer[i]; // Apply the offer by reducing the required items
            }
            if (valid) {
                // Compare the base cost with the cost of using the current offer and update the minimum cost
                cost = min(cost, offer.back() + dfs(price, special, newNeeds, memo));
            }
        }

        // Store the computed cost for the current state in the memoization map
        return memo[key] = cost;
    }

    
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        unordered_map<string, int> memo; 
        return dfs(price, special, needs, memo);
    }
};
