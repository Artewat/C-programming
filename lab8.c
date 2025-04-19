#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Clients {
    char Sname[100];
    char Name[100];
    int byear;
    char Gender;
    double height;
};

int strcount() {
    int c = 0;
    char buffer[256];
    FILE *fp = fopen("input.txt", "r");
    if (!fp) {
        printf("Не удалось открыть файл.\n");
        exit(1);
    }

    while (fgets(buffer, sizeof(buffer), fp) != NULL) {
        c++;
    }
    fclose(fp);
    return c;
}

void loadData(struct Clients clients[], int count) {
    FILE *file = fopen("input.txt", "r");
    char buffer[256];
    int c = 0;

    while (fgets(buffer, sizeof(buffer), file) != NULL && c < count) {
        sscanf(buffer, "%s %s %d %c %lf", clients[c].Sname, clients[c].Name, &clients[c].byear, &clients[c].Gender, &clients[c].height);
        c++;
    }

    fclose(file);
}

int compare(struct Clients a, struct Clients b, int mode) {
    switch (mode) {
        case 1: return strcmp(a.Sname, b.Sname);
        case 2: return strcmp(a.Name, b.Name);
        case 3: return a.byear - b.byear;
        case 4: return a.Gender - b.Gender;
        case 5: return (a.height > b.height) - (a.height < b.height);
        default: return 0;
    }
}

void sort(struct Clients arr[], int size, int key1, int key2) {
    struct Clients temp;
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            int cmp1 = compare(arr[j], arr[j + 1], key1);
            int cmp2 = compare(arr[j], arr[j + 1], key2);
            if (cmp1 > 0 || (cmp1 == 0 && cmp2 > 0)) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void printClients(struct Clients clients[], int count) {
    printf("\nОтсортированный список:\n");
    for (int i = 0; i < count; i++) {
        printf("%s %s %d %c %.2lf\n", clients[i].Sname, clients[i].Name, clients[i].byear, clients[i].Gender, clients[i].height);
    }
}

int main() {
    
    int lines = strcount();
    struct Clients clients[lines];

    loadData(clients, lines);

    printf("Как отсортировать массив?\n");
    printf("1. По фамилии\n");
    printf("2. По имени\n");
    printf("3. По дате рождения\n");
    printf("4. По полу\n");
    printf("5. По росту\n\n");

    printf("Введите 1 или 2 цифры (например, 13 — по фамилии, потом по году рождения): ");
    
    char input[10];
    scanf("%s", input);

    int key1 = input[0] - '0';
    int key2 = (input[1] != '\0') ? (input[1] - '0') : 0;

    if (key1 < 1 || key1 > 5 || (key2 != 0 && (key2 < 1 || key2 > 5))) {
        printf("Неверный ввод критериев сортировки.\n");
        return 1;
    }

    sort(clients, lines, key1, key2);
    printClients(clients, lines);

    return 0;

}
