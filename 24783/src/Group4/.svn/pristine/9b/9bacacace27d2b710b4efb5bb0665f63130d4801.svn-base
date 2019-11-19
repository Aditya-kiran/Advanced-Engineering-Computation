#include "mapreader.h"

std::vector<physical_node> MapReader::readPhysicalNodes() {
    std::vector<physical_node> result;
    redisReply * replyId = (redisReply *)redisCommand(ctx, "lrange physical_node_list 0 -1");
    for(int i = 0 ; i < replyId->elements; i++)
    {
        std::string ids = replyId->element[i]->str;
        const char * data = ids.c_str();
        cJSON * json = cJSON_Parse(data);
        physical_node node;
        int physical_node_id = json->child->valueint;

        std::vector<int> lock_nodes;
        cJSON * ptr = json->child->next->child;
        while (ptr != NULL) {
            lock_nodes.push_back(ptr->valueint);
            ptr = ptr->next;
        }

        std::vector<int> phy_adjacent_nodes;
        ptr = json->child->next->next->child;
        while (ptr != NULL) {
            phy_adjacent_nodes.push_back(ptr->valueint);
            ptr = ptr->next;
        }

        std::vector<int> logical_nodes;
        ptr = json->child->next->next->next->child;
        while (ptr != NULL) {
            logical_nodes.push_back(ptr->valueint);
            ptr = ptr->next;
        }

        double y;
        y = json->child->next->next->next->next->valuedouble;

        double x;
        x = json->child->next->next->next->next->next->valuedouble;

        int type;
        type = std::stoi(json->child->next->next->next->next->next->next->valuestring);

        node.lock_nodes = lock_nodes;
        node.logicl_nodes = logical_nodes;
        node.physical_node_id = physical_node_id;
        node.phy_adjacent_nodes = phy_adjacent_nodes;
        node.x = x;
        node.y = y;
        node.type = type;
        result.push_back(node);

    }
    freeReplyObject(replyId);
    return result;
}

std::vector<physical_link> MapReader::readPhysicalLinks() {
    std::vector<physical_link> result;
    redisReply * reply = (redisReply *)redisCommand(ctx, "lrange physical_link_list 0 -1");
    for (int i = 0; i < reply->elements; i++) {
        const char * data = reply->element[i]->str;
        cJSON * json = cJSON_Parse(data);
        physical_link link;

        int physical_link_id = json->child->valueint;
        int to_physical_node = json->child->next->valueint;
        int from_physical_node = json->child->next->next->valueint;
        cJSON * ptr = json->child->next->next->next->child;
        std::vector<int> lock_nodes;
        while (ptr != NULL) {
            lock_nodes.push_back(ptr->valueint);
            ptr = ptr->next;
        }
        link.from_physical_node = from_physical_node;
        link.to_physical_node = to_physical_node;
        link.lock_nodes = lock_nodes;
        link.physical_link_id = physical_link_id;
        result.push_back(link);
    }
    freeReplyObject(reply);
    return result;
}

std::vector<logical_node> MapReader::readLogicalNodes() {
    std::vector<logical_node> result;
    redisReply * reply = (redisReply *) redisCommand(ctx, "lrange logical_node_list 0 -1");
    for (int i = 0; i < reply->elements; i++) {
        const char * data = reply->element[i]->str;
        cJSON * json = cJSON_Parse(data);
        logical_node node;
        std::vector<int> adjacent_nodes;
        cJSON * ptr = json->child->child;
        while (ptr != NULL) {
            adjacent_nodes.push_back(ptr->valueint);
            ptr = ptr->next;
        }
        int physical_node_id = json->child->next->valueint;
        int logical_node_id = json->child->next->next->valueint;
        node.adjacent_nodes = adjacent_nodes;
        node.logical_node_id = logical_node_id;
        node.physical_node_id = physical_node_id;
        result.push_back(node);
    }
    freeReplyObject(reply);
    return result;
}
