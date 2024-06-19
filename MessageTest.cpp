#include "RequestFactory.h"
#include "RespondFactory.h"

using namespace std;

string endcodeMsg(Codec* codec) {
	return codec->encodeMsg();
}

void* decodeMsg(Codec* codec) {
	return codec->decodeMsg();
}

int main() {
	RequestInfo reqInfo;
	reqInfo.cmdType = 9;
	reqInfo.clientId = "your father";
	reqInfo.serverId = "feiji";
	reqInfo.data = "µ¥É±facker";
	reqInfo.sign = "1";
	/*	RequestCodec req(&reqInfo);
	//±àÂë
	*/
	RequestFactory *reqFactory = new RequestFactory(&reqInfo);
	RequestCodec *req = (RequestCodec*)reqFactory->createCodec();
	string reqmsg = endcodeMsg(req);
	// ½âÂë
	RequestCodec req1(reqmsg);
	RequestMsg* reqMsg = (RequestMsg*)decodeMsg(&req1);
	cout << reqMsg->data() << endl;
}