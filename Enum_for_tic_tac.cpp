
#include <iostream>
#include <locale>



/*задание первое (вывод ниже по коду)*/
short int a = 1;
int b = 2;
long int c = 3;
long long d = 4;
char e = 'A';
bool f = true;
float g = 3.14;
double h = 2.7182818284;

/*задание второе и третее (его вывод так же ниже, но происходит до переменных) массив так же ниже*/

enum TToe { X = -2, O, _ };
TToe fp = X;                                    // вот тут Visual Studio дает предупреждение (Тип перечисления "TToe" не входит в область. Старайтесь использовать "enum class" вместо "enum")
TToe fs = O;
TToe sp = _;

/*четвертое задание (в нем я совсем не уверен потому как кодом не смог пока его пощупать)*/

struct GameLevel
{
    TToe mas[3][3];                             // массив поля для игры
    int Score1 : 3;                             // счетчики очков первого и второго игроков
    int Score2 : 3;
    char Name1[10];                             // имена игроков
    char Name2[10];
};


/*Создать структуру (struct MyVariant) объединяющую: union MyData (int, float, char) и 3-и битовых поля (флага) указывающими 
какого типа значение в данный момент содержится в объединении (isInt, isFloat, isChar). Продемонстрировать пример использования 
в коде этой структуры.*/

struct MyVariant {
    unsigned int isInt : 1;
    unsigned int isFloat : 1;
    unsigned int isChar : 1;
    union MyData
    {
        char ca;
        int ib;
        float fc;
    };
};
/*пока полностью не разобрался как в код запихнуть это объединение. надеюсь, еще доработаю этот код. а так, по честному, что то пока сыро у меня с 
перечислениями, структурами и объединениями.*/

int main(int argc, char *argv[])
{

    setlocale(LC_ALL, "Ru");
    std::cout << fp << " " << fs << " " << sp << std::endl << std::endl;
                                                // вывод на экран переменных типа перечисления

/*============================================*/
    
    TToe mas[3] = { X, O, _};                   //массив хранящий значения перечисления TToe
    for (int i = 0; i < 3; i++)                 //цикл вывода массива в терминал
    {
        std::cout << mas[i] << " ";             //вывод значений массива в терминал
    }
    std::cout << std::endl;
    
/*============================================*/

    GameLevel ms;
    std::cout << "Введите имя 1-го игрока: ";
    std::cin >> ms.Name1; std::cout << std::endl;
    std::cout << "Введите имя 2-го игрока: ";
    std::cin >> ms.Name2; std::cout << std::endl;
    ms.Score1 = 0;
    ms.Score2 = 0;

    std::cout << "Имя первого игрока " << ms.Name1 << std::endl;
    std::cout << "Имя второго игрока " << ms.Name2 << std::endl;
    std::cout << "Стартовый счет      " << ms.Score1 << "    " << ms.Score2 << std::endl;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            ms.mas[i][j] = sp;
        }
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            std::cout << ms.mas[i][j] << " ";
        }
        std::cout << std::endl;
    }

    std::cout << std::endl << std::endl;


/*=======================================*/

    std::cout << "Переменная типа short int:\t " << a << "\t\tзанимает байт:\t" << sizeof(a) << "\tадрес в памяти переменной:\t" << &a << std::endl;
    std::cout << "Переменная типа int:\t\t " << b << "\t\tзанимает байт:\t" << sizeof(b) << "\tадрес в памяти переменной:\t" << &b << std::endl;
    std::cout << "Переменная типа long int:\t " << c << "\t\tзанимает байт:\t" << sizeof(c) << "\tадрес в памяти переменной:\t" << &c << std::endl;
    std::cout << "Переменная типа long long:\t " << d << "\t\tзанимает байт:\t" << sizeof(d) << "\tадрес в памяти переменной:\t" << &d << std::endl;
    std::cout << "Переменная типа char:\t\t " << e << "\t\tзанимает байт:\t" << sizeof(e) << "\tадрес в памяти переменной:\t" << &e << std::endl;
    // вот, кстати, адрес символа вылетает какой то странный. при первом запуске в адресе вылетело (AMMMMMMMMMMM) второй раз вылетело (A и пара смайлов)
    std::cout << "Переменная типа bool:\t\t " << f << "\t\tзанимает байт:\t" << sizeof(f) << "\tадрес в памяти переменной:\t" << &f << std::endl;
    std::cout << "Переменная типа float:\t\t " << g << "\t\tзанимает байт:\t" << sizeof(g) << "\tадрес в памяти переменной:\t" << &g << std::endl;
    std::cout << "Переменная типа double:\t\t " << h << "\tзанимает байт:\t" << sizeof(h) << "\tадрес в памяти переменной:\t" << &h << std::endl;

/*========================================*/
/* Непонятный адрес выводит команда &e относительно типа данных char. вопрос: что это может быть?*/

    MyVariant::MyData temp; // вот на этом месте я поплыл...

   return 0;
}

