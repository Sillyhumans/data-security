#include "BaseFactory.h"

BaseFactory::BaseFactory()
{
}

BaseFactory::~BaseFactory()
{
}

Codec * BaseFactory::createObject()
{
	return nullptr;
}
