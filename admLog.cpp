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

using namespace std;

#ifndef AdminLog_CPP
#define AdminLog_CPP

class admLog{
	private:
		string ruta;
		vector<Log*> logs;
	public:
		admLog(string ruta){
			this->ruta=ruta;
		}
		
		string getRuta(){
			return ruta;
		}
		
		void addLog(Log *p){
            logs.push_back(p);
		}
            
        vector<Log*> getlogs(){
            return this->logs;
        } 

		void remLog(int p){
            logs.erase(
			logs.begin()+p);
        }
			 
		int getN(){
            logs.size();
		}             
            
        void Escribir(){
        	fstream Escribir(ruta.c_str(), ios::out | ios::binary | ios::app);
        	for (int i=0; i<logs.size() ;i++){
        		Log c= *logs.at(i);
        		Escribir.seekp(0,ios::end);
				Escribir.write((char*)(&c), sizeof(Log)); 
			}
			Escribir.close();
		}
		
		void Leer(){
			ifstream Leer(ruta.c_str(), ios::in | ios::binary);
			if (!Leer){
			}else{
				while(!Leer.eof()){
					Log c;
					Leer.read(reinterpret_cast<char*>(&c), sizeof(Log));
					Log* cA= &c;
					addLog(cA);
				}
				Leer.close();
			}
		}
		
		void print(){
			cout<<"logs:"<<endl;
			for(int i=0; i<logs.size(); i++){
				logs.at(i)->print();
			}
		}
		~admLog(){}
};

#endif
