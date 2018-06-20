https://practice.geeksforgeeks.org/problems/equilibrium-point/0

https://drive.google.com/open?id=10DFcvBwQsP0eetKPsN4gBeOMl1oAghGF

Brute Force-O(n^2)
int equilibriumPoint(vector<int> &v,int n){
    
    int sum_before=0;
    int sum_after;
    
    for(int i=0;i<n;i++){
        
        // Select i as equillirbrium point
        sum_after=0;
        for(int j=i+1;j<n;j++){
            
            sum_after+=v[j];
            
        }
        
        if(sum_after==sum_before){
            return i+1; //Index
        }
        else{
            
            // Add this element to sum_before of next element
            sum_before+=v[i];
            
        }
    }
    return -1;
}


O(N) solution

int equilibriumPoint(vector<int> &v,int n){
    
   int total_sum=0;
   
   for(int i=0;i<n;i++){
       total_sum+=v[i];
   }
   
   
   int sum_before=0;
   int sum_after;
   
   for(int i=0;i<n;i++){
       
       // For given i sum_after=total_sum-v[i]-sum_before
       sum_after=total_sum-v[i]-sum_before;
       
       if(sum_before==sum_after){
           return i+1; // 1 based indexing
       }
       
       // Else add this element to next element's sum_before
       else{
           sum_before+=v[i];
       }
   }
   return -1;
}
