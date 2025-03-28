#include<iostream>
#include<string>
using  namespace  std;   

class List;
class Card;

class Card
{
    friend class List;
public:
    int id;
    string name;
    int tele;
    double cost;
    double points;

public:
    // 新增带参构造函数
    Card(int i, string n, int t) : id(i), name(n), tele(t), cost(0), points(0) {}
    double bill(double money)
    {
        cost=money;
        rePoint(money);
        return cost;
    }

    double rePoint(double money)
    {
        points=(money/20);
        return points;
    }
};

class  List
{
    friend class Card;
private:
    struct Node {          // 新增节点结构
        Card* data;
        Node* next;
        Node(Card* c) : data(c), next(nullptr) {}
    };
    Node* head;            // 头指针
    Node* tail;            // 尾指针
    
public:
    List() : head(nullptr), tail(nullptr) {}
    
    void insertrear(Card* card) {
        Node* newNode = new Node(card);
        if (!head) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }
    
    void printlist() 
    {
        Node* current = head;
        while (current) 
        {
            cout<<current->data->name<<"本次消费金额和积分如下："<<'\n'<<' '<<current->data->cost<<"元,"<<current->data->points<<"分"<<'\n'<<' ';
            current = current->next;
        }
    }
};

int  main()  
{
    List  list;
    Card  card1(12345,  "张华",  123456789),  card2(23456,  "何欢",  234567891);
    list.insertrear(&card1);
    list.insertrear(&card2);
    card1.bill(531);
    card2.bill(472);
    list.printlist();
    return  0;
}