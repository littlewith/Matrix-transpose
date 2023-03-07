#include<stdio.h>
#include<Windows.h>

#define MAXSIZE 1000
typedef int elemType;

//定义单个非零元素类型
typedef struct {
	int row;//定义行下标
	int col;//定义列下标
	elemType elem;//定义具体的值
} Triple;

//定义矩阵数组
typedef struct {
	Triple data[MAXSIZE + 1];//分配内存，最大为MAXSIZE
	int m;//行数
	int n;//列数
	int len;//非零元素个数
} TSmatrix;


int init(Triple* s) {
	s->row = s->col = 0;
}

int create(TSmatrix* b) {
	int i;
	//先执行清零操作，删除原来矩阵中存储的值
	for (i = 0; i < MAXSIZE; i++) {
		b->data[i].elem = 0;
	}
	printf("请输入行数列数以及非零元素个数:  ");
	scanf("%d%d%d", &b->m, &b->n, &b->len);
	for (i = 1; i <= b->len; i++) {
		printf("请依次输入元素的行、列、值:  ");
		scanf("%d%d%d", &b->data[i].row, &b->data[i].col, &b->data[i].elem);
	}
	system("cls");
	printf("\t\t\n\t\t矩阵录入成功了捏！！");
	getchar();
	getchar();
}

//C语言普通转置算法实现
void TransposetMatrix(TSmatrix a, TSmatrix* b)
{
	int i, j, k;
	//先执行清零操作，删除原来矩阵中存储的值
	for (i = 0; i < MAXSIZE; i++) {
		b->data[i].elem = 0;
	}
	b->m = a.n;
	b->n = a.m;
	b->len = a.len;
	if (b->len <= 0) 
		printf("矩阵是空的!\n");
	else 
		if (b->len > MAXSIZE) 
			printf("矩阵错误，超出最大存储空间！\n");
		else
		{
			j = 1;
			for (k = 1; k <= a.n; k++) 
				for (i = 1; i <= a.len; i++)
					if (a.data[i].col == k) 
					{ 
						b->data[j].row = a.data[i].col;//交换行和列
						b->data[j].col = a.data[i].row;//交换行和列
						b->data[j].elem = a.data[i].elem;//值不变，直接赋值就行
						j++;
					}
		}
}

//C语言快速转置算法实现
void fastTrans(TSmatrix a, TSmatrix* b)
{
	int i;
	//先执行清零操作，删除原来矩阵中存储的值
	for (i = 0; i < MAXSIZE; i++) {
		b->data[i].elem = 0;
	}
	int col, t, p, q;
	int num[MAXSIZE], position[MAXSIZE];
	b->len = a.len; 
	b->n = a.m;
	b->m = a.n;
	if (b->len <= 0)
		printf("矩阵是空的！");

	else if (b->len > MAXSIZE) 
			printf("数组错误，超过最大存储容量");
		
		else {
			for (col = 1; col <= a.n; col++) 
				num[col] = 0;

			for (t = 1; t <= a.len; t++) 
				num[a.data[t].col]++;
			position[1] = 1;

			for (col = 2; col < a.n; col++) 
				position[col] = position[col - 1] + num[col - 1];
			for (p = 1; p <= a.len; p++)
			{
				col = a.data[p].col;
				q = position[col];
				b->data[q].row = a.data[p].col;//这里访问冲突
				b->data[q].col = a.data[p].row;
				b->data[q].elem = a.data[p].elem;
				position[col]++;
			}
		}
}

void display(TSmatrix* b)
{
	printf("嘀嘀嘀......这个矩阵当前是这样的奥！！");
	putchar('\n');
	int i, j, k;
	for (i = 1; i <= b->m; i++) {
		for (j = 1; j <= b->n; j++)
		{
			for (k = 1; k <= b->len; k++)
			{
				if (b->data[k].row == i && b->data[k].col == j) {//行匹配，列也匹配的时候
					printf("%5d", b->data[k].elem);
					break;
				}
			}
			if (k > b->len)
				printf("%5d", 0);
			if (j == b->n)
			{
				putchar('\n');
				putchar('\n');
			}
		}
	}
	printf("\n\t按任意键返回!");
	getchar();
	getchar();
}

int chooseMethods() {
	while (1) {
		printf("\t\t请选择你要对矩阵转置的方式:\n");
		printf("\t\t\t1.使用普通转置的方式对矩阵进行转置\n");
		printf("\t\t\t2.使用快速转置的方式对矩阵进行转置\n");
		printf("\t\t\t3.返回上一级\n");
		printf("\t\t\t4.现在退出程序\n");
		printf("\t请输入你的选择: ");
		char choose;
		scanf("%c", &choose);
		switch (choose)
		{
		case '1':return 1; break;
		case '2':return 2; break;
		case '3':return 3; break;
		case '4':return 4; break;//退出信息
		default:
		{
			system("cls");
			printf("\t\t\t你你你........你好好看看选项奥！\n");
			printf("\t\t\t输错了...........\n");
			printf("\t\t\t重新输一遍吧\n");
		}
		getchar();
		getchar();
		system("cls");
		continue;
		}
	}
}

int menu() {//用户界面啊
	while (1) {
		printf("========================================================================================================\n");
		printf("\t\t\t\t欢迎使用矩阵转置小工具!\t\t\t\n");
		putchar('\n');
		printf("\t\t\t1.输入矩阵\t\t2.执行转置操作\n");
		putchar('\n');
		printf("\t\t\t3.打印当前矩阵\t\t4.退出程序\n");
		printf("========================================================================================================\n");
		printf("\t\t请选择你的操作:\t");
		char choose;
		scanf("%c", &choose);
		switch (choose)
		{
		case '1':return 1; break;
		case '2':return 2; break;
		case '3':return 3; break;
		case '4':return 4; break;
		default:
		{
			system("cls");
			printf("\t\t\t你你你........你好好看看选项奥！\n");
			printf("\t\t\t输错了...........\n");
			printf("\t\t\t重新输一遍吧\n");
		}
		getchar();
		getchar();
		system("cls");
		continue;
		}
	}
	
}

int main() {//主函数
	Triple s;//初始化矩阵
	TSmatrix a, b, c;//初始化矩阵
	init(&s);
	int isCreate = 0;
	char nowMatrix = 'a';//初始录入的矩阵保存在a中，此时函数所有的作用对象均为a
	//当前操作的矩阵.
	while (1) {
		system("cls");
		//程序清屏

		int choose = menu();
		//触发函数，进入主要的菜单，即用户的主界面，接受数据的返回值交给choose，choose包含了选择的信息。

		if (choose == 1) {//对选择的choose进行判断，如果choose 为1，那么就输入矩阵
			system("cls");

			create(&a);//调用创建的函数
			isCreate = 1;//是否创建的标识变为1，表示已经创建
			nowMatrix = 'a';
		}

		else if (choose == 2) {//如果选择的是2，先判断是否进行了创建
			system("cls");

			//判断当前的矩阵是否已经初始化。
			if (isCreate == 0) {
				putchar('\n');
				printf("\t\tNoNoNo！！！矩阵还没有初始化捏！请先执行1来初始化矩阵哦！");
				getchar();//停一下
				getchar();
			}
			else
				while (1) {//否则进入下一个循环菜单
					getchar();
					system("cls");
					int choose = chooseMethods();

					if (choose == 1) {//快速转置
						TransposetMatrix(a, &b);
						system("cls");
						printf("\t\t矩阵转置成功了!");
						getchar();//过滤两个回车
						//system("cls");
						nowMatrix = 'b';
						a = b;
					}

					else if (choose == 2) {//普通转置
						fastTrans(a, &c);
						system("cls");
						printf("\t\t矩阵转置成功了!");
						getchar();//过滤两个回车
						//system("cls");
						nowMatrix = 'c';
						a = c;
					}
					else if (choose == 3) {//返回上一级
						getchar();
						break;
					}
					else if (choose == 4) {
						system("cls");
						printf("\t\t程序即将退出..........");
						putchar('\n');
						Sleep(500);
						exit(0);
					}
				}

		}
		else if (choose == 3) {
			system("cls");
			if (isCreate == 0) {
				putchar('\n');
				printf("NoNoNo！！！矩阵还没有初始化捏！请先执行1来初始化矩阵哦！");
				getchar();
				getchar();
			}
			else {
				system("cls");
				if (nowMatrix == 'a') {
					display(&a);
				}
				else if (nowMatrix == 'b') {
					display(&b);
				}
				else if (nowMatrix == 'c') {
					display(&c);
				}
			}
		}

		else if (choose == 4) {
			system("cls");
			printf("\t\t程序即将退出..........");
			putchar('\n');
			Sleep(500);
			exit(0);
		}
	}
	return 0;
}