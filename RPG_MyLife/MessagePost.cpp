#include "MessagePost.h"
#include "MessageFrom.h"

#include "Component.h"
MessagePost *  MessagePost::_instance = nullptr;

MessagePost *  MessagePost::GetInstance()
{
	if (_instance == nullptr)
	{
		_instance = new MessagePost();
	}
	return _instance;
}
void MessagePost::Clear()
{
	while (false==_postBox.empty())
	{
		_postBox.pop();
	}
}
MessagePost::MessagePost()
{
}
MessagePost::~MessagePost()
{
}
void MessagePost::SendMessage(MessageFrom & messageFrom)
{
	_postBox.push(messageFrom);
}
void MessagePost::ProcessMessageQueue()
{
	while (false == _postBox.empty())
	{
		MessageFrom messageFrom = _postBox.front();
		_postBox.pop();
		messageFrom.reciver->ReciverMessage(messageFrom);
	}
}