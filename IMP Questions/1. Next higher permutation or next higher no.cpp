https://practice.geeksforgeeks.org/problems/next-permutation/0  

CAN ALSO BE DONE WITH STL LOOK IN STL FOLDER


https://drive.google.com/open?id=10kzPnOC3FSc3p37ThZOyJUUoGU9cgqAQ
https://drive.google.com/open?id=1MYcUHKmu-E_3SsYg56hlqF-6YJQZEjwq
https://drive.google.com/open?id=1Ak98vhNEvpSn-UeJ8n1QfguIpAd7IXEw

void nextPermutation(vector<int> v){
    
    int n=v.size();
    // 1.Find a no such that it is less than it's next element starting from end
    int swapPos1=-1;
    for(int i=n-1;i>=1;i--){
        if(v[i-1]<v[i]){
            swapPos1=i-1;
            break;
        }
    }
    
    // 2. If we can't find this no then it means numbers are arranged in descending order 3 2 1
    if(swapPos1==-1){
        // Output in ascending order
        for(int i=n-1;i>=0;i--){
            cout<<v[i]<<" ";
        }
        return;
    }
    
    // 3. Find smallest no greater than this no from (swapPos1)+1 till the end
    int swapPos2=-1;
    for(int i=swapPos1+1;i<n;i++){
        if(v[i]>v[swapPos1]){
            
            if(swapPos2==-1){
                swapPos2=i;
            }
            else{
                if(v[i]<v[swapPos2]){
                    swapPos2=i;
                }
            }
        }
    }
    
    // 4. Swap these 2 number
    swap(v[swapPos1],v[swapPos2]);
    
    // 5. Now sort/reverse numbers from swapPos1+1 til end
    reverse(v.begin()+swapPos1+1,v.end());
    
    // 6. Print the number
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }   
}
