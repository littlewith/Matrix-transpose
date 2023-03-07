#include<stdio.h>
#include<Windows.h>

#define MAXSIZE 1000
typedef int elemType;

//���嵥������Ԫ������
typedef struct {
	int row;//�������±�
	int col;//�������±�
	elemType elem;//��������ֵ
} Triple;

//�����������
typedef struct {
	Triple data[MAXSIZE + 1];//�����ڴ棬���ΪMAXSIZE
	int m;//����
	int n;//����
	int len;//����Ԫ�ظ���
} TSmatrix;


int init(Triple* s) {
	s->row = s->col = 0;
}

int create(TSmatrix* b) {
	int i;
	//��ִ�����������ɾ��ԭ�������д洢��ֵ
	for (i = 0; i < MAXSIZE; i++) {
		b->data[i].elem = 0;
	}
	printf("���������������Լ�����Ԫ�ظ���:  ");
	scanf("%d%d%d", &b->m, &b->n, &b->len);
	for (i = 1; i <= b->len; i++) {
		printf("����������Ԫ�ص��С��С�ֵ:  ");
		scanf("%d%d%d", &b->data[i].row, &b->data[i].col, &b->data[i].elem);
	}
	system("cls");
	printf("\t\t\n\t\t����¼��ɹ����󣡣�");
	getchar();
	getchar();
}

//C������ͨת���㷨ʵ��
void TransposetMatrix(TSmatrix a, TSmatrix* b)
{
	int i, j, k;
	//��ִ�����������ɾ��ԭ�������д洢��ֵ
	for (i = 0; i < MAXSIZE; i++) {
		b->data[i].elem = 0;
	}
	b->m = a.n;
	b->n = a.m;
	b->len = a.len;
	if (b->len <= 0) 
		printf("�����ǿյ�!\n");
	else 
		if (b->len > MAXSIZE) 
			printf("������󣬳������洢�ռ䣡\n");
		else
		{
			j = 1;
			for (k = 1; k <= a.n; k++) 
				for (i = 1; i <= a.len; i++)
					if (a.data[i].col == k) 
					{ 
						b->data[j].row = a.data[i].col;//�����к���
						b->data[j].col = a.data[i].row;//�����к���
						b->data[j].elem = a.data[i].elem;//ֵ���䣬ֱ�Ӹ�ֵ����
						j++;
					}
		}
}

//C���Կ���ת���㷨ʵ��
void fastTrans(TSmatrix a, TSmatrix* b)
{
	int i;
	//��ִ�����������ɾ��ԭ�������д洢��ֵ
	for (i = 0; i < MAXSIZE; i++) {
		b->data[i].elem = 0;
	}
	int col, t, p, q;
	int num[MAXSIZE], position[MAXSIZE];
	b->len = a.len; 
	b->n = a.m;
	b->m = a.n;
	if (b->len <= 0)
		printf("�����ǿյģ�");

	else if (b->len > MAXSIZE) 
			printf("������󣬳������洢����");
		
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
				b->data[q].row = a.data[p].col;//������ʳ�ͻ
				b->data[q].col = a.data[p].row;
				b->data[q].elem = a.data[p].elem;
				position[col]++;
			}
		}
}

void display(TSmatrix* b)
{
	printf("������......�������ǰ�������İ£���");
	putchar('\n');
	int i, j, k;
	for (i = 1; i <= b->m; i++) {
		for (j = 1; j <= b->n; j++)
		{
			for (k = 1; k <= b->len; k++)
			{
				if (b->data[k].row == i && b->data[k].col == j) {//��ƥ�䣬��Ҳƥ���ʱ��
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
	printf("\n\t�����������!");
	getchar();
	getchar();
}

int chooseMethods() {
	while (1) {
		printf("\t\t��ѡ����Ҫ�Ծ���ת�õķ�ʽ:\n");
		printf("\t\t\t1.ʹ����ͨת�õķ�ʽ�Ծ������ת��\n");
		printf("\t\t\t2.ʹ�ÿ���ת�õķ�ʽ�Ծ������ת��\n");
		printf("\t\t\t3.������һ��\n");
		printf("\t\t\t4.�����˳�����\n");
		printf("\t���������ѡ��: ");
		char choose;
		scanf("%c", &choose);
		switch (choose)
		{
		case '1':return 1; break;
		case '2':return 2; break;
		case '3':return 3; break;
		case '4':return 4; break;//�˳���Ϣ
		default:
		{
			system("cls");
			printf("\t\t\t������........��úÿ���ѡ��£�\n");
			printf("\t\t\t�����...........\n");
			printf("\t\t\t������һ���\n");
		}
		getchar();
		getchar();
		system("cls");
		continue;
		}
	}
}

int menu() {//�û����氡
	while (1) {
		printf("========================================================================================================\n");
		printf("\t\t\t\t��ӭʹ�þ���ת��С����!\t\t\t\n");
		putchar('\n');
		printf("\t\t\t1.�������\t\t2.ִ��ת�ò���\n");
		putchar('\n');
		printf("\t\t\t3.��ӡ��ǰ����\t\t4.�˳�����\n");
		printf("========================================================================================================\n");
		printf("\t\t��ѡ����Ĳ���:\t");
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
			printf("\t\t\t������........��úÿ���ѡ��£�\n");
			printf("\t\t\t�����...........\n");
			printf("\t\t\t������һ���\n");
		}
		getchar();
		getchar();
		system("cls");
		continue;
		}
	}
	
}

int main() {//������
	Triple s;//��ʼ������
	TSmatrix a, b, c;//��ʼ������
	init(&s);
	int isCreate = 0;
	char nowMatrix = 'a';//��ʼ¼��ľ��󱣴���a�У���ʱ�������е����ö����Ϊa
	//��ǰ�����ľ���.
	while (1) {
		system("cls");
		//��������

		int choose = menu();
		//����������������Ҫ�Ĳ˵������û��������棬�������ݵķ���ֵ����choose��choose������ѡ�����Ϣ��

		if (choose == 1) {//��ѡ���choose�����жϣ����choose Ϊ1����ô���������
			system("cls");

			create(&a);//���ô����ĺ���
			isCreate = 1;//�Ƿ񴴽��ı�ʶ��Ϊ1����ʾ�Ѿ�����
			nowMatrix = 'a';
		}

		else if (choose == 2) {//���ѡ�����2�����ж��Ƿ�����˴���
			system("cls");

			//�жϵ�ǰ�ľ����Ƿ��Ѿ���ʼ����
			if (isCreate == 0) {
				putchar('\n');
				printf("\t\tNoNoNo����������û�г�ʼ��������ִ��1����ʼ������Ŷ��");
				getchar();//ͣһ��
				getchar();
			}
			else
				while (1) {//���������һ��ѭ���˵�
					getchar();
					system("cls");
					int choose = chooseMethods();

					if (choose == 1) {//����ת��
						TransposetMatrix(a, &b);
						system("cls");
						printf("\t\t����ת�óɹ���!");
						getchar();//���������س�
						//system("cls");
						nowMatrix = 'b';
						a = b;
					}

					else if (choose == 2) {//��ͨת��
						fastTrans(a, &c);
						system("cls");
						printf("\t\t����ת�óɹ���!");
						getchar();//���������س�
						//system("cls");
						nowMatrix = 'c';
						a = c;
					}
					else if (choose == 3) {//������һ��
						getchar();
						break;
					}
					else if (choose == 4) {
						system("cls");
						printf("\t\t���򼴽��˳�..........");
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
				printf("NoNoNo����������û�г�ʼ��������ִ��1����ʼ������Ŷ��");
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
			printf("\t\t���򼴽��˳�..........");
			putchar('\n');
			Sleep(500);
			exit(0);
		}
	}
	return 0;
}