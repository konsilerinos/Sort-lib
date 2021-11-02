#pragma once
#include <chrono>
#include <vector>

/**
 * @brief Класс, содержащий алгоритмы сортировки, а также метод их тестирования
 */
class Sort {

  private:
    /**
     * @brief Время в миллисекундах, сортировка выбором
     */
    std::chrono::milliseconds choiseSortTime;
    /**
     * @brief Время в миллисекундах, сортировка вставками
     */
    std::chrono::milliseconds insertSortTime;
    /**
     * @brief Время в миллисекундах, сортировка слиянием
     */
    std::chrono::milliseconds mergeSortTime;
    /**
     * @brief Время в миллисекундах, сортировка обменом (пузырьковая)
     */
    std::chrono::milliseconds bubbleSortTime;
    /**
     * @brief Время в миллисекундах, сортировка перемешиванием (шейкерная)
     */
    std::chrono::milliseconds shakerSortTime;
    /**
     * @brief Размер вектора, используется для вывода информации
     * о результатах тестирование
     */
    int size;

    /**
     * @brief Обмен значений двух чисел
     * @param digit1 - первое число
     * @param digit2 - второе число
     */
    void Swap(int& digit1, int& digit2);

    /**
     * @brief Поиск индекса минимального элемента в векторе
     * @param array - вектор
     * @param left - левая граница поиска
     * @param right - правая граница поиска
     * @return minElementIndex - искомый индекс
     */
    int FindMinElementIndex(std::vector<int>& array, int left, int right);
    /**
     * @brief Вставка элемента по индексу в вектор по возрастанию
     * @param array - вектор
     * @param index - индекс
     */
    void InsertElement(std::vector<int>& array, int index);

    /**
     * @brief Сортировка слиянием. Не возвращает времени выполнения
     * @param array - вектор
     * @param start - левая граница сортировки
     * @param end - правая граница сортировки
     */
    void MergeSort(std::vector<int>& array, int start, int end);

    /**
     * @brief Сортировка выбором
     * @param array - вектор
     * @return resultTime - время выполнения
     */
    std::chrono::milliseconds ChoiseSort(std::vector<int>& array);
    /**
     * @brief Сортировка вставками
     * @param array - вектор
     * @return resultTime - время выполнения
     */
    std::chrono::milliseconds InsertSort(std::vector<int>& array);
    /**
     * @brief Сортировка обменом, пузырьковая
     * @param array - вектор
     * @return resultTime - время выполнения
     */
    std::chrono::milliseconds BubbleSort(std::vector<int>& array);

    /**
     * @brief Сортировка перемешиванием, шейкерная
     * @param array - вектор
     * @return resultTime - время выполнения
     */
    std::chrono::milliseconds ShakerSort(std::vector<int>& array);

    /**
     * @brief Запись вектора случайными значениями
     * @param array - вектор
     */
    void WriteArray(std::vector<int>& array);

  public:
    /**
     * @brief Сортировка слиянием
     * @param array - вектор
     * @return resultTime - время выполнения
     */
    std::chrono::milliseconds MergeSort(std::vector<int>& array);

    /**
     * @brief Замер времени работы алгоритмов сортировки
     * @param size - размер генерируемого вектора
     */
    void RunTimeTest(int size);

    /**
     * @brief Вывод на экран информации о работе алгоритмов сортировки
     */
    void PrintResults();
};
