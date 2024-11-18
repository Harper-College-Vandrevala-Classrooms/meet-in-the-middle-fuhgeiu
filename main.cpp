#include <fstream>
#include <sstream>
#include <iostream>

/* notes
 *
 *  median function is not written with performance in mind, written as practice of varius things
 *
 * no exception handling in the getline, ie the data file must contain only int types
 * no exception of length
 */

double median (const std::vector<int>& data) {
//
//    size_t size = data.size();
//    if (size == 0) std::cout << "no data processed\n"; return 0.0;
//
//    size_t slow = 0;
//    size_t fast = 0;
//
//    if (size % 2 == 1) {
//        slow = fast = size / 2;
//    } else {
//
//        slow = size / 2 - 1;
//        fast = size / 2;
//    }
//
//    if (size % 2 == 0) {
//        return (data[slow] + data[fast]) / 2.0;
//    } else {
//        return data[slow];
//    }

    size_t size = data.size();
    if (size == 0) {std::cout << "no data to process\n"; return 0.0;}

    if (size % 2 == 0) {
        return (data[size / 2 - 1] + data[size / 2]) / 2.0;
    }
    else {return data[size / 2];}
}


int main () {

    std::string filename;

    while (true) {

        std::cout << "enter filename\n";
        std::cin >> filename;

        if (std::cin.fail()) {

            std::cout << "invalid input\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }
        break;
    }

    std::ifstream filestreamobj(filename);
    if (!filestreamobj.is_open()) {
        std::cerr << "Error: Could not open the file." << std::endl;
        return 1;
    }

    std::vector<int> data;
    std::string line, toint;

    while (getline(filestreamobj, line)) {
        std::stringstream ss(line);

        while (getline(ss, toint, ',')) {         // WARNING! non caught exception will be thrown if file contiains non int
            data.push_back(stoi(toint));
        }
    }

    filestreamobj.close();

    std::cout << "The median is: " << median(data);
}