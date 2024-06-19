#pragma once
#include "BaseFactory.h"
#include "RespondCodec.h"

class RespondFactory : public BaseFactory {
public:
	RespondFactory();
	RespondFactory(string enc);
	RespondFactory(RespondInfo *info);
	~RespondFactory();
	Codec* createObject();
private:
	// 保存要解码的字符串
	string m_encStr;
	// 需要序列化的数据
	RespondInfo *m_info;
	// 判断是编码对象还是解码对象
	int m_flag;
};
