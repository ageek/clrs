#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

void bubbleSort(std::vector<int>);

int main() {
    int length;
    std::cout << "Enter size :" << std::endl;
    std::cin >> length;

    int max = 1000;
    std::vector<int> data;
    for (int i = 0; i < length; i++)
        data.push_back(std::rand()% max);

    for (auto x: data)
        std::cout << x << ", ";
    std::cout << std::endl;
    //sort data
    bubbleSort(data);

    std::cout << "Sorting using STL containers" << std::endl;
    std::sort(data.begin(), data.end());
    for (auto x: data)
        std::cout << x << ", ";
    std::cout << std::endl;
 
}

void bubbleSort(std::vector<int> data) {

    for (int i = 0; i < data.size(); i++) {
        for (int j = data.size()-1; j > i; j--) {
            if (data.at(j) <  data.at(j - 1)) {
                int temp = data.at(j);
                data.at(j) = data.at(j-1);
                data.at(j-1) = temp;
            }
        }
    }
    for (auto x: data)
        std::cout << x << ", ";
    std::cout << std::endl;
}