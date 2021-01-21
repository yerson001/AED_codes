/*lista simple doblemente enlazada*/
#include<iostream>
using namespace std;

template<class T>
class nodo
{
    public:
        T valor;
        nodo *next;
        nodo *prev;
        nodo();
        nodo(T valor,nodo<T>*next=NULL,nodo<T>*p=NULL){
            this->valor=valor;
            this->next=next;
            this->prev=p;
        }
       ~nodo(){
            cout<<"nuerto"<<endl;
        }

};

template <class T>
class lista{
public:
    nodo<T>*head=NULL,*tail=NULL;
    lista(){};
    bool findd(T dato, nodo<T>*&ptr){
        ptr=0;
        for(nodo<T>*p=head;p&&p->valor<=dato;ptr=p,p=p->next){
            if(p->valor==dato)
                return true;
        }return false;
    }
    void add(T dato){
        nodo<T>*pos;
        if(!findd(dato,pos)){
            if(!pos){
                if(!head)
                    head = new nodo<T>(dato,head,head); tail=head;
                else{
                    nodo<T>*tmp = new nodo<T>(dato,head);
                    head->prev=tmp;
                    head=tmp;
                }
            }
            else
            {
                nodo<T>*tmp=new nodo<T>(dato,pos->next,pos);
                pos->next=tmp;
                if(tmp->next){
                tmp->next->prev=tmp;}
                else{tail=tmp;}
            }
            //cout<<"head "<<head->valor<<endl;
            //cout<<"tail "<<tail->valor<<endl;

        }
    }
    void remove(T dato){
        nodo<T>*pos;
        if(findd(dato,pos)){
            if(!pos){
                nodo<T>*tmp=head;
                head=head->next;
                head->prev=NULL;
                delete tmp;
            }
            else{
                nodo<T>*tmp=pos->next;
                pos->next=pos->next->next;
                if(pos->next){
                    pos->next->prev=pos;//cout<<"pos"<<pos->valor;
                }
                else{
                    tail=tail->prev;
                }
                delete tmp;
            }
        }
    }
    void imprimir(){
    nodo<T>*d=this->head;
        if(d){
        while(d!=NULL){
                cout<<d->valor<<" -> ";
                d=d->next;
            }cout<<"NULL"<<endl;
        }
        else{
        cout<<"lista vacia"<<endl;
        }
    }
    ~lista(){
        cout<<"delete"<<endl;
        while(head){
            remove(head->valor);
        }
    }
    void imprimi_(){
    nodo<T>*d=this->tail;
    if(!d)
        cout<<"lista esta vacia"<<endl;
        else{
            while(d!=NULL){
                cout<<d->valor<<" <- ";
                d=d->prev;
            }cout<<"null"<<endl;
        }
    }
};


int main(){
    lista<int> a;
     int opcion=0,valor;
	 cout<<"      <-->        "<<endl;
     cout<<"    Insertar [1]"<<endl;
     cout<<"    Borrar   [2]"<<endl;
     cout<<"    print R  [3]"<<endl;
     cout<<"    Salir    [4]"<<endl;
    do{
         cout<<"Opcion: ";
         cin>>opcion;
        if(opcion == 1){
            cout<<"> ";cin>>valor;
            a.add(valor);
            a.imprimir();
        }
        if(opcion == 2){
            cout<<"> ";cin>>valor;
            a.remove(valor);
            a.imprimir();
        }
       if(opcion == 3){
            a.imprimi_();
        }
    }while(opcion!=4);

    return 0;
}