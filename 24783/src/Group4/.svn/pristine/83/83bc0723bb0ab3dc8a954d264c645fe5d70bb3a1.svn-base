#include "mapreader.h"
#include <map>
#include <string>
#include <vector>
#include <map>
#include <regex>
#include "../../hiredis/hiredis.h"
#include <set>
#include <iomanip>
#include <time.h>

using namespace std;

struct XOY {
    double x;
    double y;
};

struct route {
    std::string vps_str = "";
    std::string wts_str = "";
    std::string tts_str = "";
    std::vector<int> vps;
    std::vector<double> wts;
    std::vector<double> tts;
    std::vector<std::pair<double, double>> arr_and_depar_time;
    std::string arr_and_depar_time_str = "";
};

class Mapper {
public:
    Mapper();
    ~Mapper();
public:
    redisContext * ctx;
    std::vector<route> robots_route;
    std::vector<XOY> node_list;
    std::vector<std::vector<int> > neighbour_node_list;
    std::vector<std::vector<double> > travel_time_list;
    std::vector<std::vector<int> > lock_node_list;
    map<int, map<int, int>> link_id_map;
    std::vector<std::vector<int> > link_lock_node_list;
    std::vector<int> robot_positions;
    std::vector<int> occupied;
    int robot_number = 3;
    std::vector<std::vector<int>> robots_cFun;
    std::vector<std::vector<int>> robots_remaining_vps;
    std::vector<std::vector<double>> robots_remaining_wts;
    std::vector<std::vector<double>> robots_remaining_tts;
    std::vector<std::vector<double>> robots_arrive_times;
    std::vector<std::vector<std::pair<double, double>>> robots_remaining_arr_and_depar_times;
    std::vector<std::string> robots_cFun_str;


public:
    std::string int2str(int num);
    int str2int(std::string num);
    std::string double2str(double num);
    double str2double(std::string num);
    std::vector<string> split(const string& str, const string& delim);
    route RetriveRobotPath(int robot_id);
    void ReadMap();
    void GetRobotPositions();
    void Lock4Node(int robot_id, int node_id);
    void InitArriveTimes();
    void FillArriveTimes();
    bool needToStop(int robot_id, int node_id);
    void StoreOccupiedArea();
    bool isCross(XOY a, XOY b, XOY c, XOY d);
    bool needToStopByCross(int robot_id, int curr_node_id, int previous_node_id);

    double mult(XOY a, XOY b, XOY c);
    bool intersect(XOY aa, XOY bb, XOY cc, XOY dd);
    bool isConflict(std::vector<int> a, std::vector<int> b);

public:
    void cut();
    void StoreRobotCFuns();
    void StoreRobotRemainTTS();

public:
    void RetriveRandomNumber();
    int randomNumber = 0;

};
