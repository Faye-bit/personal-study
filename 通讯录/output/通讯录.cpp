#include<iostream>
#include<string>
using namespace std;

#define max 1000

void showmenu()
{   
    cout<<"******************************************************"<<endl;
    cout<<"******************************************************"<<endl;
    cout<<"**** Please Press 1 to create a new contact **********"<<endl;
    cout<<"**** Please Press 2 to show all contacts *************"<<endl;
    cout<<"**** Please Press 3 to search a existig contact ******"<<endl;
    cout<<"**** Please Press 4 to delete a existing contact *****"<<endl;
    cout<<"**** Please Press 5 to modify a existing contact  ****"<<endl;
    cout<<"**** Please Press 6 to empty the contact list ********"<<endl;
    cout<<"**** Please Press 0 to exit the Address List *********"<<endl;
    cout<<"******************************************************"<<endl;
    cout<<"******************************************************"<<endl;
}

struct contact
{
    string name;
    int gender;
    int age;
    string phone;
};

struct addresslist
{
    contact con[max];
    int num;
};

void addcontact(addresslist * list)//function to create a new contact
{
    if(list->num == max)
    {
        cout<<"The list is full! Maybe you should delete some contacts to create more."<<endl;
        return;
    }
    else
    {
        cout<<"Please enter the name:";//enter name
        cin>>list->con[list->num].name;
        cout<<endl;

        cout<<"1--male And 2--female.";//enter gender
        cout<<"Please enter the gender:";
        int gender = 0;
        cin>>gender;
        while(true)
        {
            if(gender==1 || gender==2)
            {
                list->con[list->num].gender = gender;
                break;
            }
            else
            {
                cout<<"This gender is known.Please enter again:";
                cin>>gender;
            }
        }
        cout<<endl;

        cout<<"Please enter the age:";//enter age
        cin>>list->con[list->num].age;
        cout<<endl;

        cout<<"Please enter the telephone number:";//enter phone
        cin>>list->con[list->num].phone;
        cout<<endl;

        cout<<"create successfully!"<<endl;
        list->num++;

        system("pause");
        system("cls");
    }
}

void showcontacts(addresslist list)//function to show the addresslist
{
    if(list.num == 0)
    {
        cout<<"The list is empty now. Try to create a new contact."<<endl;

        system("pause");
        system("cls");
    }
    else
    {
        for(int i = 0;i<list.num;i++)
                {
                    cout<<"name:"<<list.con[i].name<<endl;
                    if(list.con[i].gender == 1)
                    {
                        cout<<"gender:male"<<endl;
                    }
                    else
                    {
                        cout<<"gender:female"<<endl;
                    }
                    cout<<"age:"<<list.con[i].age<<endl;
                    cout<<"phone:"<<list.con[i].phone<<endl;
                    cout<<endl;
                }
                cout<<"Over."<<endl;

                system("pause");
                system("cls");
    }
}

int searchcontact(addresslist list,string name)//function to search a contact
{
    
    int j=-1;

    for(int i=0;i<list.num;i++)
    {
        if(list.con[i].name == name)
        {
            j=i;
        }
    }

    return j;
}

void deletecontact(addresslist * list,int b)
{
    for(int i=b;i<list->num;i++)
    {
        list->con[i]=list->con[i+1];
    }
    list->num--;

    cout<<"Delete successfully!"<<endl;
    system("pause");
    system("cls");
}    

int main()
{
    cout<<"Welcome to use Address List"<<endl;

    addresslist list;
    list.num = 0;

    while(true)
    {
        showmenu();

        int n;
        cin>>n;

        switch (n)
        {
            case 1://Please Press 1 to create a new contact
                addcontact(&list);
                break;
            case 2://Please Press 2 to show all contacts
                showcontacts(list);
                break;
            case 3://Please Press 3 to search a existig contact
                {
                    string name;
                    cout<<"Please enter the contact's name who you want to search:";
                    cin>>name;
                
                    int a = searchcontact(list,name);
                
                    if(a == -1)
                    {
                        cout<<"No result.Please check whether the name you enter is right."<<endl;
                        system("pause");
                        system("cls");
                    }
                    else
                    {
                        cout<<list.con[a].name<<endl;
                        cout<<list.con[a].gender<<endl;
                        cout<<list.con[a].age<<endl;
                        cout<<list.con[a].phone<<endl;
                        cout<<endl;
                    }
                    system("pause");
                    system("cls");
                    break;
                }
            case 4://Please Press 4 to delete a existing contact
                {
                    string name;
                    cout<<"Please enter the contact's name who you want to delete:";
                    cin>>name;
                
                    int b = searchcontact(list,name);
                    //cout<<b<<endl;
                    if(b != -1)
                    {
                        deletecontact(&list, b);
                    }
                }
                break;
            case 5://Please Press 5 to modify a existing contact
                {
                    string name;
                    cout<<"Please enter the came of the contact who you want to modify.";
                    cin>>name;

                    int c = searchcontact(list,name);

                    if(c != -1)
                    {
                        cout<<"Please enter the name:";//enter name
                        cin>>list.con[c].name;
                        cout<<endl;

                        cout<<"1--male And 2--female.";//enter gender
                        cout<<"Please enter the gender:";
                        int gender = 0;
                        cin>>gender;
                        while(true)
                        {
                            if(gender==1 || gender==2)
                            {
                                list.con[c].gender = gender;
                                break;
                            }
                            else
                            {
                                cout<<"This gender is known.Please enter again:";
                                cin>>gender;
                            }
                        }
                        cout<<endl;

                        cout<<"Please enter the age:";//enter age
                        cin>>list.con[c].age;
                        cout<<endl;

                        cout<<"Please enter the telephone number:";//enter phone
                        cin>>list.con[c].phone;
                        cout<<endl;

                        cout<<"modify successfully!"<<endl;
                        system("pause");
                        system("cls");
                    }
                }
                break;
            case 6://Please Press 6 to empty the contact list
                {
                    list.num = 0;
                    cout<<"Your address list is empty now!"<<endl;

                    system("pause");
                    system("cls");
                }
                break;
            case 0:
                cout<<"Welcome to use Address List again!"<<endl;
                system("pause");
                return 0;
            default:
                cout<<"More functions are under improvement..."<<endl;
                break;
        }

    }
    
}