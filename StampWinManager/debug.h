#pragma once
#include <stacktrace>
#include <iostream>

#define SWM_DEBUG
#ifdef SWM_DEBUG 
#define STAMPSTACK() std::cout << std::to_string(std::stacktrace::current()) << std::endl
#define STAMPDMSG(msg) std::cout << msg << std::endl
#define STAMPERROR(con,msg) if(con) {STAMPSTACK(); std::cout << msg << std::endl; }
#else
#define STAMPSTACK()
#define STAMPDMSG(msg)
#define STAMPERROR(con,msg)
#endif