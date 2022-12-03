#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <numeric>
#include <tuple>
#include <map>

using namespace std;

std::map<char, int> moves;
std::map<char, int> outcomes;
std::map<char, int> X_opp;
std::map<char, int> Y_opp;
std::map<char, int> Z_opp;
std::map<char, map<char, int>> competition;
std::map<char, int> win;
std::map<char, int> tied;
std::map<char, int> lose;
std::map<char, map<char, int>> which_move;

int32_t get_score(vector<tuple<char, char>> data) 
{
    int score = 0;

    for(tuple<char, char> move : data) 
    {
        char their_move = std::get<0>(move);
        char my_move = std::get<1>(move);

        score += moves[my_move];
        score += competition[my_move][their_move];
    }
    
    return score;
}

int32_t get_second_score(vector<tuple<char, char>> data) 
{
    int score = 0;
    for(tuple<char, char> move : data) 
    {
        char their_move = std::get<0>(move);
        char intended_outcome = std::get<1>(move);

        score += outcomes[intended_outcome];
        score += which_move[intended_outcome][their_move];
    }

    return score;
}

int main()
{
    // FOR PART 1
    // base points
    moves['X'] = 1;
    moves['Y'] = 2;
    moves['Z'] = 3;

    // ties
    X_opp['A'] = Y_opp['B'] = Z_opp['C'] = 3;

    // win
    X_opp['C'] = Y_opp['A'] = Z_opp['B'] = 6;

    // lose
    X_opp['B']  = Y_opp['C'] = Z_opp['A'] = 0;

    // points
    competition['X'] = X_opp;
    competition['Y'] = Y_opp;
    competition['Z'] = Z_opp;

    // FOR PART 2
    outcomes['X'] = 0;
    outcomes['Y'] = 3;
    outcomes['Z'] = 6;

    win['C'] = tied['A'] = lose['B'] = 1;
    win['A'] = tied['B'] = lose['C'] = 2;
    win['B'] = tied['C'] = lose['A'] = 3;

    which_move['X'] = lose;
    which_move['Y'] = tied;
    which_move['Z'] = win;

    std::ifstream file("day2.txt");
    std::string line;
    std::vector<tuple<char, char>> data;

     while (getline(file, line)) {
        //std::get<0>(pos), std::get<1>(pos);
        data.push_back(make_tuple(line[0], line[2]));
    }
    std::cout << "Score: " << get_score(data);
    std::cout << "\nSecond score: " << get_second_score(data);
    return 0;
}