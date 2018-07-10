https://leetcode.com/problems/merge-intervals/description/

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
bool myComp(const Interval &s1,const Interval &s2){
    // returns true if we want to place s1 before s2
    if(s1.start<s2.start){
        return true;
    }
    else{
        return false;
    }
}
class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        
        int n=intervals.size();
        // Empty 
        if(n==0){
            return vector<Interval>{};
        }
        vector<Interval> ans;
        sort(intervals.begin(),intervals.end(),myComp); // Sort
        ans.push_back(intervals[0]);
        for(int i=1;i<n;i++){
            
            Interval s1=ans[ans.size()-1];
            Interval s2=intervals[i];
            
            if(s2.start>s1.end){
                // No overlap just push
                ans.push_back(Interval(s2.start,s2.end));
            }
            else{
                // Overlap so change interval to [s1.start,max(s1.end,s2.end)]
                // ans.pop_back();
                // ans.push_back(Interval(s1.start,max(s1.end,s2.end)));
                ans.back().end=max(ans.back().end,s2.end);
            }
        }
        return ans; 
    }
};
