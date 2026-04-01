class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> answers(temperatures.size(), 0);
        for(int i=temperatures.size()-1;i>=0;i--){
            if(i==temperatures.size()-1) continue; // it will always be 0
            int movingIndex=i+1;
            
            while(temperatures[i]>=temperatures[movingIndex]) {
                movingIndex= movingIndex + answers[movingIndex];
                if(answers[movingIndex]==0) break;
            }
            if(temperatures[movingIndex]>temperatures[i]) answers[i]= movingIndex-i;
        }
        return answers;
    }
};