#include<bits/stdc++.h>
using namespace std;
template<typename T>
class List{

  public:
        List();   /// Constructor
        int getSize();
        void insertAtFront(T data);
        void insertAtBack(T data);
        void deleteFromFront();
        void deleteFromBack();
        void printList();

  private:
        struct listNode{

            T data;
            listNode *next;
            /// Parametrized constructor
            listNode(T newdata){

              data=newdata;
              next=NULL;

            }

        };

        listNode *head;
        int sizeOfList;

};

template<typename T>
List<T>::List(){

    head=NULL;
    sizeOfList=0;

}

template<typename T>
void List<T>::insertAtFront(T data){

    sizeOfList++;
    listNode *newNode=new listNode (data);  /// By default it's next is null

    /// Empty list
    if(head==NULL){

        head=newNode;

    }
    else{

        newNode->next=head;
        head=newNode;

    }
}


template<typename T>
void List<T>::insertAtBack(T data){

   sizeOfList++;
   listNode *newNode=new listNode(data);


   if(head==NULL){

       head=newNode;

   }

   else{

      listNode *temp=head;
      while(temp->next!=NULL){

        temp=temp->next;

      }

      temp->next=newNode;

   }

}

template<typename T>
void List<T>::deleteFromFront(){


    /// List is empty
    if(head==NULL){

        cout<<"List is empty";
        return;

    }
    else{

        listNode *temp;
        temp=head;
        head=head->next;
        delete temp;

    }

    sizeOfList--;
}

template<typename T>
void List<T>::deleteFromBack(){


    /// List is empty
    if(head==NULL){

        cout<<"List is empty";
        return;

    }

    sizeOfList--;

    listNode *temp=head;
    listNode *prev=NULL;


    while(temp->next!=NULL){

        prev=temp;
        temp=temp->next;

    }


    /// Single Node
    if(prev==NULL){

        listNode *temp=head;
        head=NULL;
        delete temp;

    }
    else{

        prev->next=NULL;
        delete temp;

    }

}

template<typename T>
void List<T>::printList(){

    listNode *temp=head;

    while(temp!=NULL){

        cout<<temp->data<<"-->";
        temp=temp->next;

    }
    cout<<endl;

}

template<typename T>
int List<T>::getSize(){

    return sizeOfList;

}


int main(){

   List<int> linkedList;
   char choice;



   do{

    cout<<"What would you like to do"<<endl;
    cout<<"1. InsertAtFront"<<endl;
    cout<<"2. InsertAtBack"<<endl;
    cout<<"3. DeleteFromFront"<<endl;
    cout<<"4. DeleteFromBack"<<endl;
    cout<<"5. Print List"<<endl;
    cout<<"6. Get Size"<<endl;
    int option;
    cin>>option;

    if(option==1){

        cout<<"Enter data ";
        int data;
        cin>>data;
        linkedList.insertAtFront(data);

    }
    else if(option==2){

       cout<<"Enter data ";
       int data;
       cin>>data;
       linkedList.insertAtBack(data);

    }

    else if(option==3){


        linkedList.deleteFromFront();

    }

    else if(option==4){

        linkedList.deleteFromBack();

    }

    else if(option==5){

        linkedList.printList();

    }
    else if(option==6){

        cout<<linkedList.getSize()<<endl;

    }


    cout<<"Do you want to continue ";
    cin>>choice;

   } while(choice=='Y' || choice=='y');


}
