
#include "iostream"
class TString
{
public:
	char*str;
	//Method SIZE//
	int Size(char* str);
	
	char* Strcpy(char*d, const char* s);
	// Method PRINT//
	void Print();
	
	//default ctor//
	TString();
	
	//user ctor char*//
	TString(char * str1);
	
	//copy ctor//
	TString(const TString& object);
	//dtor//
	~TString();
	//Operators
	TString& operator=(const TString& object);
	
	TString& operator+=(const TString& object);
	
	//peregruz operator + - Студия выдавала ошибку связанную с тем, что в аргументах к функции перегруза '+', можно передать только один аргумент. Поэтому оставил только '+='
	// Могу подтвердить на занятии. Прихожу все равно с ноутбуком .P.S. Ну либо я уж совсем криворукий, хотя пытался брать ваш прототип функции)
	bool operator ==(const TString& object);
	
	bool operator != (const TString & object);
	
	bool operator < (const TString& object);
	
	bool operator > (const TString& object);
	
	char operator[](size_t index);
	
	//Replace func
	void Replace(char oldSym, char newSym);
	
	bool Empty();
	
	//TRIMS
	void Ltrim(char symbol);
	
	void Rtrim(char symbol);
	// Find func
	int Find(const TString& object);
	//ostream func
	std::ostream & operator<<(std::ostream &out);

};
