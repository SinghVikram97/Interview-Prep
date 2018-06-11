https://practice.geeksforgeeks.org/problems/sort-a-stack/1

https://drive.google.com/open?id=1zcK5Pp8s91v9Aua11BuOB2ZzkWfLOrEo  O(n^2)
https://drive.google.com/open?id=1ecmztnWgwlrTFrq_X4WlnNkJLtqUclRi  Time complexity analysis

void SortedStack :: sort()
{
    // 1. Take a helper stack that will always be sorted
    stack<int> helper;
    
    while(!s.empty()){
        
        int cur=s.top();
        s.pop();
        
        // 2. Pop from helper stack till it's top is greater than curr element or it's not empty
        while(!helper.empty() && helper.top()>cur){
            
            int element=helper.top();
            helper.pop();
            
            // 3. Push it to original stack
            s.push(element);
            
        }
        
        // 4. Now we can push current element to helper stack and it will remain sorted
        helper.push(cur);
    }
    s=helper;  // Deep copy vs shallow copy
}
