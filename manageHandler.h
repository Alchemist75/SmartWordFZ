#ifndef MANAGEHANDLER_H_
#define MANAGEHANDLER_H_

#include "Dictionary.h"
#include "handler.h"

class manageHandler : public Handler 
{
public:
	searchHandler();
	~searchHandler();
	void CallHelper() ;	
	void Processer() ;
	void Ownfunction() ;
private:

};

#endif