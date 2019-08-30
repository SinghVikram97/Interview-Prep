https://leetcode.com/problems/gas-station/

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        
        int totalGas=0;
        
        int n=gas.size();
        
        for(int i=0;i<n;i++){
            totalGas+=gas[i];
        }
        
        int totalCost=0;
        
        for(int i=0;i<n;i++){
            totalCost+=cost[i];
        }
        
        if(totalGas<totalCost){
            return -1;
        }
        
        int start=0,tank=0;
        
        for(int i=0;i<n;i++){
            
            tank=tank+gas[i]-cost[i];
            
            if(tank<0){
                
                tank=0;
                start=i+1;
                
            }
            
            
        }
        
        return start;
        
    }
};
