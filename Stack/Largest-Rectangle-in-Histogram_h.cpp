//
// Created by muham on 30/06/2024.
//
#include <iostream>
#include <vector>
#include <stack>

class Solution {
public:
     int largestRectangleArea(std::vector<int>& heights) {
        std::stack<int>s;
        int result=0;
        for (int i=0;i<=heights.size();i++){
            if(s.empty()){
                s.push(i);
            }
            else if(i<heights.size() && heights[i]>=heights[s.top()]){
                s.push(i);
                continue;
            }
            else{
                while(!s.empty() && (i==heights.size() || heights[i]<heights[s.top()])){
                    int save=s.top();
                    s.pop();
                    if(!s.empty()){
                        if ( ( (i-s.top()-1)*heights[save] ) >result){
                            result=(i-s.top()-1)*heights[save];
                        }
                    }
                    else{
                        if ( (i*heights[save] ) >result){
                            result=i*heights[save];
                        }
                    }
                }
                s.push(i);
            }
        }
        return result;
    }
};
int main(){
    Solution s;
    std::vector<int> v{7,1,7,2,2,4};
    std::cout<< s.largestRectangleArea(v);
}