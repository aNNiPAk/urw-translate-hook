#include "pch.h"
#include "hooked_functions.h"
#include <set>

#include <string>
// Set address function from urw.exe

std::set<char*> arr;

FILE* fp;

SETUP_ORIG_FUNC(ShowText, 0xF3B30);
void _fastcall h(ShowText)(int y, int x, char* str, UINT color, int border)
{
	DictSearch(str);
	o(ShowText)(y, x, str, color, border);
	RETR
}

SETUP_ORIG_FUNC(SANATAULUKKO_Lisaa, 0x140390);
int __fastcall h(SANATAULUKKO_Lisaa)(int x, char* str)
{
	DictSearch(str);
	return o(SANATAULUKKO_Lisaa)(x, str);
}

SETUP_ORIG_FUNC(winbox, 0xFB160);
void __fastcall h(winbox)(int a1, int a2, int a3, int a4, PCHAR text, UINT a6, UINT a7)
{
	DictSearch(text);
	o(winbox)(a1, a2, a3, a4, text, a6, a7);
	RETR
}

SETUP_ORIG_FUNC(Note, 0xDCD90);
bool __fastcall h(Note)(char* text)
{
	DictSearch(text);
	return o(Note)(text);
}

SETUP_ORIG_FUNC(LIST_Highlight, 0xB6E40);
char* __fastcall h(LIST_Highlight)(int x, int y, int z, char* text)
{
	DictSearch(text);
	o(LIST_Highlight)(x, y, z, text);
	RETR
}

void ChangePiirra_Nappain(int& x, int& y, char* text)
{
	if (x == 238 && y == 408 && !strncmp(text, "ENTER", 5))
	{
		x = 190;
	}
}

SETUP_ORIG_FUNC(Piirra_Nappain, 0xF95D0);
int __fastcall h(Piirra_Nappain)(int x, int y, char* text)
{
	ChangePiirra_Nappain(x, y, text);
	DictSearch(text);
	o(Piirra_Nappain)(x, y, text);
	RETR
}

SETUP_ORIG_FUNC(renshowtext, 0xF3950);
int __fastcall h(renshowtext)(int a, int b, int c, char* text, int d)
{
	DictSearch(text);
	if (text[0] == ' ') {

	}
	o(renshowtext)(a, b, c, text, d);
	RETR
}

SETUP_ORIG_FUNC(render_drawbutton, 0xF9C70);
int __fastcall h(render_drawbutton)(UINT a1, int a2, int a3, char* text, int a5, char a6)
{
	DictSearch(text);
	o(render_drawbutton)(a1, a2, a3, text, a5, a6);
	RETR
}

SETUP_ORIG_FUNC(LIST_Entry, 0xB6CE0);
char __fastcall h(LIST_Entry)(int id, char* text)
{
	DictSearch(text);
	return o(LIST_Entry)(id, text);
}

SETUP_ORIG_FUNC(elaatu, 0x44B70);
char* __fastcall h(elaatu)(unsigned __int8* a1, int a2) {
	char* text = o(elaatu)(a1, a2);
	DictSearch(text);
	return text;
}

SETUP_ORIG_FUNC(SubstituteValue, 0x1460);
int __cdecl h(SubstituteValue)(char* buffer, char* format, ...)
{

	va_list arg;
	va_start(arg, format);
	if (!arr.count(format)) {
		arr.insert(format);
		fp = fopen("Log/subst.txt", "a");
		fprintf(fp, "%s\n", format);
		fclose(fp);
	}
	//DictSearch(format);
	int res = vsprintf(buffer, format, arg);
	
	//int res = o(SubstituteValue)(buffer, format, arg);
	va_end(arg);

	return res;
}

SETUP_ORIG_FUNC(aseta_luonnonkasvi, 0xE74F0);
char* __fastcall h(aseta_luonnonkasvi)(char* Str, char* a2)
{
	printf("%s, %s\n", Str, a2);
	return o(aseta_luonnonkasvi)(Str, a2);
}

void AttachFunctions()
{
	ATTACH(ShowText);
	ATTACH(SANATAULUKKO_Lisaa);
	ATTACH(winbox);
	ATTACH(Note);
	ATTACH(LIST_Highlight);
	ATTACH(Piirra_Nappain);
	ATTACH(renshowtext);
	ATTACH(render_drawbutton);
	ATTACH(LIST_Entry);
	ATTACH(elaatu);
	ATTACH(SubstituteValue);
	ATTACH(aseta_luonnonkasvi);
}
