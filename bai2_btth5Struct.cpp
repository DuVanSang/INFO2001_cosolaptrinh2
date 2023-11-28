#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STUDENTS 100

// Ð?nh nghia c?u trúc Student
struct Student {
    char name[50];
    int id;
    float grade;
};

// Hàm so sánh cho qsort khi s?p x?p theo tên
int compareByName(const void *a, const void *b) {
    return strcmp(((struct Student *)a)->name, ((struct Student *)b)->name);
}

// Hàm so sánh cho qsort khi s?p x?p theo di?m s?
int compareByGrade(const void *a, const void *b) {
    if (((struct Student *)a)->grade < ((struct Student *)b)->grade) return -1;
    if (((struct Student *)a)->grade > ((struct Student *)b)->grade) return 1;
    return 0;
}

// Hàm tìm ki?m sinh viên theo tên
struct Student *searchByName(struct Student students[], int numStudents, const char *name) {
    for (int i = 0; i < numStudents; i++) {
        if (strcmp(students[i].name, name) == 0) {
            return &students[i];
        }
    }
    return NULL; // Không tìm th?y sinh viên
}

// Hàm tìm ki?m sinh viên theo id
struct Student *searchById(struct Student students[], int numStudents, int id) {
    for (int i = 0; i < numStudents; i++) {
        if (students[i].id == id) {
            return &students[i];
        }
    }
    return NULL; // Không tìm th?y sinh viên
}

// Hàm hi?n th? thông tin c?a sinh viên
void displayStudent(struct Student student) {
    printf("Ten: %s\n", student.name);
    printf("ID: %d\n", student.id);
    printf("Diem: %.2f\n", student.grade);
}

int main() {
    struct Student students[MAX_STUDENTS];
    int numStudents;

    printf("Nhap so luong sinh vien (toi da %d): ", MAX_STUDENTS);
    scanf("%d", &numStudents);

    // Ki?m tra s? lu?ng sinh viên
    if (numStudents <= 0 || numStudents > MAX_STUDENTS) {
        printf("So luong sinh vien khong hop le.\n");
        return 1;  // K?t thúc chuong trình v?i mã l?i
    }

    // Nh?p thông tin c?a t?ng sinh viên vào m?ng
    for (int i = 0; i < numStudents; i++) {
        printf("\nNhap thong tin cho sinh vien %d:\n", i + 1);
        printf("Nhap ten sinh vien: ");
        scanf("%s", students[i].name);
        printf("Nhap ID sinh vien: ");
        scanf("%d", &students[i].id);
        printf("Nhap diem cua sinh vien: ");
        scanf("%f", &students[i].grade);
    }

    // S?p x?p danh sách sinh viên theo tên
    qsort(students, numStudents, sizeof(struct Student), compareByName);

    // Hi?n th? danh sách sinh viên sau khi s?p x?p theo tên
    printf("\nDanh sach sinh vien sau khi sap xep theo ten:\n");
    for (int i = 0; i < numStudents; i++) {
        printf("\nThong tin cua sinh vien %d:\n", i + 1);
        displayStudent(students[i]);
    }

    // S?p x?p danh sách sinh viên theo di?m s?
    qsort(students, numStudents, sizeof(struct Student), compareByGrade);

    // Hi?n th? danh sách sinh viên sau khi s?p x?p theo di?m s?
    printf("\nDanh sach sinh vien sau khi sap xep theo diem:\n");
    for (int i = 0; i < numStudents; i++) {
        printf("\nThong tin cua sinh vien %d:\n", i + 1);
        displayStudent(students[i]);
    }

    // Tìm ki?m sinh viên theo tên
    char searchName[50];
    printf("\nNhap ten sinh vien can tim kiem: ");
    scanf("%s", searchName);
    struct Student *foundByName = searchByName(students, numStudents, searchName);
    if (foundByName != NULL) {
        printf("Sinh vien co ten '%s' duoc tim thay:\n", searchName);
        displayStudent(*foundByName);
    } else {
        printf("Khong tim thay sinh vien co ten '%s'.\n", searchName);
    }

    // Tìm ki?m sinh viên theo id
    int searchId;
    printf("\nNhap ID sinh vien can tim kiem: ");
    scanf("%d", &searchId);
    struct Student *foundById = searchById(students, numStudents, searchId);
    if (foundById != NULL) {
        printf("Sinh vien co ID '%d' duoc tim thay:\n", searchId);
        displayStudent(*foundById);
    } else {
        printf("Khong tim thay sinh vien co ID '%d'.\n", searchId);
    }

    return 0;
}
