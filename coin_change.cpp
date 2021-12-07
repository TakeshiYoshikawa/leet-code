class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> change(amount + 1, amount + 1);
        
        change[0] = 0;
        for(int coin : coins){
            for(int j = coin; j < amount + 1; j++){
                change[j] = min(change[j - coin] + 1, change[j]);
            }
        }
        
        return change[amount] != amount + 1 ? change[amount] : -1;
    }
};
