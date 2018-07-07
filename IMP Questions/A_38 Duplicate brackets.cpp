https://www.geeksforgeeks.org/find-expression-duplicate-parenthesis-not/

https://drive.google.com/open?id=10qaQ2uMpue9UZYjR258PGk9fTixSqtex What is a duplicate bracket
https://drive.google.com/open?id=1pjuhzcmDrZRZ3jriaTJRvtoBzuxFEHcD Algo

bool isDuplicate(string b){
    
    // Assume brackets are balanced
    
    stack<char> s;
    
    for(int i=0;i<b.length();i++){
        
        // If a ')' encountered
        if(b[i]==')'){
            
            // If immediately we encounter a '(' it means no expression b/w them so duplicate
            if(s.top()=='('){
                return true;
            }
            // Else pop till we encounter a '('
            while(s.top!='('){
                s.pop();
            }
            s.pop(); // For '('
        }
        // If '(' operator operand encountered push to stack
        else{
            s.push(b[i]);
        }
    }
    // No duplicates found
    return false;
}
