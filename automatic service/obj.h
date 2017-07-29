//
//  obj.hpp
//  Automatic-backup
//
//  Created by 赵飞 on 2017/7/29.
//  Copyright © 2017年 赵飞. All rights reserved.
//

#ifndef obj_hpp
#define obj_hpp
#include <list>
#include "stdafx.h"
class obj;
class objMgr {
private:
	std::list<obj*> ptr_list;
public:
	static objMgr* g_instance;
	static objMgr* getInstance();
	void push(obj*ptr);
	void clean();
};
class obj {
	friend class objMgr;
	bool m_retain = false;
public:
	obj() {
		objMgr::getInstance()->push(this);
	}
	void retain();
	void release();
};

#endif /* obj_hpp */
