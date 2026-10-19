# Группа: ИКТГ-2522
Владелец репозитория: Калганова Екатерина\
Состав коллектива: Калганова Екатерина, Пимахина Юлия\
Вариант №16\
Реализация "Плеера"

1. Модель плеера, описание поведения устройства

Свойства
   
| Свойство  | Тип | Допустимые значения |
| -------------  | ------------- | ------------- |
| power          | bool  | false – выключен, true – включён |
| playing        | bool  | false – пауза, true – играет (только если power = true) |
| volume         | int   | от 0 до 10 |
| track  | int   | от 1 до 5  |

Методы
changePower(), changePlay(), volumeUp(), volumeDown(), nextTrack(), prevTrack().     Дополнительно есть setVolume(), setTrack(), show() и методы для чтения свойств.

Таблица состояний
   
| № | power | playing | Описание состояния |
| ------------- | ------------- | ------------- | ------------- |
| 1  | false  | false | Плеер выключен |
| 2  | true | false | Плеер включён, пауза |
| 3  | true  | true | Плеер включён, воспроизведение музыки |

Диаграмма состояний

```mermaid
stateDiagram-v2
    [*] --> Выключен
    state "Включён" as On {
        [*] --> Пауза
        Пауза --> Играет: пуск
        Играет --> Пауза: пауза
    }
    Выключен --> On: включить
    On --> Выключен: выключить
```

   
1. Создание объекта с помощью конструктора по умолчанию
   ```cpp
   Player p1;
   p1.show();
   ```
   Вывод:
   ```
   Плеер выключен
   ```
   
2. Создание объекта с помощью конструктора с параметрами
   ```cpp
   Player p2(true, false, 7, 3);
   p2.show();
   ```
   Вывод:
   ```
   Плеер включён. Состояние: пауза. Громкость: 7. Трек: 3
   ```
   
3. Создание массива объектов
   ```cpp
   Player players[3];
   players[1] = Player(true, false, 3, 2);
   players[2] = Player(true, true, 8, 5);

   for (int i = 0; i < 3; i++)
   {
       std::cout << "Плеер " << i + 1 << ": ";
       players[i].show();
   }
   ```
   Вывод:
   ```
   Плеер 1: Плеер выключен
   Плеер 2: Плеер включён. Состояние: пауза. Громкость: 3. Трек: 2
   Плеер 3: Плеер включён. Состояние: играет. Громкость: 8. Трек: 5
   ```
   
4. Редактирование и просмотр свойств каждого объекта
    ```cpp
    players[0].changePower();
   players[0].setVolume(9);
   players[1].nextTrack();
   players[2].changePlay();

   for (int i = 0; i < 3; i++)
   {
       std::cout << "Плеер " << i + 1 << ": ";
       players[i].show();
   }
   ```
   Вывод:
   ```
   Плеер 1: Плеер включён. Состояние: пауза. Громкость: 9. Трек: 1
   Плеер 2: Плеер включён. Состояние: пауза. Громкость: 3. Трек: 3
   Плеер 3: Плеер включён. Состояние: пауза. Громкость: 8. Трек: 5
   ```
   
6. Обработка массива объектов
   ```cpp
   int onCount = 0;
   int playCount = 0;
   int sumVolume = 0;
   int maxVolume = -1;
   int maxIndex = 0;

   for (int i = 0; i < 3; i++)
   {
      if (players[i].getPower() == true)
       {
           onCount = onCount + 1;
           sumVolume = sumVolume + players[i].getVolume();

           if (players[i].getVolume() > maxVolume)
           {
               maxVolume = players[i].getVolume();
               maxIndex = i;
           }
       }
       if (players[i].getPlaying() == true)
       {
            playCount = playCount + 1;
       }
     }

   std::cout << "Включено плееров: " << onCount << std::endl;
   std::cout << "Играет плееров: " << playCount << std::endl;
   if (onCount > 0)
   {
       std::cout << "Средняя громкость включённых: " << (double)sumVolume / onCount << std::endl;
       std::cout << "Самый громкий плеер: " << maxIndex + 1 << " (громкость " << maxVolume << ")" << std::endl;
   }
   else
   {
       std::cout << "Все плееры выключены." << std::endl;
   }
   ```
   Вывод:
   ```
   Включено плееров: 2
   Играет плееров: 1
   Средняя громкость включённых: 5.5
   Самый громкий плеер: 3 (громкость 8)
   ```
   
8. Файл main.cpp
   ```cpp
   #include <iostream>
   #include <clocale>
   #include "player.h"

   int main()
   {
       Player players[3];
       players[1] = Player(true, false, 3, 2);
       players[2] = Player(true, true, 8, 5);

       int work = 1;
       int command;
       int index;
       int number;
       int value;
   
       while (work)
       {
           std::cout << std::endl;
           std::cout << "----- МЕНЮ -----" << std::endl;
           std::cout << "1 - Показать все плееры" << std::endl;
           std::cout << "2 - Включить/выключить плеер" << std::endl;
           std::cout << "3 - Пуск/пауза" << std::endl;
           std::cout << "4 - Громкость больше" << std::endl;
           std::cout << "5 - Громкость меньше" << std::endl;
           std::cout << "6 - Следующий трек" << std::endl;
           std::cout << "7 - Предыдущий трек" << std::endl;
           std::cout << "8 - Установить громкость" << std::endl;
           std::cout << "9 - Установить номер трека" << std::endl;
           std::cout << "10 - Обработка массива (статистика)" << std::endl;
           std::cout << "11 - Выход" << std::endl;
           std::cout << "Введите номер команды ";
           std::cin >> command;
   
           index = 0;
           if (command >= 2 && command <= 9)
           {
               std::cout << "Введите номер плеера (1-3): ";
               std::cin >> number;
               if (number < 1 || number > 3)
               {
                   std::cout << "Такого плеера нет" << std::endl;
                   continue;
               }
            index = number - 1;
        }

        switch (command)
        {
        case 1:
            for (int i = 0; i < 3; i++)
            {
                std::cout << "Плеер " << i + 1 << ": ";
                players[i].show();
            }
            break;
        case 2:
            players[index].changePower();
            players[index].show();
            break;
        case 3:
            players[index].changePlay();
            players[index].show();
            break;
        case 4:
            players[index].volumeUp();
            players[index].show();
            break;
        case 5:
            players[index].volumeDown();
            players[index].show();
            break;
        case 6:
            players[index].nextTrack();
            players[index].show();
            break;
        case 7:
            players[index].prevTrack();
            players[index].show();
            break;
        case 8:
            std::cout << "Введите громкость (0-10): ";
            std::cin >> value;
            players[index].setVolume(value);
            players[index].show();
            break;
         case 9:
            std::cout << "Введите номер трека (1-5): ";
            std::cin >> value;
            players[index].setTrack(value);
            players[index].show();
            break;
         case 10:
         {
            int onCount = 0;
            int playCount = 0;
            int sumVolume = 0;
            int maxVolume = -1;
            int maxIndex = 0;

            for (int i = 0; i < 3; i++)
            {
                if (players[i].getPower() == true)
                {
                    onCount = onCount + 1;
                    sumVolume = sumVolume + players[i].getVolume();

                    if (players[i].getVolume() > maxVolume)
                    {
                        maxVolume = players[i].getVolume();
                        maxIndex = i;
                    }
                }
                if (players[i].getPlaying() == true)
                {
                    playCount = playCount + 1;
                }
            }

            std::cout << "Включено плееров: " << onCount << std::endl;
            std::cout << "Играет плееров: " << playCount << std::endl;
            if (onCount > 0)
            {
                std::cout << "Средняя громкость включённых: " << (double)sumVolume / onCount << std::endl;
                std::cout << "Самый громкий плеер: " << maxIndex + 1 << " (громкость " << maxVolume << ")" << std::endl;
            }
            else
            {
                std::cout << "Все плееры выключены" << std::endl;
            }
            break;
        }
        case 11:
            work = 0;
            break;
        default:
            std::cout << "Нет такой команды" << std::endl;
        }
    }
    return 0;
   }
   ```

Демонстрация работы программы 

https://github.com/user-attachments/assets/71ae1fd3-c5cd-4065-a186-606acc77f0cc

Заключение
