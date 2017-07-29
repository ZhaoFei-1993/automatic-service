//  task.cpp
//  Automatic-backup
//
//  Created by 赵飞 on 2017/7/29.
//  Copyright © 2017年 赵飞. All rights reserved.
//
#include "task.h"


task_management* task_management::g_instance = nullptr;
task::task(task_Type type, char* cmd, Date*taskTime, char* des)
{
	m_type = type;
	m_des = new char[250];
	strcpy(m_des, des);
	m_command = new char[250];
	strcpy(m_command, cmd);
 	m_taskTime = taskTime;
	m_taskTime->retain();
	task_management::getInstance()->m_taskList.push_back(this);
	//因为Date管理基制为每一桢删除，不能直接赋值，只能拷贝内存
	/*void* ptr = malloc(sizeof(Date));
	memcpy(ptr, taskTime, sizeof(ptr));
	m_taskTime = static_cast<Date*>(ptr);*/
}

int task::runtask()
{
	return system(m_command);
}

task * task_management::createTask(task_Type type, char* cmd,Date*taskTime, char* des)
{
	task*_task = new task(type, cmd, taskTime, des);
	_task->retain();
	char *msg = new char[255];
	sprintf(msg, "初始化任务  %s", _task->m_des);
	LOG::RECORD(msg);
	return _task;
}

void task_management::run()
{
	std::list<task*>::iterator iter = task_management::getInstance()->m_taskList.begin();
	char *msg = nullptr; 
	while (iter != task_management::getInstance()->m_taskList.end())
	{
		if ((*iter)->m_type == task_Type::now) {
			msg = new char[255];
			sprintf(msg, "准备任务  %s", (*iter)->m_des);
			LOG::RECORD(msg);
			if ((*iter)->runtask() == 0) {
				sprintf(msg, "执行成功  %s", (*iter)->m_des);
				LOG::RECORD(msg);
			}
			else {
				sprintf(msg, "执行失败  %s", (*iter)->m_des);
				LOG::RECORD(msg);
			}
			(*iter)->release();
			task_management::getInstance()->m_taskList.erase(iter++);
		}
		else {
			if ((*iter)->m_type == Date::getWeek()) {
				if (Date::isNow((*iter)->m_taskTime)) {
					msg = new char[255];
					sprintf(msg, "准备任务  %s", (*iter)->m_des);
					LOG::RECORD(msg);
					if ((*iter)->runtask() == 0) {
						sprintf(msg, "执行成功  %s", (*iter)->m_des);
					}
					else {
						sprintf(msg, "执行失败  %s", (*iter)->m_des);
					}
					LOG::RECORD(msg);
				}
			}
			iter++;
		}
	}
}

void task_management::showtask()
{
	std::list<task*>::iterator iter = task_management::getInstance()->m_taskList.begin();
	while (iter != task_management::getInstance()->m_taskList.end())
	{
		if ((*iter)->m_type == task_Type::everyday) {
			printf("每天\t %d:%d:%d  \t%s\n", (*iter)->m_taskTime->m_hour, (*iter)->m_taskTime->m_min, (*iter)->m_taskTime->m_sec, (*iter)->m_des);
		}
		else if ((*iter)->m_type == task_Type::now) {
			printf("立即执行  \t%s\n", (*iter)->m_des);
		}
		else {
			printf("每周%d\t %d:%d:%d  \t%s\n", (*iter)->m_type,(*iter)->m_taskTime->m_hour, (*iter)->m_taskTime->m_min, (*iter)->m_taskTime->m_sec, (*iter)->m_des);
		}
		iter++;
	}
}

task_management * task_management::getInstance()
{
	if (!task_management::g_instance) {
		task_management::g_instance = new task_management();
	}
	return 	task_management::g_instance;
}
