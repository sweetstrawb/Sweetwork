#define _CRT_SECURE_NO_WARNINGS


#include<string.h>
#include<stdio.h>
#include<iostream>
#include<fstream>
#include<string>
#include<direct.h>

using namespace std;

double similar_count(string orig,string _article,int sum1,int sum2)//���������
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

			if (num - find_index > 5)//����û�и��ֻ�����һ�����ֳ���ǰ��̫����
			{
				modi++;
				continue;
			}
			else
			{
				modi += num - find_index;//�м�Ӧ��ɾ��������
				find_index = num + 1;//�������²����±��ƶ��������ظ��ַ�����һ���±�
			}
		}
		
		

	}

	double ans;
	if (find_index == 0)//��������Ѱ���±�һֱû����˵�����ƶȺܵ�
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
		cout << "�ļ���ʧ��" << endl;
	}
	//�ر��ļ�   
	ifs.close();
}

void printfans(double ans)//����𰸾���·��
{
	char namen[100];
	_getcwd(namen, 50);//��ȡ��ǰ���������ľ���·��

	size_t finalroad;
	for (int i = strlen(namen) - 1; i >= 0; i--)//��ȡ��ǰ���������ľ���·����ǰ׺
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
	newroad = newroad + "TheAnswer.txt";//����𰸵ľ���·��

	cout << newroad << endl;


	ofstream outfile(newroad);//���ļ�

	outfile << "�����ظ��ʣ�";
	outfile.precision(2);//����2λС��
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
	
	cin >> orig_road;//ԭ�ĵ�·��
	cin >> art_road;//�������µ�·��
	SaveStr(orig, orig_road);
	SaveStr(_article, art_road);
	sum1 = orig.length();
	sum2 = _article.length();
	double ans = similar_count(orig, _article, sum1, sum2);
	
	ans = ans * 100;//��ɰٷ���
	printfans(ans); //����𰸾���·��
	return 0;


}