//
// Created by muham on 28/06/2024.
//
#include <iostream>
#include <stack>

class MinStack {
private:
    std::stack<int> s;
    std::stack<int> s2;


public:

    MinStack() {}

    void push(int val) {
        s.push(val);

        if(s2.empty()){
            s2.push(val);
        }
        else{
            val=std::min(s2.top(),val);
            s2.push(val);
        }

    }

    void pop() {
        s.pop();
        s2.pop();
    }

    int top() {
        return s.top();
    }

    int getMin() {
        return s2.top();
    }
};


int main() {
    MinStack* obj = new MinStack();

    obj->push(3);
    std::cout << "Top: " << obj->top() << ", Min: " << obj->getMin() << std::endl;

    obj->push(5);
    std::cout << "Top: " << obj->top() << ", Min: " << obj->getMin() << std::endl;

    obj->push(2);
    std::cout << "Top: " << obj->top() << ", Min: " << obj->getMin() << std::endl;

    obj->push(1);
    std::cout << "Top: " << obj->top() << ", Min: " << obj->getMin() << std::endl;

    obj->pop();
    std::cout << "Top: " << obj->top() << ", Min: " << obj->getMin() << std::endl;

    obj->pop();
    std::cout << "Top: " << obj->top() << ", Min: " << obj->getMin() << std::endl;

    delete obj;
    return 0;
}