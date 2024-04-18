https://practice.geeksforgeeks.org/problems/first-non-repeating-character-in-a-stream/0

https://drive.google.com/open?id=1hd2xVMX_lm8xXh94rK2INoP7BhXpMtPV

class Solution {
	public:
		string FirstNonRepeating(string A){
		    vector<int> freq(26);
		    int n = A.length();
		    
		    string ans="";
		    
		    queue<char> mq;
		    
		    for(int i=0;i<n;i++){
		        freq[A[i]-'a']++;
		        
		        if(freq[A[i]-'a']==1){
		            mq.push(A[i]);
		        }
		        
		        while(!mq.empty() && freq[mq.front()-'a']>1){
		            mq.pop();
		        }
		        
		        if(!mq.empty()){
		            ans+=mq.front();
		        }else{
		            ans+="#";
		        }
		    }
		    
		    return ans;
		    
		}

};
