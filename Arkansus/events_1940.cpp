#include <iostream>
#include <cstdlib>
#include <ctime>
#include "structure.h"

using namespace std;

void events_1940()
{
    setlocale(LC_CTYPE, "Russian");

    srand((unsigned)time(NULL));
    int incident = rand() % 6 + 1; // Шесть вариантов событий.
    int choice;

    int karma_points;

    // Событие #1: Побег заключенного
    if (incident == 1)
    {
        cout << "Срочные новости! Один из опасных заключенных сбежал из местной тюрьмы." << endl;
        cout << "1 - Организовать массовую погоню с участием полиции." << endl;
        cout << "2 - Объявить награду за поимку беглеца." << endl;
        cout << "3 - Лично возглавить поисковую операцию." << endl;

        cout << "-> ";
        cin >> choice;

        switch (choice)
        {
        case 1: // Массовая погоня
        {
            cout << "Полиция организовала масштабную операцию, но беглецу удалось скрыться." << endl;
            karma_points = -1;
            game_points(karma_points);
            break;
        }
        case 2: // Объявить награду
        {
            cout << "Вы объявили награду за поимку. Один из жителей сообщил информацию о местонахождении беглеца." << endl;
            karma_points = 2;
            game_points(karma_points);
            break;
        }
        case 3: // Личное участие (Под-событие: Погоня)
        {
            cout << "Вы решили лично возглавить операцию. Начинается погоня!" << endl;
            chase(); // Вызов функции под-события.
            break;
        }
        default:
        {
            cout << "Неверный выбор. Беглец скрылся без следа." << endl;
            karma_points = -2;
            game_points(karma_points);
            break;
        }
        }
    }

    // Событие #2: Визит знаменитости
    if (incident == 2)
    {
        cout << "В город приезжает известный артист! Это может стать как благом, так и проблемой." << endl;
        cout << "1 - Организовать грандиозный концерт." << endl;
        cout << "2 - Провести пресс-конференцию." << endl;
        cout << "3 - Игнорировать визит." << endl;

        cout << "-> ";
        cin >> choice;

        switch (choice)
        {
        case 1: // Грандиозный концерт
        {
            cout << "Вы решили организовать грандиозный концерт!" << endl;
            organize_concert(); // Вызов функции для организации концерта.
            break;
        }
        case 2: // Пресс-конференция
        {
            cout << "На пресс-конференции возникли споры, и некоторые жители начали протестовать." << endl;
            karma_points = -1;
            game_points(karma_points);
            break;
        }
        case 3: // Игнорировать визит
        {
            cout << "Вы проигнорировали визит, и артист уехал, не оставив следа." << endl;
            karma_points = -2;
            game_points(karma_points);
            break;
        }
        default:
        {
            cout << "Неверный выбор. Визит завершился безрезультатно." << endl;
            karma_points = 0;
            game_points(karma_points);
            break;
        }
        }
    }

    // Событие #3: Наводнение в городе
    if (incident == 3)
    {
        cout << "В городе произошло наводнение! Вам нужно быстро реагировать." << endl;
        cout << "1 - Организовать эвакуацию жителей." << endl;
        cout << "2 - Попробовать укрепить дамбы." << endl;
        cout << "3 - Игнорировать ситуацию." << endl;

        cout << "-> ";
        cin >> choice;

        switch (choice)
        {
        case 1: // Эвакуация
        {
            cout << "Вы организовали эвакуацию жителей. Это спасло много жизней!" << endl;
            karma_points = 3;
            game_points(karma_points);
            organize_evacuations(); // Вызов функции для организации эвакуации.
            break;
        }
        case 2: // Укрепление дамб
        {
            cout << "Вы попытались укрепить дамбы, но это не дало результата." << endl;
            karma_points = -1;
            game_points(karma_points);
            break;
        }
        case 3: // Игнорировать ситуацию
        {
            cout << "Вы проигнорировали ситуацию, и это привело к большим потерям." << endl;
            karma_points = -3;
            game_points(karma_points);
            break;
        }
        default:
        {
            cout << "Неверный выбор. Наводнение продолжается." << endl;
            karma_points = 0;
            game_points(karma_points);
            break;
        }
        }
    }

    // Событие #4: Культурный фестиваль
    if (incident == 4)
    {
        cout << "В городе планируется культурный фестиваль! Это отличная возможность для жителей." << endl;
        cout << "1 - Организовать фестиваль на главной площади." << endl;
        cout << "2 - Провести фестиваль в парке." << endl;
        cout << "3 - Отменить фестиваль." << endl;

        cout << "-> ";
        cin >> choice;

        switch (choice)
        {
        case 1: // Фестиваль на главной площади
        {
            cout << "Вы организовали фестиваль на главной площади. Это привлекло много людей!" << endl;
            karma_points = 4;
            game_points(karma_points);
            organize_festival(); // Вызов функции для организации фестиваля.
            break;
        }
        case 2: // Фестиваль в парке
        {
            cout << "Фестиваль в парке прошел хорошо, но погода испортилась." << endl;
            karma_points = 1;
            game_points(karma_points);
            break;
        }
        case 3: // Отменить фестиваль
        {
            cout << "Вы отменили фестиваль, и жители были разочарованы." << endl;
            karma_points = -2;
            game_points(karma_points);
            break;
        }
        default:
        {
            cout << "Неверный выбор. Фестиваль не состоялся." << endl;
            karma_points = 0;
            game_points(karma_points);
            break;
        }
        }
    }

    // Событие #5: Экономический кризис
    if (incident == 5)
    {
        cout << "В городе начался экономический кризис! Уровень безработицы растет, и жители недовольны." << endl;
        cout << "1 - Увеличить налоги для поддержки бюджета." << endl;
        cout << "2 - Сократить расходы на социальные программы." << endl;
        cout << "3 - Игнорировать кризис." << endl;

        cout << "-> ";
        cin >> choice;

        switch (choice)
        {
        case 1: // Увеличить налоги
        {
            cout << "Вы решили увеличить налоги. Это вызвало недовольство среди жителей." << endl;
            karma_points = -4;
            game_points(karma_points);
            handle_crisis(); // Вызов функции для обработки кризиса.
            break;
        }
        case 2: // Сократить расходы на социальные программы
        {
            cout << "Вы сократили расходы на социальные программы. Это привело к протестам." << endl;
            karma_points = -5;
            game_points(karma_points);
            handle_crisis(); // Вызов функции для обработки кризиса.
            break;
        }
        case 3: // Игнорировать кризис
        {
            cout << "Вы проигнорировали кризис, и ситуация только ухудшилась." << endl;
            karma_points = -6;
            game_points(karma_points);
            handle_crisis(); // Вызов функции для обработки кризиса.
            break;
        }
        default:
        {
            cout << "Неверный выбор. Кризис продолжается." << endl;
            karma_points = -2;
            game_points(karma_points);
            handle_crisis(); // Вызов функции для обработки кризиса.
            break;
        }
        }
    }

    // Событие #6: Открытие нового культурного центра
    if (incident == 6)
    {
        cout << "В городе планируется открытие нового культурного центра! Это отличная возможность для развития культуры и искусства." << endl;
        cout << "1 - Организовать выставку местных художников." << endl;
        cout << "2 - Провести мастер-классы для жителей." << endl;
        cout << "3 - Просто открыть центр без мероприятий." << endl;

        cout << "-> ";
        cin >> choice;

        switch (choice)
        {
        case 1: // Выставка местных художников
        {
            cout << "Вы организовали выставку местных художников. Это привлекло много посетителей!" << endl;
            karma_points = 5;
            game_points(karma_points);
            manage_cultural_center(); // Вызов функции для управления открытием.
            break;
        }
        case 2: // Мастер-классы
        {
            cout << "Вы провели мастер-классы, и жители были в восторге от новых знаний!" << endl;
            karma_points = 4;
            game_points(karma_points);
            manage_cultural_center(); // Вызов функции для управления открытием.
            break;
        }
        case 3: // Открытие без мероприятий
        {
            cout << "Вы просто открыли центр, и жители оценили это, но не так сильно." << endl;
            karma_points = 2;
            game_points(karma_points);
            manage_cultural_center(); // Вызов функции для управления открытием.
            break;
        }
        default:
        {
            cout << "Неверный выбор. Центр был открыт без особых мероприятий." << endl;
            karma_points = 1;
            game_points(karma_points);
            manage_cultural_center(); // Вызов функции для управления открытием.
            break;
        }
        }
    }
}