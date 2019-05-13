#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <numeric>
#include <algorithm>
#include <cmath>

struct Subject {
    std::string name;
    int credit;
};

struct Student {
    std::string name;
    std::vector<int> scores;
    double mean;
};

int main() {
    unsigned int subjectCount, studentCount;
    while (std::cin >> subjectCount) {
        std::vector<Subject> subjects(subjectCount);
        for (auto &subject: subjects) std::cin >> subject.name >> subject.credit;

        std::cin >> studentCount;
        std::vector<Student> students(studentCount);
        for (auto &student: students) {
            std::cin >> student.name;
            student.scores.resize(subjectCount);
            for (auto &score:student.scores) std::cin >> score;
        }

        std::cout << std::fixed << std::setprecision(2);
        for (auto &student: students) {
            student.mean = 0;
            for (int i = 0; i < subjectCount; ++i) student.mean += student.scores[i] * subjects[i].credit;
            student.mean /= std::accumulate(subjects.begin(), subjects.end(), 0,
                                            [](int sum, const Subject &subject) { return sum + subject.credit; });

            std::cout << student.name << ' ' << student.mean << std::endl;

            std::cout << "PASS:";
            for (int i = 0; i < subjectCount; ++i) {
                if (student.scores[i] < 60) continue;
                std::cout << ' ' << subjects[i].name;
            }
            std::cout << std::endl;

            std::cout << "FAIL:";
            for (int i = 0; i < subjectCount; ++i) {
                if (student.scores[i] >= 60) continue;
                std::cout << ' ' << subjects[i].name;
            }
            std::cout << std::endl;
        }

        std::cout << std::endl;
        for (int i = 0; i < subjectCount; ++i) {
            if (i > 0) std::cout << ' ';
            std::cout << subjects[i].name << ": " << (*std::max_element(
                    students.begin(), students.end(),
                    [&](const Student &a, const Student &b) { return a.scores[i] < b.scores[i]; })).name;
        }
        std::cout << std::endl;

        double scoreMean = std::accumulate(
                students.begin(), students.end(), 0,
                [](int sum, const Student &student) { return sum + student.mean; });
        scoreMean /= studentCount;

        double scoreStdDev = std::sqrt(std::accumulate(
                students.begin(), students.end(), 0.0,
                [&](int sum, const Student &student) { return sum + std::pow(student.mean - scoreMean, 2.0); }));

        std::cout << std::endl << "Mean: " << scoreMean << " StdDev: " << scoreStdDev << std::endl;

    }
    return 0;
}
