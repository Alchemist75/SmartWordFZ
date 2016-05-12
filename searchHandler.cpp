#include "searchHandler.h"
#include "Word.h"
#include <iostream>
#include <cstdlib>

searchHandler::searchHandler() { } ;
searchHandler::~searchHandler() { } ;

void searchHandler::CallHelper()
{
	#if defined(WIN32)|defined(_WIN32)|defined(__WIN32) 
		system("cls");
	#else
		system("clear");
	#endif
	
	std::cout << "Welcome To SmartWord" << std::endl;
	std::cout << "--------------------" << std::endl;
	std::cout << "请输入要查询的单词..." << std::endl;
	std::cout << "[Q] 返回上一层" << std::endl;
	std::cout << "--------------------" << std::endl;
}

bool searchHandler::Ownfunction()
{
		std::string input;
		std::cin >> input;
		if(input.length() == 1 && (input[0] == 'Q' || input[0] == 'q'))
		{
			return false ;
		}
		if (dict->isExisted(input))
		{
			Word tmp = dict->getSearchWord(input) ;
			std::cerr << tmp ;
		}
		else 
		{
			std::cerr << "Can not find the word!" << std::endl;
		}
		getchar();
		return true ;
} 


