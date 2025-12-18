#ifndef STAGE_H
#define STAGE_H        

#include <map>
#include <vector>
#include <string>
#include "../persons/persons.h"

class Stage{

    private:

        std::map<std::string, int>delay_;
        int hard_;

    public:

        Stage(int hard);

        std::map<std::string, int> GetDelays(){return delay_;}
        int GetHard(){return hard_;}

        std::map<std::string, int> Simulate(const std::vector<Cyclist> &Cyclist);
};

#endif