#pragma once
#include "RequestMsg.pb.h"
#include "Codec.h"

struct RequestInfo {
	//1 密钥协商 //2 密钥校验; // 3 密钥注销
	int cmdType; // 报文类型
	string clientId; // 客户端编号
	string serverId; // 服务器端编号
	string sign;
	string data;
};

class RequestCodec : public Codec {
public:
	RequestCodec();
	~RequestCodec();
	RequestCodec(string encstr);
	RequestCodec(RequestInfo *info);
	void initMessage(string encstr);
	void initMessage(RequestInfo *info);
	string encodeMsg();
	void* decodeMsg();

private:
	// 保存要解码的字符串
	string m_encStr;
	// 需要序列化的数据
	RequestMsg m_msg;
};