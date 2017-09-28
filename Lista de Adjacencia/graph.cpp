//lista de adjacencia
#include <iostream>
#include <cstdlib>
using namespace std;
typedef int Vertex;
/*
template <class T>
class Item{
private:
	Vertex chave;

public:
	Item(){}
	Item(int chave){
		this->chave=chave;
	}

	
}
*/




template <class T>
class No{
private:
    T item; //vetor de itens
    No* prox;
public:
    No(){
        this->prox = NULL;
    }

    No(T item){
        this->item = item;
        this->prox = NULL;
    }
    
    No* getProx(){
        return prox;
    }
    
    void setProx(No* prox){
        this->prox = prox;
    }
    
    T getItem(){
        return item;
    }
    
    void setItem(T item){
        this->item = item;
    }
};

template<class T>
class List{
private:
    No<T> *prim;
    No<T> *ult;
    bool vazia();
public:
	//Lista(){}
    List(){
        prim = new No<T>;
        prim->setProx(NULL);
        ult = prim;
    }

    void insere(T item);
    void mostra();
    void destroi();
    void remove(T item, No<T>* r);
    //No* busca(Jogo item);
    No<T>* predecessor(No<T>* r);
};

template <class T>
bool List<T>::vazia(){
	return prim == ult;
}


template <class T>
void List<T>::insere(T item){
    ult->setProx(new No<T>);
    ult = ult->getProx();
    ult->setProx(NULL);
    ult->setItem(item); 
}

template <class T>
void List<T>::mostra(){
    No<T> *p = prim->getProx();
    while(p != NULL){
        cout << p->getItem();
        p = p->getProx();
    }
}

template <class T>
void List<T>::destroi(){
	No<T> *p = prim->getProx();
	while(p != NULL){
		p->getItem();
		p = p->getProx();
	}
	delete(p);
}

template <class T>
void List<T>::remove(T item, No* r){
     if(vazia() || r == NULL || r == prim){
         cout << "Impossivel remoção\n";
     }
     else{
         item = r->getItem();
         No* p = predecessor(T item, No* r);
         p->getProx() = r->getProx();
         if(p->setProx(NULL)){
             delete r;
         }
     }
 }
/* 
No* Lista::busca(Jogo item){
    No* p = prim->getProx();
    while(p != NULL && p->getItem() != item){
        p = p->getProx();
    }
    return p;
}
*/
template <class T>
No* List<T>::predecessor(No* r){
     No<T>* p = prim->getProx();
     while(p->getProx() != r){
         p = p->getProx();
     }
     return p;
 }

// FIM DA LISTA


class Graph{
private:
	List<Vertex> *adj;
	int n, m; //ordem e tamanho
	void destroy();

public:
	Graph(int); //construtor
	void initialize(int);
	void insertEdge(Vertex, Vertex);
	void print();

	//void setM(int);
	int getM();

	//void setN(int);
	int getN();

	List<Vertex>* getAdj();
	void setAdj(List<Vertex> &adj);
};

Graph::Graph(int n){
	cout << "erro 1";
	initialize(n);
}

//void Graph::setAdj(List<Vertex> &adj){
//	this->adj = new List<Vertex>[n+1];
//}

List<Vertex>* Graph::getAdj(){
	return adj;
}

//void Graph::setN(int n){
//	this->n=n;
//}

int Graph::getN(){
	return n;
}

//void Graph::setM(int m){
//	this->m=m;
//}

int Graph::getM(){
	return m;
}

void Graph::initialize(int n){
	cout << "erro 2";
	if(this->n != 0){
		destroy();
	}
	this->n = n;
	adj = new List<Vertex>[n+1];
	cout << "erro 3";
}

void Graph::insertEdge(Vertex u, Vertex v){
	Vertex x = v; //chave = vertice
	adj[u].insere(x); //insere na lista
	x = u;
	adj[v].insere(x); //insere na lista
	m++;
}

void Graph::print(){
	for(int i=1; i<=n; i++){
		cout<<"v["<<i<<"]=";
		adj[i].mostra();
	}
}

void Graph::destroy(){
	for(int i=0; i<=n; i++){
		adj[i].destroi(); //destroi lista
	}
	delete [] adj;
	n=m=0;
}

void testaGrafo(Graph &g){
	cout << "jee";
	g.insertEdge(1,2);
	g.insertEdge(2,3);
	g.insertEdge(3,4);
	g.insertEdge(4,5);
	g.insertEdge(5,1);
	g.insertEdge(5,2);
	g.insertEdge(2,4);
	g.print();
	cout << "ssica";
}

int main(int argc, char const *argv[]){
	
	int n, m;
	cout << "ordem: ";
	cin >> n;
	cout << "felipe";
	Graph g(n);
	testaGrafo(g);
	cout << "filip";

	return 0;
}