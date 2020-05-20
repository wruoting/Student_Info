// Student_info.h header file
#include "Student_info.h"
#include "grade.h"

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

bool fgrade(const Student_info& s) {
    return grade(s) < 60;
};

std::vector<Student_info> extract_fails(std::vector<Student_info>& students) {
    std::vector<Student_info> passes, fails;

    for(std::vector<Student_info>::size_type i = 0; i != students.size(); ++i) {
        if(fgrade(students[i])) {
            fails.push_back(students[i]);
        } else {
            passes.push_back(students[i]);
        }
    }
    students = passes;
    return fails;
}

std::vector<Student_info> extract_fails_iterator(std::vector<Student_info>& students) {
    std::vector<Student_info> fails;
    std::vector<Student_info>::iterator iter = students.begin();
    // We CANNOT use a for loop here, because your vector.end() points towards the end of the vector you
    // JUST invalidated, and therefore we need to call vector.end() again after an erase()
    while(iter != students.end()) {
        if (fgrade(*iter)) {
            fails.push_back(*iter);
            iter = students.erase(iter);
        } else {
            ++iter;
        }
    }
    return fails;
}

std::list<Student_info> extract_fails_iterator(std::list<Student_info>& students) {
    std::list<Student_info> fails;
    std::list<Student_info>::iterator iter = students.begin();
    // We CANNOT use a for loop here, because your vector.end() points towards the end of the vector you
    // JUST invalidated, and therefore we need to call vector.end() again after an erase()
    while(iter != students.end()) {
        if (fgrade(*iter)) {
            fails.push_back(*iter);
            iter = students.erase(iter);
        } else {
            ++iter;
        }
    }
    return fails;
}

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