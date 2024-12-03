#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <iterator>

using namespace std;

int maximumShops(vector<int>& opening, vector<int>& closing, int n, int k) {
    vector<pair<int, int>> a(n);
    
    for (int i = 0; i < n; ++i) {
        a[i] = {opening[i], closing[i]};
    }
    
    sort(a.begin(), a.end(), [](pair<int, int>& x, pair<int, int>& y) {
        return x.second < y.second;
    });
    
    map<int, int> st;
    int count = 1;
    
    for (int i = 0; i < n; ++i) {
        bool flag = false;
        
        if (st.empty()) {
            auto it = st.upper_bound(a[i].first);
            if (it != st.begin()) {
                --it;
                if (it->first <= a[i].first) {
                    st.erase(it);
                    st[a[i].second] = 1;
                    ++count;
                    flag = true;
                }
            }
        }
        
        if (st.size() < k && !flag) {
            st[a[i].second] = 1;
            ++count;
        }
    }
    return count;
}

int main() {
    vector<int> S = {1, 8, 3, 2, 6};
    vector<int> E = {5, 10, 6, 5, 9};
    int K = 2, N = S.size();
    
    cout << maximumShops(S, E, N, K) << endl;
    return 0;
}
