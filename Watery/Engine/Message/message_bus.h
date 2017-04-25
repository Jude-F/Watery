//
// Created by Mike Smith on 2017/4/17.
//

#ifndef WATERY_MESSAGE_BUS_H
#define WATERY_MESSAGE_BUS_H

#include <queue>
#include "message.h"

namespace watery
{
	// Singleton message bus.
	class MessageBus
	{
	private:
		std::queue<Message *>  _message_queue;
		
		// The singleton instance.
		static MessageBus *_instance;
		
		// Forbidden functions.
		MessageBus(void) {}
		MessageBus(const MessageBus &) = delete;
		virtual ~MessageBus(void) {}
		MessageBus &operator=(const MessageBus &) = delete;
		
	public:
		virtual bool empty(void) const { return _message_queue.empty(); }
		virtual Message *retrieve(void);
		virtual void dispatch(Message *message);
		
		// Get the singleton instance.
		static MessageBus &instance(void) { return *_instance; }
	};
}

#endif  // WATERY_MESSAGE_BUS_H
