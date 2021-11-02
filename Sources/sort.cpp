#include "sort.h"
#include "view.h"
#include <random>
#include <string>

/**
 * @brief Обмен значений двух чисел
 * @param digit1 - первое число
 * @param digit2 - второе число
 */
void Sort::Swap(int& digit1, int& digit2) {

    digit1 = digit1 + digit2;
    digit2 = digit1 - digit2;
    digit1 = digit1 - digit2;
}

/**
 * @brief Поиск индекса минимального элемента в векторе
 * @param array - вектор
 * @param left - левая граница поиска
 * @param right - правая граница поиска
 * @return minElementIndex - искомый индекс
 */
int Sort::FindMinElementIndex(std::vector<int>& array, int left, int right) {

    // Начальная инициализация индекса
    int minElementIndex = left;

    // Поиск минимального элемента, сохранение индекса
    for (int i = left + 1; i < right; i++) {

        if (array[minElementIndex] > array[i]) {

            minElementIndex = i;
        }
    }

    return minElementIndex;
}
/**
 * @brief Вставка элемента по индексу в вектор по возрастанию
 * @param array - вектор
 * @param index - индекс
 */
void Sort::InsertElement(std::vector<int>& array, int index) {

    // Вставляемый элемент
    int value = array[index];

    // Сдвиг значений влево, возникает пара
    while ((index > 0) && (value < array[index - 1])) {

        array[index] = array[index - 1];
        index--;
    }

    // Вставка, удаление пары
    array[index] = value;
}

/**
 * @brief Сортировка слиянием. Не возвращает времени выполнения
 * @param array - вектор
 * @param start - левая граница сортировки
 * @param end - правая граница сортировки
 */
void Sort::MergeSort(std::vector<int>& array, int start, int end) {

    // Сортировка не требуется
    if (end - start < 2) {

        return;
        // Пара элементов, требуется сортировка
    } else if (end - start == 2) {

        // Установить порядок по возрастанию
        if (array[start] > array[start + 1]) {

            Swap(array[start], array[start + 1]);
        }
    }

    // Вектор. Используется для слияния сортируемых частей
    std::vector<int> temp(end - start, 0);

    // Деление вектора на две части
    MergeSort(array, start, (start + end) / 2);
    MergeSort(array, (start + end) / 2, end);

    // Сохранение границ первой части
    int start1 = start;
    int end1 = (start + end) / 2;

    // Сохранение границ второй части
    int start2 = end1;
    int end2 = end;

    // Слияние сортируемых частей
    for (int i = 0; i < end - start; i++) {

        // Выход за границы первой части или элемент второй части меньша элемента первой
        // Сохранение в temp элементов второй части
        if ((start1 >= end1) || ((start2 < end2) && (array[start2] < array[start1]))) {

            temp[i] = array[start2];
            start2++;
            // Сохранение в temp элементов первой части
        } else {

            temp[i] = array[start1];
            start1++;
        }
    }

    // Сохранение отсортированного отрезка [start, end] в исходный массив
    for (int i = start; i < end; i++) {
        array[i] = temp[i - start];
    }

    // Очистка вектора
    temp.clear();
}

/**
 * @brief Сортировка выбором
 * @param array - вектор
 * @return resultTime - время выполнения
 */
std::chrono::milliseconds Sort::ChoiseSort(std::vector<int>& array) {

    // Точка времени, начало, миллисекунды
    std::chrono::steady_clock::time_point beginTime = std::chrono::steady_clock::now();

    for (int i = 0; i < array.size(); i++) {

        // Поиск индекса с минимальным элементом
        int index = FindMinElementIndex(array, i, array.size());

        // Требуется перестановка
        if (index != i) {

            // Перестановка
            Swap(array[index], array[i]);
        }
    }

    // Точка времени, конец, миллисекунды
    std::chrono::steady_clock::time_point endTime = std::chrono::steady_clock::now();

    // Миллисекунды, время выполнения
    std::chrono::milliseconds resultTime = std::chrono::duration_cast<std::chrono::milliseconds>(endTime - beginTime);

    return resultTime;
}
/**
 * @brief Сортировка вставками
 * @param array - вектор
 * @return resultTime - время выполнения
 */
std::chrono::milliseconds Sort::InsertSort(std::vector<int>& array) {

    // Точка времени, начало, миллисекунды
    std::chrono::steady_clock::time_point beginTime = std::chrono::steady_clock::now();

    for (int i = 1; i < array.size(); i++) {

        // Вставка элемента в вектор по порядку возрастания
        InsertElement(array, i);
    }

    // Точка времени, конец, миллисекунды
    std::chrono::steady_clock::time_point endTime = std::chrono::steady_clock::now();

    // Миллисекунды, время выполнения
    std::chrono::milliseconds resultTime = std::chrono::duration_cast<std::chrono::milliseconds>(endTime - beginTime);

    return resultTime;
}
/**
 * @brief Сортировка обменом, пузырьковая
 * @param array - вектор
 * @return resultTime - время выполнения
 */
std::chrono::milliseconds Sort::BubbleSort(std::vector<int>& array) {

    // Точка времени, начало, миллисекунды
    std::chrono::steady_clock::time_point beginTime = std::chrono::steady_clock::now();

    // Перебор, перестановка
    for (int i = 0; i < array.size(); i++) {

        for (int j = 0; j < array.size() - i - 1; j++) {

            // Требуется перестановка
            if (array[j] > array[j + 1]) {

                // Перестановка
                Swap(array[j], array[j + 1]);
            }
        }
    }

    // Точка времени, конец, миллисекунды
    std::chrono::steady_clock::time_point endTime = std::chrono::steady_clock::now();

    // Миллисекунды, время выполнения
    std::chrono::milliseconds resultTime = std::chrono::duration_cast<std::chrono::milliseconds>(endTime - beginTime);

    return resultTime;
}

/**
 * @brief Сортировка перемешиванием, шейкерная
 * @param array - вектор
 * @return resultTime - время выполнения
 */
std::chrono::milliseconds Sort::ShakerSort(std::vector<int>& array) {

    // Точка времени, начало, миллисекунды
    std::chrono::steady_clock::time_point beginTime = std::chrono::steady_clock::now();

    // Сохранение левой границы
    int left = 0;
    // Сохранение правой границы
    int right = array.size() - 1;

    // Если границы пересекутся - вектор отсортирован
    while (left < right) {

        // Индекс последней перестановки, пра
        int lastSwap = 0;

        // Проход вправо
        for (int i = left; i < right; i++) {

            // Требуется перестановка
            if (array[i] > array[i + 1]) {

                // Перестановка
                Swap(array[i], array[i + 1]);
                // Сохранение индекса последней перестановки
                lastSwap = i;
            }
        }

        // Сдвиг правой границы
        right = lastSwap;

        // Проход влево
        for (int i = right; i > left; i--) {

            // Требуется перестановка
            if (array[i - 1] > array[i]) {

                // Перестановка
                Swap(array[i - 1], array[i]);
                // Сохранение индекса последней перестановки
                lastSwap = i;
            }
        }

        // Сдвиг левой границы
        left = lastSwap;
    }

    // Точка времени, конец, миллисекунды
    std::chrono::steady_clock::time_point endTime = std::chrono::steady_clock::now();

    // Миллисекунды, время выполнения
    std::chrono::milliseconds resultTime = std::chrono::duration_cast<std::chrono::milliseconds>(endTime - beginTime);

    return resultTime;
}

/**
 * @brief Запись вектора случайными значениями
 * @param array - вектор
 */
void Sort::WriteArray(std::vector<int>& array) {

    // Генератор случайных (почти) чисел
    std::random_device dev;
    std::mt19937 png(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dist(0, 10);

    // Заипсь
    for (int i = 0; i < array.size(); i++) {

        array[i] = dist(png);
    }
}

/**
 * @brief Сортировка слиянием
 * @param array - вектор
 * @return resultTime - время выполнения
 */
std::chrono::milliseconds Sort::MergeSort(std::vector<int>& array) {

    // Точка времени, начало, миллисекунды
    std::chrono::steady_clock::time_point beginTime = std::chrono::steady_clock::now();

    // Сортировка слиянием
    MergeSort(array, 0, array.size());

    // Точка времени, конец, миллисекунды
    std::chrono::steady_clock::time_point endTime = std::chrono::steady_clock::now();

    // Миллисекунды, время выполнения
    std::chrono::milliseconds resultTime = std::chrono::duration_cast<std::chrono::milliseconds>(endTime - beginTime);

    return resultTime;
}

/**
 * @brief Замер времени работы алгоритмов сортировки
 * @param size - размер генерируемого вектора
 */
void Sort::RunTimeTest(int size) {

    // Генерируемый вектор
    std::vector<int> array(size, 0);

    // Количество повторений
    int iterCount = 100;
    // Сохранение размера генерируемого вектора
    this->size = size;

    // Время работы алгоритма сортировки выбором, 0 мс
    choiseSortTime = std::chrono::milliseconds(0);
    // Время работы алгоритма сортировки вставками, 0 мс
    insertSortTime = std::chrono::milliseconds(0);
    // Время работы алгоритма сортировки слиянием, 0 мс
    mergeSortTime = std::chrono::milliseconds(0);
    // Время работы алгоритма пузырьковой сортировки, 0 мс
    bubbleSortTime = std::chrono::milliseconds(0);
    // Время работы алгоритмы шейкерной сортировки, 0 мс
    shakerSortTime = std::chrono::milliseconds(0);

    // Начало проверки. Получение среднего времени работы алгоритмов
    for (int i = 0; i < iterCount; i++) {

        // Запись вектора случайными знаениями
        WriteArray(array);

        // Копия вектора
        std::vector<int> arrayCopy;

        // Сохранение времени работы алгоритма сортировки выбором
        choiseSortTime += ChoiseSort(arrayCopy = array);
        // Сохранение времени работы алгоритма сортировки вставками
        insertSortTime += InsertSort(arrayCopy = array);
        // Сохранение времени работы алгоритма сортировки слиянием
        mergeSortTime += MergeSort(arrayCopy = array);
        View::Print(std::to_string(i) + "\n");
        // Сохранение времени работы алгоритма пузырьковой сортировки
        bubbleSortTime += BubbleSort(arrayCopy = array);
        // Сохранение времени работы алгоритма шейкерной сортировки
        shakerSortTime += ShakerSort(arrayCopy = array);
    }

    // Среднее время работы алгоритма сортировки выбором
    // std::cout << "Choise sort count is " << choiseSortTime.count() << "\n";
    choiseSortTime /= iterCount;
    // Среднее время работы алгоритма сортировки вставками
    // std::cout << "Insert sort count is " << insertSortTime.count() << "\n";
    insertSortTime /= iterCount;
    // Среднее время работы алгоритма сортировки слиянием
    // std::cout << "Merge sort count is " << mergeSortTime.count() << "\n";
    mergeSortTime /= iterCount;
    // Среднее время работы алгоритма пузырьковой сортировки
    // std::cout << "Bubble sort count is " << bubbleSortTime.count() << "\n";
    bubbleSortTime /= iterCount;
    // Среднее время работы алгоритма шейкерной сортировки
    // std::cout << "Shaker sort count is " << shakerSortTime.count() << "\n";
    shakerSortTime /= iterCount;

    // Вывод информации на экран
    PrintResults();
}

/**
 * @brief Вывод на экран информации о работе алгоритмов сортировки
 */
void Sort::PrintResults() {

    // Размер генерируемого вектора
    View::Print("Size = " + std::to_string(size) + "\n");

    // Информация о замерах
    View::Print("Choise sorting time is " + std::to_string(choiseSortTime.count()) + " milliseconds\n");
    View::Print("Insert sorting time is " + std::to_string(insertSortTime.count()) + " milliseconds\n");
    View::Print("Merge sorting time is " + std::to_string(mergeSortTime.count()) + " milliseconds\n");
    View::Print("Bubble sorting time is " + std::to_string(bubbleSortTime.count()) + " milliseconds\n");
    View::Print("Shaker sorting time is " + std::to_string(shakerSortTime.count()) + " milliseconds\n");
}
