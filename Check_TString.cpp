#include "stdafx.h"
#include "iostream"
#include "TString.h"



int _tmain(int argc, _TCHAR* argv[])
{
	//objects
	TString str("Test string 1");
	std::cout << "String 1 :";
	str.Print();
	TString str2(str);
	std::cout << "String 2 :";
	str2.Print();
	//str2.Print();
	TString str3;
	std::cout << "String 3 :";
	str3.Print();
	TString str4test("EEEredEEE");
	str = str3;
	std::cout << "\n";
	std::cout << "Stroka 1 = Stroke 3 TEST operator (=):\n";
	std::cout << "String 1 :";
	str.Print();
	std::cout << "Dlya udobstva sdelal kommandu system('cls'). Esli nado - uberite" << std::endl;
	system("pause");
	system("cls");
	std::cout << "TEST HERE: \n";
	std::cout << "Find 'ult' in String 3. Function returns : ";
	std::cout << str3.Find("ult") << '\n';
	std::cout << "Ravny li stroki (1 i 3)?\t" << (str == str3) << std::endl;
	std::cout << "Esli stroki (1 i 2)(DefaultString i TestString1) ravny - return 0 : \t" << (str != str2) << std::endl;
	std::cout << "Stroka 2 < Stroki 3(teststring1 < defaultstring?)\t" << (str2 < str3) << std::endl;
	std::cout << "Stroka 2 > Stroki 3(teststring1 > defaultstring?)\t" << (str2 > str3) << std::endl;
	std::cout << str[3];
	std::cout << "\n";
	std::cout << "String for test :";
	str4test.Print();
	str4test.Replace('E', 'x');
	str4test.Print();
	str4test.Ltrim('x');
	str4test.Print();
	str4test.Rtrim('x');
	str4test.Print();
	str4test.Empty();
	system("pause");
	return 0;
}
