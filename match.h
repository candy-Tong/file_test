//
// Created by candyTong on 2017/2/26.
//

#ifndef FILE_TEST_MATCH_H
#define FILE_TEST_MATCH_H

#include <stdio.h>
#include <io.h>
#include <stdlib.h>

//40字节
//用于存储的结构体
typedef struct{
    int id;             //4字节
    char matchName[30]; //30字节
    time_t matchTime;   //4字节
}Match;

/*=============================================  查询  ===============================================================*/

/**
 * 获取比赛项目数量
 * @return
 */
int countMatch(){
    FILE *fp;
    if((fp=fopen("match.dat","rb"))==NULL){
        if (_access("match.dat",0)==-1){     //检查是否存在，-1为不存在
            if ((fp=fopen("match.dat","wb"))==NULL){
                printf("新建文件失败");
                exit(0);
            }
            return 0;
        }
        printf("无法打开此文件");
        exit(0);
    }
    fseek(fp,0L,SEEK_END); /* 定位到文件末尾 */
    int fileSize=ftell(fp); /* 得到文件大小 */
    fclose(fp);
    if (fileSize!=-1)
        return fileSize/sizeof(Match);
    else
        return 0;
}

/**
 * 获取文件最末端的比赛
 * @return
 */
Match __getLastMatch(){
    FILE *fp;
    if((fp=fopen("match.dat","rb"))==NULL){
        printf("无法打开此文件");
        exit(0);
    }
    Match lastMatch;
    if (countMatch()!=0){
        fseek(fp,-sizeof(Match),SEEK_END); /* 定位到文件最后一个用户 */
        fread(&lastMatch, sizeof(Match),1,fp);
    } else
        lastMatch.id=0;
    fclose(fp);
    return lastMatch;
}


/*=============================================  增加  ===============================================================*/

void insertOneMatch(Match match){
    //函数声明
    Match __getLastMatch();

    Match __getLastMatch();
    FILE *fp;
    if((fp=fopen("match.dat","ab"))==NULL){
        printf("无法打开此文件");
        if ((fp=fopen("match.dat","wb"))==NULL){
            printf("新建文件失败");
            exit(0);
        }
    }
    Match lastMatch=__getLastMatch();
    match.id=lastMatch.id+1;
    if(fwrite(&match, sizeof(Match),1,fp)!=1)
        printf("fail to insert a 码头车");
    fclose(fp);
}


#endif //FILE_TEST_MATCH_H
