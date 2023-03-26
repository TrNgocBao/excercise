#include <iostream>
#include <conio.h>
#include <string.h>
#include <stdio.h>
#define MAX 100
using namespace std;

struct SinhVien {
	int id;
	char ten[30];
	char gioiTinh[5];
	int tuoi;
	float diemToan;
	float diemLy;
	float diemHoa;
	float diemTB;
	char hocLuc[10];
};
typedef SinhVien sv;

void printLine(int n);
int docFile(sv a[], char fileName[]);
int ghiFile(sv a[], int n, char fileName[]);
int idLonNhat(sv a[], int id);
void tinhDTB (sv &sv);
void xepLoai (sv &sv);
void nhapThongTin(sv& sv, int id);
void nhapSV(sv a[], int id, int n);
void capNhatThongTin(sv &sv);
void capNhatSV(sv a[], int id, int n);
int xoaSV(sv a[], int id, int n);
void timKiemTen(sv a[], char ten[], int n);
void showSV(sv a[], int n);
void sapXepTheoDTB(sv a[], int n);
void sapXepTheoTen(sv a[], int n);
void pressAnyKey();

int main() {
	int key;
	char fileName[] = "sinhvien.txt";
	sv arraySV[MAX];
	int soLuong = 0;
	int idCount = 0;

	//Nhap danh sach sinh vien tu file
	soLuong = docFile(arraySV, fileName);
	idCount = idLonNhat(arraySV, soLuong);

	while (true) {
		cout << "CHUONG TRINH QUAN LY SINH VIEN C/C++\n";
		cout << "*************************MENU**************************\n";
		cout << "**  1. Them sinh vien.                               **\n";
		cout << "**  2. Cap nhat thong tin sinh vien boi ID.          **\n";
		cout << "**  3. Xoa sinh vien boi ID.                         **\n";
		cout << "**  4. Tim kiem sinh vien theo ten.                  **\n";
		cout << "**  5. Sap xep sinh vien theo diem trung binh (GPA). **\n";
		cout << "**  6. Sap xep sinh vien theo ten.                   **\n";
		cout << "**  7. Hien thi danh sach sinh vien.                 **\n";
		cout << "**  8. Ghi danh sach sinh vien vao file.             **\n";
		cout << "**  0. Thoat                                         **\n";
		cout << "*******************************************************\n";
		cout << "Nhap tuy chon: ";
		cin >> key;
		switch (key) {
			case 1:
				cout << "\n1. Them sinh vien.";
				idCount++;
				nhapSV(arraySV, idCount, soLuong);
				printf("\nThem sinh vien thanh cong.");
				soLuong++;
				pressAnyKey();
				break;
			case 2:
				if(soLuong > 0){
					int id;
					cout << "\n2. Cap nhat thong tin sinh vien.";
					cout << "\nNhap id: ";
					cin >> id;
					capNhatSV(arraySV, id, soLuong);
				} else {
					cout << "\nDanh sach sinh vien trong.";
				}
				pressAnyKey();
				break;
			case 3:
				if(soLuong > 0){
					int id;
					cout << "\n3. Xoa sinh vien.";
					cout << "Nhap ID: "; cin >> id;
					if(xoaSV(arraySV, id, soLuong) == 1){
						printf("\nSinh vien co ID = %d da bi xoa.", id);
						soLuong--;
					} 
				} else cout << "\nDanh sach sinh vien trong.";
				pressAnyKey();
				break;
			case 4:
				if(soLuong > 0){
					char strTen[30];
				 	cout << "\n4. Nhap ten de tim kiem sinh vien.\nTen SV: ";
				 	fflush(stdin);  gets(strTen);
					timKiemTen(arraySV, strTen, soLuong);	
				} else cout << "Danh sach sinh vien trong.";
				pressAnyKey();
				break;
			case 5:
				if(soLuong > 0){
					cout << "\n5. Sap xep sinh vien theo DTB.";
					sapXepTheoDTB(arraySV, soLuong);
					showSV(arraySV, soLuong);
				} else cout << "Danh sach sinh vien trong.";
				pressAnyKey();
				break;
			case 6:
				if (soLuong >0){
					cout << "6. Sap xep sinh vien theo ten.";
					sapXepTheoTen(arraySV, soLuong);
					showSV(arraySV, soLuong);
				} else cout << "Danh sach sinh vien trong.";
				pressAnyKey();
				break;
			case 7:
				if (soLuong > 0){
					cout << "\n7. Hien thi danh sach sinh vien.";
					showSV(arraySV, soLuong);
				} else cout << "Danh sach sinh vien trong.";
				pressAnyKey();
				break;
			case 8:
				if (soLuong >0){
					cout << "\n8. Ghi danh sach sinh vien vao file.";
					ghiFile(arraySV, soLuong, fileName);
				} else cout << "Danh sach sinh vien trong.";
				printf("Ghi danh sach vao file %s thanh cong", fileName);
				pressAnyKey();
				break;
			case 0:
				cout << "Thoat chuong trinh.";
				getch();
				return 0;
			default:
				cout << "Chuc nang khong hop le.\nVui long chon lai";
				pressAnyKey();
		}
	}
}

void printLine(int n) {
	cout << endl;
	for (int i = 0; i < n; i++)
		cout << "_";
	cout << endl;
}

void pressAnyKey(){
	cout << "\n\nBam phim bat ky de tiep tuc..." ;
	getch();
	system("cls");
}

int docFile(sv a[], char fileName[]) {
	FILE* fp;
	fp = fopen(fileName, "r");
	cout << "Chuan bi doc FILE: ";
	puts(fileName);
	int i = 0;
	while (fscanf(fp, "%5d%30s%5s%5d%10f%10f%10f%10f%10s\n",
		&a[i].id, &a[i].ten, &a[i].gioiTinh, &a[i].tuoi,
		&a[i].diemToan, &a[i].diemLy, &a[i].diemHoa, &a[i].diemTB, &a[i].hocLuc) != EOF) {
		i++;
		cout << "Doc ban ghi thu: " << i << endl;
	}
	cout << "So luong sinh vien co san trong file la: " << i << endl;
	cout << endl;
	return i;	// tra ve so luong sv duoc doc tu file
	fclose(fp);
}
int ghiFile(sv a[], int n, char fileName[]){
	FILE* fp;
	fp = fopen (fileName,"w");
	for (int i=0; i<n; i++){
		fprintf(fp,"%5d%30s%5s%5d%10f%10f%10f%10f%10s\n",a[i].id, a[i].ten, a[i].gioiTinh, a[i].tuoi,
		a[i].diemToan, a[i].diemLy, a[i].diemHoa, a[i].diemTB, a[i].hocLuc);
	}
	fclose(fp);
}

int idLonNhat(sv a[], int n) {
	int idMax = 0;
	if (n > 0) {
		idMax = a[0].id;
		for (int i = 0; i < n; i++) {
			if (a[i].id > idMax)
				idMax = a[i].id;
		}
	}
	return idMax;
}

void tinhDTB (sv &sv){
	sv.diemTB = (sv.diemToan + sv.diemLy + sv.diemHoa) / 3;
}
void xepLoai (sv &sv){
	if(sv.diemTB >= 8) strcpy(sv.hocLuc, "Gioi");
	else if(sv.diemTB >= 6.5) strcpy(sv.hocLuc, "Kha");
	else if(sv.diemTB >= 5) strcpy(sv.hocLuc, "Trung binh");
	else strcpy(sv.hocLuc,"Yeu");
}
void nhapThongTin(sv& sv, int id){
	cout << "\nNhap ten sv: "; fflush(stdin);
	gets (sv.ten);
	cout << "Nhap gioi tinh: ";
	gets(sv.gioiTinh);
	cout << "Nhap tuoi: ";	cin >> sv.tuoi;
	cout << "Nhap diem Toan: ";	 cin >> sv.diemToan;
	cout << "Nhap diem Ly: ";	cin >> sv.diemLy;
	cout << "Nhap diem Hoa: ";	cin >> sv.diemHoa;
	sv.id = id;
	tinhDTB (sv);
	xepLoai (sv);
}
void nhapSV(sv a[], int id, int n){
	printLine(35);
	printf("\nNhap sinh vien thu %d", n+1);
	nhapThongTin(a[n], id);
	printLine(35);
}

void capNhatThongTin(sv &sv){
	cout << "\nNhap ten sv: "; fflush(stdin);
	gets (sv.ten);
	cout << "Nhap gioi tinh: ";
	gets(sv.gioiTinh);
	cout << "Nhap tuoi: ";	cin >> sv.tuoi;
	cout << "Nhap diem Toan: ";	 cin >> sv.diemToan;
	cout << "Nhap diem Ly: ";	cin >> sv.diemLy;
	cout << "Nhap diem Hoa: ";	cin >> sv.diemHoa;
	tinhDTB (sv);
	xepLoai (sv);
}
void capNhatSV(sv a[], int id, int n){
	int found = 0;
	for (int i = 0; i < n; i++){
		if (a[i].id == id){
			found = 1;
			printLine(35);
			cout << "\nCap nhat thong tin sinh vien co ID: " << id;
			capNhatThongTin(a[i]);
			printLine(35);
			break;
		}
	}
	if (found == 0)  printf("\nSinh vien co ID khong ton tai.", id);
}

int xoaSV(sv a[], int id, int n){
	int found = 0;
	for (int i=0; i<n; i++){
		if (a[i].id == id){
			found = 1;
			printLine(35);
			for (int j = i; j < n; j++)
				a[j] = a[j+1];
			cout << "Da xoa sinh vien co ID = " << id;
			printLine(35);
			break; 
		}
	}
	if (found == 0) {
		printf("\nSinh vien co ID = %d khong ton tai.", id);
		return 0;
	} else return 1;	
}

void showSV(sv a[], int n){
	printLine(90);
	cout << "\nSTT \tID \tHo ten \tGioi tinh \tTuoi \tToan \tLy \tHoa \tTB \tHoc luc";
	for (int i=0; i<n; i++){
		printf("\n%d", i+1);
		printf("\t%d", a[i].id);
		printf("\t%s", a[i].ten);
		printf("\t%s", a[i].gioiTinh);
		printf("\t\t%d", a[i].tuoi);
		printf("\t%.2f\t%.2f\t%.2f", a[i].diemToan, a[i].diemLy, a[i].diemHoa);
		printf("\t%.2f", a[i].diemTB);
		printf("\t%s", a[i].hocLuc);
	}
	printLine(90); 
}

void timKiemTen(sv a[], char ten[], int n){
	sv arrayFound [MAX];
	char tenSV[30];
	int found = 0;
	for(int i=0; i<n; i++){
		strcpy(tenSV, a[i].ten);
		if (strstr(strupr(tenSV), strupr(ten))){
			arrayFound[found] = a[i];
			found++;
		} 
	}
	showSV(arrayFound, found);
}

void sapXepTheoDTB(sv a[], int n){
	//tang dan
	sv tmp;
    for(int i = 0;i < n;i++) {
        for(int j = i+1; j < n;j++) {
            if(a[i].diemTB > a[j].diemTB) {
                tmp = a[i];
                a[i] = a[j];
                a[j] = tmp;
            }
        }
    }
}

void sapXepTheoTen(sv a[], int n){
	sv tmp;
    char tenSV1[30];
    char tenSV2[30];
    for(int i = 0;i < n; i++) {
        strcpy(tenSV1, a[i].ten);
        for(int j = i+1; j < n; j++) {
            strcpy(tenSV2, a[j].ten);
            if(strcmp(strupr(tenSV1), strupr(tenSV2)) > 0) {
                tmp = a[i];
                a[i] = a[j];
                a[j] = tmp;
            }
        }
    }
}
