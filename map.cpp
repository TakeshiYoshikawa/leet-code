#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<pair<int, bool>> mPair;

    for(int i = 0; i < 20; i++){
        mPair.push_back(std::make_pair(i, false));
    }

    for(auto i = mPair.begin(); i != mPair.end(); i++){
        if(i->first % 2 == 0)
            i->second = true;

        cout << i->first << ":" << boolalpha << i->second << endl;
    }
}
