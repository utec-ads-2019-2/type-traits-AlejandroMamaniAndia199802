#ifndef TRAITS_LIST_H
#define TRAITS_LIST_H

#include "node.h"

template <typename Tr>
class TraitsList {     
    public:
        typedef typename Tr::T T;
        typedef typename Tr::Operation Operation;
      
    private:
        Node<T>* head;
        Operation cmp;

        bool find(T data, Node<T> **&pointer)
        {
            pointer = &head;
            while(*pointer != nullptr && !cmp(data, (*pointer)->data))
                pointer = &((*pointer)->next);
            return *pointer != nullptr && (*pointer)->data == data;
        }
              
    public:
        TraitsList() : head(nullptr) {};
             
        bool insert(T data) {
            // TODO
        }
             
        bool remove(T data) {
            // TODO
        }  

        bool find(T data) {
            // TODO
        }

        T operator [] (int index) {
            // TODO
        }
             
        int size() {
            // TODO
        }

        void print() {
            // TODO
        }

        ~TraitsList() {
            // TODO
        }         
};

#endif