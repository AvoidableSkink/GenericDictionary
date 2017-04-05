//
// Created by klind on 4/4/2017.
//

#ifndef GENERICDICTIONARY_DICTIONARY_H
#define GENERICDICTIONARY_DICTIONARY_H

#include "KeyValue.h"

template <typename X, typename Y>
class Dictionary {
private:
    int count;

public:
    Dictionary();
    Dictionary(int size);
    Dictionary(const Dictionary&);

    void add(X key, Y value);
    KeyValue<X, Y> getByKey(X key);
    KeyValue<X, Y> getByIndex(int index);
    void removeByKey(X key);
    void removeByIndex(int index);

    int getCount() const { return count; }
};

const int DEFAULT_DICTIONARY_SIZE = 10;

//set default size to default size lol
template <typename X, typename Y>
Dictionary<X,Y>::Dictionary() {

}

//set default size to the size parameter
template <typename X, typename Y>
Dictionary<X,Y>::Dictionary(int size) {

}

//copy constructor
template <typename X, typename Y>
Dictionary<X,Y>::Dictionary(const Dictionary &) {}

template <typename X, typename Y>
void Dictionary<X,Y>::add(X key, Y value) {

}

template <typename X, typename Y>
KeyValue<X, Y> Dictionary<X,Y>::getByKey(X key) {

}

template <typename X, typename Y>
KeyValue<X, Y> Dictionary<X,Y>::getByIndex(int index) {

}

template <typename X, typename Y>
void Dictionary<X,Y>::removeByKey(X key) {

}

template <typename X, typename Y>
void Dictionary<X,Y>::removeByIndex(int index) {

}


#endif //GENERICDICTIONARY_DICTIONARY_H
