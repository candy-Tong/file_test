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
 * 2.ѧԺ���
 * һ���˵�
 * @param college_id
 */
void CollegeInterface(int college_id) {

    while (1) {
        system("cls");
        printf("��ӭ��¼ѧԺ���\n");
        printf("1.��ѯ�������\n");
        printf("2.��ѯ�ɼ�\n");
        printf("3.�˳���¼\n");
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
                printf("������������������");
                Sleep(1500);
        }
    }
}
/*=================================================�鿴�������=======================================================*/
/**
 * 2.1ѡ�����
 * �����˵�������ѯȫ������ѯ��������
 * @param college_id
 */
void selectJoinMsg(int college_id) {

    while (1) {
        system("cls");
        printf("�鿴������Ϣ\n");
        printf("1.��ѯȫ��\n");
        printf("2.��ѯ��������\n");
        printf("3.����\n");
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
 * 2.1.1 ��ѯȫ��������Ϣ
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
        printf("\n\t%d �˲μ� %s\n", msg_n, match.matchName);
        printf("\t����\t���\n");
        for (int i = 0; i < msg_n; ++i) {
            user = selectUserById(joinMsg[i].user_id);
            if (user.college_id == college_id);
            {
                printf("\t%s\t%d\n", user.name, joinMsg[i].id);
            }

        }
        if (msg_n > 8) {
            printf(LIGHT_RED"ͬһ����Ŀ���ֻ�ܱ���8��\n"NONE);
        }
    }

    printf("\n�����˶�Ա�������ȡ�����˶�Ա����,����0����\n");
    int chosen;
    scanf("%d", &chosen);
    fflush(stdin);
    if (chosen == 0)
        return;
    JoinMsg msg = selectJoinMsgById(chosen);
    if (msg.id != 0) {
        user = selectUserById(msg.user_id);
        match = selectMatchById(msg.match_id);
        printf(LIGHT_RED"ȷ��ȡ��%s�Ĳ����ʸ���\n\t%d\t%s\t%s\n", user.name, chosen, user.name, match.matchName);
        printf("1.ȷ��\t2.ȡ��\n"NONE);
        scanf("%d", &chosen);
        fflush(stdin);
        if (chosen == 1) {
            deleteJoinMsgById(chosen);
            printf("ȡ���ɹ�\n");
            system("pause");
        }
    } else {
        printf("�޴˼�¼\n");
        system("pause");
    }


}

/**
 * 2.1.2��ѯȫ������
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
            printf(" ���\t������\t����ʱ��\t��������\n");
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
                strcpy(place, "�ܵ�");
                break;
            case 2:
                strcpy(place, "���߳���");
                break;
            case 3:
                strcpy(place, "ɳ��");
                break;
            case 4:
                strcpy(place, "Ǧ�򳡵�");
                break;
            case 5:
                strcpy(place, "��ǹ����");
                break;
        }
        msg_n = selectJoinMsgByMatch_id(&joinMsg, match[i].id);
        if (msg_n > 8)
            printf(LIGHT_RED"%d\t%s\t%s\t%s \n"NONE, i + 1, match[i].matchName, time, place);
        else
            printf("%d\t%s\t%s\t%s \n", i + 1, match[i].matchName, time, place);
    }
    printf("��ɫ������ʾ����Ŀ����������������\n");
    printf("\n��ѡ����Ҫ�鿴��������ı���,�������: ");
    int chosen;
    scanf("%d", &chosen);
    fflush(stdin);
    selectOneJoinMsg_College(college_id, match[chosen - 1].id);
}

/**
 * 2.1.2.1 ѡ�񵥸�����
 * @param college_id
 * @param match_id
 */
void selectOneJoinMsg_College(int college_id, int match_id) {


    JoinMsg *joinMsg;
    User user;
    int msg_n = selectJoinMsgByMatch_id(&joinMsg, match_id);
    Match match = selectMatchById(match_id);

    if (msg_n > 8)
        printf(LIGHT_RED"\n\t%d �˲μ� %s\n"NONE, msg_n, match.matchName);
    else
        printf("\n\t%d �˲μ� %s\n", msg_n, match.matchName);
    for (int i = 0; i < msg_n; ++i) {
        user = selectUserById(joinMsg[i].user_id);
        if (user.college_id == college_id);
        {
            printf("\t%s\t���:%d\n", user.name, joinMsg[i].id);
        }
    }
    printf("\n�����˶�Ա�������ȡ�����˶�Ա����,����0����\n");
    int chosen;
    scanf("%d", &chosen);
    fflush(stdin);
    if (chosen == 0)
        return;
    JoinMsg msg = selectJoinMsgById(chosen);

    if (msg.id != 0) {
        user = selectUserById(msg.user_id);
        match = selectMatchById(msg.match_id);
        printf(LIGHT_RED"ȷ��ȡ��%s�Ĳ����ʸ���\n\t%d\t%s\t%s\n", user.name, chosen, user.name, match.matchName);
        printf("1.ȷ��\t2.ȡ��\n"NONE);
        scanf("%d", &chosen);
        fflush(stdin);
        if (chosen == 1) {
            deleteJoinMsgById(chosen);
            printf("ȡ���ɹ�\n");
        }
    } else {
        printf("�޴˼�¼\n");
    }
    system("pause");
}

/*=================================================�鿴�ɼ�==========================================================*/

/**
 * 2.2��ѯ�ɼ�
 * �����˵�
 * @param college_id
 */
void selectGrade_College(int college_id) {
    while (1) {
        system("cls");
        printf("�鿴�ɼ�\n");
        printf("1.�鿴ѧԺ�ɼ�\n");
        printf("2.�鿴�˶�Ա�ɼ�\n");
        printf("3.����\n");
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
    printf("%s Ŀǰ�ڱ����˶����л�� %d ��\n", college.name, college.grade);

    printf("\n����Ϊ�����˶����и�������ɼ�");
    int grade;
    for (int i = 0; i < match_n; ++i) {
        grade = 0;
        msg_n = selectJoinMsgByMatch_id(&joinMsg, i + 1);
        match = selectMatchById(i + 1);
        for (int j = 0; j < msg_n; ++j) {
            grade = grade + getGrade(joinMsg[j]);
        }
        printf("\t%s ���ܵ÷�Ϊ %d \n", match.matchName,grade);
    }

    printf("\n����Ϊ�����˶����б��ֳ�ɫ���˶�Ա:\n");
    for (int i = 0; i < match_n; ++i) {
        msg_n = selectJoinMsgByMatch_id(&joinMsg, i + 1);
        match = selectMatchById(i + 1);
        for (int j = 0; j < msg_n; ++j) {
            printf("\n");
            if (joinMsg[j].rank != 0 && joinMsg[j].grade != 0 && joinMsg[j].rank < 3) {
                user = selectUserById(joinMsg[j].user_id);

                if (user.college_id == college_id) {
                    printf("\t%s ͬѧ�� %s �л�õ� %d ��\n", user.name, match.matchName, joinMsg[j].rank);
                }
            }
        }
    }


}



