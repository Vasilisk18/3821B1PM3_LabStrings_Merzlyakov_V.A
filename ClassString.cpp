#include "ClassString.h"
#include<iostream>

classString::classString()
{
	len = 0;
	str = nullptr;
}

classString::classString(int _len, char _str)
{
	int q = 0;

	if (str == nullptr)
	{
		delete[] str;
		len = 0;
	}
	if (_len > 0)
	{
		str = new char[_len + 1];
		str[_len ] = '\0';
		for ( q = 0; q < _len; q++)
			str[q] = _str;
		
	}
	if(str != nullptr) len = (int)strlen(str);
}

classString::classString(const classString& c)
{
	int q = 0;

	if (c.len <= 0) std::cout << "f" << std::endl;
	else if (c.len > 0 && c.str != nullptr)
	{
		len = c.len;

		if (str != nullptr) delete[] str;
		str = new char[len + 1];

		for ( q = 0; q < len; q++)
		{
			str[q] = c.str[q];
		}

	}
	
	str[len] = '\0';
}

int classString::GetLength()
{
	return len;
}

void classString::SetLength(int _len)
{
	len = _len;
}

void classString::SetString(char* _str)
{
	int TemporaryLength = 0;
	if (_str == nullptr) throw "Error in SetString func. Your string = nullptr";

	if (str != nullptr) delete[] str;
	str = new char[strlen(_str) + 1];
	str[strlen(_str)] = '\0';

	for (int q = 0; q < strlen(_str); q++)
	{
		str[q] = _str[q];
	}

	len = (int)strlen(_str);
}

void classString::SetConstString(const char* _str)
{
	int TemporaryLength = 0;
	if (_str == nullptr) throw "Error in SetString func. Your string = nullptr";

	if (str != nullptr) delete[] str;

	str = new char[strlen(_str) + 1];
	str[strlen(_str)] = '\0';

	for (int q = 0; q < strlen(_str); q++)
	{
		str[q] = _str[q];
	}

	len = (int)strlen(_str);
}

classString::~classString()
{
	if (str != nullptr) delete[] str;
}

char* classString::GetString()
{
	return str;
}

int classString::FindFirstSymb(char symbol)
{
	if (str == nullptr) return -1;
	
	for (int q = 0; q < strlen(str); q++)
	{
		if (str[q] == symbol) return q;
	}

	return -1;
}

void classString::FindSub(char symbol)
{
char* str_res = nullptr;
int k=1;
	for (int q = 0; q < strlen(str); q++)
	{
		if (str[q] != symbol) 
		{
		cout << str[q];
		}
		else 
		{
			cout << " ->" << k << " Под слово" << endl;
			k++;
		}

	}
	cout << " ->" << k << " Под слово" << endl;
delete[] str_res;
}



int classString::FindFirstWord(char* _str)
{
	bool flag;

	if (_str == nullptr) return -1;

	for (int q = 0; q < strlen(str); q++)
	{
		if (_str[0] == str[q])
		{
			flag = true;

			for (int w = 1; w < strlen(_str); w++)
			{
				if (_str[w] != str[q+w]) flag = false;
			}

			if (flag == true) return q;
		}

	}

return -1;   
}

char& classString::operator[](int i)
{
	char q = 3;

	if (len > 0 && str != nullptr && (i >= 0 && i < len))
	{
		return str[i];
	}
	else

		return q;
}

bool classString::operator==(const classString& c)
{
	int tmplen = strlen(str);
	int _tmplen = strlen(c.str);

	if (tmplen != _tmplen) return false;
	else
	{
		for (int q = 0; q < tmplen; q++)
		{
			if (str[q] != c.str[q]) return false;
		}
	}

	return true;
}
classString& classString::operator = (const classString& c)
{
	if (c.str != nullptr)
	{
		len = strlen(c.str);

		if (str == nullptr) delete[] str;
		str = new char[len + 1];
		str[len] = '\0';

		for (int q = 0; q < len; q++)
		{
			str[q] = c.str[q];
		}
	}

	return *this;
}

bool classString::operator < (const classString& c)
{
	int tmplen1 = 0;
	int tmplen2 = 0;

	if (c.str == nullptr && str == nullptr) throw "Exception in operator <";
	else
	{
		tmplen1 = strlen(str);
		tmplen2 = strlen(c.str);

		if (tmplen2 < tmplen1) tmplen2 = tmplen1;

		for (int q = 0; q < tmplen1; q++)
		{
			if (str[q] >= c.str[q]) return false;
		}

	}

	return true;
}

bool classString::operator > (const classString& c)
{
	int tmplen1 = 0;
	int tmplen2 = 0;

	if (c.str == nullptr && str == nullptr) throw "Exception in operator <";
	else
	{
		tmplen1 = strlen(str);
		tmplen2 = strlen(c.str);

		if (tmplen2 < tmplen1) tmplen2 = tmplen1;

		for (int q = 0; q < tmplen1; q++)
		{
			if (str[q] <= c.str[q]) return false;
		}

	}

	return true;
}

classString classString::operator + (const classString& c)
{
	int tmpLen = 0; int c_tmpLen = 0;
	classString result(*this);

	if (str == nullptr) throw "string of first object = nullptr";
	if (c.str == nullptr) throw "string of second object = nullptr";

	if (result.str == nullptr) delete[] result.str;

	result.str = new char[strlen(str) + strlen(c.str) + 1];
	result.str[strlen(str) + strlen(c.str)] = '\0';
	tmpLen = strlen(str);
	c_tmpLen = strlen(c.str);

	for (int i = 0; i < tmpLen; i++)
	{
		result.str[i] = str[i];
	}

	for (int i = 0; i < c_tmpLen; i++)
	{
		result.str[tmpLen + i] = c.str[i];
	}

	result.len = strlen(result.str);
	return result;

}

std::istream& operator>>(std::istream& Stream, classString& c)
{
	int i = 0;
	char tmp = 0;

	if (c.str != nullptr) delete[] c.str;

	char* tmpstring = nullptr;
	tmpstring = new char[255];

	for (int a = 0; a < 255; a++)
	{
		tmpstring[a] = '\0';
	}

	while (tmp != '0')
	{
		Stream >> tmp;
		tmpstring[i] = tmp;
		i++;
	}

	c.str = new char[strlen(tmpstring)];
	c.str[strlen(tmpstring) - 1] = '\0';

	for (int q = 0; q < strlen(tmpstring) - 1; q++)
		c.str[q] = tmpstring[q];

	c.len = strlen(c.str);
	delete[] tmpstring;
	tmpstring = nullptr;

	return Stream;

}

std::ostream& operator<<(std::ostream& Stream, const classString& c)
{
	for (int q = 0; q < strlen(c.str); q++)
	{
		Stream << c.str[q];
	}
	Stream << '\n';
	return Stream;

}

classString& classString::duplication(int count)
{
	char* TemporaryStr = new char[strlen(str) * count + 1];
	TemporaryStr[strlen(str) * count] = '\0';
	for (int q = 0; q < strlen(str) * count; q = q + 3)
	{
		for (int i = 0; i < strlen(str); i++)
		{
			TemporaryStr[q+1] = str[i];
		}
	}
	delete[] str;
	str = TemporaryStr;
	return *this;
}