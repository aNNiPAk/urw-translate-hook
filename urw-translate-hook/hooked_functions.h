#pragma once
#include "detours.h"
#include "hook_helper.h"

typedef int(__cdecl* SubstituteValue)(char* buf, char* format, ...);
typedef void(__fastcall* ShowText)(int, int, PCHAR, UINT, int);
typedef int(__fastcall* SANATAULUKKO_Lisaa)(int, PCHAR);
typedef void(__fastcall* winbox)(int, int, int, int, PCHAR, UINT, int);
typedef bool(__fastcall* Note)(char*);
typedef char* (__fastcall* LIST_Highlight)(int, int, int, char*);
typedef int(__fastcall* Piirra_Nappain)(int, int, char*);
typedef int(__fastcall* renshowtext)(int, int, int, char*, int);
typedef int(__fastcall* render_drawbutton)(UINT, int, int, char*, int, char);
typedef char(__fastcall* LIST_Entry)(int, char*);
typedef char* (__fastcall* elaatu)(unsigned __int8* a1, int a2);

typedef char* (__fastcall* aseta_luonnonkasvi)(char* Str, char* a2);

void AttachFunctions();
