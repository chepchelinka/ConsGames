// This file contains some common macros

#define P1 'X'
#define P2 'O'
#define FREE ' '

#define SIZE 3

// Clear console command depends of OS
#if defined(_WIN32)
    #define CLEAR "cls"

#elif defined(__linux__)
    #define CLEAR "clear"

#endif


