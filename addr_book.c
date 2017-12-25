//
//  addr_book.c
//  通讯录
//
//  Created by admin on 17/12/13.
//  Copyright © 2017年 Amon. All rights reserved.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "addr_book.h"

void menu()
{
    printf("///////////////////////////////////\n");
    printf("//     1.显示所有联系人信息         //\n");
    printf("//     2.新增联系人                //\n");
    printf("//     3.删除联系人                //\n");
    printf("//     4.查找联系人                //\n");
    printf("//     5.修改联系人信息            //\n");
    printf("//     6.清空所有联系人信息         //\n");
    printf("//     0.退出                     //\n");
    printf("///////////////////////////////////\n");
    
}

void AddrBookInit(AddrBook* addr_book)
{
    if (addr_book == NULL)
        return;
    addr_book->data = (PersonInfo*)malloc(sizeof(PersonInfo));
    if (addr_book->data == NULL) {
        printf("malloc error: init!\n");
    }
    addr_book->size = 0;
    addr_book->capacity = 1;
    
}

void capacityadd(AddrBook* addr_book)
{
    PersonInfo* new_book = (PersonInfo*)malloc
            (sizeof(PersonInfo)*(addr_book->capacity*2+1));
    if (new_book == NULL) {
        printf("malloc error!\n");
    }
    memcpy(new_book, addr_book->data,
           sizeof(PersonInfo)*addr_book->size);
    free(addr_book->data);
    
    addr_book->data = new_book;
    addr_book->capacity = addr_book->capacity*2+1;
    addr_book->size = addr_book->size;
    
}


void AddrBookAdd(AddrBook* addr_book)
{
    if (addr_book == NULL || addr_book->data == NULL)
        return;
    if (addr_book->capacity == addr_book->size)
        capacityadd(addr_book);
    
    printf("请输入联系人姓名:>");
    char name[100] = {0};
    scanf("%s",name);
    strncpy((addr_book->data + addr_book->size)->name, name, sizeof(addr_book->data->name));
    
    printf("请输入联系人电话:>");
    char phone[20] = {0};
    scanf("%s",phone);
    strncpy((addr_book->data + addr_book->size)->phone, phone, sizeof(addr_book->data->phone));
    
    printf("请输入联系人地址:>");
    char addr[50] = {0};
    scanf("%s",addr);
    strncpy((addr_book->data + addr_book->size)->addr, addr, sizeof(addr_book->data->addr));
    
    addr_book->size++;
    printf("添加成功！\n");
    printf("继续添加联系人请按2;返回主菜单请按0:\n");
    
    getchar();
    int choice;
    scanf("%d", &choice);
    while ( choice != 2 && choice != 0) {
        printf("输入错误,请重新输入:\n");
        getchar();
        scanf("%d", &choice);
    }
    if (choice == 0) {
        return;
    }else{
        AddrBookAdd(addr_book);
    }
}


void AddrBookDisplay(AddrBook* addr_book)
{
    if (addr_book == NULL || addr_book->data == NULL) {
        return;
    }
    
    if (addr_book->size == 0) {
        printf("目前无联系人，是否进行添加？\n1.添加联系人\n0.返回主菜单\n");
        int choice;
        getchar();
        scanf("%d", &choice);
        while (choice != 1 && choice != 0) {
            printf("选择错误，请重新输入:>\n");
            getchar();
            scanf("%d", &choice);
        }
        if (choice == 1) {
            AddrBookAdd(addr_book);
        }
        return;
    }
    
    printf("[No.]  [name]         [phone]         [addr]\n");
    size_t count = 0;
    
    for ( ; count < addr_book->size; ++count) {
        printf("%-7lu%-15s%-16s%s\n",count+1,
               (addr_book->data+count)->name,
               (addr_book->data+count)->phone,
               (addr_book->data+count)->addr);
    }
}


void AddrBookErase_Person(AddrBook* addr_book, int number)
{
    if (addr_book == NULL || addr_book->data == NULL) {
        return;
    }
    printf("是否确认删除？\n1.确认\n0.返回\n");
    int choice;
    scanf("%d", &choice);
    while (choice != 1 && choice != 0) {
        printf("选择错误，请重新输入:>\n");
        scanf("%d", &choice);
    }
    
    if (choice == 1) {
        memcpy(addr_book->data+number-1, addr_book->data+number, sizeof(PersonInfo)*(addr_book->size-number));
        
        addr_book->size--;
        printf("删除成功！\n");
        AddrBookDisplay(addr_book);
    }
}


void AddrBookErase(AddrBook* addr_book)
{
    if (addr_book == NULL || addr_book->data == NULL) {
        return;
    }
    if (addr_book->size == 0) {
        printf("当前无联系人可删除\n");
        return;
    }
    AddrBookDisplay(addr_book);
    printf("请选择要删除的联系人编号[返回主菜单请按0]\n");
    int number;
    scanf("%d", &number);
    while (number > addr_book->size || number <= 0) {
        if (number == 0) {
            return;
        }
        printf("不在删除范围内，请重新输入:>");
        scanf("%d", &number);
    }
    if (addr_book->size != 0) {
        AddrBookErase_Person(addr_book, number);
    }
}


void AddrBookFind_Number(AddrBook* addr_book)
{
flag:
    AddrBookDisplay(addr_book);
    printf("请输入要查找联系人的编号(输入0退出):\n");
    int number;
    scanf("%d", &number);
    while ( number > addr_book->size || number <= 0) {
        
        if (number == 0) {
            return;
        }
        printf("不在查找范围内，请重新输入:>");
        scanf("%d", &number);
    }
    printf("[No.]  [name]         [phone]         [addr]\n");
    printf("%-7d%-15s%-16s%s\n",number,
           (addr_book->data+number-1)->name,
           (addr_book->data+number-1)->phone,
           (addr_book->data+number-1)->addr);
    printf("重新按编号查找请按1，按其他方式查找请按0\n:>");
    getchar();
    int choice;
    scanf("%d", &choice);
    while ( choice != 1 && choice != 2 && choice != 0) {
        printf("输入错误,请重新输入:\n");
        getchar();
        scanf("%d", &choice);
    }
    if (choice == 1) {
        goto flag;
    }
    else
        AddrBookFind(addr_book);
}


void AddrBookFind_Name(AddrBook* addr_book)
{
flag:
    printf("请输入要查找的人姓名:>");
    char Name[100] = {0};
    scanf("%s",Name);
    printf("[No.]  [name]         [phone]         [addr]\n");
    size_t i = 0;
    int count = 0;
    for ( ; i < addr_book->size ; i++) {
        if (strstr((addr_book->data+i)->name, Name)) {
            printf("%-7lu%-15s%-16s%s\n",i+1,
                   (addr_book->data+i)->name,
                   (addr_book->data+i)->phone,
                   (addr_book->data+i)->addr);
            count++;
        }
        
    }
    if (count == 0) {
        printf("无此联系人，重新输入姓名请按1，按其他方式查找请按2，退出请按0\n:>");
    }
    else{
        printf("重新按姓名查找请按1，按其他方式查找请按2，退出请按0\n:>");
    }
    getchar();
    int choice;
    scanf("%d", &choice);
    while ( choice != 1 && choice != 2 && choice != 0) {
        printf("输入错误,请重新输入:\n");
        getchar();
        scanf("%d", &choice);
    }
    if (choice == 1) {
        goto flag;
    }
    else if (choice == 2){
        AddrBookFind(addr_book);
    }
    else
        return;
}

void AddrBookFind_Phone(AddrBook* addr_book)
{
flag:
    printf("请输入要查找的人电话:>");
    char Phone[20] = {0};
    scanf("%s",Phone);
    printf("[No.]  [name]         [phone]         [addr]\n");
    size_t i = 0;
    int count = 0;
    for ( ; i < addr_book->size ; i++) {
        if (strstr((addr_book->data+i)->phone, Phone)) {
            printf("%-7lu%-15s%-16s%s\n",i+1,
                   (addr_book->data+i)->name,
                   (addr_book->data+i)->phone,
                   (addr_book->data+i)->addr);
            count++;
        }
        
    }
    if (count == 0) {
        printf("无此联系人，重新输入电话请按1，按其他方式查找请按2，退出请按0\n:>");
    }
    else{
        printf("重新按电话查找请按1，按其他方式查找请按2，退出请按0\n:>");
    }
    getchar();
    int choice;
    scanf("%d", &choice);
    while ( choice != 1 && choice != 2 && choice != 0) {
        printf("输入错误,请重新输入:\n");
        getchar();
        scanf("%d", &choice);
    }
    if (choice == 1) {
        goto flag;
    }
    else if (choice == 2)
        AddrBookFind(addr_book);
    
    else
        return;
}


void AddrBookFind_Addr(AddrBook* addr_book)
{
flag:
    printf("请输入要查找的人地址:>");
    char Addr[50] = {0};
    scanf("%s",Addr);
    printf("[No.]  [name]         [phone]         [addr]\n");
    size_t i = 0;
    int count = 0;
    for ( ; i < addr_book->size ; i++) {
        if (strstr((addr_book->data+i)->addr, Addr)) {
            printf("%-7lu%-15s%-16s%s\n",i+1,
                   (addr_book->data+i)->name,
                   (addr_book->data+i)->phone,
                   (addr_book->data+i)->addr);
            count++;
        }
    }
    if (count == 0) {
        printf("无此联系人，重新输入地址请按1，按其他方式查找请按2，退出请按0\n:>");
    }
    else{
        printf("重新按地址查找请按1，按其他方式查找请按2，退出请按0\n:>");
    }
    getchar();
    int choice;
    scanf("%d", &choice);
    while ( choice != 1 && choice != 2 && choice != 0) {
        printf("输入错误,请重新输入:\n");
        getchar();
        scanf("%d", &choice);
    }
    if (choice == 1) {
        goto flag;
    }
    else if (choice == 2)
        AddrBookFind(addr_book);
    else
        return;
}


void AddrBookFind(AddrBook* addr_book)
{
    if (addr_book == NULL || addr_book->data == NULL) {
        return;
    }
    if (addr_book->size == 0) {
        printf("当前无联系人\n");
        return;
    }
    
    printf("请问您要按以下哪种方式找:\n");
    printf("1.number\n2.name\n3.phone\n4.address\n0.返回主菜单\n");
    int choice;
    scanf("%d", &choice);
    while ( choice != 0 && choice != 1 && choice != 2 && choice != 3 && choice != 4) {
        printf("输入有误，请重新输入;>");
        scanf("%d", &choice);
    }
    switch (choice) {
        case 1:
            AddrBookFind_Number(addr_book);
            break;
        case 2:
            AddrBookFind_Name(addr_book);
            break;
        case 3:
            AddrBookFind_Phone(addr_book);
            break;
        case 4:
            AddrBookFind_Addr(addr_book);
            break;
        case 0:
            return;
            break;
        default:
            printf("选择错误，请重新输入:\n");
            break;
    }
}


void AddrBookModify_Name(AddrBook* addr_book, int number)
{
    printf("请输入要修改的名字:>");
    char Name[100] = {0};
    scanf("%s",Name);
    strncpy((addr_book->data+number-1)->name, Name, sizeof(addr_book->data->name));
    printf("修改姓名成功！\n");
    AddrBookDisplay(addr_book);
}

void AddrBookModify_Phone(AddrBook* addr_book, int number)
{
    printf("请输入要修改的联系电话:>");
    char Phone[20] = {0};
    scanf("%s",Phone);
    strncpy((addr_book->data+number-1)->phone, Phone, sizeof(addr_book->data->phone));
    printf("修改联系电话成功！\n");
    AddrBookDisplay(addr_book);
}

void AddrBookModify_Addr(AddrBook* addr_book, int number)
{
    printf("请输入要修改的地址:>");
    char Addr[50] = {0};
    scanf("%s",Addr);
    strncpy((addr_book->data+number-1)->addr, Addr, sizeof(addr_book->data->addr));
    printf("修改地址成功！\n");
    AddrBookDisplay(addr_book);
}


void AddrBookModify_Person(AddrBook* addr_book,int number)
{
    printf("请选择要操作的内容\n");
flag:
    printf("1.删除联系人\n2.修改姓名\n3.修改联系电话\n4.修改地址\n0.退出\n");
    
    int choice;
    scanf("%d", &choice);
    while (choice != 1 && choice != 2 && choice != 3 && choice != 4 && choice != 0) {
        printf("选择错误，请重新输入:>");
        scanf("%d", &choice);
    }
    
    switch (choice) {
        case 1:
            AddrBookErase_Person(addr_book, number);
            if (addr_book->size != 0) {
                printf("是否继续进行修改操作？\n");
                goto flag;
            }
            break;
        case 2:
            AddrBookModify_Name(addr_book, number);
            if (addr_book->size != 0) {
                printf("是否继续进行修改操作？\n");
                goto flag;
            }
            break;
        case 3:
            AddrBookModify_Phone(addr_book, number);
            if (addr_book->size != 0) {
                printf("是否继续进行修改操作？\n");
                goto flag;
            }
            break;
        case 4:
            AddrBookModify_Addr(addr_book, number);
            if (addr_book->size != 0) {
                printf("是否继续进行修改操作？\n");
                goto flag;
            }
            break;
        case 0:
            return;
            break;
        default:
            break;
    }
}


void AddrBookModify(AddrBook* addr_book)
{
    if (addr_book == NULL || addr_book->data == NULL) {
        return;
    }
    if (addr_book->size == 0) {
        printf("当前无联系人\n");
        return;
    }
flag:
    AddrBookDisplay(addr_book);
    printf("请输入要修改的联系人编号(输入0返回上一级):\n");
    
    int number;
    getchar();
    scanf("%d", &number);
    while ( number > addr_book->size || number <= 0) {
        
        if (number == 0) {
            return;
        }
        printf("不在范围内，请重新输入:>");
        getchar();
        scanf("%d", &number);
    }
    
    printf("[No.]  [name]         [phone]         [addr]\n");
    printf("%-7d%-15s%-16s%s\n",number,
           (addr_book->data+number-1)->name,
           (addr_book->data+number-1)->phone,
           (addr_book->data+number-1)->addr);
    printf("是否为要修改的联系人？\n1.确认\n2.重新选择\n0.返回主菜单\n:>");
    
    int choice;
    scanf("%d",&choice);
    while (choice != 0 && choice != 1 && choice != 2) {
        printf("输入有误，请重新输入:>");
        scanf("%d",&choice);
    }
    if (choice == 1) {
        AddrBookModify_Person(addr_book,number);
        return;
    }
    else if (choice == 2)
        goto flag;
    else
        return;
}

void AddrBookEmpty(AddrBook* addr_book)
{
    if (addr_book == NULL || addr_book->data == NULL) {
        return;
    }
    addr_book->size = 0;
    printf("清空成功！\n");
}


void AddrBookDestroy(AddrBook* addr_book)
{
    free(addr_book->data->name);
    
    addr_book->data = NULL;
    addr_book->size = 0;
    addr_book->capacity = 1;
}


void AddrBookSave(AddrBook* addr_book)
{
    if (addr_book == NULL) {
        return;
    }
    
    FILE* Psave = fopen(FILE_PATH, "w");
    
    if (Psave == NULL) {
        printf("open file error!\n");
        return;
    }
    
    size_t count = 0;
    for ( ; count < addr_book->size; count++) {
        fwrite((addr_book->data+count)->name,
               sizeof((addr_book->data+count)->name), 1, Psave);
        fwrite((addr_book->data+count)->phone,
               sizeof((addr_book->data+count)->phone), 1, Psave);
        fwrite((addr_book->data+count)->addr,
               sizeof((addr_book->data+count)->addr), 1, Psave);
    }
    fclose(Psave);
}


void AddrBookLoad(AddrBook* addr_book)
{
    if (addr_book == NULL) {
        return;
    }
    
    FILE* Pload = fopen(FILE_PATH, "r");
    if (Pload == NULL) {
        printf("open file error!\n");
        return;
    }
    
    size_t count = 0;
    while (feof(Pload) == 0) {
        fread((addr_book->data+count)->name,
              sizeof((addr_book->data+count)->name), 1, Pload);
        fread((addr_book->data+count)->phone,
              sizeof((addr_book->data+count)->phone), 1, Pload);
        fread((addr_book->data+count)->addr,
              sizeof((addr_book->data+count)->addr), 1, Pload);

        count++;
    }
    //feof先读取，读取到二进制文件末尾时，会写入FF，等到下一次判断发现是FF再返回非0
    //值，所以减1（因为多读取了一次）
    addr_book->size = count-1;
    addr_book->capacity = count;
    fclose(Pload);
}


int main ()
{
    AddrBook* addr_book;
    AddrBookInit(addr_book);
    AddrBookLoad(addr_book);
    
    
    while (1){
        
        menu();
        printf("请输入您的选择:");
        int choice;
        scanf("%d",&choice);
        switch (choice){
            
            case DISPLAY:
                AddrBookDisplay(addr_book);
                AddrBookSave(addr_book);
                break;
            case ADD:
                AddrBookAdd(addr_book);
                AddrBookSave(addr_book);
                break;
            case ERASE:
                AddrBookErase(addr_book);
                AddrBookSave(addr_book);
                break;
            case FIND:
                AddrBookFind(addr_book);
                break;
            case MODIFY:
                AddrBookModify(addr_book);
                AddrBookSave(addr_book);
                break;
            case EMPTY:
                AddrBookEmpty(addr_book);
                AddrBookSave(addr_book);
                break;
            case EXIT:
                AddrBookDestroy(addr_book);
                return 0;
                break;
            default:
                printf("输入错误，请重新选择:\n");
                break;
        }
    }

    return 0;
}
