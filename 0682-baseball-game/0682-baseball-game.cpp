class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int>s;
        for(int i=0;i<operations.size();i++){
            if(operations[i]=="+"){
                int firstVal=s.top();
                s.pop();
                int newValue= s.top()+ firstVal;
                s.push(firstVal);
                s.push(newValue);
            }
            else if(operations[i]=="D") s.push(2*s.top());
            else if(operations[i]=="C") s.pop();
            else s.push(stoi(operations[i]));
        }
        int result=0;
        while(!s.empty()){
         result+=s.top();
         s.pop();   
        }
        return result;
    }
};