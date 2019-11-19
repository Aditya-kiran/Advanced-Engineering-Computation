#include "ts.h"

TS::TS()
{
    ctx = redisConnect("127.0.0.1", 6379);
    if(ctx->err)
    {
        std::cout<<"No connection with ctx_get"<<std::endl;
    } else {
        std::cout << "Successfully connected to Redis!" << std::endl;
    }

}


TS::~TS()
{

}

void TS::ReadMap() {
    this->physical_node_list = myMapreader.readPhysicalNodes();
    std::vector<int> tempYardPoints;
    for (int i = 0; i < this->physical_node_list.size(); i++) {
        if (this->physical_node_list[i].type == 3) {
            tempYardPoints.push_back(this->physical_node_list[i].physical_node_id);
        }
    }
    this->yardPoints = tempYardPoints;
    for (int i = 0; i < 3; i++) {
        rf_task t;
        this->StraddleTasks.push_back(t);
    }
    return;
}



void TS::Init() {
    for (int i = 1; i <= this->StraddleTasks.size(); i++) {
        rf_task t;
        redisReply * reply = (redisReply *)redisCommand(ctx, "HGET straddle_task %d", i);
        std::string ids = reply->str;
        const char * data = ids.c_str();
        cJSON * json = cJSON_Parse(data);
        cJSON * temp_ptr = json->child;
        for (int i = 0; i < 3; i++) {
            std::string temp_str = temp_ptr->string;
            if (temp_str == "isFinished") {
                t.isFinished = temp_ptr->valueint;
            } else if (temp_str == "from") {
                t.from = temp_ptr->valueint;
            } else if (temp_str== "to") {
                t.to = temp_ptr->valueint;
            }
            temp_ptr = temp_ptr->next;
        }
        //delete(data);
        cJSON_Delete(json);
        cJSON_Delete(temp_ptr);

        this->StraddleTasks[i - 1] = t;
        freeReplyObject(reply);
    }
    return;
}

void TS::GetStraddlePositions() {
    std::vector<int> positions;
    for (int i = 1; i <= this->StraddleTasks.size(); i++) {
        redisReply * reply = (redisReply *) redisCommand(ctx, "HGET straddle_position %d", i);
        int tempPos = std::stoi(reply->str);
        positions.push_back(tempPos);
        freeReplyObject(reply);
    }
    this->straddle_positions = positions;
}

void TS::StoreStraddleTask(int straddle_id, rf_task t) {
    std::string s = "{\"from\":";
    s += std::to_string(t.from);
    s += ", \"to\":";
    s += std::to_string(t.to);
    s += ", \"isFinished\":";
    s += std::to_string(t.isFinished);
    s += "}";
    redisReply * reply = (redisReply *)redisCommand(ctx, "HSET straddle_task %d %s", straddle_id, s.c_str());
    freeReplyObject(reply);
}

void TS::checkDeadLock() {
    redisReply * reply = (redisReply *)redisCommand(ctx, "GET dead_lock");
    int islocked = std::stoi(reply->str);
    this->isDeadLock = islocked;
    freeReplyObject(reply);
}

void TS::setDeadLock(int a) {
    redisReply * reply = (redisReply *)redisCommand(ctx, "SET dead_lock %d", a);
    freeReplyObject(reply);
}
