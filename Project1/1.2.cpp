//1.2.cpp           ФАЙЛ С ФУНКЦИЯМИ
#include"1.2.h"
typedef struct STUDENT {
public:
	char* FirstName; // ИМЯ
	char* LastName; // ФАМИЛИЯ
	char* Surname; // ОТЧЕСТВО
	int GroupeNumber; // НОМЕР ГРУППЫ
	int Marks[5]; // УСПЕВАЕМОСТЬ

	STUDENT(const char* fn="None", const char* ln="None", const char* sn="None", int g=0, int* m=0) {
		FirstName = new char[strlen(fn) + 1];
		strcpy(FirstName, fn);
		LastName = new char[strlen(ln)+1];
		strcpy(LastName, ln);
		Surname = new char[strlen(sn) + 1];
		strcpy(Surname, sn);
		GroupeNumber = g;
		if (m != 0) {
			for (register short unsigned i=0; i < 5; i++) {
				Marks[i] = m[i];
			}
		}
		else
			for (register short unsigned i=0; i < 5; i++) {
				Marks[i] = 0;
			}
	}

	~STUDENT() {
		delete[] LastName;
		delete[] FirstName;
		delete[] Surname;
	}

	STUDENT(STUDENT& st) {
		FirstName = new char[strlen(st.FirstName) + 1];
		strcpy(FirstName, st.FirstName);
		LastName = new char[strlen(st.LastName) + 1];
		strcpy(LastName, st.LastName);
		Surname = new char[strlen(st.LastName) + 1];
		strcpy(Surname, st.LastName);
		GroupeNumber = st.GroupeNumber;
		for (register short unsigned i=0; i < 5; i++) {
			Marks[i] = st.Marks[i];
		}
	}
	STUDENT operator= (const STUDENT& st) {
		FirstName = new char[strlen(st.FirstName) + 1];
		strcpy(FirstName, st.FirstName);
		LastName = new char[strlen(st.LastName) + 1];
		strcpy(LastName, st.LastName);
		Surname = new char[strlen(st.LastName) + 1];
		strcpy(Surname, st.LastName);
		GroupeNumber = st.GroupeNumber;
		for (register short unsigned i=0; i < 5; i++) {
			Marks[i] = st.Marks[i];
		}
		return *this;
	}
	void Info() {
		cout.width(20);
		cout << LastName << " " << FirstName[0] << ". " << Surname[0] << ".";
		cout.width(20);
		cout << GroupeNumber;
		cout.width(20);
		cout << Marks[0] << ", " << Marks[1] << ", " << Marks[2] << ", " << Marks[3] << ", " << Marks[4] << ". " << endl;
	}
}STUDENT; // Структура студент
}STUDENT; // Структура студент
////////// Переменные
static STUDENT* undergraduate; // структура для хранения данных о студентах
static STUDENT* tmp; // структура для хранения временных данных(нужно для сортировки)
static int CountStudent = 0; // Количество студентов

///////////// Вспомогательные функции

static void DinamicAllocate() {
	tmp = new STUDENT[CountStudent];
	for (register int i = 0; i < CountStudent-1; i++) {
		tmp[i] = undergraduate[i];
	}
	delete[] undergraduate;
	undergraduate = tmp;
}
static char* CoutString() {

	char c;
	int len = 1;
	char* str = new char[0];
	while ((c = cin.get()) != '\n')
	{
		char* temp = new char[len + 1];

		for (int i = 0; i < len - 1; i++) {
			temp[i] = str[i];
		}
		temp[len - 1] = c;
		temp[len] = '\0';
		delete[] str;
		str = temp;
		len++;
	}
	return str;
}
static void InfoClassification() {
	CLEAN
		cout.width(30);
	cout << "Фамилия и Инициалы";
	cout.width(24);
	cout << "Номер группы";
	cout.width(29);
	cout << "5 оценок студента" << endl;
	for (register int i = 0; i < 85; i++)
		cout << "_";
	cout << endl;
}
static void SortLastNameStudent() {
	STUDENT temp;
	for (register int i = 0; i < CountStudent; i++) {
		for (register int j = 0; j < CountStudent-1; j++) {
			if (strcmp(undergraduate[j].LastName, undergraduate[j + 1].LastName)>0) {
				temp = undergraduate[j];
				undergraduate[j] = undergraduate[j+1];
				undergraduate[j + 1] = temp;
			}
		}
	}
}
static void SortGroupeNumber() {
	STUDENT temp;
	for (register int i = 0; i < CountStudent; i++) {
		for (register int j = 0; j < CountStudent - 1; j++) {
			if (undergraduate[j].GroupeNumber > undergraduate[j + 1].GroupeNumber) {
				temp = undergraduate[j];
				undergraduate[j] = undergraduate[j + 1];
				undergraduate[j + 1] = temp;
			}
		}
	}
}
static float MiddleRes(int * s) {
	float sum=0;
	for (register int i = 0; i < 5; i++) {
		sum +=(float) *s;
		s++;
	}
	return sum / 5;
}
static void SortArtigmetic() {
	STUDENT temp;
	for (register int i = 0; i < CountStudent; i++) {
		for (register int j = 0; j < CountStudent - 1; j++) {
			if (MiddleRes(undergraduate[j].Marks) > MiddleRes(undergraduate[j + 1].Marks)) {
				temp = undergraduate[j];
				undergraduate[j] = undergraduate[j + 1];
				undergraduate[j + 1] = temp;
			}
		}
	}
}
//////////////// основные функции

extern void CinInfoAboutStudent() {
	CountStudent++;
	DinamicAllocate();
	cout << "Введите фамилию "<<CountStudent <<"-ого студента: " << endl;
	undergraduate[CountStudent - 1].LastName = CoutString();
	cout << "Введите имя " << CountStudent << "-ого студента: " << endl;
	undergraduate[CountStudent - 1].FirstName = CoutString();
	cout << "Введите отчество " << CountStudent << "-ого студента: " << endl;
	undergraduate[CountStudent - 1].Surname = CoutString();
	cout << "Введите группу " << CountStudent << "-ого студента: " << endl;
	undergraduate[CountStudent - 1].GroupeNumber = getValue(undergraduate[CountStudent - 1].GroupeNumber);
	cout << "Введите 5 оценок " << CountStudent << "-ого студента: " << endl;
	for (register short unsigned i = 0; i < 5; i++) {
		cout <<"\t" << i + 1 << ": ";
		undergraduate[CountStudent - 1].Marks[i] = getValue(undergraduate[CountStudent - 1].Marks[i]);
	}

} 
extern void PrintInfoAboutStudent() {
	if (CountStudent == 0) {
		cout << "Сначало нужно ввести данные" << endl;
		PAUSE
		return;
	}
	InfoClassification();
	for (register int i = 0; i < CountStudent; i++) {
		cout << i + 1 << ":";
		undergraduate[i].Info();
	}
	PAUSE
}
extern void DeleteInfoAboutStedent() {
	if (CountStudent == 0) {
		cout << "Сначало нужно ввести данные" << endl;
		PAUSE
	}
	else {
		delete[] undergraduate;
		CountStudent = 0;
	}

}
extern void menu() {
	////////////
	cout << "+-----------------------------------------------------------------------------------------+" << endl << "|";
	cout.width(50);
	cout << "Меню";
	cout.setf(ios::right);
	cout.width(40);
	cout << "|" << endl;
	////////////
	cout << "+-----------------------------------------------------------------------------------------+" << endl << "|";
	cout.width(65);
	cout << "1. Ввод данных о студенте с клавитуре;";
	cout.setf(ios::right);
	cout.width(25);
	cout << "|" << endl;
	cout << "|";
	/////////////
	cout.width(55);
	cout << "2. Вывод данных о студентах;";
	cout.setf(ios::right);
	cout.width(35);
	cout << "|" << endl;
	cout << "|";
	//////////////
	cout.width(61);
	cout << "3. Сортировка данных по параметру;";
	cout.setf(ios::right);
	cout.width(29);
	cout << "|" << endl;
	cout << "|";
	/////////////////
	cout.width(85);
	cout << "4. Вывести информацию о лучших студентах, с оценках 8 и 9;";
	cout.setf(ios::right);
	cout.width(5);
	cout << "|" << endl;
	cout << "|";
	//////////////////
	cout.width(59);
	cout << "5. Отчистить данные о студентах;";
	cout.setf(ios::right);
	cout.width(31);
	cout << "|" << endl;
	cout << "|";
	///////////////
	cout.width(47);
	cout << "6. Завершить работу.";
	cout.setf(ios::right);
	cout.width(43);
	cout << "|" << endl;


	cout << "+-----------------------------------------------------------------------------------------+" << endl;
}
extern void InfoAboutBestStudent() {
	if (CountStudent == 0) {
		cout << "Сначало нужно ввести данные" << endl;
		PAUSE
			return;
	}
	register int flag = 0;
	for (register int i = 0; i < CountStudent; i++) {
		int j = 0;
		for (j; j < 5 && (undergraduate[i].Marks[j] == 8 || undergraduate[i].Marks[j] == 9); j++) {}
		if (j == 5) {
			flag++;
			if (flag == 1) {
				InfoClassification();
			}
			undergraduate[i].Info();
		}
	}
	if (flag == 0) {
		cout << "Нет студентов только с оценками 8 и 9" << endl;
	}
	PAUSE
}
extern void SortStudent() {
	cout << "Выберите поля, по которому надо сделать сортировку:" << endl;
	cout << "\t1) Фамилия" << endl;
	cout << "\t2) Учебная группа" << endl;
	cout << "\t3) Средний балл" << endl;
	register int choice=0;
	choice = getValue(choice);
	register int flag = 0;
	while (flag==0) {
		switch (choice)
		{
		case 1:
			flag++;
			SortLastNameStudent();
			break;
		case 2:
			SortGroupeNumber();
			flag++;
			break;
		case 3:
			SortArtigmetic();
			flag++;
			break;
		default:
			cout << "Ошибка выберите правильное поле" << endl;
			choice = getValue(choice);
			break;
		}
	}
	cout << "Сортировка завершена!!!" << endl;
	PAUSE
}
//////////////