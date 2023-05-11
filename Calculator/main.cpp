#include <iostream>
#include <cmath>

using namespace std;

class Calculator {
    private:
        float* numbers;
        int singlenum;
    public:
        virtual float* getNumbers() {
            return numbers;
        }
        virtual int getSinglenum(){
            return singlenum;
        }
        void setNumbers(float* numbers, int size) {
            this->numbers = new float[size];
            for (int i = 0; i < size; i++) {
                this->numbers[i] = numbers[i];
            }
        }
        void setSinglenum(int singlenum){
            this->singlenum = singlenum;
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

class StandardCalculator : public Calculator {
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
    void performSubtraction(int size) {
            float* numbers = getNumbers();
            for (int i = 1; i < size; i++) {
                numbers[i] = numbers[i-1] - numbers[i];
            }
        }
    void subtract(){
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
        performSubtraction(n);
        printResult(n);
        clearResult();
    }
    void performMultiply(int size) {
            float* numbers = getNumbers();
            for (int i = 1; i < size; i++) {
                numbers[i] = numbers[i-1] * numbers[i];
            }
        }
    void multiply(){
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
        performMultiply(n);
        printResult(n);
        clearResult();
    }
    void performDivide(int size) {
            float* numbers = getNumbers();
            for (int i = 1; i < size; i++) {
                numbers[i] = numbers[i-1] / numbers[i];
            }
        }
    void divide(){
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
        performDivide(n);
        printResult(n);
        clearResult();
    }
    void standardMenu() {
        string menuStan;
        while (true) {
            cout << "Standard Calculator \n1.) Addition\n2.) Subtraction\n3.) Multiplication\n4.) Division\n(x) to close\n=";
            cin >> menuStan;
            if (menuStan == "1"){
                addition();
            } else if (menuStan == "2"){
                subtract();
            } else if (menuStan == "3"){
                multiply();
            } else if (menuStan == "4"){
                divide();
            } else if (menuStan == "x"){
                break;
            } else {
                cout << "Invalid input. Please try again.\n";
            }
        }
    }
};
class ScientificCalculator : public Calculator {
    public :
    void performSqrt(){
        int numb = getSinglenum();
        int sqroot = sqrt(numb);
        cout << sqroot;
    }
    void squareroot(){
    cout << "Enter number = ";
    string input;
    cin >> input;
    if (input == "x"){
    }
    int num = stoi(input);
    setSinglenum(num);
    performSqrt();
    }
} ;
int main()
{
    StandardCalculator standard;
    ScientificCalculator scientific;
    standard.standardMenu();
    scientific.squareroot();

}
