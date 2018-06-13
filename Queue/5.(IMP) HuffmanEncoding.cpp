https://practice.geeksforgeeks.org/problems/huffman-encoding/0

https://drive.google.com/open?id=1vGXVavmEHNT50KOrZRivjNRu-iVH6oSG
https://drive.google.com/open?id=1eMHQbeVtFGO6Js8SkjvGBAqs6Swy8Pq-
https://drive.google.com/open?id=1blCZXilFVJpcn4CtgBtWZZYckvLQX8HO
https://drive.google.com/open?id=1z1CpwsxSunYZ1uOsR9rpPXNZDJtZE26b  (TIME COMPLEXITY)

#include<bits/stdc++.h>
using namespace std;
class Node{

    public:

        int freq;
        char data;
        Node *left;
        Node *right;


        Node(char data,int frequency){

            data=data;
            freq=frequency;
            left=NULL;
            right=NULL;

        }


};
class cmp{

    public:
        bool operator() (const Node *p1,const Node *p2){

            return (p1->freq)>(p2->freq);  /// Min heap

        }
};
void huffman_tree(priority_queue<Node *,vector<Node *>,cmp > &pq){


    while(pq.size()!=1){

        /// Take out 2 min node
        Node *first=pq.top();
        pq.pop();
        Node *second=pq.top();
        pq.pop();

        /// Make a newNode and assign first to it's left and second to right
        Node *newNode=new Node('@',first->freq+second->freq);
        newNode->left=first;
        newNode->right=second;

        /// Push this newNode to queue
        pq.push(newNode);

    }

}
void preorder(Node *root,string s){


    if(root==NULL){

        return;
    }
    /// Leaf node
    if(root->right==NULL && root->left==NULL){

        cout<<s<<" ";
        return;

    }


        preorder(root->left,s+"0");
        preorder(root->right,s+"1");


}
int main(){

    int t;
    cin>>t;
    while(t--){

        priority_queue<Node *,vector<Node *>,cmp > pq;  /// Not Node because Node on heap memory (dynamic) can acess it only by a pointer

        string str;
        cin>>str;
        int f;

        for(int i=0;i<str.length();i++){

            cin>>f;
            Node *newNode=new Node(str[i],f);
            pq.push(newNode);

        }

        huffman_tree(pq);

        preorder(pq.top(),"");
        
        cout<<endl;

    }

}
