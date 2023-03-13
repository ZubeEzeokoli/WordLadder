#include "convert.hpp"
#include <string>
#include <sstream>
#include <unordered_set>
#include <string>
#include "MyPriorityQueue.hpp"
#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <string>

// You should not need to change this function.
void loadWordsIntoTable(std::unordered_set<std::string> & words, std::istream & in)
{
	std::string line, word;
	std::stringstream ss;

	while(	getline(in, line) )
	{
		ss.clear();
		ss << line;
		while( ss >> word )
		{
			words.insert( word );
		}
	}

}



// You probably want to change this function.
std::vector< std::string > convert(const std::string & s1, const std::string & s2, const std::unordered_set<std::string> & words)
{
	std::vector< std::string > ret;
	if(s1 == "" || s2 == ""){
		return ret;
	}
	if(s1 == s2){
		return ret;
	}
	if(words.find(s1) == words.end() || words.find(s2) == words.end()){
		return ret;
	}

	MyPriorityQueue<Node> mpq;
	std::vector<std::string> garbage;
	std::unordered_map<std::string, std::string> path;
	unsigned lcd = 0;
	Node s = Node(s1, 0, 0);
	mpq.insert(s);
	while(!mpq.isEmpty()){
			unsigned level = mpq.size();
			while(level != 0){
				std::string word = mpq.min().word;
				mpq.extractMin();
				garbage.push_back(word);
				for(unsigned i = 0; i <word.size(); i++){
					std::string temp_word = word;
					bool inserted_already = false;
					for(char c = 97; c < 123; c++){
						temp_word[i] = c;
						if(temp_word == s2){
							path.insert({s2, word});
							ret.push_back(s2);
							for(int k = 0; k<path.size(); k++){
								ret.push_back(path.at(ret.at(k)));
								if(ret.at(k+1) == s1){
									reverse(ret.begin(), ret.end());
									// for(auto z: ret){
									// 	std::cout<< z <<std::endl;
									// }
									return ret;
								}
							}
							return ret;
						}
						if(word.compare(temp_word) == 0){
							continue;
						}
						if(words.find(temp_word) != words.end()){
							for(auto w: garbage){
								if(w == temp_word){
									inserted_already = true;
									break;
								}
							}
							if(!inserted_already){
								path.insert({temp_word, word});
								unsigned diff_lett = 0;
								for(int i =0; i < temp_word.size(); i++){
									if(temp_word[i] != s2[i]){
										diff_lett++;
									}
								}
								Node s = Node{temp_word, lcd, diff_lett};
								mpq.insert(s);
							}
						}
					}
					lcd++;
				}
				level--;
			}
		}
		return ret;

}

