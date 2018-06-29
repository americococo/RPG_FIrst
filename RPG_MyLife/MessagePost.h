#pragma once


#include <queue>


#include "MessageFrom.h"

class MessagePost
{
private:
	MessagePost();
public:
	~MessagePost();


	static MessagePost * _instance;
	static MessagePost * GetInstance();


private:
	std::queue<MessageFrom> _postBox;


public:
	void SendMessage(MessageFrom & messageFrom);
	void ProcessMessageQueue();

	void Clear();
};

