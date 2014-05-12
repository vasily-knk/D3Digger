#pragma once

typedef boost::signals2::connection Connection;

#define DECLARE_SIGNAL(name,arglist)                                                     \
	typedef boost::signals2::signal<void arglist>::slot_type name##Slot;                \
	virtual Connection subscribe##name(name##Slot const& slot) = 0;

#define DEFINE_SIGNAL(name,arglist)                                                     \
	typedef boost::signals2::signal<void arglist>::slot_type name##Slot;               \
	virtual boost::signals2::connection subscribe##name(name##Slot const& slot)        \
{                                                                                      \
	return emit##name .connect(slot);                                              \
}                                                                                      \
	boost::signals2::signal<void arglist> emit##name ;

