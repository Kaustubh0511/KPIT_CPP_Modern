#ifndef EXCEPTION_H
#define EXCEPTION_H

#include <string>
class exception
{
private:
  std::string _msg;
public:
   exception() = delete;
   explicit exception(std::string msg):_msg(msg){}
   std::string what(){return _msg;}
};

#endif // EXCEPTION_H