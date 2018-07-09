#pragma once


#include <queue>


#include "MessageFrom.h"
class MessagePost
{
private:
	MessagePost();
	static MessagePost * _instance;
public:
	~MessagePost();


	static MessagePost * GetInstance();


private:
	std::queue<MessageFrom> _postBox;


public:
	void SendMessageW(const MessageFrom & messageFrom);
	void ProcessMessageQueue();

	void Clear();
};

