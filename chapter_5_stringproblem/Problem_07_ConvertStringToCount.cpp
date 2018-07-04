#include <iostream>
#include <string>
#include <sstream>

using namespace std;

string getCountString(string str)
{
	if(str.empty())
		return "";

	string res = "";
	int num = 1;
	unsigned int i;
	for(i = 1; i < str.size(); i++)
	{
		if(str[i] != str[i-1])
		{
			stringstream ss;
			ss << num;
			string snum = ss.str();
			res += str[i-1];
			res += '_';
			res += snum;
			res += '_';
			num = 1;
		}
		else
		{
			num++;
		}
	}
	stringstream ss;
	ss << num;
	string snum = ss.str();
	res += str[i-1];
	res += '_';
	res += snum;
	return res;
}


char getCharArt(string cstr, int index)
{
	if(cstr.empty())
		return 0;

	bool stage = true;
	int num = 0;
	char cur = 0;
	int sum = 0;
	for(unsigned int i = 0; i < cstr.size(); i++)
	{
		if(cstr[i] == '_')
			stage = !stage;
		else if(stage)
		{
			sum += num;
			if(sum > index)
				return cur;
			num = 0;
			cur = cstr[i];
		}
		else
		{
			num = cstr[i] - '0';
		}
	}
	return sum + num > index ? cur : 0;
}

int main()
{
	string str = "aaabbadddffc";
	cout << str << endl;
	string res = getCountString(str);
	cout << res << endl;
	cout << getCharArt(res, 4) << endl;
	return 0;
}
