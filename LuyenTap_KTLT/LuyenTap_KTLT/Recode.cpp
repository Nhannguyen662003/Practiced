#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <math.h>

float* taoMang(int n)
{
	float* a = (float*)malloc(n * sizeof(float));
	if (a == NULL)
	{
		printf("Loi. Khong the cap phat bo nho");
		exit(1);
	}
	return a;
}

void nhapMang(float* a, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("Nhap vao gia tri cua a[%d]: ",i);
		scanf("%f", &a[i]);
	}
	
}
void nhapMangAuto(float* a, int n)
{
	srand(time(0));
	for (int i = 0; i < n; i++)
	{
		a[i] = (float)(rand() % 100) / 10.0;
	}
}

void xuatMang(float* a, int n) 
{
	printf("Gia tri cac phan tu trong mang la: ");
	for (int i = 0; i < n; i++)
	{
		printf("%.2f ", a[i]);
	}
}

int lasoNguyenTo(int n)
{
	if (n < 2)
	{
		return 0;
	}
	for (int i = 2; i <= sqrt(n); i++)
	{
		if (n % i == 0)
		{
			return 0; // ko la so nguyen to
		}

	}
	return 1; // la so nguyen to 
}

void xuatsoNT(float* a, int n)
{
	printf("Cac phan tu la so nt la : ");
	for (int i = 0; i < n; i++)
	{
		int phannguyen = (int)a[i]; // neu float ép kiểu lay phan nguyen
		if (lasoNguyenTo(phannguyen)) {
			printf("   %.2f",a[i]);
		}
	}
	printf("\n");
}

void xuatPhanTP(float* a, int n)
{
	printf("Phan thap phan cua cac phan tu la:");
	for (int i = 0; i < n; i++)
	{
		int phanNguyen = (int)a[i];
		float phanThapPhan = a[i] - phanNguyen;
		printf(" %.2f", phanThapPhan);
	}
	printf("\n");
}



int chuSo2(int n)
{
	n = abs(n); // lay gia tri tuyet doi
	while (n > 0)
	{
		if (n % 10 == 2)
		{
			return 1; // neu tim thay chu so 2
		}
		n /= 10; // loai bo chu so cuoi
	}
	return 0; // neu khong tim thay so 2
}

int demSo2(float* a, int n)
{
	int count = 0;
	for (int i = 0; i < n; i++)
	{
		int phanNguyen = (int)a[i]; // lay phan nguyen
		if (chuSo2(phanNguyen)) {
			count++; // neu tim thay so 2 thi tang bo dem len 1
		}
	}
	return count;
}



void xoaPhanTuLe(float* a, int* n)
{
	int j = 0; // Bien dem cho mang moi
	for (int i = 0; i < *n; i++)
	{
		int phanNguyen = (int)a[i];
		if (phanNguyen % 2 == 0)
		{
			a[j++] = a[i]; // giữ lại phần tử
		}
	}
	*n = j; //cập nhật lại mảng 
}

int demPhantu(float* a, int n, float x)
{
	int count = 0;
	for (int i = 0; i < n; i++)
	{
		if (a[i] == x)
		{
			count++;
		}
	}
	return count;
}


int timMax(float* a, int n)
{
	int soMax = 0;
	for (int i = 0; i < n; i++)
	{
		if (a[i] > soMax)
		{
			soMax = i;
		}
	}
	return soMax;
}

int timMin(float* a, int n)
{
	int soMin = 0;
	for (int i = 0; i < n; i++)
	{
		if (a[i] < soMin)
		{
			soMin = i;
		}
	}
	return soMin;
}


void xoaPT(float* a, int* n, int index)
{
	for (int i = index; i < *n - 1; i++)
	{
		a[i] = a[i + 1];
	}
	(*n)--; //giảm kich thưởng mảng sau khi xóa 
}

int main()
{
	float* a;
	int n;
	float x = 4.00;
	int luachon;
	printf("Nhap vao so luong phan tu manggggg: ");
	scanf("%d", &n);
	if (n <= 0)
	{
		printf("Loi. So luong phan tu mang phai lon hon 0");
		return 1;
	}
	a = taoMang(n);
	printf("Nhap vao lua chon cua ban: \n");
	printf("1.Nhap mang \n");
	printf("2.Nhap mang tu dong \n");
	scanf("%d", &luachon);
	switch (luachon)
	{
	case 1:
		nhapMang(a, n);
		break;
	case 2:
		nhapMangAuto(a, n);
		break;

	default:
		printf("Lua chon khong hop le");
		free(a);
		return 1;
	}

	xuatMang(a, n);
	printf("\n");

	xuatsoNT(a, n);
	printf("\n");

	xuatPhanTP(a, n);
	printf("\n");

	printf("So luong so 2 trong mang: %d", demSo2(a, n));
	printf("\n");


	xoaPhanTuLe(a, &n);
	xuatMang(a, n);
	printf("\n");

	//printf("Nhap vao phan tu x: ");
	//scanf("%.f", &x);
	int soluongx = demPhantu(a, n, x);
	printf(" So luong phan tu bang %.f trong mang la: %d ", x, soluongx);



	free(a);
	return 0;
}


void traodoiSX(float* a, int n, int X)
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if ((X && a[i] > a[j]) || (!X && a[i] < a[j]))
			{
				float temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}
	}
}

// Nhap ma tran vuon 

void nhapMTV(int a[][100], int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			printf("Nhap a[%d][%d]", i, j);
			scanf("%d", a[i][j]);

		}
	}
}

void xuatMTV(int a[][100], int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			printf("%d", a[i][j]);
		}
	}
}

int tongCheoChinh(int a[][100], int n)
{
	int tong = 0;
	for (int i = 0; i < n; i++)
	{
		tong += a[i][i];
	}
	return tong;
}
int tongCheoPhu(int a[][100], int n)
{
	int tong = 0;
	for (int i = 0; i < n; i++)
	{
		tong += a[i][n - 1 - i];
	}
	return tong;
}

int tongTtren(int a[][100], int n)
{
	int tong = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			tong += a[i][j];
		}
	}
	return tong;
}

int tongTduoi(int a[][100], int n)
{
	int tong = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			tong += a[i][j];
		}
	}
	return tong;
}

int tongMang(int a[], int n) {
	if (n == 0)
	{
		return 0;
	}
	// Gọi đệ quy: tổng của mảng bằng phần tử cuối cùng cộng với tổng của các phần tử trước nó
	return a[n - 1] + tongMang(a, n - 1);
}


