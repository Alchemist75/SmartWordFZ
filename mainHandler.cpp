#include "mainHandler.h" 
#include "handler.h"
#include "searchHandler.h"
#include <iostream>
#include <cstdlib>
mainHandler::mainHandler()
{
    handlers[1] = new searchHandler() ;
    // handlers['2'] = new reciteHandler() ;
    // handlers['3'] = new testHandler() ;
    //handlers[4] = new manageHandler() ;
    // handlers['E'] = new exitHandler() ;
    // handlers['R'] = new bugHandler() ;
    gotoHandler() ;
}

mainHandler::~mainHandler() {} ;

void mainHandler::callHelper()
{
//#if defined(WIN32)|defined(_WIN32)|defined(__WIN32) // 为什么清不了我的屏233333
	//system("cls");
//#else
	system("clear");
//#endif
	std::cout << "Welcome To SmartWord" << std::endl;
	std::cout << "--------------------" << std::endl;
	std::cout << "[1] 查询单词" << std::endl;
	std::cout << "[2] 每日背诵" << std::endl;
	std::cout << "[3] 单词量测试" << std::endl;
	std::cout << "[4] 文本标注" << std::endl;
	std::cout << "[5] 版本信息" << std::endl;
	std::cout << "[6] 退出程序" << std::endl;
	std::cout << "[7] 我要反馈bug" << std::endl;
	std::cout << "--------------------" << std::endl;
}

void mainHandler::gotoHandler()
{
	while(true)
	{
		callHelper(); 
		char choice;
		std::cin >> choice;
//		std::cout << choice << std::endl;
		if ( choice >= '1' && choice <= '7'  )
		{
			handlers[choice-'0']->Processer() ;
		}
		else
		{
			std::cout << "Please input a correct instruction!" << std::endl;
			continue ;
		}

		std::cout<<"press enter to continue..."<<std::endl;
	 	system("pause") ;
	}
	
}


