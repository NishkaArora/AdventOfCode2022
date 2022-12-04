#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <numeric>
#include <map>

int sum_of_priorities(std::vector<std::string> data) 
{
    int total = 0;
    for(std::string rucksack : data) 
    {
        int priority = 0;
        std::map<char, bool> bagofletters;

        for(int i = 0; i < rucksack.length()/2; i++) 
        {
            char c = rucksack[i];
            bagofletters[c] = true;
        }
        for(int i = rucksack.length()/2; i < rucksack.length(); i++) {
            char c = rucksack[i];
            if(bagofletters.count(c) != 0) {
                if (int(c) >= 97) 
                {
                    priority = int(c) - 96;
                }
                else 
                {
                    priority = int(c) - 38;
                }
                break;
            }
        }
        total += priority;
    }
    return total;
}

int sum_of_badges(std::vector<std::string> data) 
{
    int total = 0;

    for(int i = 0; i < data.size(); i+= 3)
    {
        std::string e1 = data[i];
        std::string e2 = data[i+1];
        std::string e3 = data[i+2];
        std::map<char, int> bagofletters;

        int priority = 0;

        for(char c : e1) {
            bagofletters[c] = 1;
        }
        for(char c : e2) {
            if(bagofletters[c] == 1) {
                bagofletters[c] = 2;
            }
        }
        for(char c : e3) {
            if(bagofletters[c] == 2) {
                if (int(c) >= 97) 
                {
                    priority = int(c) - 96;
                }
                else 
                {
                    priority = int(c) - 38;
                }
                break;
            }
        }

        total += priority;
    }
    return total;
}

int main() {

    std::ifstream file("day3.txt");
    std::string line;
    std::vector<std::string> data;

     while (getline(file, line)) {
        data.push_back(line);
    }
    std::cout << "\nSum of Priorities: " << sum_of_priorities(data);
    std::cout << "\nSum of Badges: " << sum_of_badges(data);
    return 0;
}