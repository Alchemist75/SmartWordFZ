#ifndef SEARCHHANDLER_H_
#define SEARCHHANDLER_H_

#include "Dictionary.h"
#include "handler.h"

class searchHandler : public Handler 
{
public:
	searchHandler();
	~searchHandler();
	void CallHelper() ;	
	void Processer() ;
	bool Ownfunction() ;
private:

};

#endif