//
// Created by candyTong on 2017/3/2.
//

#ifndef FILE_TEST_COMMON_H
#define FILE_TEST_COMMON_H

//定义控制台颜色
#define NONE  "\033[m"
#define RED           "\033[0;32;31m"
#define LIGHT_RED     "\033[1;31m"
#define GREEN         "\033[0;32;32m"
#define LIGHT_GREEN   "\033[1;32m"
#define BLUE          "\033[0;32;34m"
#define LIGHT_BLUE    "\033[1;34m"
#define DARY_GRAY     "\033[1;30m"
#define CYAN          "\033[0;36m"
#define LIGHT_CYAN    "\033[1;36m"
#define PURPLE        "\033[0;35m"
#define LIGHT_PURPLE "\033[1;35m"
#define BROWN         "\033[0;33m"
#define YELLOW        "\033[1;33m"
#define LIGHT_GRAY    "\033[0;37m"
#define WHITE         "\033[1;37m"

#define MAXN  305
typedef struct {
    int id;
    char account[30];
    char password[30];
    char name[30];
    int grade;
}College;

struct CollegeArray{
    int id;
    char account[30];
    char password[30];
    char name[30];
    struct CollegeArray *next;
    int grade;
};
typedef struct CollegeArray CollegeArray;


//用户存储User结构体
//用户存储User结构体
typedef struct {
    int id;
    char account[30];
    char password[30];
    char name[30];
    int college_id;
    int sex;
}User;
//链表无限扩展的User结构体
struct userArray{
    int id;
    char account[30];
    char password[30];
    char name[30];
    int college_id;
    int sex;
    struct userArray *next;
};
typedef struct userArray UserArray;



//40字节
//用于存储的结构体
typedef struct{
    int id;             //比赛id
    char matchName[30]; //比赛名
    int matchTime;   //比赛时间
    int sex;        //性别    0 男 1 女
    int place;      //比赛地点
}Match;

//链表无限扩展的match结构体
struct MatchArray{
    int id;
    char matchName[30];
    int matchTime;
    int sex;        //性别
    int place;      //比赛地点
    struct MatchArray *next;
};
typedef struct MatchArray MatchArray;

//用户与赛事存储JoinMsg结构体
typedef struct {
    int id;
    int user_id;
    int match_id;
    double grade;
    int rank;
}JoinMsg;

//链表无限扩展的JoinMsg结构体
struct joinMsgArray{
    int id;
    int user_id;
    int match_id;
    double grade;
    int rank;
    struct joinMsgArray *next;
};
typedef struct joinMsgArray JoinMsgArray;

#endif //FILE_TEST_COMMON_H
