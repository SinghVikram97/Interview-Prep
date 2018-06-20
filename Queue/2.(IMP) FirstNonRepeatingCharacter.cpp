https://practice.geeksforgeeks.org/problems/first-non-repeating-character-in-a-stream/0

https://drive.google.com/open?id=1hd2xVMX_lm8xXh94rK2INoP7BhXpMtPV

Time complexity???

#include <bits/stdc++.h>
using namespace std;

int main() {

    int t;
    cin>>t;
    while(t--){
        
        int n;
        cin>>n;
        
        vector<char> ch(n);
        
        for(int i=0;i<n;i++){
            cin>>ch[i];
        }
        
        int freq[26];
        
        for(int i=0;i<26;i++){
            
            freq[i]=0;
        }
        
        queue<char> q;
        
        for(int i=0;i<n;i++){
            
            // Increase frequency of current element
            freq[ch[i]-'a']++;
            
            // Push it into the queue
            q.push(ch[i]);
            
            while(!q.empty()){
                
                // Try element in front of the queue
                
                // If it's frequency>1 it can't be non repeating pop it out and try next one
                if(freq[q.front()-'a']>1){
                    q.pop();
                }
                // Freq=1 so print and break
                else{
                    cout<<q.front()<<" ";
                    break;
                }
                
            }
            // Can't find any non repeating character
            if(q.empty()){
                cout<<-1<<" ";
            }
            
        }
        cout<<endl;
    }
	
}
