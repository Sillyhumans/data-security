#include "RespondFactory.h"
#include "RespondCodec.h"

RespondFactory::RespondFactory()
{
}

RespondFactory::RespondFactory(string enc)
{
	// Ω‚¬Î∂‘œÛ
	m_flag = 1;
	m_encStr = enc;
}

RespondFactory::RespondFactory(RespondInfo * info)
{
	m_flag = 2;
	m_info = info;
}

RespondFactory::~RespondFactory()
{
}

Codec * RespondFactory::createObject()
{
	if (m_flag == 1) return new RespondCodec(m_encStr);
	return new RespondCodec(m_info);
}
