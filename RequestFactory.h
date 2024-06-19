#pragma once
#include "BaseFactory.h"
#include "RequestCodec.h"

class RequestFactory: BaseFactory {
public:
	RequestFactory();
	RequestFactory(string enc);
	RequestFactory(RequestInfo *info);
	~RequestFactory();
	Codec* createCodec();
private:
	// 保存要解码的字符串
	string m_encStr;
	// 需要序列化的数据
	RequestInfo *m_info;
	// 判断是编码对象还是解码对象
	int m_flag;
};