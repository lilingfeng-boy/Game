/*
����Ҫc++11 
����ǰ�����
��Ϸ�еĿ��������ռ�game�� 
�����ٶ���outspeed������
�����game::out��������ṩֵendl = true����Ȼendl = false
��ͼ����map�� 
��ͣ��stop(time) //time��λΪms
��Ҫusing namespace std;!!! 
��Ҫusing namespace std;!!!
��Ҫusing namespace std;!!!
��Ҫusing namespace std;!!!
*/
#include<bits/stdc++.h>
#define GAME
#ifdef __WIN32
	#include<Windows.h>
	#define stop(a) Sleep(a)
	#define clear() system("cls") 
#endif
#ifdef __WIN64
	#include<Windows.h>
	#define stop(a) Sleep(a)
	#define clear() system("cls")
#endif
#ifdef _linux_
	#include <unistd.h>
	#define stop(a) usleep((a) * 1000)
	#define clear() system("clear")
#endif
#ifdef _linux
	#include <unistd.h>
	#define stop(a) usleep((a) * 1000)
	#define clear() system("cls")
#endif
using std::string;
namespace game
{
	string name;
	string version = "1.0";
	double outspeed=3;
	struct __map
	{
		int x = 0, y = 0;
		string *m = new string;
		void operator = (const __map &mm)
		{
			this -> x = mm.x;
			this -> y = mm.y;
			std::copy(mm.m, mm.m + 10000, m);
		}
		string a;
		int out()
		{
			for(int i = 0; i < y; i++)
			{
				std::cout << m[i] << '\n';
			}
			std::cout << a << '\n'; 
		}
		int out(int __x, int __y, char __char)
		{
			for(int i = 0; i < y; i++)
			{
				if(i == __y)
					for(int j = 0; j < m[i].length(); j++)
						if(j == __x)
							printf("%c", __char);
						else
							printf("%c", m[i][j]);
				else
					std::cout << m[i];
				printf("\n");
			}
		}
		__map(){};
		void themap(int __x, int __y)
		{
			this -> x = __x;
			this -> y = __y;
			delete(this -> m);
			this -> m = new string[__y];
		};
	};
	void move(int __x, int __y, char __char, __map _map, char player)
	{
		char c, b;
		printf("2\n");
		_map.out(__x, __y, player);
		while(_map.m[__y][__x] != __char)
		{
			scanf("%c", &c);
			scanf("%c", &b);
			switch (c)
			{
				case 'w':
					if(__y != 0)
						__y--;
					break;					
				case 'd':
					if(__x != _map.x)
						__x++;
					break;
				case 'a':
					if(__x != 0)
						__x--;
					break;
				case 's':
					if(__y != _map.y)
						__y++;
					break;
			}
			clear();
			_map.out(__x, __y, player);
		}
	}
	void out(string str, bool endl, unsigned time)
	{
	    if(endl)
	    {
	        for(int i = 0; i < str.length(); i++)
	        {
	        	printf("%c", str[i]);
	        	stop(time);
			}
			printf("\n");
    	}
    	else
    	        for(int i = 0; i < str.length(); i++)
	        {
	        	printf("%c", str[i]);
	        	stop(time);
	        }
	}
	void out(string str, bool endl)
	{
		out(str, endl, outspeed * 0.1);
	}
	
	void out(string str)
	{
	    out(str, false);
	}
	void out(string str, unsigned time)
	{
	    out(str, false, time);
	}
} 
using game::out;
int main(void)
{
	out("��ӭ����World��Ϸ, ������:", true);
	out("0%  ", false);
	out(game::version, true);
	game::__map nb;
	nb.themap(20, 5);
	nb.m[0] = "********************";
	nb.m[1] = "d khh kkk    hhh   *";
	nb.m[2] = "drkhhrkckrrrrhhh   *";
	nb.m[3] = "d khh kkk    hhh   *";
	nb.m[4] = "********************";
	nb.a = "d����,*��Χǽ,h�Ƿ���,k�Ǿ�Ӫ,c�Ǵ�����,r��·";
	out("100%  ���", true);
	stop(2000);
	clear();
	out("�������һ�����ӱߣ�������ӵ�����ո�ȥ��������ɺ�ʹ�㵱��������", true);
	out("����NB��......", true);
	nb.out();
	out("�뵽��������ְ", true);
	game::move(1, 2, 'c', nb, 'y');
	out("��һ���������̨,����ʮ���˷�,���������˸�����,���ǵĵ����뿪ս��", true);
	out("��ѡ�����:\n1.��� 2.��ս 3.����", true);
	int *a = new int;
	scanf("%d", a);
	switch (*a)
	{
		case 1:
			out("���ʧ��,ս����ʼ,��򲻹�,��Ϸ����", true);
			return 0;
		case 2:
			out("ս����ʼ��,��Ҫ��ʲô:\n1.�ȴ� 2.������˵", true);
			scanf("%d", a);
			 
	}
	delete a; 
	return 0;
}
