#include "stdafx.h"
#include "TString.h"

	//Method SIZE//
	int TString::Size(char* str)
	{
		int len = 0;
		for (int i = 0; str[i] != 0; i++)
		{
			len++;
		}

		return len;
	}
	// Method PRINT//
	void TString::Print()
	{
		std::cout << str << std::endl;
	}
	//default ctor//
	TString::TString()
	{
		char* strdef = "Default String";
		str = new char[Size(strdef) + 1];
		Strcpy(str, strdef);
	}
	//user ctor char*//
	TString::TString(char * str1)
	{
		str = new char[Size(str1) + 1];
		Strcpy(str, str1);

	}
	//copy ctor//
	TString::TString(const TString& object)

	{
		str = new char[Size(object.str) + 1];
		Strcpy(str, object.str);
	}

	//dtor//
	TString::~TString()
	{
		delete[] str;
	}
	TString& TString:: operator=(const TString& object)
	{
		if (this != &object)
		{
			delete[]str;
			str = new char[Size(object.str) + 1];
			strcpy(str, object.str);
		}
		else
		{
			std::cout << "Self Assignment" << std::endl;;
		}
		return *this;
	}
	TString& TString::operator+=(const TString& object)
	{
		int size = Size(this->str);
		char * str_t = new char[Size(this->str)];

		for (int i = 0; i < Size(str_t); i++)
		{
			str_t[i] = this->str[i];
		}

		delete this->str;
		this->str = new char[Size(str_t) + Size(object.str)];
		this->str[Size(str_t) + Size(object.str)] = '\0';
		for (int i = 0; i < Size(str_t); i++)
		{
			this->str[i] = str_t[i];
		}
		for (int j = 0; j < Size(object.str); j++)
		{
			this->str[size + j] = object.str[j];
		}
		return *this;
	}
	bool TString::operator ==(const TString& object)
	{
		for (int i = 0; i < Size(this->str); i++)
		{
			if (this->str[i] != object.str[i])
			{
				return false;
			}
		}
		return true;
	}
	bool TString::operator != (const TString & object)
	{
		int a = 0;
		if (this->str[0] == object.str[0])
		{
			return false;
		}
		else
		{
			for (int i = 0; i < Size(this->str); i++)
			{
				if (this->str[i] == object.str[i])
				{
					a++;
				}
			}

		}
		if (a == Size(this->str))
		{
			return false;
		}
		else
		{
			return true;
		}
	}
	bool TString::operator < (const TString& object)
	{
		return(Size(this->str) < Size(object.str) ? true : false);
	}
	bool TString::operator > (const TString& object)
	{
		return(Size(this->str) > Size(object.str) ? true : false);
	}
	char TString::operator[](size_t index)
	{
		if (index > Size(this->str) || index == 0)
		{
			std::cout << "Error";
			return 0;
		}
		else
		{
			std::cout << "\n You want to found " << index << " symbol in this string: " << this->str << "\n Founded Symbol: ";
			return this->str[index - 1];
		}

	}
	//Replace func
	void TString::Replace(char oldSym, char newSym)
	{
		for (int i = 0; i < Size(this->str); i++)
		{
			if (this->str[i] == oldSym)
			{

				str[i] = newSym;
			}
		}
	}
	bool TString::Empty()
	{
			if (this->str != "")
			{
				std::cout << "Not empty" << std::endl;
				return false;
			}
			else
			{
				std::cout << "Empty" << std::endl;
				return true;
			}
	}
	//TRIMS
	void TString::Ltrim(char symbol)
	{

		bool find = false;
		int a = 0;
		char * str_new = new char[Size(this->str)];
		int i = 0;



		for (int i = 0; i < Size(this->str); i++)
		{
			if (this->str[i] == symbol)
			{
				a++;
			}
			else
			{
				break;

			}
		}
		int c = a;
		for (int i = 0; i < Size(this->str) - c; a++, i++)
		{
			str_new[i] = this->str[a];
		}

		str_new[Size(this->str) - c] = '\0';
		this->str = str_new;
	}
	void TString::Rtrim(char symbol)
	{
		int size = Size(this->str);
		int a = 0;
		for (int i = 0; i < size + 1; i++)
		{
			int j = size - i;
			if (this->str[j] != symbol)
			{
				a++;
				str[j + 1] = '\0';
				if (a == 2)
				{
					break;
				}
			}

		}
	}
	//Find func
	int TString::Find(const TString& object)
	{
		int ret = 0;;
		int check = 0;
		for (int i = 0; i < Size(this->str); i++)
		{
			if (this->str[i] == object.str[0])
			{
				check++;
				ret = i;
				for (int j = 1; j < Size(object.str); j++)
				{
					i++;
					if (this->str[i] == object.str[j])
					{
						check++;
					}
					else
					{
						check = 0;
						break;
					}
				}
			}
		}
		if (check == Size(object.str))
		{
			return ret;
		}
		else
		{
			return -1;
		}

	}
	char* TString::Strcpy(char*d, const char* s)
	{
		char* start = d;
		while (*d++ = *s++)
		{
		}
		return start;
	}
	std::ostream & operator<<(std::ostream &out, const TString & object)
	{
		out << object.str;
		return out;
	}
