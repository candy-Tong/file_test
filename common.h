//
// Created by candyTong on 2017/2/26.
//

#include <time.h>
#include <mem.h>
#include <stdio.h>
#include <malloc.h>

#ifndef FILE_TEST_COMMON_H
#define FILE_TEST_COMMON_H 

/*=============================================  时间转换  ============================================================*/

/**
 * 将时间戳转为标准时间
 * @param t 时间戳
 * @return  标准时间的字符串
 * 记得把输出完把空间释放
 */
char* toStandardTime(time_t t){
    struct tm *lt;
    int ii = time(&t);
    t = time(NULL);
    lt = localtime(&t);
    char *nowtime=malloc(24);
    strftime(nowtime, 24, "%Y-%m-%d %H:%M:%S", lt);
    return nowtime;
}
/**
 * 输入一个标准时间  转化成时间戳
 * 格式2017-2-27 2:27 无需输入秒
 * @return
 */
long toTimeStamp()
{
    struct tm stm;
    int iY, iM, iD, iH, iMin, iS;
    memset(&stm,0,sizeof(stm));

    scanf("%d-%d-%d %d:%d",&iY,&iM,&iD,&iH,&iMin);

    stm.tm_year=iY-1900;
    stm.tm_mon=iM-1;
    stm.tm_mday=iD;
    stm.tm_hour=iH;
    stm.tm_min=iMin;
    stm.tm_sec=iS;

    /*printf("%d-%0d-%0d %0d:%0d\n", iY, iM, iD, iH, iMin);*/
    return mktime(&stm);
}
/*---------------------------------------------------------------------------------------------------------------------*/

#endif //FILE_TEST_COMMON_H
