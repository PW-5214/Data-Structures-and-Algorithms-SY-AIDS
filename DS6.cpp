#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node* left;
    node * right;

    node(int value){
        data=value;
        left=NULL;
        right=NULL;
    }

node* insert(node* root,int val){
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

node *LCA(node*root,int x,int y){
    if(root==NULL){
        return NULL;
    }

    if(root->data > x && root->data> y){
        return LCA(root->left,x,y);
    }
    else if(root->data< x  && root->data < y){
        return LCA(root->right,x,y);
    }
    else{
        return root;
    }


}
};

int main(){

    node ob(0);

    node*root=nullptr;

    int n;
    cout<<"Enter how many elements need:";
    cin>>n;

    int arr[n];
    for(int i=0; i<n;i++){
        cout<<"Enter "<<i+1<<":";
        cin>>arr[i];
    }

    for(int i=0;i<n;i++){
       root= ob.insert(root,arr[i]);
    }
     
    int x,y;
    cout<<"Enter N1 :"<<endl;
    cin>>x;
    cout<<"Enter N2 :"<<endl;
    cin>>y;

    node * lca =ob.LCA(root,x,y);

   if(lca!=nullptr){
       cout<<"The LCA is:"<<lca->data;
   }
   else{
    cout<<"LCA Not Found";
   }
    
return 0;

}