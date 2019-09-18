#ifndef SELF_LIST_H
#define SELF_LIST_H

#include "node.h"
#include <iostream>

template <typename T>
class SelfList {
    public: 
        enum Method {Move, Count, Transpose};

    protected:
        Node<T>* head;
        Method method;
private:
    bool find(T data, Node<T> **&pointer)
    {
        pointer = &head;
        for(int i = 0; ((*pointer != nullptr)); i++)
        {
            if(!cmp(data, (*pointer)->data))
            {
                pointer = &((*pointer)->next);
            }
            else{
                break;
            }
        }
        return *pointer != nullptr && (*pointer)->data == data;
    }

    public:
        SelfList(Method method) : head(nullptr) {};
        bool insert(T data)
        {
            Node<T> *newNode = new Node<T>(data);
            Node<T> **tempNode;
            newNode->next = *tempNode;
            *tempNode = newNode;
            ++this -> nodes;
            return true;
        }

        bool remove(T data) {
            Node<T> **tempNode;
            if (!find(data, tempNode)) return false;
            Node<T> *newNode = *tempNode;
            *tempNode = (*tempNode)->next;
            --this->nodes;
            delete newNode;
            return true;
        }

        bool find(T data) {
            switch (this->method)
            {
                case Move:{

                }
            }
        }

        T operator [] (int index) {
            Node<T> *tempNode = head;
            for (int i = 0; i < index; i++)
                tempNode = tempNode->next;
            return tempNode->data ;
        }
             
        int size() {
            return this->nodes;
        }

        void print()
        {

        }

        ~SelfList() {
            head->killSelf();
        }  
};

#endif