
#include <iostream>
using namespace std;

class node{
    public:
    int data;
    node* left;
    node* right;

    node(int value){
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

class Queue{
    public:
    int front, rear;
    node* arr[100];

    Queue(){
        front = 0;
        rear = -1;
    }

    bool isempty(){
        return front > rear;
    }

    void enqueue(node* val){
        rear = rear + 1;
        arr[rear] = val;
    }

    node* dequeue(){
       if(isempty()){
           return nullptr;
       }
       return arr[front++];
    }
};

node* insert(node* root, int values) {
    if(root == nullptr) {
        return new node(values);
    }
    if(values < root->data) {
        root->left = insert(root->left, values);
    } else {
        root->right = insert(root->right, values);
    }
    return root;
}

void inorder(node* root, int arr[], int &index) {
    if(!root)
        return;

    inorder(root->left, arr, index);
    arr[index++] = root->data;
    inorder(root->right, arr, index);
}

void convrtmin(node* root, int arr[], int &index) {
    Queue q;
    q.enqueue(root);

    while(!q.isempty()) {
        node* current = q.dequeue();
        
        current->data = arr[index++];

        if(current->left) {
            q.enqueue(current->left);
        }
        if(current->right) {
            q.enqueue(current->right);
        }   
    }
}

void preorder(node* root) {
    if (!root) return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

int main() {
    node* root = nullptr;
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    int arr[n];
    for(int i = 0; i < n; i++) {
        cout << "Enter element " << i+1 << ": ";
        cin >> arr[i];
        root = insert(root, arr[i]);
    }

    int inordarr[n], index = 0;

    inorder(root, inordarr, index);

    index = 0;  
    convrtmin(root, inordarr, index);

    cout << "\nPre-order traversal of the converted Min Heap: ";
    preorder(root);

    return 0;
}
