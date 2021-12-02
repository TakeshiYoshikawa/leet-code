#include <iostream>
#include<vector>
#include <map>
using namespace std;

class FindSum {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::map<int, int> indexOf;
        
        for(int i = 0; i < nums.size(); i++){
            int remainder = target - nums[i];
            
            if(indexOf.find(remainder) != indexOf.end()){
                return {i, indexOf[i]};
            }
            indexOf[nums[i]] = i;
        }
        return {};
    }
};

int main() {
    vector<int> arr = {2,7,11,15};

    FindSum findSum;
    auto answer = findSum.twoSum(arr, 9);

    cout << "[" << answer[0] << "," << answer[1] << "]";
    return 0;
}
