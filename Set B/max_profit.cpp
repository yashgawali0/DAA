#include <iostream>
#include <vector>

using namespace std;

int maxProfit(vector<int>& prices, int n) {
    int profit = 0;
    int currentDay = n - 1;

    while (currentDay > 0) {
        int day = currentDay - 1;

        while (day >= 0 && prices[currentDay] > prices[day]) {
            profit += prices[currentDay] - prices[day];
            --day;
        }
        currentDay = day;
    }
    return profit;
}

int main() {
    vector<int> prices = {2, 3, 5};
    int N = prices.size();

    cout << maxProfit(prices, N) << endl;

    return 0;
}
