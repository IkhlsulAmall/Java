#include <iostream>
using namespace std;
// Fungsi partisi untuk Quick Sort
int partition(int arr[], int start, int end){
	int pivot = arr[end]; // Pilih elemen pivot
	int i = start - 1; // Indeks elemen yang lebih kecil
	for (int j = start; j < end; j ++){
		if (arr[j] <= pivot){ // Jika elemen saat ini lebih kecil atau sama dengan pivot
			i++; // Tingkatkan indeks elemen yang lebih kecil
			swap(arr[i],arr[j]);
		}
	}
		swap(arr[i+1], arr[end]);
		return i+1;
}

void recursiveSort(int arr[], int start, int end){
	if (start<end){
		int i = partition(arr,start,end); // Hitung indeks tengah
		recursiveSort(arr,start, i - 1); // Urutkan secara rekursif setengah pertama dan kedua
		recursiveSort(arr,i + 1, end);  // Gabungkan setengah yang telah diurutkan
	}
}

void iterativeSort(int arr[],int start,int end){
	int stack[end - start + 1];
	int top = -1; 
	//Stack digunakan untuk menyimpan informasi tentang partisi yang
//	belum diurutkan agar dapat diproses secara iteratif.
	stack[++top] = start;
	stack[++top] = end;
	while (top >= 0){ //Selama stack tidak kosong (while (top >= 0)), proses iteratif dilakukan.
		end = stack[top--];
		start = stack[top--];
		int p = partition(arr, start, end);
		if (p-1 > start){ //Jika ada partisi kiri yang perlu diproses
			stack[++top] = start;
			stack[++top] = p-1;
		}
		if (p+1 < end){ //Jika ada partisi kanan yang perlu diproses
			stack[++top] = p+1;
			stack[++top] = end;
		}
		}
	}
void swap(int& a,int& b){
	int temp = a;
	a = b;
	b = temp;
}

int main(){
	int n;
	cout << "Masukkan Jumlah data: ";cin >> n;cout << endl;
	
	int arr[n];
	for (int i = 0; i < n; i++){
		cout << "Masukkan Data ke-" << i+1 << " = ";
		cin >> arr[i];
	}
	
	int pilih;
	cout << "\nUrutkan data: \n1. Iterative Quicksort \n2. Recursive Quicksort" << endl;
	cout << "Masukkan pilihan [1..2]: ";
	cin >> pilih;
	
	switch (pilih){
		case 1 : 
		cout << endl;
		cout << "Pengurutan dengan Iterative Quicksort";
		cout << "\n====================================";
		cout << "\nSebelum Sorting: ";for( int b : arr) cout << b << " ";
		cout << endl;
		iterativeSort(arr,0,n-1);
		cout << "Sesudah Sorting: ";
		for(int c : arr) cout << c << " ";
		break;
		
		case 2 :
			cout << endl;
				cout << "Pengurutan dengan Recursive Quicksort";
		cout << "\n====================================";
		cout << "\nSebelum Sorting: ";for( int b : arr) cout << b << " ";
		recursiveSort(arr,0,n-1);
		cout << "\nSesudah Sorting: ";for(int c : arr) cout << c << " ";
		break;
	}
	
		
}