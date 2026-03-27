class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;

        // modern C++ (C++11): unordered_map + std::function + lambda expressions
        unordered_map<string, function<int(int,int)>> ops = {
            {"+", [](int a, int b){ return a+b; }},
            {"-", [](int a, int b){ return a-b; }},
            {"*", [](int a, int b){ return a*b; }},
            {"/", [](int a, int b){ return a/b; }}
        };

        for (int i = 0; i < tokens.size(); i++) {
            // using count to check existence only (no need for value)
            // equivalent using find: if (ops.find(tokens[i]) != ops.end())
            if (ops.count(tokens[i])) {
                int b = s.top(); s.pop();
                int a = s.top(); s.pop();

                // one-liner: get function from map + call it
                s.push(ops[tokens[i]](a,b));

                // equivalent 2-liner:
                // auto f = ops[tokens[i]];
                // s.push(f(a,b));
            } else {
                s.push(stoi(tokens[i]));
            }
        }
        return s.top();
    }
};