#ifndef _NODE_H_
#define _NODE_H_

#include <string>
#include <vector>

class Node {

    public:

        Node() {

        }
        Node(std::string name2, char type2){

            SetPrev(nullptr);
            SetNext(nullptr);
            name = name2;
            type = type2;
            if(type2 == 'd') {

                hasChildren = true;
            }
        }
        Node (Node &node) {

            next = node.next;
            prev = node.prev;
            child = node.child;
            parent = node.parent;
            hasChildren = node.hasChildren;
            type = node.type;

            name = node.name;

        }


        
     
        Node* GetChild(); 
        void SetChild(Node* child);
        void RemoveChildren();
        void SetHasChildren(bool hasChildren);
        bool GetHasChildren();
        void SetNext(Node* next);
        void SetPrev(Node* prev);
        void SetType(char type);
        Node* GetNext();
        Node* GetPrev();
        char GetType();
        void SetName(std::string name);
        std::string GetName();




        void SetParent(Node* parent);
        Node* GetParent();
    
    private:
        
        bool hasChildren = false;
        char type;
        std::string name;
        Node* next;
        Node* prev;
        Node* child = nullptr;

        Node* parent;
        void RemoveHelper(Node* subtree);

};


#endif
