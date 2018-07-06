 1. Min heap of integers--->priority_queue<int,vector<int>,greater<int> > pq;
 
 2. Min heap of pair-----> priority_queue<pair<int,int> ,vector<pair<int,int> > ,greater<pair<int,int> > pq;
 
 
 3. Max Heap of a struct
    struct matElement{

    int value;
    int row;
    int col;

    matElement(int v,int r,int c){

        value=v;
        row=r;
        col=c;
    }

    bool operator < (const matElement &m) const{
            /// Max heap, for min do value>m.value
            if(value<m.value){
                return true;
            }
            else{
                return false;
            }
    }
  };
  int main(){

    priority_queue< matElement> pq;
    pq.push(matElement(10,0,0));
    pq.push(matElement(20,0,1));
    pq.push(matElement(15,1,0));
    cout<<pq.top().value;
  }
