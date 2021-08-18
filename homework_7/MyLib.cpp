#include <iostream>

size_t SIZEMAS;

namespace MSpace {
	float* ConstructMas() {
		std::cout << "¬ведите длинну массива: ";
		
		std::cin >> SIZEMAS;
		float* mas = new float[SIZEMAS];
		return mas;
	}

	void ConstructMas(float* mas) {
		delete mas;
	}

	void InitMas(float* mas) {
		for (int i = 0; i < SIZEMAS; i++) {
			std::cin >> mas[i];
		}

	}

	void ScoreMas(float* mas) {
		int i = 0;
		float acp =0;
		float acn =0;
		while (i < SIZEMAS) {
			if (mas[i] < 0) {
				acn += mas[i];
			}
			else {
				acp += mas[i];
			}
			i++;
		}
		std::cout << "сумма положительных элементов массива: " << acp << std::endl;
		std::cout << "сумма отрицательных элементов массива: " << acn << std::endl;
	}

	void ShowMas(float* mas) {
		for (int i = 0; i < SIZEMAS; i++) {
			std::cout << mas[i] << "  ";
		}
	}
}