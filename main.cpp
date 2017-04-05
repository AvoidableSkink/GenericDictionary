#include <iostream>
#include "Dictionary.h"
#include "KeyValue.h"

int main() {
    Dictionary<std::string, std::string> myShows;
    myShows.add("Hwarang", "Not Finished");
    myShows.add("Strong Woman", "Still Airing");
    myShows.add("City Hunter", "Completed -- many times");

    myShows.add("Strong Woman", "who even knows");

    KeyValue<std::string, std::string> myKeyVal1 = myShows.getByKey("Hwarang");
    KeyValue<std::string, std::string> myKeyVal2 = myShows.getByIndex(1);
    KeyValue<std::string, std::string> myKeyVal3 = myShows.getByIndex(2);

    myShows.removeByIndex(3);

    for (int i = 0; i < myShows.getCount(); ++i) {
        KeyValue<std::string, std::string> myKeyVal2 = myShows.getByIndex(i);
        std::cout << myKeyVal2.getKey() << std::endl;
    }

//    std::cout << "Series: " << myKeyVal1.getKey() << " Status: " << myKeyVal1.getValue() << std::endl;
//    std::cout << "Series: " << myKeyVal2.getKey() << " Status: " << myKeyVal2.getValue();

}