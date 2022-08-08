#include <iostream>
#include <sstream>
#include <string>
#include <memory>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

class BitMap
{
private:
    std::vector<unsigned int> bitmap;

    void set_key(const unsigned int &key)
    {
        int array_index = key >> 5;
        int bit_index = key & 31;
        // set 1
        bitmap.at(array_index) |= 1 << bit_index;
    }

    void unset_key(const unsigned int &key)
    {
        int array_index = key >> 5;
        int bit_index = key & 31;
        // set 0
        bitmap.at(array_index) &= ~(1 << bit_index);
        // System.out.println(get32BitBinString(bigArray[arrayIndex]));
    }

    // private static String get32BitBinString(int number) {
    //     StringBuilder sBuilder = new StringBuilder();
    //     for (int i = 0; i < 32; i++){
    //         sBuilder.append(number & 1);
    //         number = number >>> 1;
    //     }
    //     return sBuilder.reverse().toString();
    // }

public:
    BitMap(std::vector<unsigned int> input)
    {
        cout << "BitMap()" << endl;
        auto max = *max_element(std::cbegin(input), std::cend(input)); // C++11
        
        cout << "Max value: " << max << endl;
        cout << "Size of unsigned int: " << sizeof(unsigned int) << endl;
        bitmap = std::vector<unsigned int>((unsigned int)(max / sizeof(unsigned int) + 1), 0);

        std::for_each(std::cbegin(input), std::cend(input), [this](const unsigned int &n)
                      { this->set_key(n); });
    }

    bool is_key_exist(const unsigned int &key)
    {
        int array_index = key >> 5;
        int bit_index = key & 31;
        return (bitmap.at(array_index) & (1 << bit_index)) != 0;
    }
};

int main()
{
    std::vector<unsigned int> input = {16, 2, 77, 40, 12071};
    BitMap bitmap(input);

    unsigned int search = 1234;
    cout << "is " << search << " exist? " << bitmap.is_key_exist(search) << endl; // false

    search = 77;
    cout << "is " << search << " exist? " << bitmap.is_key_exist(search) << endl; // true

    cin.get();
    return 0;
}