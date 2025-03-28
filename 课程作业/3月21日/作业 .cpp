#include  <iostream>
using  namespace  std;
template<typename  _Tp>
struct  Node
{
        _Tp  _data;//������
        Node<_Tp>  *  _prev  =  nullptr;//ǰһ���ڵ��ָ��
        Node<_Tp>  *  _next  =  nullptr;//��һ���ڵ��ָ��
};

template<typename  _Tp>
class  biList
{
        //member  of  data
        //head  pointer
        Node<_Tp>  *  _head  =  nullptr;

public:
        //ctor
        biList():_head(nullptr){}

        //copy  ctor
        biList(const  biList  &  obj)  =  delete;
        //copy  assignment
        biList<_Tp>&  operator=(const  biList  &  obj)  =  delete;

        //dtor
        ~biList();

        //push_back  Insert  a  node  at  the  end  of  the  linked  list
        //////////////////////////////////////////////////
        //function  name:push_back
        //describe:��list��ĩβ����һ���ڵ㣬�ڵ��ֵΪval
        //class  name:biList
        //In:const  _Tp  &  val  ��ĩβ����ڵ��ֵ
        //In:
        //Out:
        //Return:void
        //Author:Zhang.Z.T
        //Date:
        //////////////////////////////////////////////////
        void  push_back(const  _Tp  &  val);

        //push_front  Insert  a  node  at  the  head  of  the  linked  list
        //////////////////////////////////////////////////
        //function  name:push_front
        //describe:��list�Ŀ�ʼλ�ü���һ���ڵ㣬�ڵ��ֵΪval
        //class  name:biList
        //In:const  _Tp  &  val  ��ĩβ����ڵ��ֵ
        //In:
        //Out:
        //Return:void
        //Author:Zhang.Z.T
        //Date:
        //////////////////////////////////////////////////
        void  push_front(const  _Tp  &  val);

        //insert  node
        //////////////////////////////////////////////////
        //function  name:insertvalue
        //describe:��list�е�ָ��λ�ü���һ���ڵ㣬�ڵ��ֵΪval
        //class  name:biList
        //In:const  Node<_Tp>  *  pi  �ڽڵ�pi֮�����ڵ�
        //In:const  _Tp  &  val  ����Ľڵ�ֵ
        //Out:
        //Return:Node<_Tp>  *  ����ڵ��ָ�룻���δ�ܲ���ڵ㣬�򷵻�nullptr
        //Author:Zhang.Z.T
        //Date:
        //////////////////////////////////////////////////
        Node<_Tp>  *  insertvalue(Node<_Tp>  *  pi,const  _Tp  &  val);

        //remove  node
        //////////////////////////////////////////////////
        //function  name:removeAt
        //describe:�Ƴ���list�е�ָ���ڵ�
        //class  name:biList
        //In:const  Node<_Tp>  *  pm  �Ƴ����Ǹ��ڵ�ָ��
        //In:
        //Out:
        //Return:Node<_Tp>  *  ���������Ƴ����Ǹ��ڵ�ָ�룻����޷��Ƴ����򷵻�nullptr
        //Author:Zhang.Z.T
        //Date:
        //////////////////////////////////////////////////
        Node<_Tp>  *  removeAt(Node<_Tp>  *  pm);

        //get  node  by  index
        //////////////////////////////////////////////////
        //function  name:getAt
        //describe:��������ֵindex���±��0��ʼ������list���ҵ��ýڵ㣬�����ظýڵ��ָ��
        //class  name:biList
        //In:const  const  size_t  &  index  �����ҽڵ��������index
        //In:
        //Out:
        //Return:Node<_Tp>  *  ָ���ڵ��ָ�룻����޸�index�Ľڵ㣬�򷵻�nullptr
        //Author:Zhang.Z.T
        //Date:
        //////////////////////////////////////////////////
        Node<_Tp>  *  getAt(const  size_t  &  index);
        const  Node<_Tp>  *  getAt(const  size_t  &  index)const;

        //get  size
        //////////////////////////////////////////////////
        //function  name:size
        //describe:��ȡlist�Ľڵ����
        //class  name:biList
        //In:
        //In:
        //Out:
        //Return:size_t  �����еĽڵ����
        //Author:Zhang.Z.T
        //Date:
        //////////////////////////////////////////////////
        size_t  size() const;

        //find  node  by  value
        //////////////////////////////////////////////////
        //function  name:find
        //describe:��list��˳����ҽڵ��ֵΪval�Ľڵ㣬�ҵ��󷵻ظýڵ��ָ��
        //class  name:biList
        //In:const  _Tp  &  val  ���ҵĽڵ�ֵ
        //In:
        //Out:
        //Return:Node<_Tp>  *  ���ҵ��Ľڵ�ָ�룻���δ���ҵ�ֵΪval�Ľڵ㣬�򷵻�nullptr
        //Author:Zhang.Z.T
        //Date:
        //////////////////////////////////////////////////
        Node<_Tp>  *  find(const  _Tp  &  val);
        //constant  object
        const  Node<_Tp>  *  find(const  _Tp  &  val)const;

        //��ʾlist�Ļ�����Ϣ
        void  display() const
        {
                size_t  nsize  =  size();
                cout<<"node  number  :  "<<nsize<<endl;
                Node<_Tp>  *  temp  =  _head;
                cout<<"node  value  :  "<<endl;
                while(temp  !=  nullptr)  {
                        cout<<temp->_data<<"  ";
                        temp  =  temp->_next;
                }
                cout<<endl;
        }
};
//dtor
template<typename  _Tp>
biList<_Tp>::~biList()
{
        if(!_head)  {return;}
        Node<_Tp>  *  temp  =  _head;
        while(temp->_next  !=  nullptr)
        {
                _head  =  temp->_next;
                delete  temp;
                temp  =  _head;
        }
        //delete  the  last  node
        delete  _head;
        _head  =  nullptr;
}

template<class _Tp>
void biList<_Tp>::push_back(const _Tp& val)
{   
    auto* newnode=new Node<_Tp>;
    newnode->_data=val;
    if (!_head) 
    {  // ���������
        _head = newnode;
        return;
    }
    Node<_Tp>* temp=_head;
    while(temp->_next!=nullptr)
    {
        temp=temp->_next;
    }
    temp->_next=newnode;
    newnode->_prev=temp;
}

template<class _Tp>
void biList<_Tp>::push_front(const _Tp& val)
{
    Node<_Tp>* newNode=new Node<_Tp>;
    newNode->_data=val;
    if(_head)
    {
        _head->_prev=newNode;
        newNode->_next=_head;
    }
     _head=newNode; 
}

template<class _Tp>
Node<_Tp>* biList<_Tp>::insertvalue(Node<_Tp>* pi,const _Tp& val)
{
    Node<_Tp>* newNode= new Node<_Tp>;
    newNode->_data=val;
    Node<_Tp>* temp=_head;
    while(temp!=pi&&temp)
    {
        temp=temp->_next;
    }
    if(temp==nullptr)
    {
        return nullptr;
    }
    if(temp->_next==nullptr)
    {
        temp->_next=newNode;
        newNode->_next=nullptr;\
        return newNode;
    }
    Node<_Tp>* tempn=temp->_next;
    temp->_next=newNode;
    newNode->_prev=temp;
    tempn->_prev=newNode;
    newNode->_next=tempn;
    return newNode;
}

template<class _Tp>
Node<_Tp>* biList<_Tp>::removeAt(Node<_Tp>* pm)
{
    if (!pm || !_head) return nullptr;

    // ����ͷ�ڵ�
    if (pm == _head) {
        _head = pm->_next;
        if (_head)  // ��ͷ�ڵ���������ǰ��ָ��
            _head->_prev = nullptr;
    } 
    // �����м��β�ڵ�
    else {
        // [ǰ���ڵ�] -> [pm] -> [��̽ڵ�]
        pm->_prev->_next = pm->_next;  // ǰ��ֱ�����
        
        // ������м�ڵ�Ŵ����̽ڵ�ָ��
        if (pm->_next)                 
            pm->_next->_prev = pm->_prev;  // ��̻���ǰ��
    }

    // �����ɾ�ڵ��ָ�루��ȫ��ʩ��
    pm->_prev = pm->_next = nullptr;
    return pm;
}
// {
//     Node<_Tp>* temp=_head;
//     while(temp!=pm&&temp)
//     {
//         temp=temp->_next;
//     }
//     if(temp!=_head)
    
//     Node<_Tp>* tempn=temp->_next;
//     Node<_Tp>* tempp=temp->_prev;
//     tempp->_next=tempn;
//     tempn->_prev=tempp;

//     return temp;
// }

template<class _Tp>
size_t biList<_Tp>::size() const
{
    size_t n=0;
    Node<_Tp>* temp=_head;
    while(temp!=nullptr)
    {
        temp=temp->_next;
        n++;
    }
    return n;
}

template<class _Tp>
Node<_Tp>* biList<_Tp>::find(const _Tp& val)
{
    Node<_Tp>* r=nullptr;
    Node<_Tp>* temp=_head;
    while(temp->_data!=val&&temp)
    {
        temp=temp->_next;
    }
    if(temp!=nullptr)
    {
        r=temp;
    }
    return r;
}

template<class _Tp>
Node<_Tp>* biList<_Tp>::getAt(const size_t& index)
{
    Node<_Tp>* r=nullptr;
    Node<_Tp>* temp=_head;
    for(size_t i=0;(i<index)&&temp;i++)
    {
        temp=temp->_next;
    }
    if(temp!=nullptr)
    {
        r=temp;
    }
    return r;
}

int  main(){
    biList<int>  list1;
    int  n  =  0;
    cin>>n;
    int  val  =  0;
    int  m  =  0;
    for(int  i=0;  i<n;  ++i){
            cin>>val;
            if(  !(i%2)  ){list1.push_back(val);  }
            else{  list1.push_front(val);        }
    }

    cin>>m;
    list1.display();

    size_t  nsize  =  list1.size();
    if(m  <  nsize){
            Node<int>  *  pit  =  list1.getAt(m);
            pit->_data  =  -1;
    }
    else{
            Node<int>  *  pit  =  list1.getAt(0);
            list1.insertvalue(pit,m);
            pit  =  list1.getAt(0);
            auto  it  =  list1.removeAt(pit);
            if(it){delete  it;}
    }
    list1.display();

    return  0;
}
