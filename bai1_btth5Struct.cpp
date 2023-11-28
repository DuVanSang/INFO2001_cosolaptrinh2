#include <stdio.h>

#define MAX_STUDENTS 100

// �inh nghia cau tr�c Student
struct Student {
    char name[50];
    int studentID;
    float grade;
};

// H�m nhap th�ng tin cua sinh vi�n
void inputStudent(struct Student *student) {
    printf("Nhap ten sinh vien: ");
    scanf("%s", student->name);

    printf("Nhap ma so sinh vien: ");
    scanf("%d", &student->studentID);  // Thay d?i t�n v� ki?u d? li?u

    printf("Nhap diem cua sinh vien: ");
    scanf("%f", &student->grade);
}

// H�m hien thi th�ng tin cua sinh vi�n
void displayStudent(struct Student student) {
    printf("Ten: %s\n", student.name);
    printf("Ma so sinh vien: %d\n", student.studentID);
    printf("Diem: %.2f\n", student.grade);
}

// H�m cap nhat th�ng tin cua sinh vi�n
void updateStudent(struct Student *student) {
    printf("Cap nhat ten sinh vien: ");
    scanf("%s", student->name);

    printf("Cap nhat ma so sinh vien: ");
    scanf("%d", &student->studentID);

    printf("Cap nhat diem cua sinh vien: ");
    scanf("%f", &student->grade);
}

int main() {
    struct Student students[MAX_STUDENTS];
    int numStudents;

    printf("Nhap so luong sinh vien (toi da %d): ", MAX_STUDENTS);
    scanf("%d", &numStudents);

    // Kiem tra so luong sinh vi�n
    if (numStudents <= 0 || numStudents > MAX_STUDENTS) {
        printf("So luong sinh vien khong hop le.\n");
        return 1;  // Ket th�c chuong tr�nh voi m� lap
    }

    // Nhap th�ng tin cua tung sinh vi�n v�o mang
    for (int i = 0; i < numStudents; i++) {
        printf("\nNhap thong tin cho sinh vien %d:\n", i + 1);
        inputStudent(&students[i]);
    }

    // Hien thi th�ng tin cua tung sinh vi�n
    printf("\nDanh sach sinh vien:\n");
    for (int i = 0; i < numStudents; i++) {
        printf("\nThong tin cua sinh vien %d:\n", i + 1);
        displayStudent(students[i]);
    }

    // Cap nhat th�ng tin cua sinh vi�n thu nhat
    printf("\nCap nhat thong tin cho sinh vien 1:\n");
    updateStudent(&students[0]);

    // Hien thi lai th�ng tin cua tung sinh vi�n sau khi cap nh?t
    printf("\nDanh sach sinh vien sau khi cap nhat:\n");
    for (int i = 0; i < numStudents; i++) {
        printf("\nThong tin cua sinh vien %d:\n", i + 1);
        displayStudent(students[i]);
    }

    return 0;
}
