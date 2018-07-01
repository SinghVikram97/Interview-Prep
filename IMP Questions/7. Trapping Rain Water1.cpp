https://leetcode.com/problems/trapping-rain-water/

https://drive.google.com/open?id=1lbCD2ohEE1P4FbPxbgv0R4_a11jbWOJZ

O(N) TIME O(N) SPACE

class Solution {
public:
    int trap(vector<int> &height) {
        
        int n=height.size();
        cout<<n<<endl;
        
        vector<int> left(n);  // Stores maximum on left
        vector<int> right(n); // Stores maximum on right
        
        int max_left=0;
        for(int i=0;i<n;i++){
            max_left=max(max_left,height[i]);  (Why height[i] ie. itself is included https://drive.google.com/open?id=1OqLPJFAdS7Ngx7mQTtxBiisVVeP5J8Wh )
            left[i]=max_left;
        }
        
        int max_right=0;
        for(int i=n-1;i>=0;i--){
            max_right=max(max_right,height[i]);
            right[i]=max_right;
        }
        
    
        int ans=0;
        
        for(int i=0;i<n;i++){
            
            ans=ans+(min(left[i],right[i])-height[i]);
            
        }
        
        return ans;
    }
};
