#include <iostream>
using namespace std;

class node{
    public:
    int data;
    node* next;
};

void detect(node* head){
    node* slow =head;
    node* fast = head;
   
while(fast && fast->next)
{
    slow = slow->next;
    fast =fast->next->next;

    if(slow == fast){
        slow = head;
        while(slow!=fast){
            slow=slow->next;
            fast=fast->next;
        }

    cout<<"Cycle data: "<<slow->data<<endl;

    node* ce=slow;
    while(ce->next!=slow){
        ce=ce->next;
    }
    ce->next = head;
    return;
}
}
cout<<"No cycle detected";
}

void print(node* head){
    node* temp = head;
    if(head==nullptr)
    return;
    do{
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    while(temp!=head);
   
}
int main(){

    node *n1 =new node();
    n1->data=1;
    node *n2 =new node();
    n2->data=5;
    node *n3 =new node();
    n3->data=6;
    node *n4 =new node();
    n4->data=3;
    node *n5 =new node();
    n5->data=4;

    node* head  =n1;
    n1->next =n2;
    n2->next =n3;
    n3->next =n4;
    n4->next =n5;
    n5->next=n3;

    detect(head);

    cout<<"Corrected list:";
    print(head);

    return 0;

}