#include <iostream>

using namespace std;

class Calculator {
    private:
        float* numbers;
    public:
        float* getNumbers() {
            return numbers;
        }
        void setNumbers(float* numbers, int size) {
            this->numbers = new float[size];
            for (int i = 0; i < size; i++) {
                this->numbers[i] = numbers[i];
            }
        }
        void printResult(int size) {
            cout << "Result: ";
            float* resultArray = getNumbers();
            cout << resultArray[size - 1] << endl;
        }
        void clearResult() {
        delete[] numbers;
        numbers = nullptr;
        }

};
class Addition : public Calculator{
    public :
    void performAddition(int size) {
            float* numbers = getNumbers();
            for (int i = 1; i < size; i++) {
                numbers[i] = numbers[i-1] + numbers[i];
            }
        }
    void addition(){
        int n = 0;
        float numbers[999];
        while (n < 999) {
            cout << "Enter number #" << (n+1) << ": ";
            string input;
            cin >> input;
            if (input == "x") {
                break;
            }
            float num = stof(input);
            numbers[n] = num;
            n++;
        }
        setNumbers(numbers, n);
        performAddition(n);
        printResult(n);
        clearResult();
    }
};
class Subtract : public Calculator{
    public :
    void performSubtraction(int size) {
            float* numbers = getNumbers();
            for (int i = 1; i < size; i++) {
                numbers[i] = numbers[i-1] - numbers[i];
            }
        }
    void subtract(){
        int n = 0;
        float numbers[100];
        while (n < 100) {
            cout << "Enter number #" << (n+1) << ": ";
            string input;
            cin >> input;
            if (input == "x") {
                break;
            }
            float num = stof(input);
            numbers[n] = num;
            n++;
        }
        setNumbers(numbers, n);
        performSubtraction(n);
        printResult(n);
        clearResult();
    }
};

class Multiply : public Calculator{
    public :
    void performMultiply(int size) {
            float* numbers = getNumbers();
            for (int i = 1; i < size; i++) {
                numbers[i] = numbers[i-1] * numbers[i];
            }
        }
    void multiply(){
        int n = 0;
        float numbers[100];
        while (n < 100) {
            cout << "Enter number #" << (n+1) << ": ";
            string input;
            cin >> input;
            if (input == "x") {
                break;
            }
            float num = stof(input);
            numbers[n] = num;
            n++;
        }
        setNumbers(numbers, n);
        performMultiply(n);
        printResult(n);
        clearResult();
    }
};

class Divide : public Calculator{
    public :
    void performDivide(int size) {
            float* numbers = getNumbers();
            for (int i = 1; i < size; i++) {
                numbers[i] = numbers[i-1] / numbers[i];
            }
        }
    void divide(){
        int n = 0;
        float numbers[100];
        while (n < 100) {
            cout << "Enter number #" << (n+1) << ": ";
            string input;
            cin >> input;
            if (input == "x") {
                break;
            }
            float num = stof(input);
            numbers[n] = num;
            n++;
        }
        setNumbers(numbers, n);
        performDivide(n);
        printResult(n);
        clearResult();
    }
};

int main()
{
    Addition add;
    add.addition();
    Subtract sub;
    sub.subtract();
    Multiply mul;
    mul.multiply();
    Divide div;
    div.divide();
}
