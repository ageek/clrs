#include <iostream>
#include <vector>
#include <ctime>

int main() {
    int length;
    std::cout << "Enter length " << std::endl;
    std::cin >> length;

    std::vector<int> data;
    std::srand(std::time(0));
    for(int i = 0; i < length;i++) {
        data.push_back(std::rand() % 200);
    }

    std::cout << "Generated data: " << std::endl;
    for(auto x: data) {
        std::cout << x << ","; 
    }
    std::cout << std::endl;

    // brute force: O(n^2)
    int count = 0;
    for (int i=0; i < length-1; i++) {
        for (int j=i+1; j < length; j++) {
            if ( data[i] >  data[j] )  {
                std::cout << " Inversion: " << data[i] << " > " << data[j] << std::endl;
                count++;
            }
            }
    }
    std::cout << " Total inversions: " << count << std::endl;
}