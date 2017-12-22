//
//  PersonInfo.h
//  通讯录
//
//  Created by admin on 17/12/9.
//  Copyright © 2017年 Amon. All rights reserved.
//

#define NAME_MAX_SIZE 100
#define PHONE_MAX_SIZE 20
#define ADDR_MAX_SIZE 50

typedef struct PersonInfo {
    
    char name[NAME_MAX_SIZE];
    char phone[PHONE_MAX_SIZE];
    char addr[ADDR_MAX_SIZE];
    
}PersonInfo;
