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
        Node<T>* tail;
        Method method;
        int nodes;
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
        explicit SelfList(Method method) : head(nullptr),tail(nullptr),method(method),nodes(0) {};
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

        void find(T data) {
            Node<T> **tempNode;
            tempNode = &(this->head);
            if(find(data,tempNode))
            {
                switch (this->method)
                {
                    case Move:{
                        if(*tempNode != this->head) std::swap(this->head->data,(*tempNode)->data);
                        break;
                    }
                    case Count:{

                    }
                    case Transpose:{
                        Node<T> *tempNode_1 = this-> head;
                        for(int i = 0;(tempNode_1->next) != *tempNode; i++)
                        {
                            tempNode_1 = tempNode_1 -> next;
                        }
                        std::swap(tempNode_1->data, (*tempNode)->data);
                        break;
                    }
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