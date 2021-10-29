#include<iostream>
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
/*  its not efficient
bool isSubTreeLesser(BSTnode* root,int value){
	if(root==NULL){
		return true;
	}
	if(root->data>value){
		return false;
	}
	return isSubTreeLesser(root->left,value) and isSubTreeLesser(root->right,value);
}
bool isSubTreegreater(BSTnode* root,int value){
	if(root==NULL){
		return true;
	}
	if(root->data<value){
		return false;
	}
	return isSubTreegreater(root->left,value) and isSubTreegreater(root->right,value);

}

bool isBST(BSTnode* root){
	if(root==NULL){
		return true;
	}
	if(isSubTreegreater(root->right,root->data) and isSubTreeLesser(root->left,root->data)
	 and isBST(root->left) and isBST(root->right)){
		 return true;}
	return false;
}
*/
bool isBST(BSTnode* root,BSTnode* min ,BSTnode* max){
	if(root==NULL){
		return true;
	}// IN this bst duplicate values are allowed at right
	if(min!=NULL and root->data<min->data)
    {//above line of code will let duplicates on right subtree
    
		return false;
	}
	else if (max!=NULL and root->data>=max->data){
		return false;
	}
	return isBST(root->left,min,root) and isBST(root->right,root,max);
}

bool checkBST(BSTnode *root){
	return isBST(root,NULL,NULL);
}

int main()            //       IN this bst duplicate values are allowed at right
{	BSTnode* root=NULL;
	root = CreateNode(4);                        //   4
	root->right=CreateNode(7);              //      2    7
	root->left=CreateNode(2);        ///          1    5    7
	root->right->left=CreateNode(5);
    root->left->left=CreateNode(1);
    root->right->right=CreateNode(7);


	if(checkBST(root)){ 
	cout<<"its bst";}
	else{
		cout<<"not bst";
	}
	return 0;
}