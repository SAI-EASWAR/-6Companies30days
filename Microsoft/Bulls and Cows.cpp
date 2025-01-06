class Solution {
public:
    string getHint(string secret, string guess) {
        int n = secret.length();

        unordered_map<char,int> mp;
        vector<int> skip;
        int bulls = 0;
        for(int i=0;i<n;i++){
            if(secret[i] == guess[i]){
                skip.push_back(i);
                bulls++;
                continue;
            }
            mp[secret[i]]++;
        }

        int cows = 0;

        for(int i=0;i<n;i++){
            if(secret[i] == guess[i])
            continue;

            if(mp.find(guess[i]) != mp.end()){
                mp[guess[i]]--;
                cows++;
                if(mp[guess[i]] == 0)
                mp.erase(guess[i]);
            }
        }

        string result = to_string(bulls) + 'A' + to_string(cows) + 'B';

        return result;

    }
};