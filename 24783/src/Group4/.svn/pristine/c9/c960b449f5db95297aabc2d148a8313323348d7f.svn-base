#include <iostream>
#include "Mapper.h"
#include <time.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    Mapper myMapper;
    myMapper.ReadMap();
    while(true) {
        myMapper.cut();
        myMapper.StoreRobotCFuns();
        myMapper.StoreOccupiedArea();
        myMapper.RetriveRandomNumber();
        sleep(1);
    }
    return 0;
}
