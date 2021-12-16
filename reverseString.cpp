#include <iostream>
#include <string>
#include <utility>
using namespace std;

string reverseString(string input){
    int n = input.size();
    char temp;

    for(int i = 0; i < n / 2; i++){
        temp = input[i];
        input[i] = input[n - i - 1];
        input[n - i - 1] = temp;
    }    
    return input;
}

int main(){
    cout << reverseString("HelloWorld");
    return 0;
}