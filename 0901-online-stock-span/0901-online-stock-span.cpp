class StockSpanner {
public:
        stack<pair<int,int>>st;
        int idx;
    StockSpanner() {
        while(!st.empty()) st.pop();
        idx=0;
    }
    
    int next(int price) {
        int ans;
        
        while(!st.empty() && st.top().second<=price) st.pop();
        ans=st.empty()?idx+1:idx-st.top().first;
        st.push({idx,price});
        idx++;
        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */