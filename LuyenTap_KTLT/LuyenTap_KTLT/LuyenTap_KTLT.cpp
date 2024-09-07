#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

// Ham tao mang tu dong
int* taoMang(int n)
{
	int* a = (int*)malloc(n * sizeof(int));
	if (a == NULL) {
		printf("Loi: khong the cap phat bo nho. \n");
		exit(1);
	}
	return a;
}

// Ham nhap gia tri mang
void nhapMang(int* a, int n) {
	for (int i = 0; i < n; i++)
	{
		printf("Nhap vao gia tri cho a[%d]: ", i);
		scanf("%d", &a[i]);
	}
}

// Ham tao mang ngau nhien 
void taoMangnn(int* a, int n) {
	srand(time(0));
	for (int i = 0; i < n; i++)
	{
		a[i] = (int)(rand() % 100); // Tao mang ngau nhien tu 0 -> 99
	}
}

// Ham xuat mang
void xuatMang(int* a, int n) {
	printf("Gia tri cac phan tu trong mang la: ");
	for (int i = 0; i < n; i++)
	{
		printf("%d", a[i]);
	}
}



int lasoNguyenTo(int n) {
	if (n < 2)
	{
		return 0;
	}
	for (int i = 2; i <= sqrt(n); i++)
	{
		if (n % i == 0) {
			return 0; // ko la so nguyen to 
		}
	}
	return 1; // la so nguyen to 
}

void xuatSoNT(int* a, int n)
{
	printf("Cac phan tu la so nguyen to la: ");
	for (int i = 0; i < n; i++)
	{
		int phanNguyen = (int)a[i]; // lấy phần nguyên của số thực 
		if (lasoNguyenTo(phanNguyen))
		{
			printf("%d", a[i]);
		}
	}
}


void layPhanthapphan(float* a, int n)
{
	printf("Phan thap phan cua cac phan tu trong mang la ");
	for (int i = 0; i < n; i++)
	{
		int phanNguyen = (int)a[i];
		float phanThapphan = a[i] - phanNguyen;
		printf("%.2f", phanThapphan);
	}
	printf("\n");
}


int chuaSo2(int n) {
	n = abs(n); // lay gia tri tuyet doi
	while (n > 0) {
		if (n % 10 == 2)
		{
			return 1; // tim thay so 2 thi tra ve 1
		}
		n /= 10; // Loai bo chu so cuoi
	}
	return 0; // khong tim thay chu so 2

}

int demso2(float* a, int n) {
	int count = 0;
	for (int i = 0; i < n; i++)
	{
		int phanNguyen = (int)a[i]; // lay phan nguyen
		if (chuaSo2(phanNguyen))
		{
			count++; // tang bo dem phan tu chu so 2
		}
	}
	return count;
}


int main()
{
	int n;
	int* a;
	
	printf("Nhap vao so luong phan tu mang: ");
	scanf("%d", &n);
	if (n <= 0)
	{
		printf("So luong phan tu mang phai lon hon 0");
		return 1;
	}
	

	a = taoMang(n);
	//nhapMang(a, n);
	taoMangnn(a, n);
	xuatMang(a, n);


	free(a); //Giai phong bo nho
	return 0;

}

//neu tangDan = 1 sx tang dan , neu tangDan = 0 sx giam dan 


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

void NhapMaTranVuon(int a[][100], int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			printf("Nhap a[%d][%d]", i, j);
			scanf("%d", &a[i][j]);
		}
	}
}
void XuatMaTranVuon(int a[][100], int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			printf("%d", a[i][j]);
		}
	}
}

int  TongCheoChinh(int a[][100], int n)
{
	int tong = 0;
	for (int i = 0; i < n; i++)
	{
		tong += a[i][i];
	}
	return tong;
}

int  TongCheoPhu(int a[][100], int n)
{
	int tong = 0;
	for (int i = 0; i < n; i++)
	{
		tong += a[i][n - 1 - i];
	}
	return tong;
}

int tongTamGiacTren(int a[][100], int n)
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

int tongTamGiacDuoi(int a[][100], int n)
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

void SXtheocot(int a[][100], int n)
{
	for (int j = 0; j < n; j++)
	{
		for (int i = 0; i < n - 1; i++)
		{
			for (int k = i + 1; k < n; k++)
			{
				if (a[i][j] > a[k][j])
				{
					// hoan doi phan tu phia tren lon hon phan tu phia duoi 
					int temp = a[i][j];
					a[i][j] = a[k][j];
					a[k][j] = temp;

				}
			}
		}
	}
}