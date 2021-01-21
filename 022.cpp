/*grafos*/
#include <iostream>
#include <vector>

using namespace std;

template <class G>
class nodo{
public:
    typedef typename G::N N;
    typedef typename G::Edge Edge;
    nodo(N x){
        m_data=x;
    }

    N m_data;
    vector<Edge*> m_aristas;
	
	void print_aristas(){
		if(m_aristas.size()>0){
			for(int i=0;i<m_aristas.size();i++){
				if(m_aristas[i]->m_dir == 0){//bidireccion
					cout<<m_aristas[i]->m_data<<"(";
					if(m_aristas[i]->m_node[0]->m_data==m_data){
						cout<< m_aristas[i]->m_node[1]->m_data<<")-";
					}
                    else{
						cout<< m_aristas[i]->m_node[0]->m_data<<")-";
					}	
				}
                else{//de 0 a 1
					if(m_aristas[i]->m_node[0]->m_data==m_data){
						cout<<m_aristas[i]->m_data<<"(";
						cout<< m_aristas[i]->m_node[1]->m_data<<")-";
					}
				}
			}
			cout<<"\n";
		}else{
			cout<<"--\n";}
	}
};

template <class G>
class arista{
public:
    typedef typename G::Node Node;
    typedef typename G::E E;
    bool m_dir;//0 BIDIRECCIONAL---1 UNIDIRECCIONAL
    E m_data;
    Node* m_node[2];
    
    //valor de arista  -->start-->end --> direccion
    arista(E x,Node *a, Node *b, bool dir){
        m_node[0]=a;
        m_node[1]=b;
        m_data=x;
        m_dir=dir;
    }
};

template <class n, class e>// "n" es el valor de la arista   y  "e" es la letra del nodo
class grafo{
public:
    typedef grafo<n,e> self;//para el mismo 
    typedef nodo<self> Node;// a todo    c_Node<selt>  = node
    typedef arista<self> Edge;
    typedef n N;
    typedef e E;

    vector<Node*> m_nodes;//vector de nodos 
    vector<Edge*> m_edges;// vector de aristas

    bool insert_node(N);        //insertar nodo
    bool remove_node(N);        //remover nodo
    bool insert_edge(E,N,N,bool);//insert arista
    bool remove_edge(E,N,N);    //remover arista
   
	
	void recorrer_grafo(){  // solo recorres el vector m_nodos
		cout<<"nodos del grafo: "<<endl;
		for(int i=0;i<m_nodes.size();i++){
			cout<<m_nodes[i]->m_data<<" : ";//imprime el nodo
			m_nodes[i]->print_aristas();    //la arista del nodo
		}
	}
};

template <class n, class e>
bool grafo<n,e>::insert_node(N x){
    //c_Node<grafo<n,e> > *new_node = new c_Node<grafo<n,e> >(x); 
    Node* new_node=new Node(x);
    m_nodes.push_back(new_node);
    return 1;   
}

template <class n, class e>// E = letra N = valor_begin N = valo_rend dir orientacion  
bool grafo<n,e>::insert_edge(E x,N a,N b,bool dir){  // 1 = en una direccion  0 = bidireccional

    Node *N_start,*N_end;//inicio---->final
    for(int i=0; i<m_nodes.size(); i++){
        if(m_nodes[i]->m_data==a)
             N_start = m_nodes[i];
        if(m_nodes[i]->m_data==b)
             N_end = m_nodes[i];
    }
    Edge* new_edge = new Edge(x,N_start,N_end,dir);
    N_start->m_aristas.push_back(new_edge);
    N_end->m_aristas.push_back(new_edge);
    m_edges.push_back(new_edge);
    return 1;
}

template <class n, class e>
bool grafo<n,e>::remove_edge(E x,N a,N b){

    Node *Na,*Nb;
    for(int i=0; i<m_nodes.size(); i++){
        if(m_nodes[i]->m_data==a)
             Na=m_nodes[i];
        if(m_nodes[i]->m_data==b)
             Nb=m_nodes[i];
    }
    Edge* borrar;
    for(int i=0; i<m_nodes.size(); i++){
        for(int j=0; j<m_nodes[i]->m_aristas.size(); j++){
            if((m_nodes[i]->m_aristas[j])->m_data==x && (m_nodes[i]->m_aristas[j])->m_node[0]==Na && (m_nodes[i]->m_nedges[j])->m_node[1]==Nb){
                m_nodes[i]->m_aristas.erase(m_nodes[i]->m_aristas.begin()+j);
            }
        }
    }
    for(int i=0; i<m_edges.size(); i++){
        if((m_edges[i])->m_data==x && (m_edges[i])->m_node[0]==Na && (m_edges[i])->m_node[1]==Nb){
            borrar= m_edges[i];
            m_edges.erase(m_edges.begin()+i);
            delete borrar;
        }
    }
    return 1;
}

template <class n, class e>
bool grafo<n,e>::remove_node(N x){
    Node* borrar;
    for(int i=0; i<m_nodes.size(); i++){
        if((m_nodes[i])->m_data==x){
            borrar= m_nodes[i];
            for(int j=0; j<(m_nodes[i])->m_aristas.size(); j++){
                remove_edge(((m_nodes[i])->m_aristas[j])->m_data,((m_nodes[i])->m_aristas[j])->m_node[0]->m_data,((m_nodes[i])->m_nedges[j])->m_node[1]->m_data);
            }
            m_nodes.erase(m_nodes.begin()+i);
            delete borrar;
        }
    }
    return 1;
}

int main()
{
    grafo<int,string> a;

    a.insert_node(1);
    a.insert_node(2);
    a.insert_node(3);
    a.insert_node(4);
    a.insert_edge("a",1,2,0);
	a.insert_edge("b",1,2,1);
    a.insert_edge("c",1,3,1);
    a.insert_edge("d",3,2,0);
    a.insert_edge("e",1,4,1);
    a.insert_edge("f",4,2,1);
    a.recorrer_grafo();
    /*
    a.remove_edge("a",1,2);
    a.recorrer_grafo();
    a.remove_node(1);
	a.recorrer_grafo();
    */
    return 0;
}

//cuando tiene parametrizado se pone typedef typename list<int> l
//cuando no es para metrizado como int no se pone 