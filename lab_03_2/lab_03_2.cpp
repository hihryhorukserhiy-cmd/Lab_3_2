#include <iostream>
#include <Windows.h>
#include "Window.h"
#include "MenuWindow.h"

using namespace std;

Window ProcessWindow(Window w)
{
	cout << "[ProcessWindow] Отримано базова вікно: " << w << endl;
	w.SetBgColor("System_Default");
	cout << "[ProcessWindow] Колір змінено: " << w << endl;
	return w;
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	cout << "--- 1. Створення об'єктів та масивів ---\n";
	Window wBase(0, 0, 800, 600, "Blue");
	cout << "Базове вікно: " << wBase << endl;

	MenuWindow mw1(10, 10, 500, 400, "Gray", "File_Edit_View");
	cout << "Вікно з меню: " << mw1 << "\n\n";

	// Статичний масив базових класів
	Window winArr[2]{ Window(0, 0, 100, 100, "Red"), Window(50, 50, 200, 200, "Green") };
	cout << "Масив базових вікон:\n1: " << winArr[0] << "\n2: " << winArr[1] << "\n\n";

	// Динамічний масив похідних класів
	MenuWindow* mwArr = new MenuWindow[2];
	mwArr[0] = MenuWindow(5, 5, 50, 50, "Black", "Tools");
	cout << "Динамічний масив вікон з меню (елемент 0): " << mwArr[0] << "\n\n";

	cout << "--- 2. Демонстрація принципу підстановки ---\n";
	cout << "Передаємо MenuWindow у функцію, що очікує Window (зрізування до базового):\n";
	Window processed = ProcessWindow(mw1);
	cout << "Результат повернення: " << processed << "\n\n";

	cout << "--- 3. Робота функцій перепризначення (Завдання 13) ---\n";
	cout << "До перепризначення: " << mw1 << endl;
	mw1.ReassingBgColor("Dark_Mode");
	mw1.ReassingMenu("Settings_Help");
	cout << "Після перепризначення: " << mw1 << "\n\n";

	delete[] mwArr;


	cout << "--- 4. Інтерактивне введення (operator>>) ---\n";
	MenuWindow userWin;
	cout << "Введіть дані для нового вікна з меню (коректні):\n";
	cin >> userWin;
	cout << "\nВи успішно ввели: " << userWin << "\n\n";

	cout << "--- 5. Перевірка контролю аргументів (Завершення програми) ---\n";
	cout << "Спроба встановити некоректну координату X1 (більшу за Х2) для вікна...\n";

	userWin.SetX1(9999);
	return 0;
}