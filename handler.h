#ifndef HANDLER_H_
#define HANDLER_H_

class Handler
{
private:
    Dictionary dict* = new Dictionary() ;
public:
    Handler();
    ~Handler();
    virtual void CallHelper()=0;
    virtual void Processer()=0;
    virtual bool Ownfunction()=0;

} ;

#endif