#include <iostream>
#include <vector>
using namespace std;


int findWaysToMakeSum(const vector<int>& coinValues, int numCoins, int targetSum) {
    // If targetSum is 0 then there is 1 solution, i.e. no coin selected
    if (targetSum == 0) 
        return 1;
    // if the sum is negative or we don't have any coins then there will be 0 solutions, therefore return 0 
    if (targetSum < 0 || numCoins == 0) 
        return 0;
    // count the number of solutions by calling the function recursively (once including the current coin and once excluding the current coin)
    return findWaysToMakeSum(coinValues, numCoins, targetSum - coinValues[numCoins - 1]) + 
           findWaysToMakeSum(coinValues, numCoins - 1, targetSum);
}
int main() {
    vector<int> coinValues = {1, 2, 3};
    int targetSum = 5;
    cout << findWaysToMakeSum(coinValues, coinValues.size(), targetSum);
    return 0;
}
