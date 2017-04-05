//
// Created by klind on 4/4/2017.
//

#include <iostream>
#include "DictionaryTester.h"
#include "KeyValueTester.h"

int main() {
    DictionaryTester dictionaryTester;
    dictionaryTester.testSearch();
    dictionaryTester.testAdd();
    dictionaryTester.testGetByIndex();
    dictionaryTester.testGetByKey();
    dictionaryTester.testRemoveByIndex();
    dictionaryTester.testRemoveByKey();

    KeyValueTester keyValueTester;
}