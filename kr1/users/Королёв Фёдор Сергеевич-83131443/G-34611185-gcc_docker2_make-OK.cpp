#include <map>
#include <string>
#include <vector>

std::map <std::string, int> final_standings(const std::vector <std::map <std::string, int> > &res) {
    std::map <std::string, int> finres;
    for (auto contest : res) {
        for (auto guy : contest) {
            if (finres.find(guy.first) == finres.end() || finres[guy.first] < guy.second) {
                finres[guy.first] = guy.second;
            }
        }
    }
    return finres;
}