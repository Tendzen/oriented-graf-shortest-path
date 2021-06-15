//
//  fronta.cpp
//  orientovanyGraf
//
//  Created by Paul Ekishev on 14/06/2021.
//

#include "graph.hpp"


Element* newElement(int d){
    Element* el = new Element;
    el->data = d;
    el->next = nullptr;
    return el;
}


FIFO::FIFO() {
    size = 0;
    head = nullptr;
    tail = nullptr;
}

bool FIFO::isEmpty() {
    return head == nullptr;
}
          
FIFO::~FIFO() {
    clean();
}

void FIFO::clean() {
    if (!isEmpty()) {
        Element* pom;
        while (head != nullptr) {
            pom = head;
            head = head->next;
            delete pom;
        }
        tail = nullptr;
        size = 0;
    }
}

Element* FIFO::pop() {
    if (isEmpty()){
        return nullptr;}
    Element* pom = head;
    head = head->next;
    --size;
    pom->next = nullptr;
    return pom;
}

void FIFO::popByData(int data){
    if (isEmpty()){
        return;}
    Element* pom = head;
    if(pom->data == data){
        head = head->next;
        --size;
        pom->next = nullptr;
        return;
    }else{
        for(int i =0; pom->next != nullptr; i++) {
            if(pom->next->data == data){
                Element* next = pom->next->next;
                free(pom->next);
                pom->next = next;
                --size;
                break;
            }else{
                pom = pom->next;
            }
        }
    }
    if(pom == nullptr || pom->next == nullptr){
        return;
    }
}

void FIFO::push(int data){
    Element* e = newElement(data);
    ++size;
    if(head == nullptr){
        head = tail = e;
    }
    else{
    tail->next = e;
    tail = e;
    }
}

bool FIFO::containInt(int data){
    if (isEmpty()){
        return false;}
    Element* pom = head;
    for(int i =0; pom != nullptr; i++){
        if(pom->data == data){
            return true;
        }
        else{
            pom = pom->next;
        }
    }
    return false;
}
