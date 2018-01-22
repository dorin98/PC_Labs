#include <stdio.h>

int str_length(char *s)
{
	if (*s) return 1 + str_length(s+1);
	return 0;
}

char * strdel(char *s, int pos, int n)
{
	int i = 0;
	while (s[pos + n + i - 1])
	{
		s[pos + i] = s[pos + n + i];
		++i;
	}
	return s;
}

char *strins(char *s1, int pos, char *s2){
	int len1, len2;
	len1 = str_length (s1);
	len2 = str_length (s2);
	for (int i = pos ; i < pos + len2 - 1 ; ++i)
	{
		s1[len1 + i - pos] = s1[i];
		s1[i] = s2[i - pos];
	}
	s1[len1 + len2 - 1] = '\0';
	return s1;
}

int eq_mask(char *sir, char *masca)
{
	int i = 0, len;
	len = str_length(sir);
	while (i++ < len)
		if (sir[i] != masca[i] && masca[i] != '?') return 0;
	return 1;
}

int eqcuv(char *cuv, char **tablou)
{
	for (int i = 0 ; tablou[i] ; ++i)
		if (eq_mask(tablou[i], cuv)) return 1;
	return 0;
}

int main()
{
	char *tablou[100] = {"curs1", "curs2", "curs3"};
	char *cuv1 = "curs2", *cuv2 = "curs5";
	printf("curs2 %s in tablou\n",(eqcuv(cuv1, tablou)) ? "este" : "nu este");
	printf("curs5 %s in tablou\n",(eqcuv(cuv2, tablou)) ? "este" : "nu este");
	char s[]="AlexBac";
	printf("%s\n",strdel(s,1,2));
	return 0;
}