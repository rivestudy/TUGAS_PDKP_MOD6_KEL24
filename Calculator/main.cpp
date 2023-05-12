#include <iostream>
#include <cmath>

using namespace std;

class Calculator {
    private:
        float* numbers;
        float singlenum;
        int repeat;
    public:
        virtual float* getNumbers(){
            return numbers;
        }
        virtual float getSinglenum(){
            return singlenum;
        }
        virtual int getRep(){
            return repeat;
        }
        void setNumbers(float* numbers, int size) {
            this->numbers = new float[size];
            for (int i = 0; i < size; i++) {
                this->numbers[i] = numbers[i];
            }
        }
        void setSinglenum(float singlenum){
            this->singlenum = singlenum;
        }
        void setRepeat(int repeat){
            this-> repeat = repeat;
        }
        void printResult(int size) {
            cout << "Result: ";
            float* resultArray = getNumbers();
            cout << resultArray[size - 1] << endl;
        }
        void printSing(){
            cout << "Result: ";
            float singlenum = getSinglenum();
            cout << singlenum << endl;
        }
        void clearResult() {
        delete[] numbers;
        numbers = nullptr;
        }
        void clearSing(){
        singlenum = 0;
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
        float numb = getSinglenum();
        float sqroot = sqrt(numb);
        setSinglenum(sqroot);
    }
    void squareroot(){
        while (true){
            cout << "Enter number = ";
            string input;
            cin >> input;
            if (input == "x"){
                break;
            }
            float num = stof(input);
            setSinglenum(num);
            performSqrt();
            printSing();
            clearSing();
        }
    }
    void performExponent(float numb, int power){
        float exponent = 1;
        for (int i = 0; i < power; i++) {
            exponent *= numb;
            setSinglenum(exponent);
        }
    }
    void exponent(){
        while(true){
            cout << "Enter number = ";
            string input;
            int rep;
            cin >> input;
            if (input == "x"){
                    break;
                }
            cout << "Enter exponent degree = ";
            cin >>  rep;
            if (input == "x"){
                    break;
                }
            float num = stof(input);
            performExponent(num, rep);
            printSing();
            clearSing();
        }
    }
    void performFactorial(float numb){
        float fact = 1;
        for (float i = 1; i < numb + 1 ; i++) {
            fact *= i;
            setSinglenum(fact);
        }
    }
    void factorial(){
        while(true){
            cout << "Enter number = ";
            string input;
            cin >> input;
            if (input == "x"){
                    break;
                }
            float num = stoi(input);
            performFactorial(num);
            printSing();
            clearSing();
        }
    }
    void scientificMenu(){
        string menuScie;
        while(true){
            cout << "Scientific Calculator\n1.) SquareRoot\n2.) Exponent\n3.) Factorial\n(x) to close\n = ";
            cin >> menuScie;
            if (menuScie == "1"){
                squareroot();
            } else if (menuScie == "2"){
                exponent();
            } else if (menuScie == "3"){
                factorial();
            } else if (menuScie == "x"){
                break;
            } else {
                cout << "Invalid input. Please try again.\n";
            }
        }
    }
} ;
int main()
{
    StandardCalculator standard;
    ScientificCalculator scientific;
    cout
    standard.standardMenu();
    scientific.scientificMenu();

