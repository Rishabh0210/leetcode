//https://leetcode.com/explore/challenge/card/may-leetcoding-challenge/536/week-3-may-15th-may-21st/3334/

class StockSpanner {
private:
    int stocks[10000];
    int size;
public:
    StockSpanner() {
        size = 0;
    }
    
    int next(int price) {
        int i, ans = 0;
        stocks[size++] = price;
        for(i = size - 1; i >= 0 && stocks[i] <= price; i--)
            ans++;
        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */