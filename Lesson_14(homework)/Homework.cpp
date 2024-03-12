#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>

using namespace std;

char* Popular_Line(char text[100][100], int counter_line)
{
	char temp_char[100];
	int counter_1 = -1;
	int counter_2 = 0;
	strcpy(temp_char, "");

	for (int i = 0; i < counter_line; i++)
	{
		for (int j = 0; j < counter_line; j++)
		{
			if (strcmp(text[i], text[j]) == 0)
			{
				counter_1++;
			}
		}
		if (counter_1 > counter_2)
		{
			strcpy(temp_char, text[i]);
			counter_2 = counter_1;
		}
		counter_1 = -1;
	}

	if (temp_char[0] == '\0')
	{
		strcpy(temp_char, "There is no such line!");
	}

	char* p_char = new char[strlen(temp_char) + 1];
	strcpy(p_char, temp_char);

	return p_char;
}


int main()
{
	// Завдання 1

	char text[100][100];
	int counter = 0;

	FILE* p_file = fopen(R"(F:\file_6.txt)", "r");

	if (p_file == nullptr)
	{
		cout << "ERROR!\n";
		return -1;
	}


	while (fgets(text[counter], 100, p_file) != nullptr)
	{
		counter++;
	}

	fclose(p_file);

	char* p_char = Popular_Line(text, counter);

	cout << p_char << endl;

	delete[] p_char;

	return 0;
}