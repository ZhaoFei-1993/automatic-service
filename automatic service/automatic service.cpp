// automatic service.cpp : �������̨Ӧ�ó������ڵ㡣
//

//#include "stdafx.h"
#include"windows.h"
#include"Date.h"
#include"task.h"
#include"LOG.h"
#define _WAIT_TIME_ 1000

int main() {
	LOG::init();
	//create task
	task_management::createTask(task_Type::everyday, "dir.bat", new Date(23,50,6), "��ʾ�ļ�Ŀ¼");
	task_management::showtask();

	while (true) {
		task_management::run();
		//clean all ptr
		LOG::updatesavefile();
		objMgr::getInstance()->clean();
		Sleep(_WAIT_TIME_);
	}
	return 0;
}
	
