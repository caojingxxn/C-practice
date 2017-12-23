#include <stddef.h>
#include "PersonInfo.h"

#define FILE_PATH "data.txt"

enum {
    
    DISPLAY = 1,
    ADD = 2,
    ERASE = 3,
    FIND = 4,
    MODIFY = 5,
    EMPTY = 6,
    EXIT = 0
    
};

typedef struct AddrBook {
    
    PersonInfo* data;
    size_t size;
    size_t capacity;
    
}AddrBook;

/**
 * * @brief 初始化通讯录
 * *
 * * @param addr_book 结构体指针
 * */
void AddrBookInit(AddrBook* addr_book);

/**
 * * @brief 通讯录中增加条目
 * *
 * * @param addr_book 结构体指针
 * */
void AddrBookAdd(AddrBook* addr_book);

/**
 * * @brief 删除通讯录中的指定条目
 * *
 * * @param addr_book 结构体指针
 * */
void AddrBookErase(AddrBook* addr_book);

/**
 * * @brief 按指定规则查找通讯录中特定条目
 * *
 * * @param addr_book 结构体指针
 * */
void AddrBookFind(AddrBook* addr_book);

/**
 * * @brief 打印通讯录中的所有信息
 * *
 * * @param addr_book 结构体指针
 * */
void AddrBookDisplay(AddrBook* addr_book);

/**
 * * @brief 修改通讯录的指定条目
 * *
 * * @param addr_book 结构体指针
 * */
void AddrBookModify(AddrBook* addr_book);

/**
* * @brief 清空通讯录
* *
* * @param addr_book 结构体指针
* */
void AddrBookEmpty(AddrBook* addr_book);

/**
 * * @brief 销毁通讯录
 * *
 * * @param addr_book 结构体指针
 * */
void AddrBookDestroy(AddrBook* addr_book);

/**
 * * @brief 将通讯录内容保存在文件
 * *
 * * @param addr_book 结构体指针
 * */
void AddrBookSave(AddrBook* addr_book);

/**
 * * @brief 将文件中的内容加载回内存.
 * *
 * * @param addr_book 结构体指针
 * */
void AddrBookLoad(AddrBook* addr_book);

