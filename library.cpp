#include <iostream>
#include<windows.h>
using namespace std;

struct book
{
	int number;
	string bookName;
	string author;
	int year;
	int month;
	string renter;
	book* next=NULL;
};
book* books[100];
book* book2=new book;
struct bookZhan
{
	book* book3[100];
	int top = 1;
};
bookZhan* bookL = new bookZhan;


void menu();
void borrow();
void returnBook();
void sort();
void shelf();
void bought();
void scrap();
void check();
void borrowed();
void select();

void menu()
{
	cout << "            (∧_∧)\n"<<"     请选择要进行的操作：\t\t\t\t\t\t@ 20201060342 王浩洋" << endl<<
	"\t\t\t   图书馆常用操作\n\n\t\t(∧_∧)σ     1.借书     σ(∧_∧；)\n\t\t(∧_∧)σ     2.还书     σ(∧_∧；)\n\n"
	<<"\t******===******===******===******===******===******   \n\t\t\t   Σ(￣□￣)\n\t     图书整理\t\t\t查看馆内收录图书\n\n   " 
	<< "3.对书架上的图书按编号排序\t\t7.查看在馆图书\n     "
	<< "4.将已归还书籍上架\n\t5.新购图书上架  \t\t8.查看借出图书\n\t 6.旧书废弃\n";
	select();
}

void select()
{
	int i = 0;
	cin >> i;
	switch (i)
	{
	case 1:
		borrow();
		break;
	case 2:
		returnBook();
		break;
	case 3:
		sort();
		break;
	case 4:
		shelf();
		break;
	case 5:
		bought();
		break;
	case 6:
		scrap();
		break;
	case 7:
		check();
		break;
	case 8:
		borrowed();
		break;
	default:
		cout << endl << "\n输入有误，请重新输入！\n";
		select();
		break;
	}
}

void check()
{
	cout << "\n当前在馆书籍如下：\n";
	for (int n = 0; n <= 99; n++)
	{
		if (books[n] != NULL)
		{
			cout << "\t序号:" << books[n]->number << "      书名:" << books[n]->bookName << "      作者:" << books[n]->author << "       出版日期:" <<
				books[n]->year << "年" << books[n]->month << "月" << endl;
		}
	}
	cout << "将返回菜单，";
	system("pause");
	menu();
}

void borrow()
{
	cout << "\n请输入借阅者姓名：\n";
	string peoname;
	cin >> peoname;
	int m = 0;
	cout << "\n请输入查找方式：1.按序号查找  2.按书名查找  3.返回菜单\n";
	cin >> m;
	if (m == 1)
	{
		int n = 0;
		cout << "\n请输入序号:";
		cin >> m;
		for ( n = 0; n < 100; n++)
		{
			if (books[n]->number == m)
			{
				cout << "\n您所将要接取的书籍信息如下，请进行确认：\n\t序号：" << books[n]->number<<endl<<"\t书名：" << books[n]->bookName
					<< endl << "\t作者：" <<books[n]->author<< endl << "\t出版日期:" <<books[n]->year<< "年" << books[n]->month<<"月"<< endl
					<<"\n1.确认 2.重新选书 3.返回菜单\n";
				cin >> m;
				
				switch (m)
				{
				case 1:
				{
					book* book22 = new book;
					book22 = book2;
					while (book22->next!=NULL)
						book22 = book22->next;
					books[n]->renter = peoname;
					book22->next = books[n];
					for (int v = n; v <= 99; n++)
					{
						if (books[v + 1] != NULL)
						{
							books[v] = books[v + 1];
							books[v + 1] = NULL;
							v++;
						}
						else
						{
							books[v] = NULL;
							break;
						}
					}
					cout << "\n借出成功！\n";
					break;
				}
				case 2:
					borrow();
					return;
				case 3:
					break;
				default:
					cout << "输入有误！";
					break;
				}
				break;
			}
			
		}
		if (n == 100)
		{
			cout << endl << "未找到该序号书籍，将返回菜单.！\n";
		}
	}
	else if (m == 2)
	{
		int n=0;
		cout << "\n请输入书名:";
		string b;
		cin >> b;
		for (n = 0; n < 100; n++)
		{
			if (books[n]->bookName == b)
			{
				cout << "\n您所将要借取的书籍信息如下，请进行确认：\n\t序号：" << books[n]->number << endl << "\t书名：" << books[n]->bookName
					<< endl << "\t作者：" << books[n]->author << endl << "\t出版日期:" << books[n]->year << "年" << books[n]->month << "月" << endl
					<< "\n1.确认 2.重新选书 3.返回菜单\n";
				cin >> m;
				switch (m)
				{
				case 1:
				{
					book* book22 = new book;
					book22 = book2;
					while (book22->next)
						book22 = book22->next;
					book22->next = books[n];
					for (int v = n; v <= 99; n++)
					{
						if (books[v + 1] != NULL)
						{
							books[v] = books[v + 1];
							books[v + 1] = NULL;
							v++;
						}
						else
						{
							books[v] = NULL;
							break;
						}
					}
					cout << "\n借出成功！\n";
					break;
				}
				case 2:
					borrow();
					return;
				case 3:
					break;
				default:
					cout << "输入有误！";
					break;
				}
				break;
			}
			
		}
		if (n == 100)
		{
			cout << endl << "未找到该书名书籍！\n";
		}
	}
	else if (m == 3)
	{
	}
	else
	{
		cout << "\n输入不合法，请重新输入！\n";
		borrow();
		return;
	}
	cout << "\n3秒后将返回菜单\n";
	Sleep(3*1000);
	menu();
}

void scrap()
{
	bool have = false;
	cout << "\n请输入要废弃的书籍的信息：1.序号 2.书名 3.返回菜单\n";
	int m = 0;
	cin >> m;
	if (m == 1)
	{
		int n = 0;
		cout << "\n请输入序号:";
		cin >> m;
		for (n = 0; n < 100; n++)
		{
			if (books[n]->number == m)
			{
				cout << "\n您所将要废弃的书籍信息如下，请进行确认：\n\t序号：" << books[n]->number << endl << "\t书名：" << books[n]->bookName
					<< endl << "\t作者：" << books[n]->author << endl << "\t出版日期:" << books[n]->year << "年" << books[n]->month << "月" << endl
					<< "\n1.确认 2.重新选书 3.返回菜单\n";
				cin >> m;

				switch (m)
				{
				case 1:
				{
					for (int v = n; v <= 99; n++)
					{
						if (books[v + 1] != NULL)
						{
							books[v] = books[v + 1];
							books[v + 1] = NULL;
							v++;
						}
						else
						{
							books[v] = NULL;
							break;
						}
					}
					cout << "\n废弃成功。\n";
					break;
				}
				case 2:
					borrow();
					return;
				case 3:
					break;
				default:
					cout << "输入有误！";
					break;
				}
				break;
			}

		}
		if (n == 100)
		{
			cout << endl << "未找到该序号书籍，将返回菜单.！\n";
		}
	}
	else if (m == 2)
	{
		int n = 0;
		cout << "\n请输入书名:";
		string b;
		cin >> b;
		for (n = 0; n < 100; n++)
		{
			if (books[n]->bookName == b)
			{
				cout << "\n您所将要废弃的书籍信息如下，请进行确认：\n\t序号：" << books[n]->number << endl << "\t书名：" << books[n]->bookName
					<< endl << "\t作者：" << books[n]->author << endl << "\t出版日期:" << books[n]->year << "年" << books[n]->month << "月" << endl
					<< "\n1.确认 2.重新选书 3.返回菜单\n";
				cin >> m;
				switch (m)
				{
				case 1:
				{
					for (int v = n; v <= 99; n++)
					{
						if (books[v + 1] != NULL)
						{
							books[v] = books[v + 1];
							books[v + 1] = NULL;
							v++;
						}
						else
						{
							books[v] = NULL;
							break;
						}
					}
					cout << "\n废弃成功。\n";
					break;
				}
				case 2:
					borrow();
					return;
				case 3:
					break;
				default:
					cout << "输入有误！";
					break;
				}
				break;
			}

		}
		if (n == 100)
		{
			cout << endl << "未找到该书名书籍！\n";
		}
	}
	else if (m == 3)
	{
	}
	else
	{
		cout << "\n输入不合法，请重新输入！\n";
		borrow();
		return;
	}
	cout << "\n3秒后将返回菜单\n";
	Sleep(3 * 1000);
	menu();
}

void sort()
{
	bool en = true;
	book* bo = new book;
	while (1)
	{
		int j = 0;
		for (j = 0; j < 100; )
		{
			if (books[j + 1] != NULL)
			{
				j++;
			}
			else
				break;
		}
		for (int i=0;i<j;i++)
		{
			if (books[i]->number > books[i + 1]->number)
			{
				bo = books[i];
				books[i] = books[i + 1];
				books[i + 1] = bo;
				en = false;
			}
		}
		if (en)
			break;
		en = true;
	}
	cout << "\n排序完毕，3秒后将返回菜单\n";
	Sleep(3 * 1000);
	menu();
}

void borrowed()
{
	cout << "\n\n如下为已借出的书籍信息：\n";
	book* book21 = book2;
	while(book21->next!=NULL)
	{
		cout << "\t序号:" << book21->next->number << "      书名:" << book21->next->bookName << "      作者:" << book21->next->author << "       出版日期:" <<
			book21->next->year << "年" << book21->next->month << "月      借阅者：" <<book21->next->renter<< endl;
		book21 = book21->next;
	}
	cout << "\n3秒后将返回菜单\n";
	Sleep(3 * 1000);
	menu();
}

void returnBook()
{
	bool have=false;
	cout << "\n查找将还书籍的信息：1.序号 2.书名 3.返回菜单\n";
	int m = 0;
	cin >> m;
	book* book22 = book2;
	if (m == 1)
	{
		cout << "\n请输入序号:\n";
		cin >> m;
		while (book22->next != NULL)
		{
			if (book22->next->number == m)
			{
				bookL->top++;
				bookL->book3[bookL->top] = book22->next;
				book22->next = book22->next->next;
				cout << "\n您所将要归还的书籍信息如下：\n\t序号：" << bookL->book3[bookL->top]->number << endl << "\t书名：" << bookL->book3[bookL->top]->bookName
					<< endl << "\t作者：" << bookL->book3[bookL->top]->author << endl << "\t出版日期:" << bookL->book3[bookL->top]->year << "年" << bookL->book3[bookL->top]->month << "月" << endl
					<<"\t借阅者:"<<bookL->book3[bookL->top]->renter<<endl<< "\n书籍已经归还！\n";
				have = true;
				break;
			}
		}
		if (!have)
		{
			cout << "\n未找到该序号所借书籍,请重新选择！\n";
			returnBook();
			return;
		}
	}
	else if (m == 2)
	{
		string bookNa;
		cout << "\n请输入书名:\n";
		cin >> bookNa;
		while (book22->next != NULL)
		{
			if (book22->next->bookName ==bookNa)
			{
				bookL->top++;
				bookL->book3[bookL->top] = book22->next;
				book22->next = book22->next->next;
				cout << "\n您所将要归还的书籍信息如下：\n\t序号：" << bookL->book3[bookL->top]->number << endl << "\t书名：" << bookL->book3[bookL->top]->bookName
					<< endl << "\t作者：" << bookL->book3[bookL->top]->author << endl << "\t出版日期:" << bookL->book3[bookL->top]->year << "年" << bookL->book3[bookL->top]->month << "月" << endl
					<< "\n\n书籍已经归还！\n";
				have = true;
				break;
			}
		}
		if (!have)
		{
			cout << "\n未找到该书名所借书籍,请重新选择！\n";
			returnBook();
			return;
		}
	}
	else if (m == 3)
	{
		menu();
		return;
	}
	else
	{
		cout << "\n输入有误，请重新选择!\n";
		returnBook();
		return;
	}

	cout << "\n3秒后将返回菜单\n";
	Sleep(3 * 1000);
	menu();
}

void shelf()
{
	int i = 0;
	while (books[i + 1])
	{
		i++;
	}
	while (1)
	{
		if (bookL->top != -1)
		{
			books[i + 1] = bookL->book3[bookL->top];
			i++;
			bookL->top--;
		}
		else
			break;
	}
	cout << "\n3秒后将返回菜单\n";
	Sleep(3 * 1000);
	menu();
}

void bought()
{
	cout << "\n请输入新购置的书籍名称：";
	string name1;
	string name2;
	int m ,n,h= 0;
	cin >> name1;
	cout << "\n请输入新购置的书籍作者：";
	cin >> name2;
	cout << "\n请输入新购置的书籍序号：";
	cin >> m;
	cout << "\n请输入新购置的书籍出版年份：";
	cin >> n;
	cout << "\n请输入新购置的书籍出版月份：";
	cin >> h;
	cout << "\n\n已在书架上添加新书!书籍信息为：\n\t序号：" << m << "\n\t书籍名称：" << name1<< "\n\t作者：" <<name2<< "\n\t出版日期：" << n << "年" << h << "月\n";
	int i = 0;
	while (books[i + 1])
	{
		i++;
	}
	books[i + 1] = new book;
	books[i + 1]->author = name2;
	books[i + 1]->bookName = name1;
	books[i + 1]->month = h;
	books[i + 1]->number = m;
	books[i + 1]->year = n;
	cout << "\n3秒后将返回菜单\n";
	Sleep(3 * 1000);
	menu();
}


int main(int argc, char* argv[])
{
	
	string booknam[50] = {"刀剑神域","加速世界","Fate stay night","Fate Zero","K","Angel Beat","Clannad","宝石之国","境界的彼方","灼眼的夏娜","月色真美","恶魔之谜","斩·赤红之瞳","只有我不在的街道","路人女主的养成方法","暗杀教室","血界战线","机巧少女不会受伤","Re：Creator","魔法少女伊莉雅","弹丸论破","约会大作战","我的青春恋爱物语果然有问题","樱花庄的宠物女孩","来自新世界","冰菓","中二病也要谈恋爱","罪恶王冠","未来日记","空之境界","绯弹的亚里亚","未闻花名","命运石之门","花开伊吕波","魔法少女小圆","无限斯特拉托斯","无头骑士异闻录","寄生兽","东京喰种","进击的巨人","86-不存在的战区","辉夜姬大小姐想让我告白","魔法禁书目录","某科学的超电磁炮","可塑性记忆","在下坂本，有何贵干","笨女孩","黑之契约者","反叛的鲁路修","寒蝉鸣泣之时"};
	string autho[50] = { "桐人", "川原砾", "切嗣", "士郎", "周防尊", "立华奏", "团子", "玛瑙", "未来", "夏娜", "月色", "蓝", "赤瞳", "我不在", "圣人惠", "黄老师", "saber", "切嗣", "士郎", "孔明", "阿尔托莉雅", "潘德拉", "吉尔伽美什", "杰尔", "安徒生", "库丘林", "加尔省", "莫德雷德", "齐格飞", "普伦希尔德", "两仪式", "特斯拉", "冲田总司", "斯卡哈", "大卫", "其", "森达", "美游", "小鸟游六花", "伊莉雅", "单", "五河", "比起谷八幡", "樱", "艾拉", "坂本", "本", "黑", "鲁路修", "川越" };
	int yea[50] = {2000,1956,2012,1911,1998,1920,2011,1989,2020,2011,1989,2001,2002,1989,2015,2020,2006,2016,1920,2003,2008,2015,2016,1989,2015,2018,2014,2014,2016,2014,2016,1989,2005,2014,1989,2014,2005,2020,2005,2014,2014,2014,2016,1989,1989,2005,1989,2005,2016,2005 };
	int mont[50] = { 1,2,5,5,8,1,8,8,2,3,1,3,3,3,12,2,7,1,5,8,1,7,1,5,8,1,6,1,2,1,3,9,4,1,5,4,1,9,6,1,6,1,5,9,2,6,6,7,12,2};
	for (int i = 0; i < 100; i++)
	{
		bookL->book3[i] = new book;
		bookL->book3[i] = NULL;
		books[i] = new book;
		if (i <= 49)
		{
			books[i]->number = i + 1;
			books[i]->bookName = booknam[i];
			books[i]->author = autho[i];
			books[i]->year = yea[i];
			books[i]->month = mont[i];
		}
		else
		{
			books[i] = NULL;
		}
	}
	for (int i = 0; i < 50; i++)
	{
		swap(books[i]->number,books[rand()%49]->number);
	}

	cout <<endl<<endl<< "\t\t\t欢迎进入图书馆管理系统！" << endl;
	
	menu();
	return 0;
}