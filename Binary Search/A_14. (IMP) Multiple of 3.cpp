https://drive.google.com/open?id=1BniW-PpaEA9k265PaZKVnZrHtw5NKEJV

https://practice.geeksforgeeks.org/problems/is-binary-number-multiple-of-3/0

bool isMultiple(string &s){
    
    int evenCount=0;
    int oddCount=0;
    
    // Traverse over bits of the number
    for(int i=0;i<s.length();i++){
        
        if(s[i]=='1' && i%2==0){
            evenCount++;
        }
        else if(s[i]=='1' && i%2!=0){
            oddCount++;
        }
    }
    if(abs(evenCount-oddCount)%3==0){
        return true;
    }
    else{
        return false;
    }
}
