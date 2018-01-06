#include <stdio.h>

#include "../SeqStack.h"

#define MAX_ROW 6
#define MAX_COL 6

typedef struct Maze {
	int map[MAX_ROW][MAX_COL];
}Maze;

void InitMap(Maze* maze) {
	int map[MAX_ROW][MAX_COL] = 
		{
			{ 0 , 1 , 0 , 0 , 0 , 0 },
			{ 0 , 1 , 1 , 1 , 0 , 0 },
			{ 0 , 1 , 0 , 1 , 1 , 0 },
			{ 0 , 1 , 1 , 0 , 0 , 0 },
			{ 0 , 0 , 1 , 0 , 0 , 0 },
			{ 0 , 0 , 1 , 0 , 0 , 0 },
		};
	int i = 0;
	for (;i < MAX_ROW; ++i) {
		int j = 0;
		for (; j < MAX_COL; ++j) {
			maze->map[i][j] = map[i][j];
		}
	}
}

void InitMapMulti(Maze* maze) {
	int map[MAX_ROW][MAX_COL] = 
		{
			{ 0 , 1 , 0 , 0 , 0 , 0 },
			{ 0 , 1 , 1 , 1 , 0 , 0 },
			{ 0 , 1 , 0 , 1 , 1 , 1 },
			{ 1 , 1 , 1 , 0 , 0 , 0 },
			{ 0 , 0 , 1 , 0 , 0 , 0 },
			{ 0 , 0 , 1 , 0 , 0 , 0 },
		};
	int i = 0;
	for (;i < MAX_ROW; ++i) {
		int j = 0;
		for (; j < MAX_COL; ++j) {
			maze->map[i][j] = map[i][j];
		}
	}
}

void InitMapWithCycle(Maze* maze) {
	int map[MAX_ROW][MAX_COL] = 
		{
			{ 0 , 1 , 0 , 0 , 0 , 0 },
			{ 0 , 1 , 1 , 1 , 0 , 0 },
			{ 0 , 1 , 0 , 1 , 1 , 1 },
			{ 1 , 1 , 1 , 1 , 0 , 0 },
			{ 0 , 0 , 1 , 0 , 0 , 0 },
			{ 0 , 0 , 1 , 0 , 0 , 0 },
		};
	int i = 0;
	for (;i < MAX_ROW; ++i) {
		int j = 0;
		for (; j < MAX_COL; ++j) {
			maze->map[i][j] = map[i][j];
		}
	}
}

int IsStay(Maze* maze, Point cur) {
	if (cur.row >= 0 && cur.col >= 0 && cur.row < MAX_ROW && cur.col < MAX_COL) {
		if (maze->map[cur.row][cur.col] == 1) {
			return 1;
		}
	}
	return 0;
}

int IsEnd(Point cur, Point entry) {
	if (cur.row == 0 || cur.row == MAX_ROW-1 ||
				cur.col == 0 || cur.col == MAX_COL-1) {
		if (cur.row == entry.row && cur.col == entry.col) {
			return 0;
		} else {
			return 1;
		}
	}
	return 0;
}

void Mark(Maze* maze, Point cur) {
	maze->map[cur.row][cur.col] = 2;
}

void HasMaze(Maze* maze, Point cur, Point entry) {
	// 1.判断是否为落脚点（1为落脚点）
	if ( !IsStay(maze, cur) ) {
		return;
	}
	// 2.走过标记为2
	Mark(maze, cur);
	// 3.判断是否为终点（边缘）
	if ( IsEnd(cur, entry) ) {
		printf("找到路了！  %d %d\n", cur.row, cur.col);
		return;
	}
	Point UP = {cur.row-1, cur.col};
	HasMaze(maze, UP, entry);

	Point RIGHT = {cur.row, cur.col+1};
	HasMaze(maze, RIGHT, entry);
	
	Point DOWN = {cur.row+1, cur.col};
	HasMaze(maze, DOWN, entry);
	
	Point LEFT = {cur.row, cur.col-1};
	HasMaze(maze, LEFT, entry);
}

void HasMaze_ByLoop(Maze* maze, Point cur, Point entry) {
	SeqStack stack;
	SeqStackInit(&stack);
	// 1.判断入口点能否落脚，若能，标记入口点，将入口点入栈
	if ( IsStay(maze, entry) ) {
		Mark(maze, entry);
		SeqStackPush(&stack, entry);//将入口点入栈
	} else {
		return;
	}
	//进入循环,取栈顶元素
	while ( SeqStackTop(stack, &cur) ) {
		// 2.判断当前点是否为终点
		if ( IsEnd(cur, entry) ) {
			printf("找到路了！  %d %d\n", cur.row, cur.col);
			//return;
		}
		//   a) 若不是终点，按一定顺序判断当前点的周围点，
		//			 若能落脚，当前点变为周围某点，即入栈，并标记、contiune（继续循环）
		Point UP = {cur.row-1, cur.col};
		if (IsStay(maze, UP)) {
			SeqStackPush(&stack, UP);
			Mark(maze, UP);
			continue;
		}

		Point RIGHT = {cur.row, cur.col+1};
		if (IsStay(maze, RIGHT)) {
			SeqStackPush(&stack, RIGHT);
			Mark(maze, RIGHT);
			continue;
		}

		Point DOWN = {cur.row+1, cur.col};
		if (IsStay(maze, DOWN)) {
			SeqStackPush(&stack, DOWN);
			Mark(maze, DOWN);
			continue;
		}

		Point LEFT = {cur.row, cur.col-1};
		if (IsStay(maze, LEFT)) {
			SeqStackPush(&stack, LEFT);
			Mark(maze, LEFT);
			continue;
		}
		//   b) 若当前点的周围点都不能落脚，将当前点出栈（当前点变为上一个点）
		SeqStackPop(&stack);
	}
}

void __MazeMulti(Maze* maze, SeqStack* Short, SeqStack* stack, Point cur, Point entry) {
	if ( !IsStay(maze, cur) ) {
		return;
	}
	Mark(maze, cur);
	SeqStackPush(stack, cur);

	if ( IsEnd(cur, entry) ) {
		SeqStackPrintChar(*stack, "\n路径为");
		if ( SeqStackSize(*Short) == 0 || SeqStackSize(*Short) > SeqStackSize(*stack) ){
			*Short = *stack;
		}
		//SeqStackPrintChar(*Short, "栈");
	}
	Point UP = {cur.row-1, cur.col};
	__MazeMulti(maze, Short, stack, UP, entry);

	Point RIGHT = {cur.row, cur.col+1};
	__MazeMulti(maze, Short, stack, RIGHT, entry);
	
	Point DOWN = {cur.row+1, cur.col};
	__MazeMulti(maze, Short, stack, DOWN, entry);
	
	Point LEFT = {cur.row, cur.col-1};
	__MazeMulti(maze, Short, stack, LEFT, entry);
	
	SeqStackPop(stack);
}

void MazeMulti(Maze* maze, Point cur, Point entry) {
	SeqStack stack;
	SeqStackInit(&stack);
	SeqStack Short;
	SeqStackInit(&Short);
	__MazeMulti(maze, &Short, &stack, cur, entry);
	SeqStackPrintChar(Short,"最短路径为");
}

int IsStayWithCycle(Maze* maze, Point cur, Point pre) {
	if (cur.row < 0 || cur.col < 0 || cur.row >= MAX_ROW || cur.col >= MAX_COL) {
		return 0;
	}
	int cur_value = maze->map[cur.row][cur.col];
	if (cur_value == 1) {
		return 1;
	}
	if (pre.row >= 0 && pre.col >= 0 && pre.row < MAX_ROW && pre.col < MAX_COL ) {
		int pre_value = maze->map[pre.row][pre.col];
		if (cur_value - 1 > pre_value) {
			return 1;
		}
	}
	return 0;
}

void MarkWithCycle(Maze* maze, Point cur, Point pre) {
	if (pre.row >= 0 && pre.col >= 0 && pre.row < MAX_ROW && pre.col < MAX_COL ) {
		int pre_value = maze->map[pre.row][pre.col];
		maze->map[cur.row][cur.col] = pre_value + 1;
		return;
	}
	maze->map[cur.row][cur.col] = 2;
}

void __MazeMultiWithCycle(Maze* maze, SeqStack* Short, SeqStack* stack,
			Point pre, Point cur, Point entry) {
	// 1.判断当前点能否落脚
	if (!IsStayWithCycle(maze, cur, pre)) {
		return;
	}
	// 2.标记为上一点+1，入栈 
	MarkWithCycle(maze, cur, pre);
	SeqStackPush(stack, cur);
	// 3.判断是否为终点
	if (IsEnd(cur, entry)) {
		// a)是终点 替换stack，出栈
		SeqStackPrintChar(*stack, "\n路径为");
		if ( SeqStackSize(*Short) == 0 || SeqStackSize(*Short) > SeqStackSize(*stack) ){
			*Short = *stack;
		}
	}
		// b)不是终点 四个方向递归
	Point UP = {cur.row-1, cur.col};
	__MazeMultiWithCycle(maze, Short, stack, cur, UP, entry);

	Point RIGHT = {cur.row, cur.col+1};
	__MazeMultiWithCycle(maze, Short, stack, cur, RIGHT, entry);
	
	Point DOWN = {cur.row+1, cur.col};
	__MazeMultiWithCycle(maze, Short, stack, cur, DOWN, entry);
	
	Point LEFT = {cur.row, cur.col-1};
	__MazeMultiWithCycle(maze, Short, stack, cur, LEFT, entry);
	
	SeqStackPop(stack);
}

void MazeMultiWithCycle(Maze* maze, Point cur, Point entry) {
	SeqStack stack;
	SeqStackInit(&stack);
	SeqStack Short;
	SeqStackInit(&Short);
	__MazeMultiWithCycle(maze, &Short, &stack, cur, cur, entry);
	SeqStackPrintChar(Short,"最短路径为");
}

///////////////////////////////
//  以下为测试代码
///////////////////////////////
#if 1
#define TEST_HEADER printf("\n=========%s=========\n",__FUNCTION__)

void PrintMap(Maze maze) {
	int row = 0;
	for (; row < MAX_ROW; ++row) {
		int col = 0;
		for (; col < MAX_COL; ++col) {
			printf(" %2d",maze.map[row][col]);
		}
		printf("\n");
	}
}

void Test1() {
	TEST_HEADER;
	Maze maze;
	InitMap(&maze);
	PrintMap(maze);
}

void Test2() {
	TEST_HEADER;
	Maze maze;
	InitMap(&maze);
  Point entry = {0,1};
	HasMaze(&maze, entry, entry);
	PrintMap(maze);
}

void Test3() {
	TEST_HEADER;
	Maze maze;
	InitMap(&maze);
  Point entry= {0,1};
	// 1.判断入口点能否落脚，若能，入栈（有一个栈顶元素）
	// 2.进入循环，取栈顶元素为当前点
	//  a) 判断是否为终点
	//  b) 不是终点：判断四周的点能否落脚，若能，入栈，标记，continue
	//  c) 四周的点都不能落脚：出栈
	HasMaze_ByLoop(&maze, entry, entry);
	PrintMap(maze);
}

void Test4() {
	TEST_HEADER;
	Maze maze;
	InitMapMulti(&maze);
  Point entry= {0,1};
	MazeMulti(&maze, entry, entry);
	PrintMap(maze);
}

void Test5() {
	TEST_HEADER;
	Maze maze;
	InitMapWithCycle(&maze);
  Point entry= {0,1};
	MazeMultiWithCycle(&maze, entry, entry);
	PrintMap(maze);
}

int main() {
	system("clear");
  Test1();//初始化地图
  Test2();//递归
	Test3();//自己维护一个栈保存point
	Test4();//求多出口迷宫最短路径
	Test5();//求带环的多出口迷宫最短路径
	return 0;
}

#endif


