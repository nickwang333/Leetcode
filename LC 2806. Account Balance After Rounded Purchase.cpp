class Solution {
public:
    int accountBalanceAfterPurchase(int purchaseAmount) {
        int tmp1 = abs(purchaseAmount/10 * 10 - purchaseAmount);
        int tmp2 = abs(purchaseAmount/10 * 10 + 10 - purchaseAmount);
        if(tmp1 < tmp2){
            return 100 - purchaseAmount/10 * 10;
        }
        else{
            return 100- purchaseAmount/10 * 10 - 10;
        }
    }
};
