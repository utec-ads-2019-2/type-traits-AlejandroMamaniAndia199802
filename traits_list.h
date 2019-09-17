#ifndef TRAITS_LIST_H
#define TRAITS_LIST_H

#include "node.h"

template <typename Tr>
class TraitsList
        {
        public:
        typedef typename Tr::T T;
        typedef typename Tr::Operation Operation;
        int nodes;

    private:
        Node<T>* head;
        Operation cmp;
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
        TraitsList() : head(nullptr), nodes(0) {};

        bool insert(T data)
        {
            Node<T> *new_node = new Node<T>(data);
            Node<T> **temp_node;
            if (find(data, temp_node)) return false;

            new_node->next = *temp_node;
            *temp_node = new_node;
            ++nodes;
            return true;
        }

        bool remove(T data)
        {
            Node<T> **tempNode;
            if (!find(data, tempNode)) return false;

            Node<T> *newNode = *tempNode;
            *tempNode = (*tempNode)->next;
            --nodes;
            delete newNode;
            return true;
        }

        bool find(T data)
        {
            Node<T> **temp;
            return find(data, temp);
        }
    T operator[](int index) {
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

        ~TraitsList() {
            head->killSelf();
        }
};

#endif