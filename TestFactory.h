#pragma once
#include "BaseFactory.h"
class TestFactory : public BaseFactory {
public:
	TestFactory();
	~TestFactory();
	Codec* createObject();
};