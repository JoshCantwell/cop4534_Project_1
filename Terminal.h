#ifndef _TERMINAL_H_
#define _TERMINAL_H_

#include "FileSystem.h"
#include <fstream>

class Terminal {

    public:

        Terminal(){

        }

        void Run();
        std::vector<std::string> LoadCommands();

    private:

        FileSystem* fs;
};


#endif
