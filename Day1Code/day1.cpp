#include<iostream>
#include<fstream>
#include<string>
#include <vector>
#include<numeric>

using namespace std;

int32_t find_max_elf(vector<int32_t> data)
{
    int32_t max_elf = 0;
    int32_t cur_elf = 0;

    for(int i = 0; i < data.size(); i++)
    {
        if (data[i] == -1) 
        { // new elf
            if (cur_elf > max_elf) {
                max_elf = cur_elf;
            }
            cur_elf = 0;
        }
        else 
        {
            cur_elf += data[i];
        }
    }

    return max_elf;
}

int32_t max_3_elves(vector<int32_t> data) {

    int32_t max_elf = 0;
    int32_t cur_elf = 0;
    std::vector<int32_t> elves;

    for(int i = 0; i < data.size(); i++)
    {
        if (data[i] == -1) 
        { // new elf
            elves.push_back(cur_elf);
            cur_elf = 0;
        }
        else 
        {
            cur_elf += data[i];
        }
    }
    elves.push_back(cur_elf);

    std::sort(elves.begin(), elves.end());
    int top3 = std::accumulate(elves.end() - 3, elves.end(), 0);
    return top3;
}

int main()
{
    std::ifstream file("day1.txt");
    std::string line;
    std::vector<int32_t> data;

    while (getline(file, line)) {
        int32_t calories = -1; // empty line, new elf

        if (line.length() != 0) calories = std::stoi(line); // string to integer

        data.push_back(calories);
    }

    std::cout << "Problem 1: " << find_max_elf(data) << std::endl;
    std::cout << "Problem 2: " << max_3_elves(data) << std::endl;

    return 0;
}