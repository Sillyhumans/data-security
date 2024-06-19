#pragma once
#include "RespondMsg.pb.h"
#include "Codec.h"

struct RespondInfo {
	bool rv; // 返回值
	int seckeyid; 		// 对称密钥编号 keysn
	string clientId; 	// 客户端编号
	string serverId; 	// 服务器编号
	string data; 	// 服务器端随机数
};

class RespondCodec : public Codec {
public:
	RespondCodec();
	~RespondCodec();
	RespondCodec(string encstr);
	RespondCodec(RespondInfo *info);
	// init给空构造使用的
	void initMessage(string encstr);
	void initMessage(RespondInfo *info);
	// 重写父类函数 返回序列化字符串
	string encodeMsg();
	// 解码函数 返还的应该是一个结构体或者类对象
	void* decodeMsg();

private:
	string m_encStr;
	RespondMsg m_msg;
};