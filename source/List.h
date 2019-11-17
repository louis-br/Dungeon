#pragma once
#include"stdafx.h"

template<class TYPE>
class List{
public:
  class Element{
  public:
    TYPE pType;
    Element* pNext;
    Element* pPrevious;

    Element(){
      pNext = nullptr;
      pPrevious = nullptr;
    }
    ~Element(){
      pNext = nullptr;
      pPrevious = nullptr;
    }
  };
  Element* pFirst;
  Element* pLast;

  void pushElement(TYPE ELEMENT){
    Element* aux = new Element();
    aux->pType = ELEMENT;
    aux->pNext = nullptr;
    aux->pPrevious = nullptr;

    if(!pFirst){
      pFirst = aux;
      pLast = aux;
    }
    else{
      aux->pPrevious = pLast;
      pLast->pNext = aux;
      pLast = aux;
    }
  }

  List(){
    pFirst = nullptr;
    pLast = nullptr;
  }
  ~List(){
    pFirst = nullptr;
    pLast = nullptr;
  }
};
