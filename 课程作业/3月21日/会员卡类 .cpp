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
    // �������ι��캯��
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
    struct Node {          // �����ڵ�ṹ
        Card* data;
        Node* next;
        Node(Card* c) : data(c), next(nullptr) {}
    };
    Node* head;            // ͷָ��
    Node* tail;            // βָ��
    
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
            cout<<current->data->name<<"�������ѽ��ͻ������£�"<<'\n'<<' '<<current->data->cost<<"Ԫ,"<<current->data->points<<"��"<<'\n'<<' ';
            current = current->next;
        }
    }
};

int  main()  
{
    List  list;
    Card  card1(12345,  "�Ż�",  123456789),  card2(23456,  "�λ�",  234567891);
    list.insertrear(&card1);
    list.insertrear(&card2);
    card1.bill(531);
    card2.bill(472);
    list.printlist();
    return  0;
}