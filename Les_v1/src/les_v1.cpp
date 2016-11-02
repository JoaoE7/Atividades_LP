// This is a stub code (or skeleton code) just to allow the first compilation.

#include <iostream>
#include "les_v1.h"

using namespace std;

//! Prints the list.
/*! This a debugging function that prints the list content.
 *  @param _pAIL Pointer to the head of the list. It NULL, list is empty.
 */

void print( SNPtr _pAIL )
{   
    if (empty(_pAIL)) {
        cout << "Lista Vazia {}" << endl;
    } else {
        cout << "Sua lista é: {";
        while (_pAIL != nullptr) {
            cout << " " << _pAIL->miData;
            _pAIL = _pAIL->mpNext;
        }
        cout << " }" << endl;
    }
}

//! Length of the list.
/*! Calculates and return the length of the list. Length is zero, if list is empty.
 *  @param _pAIL Pointer to the head of the list. It NULL, list is empty.
 *  @return The length.
 */
int length( SNPtr _pAIL )
{
    int tam = 0;
    while (_pAIL != nullptr) {
        tam++;
        _pAIL = _pAIL->mpNext;
    }
    return tam;
}


bool empty( SNPtr _pAIL )
{
    if (_pAIL == nullptr) {
        return true;
    }
    return false;
}


void clear( SNPtr & _pAIL )
{
    SNPtr aux;
    while (_pAIL != nullptr) {
        aux = _pAIL->mpNext;
        delete _pAIL;
        _pAIL = aux;
    }
    //_pAIL = nullptr;
}


bool front( SNPtr _pAIL, int & _retrievedVal )
{
    if (empty(_pAIL)) {
        return false;
    } else {
        _retrievedVal = _pAIL->miData;
        return true;
    }
}


bool back( SNPtr _pAIL, int & _retrievedVal )
{
    if (empty(_pAIL)) {
        return false;
    } else {
        while (_pAIL->mpNext != nullptr) {
            _pAIL = _pAIL->mpNext;
        }
        _retrievedVal = _pAIL->miData;
        return true;
    }
}


bool pushFront( SNPtr & _pAIL, int _newVal )
{
    SNPtr primeiro;
    try { primeiro = new SLLNode; }
    catch (const bad_alloc &e) { return false; }
    primeiro->miData = _newVal;
    primeiro->mpNext = _pAIL;
    _pAIL = primeiro;
    return true;
}


bool pushBack( SNPtr & _pAIL, int _newVal )
{
    SNPtr ultimo;
    SNPtr aux;
    aux = _pAIL;
    try { ultimo = new SLLNode; }
    catch (const bad_alloc &e) { return false; }
    while (aux->mpNext != nullptr) {
        aux = aux->mpNext;
    }
    ultimo->miData = _newVal;
    ultimo->mpNext = nullptr;
    aux->mpNext = ultimo;
    return true;
}


bool popFront( SNPtr & _pAIL, int & _retrievedVal )
{
    if (empty(_pAIL)) {
        return false;
    }
    SNPtr aux = _pAIL;
    _retrievedVal = _pAIL->miData;
    _pAIL = _pAIL->mpNext;
    delete aux;
    return true;
}


bool popBack( SNPtr & _pAIL, int& _retrievedVal )
{
    if (empty(_pAIL)) {
        return false;
    }
    SNPtr ult, del;
    ult = _pAIL;
    del = _pAIL->mpNext;
    while (del->mpNext != nullptr) {
        ult = del;
        del = ult->mpNext;
    }
    _retrievedVal = del->miData;
    delete del;
    ult->mpNext = nullptr;
    return true;
}


SNPtr find( SNPtr _pAIL, int _targetVal, int ocorrencia )
{
    if (empty(_pAIL) || _pAIL->miData == _targetVal || ocorrencia < 1) {
        return nullptr;
    }
    SNPtr aux = _pAIL;
    int ocor = 0;
    _pAIL = _pAIL->mpNext;
    while (_pAIL != nullptr) {
        if (_pAIL->miData == _targetVal) {
            ocor++;
            if (ocor == ocorrencia) {
                return aux;
            } 
        }
        aux = _pAIL;
        _pAIL = _pAIL->mpNext;
    }
    return aux;
}


bool insert( SNPtr & _pAIL, SNPtr _pAnte, int _newVal )
{
    SNPtr insert;
    SNPtr aux;
    try { insert = new SLLNode; }
    catch (const bad_alloc &e) { return false; }
    if (_pAnte == nullptr) {
        insert->miData = _newVal;
        insert->mpNext = _pAIL;
        _pAIL = insert;
        return true;
    } else {
        aux = _pAIL;
        while (aux != nullptr) {
            if (aux == _pAnte) {
                insert->miData = _newVal;
                insert->mpNext = aux->mpNext;
                aux->mpNext = insert;
                return true;
            }
            aux = aux->mpNext;
        }
        return false;
    }
}


bool remove( SNPtr & _pAIL, SNPtr _pAnte, int & _retrievedVal )
{

    if (_pAnte == nullptr) {
        SNPtr aux = _pAIL;
        _retrievedVal = _pAIL->miData;
        _pAIL = _pAIL->mpNext;
        delete aux;
        return true;
    } else {
        SNPtr aux;
        aux = _pAIL;
        while (aux != nullptr) {
            if (aux == _pAnte) {
                aux = aux->mpNext;
                _retrievedVal = aux->miData;
                _pAnte->mpNext = aux->mpNext;
                delete aux;
                return true;
            }
            aux = aux->mpNext;        
        }
        return false;
    }
}


//**** ===================[ End of les_v1.cpp ]=================== ****// 
