// building the tree using  recursion

#include<iostream>
#include<queue>
using namespace std;

class node {
           public:
           int data;
           node * left;
           node * right;
           
           node(){
            this->data = -1;
            this ->left = NULL;
            this ->right  =NULL;

           }


           node(int d){
            this->data = d;
            this ->left = NULL;
            this ->right  =NULL;
           }
           ~node(){
            delete left ,right;
           }

};

node* buildTree(node*root){

    cout<<"enter the data"<<endl;
    int data;
    cin>>data;
    root = new node(data);
    if(data == -1){
        return NULL;
    }
    cout<<"Enter the data for left of "<<data<<endl;
    root->left = buildTree(root->left);
    cout<<"Enter the data for right of "<<data<<endl;
    root->right = buildTree(root->right);

    return root;

}
void levelordertraversal(node*root){
          queue<node*>q;
          
          q.push(root);
         
         while(!q.empty()){
            node* temp  = q.front();
            q.pop();
          if(temp == NULL){
            return ;
          }
// 1 2 -1 -1 5 -1 -1
          else{
            cout<<temp->data<<" ";
            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
          }
        }
}


// inorder (LNR) / preorder (NLR) / postorder traversal (LRN)
void inorder(node*root){
      if(root==NULL){
        return ;
      }

      inorder(root->left);
      cout<<root->data<<" ";
      inorder(root->right);
}


void preorder(node*root){
    if(root==NULL){
        return ;

    }

    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
    
}

void postorder(node*root){
    if(root==NULL){
        return ;

    }

    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
    
}

int main(){
           node * root ;
           root =  buildTree(root);

           levelordertraversal(root);
           cout<<endl;
           inorder(root);
           cout<<endl;
           preorder(root);cout<<endl;
           postorder(root);

return 0;
}