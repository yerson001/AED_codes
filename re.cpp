/*red blac tree with remove complet*/
#include<iostream>
#include<stack>
#include<vector>
#include<windows.h>
#include <iomanip>
#include <queue>
#include <cmath>
#include<string>
using namespace std; 
  
enum COLOR { RED, BLACK }; 
  
class nodo { 
public: 
  int val; 
  COLOR color; 
  nodo *left, *right, *parent;
 
  
  nodo(int val) : val(val) { 
    parent = left = right = NULL; 
  
    // Node is created during insertion 
    // Node is red at insertion 
    color = RED; 
  } 
  
  // returns pointer to uncle 
  nodo *uncle() { 
    // If no parent or grandparent, then no uncle 
    if (parent == NULL || parent->parent == NULL) 
      return NULL; 
  
    if (parent->isOnLeft()) 
      // uncle on right 
      return parent->parent->right; 
    else
      // uncle on left 
      return parent->parent->left; 
  } 
  
  // check if node is left child of parent 
  bool isOnLeft() { return this == parent->left; } 
  
  // returns pointer to sibling 
  nodo *sibling() { 
    // sibling null if no parent 
    if (parent == NULL) 
      return NULL; 
  
    if (isOnLeft()) 
      return parent->right; 
  
    return parent->left; 
  } 
  
  // moves node down and moves given node in its place 
  void moveDown(nodo *nParent) { 
    if (parent != NULL) { 
      if (isOnLeft()) { 
        parent->left = nParent; 
      } else { 
        parent->right = nParent; 
      } 
    } 
    nParent->parent = parent; 
    parent = nParent; 
  } 
  
  bool hasRedChild() { 
    return (left != NULL && left->color == RED) || (right != NULL && right->color == RED); 
  } 
}; 
  
class RBTree { 
  public:
  nodo *root; 
  vector<string> colores;
  // left rotates the given node 
  void leftRotate(nodo *x) { 
    // new parent will be node's right child 
    nodo *nParent = x->right; 
  
    // update root if current node is root 
    if (x == root) 
      root = nParent; 
  
    x->moveDown(nParent); 
  
    // connect x with new parent's left element 
    x->right = nParent->left; 
    // connect new parent's left element with node 
    // if it is not null 
    if (nParent->left != NULL) 
      nParent->left->parent = x; 
  
    // connect new parent with x 
    nParent->left = x; 
  } 
  
  void rightRotate(nodo *x) { 
    // new parent will be node's left child 
    nodo *nParent = x->left; 
  
    // update root if current node is root 
    if (x == root) 
      root = nParent; 
  
    x->moveDown(nParent); 
  
    // connect x with new parent's right element 
    x->left = nParent->right; 
    // connect new parent's right element with node 
    // if it is not null 
    if (nParent->right != NULL) 
      nParent->right->parent = x; 
  
    // connect new parent with x 
    nParent->right = x; 
  } 
  
  void swapColors(nodo *x1, nodo *x2) { 
    COLOR temp; 
    temp = x1->color; 
    x1->color = x2->color; 
    x2->color = temp; 
  } 
  
  void swapValues(nodo *u, nodo *v) { 
    int temp; 
    temp = u->val; 
    u->val = v->val; 
    v->val = temp; 
  } 
  
  // fix red red at given node 
  void fixRedRed(nodo *x) { 
    // if x is root color it black and return 
    if (x == root) { 
      x->color = BLACK; 
      return; 
    } 
  
    // initialize parent, grandparent, uncle 
    nodo *parent = x->parent, *grandparent = parent->parent, 
         *uncle = x->uncle(); 
  
    if (parent->color != BLACK) { 
      if (uncle != NULL && uncle->color == RED) { 
        // uncle red, perform recoloring and recurse 
        parent->color = BLACK; 
        uncle->color = BLACK; 
        grandparent->color = RED; 
        fixRedRed(grandparent); 
      } else { 
        // Else perform LR, LL, RL, RR 
        if (parent->isOnLeft()) { 
          if (x->isOnLeft()) { 
            // for left right 
            swapColors(parent, grandparent); 
          } else { 
            leftRotate(parent); 
            swapColors(x, grandparent); 
          } 
          // for left left and left right 
          rightRotate(grandparent); 
        } else { 
          if (x->isOnLeft()) { 
            // for right left 
            rightRotate(parent); 
            swapColors(x, grandparent); 
          } else { 
            swapColors(parent, grandparent); 
          } 
  
          // for right right and right left 
          leftRotate(grandparent); 
        } 
      } 
    } 
  } 
  
  // find node that do not have a left child 
  // in the subtree of the given node 
  nodo *successor(nodo *x) { 
    nodo *temp = x; 
  
    while (temp->left != NULL) 
      temp = temp->left; 
  
    return temp; 
  } 
  
  // find node that replaces a deleted node in BST 
  nodo *BSTreplace(nodo *x) { 
    // when node have 2 children 
    if (x->left != NULL && x->right != NULL) 
      return successor(x->right); 
  
    // when leaf 
    if (x->left == NULL && x->right == NULL) 
      return NULL; 
  
    // when single child 
    if (x->left != NULL) 
      return x->left; 
    else
      return x->right; 
  } 
  
  // deletes the given node 
  void deleteNode(nodo *v) { 
    nodo *u = BSTreplace(v); 
  
    // True when u and v are both black 
    bool uvBlack = ((u == NULL || u->color == BLACK) && (v->color == BLACK)); 
    nodo *parent = v->parent; 
  
    if (u == NULL) { 
      // u is NULL therefore v is leaf 
      if (v == root) { 
        // v is root, making root null 
        root = NULL; 
      } else { 
        if (uvBlack) { 
          // u and v both black 
          // v is leaf, fix double black at v 
          fixDoubleBlack(v); 
        } else { 
          // u or v is red 
          if (v->sibling() != NULL) 
            // sibling is not null, make it red" 
            v->sibling()->color = RED; 
        } 
  
        // delete v from the tree 
        if (v->isOnLeft()) { 
          parent->left = NULL; 
        } else { 
          parent->right = NULL; 
        } 
      } 
      delete v; 
      return; 
    } 
  
    if (v->left == NULL || v->right == NULL) { 
      // v has 1 child 
      if (v == root) { 
        // v is root, assign the value of u to v, and delete u 
        v->val = u->val; 
        v->left = v->right = NULL; 
        delete u; 
      } else { 
        // Detach v from tree and move u up 
        if (v->isOnLeft()) { 
          parent->left = u; 
        } else { 
          parent->right = u; 
        } 
        delete v; 
        u->parent = parent; 
        if (uvBlack) { 
          // u and v both black, fix double black at u 
          fixDoubleBlack(u); 
        } else { 
          // u or v red, color u black 
          u->color = BLACK; 
        } 
      } 
      return; 
    } 
  
    // v has 2 children, swap values with successor and recurse 
    swapValues(u, v); 
    deleteNode(u); 
  } 
  
  void fixDoubleBlack(nodo *x) { 
    if (x == root) 
      // Reached root 
      return; 
  
    nodo *sibling = x->sibling(), *parent = x->parent; 
    if (sibling == NULL) { 
      // No sibiling, double black pushed up 
      fixDoubleBlack(parent); 
    } else { 
      if (sibling->color == RED) { 
        // Sibling red 
        parent->color = RED; 
        sibling->color = BLACK; 
        if (sibling->isOnLeft()) { 
          // left case 
          rightRotate(parent); 
        } else { 
          // right case 
          leftRotate(parent); 
        } 
        fixDoubleBlack(x); 
      } else { 
        // Sibling black 
        if (sibling->hasRedChild()) { 
          // at least 1 red children 
          if (sibling->left != NULL && sibling->left->color == RED) { 
            if (sibling->isOnLeft()) { 
              // left left 
              sibling->left->color = sibling->color; 
              sibling->color = parent->color; 
              rightRotate(parent); 
            } else { 
              // right left 
              sibling->left->color = parent->color; 
              rightRotate(sibling); 
              leftRotate(parent); 
            } 
          } else { 
            if (sibling->isOnLeft()) { 
              // left right 
              sibling->right->color = parent->color; 
              leftRotate(sibling); 
              rightRotate(parent); 
            } else { 
              // right right 
              sibling->right->color = sibling->color; 
              sibling->color = parent->color; 
              leftRotate(parent); 
            } 
          } 
          parent->color = BLACK; 
        } else { 
          // 2 black children 
          sibling->color = RED; 
          if (parent->color == BLACK) 
            fixDoubleBlack(parent); 
          else
            parent->color = BLACK; 
        } 
      } 
    } 
  } 
  
  // prints level order for given node 
  void levelOrder(nodo *x) { 
    if (x == NULL) 
      // return if node is null 
      return; 
  
    // queue for level order 
    queue<nodo *> q; 
    nodo *curr; 
  
    // push x 
    q.push(x); 
  
    while (!q.empty()) { 
      // while q is not empty 
      // dequeue 
      curr = q.front(); 
      q.pop(); 
  
      // print node value 
      cout << curr->val << " ";if(curr->color==1){cout<<"B"; colores.push_back(to_string(curr->val)+"B");}else{cout<<"R"; colores.push_back(to_string(curr->val)+"R");}
      cout<<" ";
  
      // push children to queue 
      if (curr->left != NULL) 
        q.push(curr->left); 
      if (curr->right != NULL) 
        q.push(curr->right); 
    } 
    cout<<endl;
  } 
  
  // prints inorder recursively 
  void inorder(nodo *x) { 
    if (x == NULL) 
      return; 
    inorder(x->left); 
    cout << x->val;
    if(x->color==1){
      cout<<" R"<<"  ";
    }else{
      cout<<" B"<<"  ";
    }
    inorder(x->right); 
  } 
  
public: 
  // constructor 
  // initialize root 
  RBTree() { root = NULL; } 
  
  nodo *getRoot() { return root; } 
  
  // searches for given value 
  // if found returns the node (used for delete) 
  // else returns the last node while traversing (used in insert) 
  nodo *search(int n) { 
    nodo *temp = root; 
    while (temp != NULL) { 
      if (n < temp->val) { 
        if (temp->left == NULL) 
          break; 
        else
          temp = temp->left; 
      } else if (n == temp->val) { 
        break; 
      } else { 
        if (temp->right == NULL) 
          break; 
        else
          temp = temp->right; 
      } 
    } 
  
    return temp; 
  } 
  
  // inserts the given value to tree 
  void insert(int n) { 
    nodo *newNode = new nodo(n); 
    if (root == NULL) { 
      // when root is null 
      // simply insert value at root 
      newNode->color = BLACK; 
      root = newNode; 
    } else { 
      nodo *temp = search(n); 
  
      if (temp->val == n) { 
        // return if value already exists 
        return; 
      } 
  
      // if value is not found, search returns the node 
      // where the value is to be inserted 
  
      // connect new node to correct node 
      newNode->parent = temp; 
  
      if (n < temp->val) 
        temp->left = newNode; 
      else
        temp->right = newNode; 
  
      // fix red red voilaton if exists 
      fixRedRed(newNode); 
    } 
  } 
  
  // utility function that deletes the node with given value 
  void deleteByVal(int n) { 
    if (root == NULL) 
      // Tree is empty 
      return; 
  
    nodo *v = search(n), *u; 
  
    if (v->val != n) { 
      cout << "No node found to delete with value:" << n << endl; 
      return; 
    } 
  
    deleteNode(v); 
  } 
  
  
  // prints level order of the tree 
  void printLevelOrder() { 
    cout << "niveles: " << endl; 
    if (root == NULL) 
      cout << "vacio" << endl; 
    else
      levelOrder(root); 
    cout << endl; 
  } 


  void mostrar(nodo *root,int s){
		string ancho = to_string(root->val);
		vector<int> x;
		vector<vector<int> > y;
		stack< pair<nodo*, int> > stk;
		stk.push({ root, 0 });
		nodo* aux = NULL;
		string str;
		while (!stk.empty()){
			aux = stk.top().first;
			if (!aux) stk.pop();
			else{
				if (stk.top().second == 0){
					str = to_string(aux->val); if (str.size() > ancho.size()) ancho = str;
					stk.top().second++;
					stk.push({ aux->left, 0 });
				}

				else{
					stk.pop();
					x.push_back(aux->val);
					stk.push({ aux->right, 0 });
				}
			}
		}
		vector<nodo*> vec;
		vector<int> vecaux;
		if (root){
			vec.push_back(root);
			vecaux.push_back(root->val);
		}
		while (vec.size() > 0){
			y.push_back(vecaux);
			vecaux.clear();
			for (int i = 0, aux = vec.size(); i < aux; ++i){
				if (vec[0]->left){
					vec.push_back(vec[0]->left);
					vecaux.push_back(vec[0]->left->val);
				}
				if (vec[0]->right){
					vec.push_back(vec[0]->right);
					vecaux.push_back(vec[0]->right->val);
				}
				vec.erase(vec.begin());
			}
		} 
    int op=s;
		for (int i = 0; i < y.size(); ++i){
			for (int j = 0, e = 0; j < x.size() && e < y[i].size(); j++){
				if (y[i][e] == x[j]){
					string aux_ = to_string(x[j]);
					for (int i = aux_.size(); i < ancho.size(); ++i)
						aux_.push_back(' ');
            if(colores[op]=="-1R"){
              cout<<"         ";
              op++;
            }
            cout<<colores[op++];
					e++;
				}

				else{
					for (int i = 0; i < ancho.size(); ++i)
						cout << " ";
				}
					
			}
			cout << endl;
		}
    cout<<endl;
	}

};
int main() { 
  RBTree tree; 
  
  int arr[] = {17,12,92,35,1,25,78,3,20};
  int del[] = {35};

  for(int i=0; i<sizeof(arr)/sizeof(arr[0]); i++){
      tree.insert(arr[i]);
  }tree.printLevelOrder();
  tree.mostrar(tree.root,sizeof(arr[0])/sizeof(arr[0])*0);  
  

  for(int i=0; i<sizeof(del)/sizeof(del[0]); i++){
        tree.deleteByVal(del[i]);
  }tree.printLevelOrder();
  tree.mostrar(tree.root,sizeof(arr)/sizeof(arr[0])*1);

  return 0; 
} 


/*456729183-7698*/
/*183729456-1234*/