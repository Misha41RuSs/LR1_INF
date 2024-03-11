#include <iostream> 
#include <iomanip>
#include <cmath>
#include <string>

using namespace std;

void task_a();  // Прототип функции Задания #1
void task_b();  // Прототип функции Задания #2
void task_c();  // Прототип функции Задания #3
pair<int, int> countDigits(const string& number); // Прототип функции подсчёта цифр в числе

int main(void) {
    setlocale(LC_ALL, "RUS");
    // Вызов функций поочередно 
    task_a();
    task_b();
    task_c();
    
    return 0;
}


void task_a() {
    cout << "\t\t\t\t\t\tЗадание 1" << endl;
    cout << "Введите  делимое, потом делитель, затем полученное частное: ";
    double a, b, res1;       // Число 1, число 2, полученный результат
    cin >> a >> b >> res1;   // Считывание данных из входного потока и занесе-ние их в переменные
    double div;              // Переменная для результата деления с помощью ЭВМ
    div = a / b;             // Вычисление частного при помощи ЭВМ
    cout << "Введите число, из которого нужно извлечь квадратный корень и ре-зультат этого извлечения: ";
    double c, res2;          // Число, из которого извлекаем корень, результат извлечения корня
    cin >> c >> res2;        // Считывание данных из входного потока и занесе-ние их в переменные
    double root;             // Переменная для вычисление квадратного корня при помощи ЭВМ
    root = sqrt(c);          // Взятие квадратного корня при помощи ЭВМ
    cout << "\n\nКакое выражение точнее: 1) " << a << " / " << b << " = " << res1 << " или 2) " << "sqrt(" << c << ") = " << res2 << endl;
    cout << "Значения выражений с большим количеством десятичных знаков:" << endl;
    cout << "1) " << a << " / " << b << " = " << fixed << setprecision(6) << div << endl;  // Вывод в консоль значения выражения с кол-вом знаков после разделителя - 6
    cout << "2) " << setprecision(0) << "sqrt(" << c << ") = " << setprecision(6) << root << endl;   // Вывод в консоль значения выражения с кол-вом знаков после разделителя - 6
    cout << "Предельные абсолютные погрешности, округляя их с избытком:" << endl;
    /*
      Вычисляем предельную абсолютную погрешность - вычитаем из результата, полученного ЭВМ результат, полученный нами
      и берем эту разность по модулю
    */
    cout << "1) " << fabs(div - res1) << endl;
    cout << "2) " << fabs(root - res2) << endl;
    /*
     Вычисляем предельную абсолютную погрешность в процентах - умножаем полу-ченный ранее резульат на 100 и делим на
     само значение, которое мы вводили
   */
    double err1, err2;
    cout << "Предельные абсолютные погрешности составляют в %:" << endl;
    err1 = fabs(div - res1) * 100 / res1;
    err2 = fabs(root - res2) * 100 / res2;
    cout << "1) " << err1 << endl;
    cout << "2) " << err2 << endl;

    // Проверка условия, какая погрешность меньше, то выражение и точнее, если они равны, значит сообщение о равенстве выражений

    cout << "Значит, более точное выражение: ";
    if (err1 > err2) {
        cout << setprecision(0) << a << " / " << b << " = " << setprecision(3) << div << endl;
    }
    else if (err1 < err2) {
        cout << setprecision(0) << "sqrt(" << c << ") = " << setprecision(2) << root << endl;
    }
    else {
        cout << "Оба выражения одинаковой точности" << endl;
    }
}

void task_b() {
    cout << "\t\t\t\t\t\tЗадание 2" << endl;
    double a;  // Переменная для хранения введенного числа
    cout << "Введите число: ";
    cin >> a;
    cout << "Введите абсолютную погрешность: \n1 - В виде числа\n2 - В процентах" << endl;
    int choice;  // Переменная для хранения выбора из меню как ввести погрешность
    cout << "Выбор: ";
    cin >> choice;
    double err;  // Переменная для хранения погрешности
    if (choice == 1) {
        cout << "Введите абсолютную погрешность в виде числа: ";
        cin >> err;
    }
    else if (choice == 2) {
        double tmp;
        cout << "Введите абсолютную погрешность в %: ";
        cin >> tmp;
        err = tmp / 100;
    }
    double log_error = log10(err);  // Переменная для вычисления десятичного логарифма от погрешности, для определения порядка величины погрешности
    // Округляем до нижнего предела (для отрицательного числа) и меняем знак на + (положительное число становится больше)
    int n = -floor(log_error);
    double scale = pow(10.0, n);    // Коэффициент числа, на сколько верных знаков округлять
    double new_value = a;           // Копируем значение, вводимое с клавиатуры в новую переменную для удобства
    /*
    * Умножаем наше значение на коэффициент верных знаков, округляем по правилам математического округления 
    * Делим на этот же коэффициент, чтобы вернуть число в исходное состояние, но уже отбросив сомнительные цифры
    */
    new_value = round(new_value * scale) / scale;      
    cout << "Новое число с округлёнными сомнительными цифрами: " << new_value << endl;
    double new_err = fabs(a - new_value);  // Погрешность вычисляем как в первом задании
    cout << "Абсолютная погрешность результата: "<< setprecision(4) << new_err << endl;
}

void task_c() {
    double num;
    cout << "Введите число: ";
    cin >> num;

    string stringNum = to_string(num);

    pair<int, int> digits = countDigits(stringNum);

    double delta_abs = 0.5 * pow(10, -digits.second - 1);
    double delta_rel_percentage = (delta_abs / abs(num)) * 100.0;
    double delta_rel = (delta_abs / abs(num));

    cout << "Предельная абсолютная погрешность: " << fixed << setprecision(8) << delta_abs << endl;
    cout << "Предельная относительная погрешность в %: " << delta_rel_percentage << endl;
    cout << "Предельная относительная погрешность в виде числа: " << delta_rel << endl;
} 

// Функция подсчёта цифр в числе
pair<int, int> countDigits(const string& number) {
    int integerDigits = 0;
    int decimalDigits = 0;
    bool decimalPart = false;

    for (char c : number) {
        if (c == ',') {
            decimalPart = true;
        }
        else {
            if (decimalPart) {
                if (c == '0')
                    break;
                decimalDigits++;
            }
            else {
                integerDigits++;
            }
        }
    }

    return make_pair(integerDigits, decimalDigits);
}