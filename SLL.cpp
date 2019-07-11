#include <iostream>

class Node {
public:
    Node* next;
    int data;
};

Node* first = nullptr;

Node* create_node(int data) {
    Node* new_node = new (class Node); //ALTERNATIVES(w/ slight discrepancy): (class Node*) malloc(sizeof(class Node)); OR new Node();
    if(new_node == nullptr) {
        std::cout << "Memory allocation failed.";
        exit(1);
    }
    new_node->data = data;
    new_node->next = nullptr;
    return new_node;
}

void add(int information) {
    Node* pe = nullptr;
    Node* p = first;
    Node* new_node = create_node(information);
    if(nullptr == first) { //lhs check to avoid accidental assignment
        first = new_node;
    } 
    else {
        while(p != nullptr) {
        pe = p;
        p = p->next;
    }
    pe->next = new_node;
    }
}

void add(int information, int position) {
    Node* new_node = create_node(information);
    if(1 == position) {
        new_node->next = first;
        first = new_node;
    }
    else {
        int i = 1;
        Node* pe = nullptr;
        Node* p = first;
        while(p != nullptr && i != position) {
            pe = p;
            p = p->next;
            i++;
        }
        if(i != position) {
            std::cout<<"Given position doesn't exist. Node will be attached to the end of the SLL.\n";
            pe->next = new_node;
        }
        else {
            pe->next = new_node;
            new_node->next = p;
        }
    }
}

void delete_node_pos(int position) {

    int i = 1;
    Node *pe = nullptr;
    Node *p = first;
    while (p != nullptr && i != position) {
        pe = p;
        p = p->next;
        i++;
    }
    if (i != position) {
        std::cout << "Given position doesn't exist.\n";
    }
    else {
        if(nullptr == pe) {
            first = nullptr;
            delete(p);
        }
        else {
            pe->next = p->next;
            delete(p);
        }
    }
}

void display() {
    Node* current_node = first;
    while(current_node != nullptr) {
        std::cout << current_node->data << " - ";
        current_node = current_node->next;
    }
}

void delete_sll() {
    Node* pe = nullptr;
    Node* p = first;
    while(p != nullptr) {
        pe = p;
        p = p->next;
        delete(pe);
    }
}

int main() {
    
    add(3);
    add(7);
    add(5);
    add(4);
    add(3);
    add(1,1);
    add(1,4);
    add(1,8);
    add(1,12);
    delete_node_pos(2);
    delete_node_pos(8);
    delete_node_pos(16);
    display();
    delete_sll();
}