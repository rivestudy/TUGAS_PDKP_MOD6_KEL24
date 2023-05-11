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
int main()
{

}
