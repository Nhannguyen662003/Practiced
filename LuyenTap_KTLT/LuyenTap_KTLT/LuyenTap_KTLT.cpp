#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>

void chiaHaiSo(int* a, int* b, int* ketQua, int* phanDu) {
    if (*b != 0) {
        *ketQua = *a / *b;    // Chia lấy phần nguyên
        *phanDu = *a % *b;     // Chia lấy phần dư
    }
    else {
        printf("Loi: Khong the chia cho 0.\n");
    }
}

int main() {
    int a, b, ketQua, phanDu;

    // Nhập vào hai số nguyên
    printf("Nhap vao so nguyen a: ");
    scanf("%d", &a);
    printf("Nhap vao so nguyen b: ");
    scanf("%d", &b);

    // Gọi hàm chia hai số sử dụng con trỏ
    chiaHaiSo(&a, &b, &ketQua, &phanDu);

    // Nếu b khác 0, in ra kết quả
    if (b != 0) {
        printf("Ket qua phep chia %d / %d = %d\n", a, b, ketQua);
        printf("Phan du = %d\n", phanDu);
    }

    return 0;
}

