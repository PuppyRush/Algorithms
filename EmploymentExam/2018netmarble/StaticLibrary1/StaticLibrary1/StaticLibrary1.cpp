// StaticLibrary1.cpp : Defines the exported functions for the static library.
//

#include "StaticLibrary1.h"

// This is an example of an exported variable
int nStaticLibrary1=0;

// This is an example of an exported function.
int fnStaticLibrary1(void)
{
    return 42;
}

// This is the constructor of a class that has been exported.
// see StaticLibrary1.h for the class definition
CStaticLibrary1::CStaticLibrary1()
{
    return;
}
