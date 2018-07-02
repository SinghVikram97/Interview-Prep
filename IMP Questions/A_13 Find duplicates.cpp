https://practice.geeksforgeeks.org/problems/find-duplicates-in-an-array/1

https://drive.google.com/open?id=1AXXwGEv7BeimAZMqwYrULShkyw-RJ3fc
https://drive.google.com/open?id=1h6xZHOEW6pa8cx1hktE8JK9Q-Ynpb2qM
https://drive.google.com/open?id=1Ailh1gDnlCEvPff20raVdEZFJQ9qkS7b
https://drive.google.com/open?id=1KTvUKQ_r7rKdAvl78RTsGZXenvt8TXUB

void printDuplicates(int v[], int n)
{
   // Traverse the array
   for(int i=0;i<n;i++){
        
        // Increase the value at index v[i]%n by n
        int index=v[i]%n;
        v[index]+=n;
               
   }
   // Traverse again and print those indices for which v[i]/n>1
   bool allDistinct=true;
   for(int i=0;i<n;i++){
       
       if((v[i]/n)>1){
           cout<<i<<" ";
           allDistinct=false;
       }
   }
   if(allDistinct){
       cout<<-1;
   }
}
