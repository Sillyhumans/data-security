#include "RespondCodec.h"

RespondCodec::RespondCodec()
{
}

RespondCodec::~RespondCodec()
{
}

RespondCodec::RespondCodec(string encstr)
{
	RespondCodec::initMessage(encstr);
}

RespondCodec::RespondCodec(RespondInfo * info)
{
	RespondCodec::initMessage(info);
}

void RespondCodec::initMessage(string encstr)
{
	m_encStr = encstr;
}

void RespondCodec::initMessage(RespondInfo * info)
{
	m_msg.set_clientid(info->clientId);
	m_msg.set_seckyid(info->seckeyid);
	m_msg.set_serverid(info->serverId);
	m_msg.set_rv(info->rv);
	m_msg.set_data(info->data);
}

string RespondCodec::encodeMsg()
{
	string output;
	m_msg.SerializeToString(&output);
	return output;
}

void * RespondCodec::decodeMsg()
{
	m_msg.ParseFromString(m_encStr);
	return &m_msg;
}
