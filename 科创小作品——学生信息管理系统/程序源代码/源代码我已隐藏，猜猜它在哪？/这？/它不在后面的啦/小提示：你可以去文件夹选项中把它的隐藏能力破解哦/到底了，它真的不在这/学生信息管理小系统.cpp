//导入播放音乐所需文件
#include<easyx.h>
#include<MMSystem.h>
#pragma comment(lib,"winmm.lib")

#include<string.h>
#include "time.h"
#include "stdlib.h"
#include "conio.h"
#include "windows.h"//导入Sleep() 
#include "stdio.h"
#include<iostream>
using namespace std;

typedef struct Student STU;
#define ll long long

void Hello(int i);
void music(int i);

int DJS=3;
int zJieMian,data_operat,primary_fail,insert_data,delete_data,find_data,print_data,dm_program,dm_way,dm_exit,program_exit,dTao_dm,primary_data,NULL_data,team;
int Exit=1;

struct Student
{
	char num[10];//学号
	char name[10];//姓名
	char sex[10];//性别
	char tel[20];//电话号码
	char fla[10];//是否去做过核酸 
	char hesuan[10];//核酸 结果 阴阳

	int sign;//点名  1：表示已点名  0：表示没有点名
	struct Student *next; //链表指针
};

//音乐函数
void music(int i,int j,int k)
{
	//导入音乐  mci(media device interface)多媒体设备接口
	//第一个参数为字符串，指给多媒体设备的指令,后面的三个参数不用管，赋NULL 0 NULL即可

	switch(i)//播放
	{
		case 1:
				mciSendString(_T("open ./music/piao.mp3 repeat"),NULL,0,NULL);
				mciSendString(_T("play ./music/piano.mp3 repeat"),NULL,0,NULL);
				break;

		case 2: //此处不知何原因，如果在刚开始的情况下打开会出错
				mciSendString(_T("open  ./music/wake.mp3 repeat"),NULL,0,NULL);
				mciSendString(_T("play  ./music/wake.mp3 repeat"),NULL,0,NULL);
				break;
		case 3: 
				mciSendString(_T("open ./music/delete.mp3"),NULL,0,NULL);
				mciSendString(_T("play ./music/delete.mp3"),NULL,0,NULL);
				break;
		case 4: 
				mciSendString(_T("open ./music/end.mp3"),NULL,0,NULL);
				mciSendString(_T("play ./music/end.mp3"),NULL,0,NULL);
				break;
		case 5: 
				mciSendString(_T("open ./music/Sleep.mp3"),NULL,0,NULL);
				mciSendString(_T("play ./music/Sleep.mp3"),NULL,0,NULL);
				break;
		case 6: 
				mciSendString(_T("open ./music/not_data.mp3"),NULL,0,NULL);
				mciSendString(_T("play ./music/not_data.mp3"),NULL,0,NULL);
				break;
		case 7: 
				mciSendString(_T("open ./music/team.mp3"),NULL,0,NULL);
				mciSendString(_T("play ./music/team.mp3"),NULL,0,NULL);
				break;
		case 8: 
				mciSendString(_T("open ./music/start.mp3"),NULL,0,NULL);
				mciSendString(_T("play ./music/start.mp3"),NULL,0,NULL	);
				break;
		case 9: 
				mciSendString(_T("open ./music/say.mp3"),NULL,0,NULL);
				mciSendString(_T("play ./music/say.mp3"),NULL,0,NULL);
				break;
		case 10: 
				mciSendString(_T("open ./music/dinner.mp3"),NULL,0,NULL);
				mciSendString(_T("play ./music/dinner.mp3"),NULL,0,NULL);
				break;
		case 11: 
				mciSendString(_T("open ./music/primary_d.mp3"),NULL,0,NULL);
				mciSendString(_T("play ./music/primary_d.mp3"),NULL,0,NULL);
				break;
		case 12: 
				mciSendString(_T("open ./music/find_d.mp3"),NULL,0,NULL);
				mciSendString(_T("play ./music/find_d.mp3"),NULL,0,NULL);
				break;
		case 13: 
				mciSendString(_T("open ./music/print_d.mp3"),NULL,0,NULL);
				mciSendString(_T("play ./music/print_d.mp3"),NULL,0,NULL);
				break;
	}

	switch(j) //暂停
	{
		case 1:
				mciSendString(_T("pause ./music/piano.mp3"),NULL,0,NULL);
				return ;
		case 2:
				mciSendString(_T("pause ./music/wake.mp3"),NULL,0,NULL);
				return ;
	}

	switch(k) //继续
	{

		case 1:
				mciSendString(_T("resume ./music/piano.mp3"),NULL,0,NULL);
				return ;
		case 2:
				mciSendString(_T("resume ./music/wake.mp3"),NULL,0,NULL);
				return ;
		case 7: 
				mciSendString(_T("open ./music/team.mp3"),NULL,0,NULL);
				mciSendString(_T("play ./music/team.mp3"),NULL,0,NULL);
				break;
	}
}

//打招呼函数
void Hello(int i)
{
	#define start1 "你 好 呀 ！"
	#define start11 "我 是 你 们 本 次 的 辅 导 员【小舞姐】"
	#define start111 "很 高 兴 能 在 这 见 到 你 ！❤"

	#define start2 "在 这 里 ，你 可 以 根 据 对 应 提 示 来 操 作"
	#define start22 "记 得 输 入 对 应 数 字 后 按 回 车 哦！"

	#define start3 "嘻 嘻，主 人 现 在 还 只 是 个 CURD 程 序 员 呢"
	#define start33 "就 只 会 增 删 查 改 这 种 简 单 的 小 操 作 啦"

	#define start4 "由 于 先 前 那 个 Student 文 档 中 有 内 容 了"
	#define start44 "就 不 用 初 始 化 了，只 需 插 入 数 据 即 足 矣"

	#define start5 "在 这 里 你 可 以 多 次 添 加 数 据"
	#define start55 "记 得 每 条 数 据 之 间一 定 要 用 空 格 隔 开 哦"

	#define start6 " 在 这 里 你 可 以 多 次 删 除 数 据"
	#define start66 "甚 至 可 以 全  删 耶 ， 不 过 要 小 心 哦 "

	#define start7 " 在 这 里 你 可 以 多 次 查 找 数 据"
	#define start77 "注 意 查 找 后 还 可 以 根 据 提 示 进 行 修 改 哦"

	#define start8 "在 这 里 你 可 以 查 看 所 有 的 成 员 信 息 哦"
	#define start88 "绿 色 字 体 真 是 带 有 代 码 感 呢"

	#define start9 "欢 迎 来 到 点 名 小 系 统 "
	#define start99 "呀 ，我 好 像 点 到 你 了 "

	#define start10 "这 里 面 有 动 态 和 静 态 点 名"
	#define start1010 " 你 想 选 哪 个 呢？ "

	#define start_11 "就 点 完 了 吗 ?  时 间 过 的 真 快 呀 ……"
	#define start_1111 " 再 见 了 路 人 ， 有 缘 再 见 。 "

	#define start_12 " 再 见 了 同 学 ， 相 逢 即 是 有 缘 "
	#define start_1212 " 小 舞 姐 祝 你 天 天 开 心 ， 学 习 进 步 哦 ！"
	#define start_121212 " See      you "

	#define start_13 " 要 注 意 已 点 名 的 人 数 哦 "
	#define start_1313 "已 经 点 了 的 同 学 系 统 不 会 再 点 呢 ！"

	#define start_14 "记 得 向 前 滚 动 滑 轮 哦 "
	#define start_1414 "你 先 去 阅 读 吧 ，See  you"

	#define start_15 "Hello ,欢 迎 来 到 数 据 初 始 化 界 面"
	#define start_1515 " 记 得 每 输 完 一 个 数 按 回 车 哟 ！"
	
	#define start_16 "看 到 后 面 这 些 信 息 不 要 慌 哦，有 我 在 呢"
	#define start_1616 "这 是 由 于刚 开 始 源 文 件 旁 没 有 Student "
	#define start_161616 "或 是 该 文 件 无 数 据 导 致 的 呢"
	#define start_16161616 "添 加 数 据 后 即 可 恢 复"

	IMAGE img;

	//创建画布
	initgraph(768,512,1);//宽 高

	//设置背景模式为透明
	setbkmode(TRANSPARENT);//transparent，此模式保持文字背景色不变

	//设置文字大小和字体 宽 高 字体
	settextstyle(40,0,_T("华文行楷"));

	//设置文字颜色
	settextcolor(RGB(0,255,246));

	switch(i)
	{
		case 1:
				//加载图片
				//图片数组地址 图片地址 图片宽度 图片高度
				loadimage(&img,_T("img/start.jpg"),getwidth(),getheight());

				//输出图片
				putimage(0,0,&img);

				//输出文本内容
				outtextxy((getwidth()-textwidth(_T(start1)))/2,0,_T(start1));
				outtextxy((getwidth()-textwidth(_T(start11)))/2,60,_T(start11));
				outtextxy((getwidth()-textwidth(_T(start111)))/2,120,_T(start111));

				Sleep(6000);

				break;
		case 2:
				loadimage(&img,_T("img/start1.jpg"),getwidth(),getheight());

				putimage(0,0,&img);

				outtextxy((getwidth()-textwidth(_T(start2)))/2,30,_T(start2));
				outtextxy((getwidth()-textwidth(_T(start22)))/2,90,_T(start22));

				Sleep(6000);

				break;
		case 3:
				loadimage(&img,_T("img/start2.jpg"),getwidth(),getheight());

				putimage(0,0,&img);

				outtextxy((getwidth()-textwidth(_T(start3)))/2,30,_T(start3));
				outtextxy((getwidth()-textwidth(_T(start33)))/2,90,_T(start33));

				Sleep(6000);

				break;
		case 4:
				loadimage(&img,_T("img/enough.jpg"),getwidth(),getheight());

				putimage(0,0,&img);

				outtextxy((getwidth()-textwidth(_T(start4)))/2,30,_T(start4));
				outtextxy((getwidth()-textwidth(_T(start44)))/2,90,_T(start44));

				Sleep(6000);

				break;
		case 5:
				loadimage(&img,_T("img/insert.jpg"),getwidth(),getheight());

				putimage(0,0,&img);

				outtextxy((getwidth()-textwidth(_T(start5)))/2,30,_T(start5));
				outtextxy((getwidth()-textwidth(_T(start55)))/2,90,_T(start55));

				Sleep(6000);

				break;
		case 6:
				loadimage(&img,_T("img/delete.jpg"),getwidth(),getheight());

				putimage(0,0,&img);

				outtextxy((getwidth()-textwidth(_T(start6)))/2,30,_T(start6));
				outtextxy((getwidth()-textwidth(_T(start66)))/2,90,_T(start66));

				Sleep(6000);

				break;
		case 7:
				settextcolor(RED);

				loadimage(&img,_T("img/find.jpg"),getwidth(),getheight());

				putimage(0,0,&img);

				outtextxy((getwidth()-textwidth(_T(start7)))/2,30,_T(start7));
				outtextxy((getwidth()-textwidth(_T(start77)))/2,90,_T(start77));

				Sleep(6000);

				break;
		case 8:
				settextcolor(RGB(22,198,12));

				loadimage(&img,_T("img/print.jpg"),getwidth(),getheight());

				putimage(0,0,&img);

				outtextxy((getwidth()-textwidth(_T(start8)))/2,30,_T(start8));
				outtextxy((getwidth()-textwidth(_T(start88)))/2,90,_T(start88));

				Sleep(6000);

				break;
		case 9:
				loadimage(&img,_T("img/name.jpg"),getwidth(),getheight());

				putimage(0,0,&img);

				outtextxy((getwidth()-textwidth(_T(start9)))/2,30,_T(start9));
				outtextxy((getwidth()-textwidth(_T(start99)))/2,90,_T(start99));

				Sleep(5000);

				break;
		case 10:
				loadimage(&img,_T("img/dm.jpg"),getwidth(),getheight());

				putimage(0,0,&img);

				outtextxy((getwidth()-textwidth(_T(start10)))/2,30,_T(start10));
				outtextxy((getwidth()-textwidth(_T(start1010)))/2,90,_T(start1010));

				Sleep(4000);

				break;
		case 11:
				loadimage(&img,_T("img/dmend.jpg"),getwidth(),getheight());

				putimage(0,0,&img);

				outtextxy((getwidth()-textwidth(_T(start_11)))/2,30,_T(start_11));
				outtextxy((getwidth()-textwidth(_T(start_1111)))/2,90,_T(start_1111));

				Sleep(5000);

				break;
		case 12:
				loadimage(&img,_T("img/finally.jpg"),getwidth(),getheight());

				putimage(0,0,&img);

				outtextxy((getwidth()-textwidth(_T(start_12)))/2,30,_T(start_12));
				outtextxy((getwidth()-textwidth(_T(start_1212)))/2,90,_T(start_1212));
				outtextxy((getwidth()-textwidth(_T(start_121212)))/2,150,_T(start_121212));

				Sleep(7000);

				break;
		case 13:
				settextcolor(RED);
				loadimage(&img,_T("img/dmts.jpg"),getwidth(),getheight());

				putimage(0,0,&img);

				outtextxy((getwidth()-textwidth(_T(start_13)))/2,30,_T(start_13));
				outtextxy((getwidth()-textwidth(_T(start_1313)))/2,90,_T(start_1313));

				Sleep(6000);

				break;
		case 14:
				settextcolor(RED);


				loadimage(&img,_T("img/dmts.jpg"),getwidth(),getheight());

				putimage(0,0,&img);

				outtextxy((getwidth()-textwidth(_T(start_14)))/2,30,_T(start_14));
				outtextxy((getwidth()-textwidth(_T(start_1414)))/2,90,_T(start_1414));

				Sleep(4000);
				break;

		case 15:
				settextcolor(RED);

				loadimage(&img,_T("img/primary.jpg"),getwidth(),getheight());

				putimage(0,0,&img);

				outtextxy((getwidth()-textwidth(_T(start_15)))/2,30,_T(start_15));
				outtextxy((getwidth()-textwidth(_T(start_1515)))/2,90,_T(start_1515));

				Sleep(5000);
				break;

		case 16:

				settextcolor(RED);

				loadimage(&img,_T("img/error.jpg"),getwidth(),getheight());

				putimage(0,0,&img);

				outtextxy((getwidth()-textwidth(_T(start_16)))/2,30,_T(start_16));
				outtextxy((getwidth()-textwidth(_T(start_1616)))/2,90,_T(start_1616));
				outtextxy((getwidth()-textwidth(_T(start_161616)))/2,150,_T(start_161616));
				outtextxy((getwidth()-textwidth(_T(start_16161616)))/2,210,_T(start_16161616));

				Sleep(7000);
				break;
	}
	
	closegraph();

}

//团队信息函数
void Team()
{
	system("cls");
	system("color 0a");

	music(7,0,0);

	if(!team)
	{
		Hello(14);
		team=1;
	}

	cout<<"————【团队信息】————\n\n";

	cout<<"团队成员：向吴  王嘉豪  刘广发 罗永庆\n\n";

	cout<<"————【分工详情】————\n\n";
	cout<<"\t    向吴\n\n链表输出函数（不够美观，未采用） \n\n插入函数（已采用，但有BUG）\n\n ";
	cout<<"\t    王嘉豪\n\n查找函数（已采用，但有BUG） 删除函数（已采用，但有BUG）\n\n ";
	cout<<"\t    刘广发\n\n添加函数（功能不全，没有排序判断，不够美观，未采用）\n\n ";
	cout<<"\t    罗永庆\n\n所有函数的BUG修复，实现源代码中除上述【已采用】函数外的其它所有函数\n\n";
	cout<<"界面的美化工作（例如程序显示的文字排版与控制台的文字及背景颜色）\n\n背景音乐与图片的导入及输出\n\n";

	cout<<"————【系统功能】————\n\n";
	cout<<"【1】实现数据的多次增删查改操作\n\n";
	cout<<"【2】数据可以保存及写入\n\n";
	cout<<"【3】点名功能\n\n";
	cout<<"【4】为防止数据意外丢失，系统已在程序启动时自动创建副本文件。\n\n";
	cout<<"温馨小提示：记得要在主界面退出系统后才能在副本文件中保存修改后的信息哦！\n\n";

	cout<<"————【系统服务】————\n\n";
	cout<<"如在使用中遇到任何问题，可联系作者 【Lyq】\n\nQQ : 1074716398\n\nWechat : ccwss66lyq\n\n";

	cout<<"————【时间信息】————\n\n";
	cout<<"系统制作开始时间 ：{ 科创竞赛结束的前1天 }\n\n（即2022年12月2日，本来是12月4日上交，但疫情原因给提前了）\n\n";
	cout<<"系统制作结束时间 ：{ 2022年12月11日早 }\n\n\n";

	cout<<"【温馨小提示】 滑动鼠标滚轮可查看前面的信息!\n\n";

	system("pause");
}

//计数函数 计算未被点到的成员数量
int noNameNum(STU *h)
{
	int num=0;
	while(h)
	{
		if(!h->sign) num++;
		h=h->next;
	}
	return num;
}

//链表释放函数
void Free(STU *h)
{
	STU *p=h;
	while(h)
	{
		p=h;
		h=h->next;
		delete p;
	}														//system("pause");
}

//观察链表成员属性函数 即每个成员的点名情况
void see(STU *h)
{
	system("cls");

	cout<<"————【成员信息观察界面】————\n\n";
	system("color 0a");
	cout<<"小提示：0表示未点名，1表示为已点名\n\n";
	while(h)
	{
		cout<<"【"<<h->name<<"】——— sign: "<<h->sign<<endl<<endl;
		h=h->next;
	}
	system("pause");
}

//点名结束标志函数(全部已点完)
int d_Name_Over(STU *h)//如果全部点完则返回1，否则返回0
{
	STU *p=h;
	while(p)
	{
		if(!(p->sign))  return 0;
		p=p->next;
	}
	return 1;
}

//为sign赋0函数
void setZero(STU *h)
{
	while(h)
	{
		h->sign=0;
		h=h->next;
	}
}

//链表长度函数
long long lb_Size(STU *h)
{
	long long num=0;
	while(h)
	{
		num++;
		h=h->next;
	}
	return num;
}

//成员初始化函数,输入#结束
STU *primary()
{
	STU *h=NULL,*p,*q;
	p=q=h=new STU;
	system("cls");
	system("color 04");

	music(11,0,0);

	if(!primary_data)
	{
		Hello(15);
		primary_data=1;
	}

	cout<<"  ————[初始化界面]————\n\n";
	cout<<"请输入学号(在学号开头处输入 # 可退出本界面)：\n";

	p->sign=0;

	cin>>p->num;
	if(p->num[0]=='#') return NULL;

	cout<<"请输入姓名：\n";
	cin>>p->name;
	cout<<"请输入性别：\n";
	cin>>p->sex;
	cout<<"请输入电话号码：\n";
	cin>>p->tel;
	cout<<"是否做过核酸(1或0)：\n";
	cin>>p->fla;
	cout<<"请输入核酸检测结果（阴或阳）：\n";
	cin>>p->hesuan;

	while(p->num[0]!='#')//以学号开头为0结束
	{
		p=new STU;
		q->next=p;
		p->sign=0;

		system("cls");
		cout<<"  ————[初始化界面]————\n\n";
		cout<<"请输入学号：(在学号开头处输入 # 可退出本界面)\n";
		cin>>p->num;
		if(p->num[0]=='#') break;

		cout<<"请输入姓名：\n";
		cin>>p->name;

		cout<<"请输入性别：\n";
		cin>>p->sex;

		cout<<"请输入电话号码：\n";
		cin>>p->tel;

		cout<<"是否做过核酸(1或0)：\n";
		cin>>p->fla;

		cout<<"请输入核酸检测结果（阴或阳）：\n";
		cin>>p->hesuan;

		q=p;
	}

	q->next=NULL;
	
	system("cls");
	cout<<"————【数据初始化成功】————\n\n";
	system("pause");

	return  h;
}

//链表输出函数  输出所有已成名的成员
void print_yd(STU *h)
{
	STU *p=h;
	system("cls");
	system("color 0a");
	cout<<"————【已被点名的幸运儿名单】————\n\n";

	if(!p) 
	{
		system("cls");
		cout<<"——————【现在还没有数据哦！】——————\n\n";
		system("pause");
		return ;
	}
	cout<<"——————————————\n";
	while(p)
	{
		
		if(p->sign)
		{
			cout<<"学号： "<<p->num<<endl<<endl;
			cout<<"姓名： "<<p->name<<endl<<endl;
			cout<<"性别： "<<p->sex<<endl<<endl;
			cout<<"电话号码： "<<p->tel<<endl<<endl;
			cout<<"核酸记录： "<<p->fla<<endl<<endl;
			cout<<"核酸检测结果： "<<p->hesuan<<endl<<endl;
			cout<<"——————————————";
			cout<<endl;
		}
		p=p->next;
	}
	system("pause");
	
}

//链表输出函数 输出所有成员
void print(STU *h)//打印
{
	STU *p=h;
	system("cls");
	system("color 0a");

	if(!print_data)
	{
		music(13,0,0);
		Hello(8);
		print_data=1;
	}

	cout<<"————【学生信息界面】————\n\n";

	if(!p) 
	{
		cout<<"现在还没有数据哦！\n\n";
		cout<<endl;
		system("pause");
		return ;
	}
	cout<<"——————————————\n";
	while(p)
	{
		cout<<"学号： "<<p->num<<endl<<endl;
		cout<<"姓名： "<<p->name<<endl<<endl;
		cout<<"性别： "<<p->sex<<endl<<endl;
		cout<<"电话号码： "<<p->tel<<endl<<endl;
		cout<<"核酸记录： "<<p->fla<<endl<<endl;
		cout<<"核酸检测结果： "<<p->hesuan<<endl<<endl;
		cout<<"——————————————";
		cout<<endl;
		p=p->next;
	}
	cout<<"【温馨小提示：如果看不到其它数据请向前滚动鼠标滑轮查看哦。】\n\n";

	system("pause");
}

//信息输出及拷贝函数
void file_Out(STU *h,int i=1)
{
	FILE *fp;
															/*if(fopen_s(&fp,"Student.txt","w+"))//文件有误返回1，否则返回0
															{
																cout<<"\n\n文件创建错误，请查看文件路径是否正确！";
																return ;
															}*/
	
	if(i)
	{
		if((fp=fopen("Student.txt","w"))==NULL)
		{
			cout<<"\n————【文件创建错误，请查看文件路径是否正确！】————\n";
			return ;
		}
	}
	else
	{
		if((fp=fopen("Student【拷贝，防止数据意外丢失】.txt","w"))==NULL)
		{
			cout<<"\n————【拷贝文件创建错误，请查看文件路径是否正确！】————\n";
			return ;
		}
	}
	
	if(!h)
	{
		if(i)
		{
			cout<<"———(现无数据存入文档)———\n\n";
			system("pause");
		}
		return ;
	}

	STU *p=h;
	while(p)
	{
		fputs(p->num,fp);
		fputc(' ',fp);
		fputs(p->name,fp);
		fputc(' ',fp);
		fputs(p->sex,fp);
		fputc(' ',fp);
		fputs(p->tel,fp);
		fputc(' ',fp);
		fputs(p->fla,fp);
		fputc(' ',fp);
		fputs(p->hesuan,fp);
		fputc('\n',fp);
		p=p->next;
	}
	fclose(fp);
}

//信息读取函数
STU *file_Read()
{
	STU *h;
																//int  err;
	FILE *fp;
	if((fp=fopen("Student.txt","r+"))==NULL)
	{
		system("cls");
		system("color 0a");
		cout<<"———(系统检测您未创建名为Student的文本文件)———\n\n";
		cout<<"———(不用担心，本系统已自动帮你创建了一个,You're welcome！)———";
		cout<<"\n\n———(此时文件中现无数据，记得去初始化数据哦!)———\n\n";
		return NULL;
	}
																	/*if((fopen_s(&fp,"Student.txt","r+")))//用这个打开就会有BUG
																	{
																																							cout<<"err:"<<err;
																		cout<<"\n\n读取文件错误，请查看文件路径是否正确或其文件是否存在！";
																		return NULL;
																	}*/
	
	for(int i=1;i<=2;i++) fgetc(fp);														//这个位置要多读取几次文件才会到结尾位置 cout<<"fe:"<<feof(fp)<<endl;
	if(feof(fp)) return NULL; 

	fseek(fp,-2L,1);	
	
	if(!ftell(fp))
	{
																							//cout<<ftell(fp)<<endl;
		STU *p,*q;
		h=q=p=new STU;
		char zf;
		while(!feof(fp))
		{
																							//cout<<"我进来了^^^ f:"<<ftell(fp)<<endl;
			int i=0;
			
			while((zf=fgetc(fp))!=EOF&&zf!=' ') p->num[i++]=zf;
			p->num[i]='\0';
			if(zf==EOF)break;

			i=0;
			while((zf=fgetc(fp))!=EOF&&zf!=' ') p->name[i++]=zf;
			p->name[i]='\0';
			if(zf==EOF)break;

			i=0;
			while((zf=fgetc(fp))!=EOF&&zf!=' ') p->sex[i++]=zf;
			p->sex[i]='\0';																	//cout<<p->sex<<"	f:"<<ftell(fp)<<endl;
			if(zf==EOF)break;

			i=0;
			while((zf=fgetc(fp))!=EOF&&zf!=' ') p->tel[i++]=zf;
			p->tel[i]='\0';
																							//cout<<p->tel<<"	f:"<<ftell(fp)<<endl;
			if(zf==EOF)break;

			i=0;
			while((zf=fgetc(fp))!=EOF&&zf!=' ') p->fla[i++]=zf;
			p->fla[i]='\0';																	//cout<<p->fla<<"	f:"<<ftell(fp)<<endl;
			if(zf==EOF)break;	

			i=0;
			while((zf=fgetc(fp))!=EOF&&zf!=' ')
			{ 
				if(zf=='\n') 
				{																			//cout<<"现在的位置："<<ftell(fp)<<endl;
					for(int i=1;i<=2;i++) fgetc(fp);										//这个位置要多读取几次文件才会到结尾位置 cout<<"fe:"<<feof(fp)<<endl;
					if(feof(fp)) break;
					fseek(fp,-2L,1);														//如果文件指针往后了两次还没到文件结尾,那么就到回来原来的位置.
					break;
				}
				p->hesuan[i++]=zf;

			}
			p->hesuan[i]='\0';																	//cout<<p->hesuan<<"	f:"<<ftell(fp)<<endl;
			if(zf==EOF)break;

			p=new STU;
			if(!feof(fp))
			{
				q->next=p;
				q=p;
			}
			
		}
		q->next=NULL;
		fclose(fp);
	}
	else 
	{
		cout<<"文件内容为空，请初始化数据。\n\n";
		fclose(fp);
		return NULL;
	}

	return h;
}

//插入函数 可插入多个重复的元素
STU * inster(STU *h)
 {
 
 	STU *t,*p,*q;
cr:
	t=new STU;

	system("cls");
	system("color 04");

	music(9,0,0);

	if(!insert_data)
	{
		Hello(5);
		insert_data=1;
	}

	printf("\t ————[插入数据]————\n\n");
	cout<<"请分别填写下面信息（每条信息之间请用空格隔开,输入 # 退出本界面）\n\n";
    printf("学号\t姓名\t性别\t电话号码    是否核酸    阴阳性\n\n");//输入给t,如果不需要使用其中的某项数据请输入0

	

    cin>>t->num;

	if(!strcmp(t->num,"#")) 
	{
		Exit=0;
		delete t;
		return h;
	}

	cin>>t->name>>t->sex>>t->tel>>t->fla>>t->hesuan;

 	if(!h)
 	{
		h=t;
		h->next=NULL;

		system("cls");
		cout<<"————【添加成功！】————\n\n";
		cout<<"（小提示：若想继续输入请输入1，否则输入任意键退出！）\n\n";
		cout<<"请输入您的选择： ";

		char n;
		cin>>n;
		if(n=='1') goto cr;

		return h;
	}
	else
	{ 
		p=q=h;
 		while(p)
 		{
 			if(strlen(p->num)>=strlen(t->num))//判断位数
 			{
				if(strlen(p->num)==strlen(t->num))//同位比较
				{
					if(strcmp(p->num,t->num)>=0)
					{
						if(p==h) //开头
						{
							h=t; 
							h->next=p;
						}
						else //中间
						{
							q->next=t;
							t->next=p;
						}	

						system("cls");
						cout<<"————【添加成功！】————\n\n";
						cout<<"（小提示：若想继续输入请输入1，否则输入任意键即可退出！）\n\n";
						cout<<"请输入您的选择： ";

						char n;
						cin>>n;
						if(n=='1') goto cr;

						return h;
					}
				}
				else //不同位插入
				{
					if(p==h) //开头
					{
						h=t; 
						h->next=p;
					}
					else //中间
					{
						q->next=t;
						t->next=p;
					}	

					system("cls");
					cout<<"————【添加成功！】————\n\n";
					cout<<"（小提示：若想继续输入请输入1，否则输入任意键即可退出！）\n\n";
					cout<<"请输入： ";

					char n;
					cin>>n;
					if(n=='1') goto cr;
					return h;
				}
				
			 }
			 q=p;
			 p=p->next;
		}  
		if(!p)//末尾
		{
			q->next=t;
			t->next=NULL;

			system("cls");
			cout<<"————【添加成功！】————\n\n";
			cout<<"（小提示：若想继续输入请输入1，否则输入任意键即可退出！）\n\n";
			cout<<"请输入： ";

			char n;
			cin>>n;
			if(n=='1') goto cr;
			return h;
		} 
	}
	
	return h;
}

//删除函数 可删除重复的元素
STU* student_delete(STU* h)  
{
	char x[10];
	
end:
	system("cls");
	system("color 04");

	music(10,0,0);

	if(!delete_data)
	{
		Hello(6);
		delete_data=1;
	}

	cout<<"\t\t————【删除界面】————\n\n";

	if(!h)
	{
		cout<<"此文件中已无数据，请前往主界面初始化！\n\n";
		system("pause");
		return h;
	}
	cout<<"(提示：输入 # 可查看现有信息，输入 * 可删除所有信息，输入 0 结束本次业务)\n\n";
	cout<<"请输入你要删除的【学号】：";

	
	cin>>x;    

	if(!strcmp(x,"#")) { print(h); goto end;}
	if(!strcmp(x,"0")) return h;
	if(!strcmp(x,"*"))
	{
		Free(h);
		FILE *fp=fopen("Student.txt","w");
		fclose(fp);

		system("cls");

		music(3,0,0);

		cout<<"————全部已删除成功！————\n\n";
		Sleep(1000);
		system("pause");

		return NULL;
	}

	STU *p,*m;
	m=h;

	while(m)
	{
		if(!strcmp(m->num,x))  break;
		m=m->next;
    }

    if(!m)
	{
		system("cls");
		cout<<"查无此数，删除失败！\n\n";
		system("pause");
		goto end;
	}

con:
	p=m=h;

	while(p)
	{
		if(!strcmp(p->num,x))  break;
		else 
		{
			m=p;p=p->next;
		} 
    }
  
    if(p==h)
	{
		h=p->next;
		delete p;
		goto con;//删除重复信息
	}
	else if(!p) 
	{
		system("cls");
		cout<<"————删除成功！————\n\n";
		Sleep(1000);
		system("pause");
		goto end;
	}
	else 
	{
		m->next=p->next;
		delete p;
		goto con;
	}
}

//修改函数
void  polish(STU *h)
{

p1:

	system("cls");
	cout<<"\t\t————【修改界面】————\n\n";

	if(!h)
	{
		cout<<"此文件中已无数据，请前往主界面初始化！\n\n";
		system("pause");
		return ;
	}

	int sign=0;
	cout<<"【1】学号："<<h->num<<endl;
	cout<<"【2】姓名："<<h->name<<endl;
	cout<<"【3】性别："<<h->sex<<endl;
	cout<<"【4】电话号码："<<h->tel<<endl;
	cout<<"【5】核酸记录："<<h->fla<<endl;
	cout<<"【6】核酸检测结果："<<h->hesuan<<endl<<endl;
	cout<<"输入前面的数字可进行更改（例如输入 2 更改姓名,如若输入 0 则退出本界面。）\n\n";
	cout<<"请输入您的选择： ";

	char n[10];
	cin>>n;

	if(!strcmp(n,"0"))
	{
		return ;
	}
	else if(!strcmp(n,"1"))
	{
		system("cls");
		cout<<"请输入新的学号：\n";
		cin>>h->num;

		system("cls");
		cout<<"\n————【更改成功】————\n\n";
		Sleep(1000);
		goto p1;
	}
	else if(!strcmp(n,"2"))
	{
		system("cls");
		cout<<"请输入新的姓名：\n";
		cin>>h->name;
		
		system("cls");
		cout<<"\n————【更改成功】————\n\n";
		Sleep(1000);
		goto p1;
	}
	else if(!strcmp(n,"3"))
	{
		system("cls");
		cout<<"请输入新的性别：\n";
		cin>>h->sex;
		
		system("cls");
		cout<<"\n————【更改成功】————\n\n";
		Sleep(1000);
		goto p1;
	}
	else if(!strcmp(n,"4"))
	{
		system("cls");
		cout<<"请输入新的电话号码：\n";
		cin>>h->tel;
		
		system("cls");
		cout<<"\n————【更改成功】————\n\n";
		Sleep(1000);
		goto p1;
	}
	else if(!strcmp(n,"5"))
	{
		system("cls");
		cout<<"请输入新的核酸记录：\n";
		cin>>h->fla;
		
		system("cls");
		cout<<"\n————【更改成功】————\n\n";
		Sleep(1000);
		goto p1;
	}
	else if(!strcmp(n,"6"))
	{
		system("cls");
		cout<<"请输入新的核酸检测结果：\n";
		cin>>h->hesuan;
		
		system("cls");
		cout<<"\n————【更改成功】————\n\n";
		Sleep(1000);
		goto p1;
	}
	else
	{
		system("cls");
		cout<<"输入错误，请重新输入\n\n";
		system("pause");
		goto p1;
	}
}

//查找函数
void find(STU *h) 
{
	char x[20];  
s:

	system("cls");
	system("color 04");
	
	music(12,0,0);

	if(!find_data)
	{
		Hello(7);
		find_data=1;
	}

	cout<<"\t\t————【查找界面】————\n\n";

	if(!h)
	{
		cout<<"此文件中已无数据可找，请前往主界面初始化！\n\n";
		system("pause");
		return ;
	}
	cout<<"(温馨小提示：输入 # 可查看现有信息，输入 0 结束本次业务)\n\n";
	cout<<"请输入要查找的学号：";

	cin>>x;

	if(!strcmp(x,"#")) { print(h); goto s;}
	if(!strcmp(x,"0")) return ;

	STU *p=h;
	while(p)
	{
		if(strcmp(p->num,x)==0) break;
		else p=p->next;
	}

	if(!p)
	{
		system("cls");
		cout<<"查无此数！\n\n";
		system("pause");
		goto s;
	}
s1:
	system("cls");
	cout<<"————【查找成功！】————\n\n";
	cout<<"学号："<<p->num<<endl;
	cout<<"姓名："<<p->name<<endl;
	cout<<"性别："<<p->sex<<endl;
	cout<<"电话号码："<<p->tel<<endl;
	cout<<"核酸记录："<<p->fla<<endl;
	cout<<"核酸检测结果："<<p->hesuan<<endl;
	cout<<endl<<endl;
	cout<<"————【小提示：如需修改输入#,返回上一级界面输入0】————\n\n";
	cout<<"请输入您的选择： ";

	char k;
	cin>>k;

	if(k=='#')
	{
		polish(p);
		goto s;
	}
	else if(!(k-48))
	{
		goto s;
	}
	else 
	{
		system("cls");
		cout<<"\n您输入的数据有误，请重新输入！\n\n";
		system("pause");
		goto s1;
	}
	
}

//开始点名函数
void call_Name(STU *h)
{
home_xitong:

	STU *p=h;

	if(!h) 
	{
		system("cls");
		cout<<"检测到您当前还未初始化数据，无法为你点名，请前往【操作数据界面】初始化数据后再来，谢谢！\n\n";

		music(0,2,0);//2音乐暂停 播放 暂停 继续

		music(0,0,1);//1音乐开始
		return ;
	}

	setZero(h);

	int DJS=3;
	srand(time(NULL));
	system("cls");
    system("color 0c");

	if(!dm_program)
	{
		Hello(9);
		dm_program=1;
	}
	

    printf("————【欢迎来到点名小系统！】————\n\n");
    printf("今日日期：  "); 
    system("date /t");
	cout<<endl;
    printf("当前时间：  ");
    system("time /t");
    
	

    printf("\n输入数字 0 可退出本系统，否则按任意键可开始哦！ ");

    if(getch()=='0') 
	{
		system("cls");

		music(0,2,0);//2音乐暂停 播放 暂停 继续

		music(0,0,1);//1音乐开始

		music(5,0,0);

		if(!dm_exit)
		{
			
			Hello(11);
			dm_exit=1;
		}

		cout<<"————【终于完成了，点名小系统补觉去了……】————\n\n";
		Sleep(1000);

		

		return ;
	}

door:
	
	system("color 04");
	system("cls");

	if(!dm_way)
	{
		Hello(10);
		dm_way=1;
	}

    printf("————【开门密钥：输入左边的数字】————\n\n");
    printf("【1】 静态点名（一次只点一名同学）\n\n");
    printf("【2】 动态点名（例如：输入2就点2名同学）\n\n");
	printf("【3】 返回主界面\n\n");

	cout<<" 请输入您的选择（暂停音乐输入 s，继续播放输入 c ）： ";

    char pd[10];
	cin>>pd;

	if(!strcmp(pd,"s")||!strcmp(pd,"S"))
	{
		music(0,2,0);
		goto door;
	}
	else if(!strcmp(pd,"c")||!strcmp(pd,"C"))
	{
		music(0,0,2);
		goto door;
	}
    else if(!strcmp(pd,"1"))//输入1的情况
	{
re:
		ll name;

		if(d_Name_Over(h))
		{
			int yu=5,yy=0;
			system("color 04");

			while(yu--)
			{
				system("cls");
				yy++;

				if(yy>3) yy=1;
					
				if(yy==1) printf("……叮咚！检测到所有成员已被点名一次，本次任务已完成，即将返回世界之门！。");
				if(yy==2) printf("……叮咚！检测到所有成员已被点名一次，本次任务已完成，即将返回世界之门！。。");
				if(yy==3) printf("……叮咚！检测到所有成员已被点名一次，本次任务已完成，即将返回世界之门！。。。");
					
				Sleep(1000);
			}
			setZero(h);
			goto door;
		}

		while(1)//点名中……
		{
			name=abs(rand())%lb_Size(h)+1;//点名

			p=h;

			if(d_Name_Over(h))//判断班上所有名字是否全都点到了。
				break;

			if(lb_Size(h)==1) name=0; //如果只有一个链表。
			else name--;

			while(name--)//找到位置
			{
				p=p->next;
			}

			if(!p->sign)// 如果有该成员sign是0说明这个成员还未点名，点完就可以进入下一次循环了。
			{
				p->sign=1;//点到就置为1 
				break;
			}
				
		}

		ll djs=DJS,sign=1;

		while(djs--)
		{
			system("cls");

			if(sign>3)sign=1;

			if(sign==1) printf("今天的幸运儿是谁呢？。");
			if(sign==2) printf("今天的幸运儿是谁呢？。。");
			if(sign==3) printf("今天的幸运儿是谁呢？。。。");
			
			sign++;
			Sleep(1000);
		}

		int show=1;
a:
		
		system("cls");
		cout<<"————【本场的幸运儿闪亮登场!】————"<<endl<<endl;

		if(show)
		{
			Sleep(1000);
			cout<<"\t\t   "<<p->name<<"\a";
			Sleep(1000);
		}
		else cout<<"\t\t   "<<p->name<<"";

		cout<<"\n\n\n————      【温馨小提示】      ————\n\n";
		cout<<"输入任意键（除后面提到的按键外）可返回上一级界面哦。\n\n";
		cout<<"按数字键(0~9之间，默认值为3)可以修改倒计时秒数哦\n\n";
		cout<<"按字母键 s 可以查看成员点名的情况哦。\n\n";
		cout<<"想查看已抽取的幸运儿名单吗，要不输入 # 试试？\n\n";
		printf("如需再次点名请按空格 【space】\n\n");
		
		int i;
		switch(_getch())
		{
			case '#': print_yd(h); show=0; system("color	04"); goto a;
			case '0': DJS=0;printf("注：倒计时已修改为%d秒。",DJS);show=0;Sleep(1000);goto a;
			case '1': DJS=1;printf("注：倒计时已修改为%d秒。",DJS);show=0;Sleep(1000);goto a;
			case '2': DJS=2;printf("注：倒计时已修改为%d秒。",DJS);show=0;Sleep(1000);goto a;
			case '3': DJS=3;printf("注：倒计时已修改为%d秒。",DJS);show=0;Sleep(1000);goto a;
			case '4': DJS=4;printf("注：倒计时已修改为%d秒。",DJS);show=0;Sleep(1000);goto a;
			case '5': DJS=5;printf("注：倒计时已修改为%d秒。",DJS);show=0;Sleep(1000);goto a;
			case '6': DJS=6;printf("注：倒计时已修改为%d秒。",DJS);show=0;Sleep(1000);goto a;
			case '7': DJS=7;printf("注：倒计时已修改为%d秒。",DJS);show=0;Sleep(1000);goto a;
			case '8': DJS=8;printf("注：倒计时已修改为%d秒。",DJS);show=0;Sleep(1000);goto a;
			case '9': DJS=9;printf("注：倒计时已修改为%d秒。",DJS);show=0;Sleep(1000);goto a;
			case ' ': goto re;
			case 's':
			case 'S':
					
					i=3; 
					while(i--)
					{
						system("cls");
						printf("……叮咚！ 【%d】秒后即将前往【成员信息观察界面】…………",i+1);
						Sleep(1000);
					}

					see(h);
					show=0;

					system("color	04"); 

					goto a;
			default : DJS=3; setZero(h);goto door;
		}
	 }

    else if(!strcmp(pd,"2"))//输入2的情况
	{
		DJS=3;

re1:
		if(d_Name_Over(h))
		{
			int yu=5,yy=0;

			system("color 04");

			while(yu--)
			{
				system("cls");
				yy++;

				if(yy>3) yy=1;
					
				if(yy==1) printf("……叮咚！检测到所有成员已被点名一次，本次任务已完成，即将返回世界之门！。");
				if(yy==2) printf("……叮咚！检测到所有成员已被点名一次，本次任务已完成，即将返回世界之门！。。");
				if(yy==3) printf("……叮咚！检测到所有成员已被点名一次，本次任务已完成，即将返回世界之门！。。。");
					
				Sleep(1000);
			}
			setZero(h);
			goto door;
		}
b:
		system("cls");

		if(!dTao_dm)
		{
			Hello(13);
			dTao_dm=1;
		}

		cout<<"————【点名环节】————\n\n";
		cout<<"您要点多少人呢，请在此输入(范围在1~"<<lb_Size(h)<<"之间，返回上级界面请输入 # ):  ";

		char number;

		cin>>number;

		if(number-48<=0||number-48>lb_Size(h))
		{
			if(number=='#') 
			{
				setZero(h); 
				goto door;

			}

			system("cls");
			printf("您输入的数据不在允许的范围内，请重新输入！\n\n",lb_Size(h));
			system("pause");
			goto re1;
		} 

		ll djs=DJS,sign=1;

		while(djs--)
		{
			system("cls");

			if(sign>3)sign=1;

			if(sign==1) printf("今天的幸运儿是谁呢？。");
			if(sign==2) printf("今天的幸运儿是谁呢？。。");
			if(sign==3) printf("今天的幸运儿是谁呢？。。。");
			
			sign++;
			Sleep(1000);
		}

		if(number-48>noNameNum(h)) 
		{
			int i=3; 
			while(i--)
			{
				system("cls");
				printf("……叮咚！检测到您输入的数值越界，系统将于【%d】秒后前往【错误信息界面】查看…………",i+1);
				Sleep(1000);
			}

			system("cls");
			cout<<"————【错误信息界面】————\n\n";
			cout<<"(注意哦，点过的同学本系统不会再点！)\n\n";
			cout<<"(目前没点名的还有"<<noNameNum(h)<<"名同学,但你竟还要点 "<<number<<" 名!)\n\n";
			cout<<"(告诉你，本系统第一个不同意，只会乖乖的帮你点剩下的这 "<<noNameNum(h)<<" 名同学呢！)\n\n";
			cout<<"(同一个人如果能被多次点名这还得问下我的主人 【Lyq】 呢)\n\n";
			cout<<"(我还小没权限 呜~ see you!)"<<endl<<endl;
			system("pause");

			number=noNameNum(h)+48;//比如总共有3名成员，但我点1 3，则最后只需点两次就可以了。此处要加上48,后面的循环中有-48,因为no这个函数返回Int，先转成字符

			if(d_Name_Over(h)) goto re1;

			i=3; 
			while(i--)
			{
				system("cls");
				printf("……叮咚！【%d】秒后将前往点名地点…………",i+1);
				Sleep(1000);
			}

			system("cls");
		}

		system("cls");
		cout<<"————【本场的幸运儿们闪亮登场】————"<<endl<<endl;
		Sleep(1000);

		for(int i=1;i<=number-48;i++)
		{
			int name,num=0;
			while(1)
			{
				name=abs(rand())%lb_Size(h)+1;//点名

				p=h;

				if(d_Name_Over(h))//判断班上所有名字是否全都点到了。
					break;

				if(lb_Size(h)==1) name=0; //如果只有一个链表。
				else name--;

				while(name--)//找到位置
				{
					p=p->next;
				}

				if(!p->sign)// 如果有该成员sign是0说明这个成员还未点名，点完就可以进入下一次循环了。
				{
					p->sign=1;//点到就置为1 
					break;
				}
				
			}
			printf("第[%d]位： %s\n\n\a",i,p->name);//输出
			Sleep(1000);
		}
		cout<<"\n————      【温馨小提示】      ————\n\n";
		cout<<"按任意键（除后面提到的按键外）可返回上一级界面哦。\n\n";
		cout<<"想查看已抽取的幸运儿名单吗，要不输入 # 试试？\n\n";
		cout<<"按数字键(0~9之间,默认值为3)可以修改倒计时哦\n\n";
		cout<<"按字母键 s 可以查看成员点名的情况哦。\n\n";
		printf("如需再次点名请按空格 【space】\n\n");
		int i;
		switch(_getch())
		{
			case '#': print_yd(h); i=3;  system("color 04"); while(i--){system("cls"); printf("【%d】秒后即将前往【点名环节】…………",i+1);Sleep(1000);}goto b;
			case '0': DJS=0;i=5; while(i--){system("cls"); printf("……叮咚！ 倒计时已修改为%d秒，【%d】秒后即将前往【点名环节】…………",DJS,i+1);Sleep(1000);}goto b;
			case '1': DJS=1;i=5; while(i--){system("cls"); printf("……叮咚！ 倒计时已修改为%d秒，【%d】秒后即将前往【点名环节】…………",DJS,i+1);Sleep(1000);}goto b;
			case '2': DJS=2;i=5; while(i--){system("cls"); printf("……叮咚！ 倒计时已修改为%d秒，【%d】秒后即将前往【点名环节】…………",DJS,i+1);Sleep(1000);}goto b;
			case '3': DJS=3;i=5; while(i--){system("cls"); printf("……叮咚！ 倒计时已修改为%d秒，【%d】秒后即将前往【点名环节】…………",DJS,i+1);Sleep(1000);}goto b;
			case '4': DJS=4;i=5; while(i--){system("cls"); printf("……叮咚！ 倒计时已修改为%d秒，【%d】秒后即将前往【点名环节】…………",DJS,i+1);Sleep(1000);}goto b;
			case '5': DJS=5;i=5; while(i--){system("cls"); printf("……叮咚！ 倒计时已修改为%d秒，【%d】秒后即将前往【点名环节】…………",DJS,i+1);Sleep(1000);}goto b;
			case '6': DJS=6;i=5; while(i--){system("cls"); printf("……叮咚！ 倒计时已修改为%d秒，【%d】秒后即将前往【点名环节】…………",DJS,i+1);Sleep(1000);}goto b;
			case '7': DJS=7;i=5; while(i--){system("cls"); printf("……叮咚！ 倒计时已修改为%d秒，【%d】秒后即将前往【点名环节】…………",DJS,i+1);Sleep(1000);}goto b;
			case '8': DJS=8;i=5; while(i--){system("cls"); printf("……叮咚！ 倒计时已修改为%d秒，【%d】秒后即将前往【点名环节】…………",DJS,i+1);Sleep(1000);}goto b;
			case '9': DJS=9;i=5; while(i--){system("cls"); printf("……叮咚！ 倒计时已修改为%d秒，【%d】秒后即将前往【点名环节】…………",DJS,i+1);Sleep(1000);}goto b;
			case ' ': i=3; while(i--){system("cls"); printf("……叮咚！【%d】秒后即将前往【点名环节】…………",i+1);Sleep(1000);} goto re1;
			case 's':
			case 'S':

					i=3; 
					while(i--)
					{
						system("cls");
						printf("……叮咚！ 【%d】秒后即将前往【成员信息观察界面】…………",i+1);
						Sleep(1000);
					}

					see(h);

					system("color 04");

					i=3; 
					while(i--)
					{
						system("cls"); 
						printf("……叮咚！【%d】秒后即将前往【点名环节】…………",i+1);
						Sleep(1000);
					}

					goto b;
			default :  setZero(h); goto door;
		}

	} 
	else if(!strcmp(pd,"3"))
	{
		goto home_xitong;
	}
    else 
	{
		system("cls");
		printf("\n您输入的数据不在允许的范围内，请重新输入！\n\n");
		system("pause");
		goto door;
	}
}

//主界面函数
void main_home()
{
	system("title 学生信息管理小系统");
	system("cls");  
    system("color 0c");

	//加速语句，加快cin和cout函数数据的读取与写入。
	ios::sync_with_stdio(false);
	cin.tie(0);

	music(2,0,0);//插放后暂停，否则在后面打开就会有BUG出现。
	music(0,2,0);

	music(8,0,0);

	Hello(1);

	music(1,0,0);

	printf("————【学生管理系统】————\n\n");
    printf("今日日期：  "); 
    system("date /t");
	cout<<endl;
    printf("当前时间：  ");
	system("time /t");
	cout<<endl;
	system("pause");

	system("cls");

	STU *h=file_Read();

	

	if(!h) 
	{

		if(!NULL_data)
		{
			Hello(16);
			NULL_data=1;
		}

	}

	file_Out(h);
	file_Out(h,0);//进行创建拷贝

home1:

	system("cls");
	system("color 04");

	
	if(!zJieMian)
	{
		music(6,0,0);
		Hello(2);
		zJieMian=1;
	}

	cout<<"\t ————【主界面】————\n\n";

	cout<<"请按提示进入相应的业务!（输入对应数字即可进入）\n\n";
	cout<<"【1】 数据操作\t";
	cout<<"【2】 开始点名\t";
	cout<<"【3】 系统介绍\t";
	cout<<"【4】 退出系统 \n\n";
	cout<<"请输入您的选择（暂停音乐输入s，继续播放输入c）： ";

	int s;

	char n[10],m[10];
	cin>>n;

	if(!(strcmp(n,"1"))||!(strcmp(n,"2"))||!(strcmp(n,"3"))||!(strcmp(n,"4"))||!(strcmp(n,"s"))||!(strcmp(n,"c"))||!(strcmp(n,"S"))||!(strcmp(n,"C")))//防止有人输入1ksfjks这种导致程序出错，就用这个了。
	{
		switch(n[0])
		{
			case '1':
sh1:
				system("cls");
				system("color 0b");

				if(!data_operat)
				{
					Hello(3);
					data_operat=1;
				}

				cout<<"    ————[数据操作界面]————\n\n";
				cout<<"请按提示进入相应的业务!（输入对应数字即可进入）\n\n";
				cout<<"【1】 初始化数据\t";
				cout<<"【2】 插入数据\n\n";
				cout<<"【3】 删除数据\t\t";
				cout<<"【4】 先查找后修改数据\n\n";
				cout<<"【5】 查看所有数据\t";
				cout<<"【6】 退出本界面\n\n";

				cout<<"请输入您的选择： ";

				cin>>m;

				if(m[0]>='1'&&m[0]<='6')
				{
					switch(m[0])
					{
						case	'1':
									if(!file_Read())
									{
										h=primary();
										if(h) file_Out(h);
										goto sh1;
									}
									else
									{
										system("cls");

										if(!primary_fail)
										{
											Hello(4);
											primary_fail=1;
										}

										cout<<"\n……叮咚！系统检测到原来的Student文本文件中已有数据，此次业务功能暂时关闭。\n\n";
										cout<<"(如需插入数据请返回【数据操作界面】中输入 2 进行插入操作)\n\n";

										system("pause");
										goto sh1;
									}
						case	'2':
									
									h=inster(h);

									if(Exit)
									{
										system("cls");
										cout<<"————添加成功！————\n\n";
										Sleep(1000);
										system("pause");
										file_Out(h);

										goto sh1;
									}

									Exit=1;
									if(h) file_Out(h);

									goto sh1;
									
						case	'3':

									h=file_Read();

									h=student_delete(h);

									if(h) file_Out(h);

									goto sh1;

						case	'4':
									find(h);

									if(h) file_Out(h);

									goto sh1;
						case	'5':
									h=file_Read();
									print(h);
									goto sh1;
						case	'6':
									break;

					}

					break;
				}
				else
				{
					system("cls");
					cout<<"————【您输入的数字有误，请确认输入的信息是否正确！】————\n\n";
					system("pause");
					goto sh1;
				}
				
			case '2':

				music(0,1,0);//暂停

				music(0,0,2);//播放另一首

				s=3;
				while(s--)
				{
					system("cls");
					printf("————【正在启动中……  %d 秒后进入点名小系统】————",s+1);
					Sleep(1000);
				}

				call_Name(h);

				system("pause");

				break;
			
			case '3':

				Team();

				break;
			case '4':


				system("cls");

				if(!program_exit)
				{
					music(4,0,0);
					Hello(12);
					program_exit=1;
				}

				cout<<"———(学生信息管理系统服务到此结束，欢迎下次光临！)———\n\n";

				file_Out(h);

				file_Out(h,0);//进行创建拷贝

				return ;

			case 's':
			case 'S':

						music(0,1,0);
						break;

			case 'c':
			case 'C':

						music(0,0,1);
						break;
		}
		goto home1;
	}
	else
	{
		system("cls");
		cout<<"————【您输入的数字有误，请确认输入的信息是否正确！】————\n\n";
		system("pause");
		goto home1;
	}

}

//主函数
int main()
{
	/*main_home();*/
	/*union
	{
		int a;
		float b;
		char s;
	}b;*/

	typedef void (*INT)();
	INT a,b;
	b=main_home;
	//INT a=main_home;
	b();

    return 0;
}