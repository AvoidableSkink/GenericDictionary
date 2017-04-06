#include <iostream>
#include "Dictionary.h"
#include "KeyValue.h"

int main() {

    Dictionary<std::string, std::string> myShows;
    myShows.add("Hwarang", "Not Finished");
    myShows.add("Strong Woman", "Still on air");
    myShows.add("City Hunter", "Completed -- many times");
    myShows.add("House", "Complete");
    myShows.add("The Heirs", "Complete");

    myShows.removeByKey("House");

    for (int i = 0; i < myShows.getCount(); ++i) {
        KeyValue<std::string, std::string> myKeyVal = myShows.getByIndex(i);
        std::cout << "Show: " << myKeyVal.getKey() << "   Status: " << myKeyVal.getValue() << std::endl;
    }

    KeyValue<std::string, std::string> myKeyVal = myShows.getByKey("City Hunter");
    std::cout << "My favorite show is " << myKeyVal.getKey() << " and its current status is " << myKeyVal.getValue() << std::endl;
}