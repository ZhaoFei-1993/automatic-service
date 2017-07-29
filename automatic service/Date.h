//
//  Date.hpp
//  Automatic-backup
//
//  Created by 赵飞 on 2017/7/29.
//  Copyright © 2017年 赵飞. All rights reserved.
//

#ifndef Date_hpp
#define Date_hpp
#include "stdafx.h"
#include <time.h>
#include"obj.h"
class Date :public obj {
	//friend class task_management;
	
public:
	int m_year, m_month, m_day, m_hour, m_min, m_sec, m_week;
	Date();
	Date(int hour,int min,int sec);
	bool isToday();
	char *getDate();
	char *getTime();
	static bool isNow(Date * date);
	static int getWeek();
	static char *getCurDate();
	static char *getCurTime();
};
#endif /* Date_hpp */
