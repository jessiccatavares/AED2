#include <iostream>
#include <cstdlib>
using namespace std;
/*
template <class T>
class Jogo{
private:
    T nome;
    T genero;
public:
    Jogo(){}
    Jogo(T nome, T genero){
        this->nome = nome;
        this->genero = genero;
    }
    
    T getNome(){
        return nome;
    }
    
    void setNome(T nome){
        this->nome = nome;
    }
    
    T getGenero(){
        return genero;
    }
    void setGenero(T genero){
        this->genero = genero;
    }
    
    void print(){
        cout << nome << "|" << genero << endl;
    }
};
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
class Lista{
private:
    No<T> *prim;
    No<T> *ult;
public:
	//Lista(){}
    Lista(){
        prim = new No<T>;
        prim->setProx(NULL);
        ult = prim;
    }

    void insere(T item);
    void mostra();
    //void remove(Jogo item, No* r);
    //No* busca(Jogo item);
    //No* predecessor(No* r);
};

template <class T>
void Lista<T>::insere(T item){
    ult->setProx(new No<T>);
    ult = ult->getProx();
    ult->setProx(NULL);
    ult->setItem(item); 
}

template <class T>
void Lista<T>::mostra(){
    No<T> *p = prim->getProx();
    while(p != NULL){
        cout << p->getItem();
        p = p->getProx();
    }
}

/*
void Lista::remove(Jogo item,No* r){
     if(Jogo item == 0 || r == NULL || r == prim){
         cout << "Impossivel remoção\n";
     }
     else{
         item = r->getItem();
         No* p = predecessor(Jogo item,No* r);
         p->getProx() = r->getProx();
         if(p->setProx(NULL)){
             delete r;
         }
     }
 }
 
No* Lista::busca(Jogo item){
    No* p = prim->getProx();
    while(p != NULL && p->getItem() != item){
        p = p->getProx();
    }
    return p;
}

No* Lista::predecessor(No* r){
     No* p = prim->getProx();
     while(p->getProx() != r){
         p = p->getProx();
     }
     return p;
 }
*/
int main(int argc, char** argv) {
    Lista <string> lista;
    //Jogo a("Cod","Fps");
    //Jogo b("Gow","Aventura");
    //Jogo c("Naruto","Luta");
    lista.insere("filip");
    lista.insere("jess");
    lista.insere("flavio");
    lista.mostra();

    return 0;
}

