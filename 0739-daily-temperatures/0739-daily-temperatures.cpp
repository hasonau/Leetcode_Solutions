class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> result(n, 0);
        stack<int>monoDecreasingStack;
        for(int i=0;i<n;i++){
            while(!monoDecreasingStack.empty() && temperatures[i]>temperatures[monoDecreasingStack.top()]){
                result[monoDecreasingStack.top()]=i-monoDecreasingStack.top();
                monoDecreasingStack.pop();
            }
            monoDecreasingStack.push(i);
        }
        return result;
    }
};