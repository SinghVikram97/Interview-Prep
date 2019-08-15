https://leetcode.com/problems/largest-rectangle-in-histogram/

O(N)

How To Understand The Algorithm? Let Me Explain The Intuition:

For the convenience of understanding, let's first assume the heights of each bar is unique.

Let's draw the stack from left to right horizontally. For an index being popped out from the stack, let's name the corresponding bar as "UPPERBOUND". Suppose there is at least two elements in the stack. For the index stored in the stack but left to the stack top, let's name the corresponding bar as "LEFTBOUND". For the index which triggers the popping, let's name the corresponding bar as "RIGHTBOUND".

Obviously, "LEFTBOUND"<"UPPERBOUND", because the heights of bars corresponding to the stack elements are in increasing order.

Obviously, "RIGHTBOUND"<"UPPERBOUND", because otherwise it will not trigger the pop operation.

In the original graph, all bars between the "LEFTBOUND" and "RIGHTBOUND" are higher than "LEFTBOUND". Because otherwise the index of "LEFTBOUND" would have already been popped out by the bar shorter than "LEFTBOUND", before we reach the "LEFTBOUND".

I claim the "UPPERBOUND" bar is the shortest among those bars right to "LEFTBOUND" and also left to "RIGHTBOUND". Because otherwise, by proof for contradiction, suppose the bar between "LEFTBOUND" and "RIGHTBOUND" but shorter than "UPPERBOUND" is named by "NONSENSE". If "NONSENSE" is left to "UPPERBOUND", then we should find the index of "NONSENSE" right to the index of "LEFTBOUND" in the stack, i.e. the stack looks like [bottom,.....,idOf"LEFTBOUND",....idOf"NONSENSE",....,idOf"UPPERBOUND"]. But actually the index of "LEFTBOUND" is directly left to that of "UPPERBOUND". Nowhere to store the index of "NONSENSE" in the stack! The "NONSENSE" also cannot be right to "UPPERBOUND", because otherwise the index of "UPPERBOUND" would have already been popped out by the "NONSENSE" before we reach "RIGHTBOUND". OK, that is why "UPPERBOUND" is the shortest bar among those bars which are left to "LEFTBOUND" and also right to "RIGHTBOUND". No such a "NONSENSE" could exist.

When we pop out the index of "UPPERBOUND", we actually find a rectangle, the left boundary of which is "LEFTBOUND"(exclusive), the right boundary of which is "RIGHTBOUND" (exclusive), the upper boundary of which is "UPPERBOUND". Note that the rectangle can not extend its area to left/right/up direction, because the height of the rectangle is limited by "UPPERBOUND", the leftside is limited by "LEFTBOUND"<"UPPERBOUND", the rightside is limited by "RIGHTBOUND"<"UPPERBOUND". Also, note that in this rectangle there is no bar shorter than "UPPERBOUND", so such a rectangle does exists.

The area of this rectangle is height*width = "UPPERBOUND" * [(index of "RIGHTBOUND")-(index of "LEFTBOUND")-1]. Correspondingly in Tusher's code, the area is input[top]*(i-stack.peekFirst()-1).

In general, All elements in the stack (except the stack top) are potential "LEFTBOUND". All bars that are pop operations triggers can be some "RIGHTBAR". All elements being popped out can be some "UPPERBOUND".

By using the stack, we can find all such un-extendable rectangles efficiently. Choose the maximum of them.

If we allow heights of some bar to be equal, then we might find some "extendable" rectangles, as its "LEFTBOUND" or "RIGHTBOUND" should not be limited by its neighbor with the same height. But it doesn't affect the correctness, because we take the maximum of all candidates.
 
class Solution {
public:
    int largestRectangleArea(vector<int>& hist) {
        
        if(hist.size()==0){
            return 0;
        }
        
        if(hist.size()==1){
            return hist[0];
        }
       
        stack<int> s;
        
        int tp;
        
        int i=0;
        
        int max_area=0;
        
        int area_with_top;
        
        
        int n=hist.size();
        
        while(i<n){
            
            
            // If this bar is higher than the bar on top  
        // stack, push it to stack 
        if (s.empty() || hist[s.top()] <= hist[i]) 
            s.push(i++); 
  
        // If this bar is lower than top of stack,  
        // then calculate area of rectangle with stack  
        // top as the smallest (or minimum height) bar.  
        // 'i' is 'right index' for the top and element  
        // before top in stack is 'left index' 
        else
        { 
            tp = s.top();  // store the top index 
            s.pop();  // pop the top 
  
            // Calculate the area with hist[tp] stack  
            // as smallest bar 
            area_with_top = hist[tp] * (s.empty() ? i :  
                                   i - s.top() - 1); 
  
            // update max area, if needed 
            if (max_area < area_with_top) 
                max_area = area_with_top; 
        } 
            
            
            
        }
        
        while (s.empty() == false) 
    { 
        tp = s.top(); 
        s.pop(); 
        area_with_top = hist[tp] * (s.empty() ? i :  
                                i - s.top() - 1); 
  
        if (max_area < area_with_top) 
            max_area = area_with_top; 
    } 
  
    return max_area; 
    }
};

