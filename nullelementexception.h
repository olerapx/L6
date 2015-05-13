#ifndef NULLELEMENTEXCEPTION_H
#define NULLELEMENTEXCEPTION_H
#include "string"

//for using in List class
class NullElementException
{
 private:
    std::string error;

 public:
    NullElementException();
    NullElementException (std::string errorText);

    inline std::string getError(){return error;}
};

#endif // NULLELEMENTEXCEPTION_H
