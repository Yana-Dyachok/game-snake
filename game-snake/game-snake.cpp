// 1. Створіть гру змійка, в якій:
//-користувач повинен мати можливість обирати розміри поля(NxN)
//- реалізуйте підрахунок балів(+1 коли змія з'їдає їжу)
#include <iostream>
#include <conio.h>
using namespace std;
void divisionArrayField(char** field, int n, int m);//функція розподілу динамічної пам’яті
void inputField(char** field, int n, int m);//функція вводу грального поля
void playField(char** field, int n, int m);// функція виводу грального поля
void deleteField(char** field, int n, int m);//функція видалення масиву
void Game(char** field, int n, int m);//функція процесу гри
int main()
{    int n = 0, m=0;//розміри грального поля рядки та стовпці відповідно
    cout << "Hi!Let's play a snake game" << endl;
    cout << "Choose size rows of play field" << endl;
    cin >> n;
    cout << "Choose size columns of play field" << endl;
    cin >> m;
    char** field =nullptr;//вказівник на двовимірний масив – гральне поле
    field = new char*[n]; //вказівник на двовимірний масив – гральне поле
    divisionArrayField(field,n, m);//звертаємось до функції розподілу динамічної пам’яті
    Game(field, n, m);// звертаємось до функції процесу гри
    deleteField(field, n, m);// звертаємось до функції видалення масиву
    delete[]field;//видаляємо масив
}
void divisionArrayField(char** field, int n, int m) {//функція розподілу динамічної пам’яті
    for (int i = 0; i < n; i++)
    {
        field[i] = new char[m];
    }
}
void deleteField(char** field, int n, int m) {//функція видалення масиву
    for (int i = 0; i < n; i++)
    {
        delete[]field[i];
    }

}
void inputField(char** field, int n, int m) {//функція вводу грального поля
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (i == 0 or i == n - 1 or j == 0 or j == m - 1)
                field[i][j] = '#';
            else { field[i][j] = '\'\ \''; }

        }

    }
}
void playField(char** field, int n, int m) {// функція виводу грального поля
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << field[i][j];
        }
        cout << endl;
    }
}
void Game(char** field, int n, int m) {//функція процесу гри
    int x = 2;//координати змії
    int y = 2;// координати змії
    int xf = 1;// координати їжі змії
    int yf = 1;// координати їжі змії
    int k = 0;//кількість разів вживання їжі змією-кількість набраних балів
    char button;//змінна для вводу напрямку змії
    while (k!=30) {//граємо поки не наберемо 30 очків
        cout << " You have=" << k << " points" << endl;
        inputField(field, n, m);//звертаємось до функції вводу грального поля
        char snake = '@';//позначаємо таким символом змію
        char food = '*'; //позначаємо таким символом їжу
        field[x][y] = snake;//розташування змії в гральному полі
        field[xf][yf] = food; //розташування змії в гральному полі
        playField(field, n, m); //звертаємось до функції виводу грального поля
        button = _getch();//використовуємо _getch() для вводу
        if (button == 'a')y--;//клавіша для руху вліво
        if (button == 'd')y++;// клавіша для руху вправо
        if (button == 'w')x--;// клавіша для руху вверх
        if (button == 's')x++;// клавіша для руху вниз
        system("cls");//очищуємо 
        if (x==0 or x==n-1 or y==0 or y==m-1) {//умова,за якої при виході за межі поля, змія повертається 
            x = 2;
            y = 2;
        }
        if (x == xf and y == yf) {//якщо координати змії та їжі співпадуть,то
            xf = rand() % (n - 2) + 1;//рандомно змінюються координати їжі
            yf = rand() % (m - 2) + 1;//
            k++;//підраховуємо кількість балів-разів харчування змії
        }
    }
        cout << "You win and get-"<<k<<" points!!!"<< endl;
}
