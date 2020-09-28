#ifndef _FILESYSTEM_H_
#define _FILESYSTEM_H_

#include <string>
#include "Node.h"
#include <iostream>
class FileSystem {

    public:

        FileSystem() {

            Node* root = new Node( "root", 'd');

           
            root->SetHasChildren(true);

        
            Node* cantwell = new Node("cantwell", 'd');
           
            root->SetNext(nullptr);
            cantwell->SetNext(nullptr);
            root->SetChild(cantwell);
            cantwell->SetParent(root);
            root->SetParent(nullptr);
            cantwell->SetHasChildren(true);
            cantwell->SetChild(nullptr);
            currentDirectory = cantwell;

        }

        //For Directories
        //

        FileSystem(std::string directoryName) {

            Node* root = new Node(directoryName, 'd');
        
            root->SetHasChildren(true);


        }

        ~FileSystem() {

        }
        Node* GetCurrentDirectory();
        std::string mkdir(std::string name);
        std::string touch(std::string name);
        std::string pwd();
        std::string ls();
        std::string rm(std::string name);
        std::string mv(std::string from, std::string to);
        std::string cd(std::string dirname);
        std::string cp(std::string from, std::string to);

        std::string pwd(Node* node);
        void WhereIs(std::string);
       

    private:

        Node* root;
        Node* cantwell;
        Node* currentDirectory;

        Node* CopyChildren(Node* head);
        void RemoveChildren(Node* head);
        void AddNode(Node* newNode);
        Node* FindNode(std::string name);

        void FindFileLocations(Node* head, std::string);
};


#endif
