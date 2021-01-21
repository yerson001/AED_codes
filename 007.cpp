/*lista simple con find usado en la funcion delete */
#include<iostream>
using namespace std;

template<class T>
class nodo{
public:
    T dato;
    nodo<T>*next;
    nodo(T x){dato = x; next = nullptr;}
};

template<class T>
class lista{
public:
    nodo<T>*head;
    lista(){head = nullptr;}

    bool find(T x,nodo<T>*&pos){
        pos = nullptr; // pos devuelve la posicion 
        for(nodo<T>*p = head; p && p->dato<=x; pos = p,p = p->next){
                    if(p->dato == x)
                        return 1;}
        return 0;
    }

    bool insert(T x){
        nodo<int>*pos;
        nodo<int>*t;
        if(head==nullptr)
            head = new nodo<T>(x);
        else{
            if(find(x,pos)==1){
                return 0;
            }
             t = new nodo<T>(x);
            if(pos == nullptr){
                t->next = head;
                head = t;
            }
            else{
                t->next = pos->next;
                pos->next = t;
                
            }
        }
        return 1;
    }
    bool delete_(T x){
        nodo<T>*pos;
        nodo<T>*t;
        if(head == nullptr){//cout <<"no enconttrado"<<endl;
            return 0;
        }
        else{
            if(find(x,pos)==1){
                if(head->dato == x){//cout<<"io"<<endl;
                    head = head->next;
                    delete pos;
                }
                else{
                    t = pos->next;
                    pos->next = t->next;
                    delete t;
                }
            }
        }
        return 1;
    }

    void show(){
        if(head){
            nodo<T>*iterador = head;
            while(iterador){
                    cout<<iterador->dato<<" -> "; iterador=iterador->next;
            }cout<<"null"<<endl;
        }
        else{
            cout<<"lista vacia"<<endl;
        }
    }
};

int main(){//183279
    /*lista<int> a;
    a.insert(1);
    a.insert(8);
    a.insert(3);
    a.insert(2);
    a.insert(7);
    a.insert(9);
    a.insert(-2);
    a.show();
    a.delete_(1);
    a.delete_(-2);
    a.delete_(9);
    a.show();*/

    int a = 5;
    int *p;
    int **ptr;
    ///////////////////
    p = &a;
    cout <<*p<<endl;//5
    ptr = &p;
    cout <<**ptr<<endl;

    return 0;
}