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

void Uppercase_to_Lowercase_Letters_in_File(FILE* p_file_1)
{
	FILE* p_file_2 = fopen(R"(F:\file_7.txt)", "w");
	char c_file;

	do
	{
		c_file = fgetc(p_file_1);
		if (c_file == -1)
		{
			break;
		}
		if (c_file >= 'A' && c_file <= 'Z')
		{
			fprintf(p_file_2, "%c", c_file + ('a' - 'A'));
		}
		else
		{
			fprintf(p_file_2, "%c", c_file);

		}
	} while (c_file != EOF);
}


void Concatenation_of_Files()
{
	char str_user_file[200];
	FILE* p_file_1 = fopen(R"(F:\fres.txt)", "w");
	char str_user_buffer[200];

	do
	{
		cout << "Example F:\\name_file.type\\name_file.type\n0 - to stop\n";
		cin.getline(str_user_file, 200);

		FILE* p_file_2 = fopen(str_user_file, "r");

		if (str_user_file[0] == '0')
		{
			break;
		}

		if (p_file_2 == nullptr)
		{
			cout << "ERROR!\n";
			continue;
		}

		while (fgets(str_user_buffer, 200, p_file_2) != nullptr)
		{
			fprintf(p_file_1, "%s", str_user_buffer);
		}

		fprintf(p_file_1, "\n");
	} while (str_user_file[0] != '0');
}

void Only_Letters_and_Numbers()
{
	FILE* p_file_1 = fopen(R"(F:\file_2.txt)", "r");
	FILE* p_file_2 = fopen(R"(F:\file_11.txt)", "w");
	FILE* p_file_3 = fopen(R"(F:\file_12.txt)", "w");
	char c_file_1;
	char c_copy = ' ';

	do
	{
		c_file_1 = fgetc(p_file_1);

		if ((c_file_1 == '\n') && ((c_copy >= 'A' && c_copy <= 'Z') || (c_copy >= 'a' && c_copy <= 'z')))
		{
			fprintf(p_file_2, "\n");
		}
		else if((c_file_1 == '\n') && ((c_copy >= '0' && c_copy <= '9')))
		{
			fprintf(p_file_3, "\n");

		}

		if ((c_file_1 >= 'A' && c_file_1 <= 'Z') || (c_file_1 >= 'a' && c_file_1 <= 'z'))
		{
			fprintf(p_file_2, "%c", c_file_1);
		}
		else if (c_file_1 >= '0' && c_file_1 <= '9')
		{
			fprintf(p_file_3, "%c", c_file_1);

		}

		c_copy = c_file_1;

	} while (c_file_1 != EOF);
}

int main()
{
	// Завдання 1

	/*char text[100][100];
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

	delete[] p_char;*/

	// Завдання 2

	/*Concatenation_of_Files();*/
	/*cout << "Done!\n";*/

	// Завдання 3

	/*FILE* p_file_1 = fopen(R"(F:\file_2.txt)", "r");

	if (p_file_1 == nullptr)
	{
		cout << "ERROR!\n";
		return -1;
	}

	Uppercase_to_Lowercase_Letters_in_File(p_file_1);

	cout << "Done!\n";*/

	// Завдання 4

	/*Only_Letters_and_Numbers();
	cout << "Done!\n";*/

	return 0;
}