#include <iostream>
#include <Windows.h>
#include <cstring>
#include <cstdio>

using namespace std;

struct things
{
	int tNumber;
	string tThings;
	bool tstate;
}a[201]{};

static void MainMenu()
{
	cout << "1.Add things\n"
		<< "2.Delete things\n"
		<< "3.Change state\n"
		<< "9.Show this menu \n"
		<< "0.Exit\n";
}

static void kMenu()
{
	cout << "1.Display all variables\n"
		<< "2.initialization\n"
		<< "9.test mode\n"
		<< "0.exit\n";
}

static void showthings(int tn)
{
	for (int i = 1; i < tn; i++)
	{
		cout << a[i].tNumber
			<< ". "
			<< a[i].tThings
			<< "  state:"
			<< a[i].tstate
			<< "\n";
		;
	}
	cout << "\n";
}

int main() {

	int cn = 1;
	int k = 0;
	int tn = 1;
	int input = 9;
	string thing;
	bool start = false;

	cout << "things record            v.1.20\n";
	cout << "Welcome to your used!\n\n";

	FILE* file = fopen("record.txt", "rb");
	fread(a, sizeof(a), 1, file);
	fclose(file);

	while (true)
	{

		showthings(tn);

		MainMenu();

		cout << "Enter:";
		cin >> input;

		//1.添加事件
		if (input == 1)
		{
			cout << "Enter your things:";
			cin >> thing;
			a[tn].tNumber = tn;
			a[tn].tThings = thing;
			a[tn].tstate = false;
			tn++;
			cout << "Add succed!\n\n";
			continue;
		}

		//2.删除事件
		if (input == 2)
		{
			cout << "Enter your delete number:";
			cin >> input;
			if (input == tn - 1)
			{
				tn--;
				continue;
			}
			else if (input == 1 && tn == 2)
			{
				tn--;
				continue;
			}
			else if (input < 1 || input >= tn)
			{
				cout << "Enter error!\n";
				continue;
			}
			cn = tn - input - 1;
			for (int i = 0; i < cn; i++)
			{
				a[input + i].tThings = a[input + i + 1].tThings;
				a[input + i].tstate = a[input + i + 1].tstate;
			}
			tn--;
			for (int j = 1; j <= tn; j++)
			{
				a[j].tNumber = j;
			}
			cout << "delete succed\n\n";
			continue;
		}

		//3.改变状态
		if (input == 3)
		{
			cout << "Enter your want to change thing:";
			cin >> input;
			if (a[input].tstate == false)
			{
				a[input].tstate = true;
			}
			else if (a[input].tstate == true)
			{
				a[input].tstate = false;
			}
			cout << "change succed\n\n";

			cn = tn - input - 1;
			for (int i = 1; i <= cn; i++)
			{
				a[input + i].tNumber--;
			}
			a[input].tNumber = tn - 1;
			for (int j = 1; j < tn; j++)
			{
				for (int m = j; m < tn; m++)
				{
					if (a[m].tNumber == j)
					{
						//swap(a[j].tNumber, a[m].tNumber);
						swap(a[j].tThings, a[m].tThings);
						swap(a[j].tstate, a[m].tstate);
					}
				}
			}
			for (int n = 1; n < tn; n++)
			{
				a[n].tNumber = n;
			}
			continue;

		}

		//8.开发者模式
		if (input == 8)
		{
			system("pause");
		a:
			kMenu();
			cout << "Enter:";
			cin >> k;
			//1.显示变量
			if (k == 1)
			{
				cout << "\n"
					<< "tn= " << tn << endl
					<< "k= " << k << endl
					<< "input= " << input << endl
					<< "start= " << start << endl
					<< "\n";
				goto a;
			}
			//2.初始化
			if (k == 2)
			{
				tn = 1;
				k = 0;
				input = 9;
				start = false;
				cout << "initialization succed\n\n";
				goto a;
			}
			//9.测试功能
			if (k == 9)
			{
				cout << "\nnull.\n\n";

				goto a;
			}
			//0.退出
			if (k == 0)
			{
				continue;
			}
		}

		//0.结束程序
		if (input == 0)
		{
			cout << "record will delete.\n\n"
				<< "Thanks for your used.\n";
			
			FILE* file = fopen("record.txt", "wb");
			fwrite(a, sizeof(a), 1, file);
			fclose(file);

			return 0;
		}
	}
}