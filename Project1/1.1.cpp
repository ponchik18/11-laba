//1.1.cpp            ОСНОВНОЙ ФАЙЛ

#include"1.2.h"

int main() {
	setlocale(0, "RUS");
	system("color 75");
	int choice = 0;
	
	do {
		CLEAN
		menu();
		choice = getValue(choice);
		switch (choice) {
		case 1:
			ClEANCONSOLE
			CinInfoAboutStudent();
			break;
		case 2:
			PrintInfoAboutStudent();
			break;
		case 3:
			ClEANCONSOLE
				SortStudent();
			break;
		case 4:
			InfoAboutBestStudent();
			break;
		case 5:
			DeleteInfoAboutStedent();
			break;
		case 6:
			return 0;
			break;
		default:
			cout << "Ошибка выберите верную операцию" << endl;
			break;
		}
	} while (choice!=6);
	return 0;
}
