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

	// Создаем новый массив на 1 элемент больше
	int* tempArr = new int[size + 1];

	// Копируем элементы до позиции вставки
	for (int i = 0; i < position; i++) {
		tempArr[i] = ar[i];
	}

	// Вставляем новый элемент
	tempArr[position] = element;


	// Копируем оставшиеся элементы
	for (int i = position; i < size; i++) {
		tempArr[i + 1] = ar[i];
	}

	size++; // Обновляем размер массива

	delete[] ar;

	// Переставляем указатель со старого массива на новый
	ar = tempArr;


} // Добавление элемента в желаемый индекс

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

// отдельная задача: проверка диапазона
bool check_diapazone(const int value) {
	int min = 1;
	int max = 1000000000;
	return value >= min && value <= max;
}

// задача функции - ввести значение с клавиатуры в переменную
void set_int_value(int& size) {
	// TO DO:
	// сделать проверку на ввод чисел больше 2147000000 или ввод строк текста
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

// int* - тип указателя на массив (в параметр придёт копия)
// int*& - ссылка на указатель на массив (в параметр придёт оригинал)

void allocate_1D_array_memory(int*& ar, const int size) {
	// size = 100; // пометка параметра как const не позволит изменить значение параметра в теле функции
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
	delete[] ar; // очистка памяти от массива
	ar = nullptr; // превращаем дикий указатель в пустой
}


// в первом параметре указатель отмечается с &, потому что планируется перевыделение памяти, запись НОВОГО адреса в указатель, и работать хотелось бы с оригиналом
// второй параметр тоже нуждается в & - размер изменится, и новое число нужно писать в оригинал
void add_element_to_end(int*& ar, int& size, const int& value) {

	// 1) нужно будет создать ещё один массив, т.н. НОВЫЙ массив, количество элементов в нём будет на 1 элемент больше, чем в СТАРОМ
	// 2) ar - указатель на СТАРЫЙ оригинальный массив, нужен ещё один указатель на НОВЫЙ массив
	int* temp = new int[size + 1];
	// 3) нужно перегнать все полезные элементы со старого массива в новый
	for (int i = 0; i < size; i++) {
		temp[i] = ar[i];
	}
	// 4) в конец нового массива пишется то самое вэлью из третьего параметра функции (которое можно передавать по ссылке)
	temp[size] = value;
	// 5) старый массив больше не нужен, потому что есть новый с дополнительным элементов в конце
	delete[] ar;
	// 6) оригинальный указатель ar нужно переставить со старого уничтоженного массива на новый
	ar = temp;
	// 7) изменить размер массива, за которым приходится следить отдельно и самостоятельно (потому что массивы ничего не помнят)
	size++;
}