#include <iostream>
#include <string>
#include <fstream>
#include "MyLib.h"

#define TFComand (a>=0 && a<b)?std::cout<<"True":std::cout<<"false"
#define SMAS 5
#define SwapINT(a, b) \
a = a xor b; \
b = b xor a; \
a = a xor b

#pragma pack(push, 1)
struct Worker {
    long id_w;
    std::string name;
    int id_work;
    std::string name_work;
};
#pragma pack(pop)

using namespace MSpace;
/*Если честно, я не совсем уверен, что этот код именно то, что является ответом на 1-е и 5-е задание урока... */
/*плюс бонусом есть неуверенность в том, что если с помощью своей библиотеки я захочу создать еще парочку массивов
то размер их не изменится (небольшая хитрость с размером массива лежит в самой библиотеке)*/
int main()
{
    setlocale(LC_ALL, "Ru");
    //========= Задание 4 ============
    Worker* e1 = new Worker;
    Worker* e2 = new Worker;
    e1->id_w = 1;
    e1->id_work = 1;
    e1->name = "Tony Stark";
    e1->name_work = "Creator";
    e2->id_w = 2;
    e2->id_work = 2;
    e2->name = "Jarvis";
    e2->name_work = "AI butler";
    std::cout << e1->name <<"  "<< sizeof(e1)<< "  " << e1->name_work << "  "  << std::endl;
    std::cout << e2->name << "  " << sizeof(e1) << "  " << e2->name_work << "  " << std::endl;
    std::ofstream out("ironman.txt");
    if (out.is_open() ) {
        out << e1->name << e1->id_w << "  "  << e1->name_work << e1->id_work << std::endl << sizeof(e1)<< std::endl;
        out << e2->name << e2->id_w << "  " << e2->name_work << e2->id_work << std::endl << sizeof(e2) << std::endl;
    }
    out.close();

    //========= Задание 3 ============
    int mas[SMAS];
    for (int i = 0; i < SMAS; i++) {
        std::cin >> mas[i];
    }
    int cell;
    do {
        cell = 0;
        for (int i = 0; i < SMAS; i++) {
            if (i + 1 < SMAS) {
                if (mas[i] > mas[i + 1]) {
                    SwapINT(mas[i], mas[i + 1]);
                    cell++;
                }
            }
        }
    } while (cell != 0);
    for (int i = 0; i < SMAS; i++) {
        std::cout << mas[i] << "  ";
    }

    //========= Задание 2 ============
    const int b = 10;
    int a;
    std::cin >> a;
    TFComand;

    //========= Задание 1 и 5 ============
    float* ukz = ConstructMas();
    std::cout << ukz << std::endl;
    InitMas(ukz);
    ScoreMas(ukz);
    ShowMas(ukz);
    ConstructMas(ukz);
    return 0;
}

