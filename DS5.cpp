#include <iostream>
using namespace std;

class node {

    public:
    int data;
    node* left;
    node* right;

    node(int value){
        data=value;
        left=NULL;
        right=NULL;
    }

node *insert(node*root,int val){
    if(root==NULL){
        return new node(val);
    }

    if(val<root->data){
        root->left=insert(root->left,val);
    }
    else{
        root->right=insert(root->right,val);
    }

    return root;

}

void postorder(node* root){
    if(root==NULL){
        return ;
    }
   postorder(root->left);
   postorder(root->right);
   cout<<" "<<root->data;
}


node* postpred(node*root,int key,node* & predecessor){
   if(root==NULL){
    return nullptr;
   }

   postpred(root->left,key,predecessor);
   postpred(root->right,key,predecessor);

   if(root->data==key){
    if(predecessor){
    cout<<"prdecessor of"<<key<<"is:"<<predecessor->data;
   }

   else{
    cout<<"Predessor cannot be find"<<endl;
   }
   return root;
   }
   predecessor = root;
  return nullptr;
}

};

int main(){

    node ob(0);

    node *root=nullptr;
    int n;
    cout<<"Enter the How many elements:";
    cin>>n;
    
    int* arr=new int[n];
    for(int i=0;i<n;i++){
        cout<<"enter"<<i+1<<":";
        cin>>arr[i];
    }

    for(int i=0;i<n;i++){
        root=ob.insert(root,arr[i]);
    }

   cout<<"Postorder Traversal:"<<endl;
   ob.postorder(root);

   int key;
   cout<<"Enter Key:";
   cin>>key;
   node* predecessor=nullptr;
   ob.postpred(root,key,predecessor);

   return 0;

}

