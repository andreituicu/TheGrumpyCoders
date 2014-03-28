// ConsoleApplication4.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
#include "xBoardProtocol.h"
#include "fstream"
#include "string"
#include "regex"
#include "stdio.h"

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	xBoardProtocol* protocol = new xBoardProtocol();
	//fstream data;
	//data.open("commands.txt", ios_base::out);
	//data.clear();

	char command[100];
	while(1){
		cin>>command;
		string uhra;
		uhra = protocol->execute(command);
		if(!uhra.compare("quit")){
			exit(0);
		}

		if(!uhra.compare("resign")) {
			//data<<uhra;
			//data.flush();
			cout<<"resign\n";
			cout.flush();
		} else {

		if( uhra.compare("")!= 0){
			cout<<"move "<<uhra;
				//cout<<"\n";
			//data<<uhra;
			//data.flush();
			cout.flush();
		}

		}
	//cout<<"\n";
	//cout.flush();
		
		//data<<command<<endl;
		//data.flush();
	}
	delete protocol;

	//data.flush();
	//data.close();
	return 0;
}

