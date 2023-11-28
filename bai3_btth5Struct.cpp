#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMPLOYEES 100

// Ðinh nghia cau trúc Employee
struct Employee {
    int employeeId;
    char name[50];
    char position[50];
    float salary;
};

// Hàm thêm nhân viên moi
void addEmployee(struct Employee *employees, int *numEmployees) {
    if (*numEmployees < MAX_EMPLOYEES) {
        struct Employee newEmployee;
        
        // Nhap thông tin cho nhân viên moi
        printf("Nhap ma nhan vien: ");
        scanf("%d", &newEmployee.employeeId);
        printf("Nhap ten nhan vien: ");
        scanf("%s", newEmployee.name);
        printf("Nhap chuc vu: ");
        scanf("%s", newEmployee.position);
        printf("Nhap luong: ");
        scanf("%f", &newEmployee.salary);

        // Thêm nhân viên moi vào danh sách
        employees[*numEmployees] = newEmployee;
        (*numEmployees)++;
        
        printf("Them nhan vien thanh cong.\n");
    } else {
        printf("Danh sach nhan vien da day. Khong the them nhan vien moi.\n");
    }
}

// Hàm xóa nhân viên theo mã nhân viên
void deleteEmployee(struct Employee *employees, int *numEmployees, int employeeIdToDelete) {
    int foundIndex = -1;
    
    // Tìm vi trí cua nhân viên can xóa
    for (int i = 0; i < *numEmployees; i++) {
        if (employees[i].employeeId == employeeIdToDelete) {
            foundIndex = i;
            break;
        }
    }

    // Neu tìm thay, xóa nhân viên và di chuyen các phan tu phía sau lên
    if (foundIndex != -1) {
        for (int i = foundIndex; i < *numEmployees - 1; i++) {
            employees[i] = employees[i + 1];
        }
        (*numEmployees)--;
        printf("Xoa nhan vien thanh cong.\n");
    } else {
        printf("Khong tim thay nhan vien co ma %d de xoa.\n", employeeIdToDelete);
    }
}

// Hàm hien thi thông tin cua mot nhân viên
void displayEmployee(struct Employee employee) {
    printf("Ma nhan vien: %d, Ten: %s, Chuc vu: %s, Luong: %.2f\n",
           employee.employeeId, employee.name, employee.position, employee.salary);
}

// Hàm hien thi danh sách nhân viên
void displayAllEmployees(struct Employee *employees, int numEmployees) {
    printf("Danh sach nhan vien:\n");
    for (int i = 0; i < numEmployees; i++) {
        displayEmployee(employees[i]);
    }
}

// Hàm sap xep danh sách nhân viên theo mã nhân viên
void sortByEmployeeId(struct Employee *employees, int numEmployees) {
    for (int i = 0; i < numEmployees - 1; i++) {
        for (int j = 0; j < numEmployees - i - 1; j++) {
            if (employees[j].employeeId > employees[j + 1].employeeId) {
                struct Employee temp = employees[j];
                employees[j] = employees[j + 1];
                employees[j + 1] = temp;
            }
        }
    }
}

// Hàm sap xep danh sách nhân viên theo luong
void sortBySalary(struct Employee *employees, int numEmployees) {
    for (int i = 0; i < numEmployees - 1; i++) {
        for (int j = 0; j < numEmployees - i - 1; j++) {
            if (employees[j].salary < employees[j + 1].salary) {
                struct Employee temp = employees[j];
                employees[j] = employees[j + 1];
                employees[j + 1] = temp;
            }
        }
    }
}

int main() {
    struct Employee employees[MAX_EMPLOYEES];
    int numEmployees = 0;
    int choice;

    do {
        printf("\n===== Quan Ly Nhan Su =====\n");
        printf("1. Them nhan vien\n");
        printf("2. Xoa nhan vien\n");
        printf("3. Hien thi danh sach nhan vien\n");
        printf("4. Sap xep theo ma nhan vien\n");
        printf("5. Sap xep theo luong\n");
        printf("0. Thoat\n");
        printf("Chon chuc nang: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addEmployee(employees, &numEmployees);
                break;
            case 2: {
                int employeeIdToDelete;
                printf("Nhap ma nhan vien can xoa: ");
                scanf("%d", &employeeIdToDelete);
                deleteEmployee(employees, &numEmployees, employeeIdToDelete);
                break;
            }
            case 3:
                displayAllEmployees(employees, numEmployees);
                break;
            case 4:
                sortByEmployeeId(employees, numEmployees);
                printf("Danh sach sau khi sap xep theo ma nhan vien:\n");
                displayAllEmployees(employees, numEmployees);
                break;
            case 5:
                sortBySalary(employees, numEmployees);
                printf("Danh sach sau khi sap xep theo luong:\n");
                displayAllEmployees(employees, numEmployees);
                break;
            case 0:
                printf("Ket thuc chuong trinh.\n");
                break;
            default:
                printf("Chuc nang khong hop le. Vui long chon lai.\n");
        }
    } while (choice != 0);

    return 0;
}
