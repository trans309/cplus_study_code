#include <iostream>

using namespace std;

template<class T=int>
class my_array
{
public:

    my_array(int capacity);
    my_array(my_array<T>& arr);
    my_array<T>& operator=(my_array<T>& arr);

    ~my_array();

    void push_end(T i);
    void pop_end();
    void find_elem();

    void print();


private:

    T* parr;
    int m_capacity;//����
    int m_size;//��С

    T* cur;
};

template<class T>
my_array<T>::my_array(int capacity)
{
    parr=new T[capacity];
    cur=parr;
    this->m_size=0;
    this->m_capacity=capacity;

//    cout<<"����"<<endl;

//    for(int i=0;i<10;i++)
//    {
//        *(this->parr)=i;
//    }
//    for(int j=0;j<10;j++)
//    {
//        cout<<this->parr[j]<<" ";
//    }
}

template<class T>
my_array<T>::~my_array()
{
    if(this->parr != NULL)
    {
        delete[] this->parr;
        this->parr=NULL;
    }

//    cout<<"����"<<endl;
}

template<class T>
my_array<T>::my_array(my_array<T>& arr)
{
    if(this->parr!=NULL)
    {
        this->cur=NULL;
        this->parr=NULL;
        this->m_size=0;
        this->m_capacity=0;
    }

    parr=new T[arr.m_capacity];
    cur=parr;
    this->parr=arr.parr;
    this->m_size=arr.m_size;
    this->m_capacity=arr.m_capacity;

    for(int i=0;i<this->m_size;i++)
    {
        this->parr[i]=arr.parr[i];
    }

//    cout<<"��������"<<endl;

//        for(int i=0;i<10;i++)
//    {
//        cout<<this->parr[i]<<" ";
//    }
}

template<class T>
my_array<T>& my_array<T>::operator=(my_array<T>& arr)
{
    if(this->parr!=NULL)
    {
        this->cur=NULL;
        this->parr=NULL;
        this->m_size=0;
        this->m_capacity=0;
    }

    parr=new T[arr.m_capacity];
    cur=parr;
    this->parr=arr.parr;
    this->m_size=arr.m_size;
    this->m_capacity=arr.m_capacity;

    for(int i=0;i<this->m_size;i++)
    {
        this->parr[i]=arr.parr[i];
    }

//    cout<<"����=����"<<endl;

    return *this;
}

template<class T>
void my_array<T>::push_end(T i)
{
    if(this->m_size >= this->m_capacity)
    {
        //�������������¿ռ�
        this->m_capacity+=5;
        T* newspace=new T[this->m_capacity];
        T* cur1=newspace;

        //����
        T* p=this->parr;
        while(p != this->cur)
        {
            *(cur1)=*p;
            cur1++;
            p++;
        }

        //�ͷ��Ͽռ�,�����¿ռ�
        this->cur=cur1;
        delete[] this->parr;
        this->parr=newspace;

        //β��
        *(this->cur)=i;
        cur++;
        this->m_size++;
    }

    else
    {
        *(this->cur)=i;
        cur++;
        this->m_size++;
    }
}

template<class T>
void my_array<T>::pop_end()
{
    if(this->cur != this->parr)
    {
        this->m_size--;
        this->cur--;
    }
    else
        cout<<"Ԫ�������,�޷�����ɾ��"<<endl;
}

template<class T>
void my_array<T>::find_elem()
{
    int des;
    cout<<"�������±꣺";
    cin>>des;

//    if(this->parr+des > this->cur)
    //or
    if(des>this->m_size)
        cout<<"�������Խ��"<<endl;
    else
        cout<<"��Ԫ��Ϊ "<<this->parr[des-1]<<endl;
}

template<class T>
void my_array<T>::print()
{
    T* temp=this->parr;
    for(int i=0;temp != this->cur;temp++)
    {
        cout<<this->parr[i]<<" ";
        i++;
    }
    cout<<endl<<"capacity="<<this->m_capacity<<endl<<"size="<<this->m_size<<endl;
}
