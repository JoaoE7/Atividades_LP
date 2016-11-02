// Para compilar: g++ -Wall -pedantic drive_les_v1.cpp les_v1.cpp -o drive_les_v1

#include "les_v1.h"
#include <iostream>
using namespace std;


int main ( void ) {
    SNPtr pHead = NULL;// nullptr;
    SNPtr pBusca;
    int f, t, d;
    cout << "Tamanho: " << length(pHead) << " " << endl;
    pushFront( pHead, 4 );
    pushBack( pHead, 7 );
    pushFront( pHead, 3 );
    pushBack( pHead, 7 );
    pushFront( pHead, 1 );
    pushBack( pHead, 7 );
    pBusca = find(pHead, 7, 2);
    insert(pHead, pBusca, 13);
    print(pHead);
    remove(pHead, pBusca, d);
    cout << "Valor deletado: " << d << " " << endl;
    popBack(pHead, f);
    popFront(pHead, t);
    cout << "Valor deletado: " << f << " " << endl;
    cout << "Valor deletado: " << t << " " << endl;
    print(pHead);
    cout << "Tamanho: " << length(pHead) << " " << endl;
    clear(pHead);
    cout << "Tamanho: " << length(pHead) << " " << endl;
    cout << "\n\n>>> Normal exiting...\n";
    return EXIT_SUCCESS;
}
