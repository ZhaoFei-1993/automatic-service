//
//  Date.cpp
//  Automatic-backup
//
//  Created by 赵飞 on 2017/7/29.
//  Copyright © 2017年 赵飞. All rights reserved.
//

#include "Date.h"
#define _MAXSTR_    255
Date::Date() {
	time_t tt = time(nullptr);
	tm *t = localtime(&tt);
	m_year = t->tm_year + 1900;
	m_month = t->tm_mon + 1;
	m_day = t->tm_mday;
	m_hour = t->tm_hour;
	m_min = t->tm_min;
	m_sec = t->tm_sec;
	m_week = t->tm_wday;
}
Date::Date(int hour, int min, int sec)
{
	time_t tt = time(nullptr);
	tm *t = localtime(&tt);
	m_year = t->tm_year + 1900;
	m_month = t->tm_mon + 1;
	m_day = t->tm_mday;
	m_hour = hour;
	m_min = min;
	m_sec = sec;
	m_week = t->tm_wday;
}
bool Date::isToday() {
	return false;
}
char * Date::getDate()
{
	char *date = new char[_MAXSTR_]; //objMgr::getInstance()->push(date);
	sprintf(date, "%d-%02d-%02d", m_year, m_month, m_day);
	return date;
}
char * Date::getTime()
{
	char *time = new char[_MAXSTR_]; //objMgr::getInstance()->push(time);
	sprintf(time, "%d-%02d-%02d %02d:%02d:%02d", m_year, m_month, m_day, m_hour, m_min, m_sec);
	return time;
}
bool Date::isNow(Date * date)
{
	Date * d = new Date();
	/*printf("targetTime\t %d-%02d-%02d %02d:%02d:%02d\n", date->m_year, date->m_month, date->m_day, date->m_hour, date->m_min, date->m_sec);
	printf("nowTime\t\t %d-%02d-%02d %02d:%02d:%02d\n", d->m_year, d->m_month, d->m_day, d->m_hour, d->m_min, d->m_sec);*/
	return d->m_hour == date->m_hour&& d->m_min==date->m_min&& d->m_sec== date->m_sec;
}
int Date::getWeek()
{
	Date *d = new Date();
	return d->m_week;
}
char*Date::getCurDate() {
	Date *d = new Date();
	char *date = new char[_MAXSTR_]; //objMgr::getInstance()->push(date);
	sprintf(date, "%d-%02d-%02d", d->m_year, d->m_month, d->m_day);
	return date;
}
char *Date::getCurTime() {
	Date *d = new Date();
	char *time = new char[_MAXSTR_]; //objMgr::getInstance()->push(time);
	sprintf(time, "%d-%02d-%02d %02d:%02d:%02d", d->m_year, d->m_month, d->m_day, d->m_hour, d->m_min, d->m_sec);
	return time;
}
