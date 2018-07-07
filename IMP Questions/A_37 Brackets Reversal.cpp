https://practice.geeksforgeeks.org/problems/count-the-reversals/0

https://drive.google.com/open?id=1FUDAg9TEV8BOr1jADXEJ7s7cBe1afB0Y

int reversals(string b){
    
    stack<char> s;
    // Remove balanced paranthesis
    for(int i=0;i<b.length();i++){
        // Simply push '{'
        if(b[i]=='{'){
            s.push(b[i]);
        }
        else{
            
            // Balanced bracket found '{}'
            if(!s.empty() && s.top()=='{'){
                s.pop();
            }
            // Push '}'
            else{
                s.push(b[i]);
            }
            
        }
    }
    int count1=0,count2=0;
    // Count1 for '{' and count 2 for '}'
    while(!s.empty()){
        if(s.top()=='{'){
            count1++;
        }
        else{
            count2++;
        }
        s.pop();
    }
    // Only possible if total count of unbalanced brackets is even
    if((count1+count2)%2==0){
        
        // Arrange { among then -> count1/2
        // Arrange } among then -> count2/2
        // Remaining will always be 1 '}'' and 1 '{' ie. }{  which requires 2 reversals
        // Can't be a case where only '}' or '{' remains because it would mean count1+count2 both odd
        // So remaining case only if both count2 odd, odd+odd=even
        return count1/2+count2/2+((count1%2!=0)?2:0);
        
    }
    else{
        return -1;
    }
}
