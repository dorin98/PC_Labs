#include <stdio.h>
#include <string.h>
#define maxLength (int)1e5

void replace(char o_string[], char s_string[], char r_string[])
{
	char buffer[maxLength];
	char *ch;
	ch = strstr(o_string, s_string);
	if (!ch) return;
	strncpy(buffer, o_string, ch - o_string);
	buffer[ch-o_string] = '\0';
	sprintf(buffer + (ch - o_string), "%s%s", r_string, ch + strlen(s_string));
	o_string[0] = '\0';
	strcpy(o_string, buffer);
	return replace(o_string + (ch - o_string) + strlen(r_string), s_string, r_string);
}

int main()
{
	char text[maxLength], str1[maxLength], str2[maxLength];
	fgets(text, maxLength, stdin);
	scanf("%s %s", str1, str2);
	replace(text,str1,str2);
	fputs(text, stdout);
	return 0;
}