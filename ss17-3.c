#include <stdio.h>
#include <string.h>
#include <ctype.h>

// nguyen mau 
void menu();
void nhapChuoi(char **str);
void inChuoiDaoNguoc(char *str);
int demSoLuongTu(char *str);
void soSanhChieuDaiChuoi(char *str1, char *str2);
void inHoaTatCaChuCai(char *str);
void themChuoiVaoChuoiKhac(char *str1, char *str2);

int main() {
    int choice;
    char chuoi[1000]; 
    char chuoiKhac[1000]; 
    char *ptrChuoi = chuoi; 
    char *ptrChuoiKhac = chuoiKhac; 

    do {
        menu();
        printf("\nLua chon cua ban la: ");
        scanf("%d", &choice);
        getchar(); 

        switch(choice) {
            case 1:
                nhapChuoi(&ptrChuoi);  
                break;
            case 2:
                inChuoiDaoNguoc(ptrChuoi);  
                break;
            case 3:
                printf("So luong tu trong chuoi: %d\n", demSoLuongTu(ptrChuoi));  
                break;
            case 4:
                nhapChuoi(&ptrChuoiKhac); 
                soSanhChieuDaiChuoi(ptrChuoi, ptrChuoiKhac);  
                break;
            case 5:
                inHoaTatCaChuCai(ptrChuoi);  
                break;
            case 6:
                nhapChuoi(&ptrChuoiKhac);  
                themChuoiVaoChuoiKhac(ptrChuoi, ptrChuoiKhac);  
                break;
            case 7:
                printf("Thoat chuong trinh.\n");
                break;
            default:
                printf("\nLua chon cua ban khong hop le. Vui long chon lai!\n");
        }
    } while (choice != 7);

    return 0;
}

// logic 
void menu() {
    printf("\n                    MENU             \n");
    printf("\n 1. Nhap vao chuoi ki tu.\n");
    printf("\n 2. In ra chuoi dao nguoc.\n");
    printf("\n 3. Dem so luong tu trong chuoi.\n");
    printf("\n 4. Nhap vao chuoi khac, so sanh chieu dai chuoi.\n");
    printf("\n 5. In hoa tat ca chu cai trong chuoi.\n");
    printf("\n 6. Nhap vao chuoi khac va them chuoi do vao chuoi ban dau.\n");
    printf("\n 7. Thoat.\n");
}

void nhapChuoi(char **str) {
    printf("Nhap vao chuoi: ");
    fgets(*str, 1000, stdin);
    (*str)[strcspn(*str, "\n")] = '\0';
}

void inChuoiDaoNguoc(char *str) {
    int len = strlen(str);
    printf("Chuoi dao nguoc: ");
    for (int i = len - 1; i >= 0; i--) {
        printf("%c", str[i]);
    }
    printf("\n");
}

int demSoLuongTu(char *str) {
    int dem = 0;
    char *token = strtok(str, " ");
    while (token != NULL) {
        dem++;
        token = strtok(NULL, " ");
    }
    return dem;
}

void soSanhChieuDaiChuoi(char *str1, char *str2) {
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    if (len1 < len2) {
        printf("Chuoi 2 dai hon chuoi 1.\n");
    } else if (len1 > len2) {
        printf("Chuoi 1 dai hon chuoi 2.\n");
    } else {
        printf("Hai chuoi co do dai bang nhau.\n");
    }
}

void inHoaTatCaChuCai(char *str) {
    printf("Chuoi in hoa: ");
    while (*str) {
        printf("%c", toupper(*str));
        str++;
    }
    printf("\n");
}

void themChuoiVaoChuoiKhac(char *str1, char *str2) {
    strcat(str1, str2); 
    printf("Chuoi sau khi them: %s\n", str1);
}
