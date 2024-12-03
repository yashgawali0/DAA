#include <iostream>
#include <vector>
using namespace std;


bool findIfSumPossible(const vector<int>& Set, int sizeOfSet, int targetSum) {
    // If targetSum is 0 then there is 1 solution i.e. empty subset, i.e. no element selected
    if (targetSum == 0) 
        return true;
    // if the sum is negative or we don't have any items in the set then there will be no solution, therefore return false 
    if (sizeOfSet == 0) 
        return false;
    // check if the solution is possible by calling the function recursively (once including the current coin and once excluding the current coin)
    return findIfSumPossible(Set, sizeOfSet-1, targetSum) || findIfSumPossible(Set, sizeOfSet - 1, targetSum - Set[sizeOfSet - 1]);
}
int main() {
    vector<int> Set = {3,34,4,12,5,2};
    int targetSum = 36;
    if(findIfSumPossible(Set, Set.size(), targetSum)==true){
        cout<<"True"<<endl;
    }
    else{
        cout<<"False"<<endl;
    }
    return 0;
}
