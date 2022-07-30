#include<iostream>
using namespace std;

template<typename T>
void asc_bubble_sort(T *a,int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n-1-i;j++)
        {
            if(a[j]>a[j+1])
            {
                T t=a[j];
                a[j]=a[j+1];
                a[j+1]=t;
            }
        }
    }
}

int main()
{   cout<<"1.Integer"<<"\n";
    cout<<"2.Float"<<"\n";
    cout<<"3.Character"<<"\n";
    cout<<"4. Structure"<<"\n";
    

    int c;
    cin>>c;
    switch(c){
        
    case 1:{
    int a[10]={10,1,2,3,4,5,6,7,8,9};
    cout<<"Before Sorting:";
    for(int i=0;i<10;i++)
    {
        cout<<a[i]<<endl;
    }
    asc_bubble_sort<int>(a,10);
    cout<<"After applying bubble sort:";
    for(int i=0;i<10;i++)
    {
        cout<<a[i]<<endl;
    }}
    break;
    case 2:{
        
    

    float b[10]={10,1,2,3,4,5,6,7,8,9};
    cout<<"Before Sorting:";
    for(int i=0;i<10;i++)
    {
        cout<<b[i]<<endl;
    }
    asc_bubble_sort<float>(b,10);
    cout<<"After applying bubble sort:";
    for(int i=0;i<10;i++)
    {
        cout<<b[i]<<endl;
    }}
    break;
    case 3:{
        
    

    char c[10]={'q','r','p'};
    cout<<"Before Sorting:";
    for(int i=0;i<3;i++)
    {
        cout<<c[i]<<endl;
    }
    asc_bubble_sort<char>(c,3);
    cout<<"After applying bubble sort:";
    for(int i=0;i<3;i++)
    {
        cout<<c[i]<<endl;
    }}
    break;
    case 4:
    {
        cout<<"Not working"<<"\n";
    }
    break;}}