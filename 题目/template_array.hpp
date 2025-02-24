#pragma once
#include<iostream>
using namespace std;

template<class T>
class myarray
{
private:
    T* m_pa;
    int m_capacity;
    int m_size;

public:
    myarray(int capacity);
    myarray(const myarray& arr);
    ~myarray();
    myarray& operator=(const myarray& arr);
    T operator[](int index);
    void push_back(const T val);
    void pop_back();
    int getcapacity();
    int getsize();
};

template<class T>
myarray<T>::myarray(int capacity)
{ 
    m_pa=new T[capacity];
    m_capacity=capacity;
    m_size=0;
}

template<class T>
myarray<T>::myarray(const myarray& arr)
{
    m_capacity=arr.m_capacity;
    m_size=arr.m_size;
    m_pa=new T[m_capacity];
    for(int i=0;i<m_size;i++)
    {
        m_pa[i]=arr.m_pa[i];
    }
}

template<class T>
myarray<T>::~myarray()
{
    if(m_pa!=nullptr)
    {
        delete[] m_pa;
        m_pa=nullptr;
    }
    m_capacity=0;
    m_size=0;
}

template<class T>
myarray<T>& myarray<T>::operator=(const myarray& arr)
{
    if(m_pa!=nullptr)
    {
        delete[] m_pa;
        m_pa=nullptr;
        m_capacity=0;
        m_size=0;
    }

    m_capacity=arr.m_capacity;
    m_size=arr.m_size;
    m_pa=new T[m_capacity];
    for(int i=0;i<m_size;i++)
    {
        m_pa[i]=arr.m_pa[i];
    }

    return *this;
}

template<class T>
T myarray<T>::operator[](int index)
{
    return m_pa[index];
}

template<class T>
void myarray<T>::push_back(const T val)
{
    if(m_size==m_capacity)
    {
        return;
    }

    m_pa[m_size]=val;
    m_size++;
}

template<class T>
void myarray<T>::pop_back()
{
    if(m_size==0)
    {
        return;
    }

    m_size--;
}

template<class T>
int myarray<T>::getcapacity()
{
    return m_capacity;
}

template<class T>
int myarray<T>::getsize()
{
    return m_size;
}

//
//Created by Faye on 25-2-3
//