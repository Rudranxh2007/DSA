class StockSpanner {
public:
        stack<pair<int,int>>st;
        int idx;
    StockSpanner() {
        while(!st.empty()) st.pop();
        idx=-1;
    }
    
    int next(int price) {
        int ans;
        idx=idx+1;
        while(!st.empty() && st.top().second<=price) st.pop();
        ans=st.empty()?idx+1:idx-st.top().first;
        st.push({idx,price});
        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */