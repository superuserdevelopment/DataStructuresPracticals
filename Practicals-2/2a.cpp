#include<iostream>
#include<conio.h>
using namespace std;
//Write a C++ program to create a single linked list, reverse list and display elements
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
    void reverse(){
        Node *current=begin;
        Node *prev = NULL, *next = NULL;
        if(begin == NULL){
            cout<<"LinkedList is empty"<<endl;
        }
        else{
        while(current != NULL){
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        begin = prev;
        }
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
        cout<<"2. Reverse a LinkList"<<endl;
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
        ll.reverse();
        cout<<"LinkedList Reversed()"<<endl;
        ll.traverse();
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
