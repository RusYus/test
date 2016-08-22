// ConsoleApplication2.cpp: определяет точку входа для консольного приложения.
//

//#include "stdafx.h"
#include <string>
#include <iomanip>
#include <iostream> 
#include <algorithm>

using namespace std;
//макс. длина строки
const int STRING_LENGTH = 100;
const string ERROR_STRING_LENGTH = "Nekorrektnaja dlina stroki";
const string ERROR_UNKNOWN = "Neizvestnaja oshibka";
const string ERROR_NO_DIGITS = "Ne najdeno chisel"; 
const string ERROR_NO_SIGNS = "Ne najdeno znakov";
const string ERROR_FALSE_SYMBOLS = "Nekorrektnie simvoli";
const string ERROR_BRACKETS = "Neparnie skobki";
const string ERROR_EXCEPTION = "Oshibka v razbore stroki";
const string DIGITS = "1234567890";
const string SIGNS = "+-*/";
const string SYMBOLS = "()";
const string DELIMITER = ".";

double Calc(string inputString) {
	char openBracket = '(';
	char closeBracket = ')';
	int brackets = 0;
	int resPos = -1;
	char resChar = ' ';
	string left = "";
	string right = "";

	brackets = 0;
	//Находим последний по порядку знак не в скобках(согласно приоритету)
	//входной символ операции
	for (int i = 0; i < inputString.length(); i++) {
		if (inputString[i] == openBracket)
			brackets++;
		if (inputString[i] == closeBracket)
			brackets--;
		//сначала + и -,т.к. приоритет ниже
		if (inputString[i] == '+' || 
			inputString[i] == '-') {
			if (brackets == 0 && i >= resPos) {
				resPos = i;
				resChar = inputString[i];
			}
		}

	}

	for (int i = 0; i < inputString.length(); i++) {
		if (inputString[i] == openBracket)
			brackets++;
		if (inputString[i] == closeBracket)
			brackets--;
		//затем * и /
		if (inputString[i] == '*' || inputString[i] == '/') {
			if (brackets == 0 && resPos == -1 && i >= resPos) {
				resPos = i;
				resChar = inputString[i];
			}
		}
	}
	
	double resNumber = .0;

	if (resPos != -1) {
		//скопировать левую и правую часть в новые строки
		left = inputString.substr(0, resPos);
		right = inputString.substr(resPos + 1, inputString.length() - resPos + 1);

		
		if (left.length() == 0 || right.length() == 0)
			throw ERROR_EXCEPTION;

		//убираем крайние скобки(если есть)
		if (left[0] == '(')
			left = left.substr(1, left.length() - 2);
		if (right[0] == '(')
			right = right.substr(1, right.length() - 2);


		switch (resChar)
		{
		case '+':resNumber = Calc(left) + Calc(right); break;
		case '-':resNumber = Calc(left) - Calc(right); break;
		case '*':resNumber = Calc(left) * Calc(right); break;
		case '/':resNumber = Calc(left) / Calc(right); break;
		default:
			break;
		}
	}
	else {
		if (inputString.find_first_not_of(DIGITS + DELIMITER, 0) != string::npos) {
			throw ERROR_EXCEPTION;
		}
		resNumber = atof(inputString.c_str());
	}

	return resNumber;

}

bool CheckString(string inputString) {
	//Проверяем длину строки(1 <..< STRING_LENGTH)
	if (inputString.length() < 1 || inputString.length() > STRING_LENGTH) {
		cout << ERROR_STRING_LENGTH << endl;
		return false;
	}
	//Проверяем на парность скобок
	char openBracket = '(';
	char closeBracket = ')';
	int brackets = 0;
	for (int i = 0; i < inputString.length(); i++) {
		if (inputString[i] == openBracket)
			brackets++;
		if (inputString[i] == closeBracket)
			brackets--;
	}
	if (brackets != 0) {
		cout << ERROR_BRACKETS << endl;
		return false;
	}

	//Проверяем, есть ли цифры в выражении
	if (inputString.find_first_of(DIGITS, 0) == string::npos) {
		cout << ERROR_NO_DIGITS << endl;
		return false;
	}

	//Проверяем, есть ли знаки операций в выражении
	if (inputString.find_first_of(SIGNS, 0) == string::npos) {
		cout << ERROR_NO_SIGNS << endl;
		return false;
	}
	
	//Проверяем, есть ли буквы и проч. символы
	if (inputString.find_first_not_of(DIGITS + SIGNS + SYMBOLS + DELIMITER, 0) != string::npos) {
		cout << ERROR_FALSE_SYMBOLS << endl;
		return false;
	}

	return true;

}

int main()
{

	//строка для выхода
	string exitString = "0";
	string inputString = exitString;

	while( 1 ) {
		cout << "Vvedite stroku (0 - vihod): ";
		cin >> inputString;

		if (inputString.compare(exitString) == 0)
			break;

		//убираем пробелы
		inputString.erase(std::remove(inputString.begin(), inputString.end(), ' '), inputString.end());
		//заменяем точки на запятые
		std::replace(inputString.begin(), inputString.end(), ',', '.');

		double calcResult = 0;
		try {
			if (CheckString(inputString)) {
				calcResult = Calc(inputString);
				//вывод двух знаков после запятой
				cout.setf(ios::fixed);
				cout << "Resultat: " <<  setprecision(2) << calcResult << endl;
			}
			else {
				cout << "Neverniy format ishodnoi stroki" << endl;
			}
		}
		catch (string s) {
			cout << "Oshibka: " << s << endl;
		}
		catch (...) {
			cout << ERROR_UNKNOWN << endl;
		}
	}
	
	return 0;
}

