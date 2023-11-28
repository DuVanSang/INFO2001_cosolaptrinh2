#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STUDENTS 100

// �?nh nghia c?u tr�c Student
struct Student {
    char name[50];
    int id;
    float grade;
};

// H�m so s�nh cho qsort khi s?p x?p theo t�n
int compareByName(const void *a, const void *b) {
    return strcmp(((struct Student *)a)->name, ((struct Student *)b)->name);
}

// H�m so s�nh cho qsort khi s?p x?p theo di?m s?
int compareByGrade(const void *a, const void *b) {
    if (((struct Student *)a)->grade < ((struct Student *)b)->grade) return -1;
    if (((struct Student *)a)->grade > ((struct Student *)b)->grade) return 1;
    return 0;
}

// H�m t�m ki?m sinh vi�n theo t�n
struct Student *searchByName(struct Student students[], int numStudents, const char *name) {
    for (int i = 0; i < numStudents; i++) {
        if (strcmp(students[i].name, name) == 0) {
            return &students[i];
        }
    }
    return NULL; // Kh�ng t�m th?y sinh vi�n
}

// H�m t�m ki?m sinh vi�n theo id
struct Student *searchById(struct Student students[], int numStudents, int id) {
    for (int i = 0; i < numStudents; i++) {
        if (students[i].id == id) {
            return &students[i];
        }
    }
    return NULL; // Kh�ng t�m th?y sinh vi�n
}

// H�m hi?n th? th�ng tin c?a sinh vi�n
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

    // Ki?m tra s? lu?ng sinh vi�n
    if (numStudents <= 0 || numStudents > MAX_STUDENTS) {
        printf("So luong sinh vien khong hop le.\n");
        return 1;  // K?t th�c chuong tr�nh v?i m� l?i
    }

    // Nh?p th�ng tin c?a t?ng sinh vi�n v�o m?ng
    for (int i = 0; i < numStudents; i++) {
        printf("\nNhap thong tin cho sinh vien %d:\n", i + 1);
        printf("Nhap ten sinh vien: ");
        scanf("%s", students[i].name);
        printf("Nhap ID sinh vien: ");
        scanf("%d", &students[i].id);
        printf("Nhap diem cua sinh vien: ");
        scanf("%f", &students[i].grade);
    }

    // S?p x?p danh s�ch sinh vi�n theo t�n
    qsort(students, numStudents, sizeof(struct Student), compareByName);

    // Hi?n th? danh s�ch sinh vi�n sau khi s?p x?p theo t�n
    printf("\nDanh sach sinh vien sau khi sap xep theo ten:\n");
    for (int i = 0; i < numStudents; i++) {
        printf("\nThong tin cua sinh vien %d:\n", i + 1);
        displayStudent(students[i]);
    }

    // S?p x?p danh s�ch sinh vi�n theo di?m s?
    qsort(students, numStudents, sizeof(struct Student), compareByGrade);

    // Hi?n th? danh s�ch sinh vi�n sau khi s?p x?p theo di?m s?
    printf("\nDanh sach sinh vien sau khi sap xep theo diem:\n");
    for (int i = 0; i < numStudents; i++) {
        printf("\nThong tin cua sinh vien %d:\n", i + 1);
        displayStudent(students[i]);
    }

    // T�m ki?m sinh vi�n theo t�n
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

    // T�m ki?m sinh vi�n theo id
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
