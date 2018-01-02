#define TEST_HEADER \
	printf("\n=================%s================\n",__FUNCTION__)

typedef char DLinkType; 

typedef struct DLinkNode {
		DLinkType data; 
		struct DLinkNode* next; 
		struct DLinkNode* prev; 
} DLinkNode; 

void DLinkListInit(DLinkNode** head); 

DLinkNode* DLinkListPushBack(DLinkNode* head,
		DLinkType value); 

void DLinkListPopBack(DLinkNode* head); 

void DLinkListPushFront(DLinkNode* head,
		DLinkType value); 

void DLinkListPopFront(DLinkNode* head); 

DLinkNode* DLinkListFind(DLinkNode* head,
		DLinkType to_find); 

/** 
 * * @brief 往指定位置之前插入一个元素 
 * */ 
void DLinkListInsert(DLinkNode* pos,
		DLinkType value); 

/** 
 * * @brief 往指定位置之后插入一个元素 
 * */ 
void DLinkListInsertAfter(DLinkNode* pos,
		DLinkType value);
