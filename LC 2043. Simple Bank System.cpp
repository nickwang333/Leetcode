class Bank {
public:
    vector<long long> m;
    Bank(vector<long long>& balance) {
        m = balance;
    }
    
    bool transfer(int account1, int account2, long long money) {
        if(account1 > m.size() || account2 > m.size()){
            return false;
        }
        if(withdraw(account1, money)){
            deposit(account2, money);
            return true;
        }
        return false;
    }
    
    bool deposit(int account, long long money) {
        if(account>m.size()){
            return false;
        }
        m[account-1]+=money;
        return true;
    }
    
    bool withdraw(int account, long long money) {
        if(account>m.size() || m[account-1]<money){
            return false;
        }
        m[account-1]-=money;
        return true;
    }
};

/**
 * Your Bank object will be instantiated and called as such:
 * Bank* obj = new Bank(balance);
 * bool param_1 = obj->transfer(account1,account2,money);
 * bool param_2 = obj->deposit(account,money);
 * bool param_3 = obj->withdraw(account,money);
 */
