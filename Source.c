/*
file.txt:
a^(b-c)+d/(e+f*g)-h
2 3 3 30 6 4 1 6
*/
#define _CRT_SECURE_NO_WARNINGS
#define MAX 100
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

void push(char stack[], int* top, char ch)
{
	stack[++(*top)] = ch;
}

void int_push(int res[], int* top, int val)
{
	res[++(*top)] = val;
}

void pop(int* top)
{
	(*top)--;
}

int prior(char ch)
{
	if (ch == '-' || ch == '+') return 1;
	if (ch == '*' || ch == '/') return 2;
	if (ch == '^') return 3;
	return 0;
}

void calc(int res[], int* top, char sgn)
{
	int v2 = res[*top];
	pop(top);
	int v1 = res[*top];
	pop(top);

	switch (sgn)
	{
	case '-':
		int_push(res, top, v1 - v2);
		break;
	case '+':
		int_push(res, top, v1 + v2);
		break;
	case '*':
		int_push(res, top, v1 * v2);
		break;
	case '/':
		if (v2 == 0)
		{
			printf("Cannot divide by zero!");
			exit(1);
		}
		int_push(res, top, v1 / v2);
		break;
	case '^':
		int_push(res, top, pow(v1, v2));
		break;
	}
}

int main()
{
	FILE* file = fopen("file.txt", "rt");
	char variables[MAX], signs[MAX], ec[MAX];
	int topv = -1, tops = -1, l = 0, values[MAX], j = 0;

	fscanf(file, "%s", ec);
	l = strlen(ec);

	while (fscanf(file, "%d", &values[j]) == 1)
		j++;

	for (int i = 0; i < l; i++)
	{
		if (isalpha(ec[i]))
			push(variables, &topv, ec[i]);
		else
		{
			if (ec[i] == '(')
				push(signs, &tops, ec[i]);
			else
				if (ec[i] == ')')
				{
					while (signs[tops] != '(')
					{
						push(variables, &topv, signs[tops]);
						pop(&tops);
					}
					pop(&tops);
				}
				else
				{
					while (tops >= 0 && prior(ec[i]) <= prior(signs[tops]))
					{
						push(variables, &topv, signs[tops]);
						pop(&tops);
					}
					push(signs, &tops, ec[i]);
				}
		}
	}

	while (tops > -1)
	{
		push(variables, &topv, signs[tops]);
		pop(&tops);
	}

	printf("Forma poloneza postfixata:\n");
	for (int i = 0; i <= topv; i++)
		printf("%c", variables[i]);

	int rez[MAX], topz = -1;
	for (int i = 0; i <= topv; i++)
	{
		if (isalpha(variables[i]))
			int_push(rez, &topz, values[variables[i] - 'a']);
		else calc(rez, &topz, variables[i]);
	}

	printf("\n\nRezult: %d\n", rez[topz]);
}