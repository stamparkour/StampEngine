#pragma once
#include <stacktrace>
#include <iostream>

//enables debug messages
#define SWM_DEBUG
//pauses console after error
#define SWM_DEBUG_PAUSE

#if defined(SWM_DEBUG) 
#ifdef SWM_DEBUG_PAUSE 
#define STAMPSTACK() std::cout << std::to_string(std::stacktrace::current()) << std::endl << __FUNCTION__  << " " << __LINE__ << " " << __FILE__ << std::endl;
#define STAMPDMSG(msg) std::cout << msg << std::endl; std::cin.get()
#define STAMPERROR(con,msg) if(con) {STAMPSTACK(); std::cout << msg << std::endl; std::cin.get(); }
#else
#define STAMPSTACK() std::cout << std::to_string(std::stacktrace::current()) << std::endl
#define STAMPDMSG(msg) std::cout << msg << std::endl
#define STAMPERROR(con,msg) if(con) {STAMPSTACK(); std::cout << msg << std::endl; }
#endif
#else
#define STAMPSTACK()
#define STAMPDMSG(msg)
#define STAMPERROR(con,msg)
#endif

#define GLSTAMPERROR STAMPERROR(wm::checkOpenGLErrors(), "")
#define GLSTAMPERRORM(message) STAMPERROR(wm::checkOpenGLErrors(), message)

//DebugBreak(void)