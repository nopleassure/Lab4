#include <iostream>
#include <clocale>
#include "Player.h"

using namespace std;

int main()
{
    Player player(true, false, 3, 2);

    int choice = 0;

    while (choice != 10)
    {
        cout << "\n===== МЕНЮ ПЛЕЕРА =====\n";
        cout << "1. Показать состояние плеера\n";
        cout << "2. Включить/выключить плеер\n";
        cout << "3. Пуск / Пауза\n";
        cout << "4. Увеличить громкость\n";
        cout << "5. Уменьшить громкость\n";
        cout << "6. Следующий трек\n";
        cout << "7. Предыдущий трек\n";
        cout << "8. Установить громкость\n";
        cout << "9. Установить номер трека\n";
        cout << "10. Выход\n";
        cout << "Введите пункт меню: ";
        cin >> choice;

        int val;

        switch (choice)
        {
        case 1:
            player.show();
            break;
        case 2:
            player.changePower();
            player.show();
            break;
        case 3:
            player.changePlay();
            player.show();
            break;
        case 4:
            player.volumeUp();
            player.show();
            break;
        case 5:
            player.volumeDown();
            player.show();
            break;
        case 6:
            player.nextTrack();
            player.show();
            break;
        case 7:
            player.prevTrack();
            player.show();
            break;
        case 8:
            cout << "Введите громкость (0-10): ";
            cin >> val;
            player.setVolume(val);
            player.show();
            break;
        case 9:
            cout << "Введите номер трека (1-5): ";
            cin >> val;
            player.setTrack(val);
            player.show();
            break;
        case 10:
            cout << "Выход из программы...\n";
            break;
        default:
            cout << "Ошибка: неверная команда!\n";
        }
    }

    return 0;
}
