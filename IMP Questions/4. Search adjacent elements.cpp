https://www.geeksforgeeks.org/search-an-element-in-an-array-where-difference-between-adjacent-elements-is-1/

https://drive.google.com/open?id=1y0tOKIzSmv-yWSGuIKQf8VErt-jDjMqt

int modifiedSearch(vector<int> v,int target){

    int i=0;
    int diff;
    int n=v.size();

    while(i<n && v[i]!=target){

        diff=abs(v[i]-target);

        i=i+diff;

    }

    if(i>n){

        return -1;

    }
    else{

        return i;

    }

}


GENERALIZED CASE(IMP)
https://www.geeksforgeeks.org/searching-array-adjacent-differ-k/

Move by diff/k

int modifiedSearch(vector<int> v,int target,int k){

    int i=0;
    int diff;
    int n=v.size();

    while(i<n && v[i]!=target){

        diff=abs(v[i]-target);
        
        i=i+max(1,(diff/k));  // 1 to ensure it moves by atleast once if diff<k  
        https://drive.google.com/open?id=18I8tur4mdUo4RI1q9r-qChIj2WJ5p9NB

    }

    if(i>n){

        return -1;

    }
    else{

        return i;

    }

}
