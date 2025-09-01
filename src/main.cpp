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
        auto vector_init_size = (unsigned int)((max / sizeof(unsigned int)) + 1);
        cout << "Size of vector: " << vector_init_size << endl;
        bitmap = std::vector<unsigned int>(vector_init_size, 0);

        std::for_each(
            std::cbegin(input), 
            std::cend(input), 
            [this](const unsigned int &n){ 
                this->set_key(n); 
            }
        );
    }

    BitMap(unsigned int max_value)
    {
        cout << "BitMap()" << endl;
        cout << "Max value: " << max_value << endl;
        cout << "Size of unsigned int: " << sizeof(unsigned int) << endl;
        auto vector_init_size = (unsigned int)((max_value / sizeof(unsigned int)) + 1);
        cout << "Size of vector: " << vector_init_size << endl;
        bitmap = std::vector<unsigned int>(vector_init_size, 0);

        // std::for_each(std::cbegin(input), std::cend(input), [this](const unsigned int &n)
        //               { this->set_key(n); });
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
    {
        BitMap bitmap(std::vector<unsigned int>{16, 2, 77, 40, 12071});

        unsigned int search = 1234;
        cout << "is " << search << " exist? " << bitmap.is_key_exist(search) << endl; // false

        search = 77;
        cout << "is " << search << " exist? " << bitmap.is_key_exist(search) << endl; // true
    }
    {
        BitMap bitmap(1000000000);
    }
    cin.get();
    return 0;
}
