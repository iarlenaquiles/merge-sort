#include <iostream>
#include <list>
#include <algorithm>

using namespace std;


void intercala_lista(list<int> &destino, list<int> &origem){
    auto itDestino = destino.begin();

    while((itDestino != destino.end()) && (origem.size() > 0)){
        if(*itDestino < *origem.begin()){
            itDestino++;
        }else{
            destino.insert(itDestino, origem.front());
            origem.pop_front();
        }
    }

    while(!origem.empty()){
        destino.push_back(origem.front());
        origem.pop_front();
    }
}

typedef list<int>::iterator lit;

template <class T, class Iter>

void merge(Iter inicio, Iter meio, Iter fim, list<T> &lista){
    while(inicio != meio && meio != fim){
        if(*inicio < *meio){
            inicio++;
        }else{
            //inicio.insert(inicio, *meio);
            lista.insert(inicio, *meio);
            meio = lista.erase(meio);
        }
    }

//    while(inicio != fim){
//        if(*inicio < *fim){
//            inicio++;
//        }else{
//            lista.insert(inicio, *fim);
//            fim = lista.erase(fim);
//        }
//    }

}

int main()
{
    list<int> lista, lista2;
    list<int> la {1, 3, 5, 4, 6, 8};
    lista.push_back(1);
    lista.push_back(2);
    lista.push_back(4);

    lista2.push_back(3);
    lista2.push_back(5);
    lista2.push_back(7);

    intercala_lista(lista, lista2);

    merge(la.begin(), find(la.begin(), la.end(), 4),la.end(), la);

    for(auto it = la.begin(); it != la.end(); it++){
        cout << *it << " ";
    }
    return 0;
}
