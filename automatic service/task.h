//
//  task.hpp
//  Automatic-backup
//
//  Created by 赵飞 on 2017/7/29.
//  Copyright © 2017年 赵飞. All rights reserved.
//

#ifndef task_hpp
#define task_hpp
#include<list>
#include"Date.h"
#include"LOG.h"
enum task_Type {
	everyday = 0,
	week_1,
	week_2,
	week_3,
	week_4,
	week_5,
	week_6,
	week_7,
	now,
};
class task:public obj
{
	friend class task_management;
	task_Type m_type;
	char* m_command;
	Date*m_taskTime;
	char* m_des;
public:
	task(task_Type type, char* cmd, Date*taskTime,char* des);
	int runtask();
};


class task_management {
	
private:
	
public:
	std::list<task*> m_taskList;
	static task_management* g_instance;
	static task_management* getInstance();
	static task *createTask(task_Type type, char* cmd, Date*taskTime,char* des);
	static void run();
	static void showtask();
};

#endif /* task_hpp */

