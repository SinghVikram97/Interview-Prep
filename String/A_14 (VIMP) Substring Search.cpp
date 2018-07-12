https://leetcode.com/problems/implement-strstr/description/

USING STL
.........................................
int strStr(string text, string pattern) {
        return text.find(pattern);
}
.........................................

USING KMP

https://drive.google.com/open?id=1-E13C7AiFjhXtxIRJ0hanFD5Yv2Ukkd5 (Intuition)
https://drive.google.com/open?id=1VEpmfCx-H-HQPBHpGiMGb6Vg70p38kGU (What is proper prefix suffix)
(LPS) ------> https://www.youtube.com/watch?v=tWDUjkMv6Lc&
https://drive.google.com/open?id=1OoQ5RPvOZRdsqL9MPsmQ74yQ8wg09SLw
https://drive.google.com/open?id=1uHcLMng775TM5mA6JHq-W63E8vdGwPN9
https://drive.google.com/open?id=1TpA1o3-dzHdgn06U-kI_45R9JJX93RvB
https://drive.google.com/open?id=1v_5RwUezeifjTit89A6tRX6ttROvJJ__
https://drive.google.com/open?id=1bKpUmsrtcCqKJCIG5LZVBgV1QNgNCika
(Index of substring)
https://drive.google.com/open?id=103KLaHmxJBBuIER-3an-wJnEL0Zpro03
.........................................
#include<bits/stdc++.h>
using namespace std;
void fillLps(string &s,vector<int> &lps) {

    int n=s.length();

    // Single character lps=0
    lps[0]=0;

    // Current index
    int i=1;

    // j is length of longest prefix till i-1
    int j=0;

    while(i<n) {

        // Increase the longest prefix length
        if(s[i]==s[j]) {
            lps[i]=j+1;
            j++;
            i++;
        }
        // Find next longest prefix
        else {
            if(j!=0) {
                j=lps[j-1];
            }
            else {
                // No choice left
                lps[i]=0;
                i++;
            }
        }
    }
}
int strStr(string text, string pattern) {


    int n=text.length();
    int m=pattern.length();

    if(m==0) {
        // Pattern empty
        return 0;
    }

    if(n==0) {
        return -1;
    }

    vector<int> lps(m);
    fillLps(pattern,lps);

    int i=0,j=0;

    while(i<n && j<m) {

        // Match
        if(text[i]==pattern[j]) {
            i++;
            j++;
        }
        else {

            // Start matching from same i and from next index of lps of substring till j-1
            if(j!=0) {
                j=lps[j-1];
            }
            else {
                // Still doesn't match then increase i
                i++;
            }
        }
    }

    if(j==m) {
        // Substring of length m found in text
        return i-m;
    }
    else {
        return -1;
    }
}

int main() {
    string text,pattern;
    cin>>text>>pattern;
    cout<<strStr(text,pattern);
}
.............................................
