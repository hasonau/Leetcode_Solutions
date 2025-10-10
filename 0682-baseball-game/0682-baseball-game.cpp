class Solution {
public:
    int calPoints(vector<string>& operations) {
        vector<int>v;
        int result=0;

        for(int i=0;i<operations.size();i++){
            if(operations[i]=="+"){
                int temp=v[v.size()-1]+v[v.size()-2];
                result+=temp;
                v.push_back(temp);
            }
            else if(operations[i]=="D") {
                int temp = v[v.size()-1]*2;
                result+=temp;
                v.push_back(temp);
            }
            else if(operations[i]=="C") {
                result-=v.back();
                v.pop_back();
            }
            else {
                v.push_back(stoi(operations[i]));
                result+=stoi(operations[i]);
            }
        }
        return result;
        
    }
};