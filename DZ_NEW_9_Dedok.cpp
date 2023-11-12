#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
int main()
{
    setlocale(LC_ALL, "RUS");
	//Task_1
    FILE* file = fopen("task_1.txt", "r");

    if (file == nullptr) {
        printf("Не удалось открыть файл\n");
        return 1;
    }
    char currentLine[1000];
    int maxLength = 0;

    
    while (fgets(currentLine, sizeof(currentLine), file) != nullptr) {
        int currentLength = 0;
        while (currentLine[currentLength] != '\0' && currentLine[currentLength] != '\n') {
            currentLength++;
        }
        if (currentLength > maxLength) {
            maxLength = currentLength;
        }
    }
    printf("Самая длинная строка имеет длину %d символов\n", maxLength);
    fclose(file);
    cout << "\n";
    //Task_2
    FILE* file_1 = fopen("task_2.txt", "r");

    if (file_1 == nullptr) {
        printf("Не удалось открыть файл\n");
        return 1;
    }
    printf("Введите слово для поиска: ");
    char searchWord[100]; 
    scanf("%s", searchWord);
    char currentLine_1[1000]; 
    int occurrences = 0;
    while (fgets(currentLine_1, sizeof(currentLine_1), file_1) != nullptr) {
        char* found = currentLine_1;
        while ((found = strstr(found, searchWord)) != nullptr) {
            occurrences++;
            found += strlen(searchWord);
        }
    }
    printf("Слово \"%s\" встречается в файле %d раз(а)\n", searchWord, occurrences);
    fclose(file_1);
    return 0;
}
