#include <iostream>

using namespace std;

typedef int Vertex;

class Item{
private:
    Vertex it;
public:
    Item();
    void setItem(Vertex);
    int getItem();
    void show();
};

Item::Item(){
}

void Item::setItem(Vertex it){
    this->it = it;
}

int Item::getItem(){
    return it;
}

void Item::show(){
  cout << it << endl;
}

class No{
private:
    Item it;
    No *prox;
public:
    No(){
      this->prox = NULL;
    }
    No(Item it){
      this->it = it;
      this->prox = NULL;
    }
    void setProx(No *prox){
        this->prox = prox;
    }
    No *getProx(){
        return prox;
    }
    void setItem(Item it){
      this->it = it;
    }
    Item getItem(){
       return it;
    }
};

class Lista{
private:
   No *prim;
   No *ult;
public:
    Lista(){
      prim = new No;
      prim->setProx(NULL);
      prim = ult;
    }
    void insere(Item);
    void mostra();
    void destroi();
};

void Lista::insere(Item it){
  ult->setProx(new No);
  ult->setProx(NULL);
  ult->getProx();
  ult->setItem(it);
}

void Lista::mostra(){
  No *nav = prim->getProx();
  while(nav != NULL){
    nav->getItem().show();
    nav = nav->getProx();
  }
}

void Lista::destroi(){
  No *nav = prim->getProx();
  while(nav != NULL){
    nav->getItem();
    nav = nav->getProx();
  }
  delete(nav);
}

class Grafo{
private:
  int n,m;
  Lista *adj;
  void destroy();
public:
  Grafo(int);
  void inicializa(int);
  void insertEdge(Vertex, Vertex);
  void print();
};
//Métodos Privados//
void Grafo::destroy(){
  for(int i = 0; i <= n; i++){
    adj[i].destroi();
  }
}
//Métodos Públicos//

Grafo::Grafo(int n){
  inicializa(n);
}

void Grafo::inicializa(int n){
  if(this->n != 0){
    destroy();
  }
  this->n = n;
  adj = new Lista[n + 1];
}

void Grafo::insertEdge(Vertex u, Vertex v){
  Item *x = new Item(v);
  adj[u].insere(x);
  x = u;
  adj[v].insere(x);
  m++;
}

void Grafo::print(){
  for(int i = 1; i <= n; i++){
    cout << "v[" << i << "]= ";
    adj[i].mostra();
  }
}

void testaGrafo(Grafo &g){
  g.insertEdge(1,2);
  g.insertEdge(2,3);
  g.insertEdge(3,4);
  g.insertEdge(4,5);
  g.insertEdge(5,6);
  g.insertEdge(6,7);
  g.print();
}

int main(){
  int n,m;
  cout << "Ordem: ";
  cin >> n;
  Grafo g(n);
  testaGrafo(g);
  return 0;
}
