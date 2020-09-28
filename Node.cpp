#include "Node.h"
#include <iostream>

// Private Functions



//Public Functions]
Node* Node::GetPrev() {

    return prev;

}

void Node::SetPrev(Node* prev) {

    this->prev = prev;

}


void Node::SetNext(Node* next){

   this->next = next;
}

void Node::SetType(char type) {

    this->type = type;
}

void Node::SetHasChildren(bool hasChildren) {

    this->hasChildren = hasChildren;

}
Node* Node::GetChild() {

    return this->child;

}

void Node::SetChild(Node* child) {

    this->child = child;

}

void Node::SetName(std::string name) {

    this->name = name;

}

void Node::RemoveChildren() {

    if(hasChildren == false) {

        std::cout << "\n Had no children.\n" << std::endl;
        return;

    } else {


    }


}

Node* Node::GetParent() {

    return this->parent;
}
void Node::SetParent(Node* parent) {

    this->parent = parent;
}
bool Node::GetHasChildren() {

    return this->hasChildren;

}
Node* Node::GetNext(){

    return next;
    /*if(GetName() != "root") {

    return parent;
    } else {
        return nullptr;

    }*/
}

char Node::GetType(){

    return this->type;
}

std::string Node::GetName() {

    return this->name;
}
