#include<cstdlib>
#include<iostream>
#include<string>
#include<algorithm>
#include<stack>
#include<stdio.h>
#include<fstream>
#include<vector>
using namespace std;

int Randnum(int minnum, int maxnum)//产生[a,b]的随机整数
{
	return (rand() % (maxnum - minnum + 1)) + minnum;
}

string numtostring(int a)       //一个整数转变为字符串
{
	string num;
	while (a >= 10)				//从最后一位取字符
	{
		int b = a % 10;
		a = a / 10;
		num = num + (char)(b + 48);
	}
	int b = a % 10;
	num = num + (char)(b + 48);
	reverse(num.begin(),num.end());				//反转字符
	return num;
}

string ChangeToString(int tor, int den)          //小数转化为字符串   分子分母已经约分
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
		int a = tor / den;       //表达式前面的数字
		int b = tor % den;			//表达式的分子

		ans = ans + numtostring(a) + '\'' + numtostring(b) + '/' + numtostring(den);
	}
	return ans;
}

int Gcd(int a, int b)		//求最大公因数
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

string pronum(int r,bool mark)	//生成一个数字,r范围 mark表示该数字是否可以为0
{
	string num;
	int a;			 //用于判断生成什么数
	a = Randnum(0, 1);     //a是否为小数,1为是,0为否
	if(a)
	{
		while (1)
		{                                                            
			int tor = Randnum(1, 20);			//分子
			int den = Randnum((tor / r) + 1, tor + 20);		//分母
			if ((tor % den == 0)|| den == 1)			//去除生成分子/分母==整数的情况
			{
				continue;
			}

			//cout << tor << "-->" << den << "-------------->" << tor % den << endl;
			int gcd = Gcd(tor, den);
			tor = tor / gcd;
			den = den / gcd;
			//cout << tor << "-->" << den << "-------------->" << tor % den<< endl << endl;

			num = ChangeToString(tor, den);         //小数转化为字符串
			break;
		}
	}
	else
	{
		if (mark)
		{
			a = Randnum(0, r - 1);		//生成0到r-1内随机一个整数
		}
		else
		{
			a = Randnum(1, r - 1);
		}
		num = numtostring(a);

	}

	return num;
}


string Prooper(bool &mark,bool &divs)    //生成一个运算符
{
	string ch;
	int sym;
	if (divs)
	{
		sym = Randnum(1, 4);		//生成一个数字，1，2，3，4分别表示+ - * /符号
	}
	else
	{
		sym = Randnum(1, 3);		//生成一个数字，1，2，3分别表示+ - *符号
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

string Numandoper(int oper, int bra,int r)//生成具体数字和运算符以及括号 oper个运算符 bra个括号 oper+1个数字
{
	string pro;
	bool mark = true;    //记录上一个运算是否为/，防止分母为0，默认上一个运算不是/
	bool divs = true;		//最多生成一个除号，多个除号太过麻烦
	if (bra == 0)			//不生成括号
	{
		pro += pronum(r,mark) + ' ';          //生成一个数字,r范围
		
		while (oper--)
		{
			pro += Prooper(mark,divs);				//生成一个运算符
			pro += pronum(r,mark) + ' ';          //生成一个数字,r范围
		}

	}
	else if (bra == 1)				//生成一个括号
	{
		int index_l = Randnum(1, oper);			//判断该左括号落在什么位置
		int index_r = Randnum(index_l + 1, oper + 1);		//右括号至少在左括号过两个数的位置
		int beginpro = 1;	//开始生成题目
		while (beginpro <= oper)
		{
			if (index_l == beginpro)		//生成左括号
			{
				pro += '(';
			}
			pro += pronum(r, mark);			//生成一个数字
			if (index_r == beginpro)		//生成右括号
			{
				pro += ") ";
			}
			else
			{
				pro += ' ';
			}
			pro += Prooper(mark, divs);				//生成一个运算符
			beginpro++;
		}
		//出循环还需要加一个数字
		if (index_l == beginpro)		//生成左括号
		{
			pro += '(';
		}
		pro += pronum(r, mark);			//生成一个数字
		if (index_r == beginpro)		//生成右括号
		{
			pro += ") ";
		}
		else
		{
			pro += ' ';
		}

	}
	else                  //生成两个括号,该种情况只有为3个运算符时所有括号才有意义  为避免出现bug，减少了很多种情况
	{
		int index_l = Randnum(1,2);			//左括号位置1
		int index_ls = Randnum(2,3);			//左括号位置2
		int index_r = index_ls==3 ? 4 : Randnum(3, 4);	//右括号位置1
		int index_rs = Randnum(index_r, 4);	//右括号位置2
		int beginpro = 1;	//开始生成题目
		while (beginpro <= oper)
		{
			if (index_l == beginpro|| index_ls == beginpro)		//生成左括号
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
			pro += pronum(r, mark);			//生成一个数字
			if (index_r == beginpro|| index_rs == beginpro)		//生成右括号
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
			pro += Prooper(mark, divs);				//生成一个运算符
			beginpro++;
		}
		//出循环还需要加一个数字
		if (index_l == beginpro || index_ls == beginpro)		//生成左括号
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
		pro += pronum(r, mark);			//生成一个数字
		if (index_r == beginpro || index_rs == beginpro)		//生成右括号
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

int ChangeTosum1(string s)					//转化为一个整数
{
	int num = 0;
	for (int i = 0; i < s.length(); i++)
	{
		num = num * 10 + (s[i] - '0');
	}
	return num;
}


void ChangeTosum2(string s, int& a, int& b)    //小数转化成整数
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

				n1 = ChangeTosum1(a2);   //保存分数'前的数


				i = j;
				break;
			}
			else if (s[j] == '/')
			{
				n2 = ChangeTosum1(a2);			//保存分数的分子
				i = j;
				break;
			}
			else if (j == s.length() - 1)
			{
				a2 += s[j];
				n3 = ChangeTosum1(a2);			//保存分数的分母
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
	for (int i = 0; i < count.length(); i++)			// 转成后缀表达式
	{
		if (count[i] <= '9' && count[i] >= '0')// 改存数字下标
		{
			beh += (num + 48);
			num++;

			for (int j = i+1; j < count.length(); j++)
			{
				if (count[j] >'9' || count[j] < '0')   //不是数
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
			while (ms.top() != '(')    //弹出直到左括号
			{
				beh += ms.top();
				ms.pop();
			}
			ms.pop();      //弹出左括号
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
			else            //'*'  '/'的情况
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
	while (!ms.empty())		//栈可能非空，把剩下所有元素送给表达式
	{
		beh += ms.top();
		ms.pop();
	}

	stack<pair<int, int>> countnum;       //第一个数存数值 第二个数 若该数为小数 存分母 否则存0
	for (int i = 0; i < beh.length(); i++)     
	{
		if (beh[i] <= '9' && beh[i] >= '0')
		{
			int index = beh[i]-48;   //数的下标
			countnum.push({ upmul[index] , mul[index]});        //将数存进去
		}
		else
		{
			int b = countnum.top().first;   //第二个入栈
			int b2 = countnum.top().second;		//该数的分母
			countnum.pop();
			int a = countnum.top().first;
			int a2 = countnum.top().second;		//该数的分母
			countnum.pop();


			switch (beh[i])
			{
			case('+'):
			{	
				a = a * b2;			//互相乘分母
				b = b * a2;
				int c = a2 * b2;     //分母合为一起
				{
					countnum.push({ b + a ,c});
				}
				break;
			}
			case('-'):
			{
				a = a * b2;			//互相乘分母
				b = b * a2;
				if (a - b < 0)							//保证计算过程不出现负数
				{
					return "-1";
				}
				int c = a2 * b2;     //分母合为一起
				{
					countnum.push({ a - b ,c });
				}
				break;
			}
			case('*'):
			{
				int c = a2 * b2;     //分母合为一起
				countnum.push({ b * a ,c });
				break;
			}
			case('/'):				//需要将/外的数乘以分母
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
			ans = ChangeToString(countnum.top().first/a, countnum.top().second / a);          //小数转化为字符串
		}
		
	}
	else
	{
		ans = numtostring(countnum.top().first);       //一个整数转变为字符串
	}
	
	return ans;
}

string Count(string s)			//将表达式转变为全部为整数的运算   计算题目值
{
	string count;
	int mul[4];       //存分母
	int upmul[4];     //存数
	int index_mul = 0;		//分母个数
	int index_num = 0;		//存数的个数
	for(int i = 0; i < s.length(); i++)
	{
		if (s[i] == '(' || s[i] == ')' || s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/')
		{
			count += s[i];
		}
		else if (s[i] == ' ')  //跳过=号
		{
			continue;
		}
		else
		{
			bool flag = false;   //检查是否为小数
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
			if (flag)					//该数为小数
			{
				int a, b;				//上 、下
				ChangeTosum2(thenum,a,b);			//小数转化为int

				upmul[index_num++] = a;        //整数加上

				mul[index_num-1] = b;			//存进该分母  用数的下标

				count += numtostring(a);       //一个整数转变为字符串 存进去
			}
			else
			{
				upmul[index_num++] = ChangeTosum1(thenum);			//整数转化为int
				mul[index_num - 1] = 1;			//分母默认为1
				count += thenum;				//存整数进去
			}
			

		}
	}
	return ReaCount(count, upmul,mul);




}

void Proproblems(int n,int r,ofstream &fout,ofstream &foutans)//生成n道r范围内的题
{
	for (int i = 1; i <= n; i++)
	{
		string problems;
		int oper = Randnum(1,3);	//运算符个数			//生成运算题的运算符个数,不超过三个
		int bra = (oper >= 2) ? Randnum(0,oper-1) : 0;//是否生成括号,运算符大于两个才有可能生成括号,否则没意义
		if (bra == 2 && (oper != 3))
		{
			i--;
			continue;
		}
		problems = Numandoper(oper, bra,r);              //生成一个题目
		string ans = Count(problems);				//将表达式转变为全部为整数的运算   计算题目值
		if (ans == "-1")				//判断中途是否出现负数  是 则去除该题
		{
			i--;
			continue;
		}
		fout << i << '.' << problems << '=' << endl;
		foutans << i << '.' << ans << endl;
	}

}

string Getproblems(string buf)				//从题目文件提取题目
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

string Getans(string buf)					//去除答案的前缀
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
	printf("请输入题目文件绝对路径:\n");
	string road;
	cin >> road;
	ifstream lookpro;

	printf("请输入答案文件绝对路径:\n");
	string ansroad;
	cin >> ansroad;
	ifstream lookans;

	lookpro.open(road, ios::in);			//打开文件
	lookans.open(ansroad, ios::in);			//打开文件

	vector<int> cor;			//正确答案
	vector<int> wor;			//错误答案
	int corsum = 0;				//正确答案个数
	int worsum = 0;				//错误答案个数
	if (lookpro.is_open())
	{
		string buf;
		string proans;
		int no_ = 1;
		while (getline(lookpro, buf))
		{
			string problems = Getproblems(buf);
			string ans = Count(problems);				//计算答案
			getline(lookans, proans);				//获取一个答案
			string theans = Getans(proans);			//获取文件答案（去除前缀）
			if (ans == theans)					//答案相同
			{
				corsum++;							//正确答案个数
				cor.push_back(no_++);				//正确答案题号
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
		cout << "文件打开失败" << endl;
	}
	
	if (corsum != 0 || worsum != 0)		//打开文件成功
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

	printf("请选择你要使用的功能\n");
	printf("1.生成题目和答案\n");
	printf("2.批改文件答案\n\n");
	int choice;
	while (cin >> choice)
	{
		if (choice == 1 || choice == 2)
		{
			break;
		}
		else
		{
			printf("请输入正确数目\n");
		}
	}
	if (choice == 1)
	{
		int n;
		printf("请输入你要生成题目的个数:\n");
		cin >> n;
		double r1;
		printf("请输入题目数值的范围r(自然数[0-r)):\n");
		while (cin >> r1)
		{
			int r = r1;
			if (r1 <= 0)
			{
				printf("你输入的范围过小，请重新输入\n");
			}
			else if (r != r1)
			{
				printf("请输入大于0的自然数\n");
			}
			else
			{
				break;
			}
		}
		int r = r1;
		ofstream foutpro("Exercises.txt");
		ofstream foutans("Answers.txt");
		Proproblems(n, r, foutpro, foutans);			//生成运算题
		foutpro.close();
		foutans.close();
		printf("题目和答案已生成在对应文件:\n");
	}
	else
	{
		Check();
		printf("批改结果已经打印到相应文件\n");
	}


	

	return 0;
}