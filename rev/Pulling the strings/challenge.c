#include <stdio.h>
#include <wchar.h>

wchar_t* flag = L"SHELLCTF{Th4nks_f0r_the_food}";

int main() {
  wchar_t buffer[80];

  wprintf(L"Give Something to eat.\n I'm Hungry!!");
  fgetws(buffer, sizeof(buffer) / sizeof(wchar_t),stdin);

  if(wcscmp(flag, buffer) == 0) {
    fputws (L"Thank you!",stdout);
  }
  return 0; 
}