/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <string.h>

typedef struct employee {
    int em_id;
    char em_name[10];
    int em_age;
    char em_phone[12];
    float em_salary;
} employee_t;

void employee_info(employee_t my_emp) {
    printf("ID: %d\n", my_emp.em_id);
    printf("Name: %s\n", my_emp.em_name);
    printf("Age: %d\n", my_emp.em_age);
    printf("Phone: %s\n", my_emp.em_phone);
    printf("Salary: %.2f\n", my_emp.em_salary);
}

// 將員工資訊寫入檔案
void emp_writefile(employee_t emp[], int n) {
    FILE *fp = fopen("employee.bin", "wb");
    if (fp == NULL) {
        printf("Error opening file for writing.\n");
        return;
    }
    fwrite(emp, sizeof(employee_t), n, fp);
    fclose(fp);
    printf("Data written to file successfully.\n");
}

// 從檔案讀取員工資訊
void emp_readfile(employee_t emp[], int n) {
    FILE *fp = fopen("employee.bin", "rb");
    if (fp == NULL) {
        printf("Error opening file for reading.\n");
        return;
    }
    fread(emp, sizeof(employee_t), n, fp);
    fclose(fp);
    printf("Data read from file successfully.\n");
}

int main() {
    employee_t my_emp[2];

    // 初始化第一位員工資料
    strcpy(my_emp[0].em_name, "IU Lee");
    strcpy(my_emp[0].em_phone, "0937123456");
    my_emp[0].em_id = 100;
    my_emp[0].em_age = 18;
    my_emp[0].em_salary = 1000.30;

    // 初始化第二位員工資料
    strcpy(my_emp[1].em_name, "John Doe");
    strcpy(my_emp[1].em_phone, "0987654321");
    my_emp[1].em_id = 101;
    my_emp[1].em_age = 25;
    my_emp[1].em_salary = 2000.50;

    // 將資料寫入檔案
    emp_writefile(my_emp, 2);

    // 清空數據以測試讀取功能
    memset(my_emp, 0, sizeof(my_emp));

    // 從檔案讀取數據
    emp_readfile(my_emp, 2);

    // 顯示讀取出的資料
    for (int i = 0; i < 2; i++) {
        printf("\nEmployee %d:\n", i + 1);
        employee_info(my_emp[i]);
    }

    return 0;
}
