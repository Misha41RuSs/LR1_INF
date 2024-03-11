#include <iostream> 
#include <iomanip>
#include <cmath>
#include <string>

using namespace std;

void task_a();  // �������� ������� ������� #1
void task_b();  // �������� ������� ������� #2
void task_c();  // �������� ������� ������� #3
pair<int, int> countDigits(const string& number); // �������� ������� �������� ���� � �����

int main(void) {
    setlocale(LC_ALL, "RUS");
    // ����� ������� ���������� 
    task_a();
    task_b();
    task_c();
    
    return 0;
}


void task_a() {
    cout << "\t\t\t\t\t\t������� 1" << endl;
    cout << "�������  �������, ����� ��������, ����� ���������� �������: ";
    double a, b, res1;       // ����� 1, ����� 2, ���������� ���������
    cin >> a >> b >> res1;   // ���������� ������ �� �������� ������ � ������-��� �� � ����������
    double div;              // ���������� ��� ���������� ������� � ������� ���
    div = a / b;             // ���������� �������� ��� ������ ���
    cout << "������� �����, �� �������� ����� ������� ���������� ������ � ��-������� ����� ����������: ";
    double c, res2;          // �����, �� �������� ��������� ������, ��������� ���������� �����
    cin >> c >> res2;        // ���������� ������ �� �������� ������ � ������-��� �� � ����������
    double root;             // ���������� ��� ���������� ����������� ����� ��� ������ ���
    root = sqrt(c);          // ������ ����������� ����� ��� ������ ���
    cout << "\n\n����� ��������� ������: 1) " << a << " / " << b << " = " << res1 << " ��� 2) " << "sqrt(" << c << ") = " << res2 << endl;
    cout << "�������� ��������� � ������� ����������� ���������� ������:" << endl;
    cout << "1) " << a << " / " << b << " = " << fixed << setprecision(6) << div << endl;  // ����� � ������� �������� ��������� � ���-��� ������ ����� ����������� - 6
    cout << "2) " << setprecision(0) << "sqrt(" << c << ") = " << setprecision(6) << root << endl;   // ����� � ������� �������� ��������� � ���-��� ������ ����� ����������� - 6
    cout << "���������� ���������� �����������, �������� �� � ��������:" << endl;
    /*
      ��������� ���������� ���������� ����������� - �������� �� ����������, ����������� ��� ���������, ���������� ����
      � ����� ��� �������� �� ������
    */
    cout << "1) " << fabs(div - res1) << endl;
    cout << "2) " << fabs(root - res2) << endl;
    /*
     ��������� ���������� ���������� ����������� � ��������� - �������� ����-������ ����� �������� �� 100 � ����� ��
     ���� ��������, ������� �� �������
   */
    double err1, err2;
    cout << "���������� ���������� ����������� ���������� � %:" << endl;
    err1 = fabs(div - res1) * 100 / res1;
    err2 = fabs(root - res2) * 100 / res2;
    cout << "1) " << err1 << endl;
    cout << "2) " << err2 << endl;

    // �������� �������, ����� ����������� ������, �� ��������� � ������, ���� ��� �����, ������ ��������� � ��������� ���������

    cout << "������, ����� ������ ���������: ";
    if (err1 > err2) {
        cout << setprecision(0) << a << " / " << b << " = " << setprecision(3) << div << endl;
    }
    else if (err1 < err2) {
        cout << setprecision(0) << "sqrt(" << c << ") = " << setprecision(2) << root << endl;
    }
    else {
        cout << "��� ��������� ���������� ��������" << endl;
    }
}

void task_b() {
    cout << "\t\t\t\t\t\t������� 2" << endl;
    double a;  // ���������� ��� �������� ���������� �����
    cout << "������� �����: ";
    cin >> a;
    cout << "������� ���������� �����������: \n1 - � ���� �����\n2 - � ���������" << endl;
    int choice;  // ���������� ��� �������� ������ �� ���� ��� ������ �����������
    cout << "�����: ";
    cin >> choice;
    double err;  // ���������� ��� �������� �����������
    if (choice == 1) {
        cout << "������� ���������� ����������� � ���� �����: ";
        cin >> err;
    }
    else if (choice == 2) {
        double tmp;
        cout << "������� ���������� ����������� � %: ";
        cin >> tmp;
        err = tmp / 100;
    }
    double log_error = log10(err);  // ���������� ��� ���������� ����������� ��������� �� �����������, ��� ����������� ������� �������� �����������
    // ��������� �� ������� ������� (��� �������������� �����) � ������ ���� �� + (������������� ����� ���������� ������)
    int n = -floor(log_error);
    double scale = pow(10.0, n);    // ����������� �����, �� ������� ������ ������ ���������
    double new_value = a;           // �������� ��������, �������� � ���������� � ����� ���������� ��� ��������
    /*
    * �������� ���� �������� �� ����������� ������ ������, ��������� �� �������� ��������������� ���������� 
    * ����� �� ���� �� �����������, ����� ������� ����� � �������� ���������, �� ��� �������� ������������ �����
    */
    new_value = round(new_value * scale) / scale;      
    cout << "����� ����� � ����������� ������������� �������: " << new_value << endl;
    double new_err = fabs(a - new_value);  // ����������� ��������� ��� � ������ �������
    cout << "���������� ����������� ����������: "<< setprecision(4) << new_err << endl;
}

void task_c() {
    double num;
    cout << "������� �����: ";
    cin >> num;

    string stringNum = to_string(num);

    pair<int, int> digits = countDigits(stringNum);

    double delta_abs = 0.5 * pow(10, -digits.second - 1);
    double delta_rel_percentage = (delta_abs / abs(num)) * 100.0;
    double delta_rel = (delta_abs / abs(num));

    cout << "���������� ���������� �����������: " << fixed << setprecision(8) << delta_abs << endl;
    cout << "���������� ������������� ����������� � %: " << delta_rel_percentage << endl;
    cout << "���������� ������������� ����������� � ���� �����: " << delta_rel << endl;
} 

// ������� �������� ���� � �����
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