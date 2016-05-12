#include"handler.h" 
#include"Dictionary.h"

Handler::Handler() {} ;

Handler::~Handler() {} ;

void Handler::CallHelper() {} ;

void Handler::Processer() 
{
    dict->importDict()
    do 
    {
        CallHelper() ;
    }
    while ( Ownfunction() ) ;
    delete dict ;
} 
;

bool Handler::Ownfunction() {} ;