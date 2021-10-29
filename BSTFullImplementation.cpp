#include<iostream>//check if a tree is bst*<important>*
#include<queue>
#include<math.h>
using namespace std;

class BSTnode{public:
	int data;
	BSTnode* left;
	BSTnode* right;
};

BSTnode* CreateNode(int data){
	BSTnode* newNode=new BSTnode();
	newNode->data=data;
	newNode->left=newNode->right=NULL;
	return newNode;
}

BSTnode* Insert(BSTnode* root, int data){
	if(root==NULL){
		root=CreateNode(data);
	}
	else if(data<root->data){
		root->left=Insert(root->left,data);
	}
	else if(data>root->data){ 
		root->right=Insert(root->right,data);
	}
	return root;
}	

bool Search(BSTnode* root,int data){
	if(root==NULL){
		return false;
	}
	else if(data==root->data){
		return true;
	}
	else if(data>root->data){
		return Search(root->right,data);
	}
	else if(data<root->data){
		return Search(root->left,data);}
	else{ 
	return false;}
}
int findMin(BSTnode* root){
	if(root==NULL){
		return -1;
	}
	while (root->left!=NULL)//iterative way
	{
		root=root->left;
	}
	return root->data;
	
	// if(root->left==NULL){//recurive way
	// 	return root->data;
	// }
	// else return findMin(root->left);
}

int findHeight(BSTnode* root){
	if(root==NULL){
		return -1;
	}
	int leftHeight=findHeight(root->left);
	int rightHeight=findHeight(root->right);
	return max(leftHeight,rightHeight)+1;
}

void BFS(BSTnode *root){
    if(root==NULL){
        return;
    }
    queue<BSTnode*> Q;
    Q.push(root);
    while(!Q.empty()){
        cout<<Q.front()->data<<" ";
        if(Q.front()->left!=NULL){
            Q.push(Q.front()->left);
        }
        if(Q.front()->right!=NULL){
            Q.push(Q.front()->right);
        }
    Q.pop();
    }
}

//node: inorder traversal of BST gives sorted list
void InorderTraversal(BSTnode* root){
    if(root==NULL){
        return;			
    }   
    InorderTraversal(root->left);//if data is printed first it'll be preorder
    cout<<root->data<<" ";       //if data is printed middle it'll be inorder
    InorderTraversal(root->right);//if data is printed last it'll be postorder
}



int main() 
{
	BSTnode* root=NULL;
	root=Insert(root,4);
	root=Insert(root,5);
	root=Insert(root,9);
	root=Insert(root,2);
	root=Insert(root,8);
	root=Insert(root,1);
	root=Insert(root,3);
	root=Insert(root,6);
	root=Insert(root,10);
	root=Insert(root,7);
	// if(Search(root,22)){
	// 	cout<<"element found\n";
	// }else{ 
	// 	cout<<"element not found";}
	//cout<<findMin(root);
	//cout<<findHeight(root);
    //BFS(root);
	InorderTraversal(root);
	

	return 0;
}