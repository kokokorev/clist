#include <stdlib.h>
#include <stdio.h>

// создаем новый тип данных СТРУКТУРУ (это не класс111) 
typedef struct s_list {
	int serial_number;
	char* firma;
	char* model;
	int series;
	int year;
	// ссылка на следующий элемент
	struct s_list* next;
} t_list;


// функция создания нового элемента списка
t_list* create_node(int set_serial_number, char *set_firma, char* set_model, int set_series, int set_year) {
	// выделяем память под новый элемент
	t_list* node = (t_list*)malloc(sizeof(t_list));
	// назначаем значения переменным элемента, которые мы передали в метод
	node->serial_number = set_serial_number;
	node->firma = set_firma;
	node->model = set_model;
	node->series = set_series;
	node->year = set_year;
	// переменной next назначем значение NULL
	node->next = NULL;
	// возвращаем элемент
	return node;
}


// вставка нового элемента в начало списка
void push_front(t_list **list, int set_serial_number, char* set_firma, char* set_model, int set_series, int set_year) {
	// создаем новый элемент функцией create_node()
	t_list* new_element = create_node(set_serial_number, set_firma, set_model, set_series, set_year);
	// присваеваем переменной next нового элемента список
	new_element->next = *list;
	// переопределяем текущий список на новый элемент
	*list = new_element;
}


// вставка нового элемента в конец списка
void push_back(t_list** list, int set_serial_number, char* set_firma, char* set_model, int set_series, int set_year) {
	// создаем новый элемент функцией create_node()
	t_list* new_element = create_node(set_serial_number, set_firma, set_model, set_series, set_year);
	// создаем указатель-копию на текущий список
	t_list* tmp = *list;
	// проходим по списку, пока next не будет равно NULL (т.е. это последний элемент списка)
	while (tmp->next != NULL)
	{
		tmp = tmp->next;
	}
	// полю next последнего элемента списка присваеваем новый созданный элемент
	tmp->next = new_element;
}


// вставка элемента в середину списка
void push_after(t_list **list, int set_serial_number, char* set_firma, char* set_model, int set_series, int set_year, int after_serial_number) {
	// создаем указатель-копию на текущий список
	t_list* tmp = *list;
	// проходим по списку, пока next не будет равно NULL
	while (tmp->next != NULL)
	{
		// находим элемент списка, после которого мы хотим вставить нвоый элемент
		if (tmp->serial_number == after_serial_number)
		{
			// создаем новый элемент
			t_list* new_element = create_node(set_serial_number, set_firma, set_model, set_series, set_year);
			// переменной next у нового созданного элемента мы присваеваем значение поля next элемента, после которого мы хотим вставить новый элемент
			new_element->next = tmp->next;
			// присваеваем полю next элемента после которого мы хотим вставить, ссылку на созданный элемент
			tmp->next = new_element;
		}
		tmp = tmp->next;
	}
}


// печатаем список
void print_list(t_list **list) {
	// создаем указатель-копию на текущий список
	t_list* tmp = *list;
	// проходим по списку, пока next не будет равно NULL
	while (tmp != NULL)
	{
		// печатаем элемент списка
		printf("serial_number = %d, firma = %s, model = %s, series = %d, year = %d\n", tmp->serial_number, tmp->firma, tmp->model, tmp->series, tmp->year);
		tmp = tmp->next;
	}

}



int main() {
	// создаем указатель типа t_list и присваеваем значение функции create_node()
	t_list* list = create_node(0, "firma0", "model0", 00, 2022);

	// суем в начало списка новые элементы
	push_front(&list, 1, "front1", "model1", 11, 2022);
	push_front(&list, 2, "front2", "model2", 22, 2023);
	push_front(&list, 3, "front2", "model3", 22, 2024);
	
	// суем в конец списка новые элементы
	push_back(&list, 1, "back1", "model1", 11, 2022);
	push_back(&list, 5, "back2", "model2", 22, 2023);
	push_back(&list, 6, "back3", "model3", 33, 2024);

	// суем в середину списка после элемента с каким то serial_number
	push_after(&list, 7, "insert1", "model1", 11, 2022, 3);

	print_list(&list);

	return 0;
}