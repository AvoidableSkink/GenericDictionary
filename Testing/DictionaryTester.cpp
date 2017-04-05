//
// Created by klind on 4/4/2017.
//

#include <iostream>
#include "DictionaryTester.h"
#include "../Dictionary.h"

void DictionaryTester::testConstructors() {
    std::cout << "DictionaryTester::testConstructors" << std::endl;

    Dictionary<std::string, std::string> defaultConstructor;
    if (defaultConstructor.getCount() != 0 && defaultConstructor.getCurrentCapacity() != 10)
    {
        std::cout << "Failure in Default constructor" << std::endl;
    }
    Dictionary<int, int> parameterizedConstructor(2);
    if (parameterizedConstructor.getCount() != 0 && parameterizedConstructor.getCurrentCapacity() != 2)
    {
        std::cout << "Failure in parameterized constructor" << std::endl;
    }
}

void DictionaryTester::testAdd() {
    std::cout << "DictionaryTester::testAdd" << std::endl;

    //test using a string key
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

    bool right = false;
    try {
        myShows.add("Strong Woman", "who even knows");
    }
    catch (std::invalid_argument) {right = true;}
    if (!right)
    {
        std::cout << "Failure: Allowed Duplicate Keys/Changed existing Key" << std::endl;
    }

    //Test using an int key
    Dictionary<int, int> myDouble;
    myDouble.add(1, 2);
    myDouble.add(3, 6);
    myDouble.add(9, 18);

    KeyValue<int, int> myKey0 = myDouble.getByIndex(0);
    KeyValue<int, int> myKey1 = myDouble.getByIndex(1);
    KeyValue<int, int> myKey2 = myDouble.getByIndex(2);
    if ((myKey0.getKey() != 1) || (myKey0.getValue() != 2))
    {
        std::cout << "Failure adding KeyValue '1', " << myShows.getByIndex(0).getKey() << " found instead" << std::endl;
    }
    if ((myKey1.getKey() != 3) || (myKey1.getValue() != 6))
    {
        std::cout << "Failure adding KeyValue '3', " << myShows.getByIndex(1).getKey() << " found instead" << std::endl;
    }
    if ((myKey2.getKey() != 9) || (myKey2.getValue() != 18))
    {
        std::cout << "Failure adding KeyValue '9', " << myShows.getByIndex(2).getKey() << " found instead" << std::endl;
    }


    right = false;
    try {
        myDouble.add(3, 89);
    }
    catch (std::invalid_argument) {right = true;}
    if (!right)
    {
        std::cout << "Failure: Allowed Duplicate Keys/Changed existing Key" << std::endl;
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
    std::cout << "DictionaryTester::testRemoveByIndex" << std::endl;

    Dictionary<std::string, std::string> myShows;
    myShows.add("Hwarang", "Not Finished");
    myShows.add("Strong Woman", "Still Airing");
    myShows.add("City Hunter", "Completed -- many times");
    myShows.add("House", "Complete");
    myShows.add("The Heirs", "Complete");

    //test correct use of removeByIndex
    myShows.removeByIndex(0);
    if (myShows.search("Hwarang") || myShows.getCount() != 4)
    {
        std::cout << "Failed to remove KeyValue with index 0" << std::endl;
    }
    myShows.removeByIndex(3);
    if (myShows.search("The Heirs") || myShows.getCount() != 3)
    {
        std::cout << "Failed to remove KeyValue with index 3" << std::endl;
    }
    myShows.removeByIndex(1);
    if (myShows.search("City Hunter") || myShows.getCount() != 2)
    {
        std::cout << "Failed to remove KeyValue with index 1" << std::endl;
    }

    //test out of bounds removeByIndex
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

void DictionaryTester::testSearch() {
    std::cout << "DictionaryTester::testSearch" << std::endl;

    Dictionary<std::string, std::string> myShows;
    myShows.add("Hwarang", "Not Finished");
    myShows.add("Strong Woman", "Still Airing");
    myShows.add("City Hunter", "Completed -- many times");

    //these should work (return true)
    if (!myShows.search("Hwarang"))
    {
        std::cout << "Failure in searching for key Hwarang. Existing key was not found." << std::endl;
    }
    if (!myShows.search("City Hunter"))
    {
        std::cout << "Failure in searching for key 'City Hunter'. Existing key was not found." << std::endl;
    }
    if (!myShows.search("Strong Woman"))
    {
        std::cout << "Failure in searching for key 'Strong Woman'. Existing key was not found." << std::endl;
    }

    //these should not work (return false)
    if (myShows.search("The Heirs"))
    {
        std::cout << "Failure in searching for key 'The Heirs'. non-existant key was found." << std::endl;
    }
    if (myShows.search(""))
    {
        std::cout << "Failure in searching for key ''. non-existant key was found." << std::endl;
    }
    if (myShows.search(" "))
    {
        std::cout << "Failure in searching for key ' '. non-existant key was found." << std::endl;
    }

}
