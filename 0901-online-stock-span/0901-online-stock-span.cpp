class StockSpanner {

    stack<int> st;
    vector<int> prices;

public:

    StockSpanner() {

    }

    int next(int price) {

        prices.push_back(price);

        int i = prices.size() - 1;

        while (!st.empty() && prices[st.top()] <= prices[i]) {
            st.pop();
        }

        int span;

        if (st.empty())
            span = i + 1;
        else
            span = i - st.top();

        st.push(i);

        return span;
    }
};