#include <iostream>
#include <vector>

using namespace std;

void calcSubset(vector<int>& A, vector<vector<int>>& res, vector<int>& subset, int index) {
    res.push_back(subset); // Add the current subset to the result

    for (int i = index; i < A.size(); ++i) {
        subset.push_back(A[i]);  // Include the current element in the subset
        calcSubset(A, res, subset, i + 1);  // Recursively generate subsets
        subset.pop_back();  // Backtrack and exclude the current element
    }
}

vector<vector<int>> subsets(vector<int>& A) {
    vector<int> subset;
    vector<vector<int>> res;
    calcSubset(A, res, subset, 0);
    return res;
}

int main() {
    vector<int> array = {1, 2, 3};
    vector<vector<int>> res = subsets(array);

    for (const auto& subset : res) {
        for (int num : subset) {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}
