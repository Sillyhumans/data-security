#pragma once
#include <iostream>
#include "Codec.h"
using namespace std;

class BaseFactory {
public:
	BaseFactory();
	~BaseFactory();
	virtual Codec* createObject();
};