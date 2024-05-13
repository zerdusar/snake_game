#include <iostream>
#include "Snake.h"
#include "Fruit.h"
#include <Windows.h>
#include <fstream>
using namespace std;

void start()
{
	cout << "It`s a snake game." << endl;
	cout << "The best record in the world is 9999. Can you beat it?" << endl;
	cout << "Press any button to continue..." << endl;
	while(!_kbhit()){}
	system("cls");
	for (size_t i = 10; i != 0; --i)
	{
		cout << "The game will start in..." << endl;
		cout << i;
		Sleep(300);
		system("cls");
	}
}

int main()
{
	const size_t height = 10;
	const size_t width = 10;
	static const HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	Map map(height, width);
	Snake snake(3, 4);
	Fruit fruit;
	map.creat_fruit(fruit);
	map.draw(fruit);
	snake.draw(map);
	start();
	map.print(handle);
	while (snake.size() < height * width)
	{
		map.clear();
		map.draw(fruit);
		snake.draw(map);
		if (_kbhit()) {
			snake.input_direction();
			snake.change_direction();
		}
		snake.move(height, width);
		if (snake.is_broken())
			break;
		snake.eat(fruit, map);
		map.print(handle);
		Sleep(130);
	}
	system("cls");
	unsigned long long record = 0;
	ifstream inputfile("record.txt");
	if (inputfile.is_open()) {
		inputfile >> record;
		if (snake.size() > record) {
			record = snake.size();
			ofstream outputfile("record.txt");
			outputfile << record;
		}
		cout << "result: " << snake.size() << endl;
		cout << "record: " << record << endl;
		cout << "Press any button to continue..." << endl;
		while (!_kbhit()) {}
		system("cls");
		if (record > 9999)
			cout << "You`re a fucking cheater! Fuck you" << endl;
		else
			cout << "HAHA, you will never beat it!" << endl;
	}
	else
		cout << "result: " << snake.size() << endl;
	system("pause");
}

