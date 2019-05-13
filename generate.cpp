#include <iostream>
#include <random>
#include <functional>
#include <string>
#include <algorithm>

int main(int argc, char **argv) {
    std::random_device randomDevice;
    std::mt19937 randomGenerator = std::mt19937(randomDevice());

    auto randomSubject = std::bind(std::uniform_int_distribution<int>(1, 10), randomGenerator);
    auto randomCredit = std::bind(std::uniform_int_distribution<int>(0, 4), randomGenerator);
    auto randomStudent = std::bind(std::uniform_int_distribution<int>(3, 40), randomGenerator);
    auto randomScore = std::bind(std::uniform_int_distribution<int>(0, 100), randomGenerator);

    std::string subjects[] = {
            "Chinese", "English", "Math", "Physical", "Chemistry",
            "Biological", "GeoScience", "Geography", "History", "Citizenship"
    };

    std::string names[] = {
            "Othelia", "Brittney", "Osmond", "Gabriele", "Kain", "Hillyer", "Selma", "Arlen", "Haleigh", "Elston",
            "Fraser", "Berte", "Britney", "Ede", "Prince", "Ebony", "Kylie", "Leann", "Shela", "Doug", "Michel",
            "Kathrine", "Kippar", "Manon", "Sharlene", "Dar", "Eric", "Laraine", "Corney", "Marven", "Vincents",
            "Mikkel", "Auroora", "Justine", "Drusilla", "Monah", "Dorry", "Olivie", "Brittany", "Hoyt", "Dorice",
            "Hailey", "Beverly", "Buddy", "Janis", "Lacey", "Gillan", "Cobby", "Catlee", "Dorothea", "Annabelle",
            "Sanders", "Tammie", "Kean", "Cherilyn", "Colline", "Jobye", "Padraig", "Alyosha", "Herta", "Frants",
            "Joceline", "Amelita", "Trina", "Julianne", "Tabbi", "Myrah", "Patricio", "Carlynne", "Karisa", "Gawen",
            "Webster", "Loralie", "Trisha", "Eberto", "Charo", "Shaylyn", "Storm", "Christalle", "Annamarie", "Adela",
            "Robbie", "Huntley", "Catherine", "Almira", "Hirsch", "Doria", "Electra", "Zachariah", "Fons", "Sherlock",
            "Veradis", "Gav", "Celestia", "Dion", "Dunc", "Veronique", "Garry", "Even", "Casar"
    };

    long long int n = 5;
    if (argc > 1) n = std::stoll(argv[1]);

    if (n-- > 0) {
        std::cout << "2 Math 3 English 2" << std::endl
                  << "3" << std::endl
                  << "Lina 40 60" << std::endl
                  << "Aisa 23 45" << std::endl
                  << "Amer 70 92" << std::endl;
    }

    while (n-- > 0) {
        std::cout << std::endl;

        int subjectCount = randomSubject(), studentCount = randomStudent(), scoreCount = randomScore();

        std::shuffle(subjects, subjects + 10, randomGenerator);
        std::shuffle(names, names + 100, randomGenerator);

        std::cout << subjectCount;
        for (int i = 0; i < subjectCount; ++i) std::cout << ' ' << subjects[i] << ' ' << randomCredit();
        std::cout << std::endl;

        std::cout << studentCount << std::endl;
        for (int i = 0; i < studentCount; ++i) {
            std::cout << names[i];
            for (int j = 0; j < subjectCount; ++j) std::cout << ' ' << randomScore();
            std::cout << std::endl;
        }
    }

    return 0;
}
