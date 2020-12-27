#include "pch.h"
#include "hook_helper.h"
#include "csv_reader.h"

map<string, string> dictionary;

void FillDictionary()
{
	readData("urw_rus.csv", dictionary);
}

BOOL DictSearch(char*& text)
{
	if (dictionary.find(text) == dictionary.end()) {
		return 0;
	} else {
		text = (char*)(dictionary.at(text)).c_str();
	}
	return 1;
}

void CreateDebugConsole()
{
	FILE* fp = 0;
	AllocConsole();
	SetConsoleTitle(L"URW debugging console");

	system("mode con cols=40 lines=20");
	freopen_s(&fp, "CONOUT$", "w", stdout);
	SetConsoleOutputCP(1251);
	COORD newSize = { 40,9999 };
	SetConsoleScreenBufferSize(GetStdHandle(STD_OUTPUT_HANDLE), newSize);
}

