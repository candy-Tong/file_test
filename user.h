//
// Created by candyTong on 2017/2/23.
//

#ifndef FILE_TEST_USER_H
#define FILE_TEST_USER_H

#include <stdio.h>
#include <stdlib.h>
#include <io.h>

//用户存储User结构体
typedef struct {
    int id;
    char account[30];
    char password[30];
    char name[30];
}User;
//链表无限扩展的User结构体
struct userArray{
    int id;
    char account[30];
    char password[30];
    char name[30];
    struct userArray *next;
};
typedef struct userArray UserArray;

//记录User数组大小的结构体
typedef struct {
    int size;
    User *user;
}UserWithSize;

/**
 * 将User链表转化为普通数组
 * @param userArray
 * @return
 */
UserWithSize transformArray(UserArray *userArray,int n){
    User *user=calloc(n, sizeof(User));
    for (User* p=user; p < user+n; ++p) {
        p->id=userArray->id;
        strcpy(p->account,userArray->account);
        strcpy(p->password,userArray->password);
        strcpy(p->name,userArray->name);
        userArray=userArray->next;
    }
    UserWithSize userWithSize={n,user};
    return userWithSize;
}

/**
 * 获取用户个数
 * @return
 */
int countUser(){
    FILE *fp;
    if((fp=fopen("user.dat","rb"))==NULL){
        if (_access("user.dat",0)==-1){
            if ((fp=fopen("user.dat","wb"))==NULL){
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
        return fileSize/sizeof(User);
    else
        return 0;
}
/**
 * 新增一个用户
 * @param user 用户结构体，其中id字段无需赋值
 */
void insertOneUser(User user){
    User __getLastUser();
    FILE *fp;
    if((fp=fopen("user.dat","ab"))==NULL){
        printf("无法打开此文件");
        if ((fp=fopen("user.dat","wb"))==NULL){
            printf("新建文件失败");
            exit(0);
        }
    }
    User lastUser=__getLastUser();
    user.id=lastUser.id+1;
    if(fwrite(&user, sizeof(User),1,fp)!=1)
        printf("fail to insert a user");
    fclose(fp);
}
/**
 * 查找user表中最后一个元素
 * user表没有元素则返回一个id为0的 User 结构体
 * @return
 */
User __getLastUser(){
    FILE *fp;
    if((fp=fopen("user.dat","rb"))==NULL){
        printf("无法打开此文件");
        exit(0);
    }
    User lastUser;
    if (countUser()!=0){
        fseek(fp,-sizeof(User),SEEK_END); /* 定位到文件最后一个用户 */
        fread(&lastUser, sizeof(User),1,fp);
    } else
        lastUser.id=0;
    fclose(fp);
    return lastUser;
}


/**
 * 根据id查找用户
 * 没有则返回一个 id=0 的结构体
 * @param id
 * @return
 */
User selectUserById(int id){
    FILE *fp;
    if((fp=fopen("user.dat","rb"))==NULL){
        printf("无法打开此文件");
        exit(0);
    }
    int n=countUser();
    User user;
    for (int i = 0; i < n; ++i) {
        fread(&user, sizeof(User),1,fp);
        if (user.id==id)
            return user;
    }
    fclose(fp);
    user.id=0;
    return  user;
}
/**
 * 按账号查找用户
 * 没有则返回一个id为0的结构体
 * @param account
 * @return
 */
User selectUserByAccount(char *account){
    FILE *fp;
    if((fp=fopen("user.dat","rb"))==NULL){
        printf("无法打开此文件");
        exit(0);
    }
    int n=countUser();
    User user;
    for (int i = 0; i < n; ++i) {
        fread(&user, sizeof(User),1,fp);
        if (strcmp(user.account,account)==0)
            return user;
    }
    fclose(fp);
    user.id=0;
    return  user;
}
/**
 * 按姓名查找用户
 * @param name
 * @return
 */
UserWithSize selectUserByName(char *name){
    FILE *fp;
    if((fp=fopen("user.dat","rb"))==NULL){
        printf("无法打开此文件");
        exit(0);
    }
    int n=countUser();
    UserArray *p1,*p2,*head=NULL;     //p1指向当前UserArray，p2指向上一个UserArray
    int count=0;        //用来计算链表长度
    p1=p2=malloc(sizeof(UserArray));
    for (int i = 0; i < n; ++i) {
        fread(p1, sizeof(User),1,fp);
        if (strcmp(p1->name,name)==0){
            if (count==0)
                head=p1;
            else
                p2->next=p1;
            p2=p1;
            count++;
            p1=malloc(sizeof(UserArray));
        }
    }
    fclose(fp);
    if(head!=NULL)
        return transformArray(head,count);
    else {
        UserWithSize userWithSize = {0, NULL};
        return userWithSize;
    }

}

/**
 * 根据user_id删除用户
 * 无此用户则不作处理
 * @param id
 */
void deleteUserById(int id){
    //函数声明
    User* selectAllUser();

    User *user=selectAllUser();
    int n= countUser();
    FILE *fp;
    if((fp=fopen("user.dat","wb"))==NULL){
        printf("无法打开此文件");
        exit(0);
    }
    for (int i = 0; i < n; ++i) {
        if (user[i].id==id)
            continue;
        fwrite(&user[i], sizeof(User),1,fp);
    }
    fclose(fp);
}
/**
 * 更新用户数据
 * @param id
 * @param updateUser 该参数为User结构体，传入时必须为 没有被更改的数据 赋上原来值
 */
void updateUserById(int id,User updateUser){
    //函数声明
    User* selectAllUser();

    User *user=selectAllUser();
    int n= countUser();
    FILE *fp;
    if((fp=fopen("user.dat","wb"))==NULL){
        printf("无法打开此文件");
        exit(0);
    }
    for (int i = 0; i < n; ++i) {
        if (user[i].id==id){
            fwrite(&updateUser, sizeof(User),1,fp);
        } else
            fwrite(&user[i], sizeof(User),1,fp);
    }
    fclose(fp);
}

User* selectAllUser(){
    FILE *fp;
    if((fp=fopen("user.dat","rb"))==NULL){
        printf("无法打开此文件");
        exit(0);
    }
    int n=countUser();
    User *user=calloc(n, sizeof(User));         //记得free 释放掉这段空间
    for (int i = 0; i < n; ++i) {
        fread(&user[i], sizeof(User),1,fp);
    }
    fclose(fp);
    return user;
}


#endif //FILE_TEST_USER_H
