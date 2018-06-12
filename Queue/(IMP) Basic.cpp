https://practice.geeksforgeeks.org/problems/implement-queue-using-linked-list/1

https://drive.google.com/open?id=1W7FiWkmW5C2KMyzwdBeCnws57-nJzpmC

#include<bits/stdc++.h>
using namespace std;
template<typename T>
class Queue{

    public:

        bool empty();
        void push(const T &x);
        T pop();
        void print();
        bool isEmpty();

        /// Constructor
        Queue();

    private:
        struct Node{

            T data;
            Node *next;

            /// Constructor
            Node(T newData){
                data=newData;
                next=NULL;
            }

        };

      Node *Front;
      Node *Rear;
      int size;

};
template<typename T>
Queue<T>::Queue(){

    Front=NULL;
    Rear=NULL;
    size=0;

}
template<typename T>
void Queue<T>::push(const T &x){


    size++;

    /// Empty Queue
    /// Or Rear==NULL
    if(Front==NULL){

        Node *newNode=new Node(x);
        Front=newNode;
        Rear=newNode;
    }

    /// Otherwise insert to rear
    else{

        Node *newNode=new Node(x);
        Rear->next=newNode;
        Rear=newNode;

    }

}
template<typename T>
T Queue<T>::pop(){

    /// Empty Queue
    if(Front==NULL){

      cout<<"Empty Queue"<<endl;
      return -1;

    }
    else{

        size--;
        Node *temp=Front;
        Front=Front->next;

        /// If front becomes NULL it means only 1 element was present so set rear to null
        if(Front==NULL){

            Rear=NULL;

        }

        T data=temp->data;
        delete temp;
        return data;

    }

}
template<typename T>
bool Queue<T>::isEmpty(){

    if(size==0){

        return true;
    }
    else{

        return false;

    }

}
template<typename T>
void Queue<T>::print(){

    if(Front==NULL){

        cout<<"Empty Queue"<<endl;
        return;

    }

    /// From front to rear print
    Node *temp=Front;
    while(temp!=NULL){

        cout<<temp->data<<"-->";
        temp=temp->next;

    }

    cout<<endl;

    return;

}
int main(){


   Queue<int> myQueue;
   char choice;

   do{

    cout<<"What would you like to do"<<endl;
    cout<<"1. Push"<<endl;
    cout<<"2. Pop"<<endl;
    cout<<"3. Print"<<endl;

    int option;
    cin>>option;

    if(option==1){

        cout<<"Enter data ";
        int data;
        cin>>data;
        myQueue.push(data);

    }
    else if(option==2){

       cout<<"Data deleted from Queue is: "<<myQueue.pop()<<endl;

    }
    else if(option==3){

        myQueue.print();

    }

    cout<<"Do you want to continue ";
    cin>>choice;

   } while(choice=='Y' || choice=='y');

}
