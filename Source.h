#include <iostream>
#include <string> // stoi
#include <windows.h> // Sleep
using namespace std;


void start_randomize();
int my_random(int min, int max);
bool check_diapazone(const int value);
void set_int_value(int& size);
void allocate_1D_array_memory(int*& ar, const int size);
void random_fill_1D_array(int* ar, const int size);
void user_fill_1D_array(int* ar, const int size);
void print_1D_array(int* ar, const int size);
void free_memory(int*& ar);
void add_element_to_end(int*& ar, int& size, const int& value);
int main();
void add_middle(int*& ar, int& size, int element, int position);
void delete_mdl();
void delete_first(int*& ar, int& size);
void delete_last(int*& ar, int& size);


void add_middle(int*& ar, int& size, int element, int position) {

	// ������� ����� ������ �� 1 ������� ������
	int* tempArr = new int[size + 1];

	// �������� �������� �� ������� �������
	for (int i = 0; i < position; i++) {
		tempArr[i] = ar[i];
	}

	// ��������� ����� �������
	tempArr[position] = element;


	// �������� ���������� ��������
	for (int i = position; i < size; i++) {
		tempArr[i + 1] = ar[i];
	}

	size++; // ��������� ������ �������

	delete[] ar;

	// ������������ ��������� �� ������� ������� �� �����
	ar = tempArr;


} // ���������� �������� � �������� ������

void delete_mdl(int*& ar, int& size, int position) {

	int* tempArr = new int[size - 1];

	for (int i = 0; i < position; i++) {
		tempArr[i] = ar[i];
	}

	for (int i = position; i < size - 1; i++) {
		tempArr[i] = ar[i + 1];
	}

	size--;

	delete[] ar;

	ar = tempArr;
}

void delete_first(int*& ar, int& size) {

	int* tempArr = new int[size - 1];

	for (int i = 1; i < size; i++) {
		tempArr[i - 1] = ar[i];
	}

	size--;

	delete[] ar;

	ar = tempArr;
}

void delete_last(int*& ar, int& size) {

	int* tempArr = new int[size - 1];

	for (int i = 0; i < size - 1; i++) {
		tempArr[i] = ar[i];
	}

	size--;

	delete[] ar;

	ar = tempArr;
}

void start_randomize() {
	srand(time(0));
	rand();
}

int my_random(int min, int max) {
	int k = max - min + 1;
	return rand() % k + min;
}

// ��������� ������: �������� ���������
bool check_diapazone(const int value) {
	int min = 1;
	int max = 1000000000;
	return value >= min && value <= max;
}

// ������ ������� - ������ �������� � ���������� � ����������
void set_int_value(int& size) {
	// TO DO:
	// ������� �������� �� ���� ����� ������ 2147000000 ��� ���� ����� ������
	int number = -1;
	do {
		cout << "Please, enter size of array: ";
		string attempt;
		cin >> attempt;

		try {
			number = stoi(attempt); // stoi = string to int
		}
		catch (...) {
			cout << "ERROR!\n";
		}
	} while (!check_diapazone(number));

	size = number;
}

// int* - ��� ��������� �� ������ (� �������� ����� �����)
// int*& - ������ �� ��������� �� ������ (� �������� ����� ��������)

void allocate_1D_array_memory(int*& ar, const int size) {
	// size = 100; // ������� ��������� ��� const �� �������� �������� �������� ��������� � ���� �������
	ar = new int[size];
}

void random_fill_1D_array(int* ar, const int size) {
	for (int i = 0; i < size; i++)
		ar[i] = my_random(0, 100);
}

void user_fill_1D_array(int* ar, const int size) {
	for (int i = 0; i < size; i++) {
		cout << "Enter value for element # " << i << ": ";
		cin >> ar[i];
	}
}

void print_1D_array(int* ar, const int size) {
	cout << "\n\n======================================\n\n";
	for (int i = 0; i < size; i++) {
		cout << ar[i] << ", ";
	}
	cout << "\n\n======================================\n\n";
}

void free_memory(int*& ar) {
	delete[] ar; // ������� ������ �� �������
	ar = nullptr; // ���������� ����� ��������� � ������
}


// � ������ ��������� ��������� ���������� � &, ������ ��� ����������� ������������� ������, ������ ������ ������ � ���������, � �������� �������� �� � ����������
// ������ �������� ���� ��������� � & - ������ ���������, � ����� ����� ����� ������ � ��������
void add_element_to_end(int*& ar, int& size, const int& value) {

	// 1) ����� ����� ������� ��� ���� ������, �.�. ����� ������, ���������� ��������� � �� ����� �� 1 ������� ������, ��� � ������
	// 2) ar - ��������� �� ������ ������������ ������, ����� ��� ���� ��������� �� ����� ������
	int* temp = new int[size + 1];
	// 3) ����� ��������� ��� �������� �������� �� ������� ������� � �����
	for (int i = 0; i < size; i++) {
		temp[i] = ar[i];
	}
	// 4) � ����� ������ ������� ������� �� ����� ����� �� �������� ��������� ������� (������� ����� ���������� �� ������)
	temp[size] = value;
	// 5) ������ ������ ������ �� �����, ������ ��� ���� ����� � �������������� ��������� � �����
	delete[] ar;
	// 6) ������������ ��������� ar ����� ����������� �� ������� ������������� ������� �� �����
	ar = temp;
	// 7) �������� ������ �������, �� ������� ���������� ������� �������� � �������������� (������ ��� ������� ������ �� ������)
	size++;
}