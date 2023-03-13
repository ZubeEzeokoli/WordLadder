#ifndef __PROJECT5_HPP
#define __PROJECT5_HPP

#include <vector>
#include <unordered_set>
#include <string>
struct Node {
    std::string word;
    unsigned distance;
    unsigned remaining;

    Node(std::string w, unsigned d, unsigned r){
        this->word = w;
        this->distance = d;
        this->remaining = r;
    }

    friend bool operator<(const Node& here, const Node& other){
        return here.distance + here.remaining < other.distance + other.remaining;
    }

     friend bool operator==(const Node& here, const Node& other){
        return here.distance + here.remaining == other.distance + other.remaining;
    }
};

void loadWordsIntoTable(std::unordered_set<std::string> & words, std::istream & in);


std::vector< std::string > convert(const std::string & s1, const std::string & s2, const std::unordered_set<std::string> & words);



#endif 
