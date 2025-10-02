class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        queue<int,deque<int>>studentsQ(deque<int>(students.begin(),students.end()));
        queue<int,deque<int>>sandwichesQ(deque<int>(sandwiches.begin(),sandwiches.end()));
        int count=0;
        while(!studentsQ.empty()){
            if(studentsQ.front()==sandwichesQ.front()){
                count=0;
                studentsQ.pop();
                sandwichesQ.pop();
            }
            else{
                if(count==studentsQ.size()) return count;
                count+=1;
                int saveFront=studentsQ.front();
                studentsQ.pop();
                studentsQ.push(saveFront);
            }
        }
        return 0;
    }
};