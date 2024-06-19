#include "RequestCodec.h"

RequestCodec::RequestCodec()
{
}

RequestCodec::~RequestCodec()
{
}

RequestCodec::RequestCodec(string encstr)
{
	RequestCodec::initMessage(encstr);
}

RequestCodec::RequestCodec(RequestInfo * info)
{
	RequestCodec::initMessage(info);
}

void RequestCodec::initMessage(string encstr)
{
	m_encStr = encstr;
}

void RequestCodec::initMessage(RequestInfo * info)
{
	m_msg.set_cmdtype(info->cmdType);
	m_msg.set_clientid(info->clientId);
	m_msg.set_data(info->data);
	m_msg.set_serverid(info->serverId);
	m_msg.set_sign(info->sign);
}

string RequestCodec::encodeMsg()
{
	string output;
	m_msg.SerializeToString(&output);
	return output;
}

void * RequestCodec::decodeMsg()
{
	m_msg.ParseFromString(m_encStr);
	return &m_msg;
}
