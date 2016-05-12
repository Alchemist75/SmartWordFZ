#include <iostream>
#include <cstdio>
#include <string>
#include "mainHandler.h"
using namespace std;

int main(int argc, char** argv)
{
	mainHandler *mhd = new mainHandler();
	delete mhd;
	return 0;
}