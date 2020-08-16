#include<iostream>
#include<conio.h>
using namespace std;
//Write a C++ program to search an element in the single linked list
template<typename type>
class LinkedList{
    struct Node{
        type data;
        Node* next;
    };
    Node* begin=NULL;
public:
    void traverse(){
        if(begin == NULL){
            cout<<"Linked List is empty"<<endl;
        }
        else{
            Node *ptr = begin;
            cout<<"List: ";
            while(ptr != NULL){
                cout<<"\t"<<ptr->data;
                ptr = ptr->next;
            }
        }
    }

    void insertBeg(type x){
        Node *tmp = new Node;
        tmp->data = x;
        tmp->next = begin;
        begin = tmp;
    }

    void insertEnd(type x){
        Node *tmp = new Node;
        tmp->data = x;
        tmp->next = NULL;
        if(begin == NULL){
            begin = tmp;
        }
        else{
            Node *ptr = begin;
            while(ptr->next != NULL){
                ptr = ptr->next;
            }
            ptr->next = tmp;
        }
    }
    bool search(type x){
        cout<<"Searching";
        Node *ptr = begin;
        if(begin == NULL){
            cout<<"Linked List is empty"<<endl;
        }
        else{
            while(ptr != NULL){
            if(ptr->data == x){
                return true;
            }
            ptr = ptr->next;
        }
        }

        return false;
    }
};
int main(){
    LinkedList <int>ll;
    int i, ch,l;
    int x;
    bool exit = false;
    while(!exit){
        cout<<"\nSelect a choice:"<<endl;
        cout<<"1. Create a LinkList"<<endl;
        cout<<"2. Search"<<endl;
        cout<<"3. Display the LinkList"<<endl;
        cout<<"4. Exit"<<endl;

    cin>>ch;
    switch(ch){
    case 1:
        cout<<"Enter the length of the LinkedList: ";
        cin>>l;
        cout<<"Enter "<<l<<" numbers"<<endl;

        for(i = 0;i<l;i++){
            cin>>x;
            ll.insertEnd(x);
        }
        cout<<"LinkedList Saved"<<endl;
    break;
    case 2:
        cout<<"Enter the number to be searched: ";
        int n;
        cin>>n;
        if(ll.search(n)){
            cout<<n<<" is present in the Linked List"<<endl;
        }
        else{
            cout<<n<<" is not present in the Linked List"<<endl;
        }
    break;
    case 3:
        ll.traverse();
    break;
    case 4:
        exit = true;
    break;
    default:
        cout<<"INVALID CHOICE"<<endl;
    break;
    }
    }
    return 0;
}
