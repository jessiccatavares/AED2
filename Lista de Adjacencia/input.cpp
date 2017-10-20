#include <iostream>
#include <vector>
#define NIL -1
using namespace std;

void printInt(vector< pair<int,int> > vec){
	for ( vector <pair<int,int> >::const_iterator it = vec.begin(); it != vec.end (); it++){
		cout <<"("<<it->first << ", " << it->second<<")"<<endl;
	}
}

void print(vector< pair<string,int> > vec){
	for ( vector <pair<string,int> >::const_iterator it = vec.begin(); it != vec.end (); it++){
		cout <<"("<<it->first << ", " << it->second<<")"<<endl;
	}
}

vector<pair<int,int> > convertePosicao(vector<string> jogadas){
	vector<int> numeros {NIL,49, 50, 51, 52, 53, 54, 55, 56}; //1,2,3...
	vector<int> letras {NIL,97, 98, 99, 100, 101, 102, 103, 104};//a,b,c,d...
	vector<pair<int, int> > coordenadas;
	pair<int, int> par;

	for (int i = 0; i < jogadas.size(); ++i){
		par = make_pair(jogadas[i][0],jogadas[i][1]);
		coordenadas.push_back(par);
	}

	for (int i = 0; i < coordenadas.size(); ++i){
		for (int j = 1; j <= letras.size(); ++j){
			if(coordenadas[i].first == letras[j]){
				coordenadas[i].first=j;
			}
		}
	}

	for (int i = 0; i < coordenadas.size(); ++i){
		for (int j = 1; j <= numeros.size(); ++j){
			if(coordenadas[i].second == numeros[j]){
				coordenadas[i].second=j;
			}
		}
	}
	return coordenadas;
}

vector<pair<string,int> > invertePosicao(vector<pair<int,int> > jogadas){
	//vector<int> numeros {NIL,49, 50, 51, 52, 53, 54, 55, 56}; //1,2,3...
	vector<int> letras {NIL,97, 98, 99, 100, 101, 102, 103, 104};//a,b,c,d...
	vector<pair<string, int> > coordenadas;
	pair<string, int> par;

	for (int i = 0; i < jogadas.size(); ++i){
		for (int j = 1; j <= letras.size(); ++j){
			if(jogadas[i].first == j){
				par = make_pair(letras[j],jogadas[i].second);
				coordenadas.push_back(par);
			}
		}
	}
	return coordenadas;
}


int main(int argc, char const *argv[]){
	vector<pair<int,int> > posicoes;
	vector<pair<string,int> > saida;
	vector<string> jogadas;
	pair<int, int> pos;
	string entrada;

	//vector<pair<int,int> > cord {{1,1},{1,8},{7,3},{8,5}};

	for(int i = 0; i < 5; ++i){
		cin >> entrada;
		cin.ignore();
		jogadas.push_back(entrada);
	}
	posicoes = convertePosicao(jogadas);
	printInt(posicoes);
	//for (int i = 0; i < posicoes.size(); ++i){
	//	if(i == posicoes.size()-1){
	//		pos = posicoes[i];
	//		cout << "king: " << pos.first <<", "<< pos.second<<endl;
	//	}
	//}
	cout<<"-----------"<<endl;
	saida = invertePosicao(posicoes);
	print(saida);
	return 0;
}