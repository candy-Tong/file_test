#include <stdio.h>
#include <mem.h>
#include <afxres.h>
#include "common.h"


int main() {
    void CollegeInterface(int college_id);
    void UserInterface(int user_id);
    void CollegeInterface(int college_id);
    void AdminInterface(int user_id);
    int validate(int choice);
    int choice;
    int id;
    void randUser();
    int insertUsersFormText();
    void randJoinMsg();
    int insertJoinMsgFormText();
    User* selectAllUser();
    int countUser();
//    randUser();
//    randJoinMsg();
//    insertUsersFormText();
//    insertJoinMsgFormText();
//    User *user=selectAllUser();
//    for (int i = 0; i < countUser(); ++i) {
//        printf("%d %s %s %s %d %d\n",user[i].id,user[i].account,user[i].password,user[i].name,user[i].college_id,user[i].sex);
//    }
//    JoinMsg *selectAllJoinMsg();
//    JoinMsg *joinMsg=selectAllJoinMsg();
//    int  countJoinMsg();
//    for (int i = 0; i < countJoinMsg(); ++i) {
//        printf("%d %d %d\n",joinMsg[i].id,joinMsg[i].user_id,joinMsg[i].match_id);
//    }
    while (1) {
        system("cls");
        printf("1.ѧ����½\n");
        printf("2.ѧԺ��½\n");
        printf("3.����Ա��¼\n");
        printf("4.�˳�\n");

        scanf("%d", &choice);
        fflush(stdin);
        id = validate(choice);
        if (id == -1)
            continue;
        else if (id == 0) {
            printf("\t������������������\n");
            Sleep(1500);
        }
        switch (choice) {
            case 1:
                UserInterface(id);
                break;
            case 2:
                CollegeInterface(id);
                break;
            case 3:
                AdminInterface(1);
                break;
            case 4:
                return 0;
        }
    }
    return 0;
}

/**
 * ��֤����
 * @param choice
 * @return  user_id ��¼�ɹ� 0 ѡ������ -1 ����
 */
int validate(int choice) {
    User selectUserByAccount(char *account);
    College selectCollegeByAccount(char *account);
    void inputPassword(char *pwd);

    char account[30], password[30];
    User user;
    College college;
    char esc[30] = "0";
    int status = 0;
    int id;

    if (choice == 4)
        exit(0);
    while (1) {
        printf("�������˺����룬����0����\n");
        system("cls");
        printf("�˺�:\t");
        scanf("%s", account);
        fflush(stdin);
        printf("����:\t");
        inputPassword(password);
        fflush(stdin);
        if (strcmp(account, esc) == 0)
            return -1;
        switch (choice) {
            case 1:
                user = selectUserByAccount(account);
                if (strcmp(user.password, password) == 0) {
                    status = 1;
                    id = user.id;
                } else {
                    printf("\n�������\n");
                    Sleep(1000);
                }
                break;
            case 2:
                college = selectCollegeByAccount(account);
                if (strcmp(college.password, password) == 0) {
                    status = 1;
                    id = college.id;
                } else {
                    printf("\n�������\n");
                    Sleep(1000);
                }
                break;
            case 3:
                id = 1;
                status = 1;
                break;
            default:
                return 0;
        }
        if (status == 1) {
            printf("\n��¼�ɹ���������ת");
            for (int i = 0; i < 5; ++i) {
                printf(".");
                Sleep(400);
            }
            return id;
        }
    }

}