/*arbol binario mostrar elementos con recursibidad y de manera iterativa */
#include <iostream>
#include <stack>

using namespace std;

const int NUL = -1;
const int ARRAY_LEN = 10;

struct TreeNode{
	int data;
	int flag;
	TreeNode* left;
	TreeNode* right;
};

TreeNode* createTree(int array[], int index, int length){
	if(index >= length) return NULL;
	if(array[index] == NUL) return NULL;
	
	TreeNode* newNode = new TreeNode();
	newNode->data = array[index];
	newNode->flag = 0;
	
	newNode->left = createTree(array, index*2+1, length);
	newNode->right = createTree(array, index*2+2, length);

	return newNode;
}
	
void printTreePreOrder(TreeNode* root){
	if(root == NULL) return;
	cout<<root->data<<" ";
	printTreePreOrder(root->left);
	printTreePreOrder(root->right);
	return;
}

void printTreeInOrder(TreeNode* root){
	if(root == NULL) return;
	printTreeInOrder(root->left);
	cout<<root->data<<" ";
	printTreeInOrder(root->right);
	return;
}

void printTreePostOrder(TreeNode* root){
	if(root == NULL) return;
	printTreePostOrder(root->left);
	printTreePostOrder(root->right);
	cout<<root->data<<" ";
	return;
}

void printTreePreOrderUsingStack(TreeNode* root){
	if(root == NULL) return;
	stack<TreeNode*> printStack;
	
	TreeNode* curNode = root;
	while(curNode != NULL || !printStack.empty()){
		while(curNode != NULL){
			printStack.push(curNode);
			cout<<curNode->data<<" ";
			curNode = curNode->left;
		}
		if(!printStack.empty()){
			curNode = printStack.top();
			printStack.pop();
			curNode = curNode->right;
		}
	}		
}

void printTreeInOrderUsingStack(TreeNode* root){
	if(root == NULL) return;
	stack<TreeNode*> printStack;
	
	TreeNode* curNode = root;
	while(curNode != NULL || !printStack.empty()){
		while(curNode != NULL){
			printStack.push(curNode);
			curNode = curNode->left;
		}
		if(!printStack.empty()){
			curNode = printStack.top();
			printStack.pop();
			cout<<curNode->data<<" ";
			curNode = curNode->right;
		}
	}		
}

void printTreePostOrderUsingStack(TreeNode* root){
	if(root == NULL) return;
	stack<TreeNode*> printStack;
	
	TreeNode* curNode = root;
	while(curNode != NULL || !printStack.empty()){
		while(curNode != NULL){
			printStack.push(curNode);
			curNode = curNode->left;
		}
		if(!printStack.empty()){
			curNode = printStack.top();
			printStack.pop();
			if(curNode->flag == 0){
				printStack.push(curNode);
				curNode->flag += 1;
			}else if(curNode->flag == 1){
				cout<<curNode->data<<" ";
				curNode->flag += 1;
			}else{
				//cout<<curNode->flag<<" ";
			} 
			curNode = curNode->right;
		}
	}		
}

int main(int argc, char* argv[]){
	int array[ARRAY_LEN] = {1,2,3,4,5,6,7,8,9,10};
	TreeNode* root = createTree(array, 0, ARRAY_LEN);

	cout<<"PRE ORDER:"<<endl;
	printTreePreOrder(root);
	cout<<endl;
	cout<<"PRE ORDER USIGN STACK:"<<endl;
	printTreePreOrderUsingStack(root);
	cout<<endl;

	cout<<"IN ORDER:"<<endl;
	printTreeInOrder(root);
	cout<<endl;
	cout<<"IN ORDER USIGN STACK:"<<endl;
	printTreeInOrderUsingStack(root);
	cout<<endl;

	cout<<"POST ORDER:"<<endl;
	printTreePostOrder(root);
	cout<<endl;
	cout<<"POST ORDER USIGN STACK:"<<endl;
	printTreePostOrderUsingStack(root);
	cout<<endl;

	return 0;
}