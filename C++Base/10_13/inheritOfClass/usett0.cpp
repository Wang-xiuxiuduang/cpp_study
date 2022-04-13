#include <iostream>

#include "headFiles/rp0.h"
#include "headFiles/tabtenn0.h"

using namespace std;

int main() {
    // TableTennisPlayer t1("Zezhong", "Wang", true);
    // TableTennisPlayer t2("Xingchi", "Zhou", false);
    // t1.getName();
    // if (t1.HasTable())
    // {
    //     cout << ": has a table.\n";
    // }
    // else
    // {
    //     cout << ": hasn't a table.\n";
    // }
    // t2.getName();
    // if (t2.HasTable())
    // {
    //     cout << ": has a table.\n";
    // }
    // else
    // {
    //     cout << ": hasn't a table.\n";
    // }

    RatedPlayer rp1("San", "Zhang", true, 12);
    cout << "rating: " << rp1.getRating() << endl;
    rp1.getName();

    return 0;
}