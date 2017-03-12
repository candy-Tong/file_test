//
// Created by candyTong on 2017/3/1.
//
#include <stdio.h>
#include <afxres.h>
#include "common.h"

College selectCollegeById(int id);

int selectUserByCollege(User **user, int college_id);

void selectJoinMsg(int college_id);

void selectAllJoinMsg_College(int college_id);

void showAllMatch(int college_id);

JoinMsg *selectAllJoinMsg();

int countJoinMsg();

User selectUserById(int id);

int countMatch();

Match selectMatchById(int id);

void deleteJoinMsgById(int joinMsg_id);

JoinMsg selectJoinMsgById(int id);

int countMatch();

Match *selectAllMatch();

void SortByMatchTime(Match *a, int n);

void selectOneJoinMsg_College(int college_id, int match_id);

int selectJoinMsgByMatch_id(JoinMsg **joinMsg, int match_id);

int selectJoinMsgByMatch_id(JoinMsg **joinMsg, int match_id);

int countJoinMsg();

User selectUserById(int id);

int countMatch();

Match selectMatchById(int id);

JoinMsg selectJoinMsgById(int id);

void deleteJoinMsgById(int joinMsg_id);

int getGrade(JoinMsg joinMsg);

/**
 * 2.学院入口
 * 一级菜单
 * @param college_id
 */
void CollegeInterface(int college_id) {

    while (1) {
        system("cls");
        printf("欢迎登录学院入口\n");
        printf("1.查询报名情况\n");
        printf("2.查询成绩\n");
        printf("3.退出登录\n");
        int chosen;
        scanf("%d", &chosen);
        fflush(stdin);
        switch (chosen) {
            case 1:
                selectJoinMsg(college_id);
                break;
            case 2:
                break;
            case 3:
                return;
            default:
                printf("输入有误，请重新输入");
                Sleep(1500);
        }
    }
}
/*=================================================查看报名情况=======================================================*/
/**
 * 2.1选择比赛
 * 二级菜单——查询全部、查询单个比赛
 * @param college_id
 */
void selectJoinMsg(int college_id) {

    while (1) {
        system("cls");
        printf("查看报名信息\n");
        printf("1.查询全部\n");
        printf("2.查询单个比赛\n");
        printf("3.返回\n");
        int chosen;
        scanf("%d", &chosen);
        fflush(stdin);
        switch (chosen) {
            case 1:
                selectAllJoinMsg_College(college_id);
                break;
            case 2:
                showAllMatch(college_id);
                fflush(stdin);
                break;
            default:
                return;
        }
    }
}

/**
 * 2.1.1 查询全部报名信息
 * @param college_id
 */
void selectAllJoinMsg_College(int college_id) {


    JoinMsg *joinMsg;
    int num = 0, status;
    int msg_n = countJoinMsg();
    int match_num = countMatch();
    int selectJoinMsgByMatch_id(JoinMsg **joinMsg, int match_id);
    User user;
    Match match;

    for (int j = 0; j < match_num; ++j) {
        msg_n = selectJoinMsgByMatch_id(&joinMsg, j);
        match = selectMatchById(j);
        if (match.id == 0)
            continue;
        printf("\n\t%d 人参加 %s\n", msg_n, match.matchName);
        printf("\t姓名\t序号\n");
        for (int i = 0; i < msg_n; ++i) {
            user = selectUserById(joinMsg[i].user_id);
            if (user.college_id == college_id);
            {
                printf("\t%s\t%d\n", user.name, joinMsg[i].id);
            }

        }
        if (msg_n > 8) {
            printf(LIGHT_RED"同一个项目最多只能报名8人\n"NONE);
        }
    }

    printf("\n输入运动员比赛序号取消该运动员报名,输入0返回\n");
    int chosen;
    scanf("%d", &chosen);
    fflush(stdin);
    if (chosen == 0)
        return;
    JoinMsg msg = selectJoinMsgById(chosen);
    if (msg.id != 0) {
        user = selectUserById(msg.user_id);
        match = selectMatchById(msg.match_id);
        printf(LIGHT_RED"确定取消%s的参赛资格吗\n\t%d\t%s\t%s\n", user.name, chosen, user.name, match.matchName);
        printf("1.确定\t2.取消\n"NONE);
        scanf("%d", &chosen);
        fflush(stdin);
        if (chosen == 1) {
            deleteJoinMsgById(chosen);
            printf("取消成功\n");
            system("pause");
        }
    } else {
        printf("无此记录\n");
        system("pause");
    }


}

/**
 * 2.1.2查询全部比赛
 * @param college_id
 */
void showAllMatch(int college_id) {
    int n = countMatch(), day = -1;
    char time[30], place[30], sex[30];
    Match *match = selectAllMatch();
    JoinMsg *joinMsg;
    int msg_n;

    SortByMatchTime(match, n);

    for (int i = 0; i < n; ++i) {
        if (day != (match[i].matchTime - 1) / 10) {
            day = (match[i].matchTime - 1) / 10;
            printf("\tDay %d\n", day + 1);
            printf(" 序号\t比赛名\t比赛时间\t比赛场地\n");
        }
        switch ((match[i].matchTime - 1) % 10 + 1) {
            case 1:
                strcpy(time, "8:30");
                break;
            case 2:
                strcpy(time, "9:10");
                break;
            case 3:
                strcpy(time, "9:50");
                break;
            case 4:
                strcpy(time, "10:30");
                break;
            case 5:
                strcpy(time, "11:10");
                break;
            case 6:
                strcpy(time, "14:30");
                break;
            case 7:
                strcpy(time, "15:10");
                break;
            case 8:
                strcpy(time, "15:50");
                break;
            case 9:
                strcpy(time, "16:30");
                break;
            case 10:
                strcpy(time, "17:10");
                break;
        }
        switch (match[i].place) {
            case 1:
                strcpy(place, "跑道");
                break;
            case 2:
                strcpy(place, "跳高场地");
                break;
            case 3:
                strcpy(place, "沙池");
                break;
            case 4:
                strcpy(place, "铅球场地");
                break;
            case 5:
                strcpy(place, "标枪场地");
                break;
        }
        msg_n = selectJoinMsgByMatch_id(&joinMsg, match[i].id);
        if (msg_n > 8)
            printf(LIGHT_RED"%d\t%s\t%s\t%s \n"NONE, i + 1, match[i].matchName, time, place);
        else
            printf("%d\t%s\t%s\t%s \n", i + 1, match[i].matchName, time, place);
    }
    printf("红色比赛表示该项目报名人数超过限制\n");
    printf("\n请选择需要查看报名情况的比赛,输入序号: ");
    int chosen;
    scanf("%d", &chosen);
    fflush(stdin);
    selectOneJoinMsg_College(college_id, match[chosen - 1].id);
}

/**
 * 2.1.2.1 选择单个比赛
 * @param college_id
 * @param match_id
 */
void selectOneJoinMsg_College(int college_id, int match_id) {


    JoinMsg *joinMsg;
    User user;
    int msg_n = selectJoinMsgByMatch_id(&joinMsg, match_id);
    Match match = selectMatchById(match_id);

    if (msg_n > 8)
        printf(LIGHT_RED"\n\t%d 人参加 %s\n"NONE, msg_n, match.matchName);
    else
        printf("\n\t%d 人参加 %s\n", msg_n, match.matchName);
    for (int i = 0; i < msg_n; ++i) {
        user = selectUserById(joinMsg[i].user_id);
        if (user.college_id == college_id);
        {
            printf("\t%s\t序号:%d\n", user.name, joinMsg[i].id);
        }
    }
    printf("\n输入运动员比赛序号取消该运动员报名,输入0返回\n");
    int chosen;
    scanf("%d", &chosen);
    fflush(stdin);
    if (chosen == 0)
        return;
    JoinMsg msg = selectJoinMsgById(chosen);

    if (msg.id != 0) {
        user = selectUserById(msg.user_id);
        match = selectMatchById(msg.match_id);
        printf(LIGHT_RED"确定取消%s的参赛资格吗\n\t%d\t%s\t%s\n", user.name, chosen, user.name, match.matchName);
        printf("1.确定\t2.取消\n"NONE);
        scanf("%d", &chosen);
        fflush(stdin);
        if (chosen == 1) {
            deleteJoinMsgById(chosen);
            printf("取消成功\n");
        }
    } else {
        printf("无此记录\n");
    }
    system("pause");
}

/*=================================================查看成绩==========================================================*/

/**
 * 2.2查询成绩
 * 二级菜单
 * @param college_id
 */
void selectGrade_College(int college_id) {
    while (1) {
        system("cls");
        printf("查看成绩\n");
        printf("1.查看学院成绩\n");
        printf("2.查看运动员成绩\n");
        printf("3.返回\n");
        int chosen;
        scanf("%d", &chosen);
        fflush(stdin);
        switch (chosen) {
            case 1:
                break;
            case 2:
                fflush(stdin);
                break;
            default:
                return;
        }
    }
}


void selectCollegeGrade(int college_id) {

    User *users, user;
    JoinMsg *joinMsg;
    Match match;
    int user_n, msg_n, match_n = countMatch();

    College college = selectCollegeById(college_id);
    printf("%s 目前在本次运动会中获得 %d 分\n", college.name, college.grade);

    printf("\n以下为本次运动会中各项比赛成绩");
    int grade;
    for (int i = 0; i < match_n; ++i) {
        grade = 0;
        msg_n = selectJoinMsgByMatch_id(&joinMsg, i + 1);
        match = selectMatchById(i + 1);
        for (int j = 0; j < msg_n; ++j) {
            grade = grade + getGrade(joinMsg[j]);
        }
        printf("\t%s 的总得分为 %d \n", match.matchName,grade);
    }

    printf("\n以下为本次运动会中表现出色的运动员:\n");
    for (int i = 0; i < match_n; ++i) {
        msg_n = selectJoinMsgByMatch_id(&joinMsg, i + 1);
        match = selectMatchById(i + 1);
        for (int j = 0; j < msg_n; ++j) {
            printf("\n");
            if (joinMsg[j].rank != 0 && joinMsg[j].grade != 0 && joinMsg[j].rank < 3) {
                user = selectUserById(joinMsg[j].user_id);

                if (user.college_id == college_id) {
                    printf("\t%s 同学在 %s 中获得第 %d 名\n", user.name, match.matchName, joinMsg[j].rank);
                }
            }
        }
    }


}



