#include<cstdlib>
#include<iostream>
#include<string>
#include<algorithm>
#include<stack>
#include<stdio.h>
#include<fstream>
#include<vector>
using namespace std;

int Randnum(int minnum, int maxnum)//����[a,b]���������
{
	return (rand() % (maxnum - minnum + 1)) + minnum;
}

string numtostring(int a)       //һ������ת��Ϊ�ַ���
{
	string num;
	while (a >= 10)				//�����һλȡ�ַ�
	{
		int b = a % 10;
		a = a / 10;
		num = num + (char)(b + 48);
	}
	int b = a % 10;
	num = num + (char)(b + 48);
	reverse(num.begin(),num.end());				//��ת�ַ�
	return num;
}

string ChangeToString(int tor, int den)          //С��ת��Ϊ�ַ���   ���ӷ�ĸ�Ѿ�Լ��
{

	string ans;
	if (tor < den)
	{
		ans = ans + numtostring(tor);
		ans = ans + '/';
		ans = ans + numtostring(den);
		//cout << tor << ' ' << den << "   " << ans << endl;
	}
	else
	{
		int a = tor / den;       //���ʽǰ�������
		int b = tor % den;			//���ʽ�ķ���

		ans = ans + numtostring(a) + '\'' + numtostring(b) + '/' + numtostring(den);
	}
	return ans;
}

int Gcd(int a, int b)		//���������
{
	while (1)
	{
		int c = a % b;
		a = b;
		b = c;
		if (b == 1)
		{
			return 1;
		}
		else if(c==0)
		{
			return a;
		}
	}
}

string pronum(int r,bool mark)	//����һ������,r��Χ mark��ʾ�������Ƿ����Ϊ0
{
	string num;
	int a;			 //�����ж�����ʲô��
	a = Randnum(0, 1);     //a�Ƿ�ΪС��,1Ϊ��,0Ϊ��
	if(a)
	{
		while (1)
		{                                                            
			int tor = Randnum(1, 20);			//����
			int den = Randnum((tor / r) + 1, tor + 20);		//��ĸ
			if ((tor % den == 0)|| den == 1)			//ȥ�����ɷ���/��ĸ==���������
			{
				continue;
			}

			//cout << tor << "-->" << den << "-------------->" << tor % den << endl;
			int gcd = Gcd(tor, den);
			tor = tor / gcd;
			den = den / gcd;
			//cout << tor << "-->" << den << "-------------->" << tor % den<< endl << endl;

			num = ChangeToString(tor, den);         //С��ת��Ϊ�ַ���
			break;
		}
	}
	else
	{
		if (mark)
		{
			a = Randnum(0, r - 1);		//����0��r-1�����һ������
		}
		else
		{
			a = Randnum(1, r - 1);
		}
		num = numtostring(a);

	}

	return num;
}


string Prooper(bool &mark,bool &divs)    //����һ�������
{
	string ch;
	int sym;
	if (divs)
	{
		sym = Randnum(1, 4);		//����һ�����֣�1��2��3��4�ֱ��ʾ+ - * /����
	}
	else
	{
		sym = Randnum(1, 3);		//����һ�����֣�1��2��3�ֱ��ʾ+ - *����
	}
	switch (sym)
	{
	case 1: {
		ch = "+ ";
		mark = true;
		break;
	}
	case 2: {
		ch = "- ";
		mark = true;
		break;
	}
	case 3: {
		ch = "* ";
		mark = true;
		break;
	}
	case 4: {
		ch = "/ ";
		mark = false;
		divs = false;
		break;
	}
	default:
		break;
	}
	return ch;

}

string Numandoper(int oper, int bra,int r)//���ɾ������ֺ�������Լ����� oper������� bra������ oper+1������
{
	string pro;
	bool mark = true;    //��¼��һ�������Ƿ�Ϊ/����ֹ��ĸΪ0��Ĭ����һ�����㲻��/
	bool divs = true;		//�������һ�����ţ��������̫���鷳
	if (bra == 0)			//����������
	{
		pro += pronum(r,mark) + ' ';          //����һ������,r��Χ
		
		while (oper--)
		{
			pro += Prooper(mark,divs);				//����һ�������
			pro += pronum(r,mark) + ' ';          //����һ������,r��Χ
		}

	}
	else if (bra == 1)				//����һ������
	{
		int index_l = Randnum(1, oper);			//�жϸ�����������ʲôλ��
		int index_r = Randnum(index_l + 1, oper + 1);		//�����������������Ź���������λ��
		int beginpro = 1;	//��ʼ������Ŀ
		while (beginpro <= oper)
		{
			if (index_l == beginpro)		//����������
			{
				pro += '(';
			}
			pro += pronum(r, mark);			//����һ������
			if (index_r == beginpro)		//����������
			{
				pro += ") ";
			}
			else
			{
				pro += ' ';
			}
			pro += Prooper(mark, divs);				//����һ�������
			beginpro++;
		}
		//��ѭ������Ҫ��һ������
		if (index_l == beginpro)		//����������
		{
			pro += '(';
		}
		pro += pronum(r, mark);			//����һ������
		if (index_r == beginpro)		//����������
		{
			pro += ") ";
		}
		else
		{
			pro += ' ';
		}

	}
	else                  //������������,�������ֻ��Ϊ3�������ʱ�������Ų�������  Ϊ�������bug�������˺ܶ������
	{
		int index_l = Randnum(1,2);			//������λ��1
		int index_ls = Randnum(2,3);			//������λ��2
		int index_r = index_ls==3 ? 4 : Randnum(3, 4);	//������λ��1
		int index_rs = Randnum(index_r, 4);	//������λ��2
		int beginpro = 1;	//��ʼ������Ŀ
		while (beginpro <= oper)
		{
			if (index_l == beginpro|| index_ls == beginpro)		//����������
			{
				if (index_l == index_ls)
				{
					pro += "(( ";
				}
				else
				{
					pro += '(';
				}
				
			}
			pro += pronum(r, mark);			//����һ������
			if (index_r == beginpro|| index_rs == beginpro)		//����������
			{
				if (index_r == index_rs)
				{
					pro += ")) ";
				}
				else
				{
					pro += ") ";
				}
			}
			else
			{
				pro += ' ';
			}
			pro += Prooper(mark, divs);				//����һ�������
			beginpro++;
		}
		//��ѭ������Ҫ��һ������
		if (index_l == beginpro || index_ls == beginpro)		//����������
		{
			if (index_l == index_ls)
			{
				pro += "(( ";
			}
			else
			{
				pro += '(';
			}
		}
		pro += pronum(r, mark);			//����һ������
		if (index_r == beginpro || index_rs == beginpro)		//����������
		{
			if (index_r == index_rs)
			{
				pro += ")) ";
			}
			else
			{
				pro += ") ";
			}
		}
		else
		{
			pro += ' ';
		}
	}

	return pro;
}

int ChangeTosum1(string s)					//ת��Ϊһ������
{
	int num = 0;
	for (int i = 0; i < s.length(); i++)
	{
		num = num * 10 + (s[i] - '0');
	}
	return num;
}


void ChangeTosum2(string s, int& a, int& b)    //С��ת��������
{

	int n1 = -1, n2 = -1, n3 = -1;
	string a1[4];
	int index_ = 0;
	for (int i = 0; i < s.length(); i++)
	{
		string a2;
		for (int j = i; j < s.length(); j++)
		{
			if (s[j] == '\'')
			{

				n1 = ChangeTosum1(a2);   //�������'ǰ����


				i = j;
				break;
			}
			else if (s[j] == '/')
			{
				n2 = ChangeTosum1(a2);			//��������ķ���
				i = j;
				break;
			}
			else if (j == s.length() - 1)
			{
				a2 += s[j];
				n3 = ChangeTosum1(a2);			//��������ķ�ĸ
				i = j;
				break;
			}
			a2 += s[j];
		}
		
	}
	if (n1 != -1)
	{
		n2 = n1 * n3 + n2;
		
	}
	
	a = n2;
	b = n3;

	return;
}

string ReaCount(string count,int upmul[],int mul[])
{
	stack<char> ms;
	string beh;
	int num = 0;
	for (int i = 0; i < count.length(); i++)			// ת�ɺ�׺���ʽ
	{
		if (count[i] <= '9' && count[i] >= '0')// �Ĵ������±�
		{
			beh += (num + 48);
			num++;

			for (int j = i+1; j < count.length(); j++)
			{
				if (count[j] >'9' || count[j] < '0')   //������
				{
					
					i = j - 1;
					break;
				}
				if (j == count.length() - 1)
				{
					i = j;
				}
			}
		}
		else if (count[i]=='(')
		{
			ms.push(count[i]);
		}
		else if (count[i] == ')')
		{
			while (ms.top() != '(')    //����ֱ��������
			{
				beh += ms.top();
				ms.pop();
			}
			ms.pop();      //����������
		}
		else if (count[i] == '+' || count[i] == '-' || count[i] == '*' || count[i] == '/')
		{
			if (ms.empty())
			{
				ms.push(count[i]);
			}
			else if (count[i] == '+' || count[i] == '-')
			{
				while (!ms.empty()&&ms.top()!='(')
				{

					beh += ms.top();
					ms.pop();
				}
				ms.push(count[i]);
			}
			else            //'*'  '/'�����
			{
				while (!ms.empty()&&ms.top()!='+'&&ms.top()!='-'&& ms.top() != '(')   
				{

					beh += ms.top();
					ms.pop();
				}
				ms.push(count[i]);

			}
		}
	}
	while (!ms.empty())		//ջ���ܷǿգ���ʣ������Ԫ���͸����ʽ
	{
		beh += ms.top();
		ms.pop();
	}

	stack<pair<int, int>> countnum;       //��һ��������ֵ �ڶ����� ������ΪС�� ���ĸ �����0
	for (int i = 0; i < beh.length(); i++)     
	{
		if (beh[i] <= '9' && beh[i] >= '0')
		{
			int index = beh[i]-48;   //�����±�
			countnum.push({ upmul[index] , mul[index]});        //�������ȥ
		}
		else
		{
			int b = countnum.top().first;   //�ڶ�����ջ
			int b2 = countnum.top().second;		//�����ķ�ĸ
			countnum.pop();
			int a = countnum.top().first;
			int a2 = countnum.top().second;		//�����ķ�ĸ
			countnum.pop();


			switch (beh[i])
			{
			case('+'):
			{	
				a = a * b2;			//����˷�ĸ
				b = b * a2;
				int c = a2 * b2;     //��ĸ��Ϊһ��
				{
					countnum.push({ b + a ,c});
				}
				break;
			}
			case('-'):
			{
				a = a * b2;			//����˷�ĸ
				b = b * a2;
				if (a - b < 0)							//��֤������̲����ָ���
				{
					return "-1";
				}
				int c = a2 * b2;     //��ĸ��Ϊһ��
				{
					countnum.push({ a - b ,c });
				}
				break;
			}
			case('*'):
			{
				int c = a2 * b2;     //��ĸ��Ϊһ��
				countnum.push({ b * a ,c });
				break;
			}
			case('/'):				//��Ҫ��/��������Է�ĸ
			{
				b = b * a2;
				a = a * b2;
				countnum.push({a,b});  
				break;
			}
			}
		}
	}
	string ans;
	if (countnum.top().second!=1)
	{
		if (countnum.top().first % countnum.top().second == 0)
		{
			ans = numtostring(countnum.top().first/ countnum.top().second);
		}
		else
		{
			int a = Gcd(countnum.top().first, countnum.top().second);
			ans = ChangeToString(countnum.top().first/a, countnum.top().second / a);          //С��ת��Ϊ�ַ���
		}
		
	}
	else
	{
		ans = numtostring(countnum.top().first);       //һ������ת��Ϊ�ַ���
	}
	
	return ans;
}

string Count(string s)			//�����ʽת��Ϊȫ��Ϊ����������   ������Ŀֵ
{
	string count;
	int mul[4];       //���ĸ
	int upmul[4];     //����
	int index_mul = 0;		//��ĸ����
	int index_num = 0;		//�����ĸ���
	for(int i = 0; i < s.length(); i++)
	{
		if (s[i] == '(' || s[i] == ')' || s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/')
		{
			count += s[i];
		}
		else if (s[i] == ' ')  //����=��
		{
			continue;
		}
		else
		{
			bool flag = false;   //����Ƿ�ΪС��
			string thenum;
			for (int j = i; j < s.length(); j++)
			{
				if (s[j] == ')')
				{
					i = j - 1;
					break;
				}
				if (s[j] == ' ')
				{
					i = j;
					break;
				}
				if (s[j] == '/')
				{
					flag = true;
				}
				thenum += s[j];
				
				
			}
			if (flag)					//����ΪС��
			{
				int a, b;				//�� ����
				ChangeTosum2(thenum,a,b);			//С��ת��Ϊint

				upmul[index_num++] = a;        //��������

				mul[index_num-1] = b;			//����÷�ĸ  �������±�

				count += numtostring(a);       //һ������ת��Ϊ�ַ��� ���ȥ
			}
			else
			{
				upmul[index_num++] = ChangeTosum1(thenum);			//����ת��Ϊint
				mul[index_num - 1] = 1;			//��ĸĬ��Ϊ1
				count += thenum;				//��������ȥ
			}
			

		}
	}
	return ReaCount(count, upmul,mul);




}

void Proproblems(int n,int r,ofstream &fout,ofstream &foutans)//����n��r��Χ�ڵ���
{
	for (int i = 1; i <= n; i++)
	{
		string problems;
		int oper = Randnum(1,3);	//���������			//��������������������,����������
		int bra = (oper >= 2) ? Randnum(0,oper-1) : 0;//�Ƿ���������,����������������п�����������,����û����
		if (bra == 2 && (oper != 3))
		{
			i--;
			continue;
		}
		problems = Numandoper(oper, bra,r);              //����һ����Ŀ
		string ans = Count(problems);				//�����ʽת��Ϊȫ��Ϊ����������   ������Ŀֵ
		if (ans == "-1")				//�ж���;�Ƿ���ָ���  �� ��ȥ������
		{
			i--;
			continue;
		}
		fout << i << '.' << problems << '=' << endl;
		foutans << i << '.' << ans << endl;
	}

}

string Getproblems(string buf)				//����Ŀ�ļ���ȡ��Ŀ
{
	int head, tail = buf.length()-2;
	string ans;
	for (int i = 0; i < buf.length(); i++)
	{
		if (buf[i] == '.')
		{
			head = i + 1;
			break;
		}
	}
	for (int i = head; i <= tail; i++)
	{
		ans += buf[i];
	}
	return ans;
}

string Getans(string buf)					//ȥ���𰸵�ǰ׺
{
	int head;
	string ans;
	for (int i = 0; i < buf.length(); i++)
	{
		if (buf[i] == '.')
		{
			head = i + 1;
			break;
		}
	}
	for (int i = head; i < buf.length(); i++)
	{
		ans += buf[i];
	}
	return ans;
}

void Check()
{
	printf("��������Ŀ�ļ�����·��:\n");
	string road;
	cin >> road;
	ifstream lookpro;

	printf("��������ļ�����·��:\n");
	string ansroad;
	cin >> ansroad;
	ifstream lookans;

	lookpro.open(road, ios::in);			//���ļ�
	lookans.open(ansroad, ios::in);			//���ļ�

	vector<int> cor;			//��ȷ��
	vector<int> wor;			//�����
	int corsum = 0;				//��ȷ�𰸸���
	int worsum = 0;				//����𰸸���
	if (lookpro.is_open())
	{
		string buf;
		string proans;
		int no_ = 1;
		while (getline(lookpro, buf))
		{
			string problems = Getproblems(buf);
			string ans = Count(problems);				//�����
			getline(lookans, proans);				//��ȡһ����
			string theans = Getans(proans);			//��ȡ�ļ��𰸣�ȥ��ǰ׺��
			if (ans == theans)					//����ͬ
			{
				corsum++;							//��ȷ�𰸸���
				cor.push_back(no_++);				//��ȷ�����
			}
			else
			{
				worsum++;
				wor.push_back(no_++);
			}


		}
		
	}
	else
	{
		cout << "�ļ���ʧ��" << endl;
	}
	
	if (corsum != 0 || worsum != 0)		//���ļ��ɹ�
	{
		ofstream coutans("Grade.txt");
		coutans << "Correct:" << corsum << '(';
		for (auto x : cor)
		{
			coutans << x;
			if (--corsum)
			{
				coutans << ',';
			}
		}
		coutans << ')' << endl;

		coutans << "Wrong:" << worsum << '(';
		for (auto x : wor)
		{
			coutans << x;
			if (--worsum)
			{
				coutans << ',';
			}
		}
		coutans << ')' << endl;
	}




	lookans.close();
	lookpro.close();
}

int main()
{
	srand(time(0));

	printf("��ѡ����Ҫʹ�õĹ���\n");
	printf("1.������Ŀ�ʹ�\n");
	printf("2.�����ļ���\n\n");
	int choice;
	while (cin >> choice)
	{
		if (choice == 1 || choice == 2)
		{
			break;
		}
		else
		{
			printf("��������ȷ��Ŀ\n");
		}
	}
	if (choice == 1)
	{
		int n;
		printf("��������Ҫ������Ŀ�ĸ���:\n");
		cin >> n;
		double r1;
		printf("��������Ŀ��ֵ�ķ�Χr(��Ȼ��[0-r)):\n");
		while (cin >> r1)
		{
			int r = r1;
			if (r1 <= 0)
			{
				printf("������ķ�Χ��С������������\n");
			}
			else if (r != r1)
			{
				printf("���������0����Ȼ��\n");
			}
			else
			{
				break;
			}
		}
		int r = r1;
		ofstream foutpro("Exercises.txt");
		ofstream foutans("Answers.txt");
		Proproblems(n, r, foutpro, foutans);			//����������
		foutpro.close();
		foutans.close();
		printf("��Ŀ�ʹ��������ڶ�Ӧ�ļ�:\n");
	}
	else
	{
		Check();
		printf("���Ľ���Ѿ���ӡ����Ӧ�ļ�\n");
	}


	

	return 0;
}