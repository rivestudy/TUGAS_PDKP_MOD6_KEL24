#include <iostream>
#include <cmath>
#include <iomanip>

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
            cout << fixed << std::setprecision(2) << singlenum << endl;
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
            cout << "Standard Calculator \n=========================\n1.) Addition\n2.) Subtraction\n3.) Multiplication\n4.) Division\n(x) to close\n=";
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
            float num = stof(input);
            performFactorial(num);
            printSing();
            clearSing();
        }
    }
    void scientificMenu(){
        string menuScie;
        while(true){
            cout << "Scientific Calculator\n=========================\n1.) SquareRoot\n2.) Exponent\n3.) Factorial\n(x) to close\n = ";
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
class ConversionCalculator : public Calculator{
    public :
    void performDivConvert(float dec, float val){
        float conv;
        conv = dec / val;
        setSinglenum(conv);
    }
    void performMulConvert(float dec, float val){
        float conv;
        conv = dec * val;
        setSinglenum(conv);
        }
    void rpdollarConvert(){
        while(true){
        cout << "Enter Rupiah value = Rp.";
        string input;
        cin >> input;
        if (input == "x"){
                break;
            }
        float num = stof(input);
        performDivConvert(num , 14800);
        printSing();
        clearSing();
        }
    }
    void dollarrpConvert(){
        while(true){
        cout << "Enter Dollar value = $";
        string input;
        cin >> input;
        if (input == "x"){
                break;
            }
        float num = stof(input);
        performMulConvert(num , 14800);
        printSing();
        clearSing();
        }
    }
    void rppsConvert(){
        while(true){
        cout << "Enter Rupiah value = Rp.";
        string input;
        cin >> input;
        if (input == "x"){
                break;
            }
        float num = stof(input);
        performDivConvert(num , 18500);
        printSing();
        clearSing();
        }
    }
    void psrpConvert(){
        while(true){
        cout << "Enter Pound Sterling value = £";
        string input;
        cin >> input;
        if (input == "x"){
                break;
            }
        float num = stof(input);
        performMulConvert(num , 18500);
        printSing();
        clearSing();
        }
    }
    void rpyenConvert(){
        while(true){
        cout << "Enter Rupiah value = Rp.";
        string input;
        cin >> input;
        if (input == "x"){
                break;
            }
        float num = stof(input);
        performDivConvert(num , 109.70);
        printSing();
        clearSing();
        }
    }
    void yenrpConvert(){
        while(true){
        cout << "Enter Yen value = ¥";
        string input;
        cin >> input;
        if (input == "x"){
                break;
            }
        float num = stof(input);
        performMulConvert(num , 109.70);
        printSing();
        clearSing();
        }
    }
    void conversionMenu(){
        string menuConv;
        while(true){
            cout << "Conversion Calculator\n=========================\n1.) IDR to USD\n2.) USD to IDR\n3.) IDR to GBP\n4.) GBP to IDR\n5.) IDR to JPY\n6.) JPY to IDR\n(x) to close\n = ";
            cin >> menuConv;
                if (menuConv == "1"){
                    rpdollarConvert();
                } else if (menuConv == "2"){
                    dollarrpConvert();
                } else if (menuConv == "3"){
                    rppsConvert();
                } else if (menuConv == "4"){
                    psrpConvert();
                } else if (menuConv == "5"){
                    rpyenConvert();
                } else if (menuConv == "6"){
                    yenrpConvert();
                } else if (menuConv == "x"){
                    break;
                } else {
                    cout << "Invalid input. Please try again.\n";
                }
        }
    }
};
int main()
{
    StandardCalculator standard;
    ScientificCalculator scientific;
    ConversionCalculator convert;

    cout << "Calculator\n=========================\n1.) Standard Calculator\n2.) Scientific Calculator\n3.) Conversion Calculator\n(x) to close\n = ";
    convert.conversionMenu();
    standard.standardMenu();
    scientific.scientificMenu();

}
