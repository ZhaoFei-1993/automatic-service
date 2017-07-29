
//
//  obj.cpp
//  Automatic-backup
//
//  Created by 赵飞 on 2017/7/29.
//  Copyright © 2017年 赵飞. All rights reserved.
//
#include "obj.h"
#define _SAFE_DELETE( _PTR_ )   \
    delete _PTR_;               \
    _PTR_ = nullptr;

objMgr*objMgr::g_instance = nullptr;//new objMgr();
objMgr* objMgr::getInstance() {
	if (!objMgr::g_instance) {
		objMgr::g_instance = new objMgr();
	}
	return objMgr::g_instance;
}
void objMgr::push(obj*ptr) {
	this->ptr_list.push_back(ptr);
}
void objMgr::clean() {
	std::list<obj*>::iterator iter = this->ptr_list.begin();
	while (iter != ptr_list.end()) {
		if ((*iter)->m_retain) {
			iter++;
		}
		else {
			_SAFE_DELETE((*iter));
			ptr_list.erase(iter++);
		}	
	}
}

void obj::retain()
{
	m_retain = true;
}

void obj::release()
{
	m_retain = false;
}
