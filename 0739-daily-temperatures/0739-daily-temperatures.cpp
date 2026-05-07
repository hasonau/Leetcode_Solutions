class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int>decreasingStack;
        vector<int>result(temperatures.size(),0);
        decreasingStack.push(0);
        for(int i=1;i<temperatures.size();i++){
            while(!decreasingStack.empty() && temperatures[i] > temperatures[decreasingStack.top()]){
                result[decreasingStack.top()]= i - decreasingStack.top();
                decreasingStack.pop();
            }
            decreasingStack.push(i);
        }
        return result;
    }
};