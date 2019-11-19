#include <string>
#include <vector>
#include "Singleton.h"
#include <map>
#include <regex>
#include "hiredis.h"
#include <set>
#include <iomanip>
#include <time.h>
#include "mapreader.h"

struct rf_task
{
    int from;
    int to;
    int isFinished = 1;
};

class TS
{
public:
    TS();
    ~TS();
    void ReadMap();
    void Init();
    void GetStraddlePositions();
    void StoreStraddleTask(int straddle_id, rf_task t);
    void checkDeadLock();
    void setDeadLock(int a);

public:
    redisContext* ctx;
    MapReader myMapreader;
    std::vector<physical_node> physical_node_list;
    std::vector<int> yardPoints;
    std::vector<rf_task> StraddleTasks;
    std::vector<int> straddle_positions;
    int isDeadLock;

};
