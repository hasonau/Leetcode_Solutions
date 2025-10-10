class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int>s;
        int result=0;
        for(int i=0;i<operations.size();i++){
            if(operations[i]=="+"){
                int firstVal=s.top();
                s.pop();
                int newValue= s.top()+ firstVal;
                s.push(firstVal);
                s.push(newValue);
                result+=newValue;
            }
            else if(operations[i]=="D") {
                int valuetoBePushed=2*s.top();
                result+=valuetoBePushed;
                s.push(valuetoBePushed);
            }
            else if(operations[i]=="C") {
                int valueTobeRemoved=s.top();
                result-=valueTobeRemoved;
                s.pop();
            }
            else {
                result+=stoi(operations[i]);
                s.push(stoi(operations[i]));
            }
        }
        return result;
        
    }
};