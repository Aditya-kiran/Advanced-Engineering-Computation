#include <iostream>
#include "AStar.h"
#include <time.h>
#include "ts.h"
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[])
{


    LMap::Instance().ReadMap();
    TS myTS;
    myTS.ReadMap();

    LMap::Instance().FunctionTest();
    while(true){

    }

    return 0;
}
