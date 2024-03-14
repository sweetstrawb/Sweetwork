#define _CRT_SECURE_NO_WARNINGS


#include<string.h>
#include<stdio.h>
#include<iostream>
#include<fstream>
#include<string>
#include<direct.h>

using namespace std;

double similar_count(string orig,string _article,int sum1,int sum2)//计算查重率
{
	size_t find_index = 0;
	size_t modi = 0;
	

	for (int i = 0; i < orig.length(); i++)
	{
		if (_article.find(orig[i], find_index) == string::npos)
		{
			continue;
		}
		else
		{
			size_t num = _article.find(orig[i], find_index);

			if (num - find_index > 5)//盗版没有该字或者下一个此字出现前有太多字
			{
				modi++;
				continue;
			}
			else
			{
				modi += num - find_index;//中间应该删除的字数
				find_index = num + 1;//盗版文章查找下标移动至出现重复字符的下一个下标
			}
		}
		
		

	}

	double ans;
	if (find_index == 0)//盗版文章寻找下标一直没动，说明相似度很低
	{
		ans = 0;
	}
	else
	{
		ans = 1.0 * sum1 / (modi + sum1);
	}
	return ans;
}

void SaveStr(string &str,string road)
{
	ifstream ifs;
	ifs.open(road, ios::in);

	if (ifs.is_open())
	{

		string buf;

		while (getline(ifs, buf))
		{
			str = str + buf;
			//cout << buf << endl;
		}
		//cout << str;
	}
	else
	{
		cout << "文件打开失败" << endl;
	}
	//关闭文件   
	ifs.close();
}

void printfans(double ans)//输出答案绝对路径
{
	char namen[100];
	_getcwd(namen, 50);//获取当前工作环境的绝对路径

	size_t finalroad;
	for (int i = strlen(namen) - 1; i >= 0; i--)//获取当前工作环境的绝对路径的前缀
	{
		if (namen[i] == '\\')
		{
			finalroad = i;
			break;
		}
	}

	string newroad;
	for (int i = 0; i <= finalroad; i++)
	{
		newroad = newroad + namen[i];
	}
	newroad = newroad + "TheAnswer.txt";//输出答案的绝对路径

	cout << newroad << endl;


	ofstream outfile(newroad);//打开文件

	outfile << "文章重复率：";
	outfile.precision(2);//保留2位小数
	outfile << fixed;
	outfile << ans << '%';

	outfile.close();
}

int main()
{
	string orig;
	string _article;
	string orig_road;
	string art_road;
	size_t sum1;
	size_t sum2;
	
	cin >> orig_road;//原文的路径
	cin >> art_road;//盗版文章的路径
	SaveStr(orig, orig_road);
	SaveStr(_article, art_road);
	sum1 = orig.length();
	sum2 = _article.length();
	double ans = similar_count(orig, _article, sum1, sum2);
	
	ans = ans * 100;//变成百分数
	printfans(ans); //输出答案绝对路径
	return 0;


}