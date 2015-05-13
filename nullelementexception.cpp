#include "nullelementexception.h"

NullElementException::NullElementException()
{
    error= "Element is null";
}


  NullElementException::NullElementException (std::string errorText)
  {
      error=errorText;
  }
