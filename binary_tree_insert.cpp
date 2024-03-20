#include<iostream>
#include<stack>
using namespace std;
class bst{
    public:
    int data;
    bst*left;
    bst*right;

};
bst*newnode(int data){
bst*newnode=new bst();
newnode->data=data;
newnode->left=NULL;
newnode->right=NULL;
return newnode;
}
void insert(bst*&root,int data){
    if(root==NULL){
     root=newnode(data);
    }
    //if root is not null
    if(data>root->data){
       insert(root->right,data);
    }
    else if(data<root->data){
        insert(root->left,data);
    }
}
void inorder(bst*&root){
    if(root==NULL)return;
    inorder(root->left);
    cout<<root->data<<"";
    inorder(root->right);

}
void deleteNode(bst*& root, int key) {
    if (root == nullptr) return;

    // Find the node to delete
    if (key < root->data) {
        deleteNode(root->left, key);
    } else if (key > root->data) {
        deleteNode(root->right, key);
    } else {
        // Node to delete found

        // Case 1: Node has no children or one child
        if (root->left == nullptr) {
            bst* temp = root->right;
            delete root;
            root = temp;
        } else if (root->right == nullptr) {
            bst* temp = root->left;
            delete root;
            root = temp;
        } else {
            // Case 3: Node has two children
            bst* temp = minValueNode(root->right); // Find in-order successor
            root->data = temp->data; // Copy the successor's data to this node
            deleteNode(root->right, temp->data); // Delete the successor
        }
    }
}

// Function to find the node with the minimum value in a subtree
bst* minValueNode(bst* root) {
    bst* current = root;
    while (current && current->left != nullptr) {
        current = current->left;
    }
    return current;
}
void inorder_nonrcursive(bst*root){
    //create an empty stack
    stack<bst*>stack;
    //set a current node to root node
    bst*curr=root;
    while(!stack.empty()||curr!=NULL){
        if(curr!=NULL){
            stack.push(curr);
            curr=curr->left;
        }
        else{
            curr=stack.top();
            stack.pop();
            cout<<curr->data<<"";
            curr=curr->right;

        }
    }

}
void preorder_nonrecursive(bst*root){
    stack<bst*>stk;
    stk.push(root);
    while(!stk.empty()){
        bst*current=stk.top();
        stk.pop();
        cout<<current->data<<"";
        if(current->right!=NULL){
            stk.push(current->right);
        }
        if(current->left!=NULL){
            stk.push(current->left);
        }

    }

}
void postorder_nonrecursive(bst*root){
    stack<bst*>stk;
    stack<int>out;
    while(!stk.empty()){
        bst*current=stk.top();
        stk.pop();
        out.push(current->data);
        if(current->right!=NULL){
            stk.push(current->right);

        }
        if (current->left!=NULL){
            stk.push(current->left);

        }
        while(!out.empty()){
            cout<<out.top()<<endl;
            out.pop();
        }

    }

}
void search(bst*root,int key){
if(root->data==key||root==NULL){
   if(root==NULL){
    cout<<"found"<<endl;

   }
   else{
    cout<<"not found";
   }

}
if(key>root->data){
    search(root->right,key);
}
else{
    search(root->left,key);
}


}

int main(){
    bst*root=NULL;
    insert(root,5);
    insert(root,1);
    insert(root,2);
    insert(root, 4);
    insert(root, 6);
    insert(root, 7);
    insert(root,8);
    deleteNode(root,8);

    return 0;
}




