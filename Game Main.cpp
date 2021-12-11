/*
编译要c++11 
扩增前看这里：
游戏中的库在命名空间game内 
吐字速度在outspeed变量中
输出用game::out换行输出提供值endl = true；不然endl = false
地图存在map中 
暂停用stop(time) //time单位为ms
不要using namespace std;!!! 
不要using namespace std;!!!
不要using namespace std;!!!
不要using namespace std;!!!
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
	out("欢迎来到World游戏, 载入中:", true);
	out("0%  ", false);
	out(game::version, true);
	game::__map nb;
	nb.themap(20, 5);
	nb.m[0] = "********************";
	nb.m[1] = "d khh kkk    hhh   *";
	nb.m[2] = "drkhhrkckrrrrhhh   *";
	nb.m[3] = "d khh kkk    hhh   *";
	nb.m[4] = "********************";
	nb.a = "d是门,*是围墙,h是房子,k是军营,c是村中心,r是路";
	out("100%  完成", true);
	stop(2000);
	clear();
	out("你昏迷在一个村子边，这个村子的首领刚刚去世，这个巧合使你当上了首领", true);
	out("加载NB村......", true);
	nb.out();
	out("请到村中心任职", true);
	game::move(1, 2, 'c', nb, 'y');
	out("打家欢呼着你上台,他们十分兴奋,但现在有人告诉你,我们的敌人想开战了", true);
	out("请选择操作:\n1.求和 2.开战 3.饶舌", true);
	int *a = new int;
	scanf("%d", a);
	switch (*a)
	{
		case 1:
			out("求和失败,战争开始,你打不过,游戏结束", true);
			return 0;
		case 2:
			out("战争开始了,你要干什么:\n1.等待 2.发表演说", true);
			scanf("%d", a);
			 
	}
	delete a; 
	return 0;
}
