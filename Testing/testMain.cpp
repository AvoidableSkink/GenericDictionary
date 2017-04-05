//
// Created by klind on 4/4/2017.
//

#include <iostream>
#include "DictionaryTester.h"
#include "KeyValueTester.h"

int main() {
    DictionaryTester dictionaryTester;
    dictionaryTester.testConstructors();
    dictionaryTester.testAdd();
    dictionaryTester.testGetByKey();
    dictionaryTester.testGetByIndex();
    dictionaryTester.testRemoveByKey();
    dictionaryTester.testRemoveByIndex();
    dictionaryTester.testSearch();

    KeyValueTester keyValueTester;
    keyValueTester.testKeyValueConstructor();
    keyValueTester.testGetKey();
    keyValueTester.testGetValue();
}