#include "head.h"

//template <class T>
//int get_len(T arr[])
//{
//    cout<<sizeof(T)<<endl;
//    return sizeof(arr)/sizeof(T);
//}

template <class T>
void Swap(T &a,T &b)
{
    T temp=a;
    a=b;
    b=temp;
}

template <class T>
void SelectionSort(T arr[],int len)
{
    int i=0;
    for(;i<len;i++)
    {
        int j=i;
        int MIN=i;

        for(;j<len;j++)
        {
            if(arr[j]<arr[MIN])//确定最小值下标
            {
                MIN=j;
            }
        }
        Swap(arr[MIN],arr[i]);
    }
}

template <class T>
void print(T arr[],int len)
{
    int i=0;
    for(;i<len;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void SelS_test()
{
    int arr[]={1,4,52,235,12,415,246,5643,636,6,363,7457};
    char ch[]="asdhaosdhauicabg";

//    SelectionSort(arr,sizeof(arr)/sizeof(int));
    SelectionSort(ch,sizeof(ch)/sizeof(char)-1);//sizeof会计算'\0'，-1去掉'\0'

//    print(arr,sizeof(arr)/sizeof(int));
    print(ch,sizeof(ch)/sizeof(char)-1);

}
