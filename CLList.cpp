#include "CLList.hpp"

#include <iostream>

template <typename T>
CLList<T>::CLList() {
    tail = nullptr;
    list_size = 0;
}

template <typename T>
void CLList<T>::push_front(const T& val) {
    if (empty()) {
        tail = new DLLNode<T>(val);
        tail->prev = tail;
        tail->next = tail;
    }
    else {
        tail->next = new DLLNode<T>(val, tail, tail->next);
    }
    
    list_size++;
}

template <typename T>
void CLList<T>::print() const {
    if (empty()) {
        return;
    }
    DLLNode<T>* cur = tail->next;
    do {
        std::cout << cur->data;
        if (cur != tail) { // not the last node
            std::cout << " -> ";
        }
        cur = cur->next;
    } while (cur != tail->next);
    
    std::cout << std::endl;
}

template <typename T>
void CLList<T>::print_backwards() const {
    if (empty()) {
        return;
    }
    DLLNode<T>* cur = tail;

    do {
        std::cout << cur->data;
        if (cur != tail->next) { // not the last node
            std::cout << " <- ";
        }
        cur = cur->prev;
    } while (cur != tail);
    
    std::cout << std::endl;
}


template <typename T>
bool CLList<T>::empty() const {
    return (list_size == 0);
}












