#include <iostream>
using namespace std;

class node{
    public:
    int data;
    node*  next;

    node(int value){
        data=value;
        next=nullptr;
    }

   node* mergelist(node* head1,node* head2){
    if(!head1){
        return head2;
    }
    else if(!head2){
        return head1;
    }
    else if(head1->data <= head2->data){
        head1->next = mergelist(head1->next,head2);
        return head1;
    }
    else{
        head2->next = mergelist(head1,head2->next);
        return head2;
    }
   }

   node *mergeklist(node* arr[],int start,int end ){
     if(start==end)
        return arr[start];
     
     int mid=start + (end-start)/2;
     node *left= mergeklist(arr,start,mid);
     node* right =mergeklist(arr,mid+1,end);
     return mergelist(left,right);
     }

};

    void print(node* val){
        while(val){
            cout<< val->data <<" ";
            val=val->next;
        }
        cout<<endl;
     }

    node* createKlists(){
        int n, value;
        cout<<"Enter the no. of elements in the list:";
        cin>>n;

        if(n == 0)
        return nullptr;

        cout<<"Enter the elements in sorted order:";
        cin>>value;
        node* head =new node(value);
        node* current = head;

        for(int i=1;i<n;i++){
            cin>>value;
            current->next = new node(value);
            current = current->next;
        }

         return head;
    }

    int main(){
        int k;
        cout<<"Enter the number of lists:";
        cin>>k;

        node* arr[k];
        for(int i =0;i<k;i++){
            cout<<"List"<<i+1<<":\n";
            arr[i]= createKlists();
        }
        node* merge =arr[0]->mergeklist(arr,0,k-1);
        cout<<"Merged list:";
        print(merge);

        return 0;
    }



