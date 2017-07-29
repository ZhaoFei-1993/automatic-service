#include "LOG.h"

//#define _RECORD_LOG_(_FILENAME_,_TIME_,_STR_)   \
//    FILE *fp = fopen(_FILENAME_,"at");          \
//    if(!fp)return 0;                            \
//    fprintf(fp,"%s  %s\n",_TIME_,_STR_);         \
//    printf("%s  %s\n",_TIME_,_STR_);             \
//    fclose(fp);
//

char*LOG::saveFile = new char[250];
void LOG::updatesavefile()
{
	sprintf(LOG::saveFile, "%s.log", Date::getCurDate());
}

void LOG::RECORD(char * msg)
{
	FILE *fp = fopen(LOG::saveFile, "at");
	if (!fp)
		return;
	fprintf(fp, "%s  %s\n", Date::getCurTime(), msg);
	printf("%s  %s\n", Date::getCurTime(), msg);
	fclose(fp);
}

void LOG::init()
{
	LOG::updatesavefile();
	LOG::RECORD("_________________________服务启动中_________________________");
}
