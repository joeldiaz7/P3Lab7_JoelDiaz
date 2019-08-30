#include <iostream>
#include <string.h>
#include <bits/stdc++.h>
#include <stdio.h>
#include <vector>
#include <iomanip>
#include <ctime>
#include <cstdlib>
#include <typeinfo>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <exception>
#include <conio.h>
#include <direct.h>

using namespace std;

#ifndef CMDERR_CPP
#define CMDERR_CPP
class CmdError: public runtime_error{
	public:
		CmdError(string msg):runtime_error(msg){
		}
};
#endif
