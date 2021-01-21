/*lista enlazada circular con doble puntero en find
y jodephus*/
#include<iostream>
using namespace std;

template<class T>
struct node {
	T val;
	node<T>* next;
	node(T x) { val = x; next = nullptr; }
};

template<class T>
struct clistp {
	node<T>* head;
	clistp() { head = nullptr; };

	bool find(T x, node<T>** &p) {
		p = &head;
		if (!(*p))
			return 0;
		if (x<(*p)->val)
			return 0;
		if ((*p)->val == x)
			return 1;
		p = &((*p)->next);
		for (; (**p).val< x && (*p) != head; p= &((*p)->next));
		return *p!= head && (*p)->val == x;
	}

	bool insert(T x) {
		node<T>** p;
		if (find(x, p))
			return 0;
		node<T>* t = new node<T>(x);
		if (!(*p)) {
			t->next = t;
			(*p) = t;
		}
		else if (*p) {
			t->next = *p;
			if (x< head->val) {
				*p = t;
				p = &((*p)->next->next);
				while (*p != t->next)
					p = &((*p)->next);
			}
			*p = t;
		}
		return 1;
	}

	bool remove(T x) {
		node<T>** p;
		if (!find(x, p))
			return 0;
		if (*p == head) {
			if (*p == (*p)->next) {
				head = nullptr;
				delete[] head;
				return 1;
			}
			*p = (*p)->next;
			while ((*p)->next != head)
				p = &((*p)->next);
			node<T>* t = *p;
			*p = head;
			delete[]t;
		}
		else {
			node<T>* t = *p;
			*p = t->next;
			delete[] t;
		}
		return 1;
	}

	void show() {
		if (head) {
			cout << head->val << " ";
			for (node<T>* i = head->next; i != head && head; i = i->next)
				cout << i->val << " ";
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
		show();
		cout << endl;
		node<T>* c = head;
		for (int i = n - 1; i != 0; i--) {
			for (int j = k - 1; j != 0; j--)
				c = c->next;
			node<T>* p = c->next;
			remove(c->val);
			show();
			cout << endl;
			c = p;
		}
	}
};

int main()
{
	clistp<int> a;
	a.josephus(12,2);
	a.show();
}