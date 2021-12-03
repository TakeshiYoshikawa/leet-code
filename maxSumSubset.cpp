#include <vector>
#include<iostream>
using namespace std;

int maxSubsetSumNoAdjacent(vector<int> array) {
	if(array.size() == 0)
		return 0;
	if(array.size() == 1)
		return array[0];
		
	vector<int> sums = array;
	
	sums[1] = max(sums[0], sums[1]);
	for(int i = 2; i < array.size(); i++){
		sums[i] = max(sums[i-1], array[i] + sums[i-2]);
	}
	
	return sums.back();
}

int main (){
    vector<int> arr = {75, 105, 120, 75, 90, 135};

    cout << maxSubsetSumNoAdjacent(arr);
    return 0;
}