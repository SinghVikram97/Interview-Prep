https://practice.geeksforgeeks.org/problems/check-if-string-is-rotated-by-two-places/0/?track=Placement

https://drive.google.com/open?id=1OvQxYfWYqpoHwA_ryr1rBM9N-1WvR15k

bool canChange(string &a,string &b){
    
    int lengthB=b.length();
    // If by right rotating B if we obtain a
    string temp=b.substr(lengthB-2,2)+b.substr(0,lengthB-2);
    if(temp==a){
        return true;
    }
    // Else by left rotating
    temp=b.substr(2,lengthB-2)+b.substr(0,2);
    if(temp==a){
        return true;
    }
    else{
        return false;
    }
}
