#include "MyPriorityQueue.hpp"
#include <iostream>
#include <fstream>
#include "convert.hpp"
int main()
{
	// MyPriorityQueue<int> mpq;
	// mpq.insert(3);
	// mpq.insert(8);
	// mpq.insert(5);
	// mpq.insert(13);
	// mpq.insert(9);
	// mpq.insert(26);
	// mpq.insert(24);
	// mpq.insert(17);
	// mpq.insert(25);
	// mpq.insert(21);
	// mpq.insert(23);
	// mpq.insert(22);
	// mpq.insert(12);
	// mpq.extractMin();
	// mpq.extractMin();
	// std::cout<<mpq.min();

	std::string WORD_ONE = "ant";
	std::string WORD_TWO = "eat";


	std::unordered_set<std::string> words;
	std::ifstream in("words.txt");
	loadWordsIntoTable(words, in);


 	std::vector< std::string > r = convert(WORD_ONE, WORD_TWO, words);
	

}

