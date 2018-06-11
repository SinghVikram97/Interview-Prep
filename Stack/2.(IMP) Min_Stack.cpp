https://leetcode.com/problems/min-stack/description/

https://drive.google.com/open?id=1zVVoStgNqWVO957UB0UaywClRXs7OtDP
https://drive.google.com/open?id=1JD9FYdZ8ucayB843wALCDt5atbLzugQl

// Global, they shouldn't be global
vector<int> min_list;
vector<int> original_list;
class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
       min_list.clear();
       original_list.clear(); 
    }
    
    void push(int x) {
        
        long long int min_value;
        
        if(!min_list.empty()){
             min_value=min_list.back();
        }
        // If empty it means no element in original stack
        else{
            min_value=INT_MAX;
        }
        
        if(x<=min_value){
            min_list.push_back(x);
        }
        original_list.push_back(x);
    }
    
    void pop() {
        
        if(original_list.back()==min_list.back()){
            min_list.pop_back();
        }
        original_list.pop_back();
    }
    
    int top() {
        return original_list.back();
    }
    
    int getMin() {
        return min_list.back();
    }
};

// Correct approach
class MinStack {
    private:
        stack<int> elementStack;
        stack<int> minimumStack;
        int minElement = -1;
    public:
        void push(int x) {
            elementStack.push(x);
            if(elementStack.size() == 1 || x <= minElement) {
                minimumStack.push(x);
                minElement = x;
            } 
        }

        void pop() {
            if (elementStack.top() == minElement) {
                minimumStack.pop();
                if (!minimumStack.empty()) {
                    minElement = minimumStack.top();
                } else {
                    minElement = -1;
                }
            }
            elementStack.pop();
        }

        int top() {
            if (elementStack.empty()) return -1;
            return elementStack.top();
        }

        int getMin() {
            return minElement;
        }
};
