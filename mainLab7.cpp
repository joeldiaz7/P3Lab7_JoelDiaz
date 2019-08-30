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
#include <direct.h>
#include <conio.h>
#include "logger.cpp"
#include "CmdError.cpp"
#include "consola.cpp"

using namespace std;

int main(){
	string user;
	cout<<"Username: ";
	cin>>user;
	consola* cons = new consola(user, new logger(user, "logs,bin"));
	
	try {
		cons->cmd();
	} catch (CmdError &e){
		cout<<e.what();
	}
	delete cons;	
	return 0;
}

