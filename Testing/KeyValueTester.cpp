//
// Created by klind on 4/4/2017.
//

#include <iostream>
#include "KeyValueTester.h"
#include "../KeyValue.h"

void KeyValueTester::testKeyValueConstructor() {
    std::cout << "KeyValueTester::testKeyValueConstructor" << std::endl;

    std::cout << "test case 1: int,int" << std::endl;
    KeyValue<int,int> kv1(4, 9);
    if (kv1.getKey() != 4)
        std::cout << "Failure in constructor unexpected value for getKey of " << kv1.getKey() << std::endl;
    if(kv1.getValue() != 9)
        std::cout << "Failure in constructor unexpected value for getValue of " << kv1.getValue() << std::endl;

}

void KeyValueTester::testGetKey() {
    std::cout << "KeyValueTester::testGetKey" << std::endl;

}

void KeyValueTester::testGetValue() {
    std::cout << "KeyValueTester::testGetValue()" << std::endl;

}