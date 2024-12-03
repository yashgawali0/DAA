#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void generateSubsets(int index, vector<int>& elements, vector<int>& currentSubset, vector<vector<int>>& allSubsets) {
    allSubsets.push_back(currentSubset);
    for (int i = index; i < elements.size(); i++) {
        if (i != index && elements[i] == elements[i - 1]) continue;
        currentSubset.push_back(elements[i]);
        generateSubsets(i + 1, elements, currentSubset, allSubsets);
        currentSubset.pop_back();
    }
}

vector<vector<int>> getAllSubsets(int arr[], int size) {
    vector<int> elements(arr, arr + size);
    vector<int> currentSubset;
    vector<vector<int>> allSubsets;
    sort(elements.begin(), elements.end());
    generateSubsets(0, elements, currentSubset, allSubsets);
    return allSubsets;
}

int main() {
    int inputSet[] = {10, 12, 12};
    vector<vector<int>> subsets = getAllSubsets(inputSet, 3);

    for (const auto& subset : subsets) {
        cout << "[";
        for (size_t i = 0; i < subset.size(); i++) {
            cout << subset[i] << (i < subset.size() - 1 ? ", " : "");
        }
        cout << "], ";
    }
    return 0;
}
