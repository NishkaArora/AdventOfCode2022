#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <numeric>
#include <tuple>
#include <map>

std::tuple<int, int> get_bounds(std::string elf) 
{
    size_t pos = elf.find('-');
    std::string low = elf.substr(0, pos);
    std::string high = elf.substr(pos+1);
    return std::make_tuple(std::stoi(low), std::stoi(high));
}

int num_full_overlaps(std::vector<std::string> data) {
    int overlaps = 0;
    for(std::string epair : data) 
    {
        size_t pos = epair.find(',');
        std::tuple<int, int> elf1 = get_bounds(epair.substr(0, pos));
        std::tuple<int, int> elf2 = get_bounds(epair.substr(pos+1));

        bool e1_has_e2 = std::get<0>(elf1) <= std::get<0>(elf2) && std::get<1>(elf1) >= std::get<1>(elf2);
        bool e2_has_e1 = std::get<0>(elf2) <= std::get<0>(elf1) && std::get<1>(elf2) >= std::get<1>(elf1);

        if ( e1_has_e2|| e2_has_e1) overlaps += 1;
    }
    return overlaps;
}

int num_overlaps(std::vector<std::string> data) {
    int no_overlap = 0;
    for(std::string epair : data) 
    {
        size_t pos = epair.find(',');
        std::tuple<int, int> elf1 = get_bounds(epair.substr(0, pos));
        std::tuple<int, int> elf2 = get_bounds(epair.substr(pos+1));

        bool mutexc1 = std::get<0>(elf1) > std::get<0>(elf2) && std::get<0>(elf1) > std::get<1>(elf2);
        bool mutexc2 = std::get<0>(elf2) > std::get<0>(elf1) && std::get<0>(elf2) > std::get<1>(elf1);

        if (mutexc1 || mutexc2) no_overlap+=1;

    }
    return int(data.size()) - no_overlap;
}

int main() {
    std::ifstream file("day4.txt");
    std::string line;
    std::vector<std::string> data;

     while (getline(file, line)) 
    {
        data.push_back(line);
    }
    std::cout << "Number of complete overlaps: " << num_full_overlaps(data);
    std::cout << "\nNumber of overlaps: " << num_overlaps(data);
    return 0;
}