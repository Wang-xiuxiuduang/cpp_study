#ifndef TABTENN0_H_
#define TABTENN0_H_
#include <string>
using std::string;

class TableTennisPlayer {
private:
    string firstName;
    string lastName;
    bool hasTable;

public:
    // constructors
    TableTennisPlayer(const string &fn = "none", const string &ln = "none", bool ht = false);
    TableTennisPlayer();

    // deconstructor
    virtual ~TableTennisPlayer() {
        std::cout << "TableTennisPlayer deconstructor..." << std::endl;
    };

    // other methods
    void getName() const;
    bool HasTable() const;
    void ResetTable(bool v);
};

#endif
