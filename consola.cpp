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
#include "logger.cpp"

using namespace std;

#ifndef CONSOLA_CPP
#define CONSOLA_CPP
class consola{
    private:
        char usuario[35];
        logger* lggr;
        int nLog;
    public:
        consola(){
        	lggr= new logger();
		}    
		          
        consola(string usuario, logger* lggr){
        	setUsuario(usuario);
        	this->lggr=lggr;
       	}
             
  	    void setUsuario(string usuario){
            const char *temp = usuario.data();
            int num =usuario.size();
       	    num = num < 35 ? num:34;
   	        strncpy(this->usuario, temp, num);
            this->usuario[num] = '\0';
		}
             
        string getUsuario(){
            return this->usuario;
        }
        
        logger* getLggr(){
        	return lggr;
		}
		
		void setLggr(logger* lggr){
			this->lggr=lggr;
		}
		
		void cmd(){
			lggr->cmd();
			lggr->~logger();
		}
        ~consola(){}    
};
#endif
