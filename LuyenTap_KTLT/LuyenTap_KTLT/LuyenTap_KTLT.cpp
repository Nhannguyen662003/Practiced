#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>

struct PhanSo 
{
	int tu, mau;

	
};

void main()
{
	PhanSo ps1, * ps2 = &ps1;
	ps1.tu = 1; ps1.mau = 2;
	ps2->tu = 1; ps2->mau = 2;

	int a = 0, b = 0;
	int t;
	printf("Nhap a va b: ");
	scanf("%d%d", &a, &b);
	try {
		if (b == 0)
			throw"So chia khong duoc la 0";
		else
			t = a / b;		
	}

	catch (const char* st)
	{
		printf("Loi: %s", st);
	}
	_getch();
}

