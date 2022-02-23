#include <map>
#include <iostream>
#include <stack>
#include <string>
using namespace std;

int pri(char ch) // ���ȼ��ж�
{
	if (ch == '+' || ch == '-') return 2;
	else return 1;
}
float trans_F(string s) // �ַ���ת������
{
	float ans = 0;
	int len = s.length();
	int index = 0;
	while (index < len)
	{
		if (s[index] == '.')
		{
			ans += (s[index + 1] - '0') / 10.0;
			return ans;
		}
		else ans = ans * 10 + (s[index]-'0');
		index++;
	}
	return ans;
}
string trans_S(string s) // �ַ�����ʽ������������һλС��
{
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] == '.') return s.substr(0, i+2);
	}
	return s;
}
float cal_tool(float num1, float num2, char ch) // ΢�ͼ��㵥Ԫ
{
	if (ch == '+')return num1 + num2;
	if (ch == '-')return num1 - num2;
	if (ch == '/')return num1 / num2;
	if (ch == '*')return num1 * num2;
}
string check(string expression) // Բ���ż��
{
	int count = 0;
	for (int i = 0; i < expression.size(); i++)
	{
		if (expression[i] == '(')count++;
		else if (expression[i] == ')')count--;
	}
	if (count == 0)
	{
		return expression + "#";
	}
	return "False";
}
string trans_RPN(string expression) // ��׺ת��׺
{
	string ans = "";
	stack<char>  p;
	int index = 0;
	char ch = expression[index];
	do {
		index++;
		if (ch <= '9' && ch >= '0' || ch == '.') ans += ch; // ��������С����
		else if (ch == '(') p.push('('); // ������
		else if (ch == ')') // ������
		{
			while (p.top() != '(')
			{
				ans += p.top();
				p.pop();
			}
			p.pop();
		}
		else // �����
		{
			ans += " ";
			while (true)
			{
				if (p.empty() || p.top() == '(' || pri(ch) < pri(p.top()))
				{
					p.push(ch);
					break;
				}
				else
				{
					ans += p.top();
					p.pop();
				}
			}
		}
		ch = expression[index];
	} while (ch != '#');
	while (!p.empty()) {
		ans += p.top();
		p.pop();
	}
	ans += "#";
	return ans;
}
string calculator(string expression)
{
	stack<float> num; // ����ջ
	int index = 0;
	string nums = "";
	char next_ch = ' ';
	char ch = expression[index];
	do 
	{
		index++;
		if (ch <= '9' && ch >= '0' || ch=='.') // �ж�Ϊ����
		{
			nums = "";
			if (ch == '.')nums = "0.";
			nums += ch;
			next_ch = expression[index];
			while (next_ch == '.' || next_ch >= '0' && next_ch <= '9')
			{
				ch = expression[index++];
				nums += ch;
				next_ch = expression[index];
			}
			num.push(trans_F(nums));
		}
		else if (ch == '+' || ch == '-' || ch == '*' || ch == '/')
		{
			float num1 = 0;
			float num2 = 0;
			num2 = num.top();
			num.pop();
			if (num.empty()) // ����ȱ�����
			{
				if (ch == '-')
				{
					num1 = 0;
				}
				else return "���������";
			}
			num1 = num.top();
			num.pop();
			if (ch == '/' && num2 == 0) return "�������";
			num.push(cal_tool(num1,num2,ch));
		}
		ch = expression[index];
	} while (ch!='#');
	float ans = num.top();
	num.pop();
	if (num.empty())return trans_S(to_string(ans));
	else return "����������";
}
string solve(string expression) // ����ӿ�
{
	string s = check(expression);
	if (s=="False")return "Բ����ƥ�����";
	else return calculator(trans_RPN(s));
}
/*
string calculator(string expression) // ��׺��ʽ���ʽ��ֵ
{
	// �ú������޸ģ�Ŀǰ˼·��дһ����ֺ�����һ��������
	float num1 = 0;
	float num2 = 0;
	int index = 0;
	bool flag = true; // ��Ǳ��ʽ�Ƿ�Ϸ�
	string wrong = ""; // �Ƿ���Ϣ
	char ch = expression[index];
	if (ch <= '9' && ch >= '0') // ������һ�����֣�����num1
	{
		float num1 = ch - '0';
		int num = 0;
		char next_ch = expression[++index];
		while (next_ch != ' ' && next_ch != '#') // ֱ����һ������
		{
			if (next_ch == '.') // �ж���һ����С���㣬�������Ǹ�����
			{
				num = expression[++index] - '0';
				num1 += num / 10.0;
				break;
			}
			else if (next_ch <= '9' && next_ch >= '0')
			{
				num = next_ch - '0';
				num1 = num1 * 10 + num;
			}
			next_ch = expression[index++];
		}
	}
	while (expression[index] == ' ')index++;
	ch = expression[index];
	while (ch != '#') // ��ѭ��
	{
		index++;
		if (ch == '-') num1 = -num1;
		else if (ch <= '9' && ch >= '0')
		{
			float num2 = ch - '0';
			int num = 0;
			char next_ch = expression[index++];
			while (next_ch != ' ' && next_ch != '#') // ֱ����һ������
			{
				num = next_ch - '0';
				if (next_ch == '.') // �ж���һ����С���㣬�������Ǹ�����
				{
					num2 += num / 10.0;
				}
				else if (next_ch <= '9' && next_ch >= '0')
				{
					num2 = num2 * 10 + num;
				}
				next_ch = expression[index++];
			}
		}
		else
		{
			flag = false;
			wrong = "������ʹ�ô���";
			break;
		}
		while (expression[index] == ' ')index++;
		if (ch == '-') num1 -= num2;
		else if (ch == '+') num1 += num2;
		else if (ch == '/')
		{
			if (num2 == 0)
			{
				flag = false;
				wrong = "�������";
				break;
			}
			else num1 /= num2;
		}
		else if (ch == '*') num1 *= num2;
		ch = expression[index];
	}
	if (!flag) return wrong;
	return to_string(num1);
}
*/
