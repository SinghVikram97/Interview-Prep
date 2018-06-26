https://drive.google.com/open?id=1eg6SjcA_KemPaz0V1zzPJa0tL9OHAU7H

void setBit1(int a,int i)
{
    /// Right shift i times
    a=a>>i;
    /// And with 1
    if(a&1)
    {
        cout<<"Bit is set"<<endl;
    }
    else
    {
        cout<<"Bit is not set"<<endl;
    }
    return;
}
void setBit2(int a,int i)
{
    /// Left swift 1 i times
    int temp=1<<i;
    /// And with given number
    if(a&temp)
    {
        cout<<"Bit is set"<<endl;
    }
    else
    {
        cout<<"Bit is not set"<<endl;
    }
    return;
}
