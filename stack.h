/*----------------------------------------*
 * Nama file: stack.h                     *
 * Deskripsi: interface kelas Stack       *
 *----------------------------------------*/

#ifndef STACK_H
#define STACK_H

#include <iostream>

template <class T>
class Stack {
  public:
    Stack();
    Stack(int);
    Stack(const Stack<T>&);
    ~Stack();

    void pop(T& x);
    /* Tangani kasus stack kosong, x tetap */

    void push(T x);
    /* Tangani kasus stack penuh, abaikan x */
    
    int isEmpty() const;
    int isFull() const;
  private:
    static const int defaultStackSize = 100;
    const int size;
    int topStack;
    T *data;
};

/* IMPLEMENTASI DI BAWAH INI */
template<class T>
Stack<T>::Stack() : size(defaultStackSize) {
  data = new T[size + 1];
  topStack = 0;
}

template<class T>
Stack<T>::Stack(int n) : size(n) {
  data = new T[size + 1];
  topStack = 0;
}

template<class T>
Stack<T>::Stack(const Stack<T>& S) : size(S.size) {
  delete [] data;
  data = new T[size + 1];
  topStack = S.topStack;
  for(int i = 0; i < size + 1; i++) {
    data[i] = S.data[i];
  }
}

template<class T>
Stack<T>::~Stack() {
  delete [] data;
}

template<class T>
void Stack<T>::pop(T& x) {
  if(isEmpty()) return;
  topStack--;
  x = data[topStack];
}

template<class T>
void Stack<T>::push(T x) {
  if(isFull()) return;
  data[topStack] = x;
  topStack++;
}

template<class T>
int Stack<T>::isEmpty() const {
  return topStack == 0;
}

template<class T>
int Stack<T>::isFull() const {
  return topStack == size;
}

#endif
