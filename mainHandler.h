#ifndef MAINHANDLER_H_
#define MAINHANDLER_H_

#include<string>
#include"handler.h"
class mainHandler
{
private:
    Handler *handlers[10] ;
        
public:
    mainHandler();
    ~mainHandler();
    void callHelper();
    void gotoHandler();
    
};

#endif
