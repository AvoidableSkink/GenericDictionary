#include <iostream>
#include "Dictionary.h"
#include "KeyValue.h"

int main() {
    Dictionary<std::string, std::string> myShows;
    myShows.add("Hwarang", "Not Finished");
    myShows.add("Strong Woman", "Still Airing");
    myShows.add("City Hunter", "Completed -- many times");

    KeyValue<std::string, std::string> myKeyVal = myShows.getByKey("Hwarang");
    std::cout << "Series: " << myKeyVal.getKey() << " Status: " << myKeyVal.getValue();
}