#include <iostream>
#include <any>
#include <vector>
#include <utility>
#include <typeinfo>
using namespace std;

int productSum(vector<any> array, int depth = 1) {
	int sum = 0;
	for(auto value : array){
		if(value.type() == typeid(vector<any>))
			sum += productSum(any_cast<vector<any>>(value), depth + 1);
		else
			sum += any_cast<int>(value);
	}
  return sum * depth;
}

int main(){
    vector<any> testCase = {5, 2, vector<any>{7, -1}, 3, vector<any>{6, vector<any>{-13, 8}, 4}};
    cout << productSum(testCase, 1);
    return 0;
}