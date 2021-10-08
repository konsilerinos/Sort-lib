#  Пишем библиотеку для сортировки линейных структур данных

## Алгоритмы

Сортировка:
1. Выбором
2. Вставками
3. Бинарными вставками
4. Слиянием
5. Обменом
6. Перемешиванием
7. Шелла
8. Быстрая (Хоара)

## Сортировка выбором

Суть алгоритма:
1. Найти номер минимального значения в текущем списке.
2. Произвести обмен этого значения со значением первой неотсортированной позиции (обмен не нужен, если минимальный элемент уже находится на данной позиции).
3. Продолжить сортировку, исключив из рассмотрения уже отсортированные элементы.

Сложность вычислений (худшая): **O(n²)**

Реализация на языке С++

```C++
template <typename T> void Swap(T& digit1, T& digit2) {

  digit1 = digit1 + digit2;
  digit2 = digit1 - digit2;
  digit1 = digit1 - digit2;
}
```

```C++
template <typename T> int FindMinElementIndex(T array, int left, int right) {

  int minElementIndex = left;

  for (int i = left + 1; i < right; i++) {

    if (array[minElementIndex] > array[i]) {

      minElementIndex = i;
    }
  }

  return minElementIndex;
}
```
```C++
template <typename T> void ChoiseSorting(T array) {

  for (int i = 0; i < size; i++) {
  
    int index = FindMinElementIndex(array, i, size);
    
    if (index != i) {

      Swap(array[index], array[i]);
    }
  }  
}
```

## Сортировка вставками

Суть алгоритма: элементы входной последовательности просматриваются по одному, и каждый новый поступивший элемент размещается в подходящее место среди ранее упорядоченных элементов.

Сложность вычислений (худшая): **O(n²)**

Реализация на языке С++

```C++
template <typename T> void InsertElement(T* array, int index) {

  T value = array[index];

  while ((index > 0) && (value < array[index - 1])) {

    array[index] = array[index - 1];
    index--;
  }

  array[index] = value;
}
```
```C++
template <typename T> void InsertSorting(T array) {

  for (int i = 1; i < size; i++) {

    InsertElement(array, i);
  }
}
```

## Сортировка бинарными вставками

Суть алгоритма: сортировка вставками с бинарным поиском.

Сложность вычислений (худшая): **O(n²)**

Реализация на языке С++
```C++
 template <typename T> int BinaryFindMinElementIndex(T* array, T value, int left, int right) {

  int middle = 0;

  while (right - left > 1) {

    middle = (left + right) / 2;

    if (array[middle] < value) {

      left = middle;
    }
    else {

      right = middle;
    }
  }

  if (array[left] <= value) {

    return right;
  }
  else {

    return left;
  }
}
```
```C++
template <typename T> void BinaryInsert(T* array, int i) {

  int index = i + 1;
  T value = array[index];
  int up = BinaryFindMinElementIndex(array, array[index], 0, index);

  while (index > up) {

    array[index] = array[index - 1];
    index--;
  }

  array[index] = value;
}
```
```C++
template <typename T> void BinaryInsertSorting(T array) {

  for (int i = 1; i < size - 1; i++) {

    BinaryInsert(array, i);
  }
}
```

## Сортировка слиянием

Суть алгоритма: 
1. Сортируемый массив разбивается на две части примерно одинакового размера.
2. Каждая из получившихся частей сортируется отдельно, например, тем же самым алгоритмом.
3. Два упорядоченных массива половинного размера соединяются в один.

Сложность вычислений (худшая): **O(n * log n)**

Реализация на языке С++

```C++
template <typename T> void MergeSorting(T* array, int start, int end) {

  if (end - start < 2) {

    return;
  }
  else if (end - start == 2) {

    if (array[start] > array[start + 1]) {

      Swap(array[start], array[start + 1]);
    }
  }

  MergeSorting(array, start, (start + end) / 2);
  MergeSorting(array, (start + end) / 2, end);

  T* temp = new T[end - start];

  int start1 = start;
  int end1 = (start + end) / 2;

  int start2 = end1;
  int end2 = end;

  for (int i = 0; i < end - start; i++) {

    if ((start1 >= end1) || ((start2 < end2) && (array[start2] < array[start1]))) {

      temp[i] = array[start2];
      start2++;
    }
    else {

      temp[i] = array[start1];
      start1++;
    }
  }

  for (int i = start; i < end; i++) {

    array[i] = temp[i - start];
  }

  delete[] temp;
}
```

## Сортировка обменом

Суть алгоритма: постановка максимального элемента в конец массива для каждого прохода в цикле.

Сложность вычислений (худшая): **O(n²)**

Реализация на языке С++
```C++
template <typename T> void ExchangeSorting(T array) {

  for (int i = 0; i < size; i++) {

    for (int j = 0; j < size - 1; j++) {

      if (array[j] > array[j + 1]) {

        Swap(array[j], array[j + 1]);
      }
    }
  }
}
```

## Сортировка перемешиванием (шейкерная)

Суть алгоритма: пузырьковый обмен в обе стороны и сохранение места последнего обмена.

Сложность вычислений (худшая): **O(n²)**

Реализация на языке С++
```C++
template <typename T> void ShakerSorting(T array) {

  int left = 0;
  int right = size - 1;

  while (left < right) {

    int lastSwap = 0;

    for (int i = left; i < right; i++) {

      if (array[i] > array[i + 1]) {

        Swap(array[i], array[i + 1]);
        lastSwap = i;
      }
    }

    right = lastSwap;

    for (int i = right; i > left; i--) {

      if (array[i - 1] > array[i]) {

        Swap(array[i - 1], array[i]);
        lastSwap = i;
      }
    }

    left = lastSwap;
  }
}
```

## Сортировка Шелла

Суть алгоритма: сравнение элементов на расстоянии (улучшенная сортировка вставками).

Сложность вычислений (худшая): **O(n²)**

Реализация на языке С++
```C++
template <typename T> void ShellSorting(T array) {

  for (int s = size; s > 0; s /= 2) {
  
    for (int i = 0; i < size; i++) {
  
      for (int j = i + s; j < size; j += s) {
  
        if (array[i] > array[j]) {
  
          Swap(array[i], array[j]);
        }
      }
    }
  }
}
```

## Быстрая сортировка (Хоара)

Суть алгоритма: выбор опорного элемента (нулевой), деление массива на три части, рекурсивная сортировка.

Сложность вычислений (худшая): **O(n²)**

Реализация на языке С++
```C++
template <typename T> void QuickSorting(T* array, int left, int right) {

  T value = array[left];

  int left_c = left;
  int right_c = right;

  while (left < right) {

    while ((array[right] >= value) && (left < right)) {

      right--;
    }

    if (left != right) {

      array[left] = array[right];
    }

    while ((array[left] <= value) && (left < right)) {

      left++;
    }

    array[right] = array[left];
    right--;
  }

  array[left] = value;

  int new_left = left;
  left = left_c;
  right = right_c;

  if (left < new_left) {

    QuickSorting(array, left, new_left - 1);
  }
  if (right > new_left) {

    QuickSorting(array, new_left + 1, right);
  }
}
```
