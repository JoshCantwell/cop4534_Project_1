#include "FileSystem.h"
#include <iostream>
#include <vector>
// Private Functions
//

void FileSystem::AddNode(Node* newNode) {
    Node* helper  = currentDirectory;
    if(currentDirectory->GetChild() == nullptr) {
        helper->SetChild(newNode);
        newNode->SetPrev(helper);
    } else {
        helper = currentDirectory->GetChild();
        while(helper->GetNext() != nullptr) {
            helper = helper->GetNext();
        };
    helper->SetNext(newNode);
    newNode->SetPrev(helper);
    }
}

Node* FileSystem::CopyChildren(Node* head) {

    if(head->GetNext() != nullptr) 
        CopyChildren(head->GetNext());
    if(head->GetChild() != nullptr)
        CopyChildren(head->GetChild());
    
    Node* node = head;
    return node;

}

void FileSystem::FindFileLocations(Node* head, std::string name) {

   int inc = 0; 
    if(head->GetNext() != nullptr)
        FindFileLocations(head->GetNext(), name);
    if(head->GetChild() != nullptr)
        FindFileLocations(head->GetChild(), name);
    
    if(head->GetName() == name){ 
        std::cout << pwd(head) << std::endl;
        inc++;
    } 
    if(inc == 0) {

        std::cout << "\n No directory with that name" << std::endl;
    }

}


void FileSystem::RemoveChildren(Node* head) {

    if(head->GetNext() != nullptr)
        RemoveChildren(head->GetNext());
    if(head->GetChild() != nullptr)
        RemoveChildren(head->GetChild());
    std::cout << "1"  << std::endl;
    free(head);
     
}

Node* FileSystem::FindNode(std::string name) {
    Node* helper = currentDirectory;
    if(currentDirectory->GetChild() == nullptr) {
        return nullptr;
    } else {
        helper = helper->GetChild();
        while(helper->GetName() != name && helper->GetNext() != nullptr) {
            helper = helper->GetNext();
        }
        if(helper->GetName() == name){
            return helper;
        } else { 
            return nullptr;
        }
    }
}



//Public Functions
//
void FileSystem::WhereIs(std::string name) {

    
    FindFileLocations(currentDirectory, name);
    return;

}

Node* FileSystem::GetCurrentDirectory() {

    return currentDirectory;

}

std::string FileSystem::mkdir(std::string name) {

    Node* node = new Node(name, 'd');
    node->SetParent(currentDirectory);
    if(FindNode(name) != nullptr) {

        std::string error = "\nDirectory with that name already exist!\n";
        return error;
    }
    AddNode(node);
    std::string mkdir = "New directory ";
    mkdir += node->GetName();
    mkdir += " made succesfully!";
    return mkdir;

}

std::string FileSystem::touch(std::string name) {

    Node* node = new Node(name, 'f');
    node->SetChild(nullptr);
    if(FindNode(name) != nullptr) {

        std::string error = "Directoy/File with that name already exist";
        return error;
    }

    AddNode(node);
    std::string touch = "\nNew File ";
    touch += name;
    touch += "created succesfully";
    return touch;


}
std::string FileSystem::pwd(Node* node) {

    Node* helper = node;
     
    std::string pwd = "";
    std::vector<std::string> workingDirectory;

    workingDirectory.push_back(helper->GetName());
    while(helper->GetParent() != nullptr) {

        helper = helper->GetParent();
        workingDirectory.push_back(helper->GetName());
    }
    for(unsigned int i = 0; i < workingDirectory.size(); i++) {
        pwd += "/";
        pwd += workingDirectory[(workingDirectory.size() - 1) -i];
    }

    return pwd;

    
}

std::string FileSystem::pwd() {

    Node* helper = currentDirectory;
     
    std::string pwd = "";
    std::vector<std::string> workingDirectory;

    workingDirectory.push_back(helper->GetName());
    while(helper->GetParent() != nullptr) {

        helper = helper->GetParent();
        workingDirectory.push_back(helper->GetName());
    }
    for(unsigned int i = 0; i < workingDirectory.size(); i++) {
        pwd += "/";
        pwd += workingDirectory[(workingDirectory.size() - 1) -i];
    }

    return pwd;

    
}


std::string FileSystem::ls() {
    Node* helper = currentDirectory->GetChild();
    if(currentDirectory->GetChild() == nullptr) {
        std::string error = "\n";
        return error;
    } else {
        std::string ls = "\n";
        do{ 
            ls += helper->GetType();
            ls += " ";
            ls += helper->GetName();
            ls += "\n";
            helper = helper->GetNext();
        } while(helper != nullptr);
        return ls;
    }
}


std::string FileSystem::rm(std::string name) {
    Node* currDirectory = currentDirectory;
    Node* helper = FindNode(name);
    if(helper == nullptr) {
        std::string error = "Directory/File was not found.";
        return error;
    } else {
        if(helper->GetNext() != nullptr) {
            helper->GetPrev()->SetNext(helper->GetNext());
            helper->GetNext()->SetPrev(helper->GetPrev());



            if(currDirectory->GetChild() == helper) {

                currentDirectory->SetChild(helper->GetNext());
            }
        } else {
            if(currDirectory->GetChild() == helper) {
                currentDirectory->SetChild(nullptr);
            }
            helper->GetPrev()->SetNext(nullptr);
        }

        if(helper->GetChild() != nullptr) {    
        
            RemoveChildren(helper->GetChild());
        }
        free(helper);
        std::string error = name;
        error += " was removed from directory.";
        return error;

    }
}

std::string FileSystem::mv(std::string from, std::string to) {

    Node* helper = FindNode(from);;
    if(helper == nullptr) {

        std::string error = "\nNo directory with that name.!\n";
        std::cout << "\n" << helper->GetName() << std::endl;
        return error;

    } else {
        if(FindNode(to) != nullptr) {
              
            std::string error = "Directory with that name already exists, try a different name.";
            return error;
        }
        helper->SetName(to);;
        std::string mv = from;
        mv += " changed to ";
        mv += to;
        return mv;
    }

}




std::string FileSystem::cp(std::string from, std::string to){

    Node* helperInit = FindNode(from);
    Node* helper = new Node(*helperInit);
    helper->SetName(to);

    if(helper == nullptr) {

        std::string error = "\nNo directory with that name.\n";

        std::cout << "\n" << helper->GetName() << std::endl;
        return error;
    } else {


        if(FindNode(to) != nullptr) {

            std::string error = "Directory with that name already exist, try a differ5ent name.";
            return error;
        }
        AddNode(CopyChildren(helper));
    

    }

    std::string cp = helper->GetName();
    return cp;

}







std::string FileSystem::cd(std::string dirname) {
    if(dirname == "..") {
        if(currentDirectory->GetParent() == nullptr) {
            std::string error = "\nNo higher directory.\n";
            return error;
        }
        currentDirectory = currentDirectory->GetParent();
        return pwd();
    } else {
        if(FindNode(dirname) != nullptr) {
       
            if(FindNode(dirname)->GetType() == 'f') {

                std::string error = dirname;
                error += " is a file. Not a directory.";
                return error;
       
            }
        }
        if(FindNode(dirname) == nullptr) {
            std::string error = "\nNot a valid directory. \n";
            return error;
        } else {
            currentDirectory = FindNode(dirname);
            return pwd();
        }
    }

        
}




