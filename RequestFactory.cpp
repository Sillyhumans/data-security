#include "RequestFactory.h"
#include "RequestCodec.h"

RequestFactory::RequestFactory()
{
}

RequestFactory::RequestFactory(string enc)
{
	// Ω‚¬Î∂‘œÛ
	m_flag = 1;
	m_encStr = enc;
}

RequestFactory::RequestFactory(RequestInfo * info)
{
	m_flag = 2;
	m_info = info;
}

RequestFactory::~RequestFactory()
{
}

Codec * RequestFactory::createCodec()
{
	if (m_flag == 1) return new RequestCodec(m_encStr);
	return new RequestCodec(m_info);
}
