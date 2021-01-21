/*  avl */
#include <iostream>
#include <list>
#include <algorithm>
#include<vector>
#include <queue>
#include<stack>
using namespace std;

typedef unsigned int uint;
typedef unsigned short ushort;

//1, 8, 3, 7, 2, 9, 4, 5, 6

template <class T>
struct nodo{
	T valor;
	nodo<T>* hijo[2];
	short height;
	ushort depth;
	nodo(T x){
		hijo[0] = hijo[1] = 0;
		valor = x;
		height = 0;
		depth = 0;
	}
};

template <class T>
void printList(list<nodo<T>* > xd){
	for(typename list<nodo<T>* >::iterator it = xd.begin(); it != xd.end(); it++){
		cout << (*it)->valor <<"  altura: "<<(*it)->height<<"  profun: "<<(*it)->depth<<endl;
	}
	cout << endl;
}

template <class T>
struct Menor{
	inline bool operator()(T a, T b){
		return a<b;
	}
};

template <class T, class C>
class AVL{
public:
	nodo<T>* root;
	C mc;
	AVL();
	bool find(T x, nodo<T>**& p);
	bool insert(T x);
	bool remove(T x);
	void inorder(nodo<T>* p);
	//private:
	nodo<T>** Rep(nodo<T>** p);
	short getHeight(nodo<T>* p);
	void mostrar(nodo<T> *root);
private:
	bool findInPath(nodo<T>* p);
	bool findHeight(nodo<T>**& p, short& h);
	void updateDepth();
	void updateDepthR();
	void updateHeights(T x);
	list< nodo<T>* > path;
	short posInList(T val);
	void RR(nodo<T>** p);
	void LL(nodo<T>** p);
	void LR(nodo<T>** p);
	void RL(nodo<T>** p);
};

template <class T, class C>
bool AVL<T,C>::findInPath(nodo<T>* p){
	for (typename list<nodo<T>* >::iterator it = path.begin(); it != path.end(); it++){
		if ( *it == p ) return 1;
	}
	return 0;
}

template <class T, class C>
short AVL<T,C>::posInList(T val){
	short i = 1;
	typename list<nodo<T>* >::iterator it;
	for(it = path.begin() ; it != path.end() && (*it)->valor != val; it++, i++);
	if (it == path.end() ) return -1;
	return i;
}

template <class T, class C>
bool AVL<T,C>::findHeight(nodo<T>**& p, short& h){
	for(typename list<nodo<T>*>::reverse_iterator it = path.rbegin(); it != path.rend(); it++){
		if ((*it)->height == 2){
			p = &(*it);
			if ( (*it)->hijo[1]->height == -1) h = 3;
			else h = 2;
			return 1;
		} else if ((*it)->height == -2){
			p = &(*it);
			if ( (*it)->hijo[0]->height == 1) h = -3;
			else h = -2;
			return 1;
		}
	}
	return 0;
}

template <class T, class C>
void AVL<T,C>::RR(nodo<T>** p){
	cout<<"_______________en RR:________________ "<<(*p)->valor<<endl;
	printList(path);
	cout<<"list size : "<<path.size()<<endl;

	typename list<nodo<T>*>::iterator it = path.end();
	bool LR = 0, RL = 0;
	cout<<"el seg hijo 1 : "<<(*p)->hijo[1]->hijo[1]->valor<<" altura "<<(*p)->hijo[1]->hijo[1]->height<<endl;
	if ( (*p)->hijo[1] && (*p)->hijo[1]->hijo[1] && (*p)->hijo[1]->hijo[1]->height == -1)
		 LR = 1;
	if ( (*p)->height  == 1) {
		RL = 1; LR = 0;
		}
	while ( (*it) != (*p) ){
		it--;
	}
	cout<<"it valor "<<(*it)->valor<<"  -- p "<<(*p)->valor<<"  root: "<<root->valor<<endl;
	nodo<T>* temp, *father;
	if (*it != root){ //si es que se tiene que balancear
		it--;
		if (RL){
			while( *p != (*it)->hijo[0]) it--; //busca en el camino hasta encontrar el padre de p
			temp = *it;
		}
		 else//temp = *(--it); //fuera de la raiz
		temp = *(it);
	}
	nodo<T>* gfather = *p;
	father = (*p)->hijo[1];
	if (!findInPath(father) )
		 path.push_back(father);
	nodo<T> *bl = father->hijo[0];
	father->hijo[0] = gfather;
	gfather->hijo[1] = bl;
	cout<<"raiz act: "<<root->valor<<endl;
	if (root == gfather) 
		root = father;
	else {
		if (father->valor < temp->valor ) 
			temp->hijo[0] = father;
		else
		 temp->hijo[1] = father;
	}
}

template <class T, class C>
void AVL<T,C>::LL(nodo<T>** p){
	cout<<"____________________LL______________"<<(*p)->valor<<endl;
	printList(path);
	bool LR = 0, RL = 0;
	//cout<<"el seg hijo 1 : "<<(*p)->hijo[0]->hijo[0]->valor<<" altura "<<(*p)->hijo[0]->hijo[0]->height<<endl;
	typename list<nodo<T>*>::iterator it = path.end();
	if ((*p)->hijo[0] && (*p)->hijo[0]->hijo[0] && (*p)->hijo[0]->hijo[0]->height == 1 )
		 RL = 1;
	if ( (*p)->height == -1) {
		LR = 1; RL = 0;
		}
	while ( (*it) != (*p)){
		it--;
	}
	cout<<"it "<<(*it)->valor<<"  p"<<(*p)->valor<<endl;
	nodo<T>* temp, *father;
	if (*it != root){ //si es que se tiene que balancear
		--it;
		if (LR){
			while( *p != (*it)->hijo[1]) it--; //busca en el camino hasta encontrar el padre de p
			temp = *it;
		}
		 else
			temp = (*it);
	}
	nodo<T>* gfather = *(p);
	father = (*p)->hijo[0];
	nodo<T> *br = father->hijo[1];
	if (!findInPath(father) )
		 path.push_back(father);
	father->hijo[1] = gfather;
	gfather->hijo[0] = br;
	if (root == gfather){
		root = father;
	}
	else {
		if (father->valor > temp->valor)
			 temp->hijo[1] = father;
		else
			 temp->hijo[0] = father;
	}
}

template <class T, class C>
void AVL<T,C>::LR(nodo<T>** p){
	if (!findInPath( (*p)->hijo[1] ) ) path.push_back((*p)->hijo[1]);
	LL( &(*p)->hijo[1]);
	RR(p);
}

template <class T, class C>
void AVL<T,C>::RL(nodo<T>** p){
	if (!findInPath( (*p)->hijo[0] ) )
		 path.push_back((*p)->hijo[0]);
	RR( &(*p)->hijo[0]);
	LL(p);
}

template <class T, class C>
nodo<T>** AVL<T,C>::Rep(nodo<T>** p){
	for(p = &(*p)->hijo[0]; *p && (*p)->hijo[1]; p = &(*p)->hijo[1]){ //the university-one like
		path.push_back(*p);
	}
	path.push_back(*p);
	return p;
}

template <class T, class C>
short AVL<T,C>::getHeight(nodo<T>* p){
	//if (p->valor == x) return 0;
	short left, right;
	if (p->hijo[0])
		 left = (p)->hijo[0]->depth;
	else
		 return (p->depth);//left = 0;
	if (p->hijo[1]) {
		right = p->hijo[1]->depth;
	}
	else 
		return -p->depth;//right = 0; si no tiene hijo 1 su altura es -1
	return right - left;
}

template <class T, class C>
void AVL<T,C>::updateHeights(T x){
	for(typename list<nodo<T>* >::iterator it = path.begin(); it != path.end(); it++){
		(*it)->height = getHeight(*it);
	}
}

template <class T, class C>
void AVL<T,C>::updateDepth(){
	nodo<T>** p;
	bool balance = 0;
	ushort lDepth, rDepth;
	typename list<nodo<T>* >::reverse_iterator rit = path.rbegin();
	while(rit != path.rend() ){
		if ( !(*rit)->hijo[0] && !(*rit)->hijo[1] ){
			(*rit)->depth = 0;
			rit++;
			continue;
		}
		if ( (*rit)->hijo[0] ) lDepth = (*rit)->hijo[0]->depth;
		else lDepth = 0;
		if ( (*rit)->hijo[1] ) rDepth = (*rit)->hijo[1]->depth;
		else rDepth = 0;
		(*rit)->depth = max(lDepth, rDepth) + 1;
		(*rit)->height = getHeight(*rit);
		if ((*rit)->height == 2){
			p = &(*rit);
			balance = 1;
			if ( getHeight((*rit)->hijo[1]) == -1){
				LR(p);
			}
			else{
				RR(p);
			}
		} else if ((*rit)->height == -2){
			p = &(*rit);
			balance = 1;
			if ( getHeight((*rit)->hijo[0]) == 1){
				RL(p);
			}
			else{
				LL(p);
			}
		}
		if (balance){
			break;
		}
		rit++;
	}
}

template <class T, class C>
void AVL<T,C>::updateDepthR(){
	ushort lDepth, rDepth;
	typename list<nodo<T>* >::iterator it = path.begin();
	while(it != path.end() ){
		if ( !(*it)->hijo[0] && !(*it)->hijo[1] ){
			(*it)->depth = 0;
			it++;
			continue;
		}
		if ( (*it)->hijo[0] ) lDepth = (*it)->hijo[0]->depth;
		else lDepth = 0;
		if ( (*it)->hijo[1] ) rDepth = (*it)->hijo[1]->depth;
		else rDepth = 0;
		(*it)->depth = max(lDepth, rDepth) + 1;
		(*it)->height = getHeight(*it);
		it++;
	}
}


template <class T, class C>
AVL<T,C>::AVL(){
	this->root = 0;
}

template <class T, class C>
bool AVL<T,C>::find(T x, nodo<T>**& p){
	for(p = &root; *p && (*p)->valor != x; p = &((*p)->hijo[mc((*p)->valor, x)])){
		path.push_back(*p);
	}
	return !!*p;
}

template <class T, class C>
bool AVL<T,C>::insert(T x){
	nodo<T>** p;
	if(find(x, p)){
		path.clear();
		return 0;
	}
	*p = new nodo<T>(x);
	path.push_back(*p);
	updateDepth();
	updateDepthR();

	printList(path);

	path.clear();
	return 1;
}

template<class T, class C>
bool AVL<T,C>::remove(T x){
	nodo<T>** p;
	if(!(find(x,p))){
		path.clear();
		return 0;
	}
	path.push_back(*p);
	cout<<"se elimina: "<<(*p)->valor<<endl;
	if ((*p)->hijo[0] && (*p)->hijo[1]){
		nodo<T>** q = Rep(p);
		(*p)->valor = (*q)->valor;
		p = q;
	}
	nodo<T>* temp = *p;
	*p = (*p)->hijo[(*p)->hijo[1]!=0];
	delete temp;
	path.pop_back();
	//mostrar(root);
	updateDepth();
	updateDepthR();
	path.clear(); 
	return 1;
}

template <class T, class C>
void AVL<T,C>::inorder(nodo<T>* p){
	if (!p) return;
	inorder(p->hijo[0]);
	cout << p->valor << " ";
	inorder(p->hijo[1]);
}

template <class T, class C>
void AVL<T,C>::mostrar(nodo<T> *root){
		string ancho = to_string(root->valor);
		vector<T> x;
		vector<vector<T> > y;
		stack< pair<nodo<T>*, int> > stk;
		stk.push({ root, 0 });
		nodo<T>* aux = NULL;
		string str;
		while (!stk.empty()){
			aux = stk.top().first;
			if (!aux) stk.pop();
			else{
				if (stk.top().second == 0){
					str = to_string(aux->valor); if (str.size() > ancho.size()) ancho = str;
					stk.top().second++;
					stk.push({ aux->hijo[0], 0 });
				}
				else{
					stk.pop();
					x.push_back(aux->valor);
					stk.push({ aux->hijo[1], 0 });
				}
			}
		}
		vector<nodo<T>*> vec;
		vector<T> vecaux;
		if (root){
			vec.push_back(root);
			vecaux.push_back(root->valor);
		}
		while (vec.size() > 0){
			y.push_back(vecaux);
			vecaux.clear();
			for (int i = 0, aux = vec.size(); i < aux; ++i){
				if (vec[0]->hijo[0]){
					vec.push_back(vec[0]->hijo[0]);
					vecaux.push_back(vec[0]->hijo[0]->valor);
				}
				if (vec[0]->hijo[1]){
					vec.push_back(vec[0]->hijo[1]);
					vecaux.push_back(vec[0]->hijo[1]->valor);
				}
				vec.erase(vec.begin());
			}
		} 
		for (int i = 0; i < y.size(); ++i){
			for (int j = 0, e = 0; j < x.size() and e < y[i].size(); j++){
				if (y[i][e] == x[j]){
					string aux = to_string(x[j]);
					for (int i = aux.size(); i < ancho.size(); ++i)
						aux.push_back(' ');
					cout << aux;
					e++;
				}

				else{
					for (int i = 0; i < ancho.size(); ++i)
						cout << " ";
				}
					
			}
			cout << endl;
		}
		cout<<"_______________________________"<<endl;
	}
int main(int argc, char *argv[]) {
	AVL<int, Menor <int> > a;

	int arr[] = {4,5,6,7,2,9,1,8,3};
	int tam = sizeof(arr)/sizeof(arr[0]);
	for (int i = 0; i < tam; i++) {
		a.insert(arr[i]);
		a.mostrar(a.root);
	}//a.mostrar(a.root);
cout<<"________________________"<<endl;
	a.remove(7);
	a.mostrar(a.root);
	/*
	a.remove(6);
	a.mostrar(a.root);
	a.remove(9);
	a.mostrar(a.root);
	a.remove(8);
	a.mostrar(a.root);
*/
/*456729183-7698*/
/*183729456-1234*/

	return 0;
}
