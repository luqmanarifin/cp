#ifndef __LIST_ELEMENT_H
#define __LIST_ELEMENT_H

#include <cstdlib>
#include <cstdio>

class ListElement {
public:
  ListElement() {
    info = 0;
    next = NULL;
  }
  ListElement(int _info, ListElement* _next) {
    info = _info;
    next = _next;
  }
  ~ListElement() {
    printf("%d kehapus\n", info);
    if(next != NULL) delete next;
  }
  void SetInfo(int _info) {
    info = _info;
  }
  int GetInfo() {
    return info;
  }
  void SetNext(ListElement* _next) {
    next = _next;
  }
  ListElement* GetNext() {
    return next;
  }
  void Print() {
    printf("%d ", info);
    if(next) next->Print();
  }
private:
  int info;
  ListElement* next;
};

class SingleLinkedList {
public:
  SingleLinkedList() {
    head = NULL;
  }
  ~SingleLinkedList() {
    delete head;
  }
  void AddFirst(int e) {
    head = new ListElement(e, head);
  }
  void Print() {
    head->Print();
  }
private:
  ListElement* head;
};

#endif