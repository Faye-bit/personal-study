#include  <iostream>   
#include  <cstdlib>   
#include  <exception>   

using  namespace  std;   

template<typename  T>   
class  dyArray{   
private:   
        //member  of  data   
        T  *  _pData  =  nullptr;//ָ�룬ָ��heap�е��ڴ�ռ��׵�ַ
        size_t  _nSize  =  0;//������Ԫ�ظ���
        size_t  _nCapacity  =  0;//����   
public:   
        //member  of  function   
        //ctor   
        dyArray(size_t  n=10);   
        //ctor  overload  nΪ����ռ��е�Ԫ�ظ���  valΪ�����и�Ԫ�صĳ�ʼֵ
        dyArray(size_t  n,const  T  &  val);   
        //copy  ctor   
        dyArray(const  dyArray  &  obj);   
        //dtor   
        ~dyArray();   

private:   
        //memory  allocate  �����ڴ�ռ�
        void  memset(size_t  n)  
        {   
                release();   
                //invoke  operator  operator  new   
                if(n  >  0){_pData  =  new  T[n];}   
        }
        //dump  memory  �ͷ��ڴ�ռ�
        void  release()  
        {   
                if(_pData){delete  []  _pData;_pData  =  nullptr;}   
        }

public:   
        //member  of  function   
        //overload  operator  []   
        //nidxΪ�±�����
        T  &  operator[](size_t  nidx)
        {   
                return  _pData[nidx];   
        }
        const T & operator[](size_t  nidx) const
        {   
                return  _pData[nidx];   
        }
        //overload  operator=   
        //rhs  source  of  array   
        dyArray<T>  &  operator=(const  dyArray<T>  &  rhs);   

public:   
        //get  begin  &  end   
        T* begin(){return  _pData;}   
        const  T  *  begin()const  {return  _pData;}   
        T* end()  {return  _pData  +  _nSize;}   
        const T* end()const {return _pData + _nSize;}   
        //get  size  ��ȡ������Ԫ�ظ���
        size_t size()const{return  _nSize;}   
        //get  capacity  ��ȡ��������������
        size_t capacity()const  {return  _nCapacity;}   


        //append  ��β������һ������
        void push_back(const  T  &  val);   
        //delete  at  ɾ��ָ��λ��(nidx)��Ԫ��
        bool deleteAt(size_t  nidx);   
        void removeAll();//�Ƴ����е�Ԫ��
        //insert  value  ��ָ��λ�ã�nidx���������һ������val
        bool insert(size_t  nidx,const  T  &  val);   

public:   
        //conversion  function   
        operator  T*(){return  _pData;}   
        operator  const  T*()const{return  _pData;}   

private:   
        //����  ��ս�����������Ҫ����ʱ������2������
        void expansion();   

};

template<class T>
dyArray<T>::dyArray(size_t n)
{
        this->_nCapacity=10;
}

template<class T>
dyArray<T>::dyArray(size_t n,const T& val)
{
        _nSize=n;
        _nCapacity=n*2;
        _pData=new T[_nCapacity];
        for(size_t i=0;i<n;i++)
        {
                _pData[i]=val;
        }
}

template<class T>
dyArray<T>::dyArray(const  dyArray  &  obj)
{
        this->_nCapacity=obj._nCapacity;
        this->_nSize=obj._nSize;
        delete[] this->_pData;
        this->_pData= obj._pData;
}

template<class T>
dyArray<T>& dyArray<T>::operator=(const dyArray<T>& rhs)
{
        this->_nCapacity=rhs._nCapacity;
        this->_nSize=rhs._nSize;
        delete[] this->_pData;
        this->_pData= rhs._pData;
        return *this;
}

template<class T>
dyArray<T>::~dyArray()
{
        delete[] this->_pData;
        _pData=nullptr;
}

template<class T>
void dyArray<T>::expansion()
{
        _nCapacity*=2;
        dyArray temp(*this);
        _pData=new T[_nCapacity];
        for(int i=0;i<_nSize;i++)
        {
                _pData[i]=temp[i];
        }
}

template<class T>
void dyArray<T>::push_back(const T& val)
{
        
        _pData[_nSize]=val;
        _nSize++;
        if(_nSize==_nCapacity)
        {
               this->expansion();
        }
}

template<class T>
bool dyArray<T>::deleteAt(size_t nidx)
{
        if (nidx<_nSize)
        {
                for(size_t i=nidx;i<(_nSize-2);i++)
                {
                        _pData[i]=_pData[i+1];
                }
                delete _pData[_nSize-1];
                _nSize--;
                return true;
        }
        else
        {
                return false;
        }


}

template<class T>
void dyArray<T>::removeAll()
{
        _nSize=0;
        delete[] _pData;
        _pData=new T[_nCapacity];
}

template<class T>
bool dyArray<T>::insert(size_t nidx,const T& val)
{
        if (nidx<_nSize)
        {
                for(size_t i=_nSize;i>nidx+1;i--)
                {
                        _pData[i]=_pData[i-1];
                }
                _pData[nidx+1]=val;
                _nSize++;
                return true;
        }
        else
        {
                return false;
        }
}

template<typename T>
void display(T* first,T* last){
        T* start = first;
        while(start!=last)
        {
                cout<<*start<<"  ";
                start++;
        }
        cout<<endl;
}

int  main(){
        int  n  =  10;
        int  val  =  0;
        int  val1  =  0;
        cin>>n>>val;

        size_t  npos  =  0;
        cin>>npos>>val1;
        dyArray<int>  ar(n,val);

        int  *  first  =  ar.begin();
        int  *  last  =  ar.end();
        display(first,last);


        ar.insert(npos,val1);

        first  =  ar.begin();
        last  =  ar.end();
        display(first,last);
        size_t  nc  =  ar.capacity();
        for(size_t  i=0;i<nc;++i)
        {
                ar.push_back(i);
        }

        cout<<ar.size()<<"  "<<ar.capacity()<<endl;

        first  =  ar.begin();
        last  =  ar.end();
        display(first,last);

        return  0;
}