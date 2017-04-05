//
// Created by klind on 4/4/2017.
//

#ifndef GENERICDICTIONARY_KEYVALUE_H
#define GENERICDICTIONARY_KEYVALUE_H

template <typename X, typename Y>
class KeyValue {
private:
    X key;
    Y value;

public:
    KeyValue(X k, Y v);
    KeyValue(const KeyValue&);

    X getKey() const { return key; }
    Y getValue() const { return value; }
};


#endif //GENERICDICTIONARY_KEYVALUE_H
