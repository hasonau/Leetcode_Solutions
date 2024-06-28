//
// Created by Muhammad Umair on 28/06/2024.
//
#include <iostream>
#include <vector>
#include <stack>

using namespace std;


class Solution {
private:
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int>result(temperatures.size(),0);
        stack<int>s;

        for(int i=temperatures.size()-1;i>-1;i--){
            if(s.empty()){
                s.push(i);
            }
            else{
                if(temperatures[s.top()]>temperatures[i]){
                    result[i]=s.top()-i;
                    s.push(i);
                }
                else{
                    while(!s.empty() && temperatures[s.top()]<=temperatures[i]){
                        s.pop();
                    }
                    if(!s.empty()){
                        result[i]=s.top()-i;
                    }
                    s.push(i);
                }
            }
        }
        return result;
    }
};

int main() {
    Solution solution;
    vector<int> temperatures = {73, 74, 75, 71, 69, 72, 76, 73};
    vector<int> result = solution.dailyTemperatures(temperatures);

    for (int i = 0; i < result.size(); ++i) {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}