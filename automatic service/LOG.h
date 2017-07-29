#pragma once

#include"Date.h"
class LOG
{
	
public:
	static char* saveFile;
	static void updatesavefile();
	static void RECORD(char* msg);
	static void init();
};

