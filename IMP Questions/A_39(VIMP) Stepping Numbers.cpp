Given a positive number and you have to find all the no. that holds the property of all the digits
with absolute difference equal to 1 to its adjacent digit below that given number.

https://practice.geeksforgeeks.org/problems/stepping-numberswrong-output/0

https://drive.google.com/open?id=1FHhrUlnm5Yg2DKbwHOZP_0IudKU6jWc3
https://drive.google.com/open?id=1xreYLbAj7ySzvUtrqEh8T4mgcDP1hwJD ALGO

BRUTE FORCE-> CHECK EVERY NO FROM N TO M WHETHER IT IS A STEPPING NUMBER

void bfsHelper(int startVertex,int n,int m,int &count){
    
    queue<int> q;
    q.push(startVertex);
    
    while(!q.empty()){
        
        int stepNum=q.front();
        q.pop();
        
        // If stepNum>=n and stepNum<=m increase the count
        if(stepNum>=n && stepNum<=m){
            count++;
        }
        
        // If stepNum is zero or >m don't generate other stepNums from it
        if(stepNum==0 || stepNum>m){
            continue;
        }
        
        // Else generate stepNums from given stepNum
        
        // Find the last digit
        int lastDigit=stepNum%10;
        
        if(lastDigit!=0){
            // Subtract 1
            q.push((stepNum*10)+(lastDigit-1));
        }
        
        if(lastDigit!=9){
            q.push((stepNum*10)+(lastDigit+1));
        }
    }
    
}
int bfs(int n,int m){
    
    // Start from 0 to 9 and generate stepping numbers
    // For 0 don't find any neighbour as 0 will generate 01 which is already taken care of
    int count=0;
    for(int i=0;i<=9;i++){
        
        bfsHelper(i,n,m,count);
        
    }
    return count;
}

