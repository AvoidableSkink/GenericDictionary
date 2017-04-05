//
// Created by klind on 4/4/2017.
//

#include <iostream>
#include "DictionaryTester.h"
#include "../Dictionary.h"

void DictionaryTester::testAdd() {
    std::cout << "DictionaryTester::testAdd" << std::endl;

    Dictionary<std::string, std::string> myShows;
    myShows.add("Hwarang", "Not Finished");
    myShows.add("Strong Woman", "Still Airing");
    myShows.add("City Hunter", "Completed -- many times");

    if ((myShows.getByIndex(0).getKey() != "Hwarang") || (myShows.getByIndex(0).getValue() != "Not Finished"))
    {
        std::cout << "Failure adding KeyValue Hwarang, " << myShows.getByIndex(0).getKey() << " found instead" << std::endl;
    }
    if ((myShows.getByIndex(1).getKey() != "Strong Woman") || (myShows.getByIndex(1).getValue() != "Still Airing"))
    {
        std::cout << "Failure adding KeyValue Strong Woman, " << myShows.getByIndex(1).getKey() << " found instead" << std::endl;
    }
    if ((myShows.getByIndex(2).getKey() != "City Hunter") || (myShows.getByIndex(2).getValue() != "Completed -- many times"))
    {
        std::cout << "Failure adding KeyValue City Hunter, " << myShows.getByIndex(2).getKey() << " found instead" << std::endl;
    }

    myShows.add("Strong Woman", "who even knows");
    if (myShows.getCount() != 3)
    {
        std::cout << "Failure: Duplicate Key added" << std::endl;
    }
    if (myShows.getByKey("Strong Woman").getValue() == "who even knows")
    {
        std::cout << "Failure: KeyValue value changed after attempt to add duplicate key" << std::endl;
    }
}

void DictionaryTester::testGetByIndex() {
    std::cout << "DictionaryTester::testGetByIndex" << std::endl;

    Dictionary<std::string, std::string> myShows;
    myShows.add("Hwarang", "Not Finished");
    myShows.add("Strong Woman", "Still Airing");
    myShows.add("City Hunter", "Completed -- many times");

    KeyValue<std::string, std::string> myKeyVal0 = myShows.getByIndex(0);
    KeyValue<std::string, std::string> myKeyVal1 = myShows.getByIndex(1);
    KeyValue<std::string, std::string> myKeyVal2 = myShows.getByIndex(2);
    if ((myKeyVal0.getKey() != "Hwarang") || (myKeyVal0.getValue() != "Not Finished"))
    {
        std::cout << "Failure in attempt to retrieve KeyValue. Hwarang, Not finished was expected"
                  << myKeyVal0.getKey() << ", " << myKeyVal0.getValue() << "found instead." << std::endl;
    }
    if ((myKeyVal1.getKey() != "Strong Woman") || (myKeyVal1.getValue() != "Still Airing"))
    {
        std::cout << "Failure in attempt to retrieve KeyValue. Strong Woman, Still Airing was expected"
                  << myKeyVal1.getKey() << ", " << myKeyVal1.getValue() << "found instead." << std::endl;
    }
    if ((myKeyVal2.getKey() != "City Hunter") || (myKeyVal2.getValue() != "Completed -- many times"))
    {
        std::cout << "Failure in attempt to retrieve KeyValue. City Hunter, Completed -- many times was expected"
                  << myKeyVal2.getKey() << ", " << myKeyVal2.getValue() << "found instead." << std::endl;
    }

    bool right = false;
    try {
        KeyValue<std::string, std::string> myKeyVal2 = myShows.getByIndex(3);
    }
    catch (std::out_of_range) {right = true;}
    if (!right)
    {
        std::cout << "Failure: allowed access to an index out of bounds" << std::endl;
    }

    right = false;
    try {
        KeyValue<std::string, std::string> myKeyVal2 = myShows.getByIndex(-1);
    }
    catch (std::out_of_range ) {right = true;}
    if (!right)
    {
        std::cout << "Failure: allowed access to an index out of bounds" << std::endl;
    }
}

void DictionaryTester::testGetByKey() {
    std::cout << "DictionaryTester::testGetByKey" << std::endl;

    Dictionary<std::string, std::string> myShows;
    myShows.add("Hwarang", "Not Finished");
    myShows.add("Strong Woman", "Still Airing");
    myShows.add("City Hunter", "Completed -- many times");

    KeyValue<std::string, std::string> myKeyVal0 = myShows.getByKey("Hwarang");
    KeyValue<std::string, std::string> myKeyVal1 = myShows.getByKey("Strong Woman");
    KeyValue<std::string, std::string> myKeyVal2 = myShows.getByKey("City Hunter");
    if ((myKeyVal0.getKey() != "Hwarang") || (myKeyVal0.getValue() != "Not Finished"))
    {
        std::cout << "Failure in attempt to retrieve KeyValue. Hwarang, Not finished was expected"
                  << myKeyVal0.getKey() << ", " << myKeyVal0.getValue() << "found instead." << std::endl;
    }
    if ((myKeyVal1.getKey() != "Strong Woman") || (myKeyVal1.getValue() != "Still Airing"))
    {
        std::cout << "Failure in attempt to retrieve KeyValue. Strong Woman, Still Airing was expected"
                  << myKeyVal1.getKey() << ", " << myKeyVal1.getValue() << "found instead." << std::endl;
    }
    if ((myKeyVal2.getKey() != "City Hunter") || (myKeyVal2.getValue() != "Completed -- many times"))
    {
        std::cout << "Failure in attempt to retrieve KeyValue. City Hunter, Completed -- many times was expected"
                  << myKeyVal2.getKey() << ", " << myKeyVal2.getValue() << "found instead." << std::endl;
    }
}

void DictionaryTester::testRemoveByKey() {
    std::cout << "DictionaryTester::testRemoveByKey" << std::endl;

    Dictionary<std::string, std::string> myShows;
    myShows.add("Hwarang", "Not Finished");
    myShows.add("Strong Woman", "Still Airing");
    myShows.add("City Hunter", "Completed -- many times");
    myShows.add("House", "Complete");
    myShows.add("The Heirs", "Complete");

    myShows.removeByKey("Hwarang");
    if (myShows.search("Hwarang") || myShows.getCount() != 4)
    {
        std::cout << "Failed to remove KeyValue with key 'Hwarang'" << std::endl;
    }
    myShows.removeByKey("The Heirs");
    if (myShows.search("The Heirs") || myShows.getCount() != 3)
    {
        std::cout << "Failed to remove KeyValue with key 'The Heirs'" << std::endl;
    }
    myShows.removeByKey("City Hunter");
    if (myShows.search("City Hunter") || myShows.getCount() != 2)
    {
        std::cout << "Failed to remove KeyValue with key 'City Hunter'" << std::endl;
    }
}

void DictionaryTester::testRemoveByIndex() {
//    myShows.removeByIndex(2);
//    std::cout << "Series: " << myKeyVal1.getKey() << " Status: " << myKeyVal1.getValue() << std::endl;
//    std::cout << "Series: " << myKeyVal2.getKey() << " Status: " << myKeyVal2.getValue();
}

void DictionaryTester::testSearch() {

}
