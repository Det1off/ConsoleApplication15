#include "Source.h"




int main()
{
	setlocale(0, "ru");
	start_randomize();

	int size;
	set_int_value(size);

	int* ar;
	allocate_1D_array_memory(ar, size); // задача функции - выделить память под одномерный массив. при этом изменится значение указателя (туда запишется адрес нового блока памяти), для переменной size побочных эффектов (side effects) не будет - при всём желании она не изменится как оригинал в контексте мейна

	random_fill_1D_array(ar, size); // и указатель, и количество элементов передаётся по значению (данные копируются)
	// массив всё равно в функцию не копируется, будут передан только его базовый адрес
	// все записи в массив сохранятся

	int position;
	cout << "Введите индекс: ";
	cin >> position;
	cout << "\n";

	if (position == 0) {
		cout << "Error" << "\n";
		return 0;
	}

	int element = 15;

	// добавление 1 в указаную позицию

	add_middle(ar, size, element, position);
	print_1D_array(ar, size);


	for (int i = 0; i < 10000; i++) {
		add_middle(ar, size, element, position);
		print_1D_array(ar, size);
		Sleep(1000);
	}





	free_memory(ar);
}
