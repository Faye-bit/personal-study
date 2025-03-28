#include  <iostream>
using  namespace  std;
template<typename  _Tp>
struct  Node
{
        _Tp  _data;//数据域
        Node<_Tp>  *  _prev  =  nullptr;//前一个节点的指针
        Node<_Tp>  *  _next  =  nullptr;//后一个节点的指针
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
        //describe:在list的末尾加入一个节点，节点的值为val
        //class  name:biList
        //In:const  _Tp  &  val  在末尾加入节点的值
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
        //describe:在list的开始位置加入一个节点，节点的值为val
        //class  name:biList
        //In:const  _Tp  &  val  在末尾加入节点的值
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
        //describe:在list中的指定位置加入一个节点，节点的值为val
        //class  name:biList
        //In:const  Node<_Tp>  *  pi  在节点pi之后插入节点
        //In:const  _Tp  &  val  插入的节点值
        //Out:
        //Return:Node<_Tp>  *  插入节点的指针；如果未能插入节点，则返回nullptr
        //Author:Zhang.Z.T
        //Date:
        //////////////////////////////////////////////////
        Node<_Tp>  *  insertvalue(Node<_Tp>  *  pi,const  _Tp  &  val);

        //remove  node
        //////////////////////////////////////////////////
        //function  name:removeAt
        //describe:移除在list中的指定节点
        //class  name:biList
        //In:const  Node<_Tp>  *  pm  移除的那个节点指针
        //In:
        //Out:
        //Return:Node<_Tp>  *  从链表中移除的那个节点指针；如果无法移除，则返回nullptr
        //Author:Zhang.Z.T
        //Date:
        //////////////////////////////////////////////////
        Node<_Tp>  *  removeAt(Node<_Tp>  *  pm);

        //get  node  by  index
        //////////////////////////////////////////////////
        //function  name:getAt
        //describe:根据索引值index（下标从0开始），在list中找到该节点，并返回该节点的指针
        //class  name:biList
        //In:const  const  size_t  &  index  待查找节点的索引号index
        //In:
        //Out:
        //Return:Node<_Tp>  *  指定节点的指针；如果无该index的节点，则返回nullptr
        //Author:Zhang.Z.T
        //Date:
        //////////////////////////////////////////////////
        Node<_Tp>  *  getAt(const  size_t  &  index);
        const  Node<_Tp>  *  getAt(const  size_t  &  index)const;

        //get  size
        //////////////////////////////////////////////////
        //function  name:size
        //describe:获取list的节点个数
        //class  name:biList
        //In:
        //In:
        //Out:
        //Return:size_t  链表中的节点个数
        //Author:Zhang.Z.T
        //Date:
        //////////////////////////////////////////////////
        size_t  size() const;

        //find  node  by  value
        //////////////////////////////////////////////////
        //function  name:find
        //describe:在list中顺序查找节点的值为val的节点，找到后返回该节点的指针
        //class  name:biList
        //In:const  _Tp  &  val  查找的节点值
        //In:
        //Out:
        //Return:Node<_Tp>  *  查找到的节点指针；如果未能找到值为val的节点，则返回nullptr
        //Author:Zhang.Z.T
        //Date:
        //////////////////////////////////////////////////
        Node<_Tp>  *  find(const  _Tp  &  val);
        //constant  object
        const  Node<_Tp>  *  find(const  _Tp  &  val)const;

        //显示list的基本信息
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
    {  // 处理空链表
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

    // 处理头节点
    if (pm == _head) {
        _head = pm->_next;
        if (_head)  // 新头节点存在则清除前驱指针
            _head->_prev = nullptr;
    } 
    // 处理中间或尾节点
    else {
        // [前驱节点] -> [pm] -> [后继节点]
        pm->_prev->_next = pm->_next;  // 前驱直连后继
        
        // 如果是中间节点才处理后继节点指针
        if (pm->_next)                 
            pm->_next->_prev = pm->_prev;  // 后继回连前驱
    }

    // 清除被删节点的指针（安全措施）
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
