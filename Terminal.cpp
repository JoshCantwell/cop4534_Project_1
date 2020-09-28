#include "Terminal.h"
#include <string>
#include <iostream>
void Terminal::Run() {
        
    std::vector <std::string> commands = {};
    fs = new FileSystem();    
    std::string userChoice = "";
    
    while(userChoice != "exit") {

        userChoice = "";
    
        int inc = 0;
        std::cout << "$ " ;
        getline( std::cin, userChoice);

        commands.clear();
            
        std::string word = "";
        for(unsigned int i = 0; i <  userChoice.length(); i++) {

            if(userChoice[i] == ' ') {

                commands.insert(commands.begin() + inc, word);
                word = "";
                inc++;

            } else {

                word =  word + userChoice[i];

            }

        }

        commands.insert(commands.begin() + inc, word);

        if(commands[0] == "ls") {

            std::cout << fs->ls() << std::endl;
        
        } else if(commands[0] == "cd") {

            std::cout << fs->cd(commands[1]) << std::endl;
            std::cout << fs->GetCurrentDirectory()->GetName() << std::endl;

        }else if(commands[0] == "mv") {
         
            std::cout << fs->mv(commands[1], commands[2]) << std::endl;


        }else if(commands[0] == "cp") {

            std::cout << fs->cp(commands[1], commands[2]) <<  std::endl;


        } else if(commands[0] == "rm") {

            std::cout << fs->rm(commands[1]) << std::endl;

        } else if(commands[0] == "whereis")  {

             fs->WhereIs(commands[1]);


        } else if(commands[0] == "mkdir") {

            if(commands[1] != "" && inc > 0) {
           
                std::cout << fs->mkdir(commands[1]) << std::endl;
            }
            

        } else if(commands[0] == "touch") {
            
        
            std::cout << fs->touch(commands[1]) << std::endl;

        } else if(commands[0] == "exit") {


        }else if(commands[0] == "pwd" ) {
            
            std::cout << fs->pwd() << std::endl;
        }else {

            std::cout << "\'" << userChoice << "\' is not a recognized command. \n" << std::endl;
        }
        

        
    }


    delete fs;
}

















