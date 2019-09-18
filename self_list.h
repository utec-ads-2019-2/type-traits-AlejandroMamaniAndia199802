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
    bool verify(T data, Node<T> **&pointer)
    {
        pointer = &head;
        for(int i = 0; ((*pointer != nullptr)); i++)
        {
            if ((*pointer)->data == data){
                return true;
            }
            pointer = &((*pointer)->next);
        }
    }

    public:
        explicit SelfList(Method method) : head(nullptr),tail(nullptr),method(method),nodes(0) {};
        bool insert(T data)
        {
            Node<T> *newNode = new Node<T>(data);
            Node<T> **tempNode;
            if (find(data, tempNode)) return false;
            newNode->next = *tempNode;
            *tempNode = newNode;
            ++nodes;
            return true;
        }

        bool remove(T data) {
            Node<T> **tempNode;
            if (!find(data, tempNode)) return false;
            Node<T> *newNode = *tempNode;
            *tempNode = (*tempNode)->next;
            --nodes;
            delete newNode;
            return true;
        }
        void find(T data) {
            Node<T> **tempNode;
            tempNode = &(this->head);
            if(verify(data,tempNode))
            {
                switch (this->method)
                {
                    case Move:{
                        std::swap(this->head->data,(*tempNode)->data);
                        break;
                        // TO DO
                    }
                    case Count:{
                        *tempNode -> counter++;
                        Node<T> *tempNode_1 = this->head;
                        while(*tempNode != nullptr)
                        {
                            if(  tempNode_1->counter <=  (*tempNode)->counter)
                            {

                                std::swap(tempNode_1->counter, (*tempNode)->counter);
                                std::swap(tempNode_1->data, (*tempNode)->data);
                            }
                                tempNode_1= tempNode_1->next;
                        }
                        break;
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
            return nodes;
        }

        void print()
        {

        }

        ~SelfList() {
            head = nullptr;
            this->next = nullptr;
            nodes = 0;
            if(nodes != 0)
            {
                head->killSelf();
                nodes = 0;
            }
        }  
};

#endif