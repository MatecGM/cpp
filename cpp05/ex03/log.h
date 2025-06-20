#ifndef __LOG__
#define __LOG__

#if defined(DEBUG)
#include <iostream>

#define YELLOW "\033[33m"             /* Yellow */
#define WHITE "\033[37m"              /* White */
#define LOG(...) std::cout << YELLOW << __VA_ARGS__ << WHITE << std::endl;
#else
#define LOG(...)
#endif

#endif /* __LOG__ */
