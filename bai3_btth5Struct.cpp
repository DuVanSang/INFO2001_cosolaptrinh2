#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMPLOYEES 100

// �inh nghia cau tr�c Employee
struct Employee {
    int employeeId;
    char name[50];
    char position[50];
    float salary;
};

// H�m th�m nh�n vi�n moi
void addEmployee(struct Employee *employees, int *numEmployees) {
    if (*numEmployees < MAX_EMPLOYEES) {
        struct Employee newEmployee;
        
        // Nhap th�ng tin cho nh�n vi�n moi
        printf("Nhap ma nhan vien: ");
        scanf("%d", &newEmployee.employeeId);
        printf("Nhap ten nhan vien: ");
        scanf("%s", newEmployee.name);
        printf("Nhap chuc vu: ");
        scanf("%s", newEmployee.position);
        printf("Nhap luong: ");
        scanf("%f", &newEmployee.salary);

        // Th�m nh�n vi�n moi v�o danh s�ch
        employees[*numEmployees] = newEmployee;
        (*numEmployees)++;
        
        printf("Them nhan vien thanh cong.\n");
    } else {
        printf("Danh sach nhan vien da day. Khong the them nhan vien moi.\n");
    }
}

// H�m x�a nh�n vi�n theo m� nh�n vi�n
void deleteEmployee(struct Employee *employees, int *numEmployees, int employeeIdToDelete) {
    int foundIndex = -1;
    
    // T�m vi tr� cua nh�n vi�n can x�a
    for (int i = 0; i < *numEmployees; i++) {
        if (employees[i].employeeId == employeeIdToDelete) {
            foundIndex = i;
            break;
        }
    }

    // Neu t�m thay, x�a nh�n vi�n v� di chuyen c�c phan tu ph�a sau l�n
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

// H�m hien thi th�ng tin cua mot nh�n vi�n
void displayEmployee(struct Employee employee) {
    printf("Ma nhan vien: %d, Ten: %s, Chuc vu: %s, Luong: %.2f\n",
           employee.employeeId, employee.name, employee.position, employee.salary);
}

// H�m hien thi danh s�ch nh�n vi�n
void displayAllEmployees(struct Employee *employees, int numEmployees) {
    printf("Danh sach nhan vien:\n");
    for (int i = 0; i < numEmployees; i++) {
        displayEmployee(employees[i]);
    }
}

// H�m sap xep danh s�ch nh�n vi�n theo m� nh�n vi�n
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

// H�m sap xep danh s�ch nh�n vi�n theo luong
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
