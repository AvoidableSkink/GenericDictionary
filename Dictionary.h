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


#endif //GENERICDICTIONARY_DICTIONARY_H
