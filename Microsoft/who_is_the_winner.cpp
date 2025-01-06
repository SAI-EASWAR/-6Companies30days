class Solution {
public:
    int josephus(int n, int k) {
        
        if (n == 1)
            return 0; 
    
        return (josephus(n - 1, k) + k) % n;
    }
    int findTheWinner(int n, int k) {

        return josephus(n,k) + 1;
    }
}; //time complexiy : O(n) and space complexity : (1)

class Solution {
public:
    int findTheWinner(int n, int k) {
        
        deque<int> dq;
        for(int i=1;i<=n;i++)
        dq.push_back(i);

        while(dq.size() > 1){
            int move = k - 1;
            while(move != 0){
                int f = dq.front();
                dq.pop_front();
                dq.push_back(f);
                move--;
            }
            dq.pop_front();
        }

        return dq.front();
    }
}; //time complexiy : O(n*k) and space complexity : (n)