//
// Created by klind on 4/4/2017.
//

#include <iostream>
#include "KeyValueTester.h"
#include "../KeyValue.h"

void KeyValueTester::testKeyValueConstructor() {
    std::cout << "KeyValueTester::testKeyValueConstructor" << std::endl;

    KeyValue<int,int> kv1(4, 9);
    if (kv1.getKey() != 4)
        std::cout << "Failure in constructor unexpected value for getKey of " << kv1.getKey() << std::endl;
    if(kv1.getValue() != 9)
        std::cout << "Failure in constructor unexpected value for getValue of " << kv1.getValue() << std::endl;

    KeyValue<std::string, std::string> kv2("key", "value");
    if (kv2.getKey() != "key")
        std::cout << "Failure in constructor unexpected value for getKey of " << kv2.getKey() << std::endl;
    if(kv2.getValue() != "value")
        std::cout << "Failure in constructor unexpected value for getValue of " << kv2.getValue() << std::endl;

    KeyValue<int, std::string> kv3(5, "my Keys value is 5");
    if (kv3.getKey() != 5)
        std::cout << "Failure in constructor unexpected value for getKey of " << kv3.getKey() << std::endl;
    if(kv3.getValue() != "my Keys value is 5")
        std::cout << "Failure in constructor unexpected value for getValue of " << kv3.getValue() << std::endl;
}

void KeyValueTester::testGetKey() {
    std::cout << "KeyValueTester::testGetKey" << std::endl;

    KeyValue<std::string, std::string> kv2("key", "value");
    if (kv2.getKey() != "key")
        std::cout << "Failure in retrieval of key. value of 'key' expected, "
                  << kv2.getKey() << " found instead." << std::endl;

}

void KeyValueTester::testGetValue() {
    std::cout << "KeyValueTester::testGetValue()" << std::endl;

    KeyValue<std::string, std::string> kv2("key", "value");
    if (kv2.getValue() != "value")
        std::cout << "Failure in retrieval of key. value of 'value' expected, "
                  << kv2.getKey() << " found instead." << std::endl;
}