https://practice.geeksforgeeks.org/problems/anagram/0

https://drive.google.com/open?id=1EJynE3wbSAfWnM29RIazzmyBaBvKolow Sorting and hashmap

bool anagram(string s1,string s2){
    
    if(s1.length()!=s2.length()){
        return false;
    }
    int n=s1.length();
    unordered_map<char,int> freq;
    for(int i=0;i<n;i++){
        freq[s1[i]]++;
        freq[s2[i]]--;
    }
    for(auto count:freq){
        if(count.second){
            return false;
        }
    }
    return true;
}
