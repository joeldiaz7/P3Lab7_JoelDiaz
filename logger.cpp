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
#include "log.cpp"
#include "CmdError.cpp"
#include "admLog.cpp"

using namespace std;

#ifndef LOGGER_CPP
#define LOGGER_CPP
class logger{
    private:
        char usuario[35];
        string file;
        int nLog;
        vector <Log*> logs;
    public:
        logger(){}    
		         
        logger(string usuario, string archivo){
            setUsuario(usuario);
            this->file=file;
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
        
        string getFile(){
        	return file;
		}
             
        void setNLog(int nLog){
            this->nLog=nLog;
        }
             
        int getNLog(){
            return this->nLog;
        }
        
        vector <Log*> getLogs(){
        	return logs;
		}
		
		void addLog(Log* log){
			logs.push_back(log);
		}
		
		void cmd(){
			char cmd[35];
			string temp;
			admLog* al = new admLog("logs.bin");
			al->Leer();
			while(temp!="exit"){
				try{
					cin>>cmd;
					if (al->getN()<1){
						nLog=0;
					}
					else{
						nLog=al->getN();
					}
					al->addLog(new Log(usuario, cmd, nLog));
					al->Escribir();
					temp=cmd;
					sysErr(cmd);
					if (temp=="listar"){
						al->print();
					}
					system(cmd);
					if (temp=="exit"){
						al->addLog(new Log(usuario, cmd, nLog));
					}
					al->Escribir();
				} catch(CmdError &e) {
					cout<<e.what();
					system("pause");
				}
			}
		}
		
		void sysErr(string cmd){
			if (_chdir(cmd.c_str())==1){
				throw CmdError("Error: Comando desconocido");
			}
		}
        
        ~logger(){}   
};
#endif
