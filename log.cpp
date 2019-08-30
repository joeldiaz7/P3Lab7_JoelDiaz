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

#ifndef LOG_CPP
#define LOG_CPP
class Log{
    private:
            char usuario[35];
            char comando[35];
            int nLog;
    public:
        Log(){
		}    
		      
        Log(string usuario, string comando, int nLog){
            setUsuario(usuario);
            setComando(comando);
       		this->nLog=nLog;
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
             
        void setComando(string comando){
            const char *temp = comando.data();
            int num =comando.size();
            num = num < 35 ? num:34;
            strncpy(this->comando, temp, num);
            this->comando[num] = '\0';
        }
             
        string getComando(){
            return this->comando;
        }
             
        void setNLog(int nLog){
            this->nLog=nLog;
        }
             
        int getNLog(){
            return this->nLog;
        }
			                     
        void print(){
            cout<<"num: "<<nLog<<", usuario: "<<usuario<<", cmd: "<<comando<<endl;
        } 
		~Log(){}
};
#endif
