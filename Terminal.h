#ifndef _TERMINAL_H_
#define _TERMINAL_H_

#include "FileSystem.h"

class Terminal {

    public:

        Terminal(){

        }

        void Run();

    private:

        FileSystem* fs;
};


#endif
