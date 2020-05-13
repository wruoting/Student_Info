// Student_info.h header file
#include "Student_info.h"

bool compare(const Student_info& x, const Student_info& y) {
    return x.name < y.name;
};


std::istream& read(std::istream& is, Student_info& s){
    // read and store the student's name and midterm and final grades
    std::cout << "Please enter the name, midterm, then final separated by spaces" << std::endl;
    // Remember that these are separated by whitespace
    is >> s.name >> s.midterm >> s.final;
    std::cout << "Enter Homework separated by spaces" << std::endl;
    std::cout << "End line with ctrl z" << std::endl;
    read_hw(is, s.homework);
    std::cout << "Done reading student " << s.name << std::endl;

    return is;
};

std::istream& read_hw(std::istream& in, std::vector<double>& hw) {
    if (in) {
        // get rid of previous contents
        hw.clear();
        double x;
        while (in >> x) {
            hw.push_back(x);
        }
        in.clear();
        std::cout << "Read Homework" << std::endl;
    }
    return in;
};