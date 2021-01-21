/*lista circular doblemente enlazada
y josephus*/

#include<iostream>
using namespace std;

template<class T>
class node {
public:
	T val;
	node<T>* next;
	node<T>* prev;
	node(T x) { val = x; next = nullptr; prev = nullptr; }
};

template<class T>
class clistp {
public:
	node<T>* head;
	clistp() { head = nullptr; };

	bool find(T x, node<T>** &p) {
		p = &head;
		if (!(*p))
			return 0;
		if (x< (*p)->val)
			return 0;
		if ((*p)->val == x)
			return 1;
		p = &((*p)->next);
		for (; ((**p).val< x) && (*p) != head; p = &((*p)->next));
		return *p != head && (*p)->val == x;
	}

	bool insert(T x) {
		node<T>** p;
		if (find(x, p))
			return 0;
		node<T>* t = new node<T>(x);
		if (!(*p)) {
			t->next = t;
			t->prev = t;
			(*p) = t;
			return 1;
		}
		else {
			t->next = *p;
			if (x < head->val) {
				*p = t;
				p = &((*p)->next->next);
				while (*p != t->next && *p != (*p)->next)
					p = &((*p)->next);
			}
			t->prev = (*p)->prev;
			(*p)->prev = t;
			*p = t;
		}
		return 1;
	}

	bool remove(T x) {
		node<T>** p;
		if (!find(x, p))
			return 0;
		node<T>* t = *p;
		if (*p == head) {
			if (*p == (*p)->next) {
				head = nullptr;
				delete[] t;
				return 1;
			}
			else {
				*p = (*p)->next;
				(*p)->prev = t->prev;
				while (*p != t)
					p = &((*p)->next);
				*p = t->next;
				delete[] t;
				return 1;
			}
		}
		*p = (*p)->next;
		(*p)->prev = t->prev;
		delete[] t;
		return 1;
	}

	void show() {
		if (head) {
			cout << head->val << " ";
			for (node<T>* i = head->next; i != head && head; i = i->next)
				cout << i->val << " ";
			/*cout << endl;
			for (node<T>* i = head->prev; i != head && head; i = i->prev)
				cout << i->val << " ";
			cout << head->val << " ";
			cout<<endl;*/
		}
		else{
			cout<<"lista vacia----"<<endl;
		}
	}
	~clistp() {
		node<T>*t = head->next;
		while (!(t->next)) {
			node<T>*p = head;
			head = t;
			delete[]p;
			t = t->next;
		}
		delete[]t;
	}

	void josephus(int n, int k) {
		for (int i = 1; i <= n; i++)
			insert(T(i));
		//show();
		//cout << endl;
		node<T>* c = head;
		for (int i = n - 1; i != 0; i--) {
			for (int j = k - 1; j != 0; j--)
				c = c->next;
			node<T>* p = c->next;
			remove(c->val);
			//show();
			if(p->next->next==head){
				show();cout << endl;
			}
			//cout << endl;
			c = p;
		}
	}
};

int main(){
	clistp<int> a;
	int n,k;
	cout <<"soldados:";cin>>n;
	cout <<"k: ";cin>>k;
	a.josephus(n, k);
	//a.show();
	/*a.insert(5);
	a.insert(6);
	a.insert(3);
	a.insert(2);
	a.insert(1);
	a.insert(45);*/

/*
	 clistp<int> a;
     int opcion=0,valor;
	 cout<<"      <-->     "<<endl;
     cout<<"    Insertar [1]"<<endl;
     cout<<"    Borrar   [2]"<<endl;
     cout<<"    Salir    [3]"<<endl;
    do{
         cout<<"Opcion: ";
         cin>>opcion;
        if(opcion == 1){
            cout<<"> ";cin>>valor;
            a.insert(valor);
            a.show();
        }
        if(opcion == 2){
            cout<<"> ";cin>>valor;
            a.remove(valor);
            a.show();
        }
    }while(opcion!=3);
	a.show();*/
}

// p-103