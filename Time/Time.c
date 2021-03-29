#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>
//-------------------------------------------------------------------
int Mode1();
//int Mode2();
void Works(int count, char** works);
int Output(char** works, char* complited, int count);
int Time(char** works,int number);
int Again(char** works, int number);
int Input();
void Write(char** works, char* complited, int count);
//int Check();
//-------------------------------------------------------------------
int main(void){
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    printf("\tTIME\nПрограмма создана для концентрации внимания\n\t\t\tДандя\n");
    int power = 1;
    while(power){
        printf("Какой режим хотите выбрать? (Ответ - цифра)\n1) Помидор(Pomodoro);\n2) Заметки(ещё не реализовано);\n3) Выход из программы.\nВведите: ");
        int answer = 0;
        scanf("%d", &answer);
        int result = 0;
        if (answer == 1) result = Mode1();
        else if(answer == 3) return 1;
        else{
            while(answer != 1 && answer != 3){
                printf("Введите ещё раз: ");
                scanf("%d", &answer);
            }
            if (answer == 3) return 1;
            result = Mode1();
        }
        if (result == -1){
            printf("Хотите выйти в меню(m) или из приложения(a)?\n");
            fflush(stdin);
            answer = (int)(getchar());
            if(answer == (int)('a')) break;
            else if (answer == (int)('m')) continue;
            else{
                printf("Неизвестный ответ - выходим в меню\n");
                continue;
            }
        }else{
            continue;
        }
    }
    return 0;
}
//-------------------------------------------------------------------
int Mode1(){
    int count = 0;
    printf("На скольких делах вы хотите соcредаточиться?\nВведите количество: ");
    scanf("%d", &count);
    char** works = (char**)malloc(count*sizeof(char*)); //Массив со списком дел
    Works(count, works);
    char complited[count];
    for(int i = 0; i<count; i++)
        complited[i] = '-';
    for(int i = 0; i<count; i++){
        int result = Output(works, complited, count);
        if(result == -1){
            Write(works, complited, count);
            return -1;
        }
    }
    Write(works, complited, count);
    return 1;
}
//-------------------------------------------------------------------
/*int Mode2(){ // Режим заметок
    FILE* app;
    int check = Check();
    if (check == 0) app = fopen("app.txt", "r");
    else{
        app = fopen("app.txt", "w");
        printf("Какую программу вы хотите выбрать для создания заметок?\n1) Notepad;\n2) Vim;\n3) Nano;\n4) Vi;\n5) Своя (записать в фаил app.txt команду для запуска в терминале).\n");
        printf("Введите номер программы: ");
        int answer;
        scanf("%d", &answer);
        while (answer<1&&answer>5){
            printf("Введён неверный ответ.\nВведите ещё раз: ");
            scanf("%d", &answer);
        }
        if (answer == 5){
            printf("Введите команду: ");
            char App[20];
            fflush(stdin); 
            scanf("%s", App);
            fprintf(app, "%s\n", App);
            fclose(app);
            app = fopen("app.txt", "r");
        } 
        else{
            char* Programms[] = {"notepad.exe", "vim", "nano", "vi"};
            fprintf(app, "app:\n%s\n", Programms[answer-1]);
            fclose(app);
            app = fopen("app.txt", "r");
        }
    }
    char App[20]; // Приложение для работы с заметками
    fflush(app);
    fgets(App,20, app);
    fgets(App,20, app);
    fclose(app);
    printf("Что хотите сделать?\n1) Создать/открыть записку;\n2) Посмотреть список записок.\n");
    int answer;
    fflush(stdin);
    printf("Введите ответ: ");
    scanf("%d", &answer);
    while (answer<1&&answer>3){
        printf("Введён неверный ответ.\nВведите ещё раз: ");
        scanf("%d", &answer);
    }
    switch (answer){
    case 1:
        printf("Введите название записки: ");
        char Name[256];
        fflush(stdin);
        fgets(Name, 250, stdin);
        strcat(Name,".txt"); 
        char Dir[] = {" ./Note/"};
        char Namefile[266];
        strcat(Namefile, App);
        strcat(Namefile, Dir);
        strcat(Namefile, Name);
        printf("%s", Namefile);
        system(Namefile);
        break;
    case 2:
        system("cd  ./Note/");
        system("dir");
        system("cd ../");
        break;
    default:
        break;
    }

}*/
//-------------------------------------------------------------------
void Works(int count, char** works){
    printf("На каких делах вы хотите сосредоточиться?\n"); 
    int index = 0;
    while(index<count){
        works[index] = (char*)malloc(50*sizeof(char));
        fflush(stdin);
        fgets(works[index],49,stdin);
        int len = strlen(works[index]);
        works[index] = (char*)realloc(works[index], len*sizeof(char));
        index++;
    }
}
//-------------------------------------------------------------------
int Output(char** works, char* complited, int count){
    printf("Каким делом вы хотите заняться? (Введите номер)\n");
    for(int i = 0; i<count; i++)
        printf("%d) [%c] %s", i+1, complited[i], works[i]);
    printf("Ваш выбор: ");
    int number;
    fflush(stdin);
    scanf("%d", &number);
    int result = Time(works, number-1);
    if (result == 1){
        printf("\nДело выполнено?\n");
        int answer = Input();
        if (answer == 1){
            complited[number-1] = '+';
            return 1;
        }
        else if (answer == 0){
            result = Again(works,number-1);
            if(result == 1) complited[number-1] = '+';
            else return result;
        }
        else return answer;
    }else return -1;
    return 1;
}
//-------------------------------------------------------------------
int Time(char** works,int number){
    int time = 0; 
    for (int o = 1; o<=4; o++){    //Будем использовать метод Помидора :)
        time = 0;
        system("cls");
        printf("Занятие: %sРежим: работа\nВремя: %2d:%2d", works[number], time/60, time%60);
        while(time != 1500){
            Sleep(1000);
            printf("\b\b\b\b\b");                     
            time++;
            printf("%2d:%2d", time/60, time%60);
        }
        system("cls");
        time = 0;
        if(o != 4){
            printf("Занятие: %sРежим: короткий отдых\nВремя: %2d:%2d", works[number], time/60, time%60);
            while(time != 300){
                Sleep(1000);
                printf("\b\b\b\b\b");                     
                time++;
                printf("%2d:%2d", time/60, time%60);
            }
            printf("\nПродолжаем? (y/n)\n");
            int answer = Input();
            if (answer == 1) continue;
            else if (answer == 0) break;
            else return answer;
        }else{
            printf("Занятие: %sРежим: долгий отдых\nВремя: %2d:%2d", works[number], time/60, time%60);
            while(time != 1800){
                Sleep(1000);
                printf("\b\b\b\b\b");                     
                time++;
                printf("%2d:%2d", time/60, time%60);
            }
        }
    }
    return 1;
}
//-------------------------------------------------------------------
int Again(char** works, int number){
    int result = Time(works, number);
    if (result == 1){
        printf("Дело выполнено?\n");
        int answer = Input();
        if (answer == 1) return 1;
        else if (answer == 0){
            result = Again(works,number);
            return result;
        }
        else return answer;
    }else return -1;
    return 1;
}
//-------------------------------------------------------------------
int Input(){
    fflush(stdin);
    char doing = getchar();
    switch (doing)
    {
    case 'y':
        return 1; break;
    case 'д': 
        return 1; break;
    case 'n':
        return 0; break;
    case 'н':
        return 0; break;
    case 'e':
        return -1; break;
    case 'h':
        printf("Помощь:\ny/д - Принять или Да;\nn/н - Отклонить или Нет;\ne - Выход;\nh -  Помощь.\n"); 
        return Input(); break;    
    default:
        printf("Неизвесный ответ.\nh - Помощь\nВведите ответ ещё раз: ");
        return Input();
        break;
    }
}
//-------------------------------------------------------------------
void Write(char** works, char* complited, int count){
    FILE* list = fopen("List_of_works.txt", "a+");
    fseek(list, 0, SEEK_END);
    time_t Time = time(NULL);
    fprintf(list, "\t\t%s\n", ctime(&Time));
    for (int i = 0; i<count; i++){
        fprintf(list,"%c ~ %s", complited[i], works[i]);
    }
    fclose(list);
}
//-------------------------------------------------------------------
/*int Check(){
    FILE* app = fopen("app.txt", "r");
    if (app == NULL) return -1;
    else{
        fclose(app);
        return 0;
    }
}*/
//-------------------------------------------------------------------