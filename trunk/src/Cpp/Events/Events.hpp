#ifndef __CPP_EVENTS__EVENTS_HPP
#define __CPP_EVENTS__EVENTS_HPP

#include "AbstractEvent.hpp"
#include "ConnectionEx.hpp"
#include "TypeTraits.hpp"

class Event0;
template<class Param0> class Event1;
template<class Param0, class Param1> class Event2;
template<class Param0, class Param1, class Param2> class Event3;
template<class Param0, class Param1, class Param2, class Param3> class Event4;
template<class Param0, class Param1, class Param2, class Param3, class Param4> class Event5;
template<class Param0, class Param1, class Param2, class Param3, class Param4, class Param5> class Event6;
template<class Param0, class Param1, class Param2, class Param3, class Param4, class Param5, class Param6> class Event7;

class EventRef0;
template<class Param0> class EventRef1;
template<class Param0, class Param1> class EventRef2;
template<class Param0, class Param1, class Param2> class EventRef3;
template<class Param0, class Param1, class Param2, class Param3> class EventRef4;
template<class Param0, class Param1, class Param2, class Param3, class Param4> class EventRef5;
template<class Param0, class Param1, class Param2, class Param3, class Param4, class Param5> class EventRef6;
template<class Param0, class Param1, class Param2, class Param3, class Param4, class Param5, class Param6> class EventRef7;

class Event0 : public AbstractEvent
{
public:
	typedef Connection0 ConnectionType;

	Event0() {}
	~Event0() {}

	inline EventRef0 ref();

	void addConnection(ConnectionList * tracker, ConnectionType * conn)
	{
		AbstractEvent::addConnection(tracker, conn);
	}
	
	void fire() const
	{
		FireLock lock(this);
		ConnectionsVector const & conns = lock.connections();
		for(ConnectionsVector::const_iterator it = conns.begin(); it != conns.end(); ++it)
		{
			static_cast<ConnectionType const *>(*it)->invoke();
		}
	}
};

class EventRef0 : public AbstractEventRef
{
public:
	typedef Event0 EventType;
	typedef EventType::ConnectionType ConnectionType;

	explicit EventRef0(EventType * ev) : AbstractEventRef(ev) {}

	template<class T, class Y> void connect(ConnectionList * tracker, T * obj, void (Y::*pmf)())
	{
		ConnectionType * conn = new ConnectionType(
			fastdelegate::MakeDelegate(obj, pmf)
		);
		addConnection(tracker, conn);
	}

	template<class T, class Y> void connect(ConnectionList * tracker, T const * obj, void (Y::*pmf)() const)
	{
		ConnectionType * conn = new ConnectionType(
			fastdelegate::MakeDelegate(obj, pmf)
		);
		addConnection(tracker, conn);
	}

	template<class T, class Y> void connect(ConnectionList * tracker, T * obj, Y pmf)
	{
		detail::ArgList0 stored;
		connectEx(tracker, fastdelegate::MakeDelegate(obj, pmf), stored);
	}

	template<class T, class Y, class T1> void connect(ConnectionList * tracker, T * obj, Y pmf, T1 x1)
	{
		typedef typename StorageType<T1>::Type S1;
		detail::ArgList1<S1> stored(x1);
		connectEx(tracker, fastdelegate::MakeDelegate(obj, pmf), stored);
	}

	template<class T, class Y, class T1, class T2> void connect(ConnectionList * tracker, T * obj, Y pmf, T1 x1, T2 x2)
	{
		typedef typename StorageType<T1>::Type S1;
		typedef typename StorageType<T2>::Type S2;
		detail::ArgList2<S1, S2> stored(x1, x2);
		connectEx(tracker, fastdelegate::MakeDelegate(obj, pmf), stored);
	}

	template<class T, class Y, class T1, class T2, class T3> void connect(ConnectionList * tracker, T * obj, Y pmf, T1 x1, T2 x2, T3 x3)
	{
		typedef typename StorageType<T1>::Type S1;
		typedef typename StorageType<T2>::Type S2;
		typedef typename StorageType<T3>::Type S3;
		detail::ArgList3<S1, S2, S3> stored(x1, x2, x3);
		connectEx(tracker, fastdelegate::MakeDelegate(obj, pmf), stored);
	}

	template<class T, class Y, class T1, class T2, class T3, class T4> void connect(ConnectionList * tracker, T * obj, Y pmf, T1 x1, T2 x2, T3 x3, T4 x4)
	{
		typedef typename StorageType<T1>::Type S1;
		typedef typename StorageType<T2>::Type S2;
		typedef typename StorageType<T3>::Type S3;
		typedef typename StorageType<T4>::Type S4;
		detail::ArgList4<S1, S2, S3, S4> stored(x1, x2, x3, x4);
		connectEx(tracker, fastdelegate::MakeDelegate(obj, pmf), stored);
	}

	template<class T, class Y, class T1, class T2, class T3, class T4, class T5> void connect(ConnectionList * tracker, T * obj, Y pmf, T1 x1, T2 x2, T3 x3, T4 x4, T5 x5)
	{
		typedef typename StorageType<T1>::Type S1;
		typedef typename StorageType<T2>::Type S2;
		typedef typename StorageType<T3>::Type S3;
		typedef typename StorageType<T4>::Type S4;
		typedef typename StorageType<T5>::Type S5;
		detail::ArgList5<S1, S2, S3, S4, S5> stored(x1, x2, x3, x4, x5);
		connectEx(tracker, fastdelegate::MakeDelegate(obj, pmf), stored);
	}

	template<class T, class Y, class T1, class T2, class T3, class T4, class T5, class T6> void connect(ConnectionList * tracker, T * obj, Y pmf, T1 x1, T2 x2, T3 x3, T4 x4, T5 x5, T6 x6)
	{
		typedef typename StorageType<T1>::Type S1;
		typedef typename StorageType<T2>::Type S2;
		typedef typename StorageType<T3>::Type S3;
		typedef typename StorageType<T4>::Type S4;
		typedef typename StorageType<T5>::Type S5;
		typedef typename StorageType<T6>::Type S6;
		detail::ArgList6<S1, S2, S3, S4, S5, S6> stored(x1, x2, x3, x4, x5, x6);
		connectEx(tracker, fastdelegate::MakeDelegate(obj, pmf), stored);
	}

	template<class T, class Y, class T1, class T2, class T3, class T4, class T5, class T6, class T7> void connect(ConnectionList * tracker, T * obj, Y pmf, T1 x1, T2 x2, T3 x3, T4 x4, T5 x5, T6 x6, T7 x7)
	{
		typedef typename StorageType<T1>::Type S1;
		typedef typename StorageType<T2>::Type S2;
		typedef typename StorageType<T3>::Type S3;
		typedef typename StorageType<T4>::Type S4;
		typedef typename StorageType<T5>::Type S5;
		typedef typename StorageType<T6>::Type S6;
		typedef typename StorageType<T7>::Type S7;
		detail::ArgList7<S1, S2, S3, S4, S5, S6, S7> stored(x1, x2, x3, x4, x5, x6, x7);
		connectEx(tracker, fastdelegate::MakeDelegate(obj, pmf), stored);
	}

	void connectEvent(ConnectionList * tracker, Event0 * ev)
	{
		connect(tracker, ev, &Event0::fire);
	}
	template<class T0> void connectEvent(ConnectionList * tracker, Event1<T0> * ev, T0 x0)
	{
		connect(tracker, ev, &Event1<T0>::fire, x0);
	}
	template<class T0, class T1> void connectEvent(ConnectionList * tracker, Event2<T0, T1> * ev, T0 x0, T1 x1)
	{
		connect(tracker, ev, &Event2<T0, T1>::fire, x0, x1);
	}
	template<class T0, class T1, class T2> void connectEvent(ConnectionList * tracker, Event3<T0, T1, T2> * ev, T0 x0, T1 x1, T2 x2)
	{
		connect(tracker, ev, &Event3<T0, T1, T2>::fire, x0, x1, x2);
	}
	template<class T0, class T1, class T2, class T3> void connectEvent(ConnectionList * tracker, Event4<T0, T1, T2, T3> * ev, T0 x0, T1 x1, T2 x2, T3 x3)
	{
		connect(tracker, ev, &Event4<T0, T1, T2, T3>::fire, x0, x1, x2, x3);
	}
	template<class T0, class T1, class T2, class T3, class T4> void connectEvent(ConnectionList * tracker, Event5<T0, T1, T2, T3, T4> * ev, T0 x0, T1 x1, T2 x2, T3 x3, T4 x4)
	{
		connect(tracker, ev, &Event5<T0, T1, T2, T3, T4>::fire, x0, x1, x2, x3, x4);
	}
	template<class T0, class T1, class T2, class T3, class T4, class T5> void connectEvent(ConnectionList * tracker, Event6<T0, T1, T2, T3, T4, T5> * ev, T0 x0, T1 x1, T2 x2, T3 x3, T4 x4, T5 x5)
	{
		connect(tracker, ev, &Event6<T0, T1, T2, T3, T4, T5>::fire, x0, x1, x2, x3, x4, x5);
	}
	template<class T0, class T1, class T2, class T3, class T4, class T5, class T6> void connectEvent(ConnectionList * tracker, Event7<T0, T1, T2, T3, T4, T5, T6> * ev, T0 x0, T1 x1, T2 x2, T3 x3, T4 x4, T5 x5, T6 x6)
	{
		connect(tracker, ev, &Event7<T0, T1, T2, T3, T4, T5, T6>::fire, x0, x1, x2, x3, x4, x5, x6);
	}
private:
	void addConnection(ConnectionList * tracker, ConnectionType * conn)
	{
		static_cast<EventType*>(senderEvent())->addConnection(tracker, conn);
	}

	template<class DelegateClass, class StoredListClass> void connectEx(ConnectionList * tracker, DelegateClass const & deleg, StoredListClass const & stored)
	{
		ConnectionType * conn = new ConnectionEx0<DelegateClass, StoredListClass>(
			deleg, stored
		);
		addConnection(tracker, conn);
	}
};


inline EventRef0 Event0::ref()
{
	return EventRef0(this);
}

template<class Param0> class Event1 : public AbstractEvent
{
public:
	typedef Connection1<Param0> ConnectionType;

	Event1() {}
	~Event1() {}

	inline EventRef1<Param0> ref();

	void addConnection(ConnectionList * tracker, ConnectionType * conn)
	{
		AbstractEvent::addConnection(tracker, conn);
	}
	
	void fire(Param0 p0) const
	{
		FireLock lock(this);
		ConnectionsVector const & conns = lock.connections();
		for(ConnectionsVector::const_iterator it = conns.begin(); it != conns.end(); ++it)
		{
			static_cast<ConnectionType const *>(*it)->invoke(p0);
		}
	}
};

template<class Param0> class EventRef1 : public AbstractEventRef
{
public:
	typedef Event1<Param0> EventType;
	typedef typename EventType::ConnectionType ConnectionType;

	explicit EventRef1(EventType * ev) : AbstractEventRef(ev) {}

	template<class T, class Y> void connect(ConnectionList * tracker, T * obj, void (Y::*pmf)(Param0 p0))
	{
		ConnectionType * conn = new ConnectionType(
			fastdelegate::MakeDelegate(obj, pmf)
		);
		addConnection(tracker, conn);
	}

	template<class T, class Y> void connect(ConnectionList * tracker, T const * obj, void (Y::*pmf)(Param0 p0) const)
	{
		ConnectionType * conn = new ConnectionType(
			fastdelegate::MakeDelegate(obj, pmf)
		);
		addConnection(tracker, conn);
	}

	template<class T, class Y> void connect(ConnectionList * tracker, T * obj, Y pmf)
	{
		detail::ArgList0 stored;
		connectEx(tracker, fastdelegate::MakeDelegate(obj, pmf), stored);
	}

	template<class T, class Y, class T1> void connect(ConnectionList * tracker, T * obj, Y pmf, T1 x1)
	{
		typedef typename StorageType<T1>::Type S1;
		detail::ArgList1<S1> stored(x1);
		connectEx(tracker, fastdelegate::MakeDelegate(obj, pmf), stored);
	}

	template<class T, class Y, class T1, class T2> void connect(ConnectionList * tracker, T * obj, Y pmf, T1 x1, T2 x2)
	{
		typedef typename StorageType<T1>::Type S1;
		typedef typename StorageType<T2>::Type S2;
		detail::ArgList2<S1, S2> stored(x1, x2);
		connectEx(tracker, fastdelegate::MakeDelegate(obj, pmf), stored);
	}

	template<class T, class Y, class T1, class T2, class T3> void connect(ConnectionList * tracker, T * obj, Y pmf, T1 x1, T2 x2, T3 x3)
	{
		typedef typename StorageType<T1>::Type S1;
		typedef typename StorageType<T2>::Type S2;
		typedef typename StorageType<T3>::Type S3;
		detail::ArgList3<S1, S2, S3> stored(x1, x2, x3);
		connectEx(tracker, fastdelegate::MakeDelegate(obj, pmf), stored);
	}

	template<class T, class Y, class T1, class T2, class T3, class T4> void connect(ConnectionList * tracker, T * obj, Y pmf, T1 x1, T2 x2, T3 x3, T4 x4)
	{
		typedef typename StorageType<T1>::Type S1;
		typedef typename StorageType<T2>::Type S2;
		typedef typename StorageType<T3>::Type S3;
		typedef typename StorageType<T4>::Type S4;
		detail::ArgList4<S1, S2, S3, S4> stored(x1, x2, x3, x4);
		connectEx(tracker, fastdelegate::MakeDelegate(obj, pmf), stored);
	}

	template<class T, class Y, class T1, class T2, class T3, class T4, class T5> void connect(ConnectionList * tracker, T * obj, Y pmf, T1 x1, T2 x2, T3 x3, T4 x4, T5 x5)
	{
		typedef typename StorageType<T1>::Type S1;
		typedef typename StorageType<T2>::Type S2;
		typedef typename StorageType<T3>::Type S3;
		typedef typename StorageType<T4>::Type S4;
		typedef typename StorageType<T5>::Type S5;
		detail::ArgList5<S1, S2, S3, S4, S5> stored(x1, x2, x3, x4, x5);
		connectEx(tracker, fastdelegate::MakeDelegate(obj, pmf), stored);
	}

	template<class T, class Y, class T1, class T2, class T3, class T4, class T5, class T6> void connect(ConnectionList * tracker, T * obj, Y pmf, T1 x1, T2 x2, T3 x3, T4 x4, T5 x5, T6 x6)
	{
		typedef typename StorageType<T1>::Type S1;
		typedef typename StorageType<T2>::Type S2;
		typedef typename StorageType<T3>::Type S3;
		typedef typename StorageType<T4>::Type S4;
		typedef typename StorageType<T5>::Type S5;
		typedef typename StorageType<T6>::Type S6;
		detail::ArgList6<S1, S2, S3, S4, S5, S6> stored(x1, x2, x3, x4, x5, x6);
		connectEx(tracker, fastdelegate::MakeDelegate(obj, pmf), stored);
	}

	template<class T, class Y, class T1, class T2, class T3, class T4, class T5, class T6, class T7> void connect(ConnectionList * tracker, T * obj, Y pmf, T1 x1, T2 x2, T3 x3, T4 x4, T5 x5, T6 x6, T7 x7)
	{
		typedef typename StorageType<T1>::Type S1;
		typedef typename StorageType<T2>::Type S2;
		typedef typename StorageType<T3>::Type S3;
		typedef typename StorageType<T4>::Type S4;
		typedef typename StorageType<T5>::Type S5;
		typedef typename StorageType<T6>::Type S6;
		typedef typename StorageType<T7>::Type S7;
		detail::ArgList7<S1, S2, S3, S4, S5, S6, S7> stored(x1, x2, x3, x4, x5, x6, x7);
		connectEx(tracker, fastdelegate::MakeDelegate(obj, pmf), stored);
	}

	template<class T0> void connectEvent(ConnectionList * tracker, Event1<T0> * ev)
	{
		connect(tracker, ev, &Event1<T0>::fire);
	}
	template<class T0, class T1> void connectEvent(ConnectionList * tracker, Event2<T0, T1> * ev, T0 x0)
	{
		connect(tracker, ev, &Event2<T0, T1>::fire, x0);
	}
	template<class T0, class T1, class T2> void connectEvent(ConnectionList * tracker, Event3<T0, T1, T2> * ev, T0 x0, T1 x1)
	{
		connect(tracker, ev, &Event3<T0, T1, T2>::fire, x0, x1);
	}
	template<class T0, class T1, class T2, class T3> void connectEvent(ConnectionList * tracker, Event4<T0, T1, T2, T3> * ev, T0 x0, T1 x1, T2 x2)
	{
		connect(tracker, ev, &Event4<T0, T1, T2, T3>::fire, x0, x1, x2);
	}
	template<class T0, class T1, class T2, class T3, class T4> void connectEvent(ConnectionList * tracker, Event5<T0, T1, T2, T3, T4> * ev, T0 x0, T1 x1, T2 x2, T3 x3)
	{
		connect(tracker, ev, &Event5<T0, T1, T2, T3, T4>::fire, x0, x1, x2, x3);
	}
	template<class T0, class T1, class T2, class T3, class T4, class T5> void connectEvent(ConnectionList * tracker, Event6<T0, T1, T2, T3, T4, T5> * ev, T0 x0, T1 x1, T2 x2, T3 x3, T4 x4)
	{
		connect(tracker, ev, &Event6<T0, T1, T2, T3, T4, T5>::fire, x0, x1, x2, x3, x4);
	}
	template<class T0, class T1, class T2, class T3, class T4, class T5, class T6> void connectEvent(ConnectionList * tracker, Event7<T0, T1, T2, T3, T4, T5, T6> * ev, T0 x0, T1 x1, T2 x2, T3 x3, T4 x4, T5 x5)
	{
		connect(tracker, ev, &Event7<T0, T1, T2, T3, T4, T5, T6>::fire, x0, x1, x2, x3, x4, x5);
	}
private:
	void addConnection(ConnectionList * tracker, ConnectionType * conn)
	{
		static_cast<EventType*>(senderEvent())->addConnection(tracker, conn);
	}

	template<class DelegateClass, class StoredListClass> void connectEx(ConnectionList * tracker, DelegateClass const & deleg, StoredListClass const & stored)
	{
		ConnectionType * conn = new ConnectionEx1<Param0, DelegateClass, StoredListClass>(
			deleg, stored
		);
		addConnection(tracker, conn);
	}
};

template<class Param0> 
inline EventRef1<Param0> Event1<Param0>::ref()
{
	return EventRef1<Param0>(this);
}

template<class Param0, class Param1> class Event2 : public AbstractEvent
{
public:
	typedef Connection2<Param0, Param1> ConnectionType;

	Event2() {}
	~Event2() {}

	inline EventRef2<Param0, Param1> ref();

	void addConnection(ConnectionList * tracker, ConnectionType * conn)
	{
		AbstractEvent::addConnection(tracker, conn);
	}
	
	void fire(Param0 p0, Param1 p1) const
	{
		FireLock lock(this);
		ConnectionsVector const & conns = lock.connections();
		for(ConnectionsVector::const_iterator it = conns.begin(); it != conns.end(); ++it)
		{
			static_cast<ConnectionType const *>(*it)->invoke(p0, p1);
		}
	}
};

template<class Param0, class Param1> class EventRef2 : public AbstractEventRef
{
public:
	typedef Event2<Param0, Param1> EventType;
	typedef typename EventType::ConnectionType ConnectionType;

	explicit EventRef2(EventType * ev) : AbstractEventRef(ev) {}

	template<class T, class Y> void connect(ConnectionList * tracker, T * obj, void (Y::*pmf)(Param0 p0, Param1 p1))
	{
		ConnectionType * conn = new ConnectionType(
			fastdelegate::MakeDelegate(obj, pmf)
		);
		addConnection(tracker, conn);
	}

	template<class T, class Y> void connect(ConnectionList * tracker, T const * obj, void (Y::*pmf)(Param0 p0, Param1 p1) const)
	{
		ConnectionType * conn = new ConnectionType(
			fastdelegate::MakeDelegate(obj, pmf)
		);
		addConnection(tracker, conn);
	}

	template<class T, class Y> void connect(ConnectionList * tracker, T * obj, Y pmf)
	{
		detail::ArgList0 stored;
		connectEx(tracker, fastdelegate::MakeDelegate(obj, pmf), stored);
	}

	template<class T, class Y, class T1> void connect(ConnectionList * tracker, T * obj, Y pmf, T1 x1)
	{
		typedef typename StorageType<T1>::Type S1;
		detail::ArgList1<S1> stored(x1);
		connectEx(tracker, fastdelegate::MakeDelegate(obj, pmf), stored);
	}

	template<class T, class Y, class T1, class T2> void connect(ConnectionList * tracker, T * obj, Y pmf, T1 x1, T2 x2)
	{
		typedef typename StorageType<T1>::Type S1;
		typedef typename StorageType<T2>::Type S2;
		detail::ArgList2<S1, S2> stored(x1, x2);
		connectEx(tracker, fastdelegate::MakeDelegate(obj, pmf), stored);
	}

	template<class T, class Y, class T1, class T2, class T3> void connect(ConnectionList * tracker, T * obj, Y pmf, T1 x1, T2 x2, T3 x3)
	{
		typedef typename StorageType<T1>::Type S1;
		typedef typename StorageType<T2>::Type S2;
		typedef typename StorageType<T3>::Type S3;
		detail::ArgList3<S1, S2, S3> stored(x1, x2, x3);
		connectEx(tracker, fastdelegate::MakeDelegate(obj, pmf), stored);
	}

	template<class T, class Y, class T1, class T2, class T3, class T4> void connect(ConnectionList * tracker, T * obj, Y pmf, T1 x1, T2 x2, T3 x3, T4 x4)
	{
		typedef typename StorageType<T1>::Type S1;
		typedef typename StorageType<T2>::Type S2;
		typedef typename StorageType<T3>::Type S3;
		typedef typename StorageType<T4>::Type S4;
		detail::ArgList4<S1, S2, S3, S4> stored(x1, x2, x3, x4);
		connectEx(tracker, fastdelegate::MakeDelegate(obj, pmf), stored);
	}

	template<class T, class Y, class T1, class T2, class T3, class T4, class T5> void connect(ConnectionList * tracker, T * obj, Y pmf, T1 x1, T2 x2, T3 x3, T4 x4, T5 x5)
	{
		typedef typename StorageType<T1>::Type S1;
		typedef typename StorageType<T2>::Type S2;
		typedef typename StorageType<T3>::Type S3;
		typedef typename StorageType<T4>::Type S4;
		typedef typename StorageType<T5>::Type S5;
		detail::ArgList5<S1, S2, S3, S4, S5> stored(x1, x2, x3, x4, x5);
		connectEx(tracker, fastdelegate::MakeDelegate(obj, pmf), stored);
	}

	template<class T, class Y, class T1, class T2, class T3, class T4, class T5, class T6> void connect(ConnectionList * tracker, T * obj, Y pmf, T1 x1, T2 x2, T3 x3, T4 x4, T5 x5, T6 x6)
	{
		typedef typename StorageType<T1>::Type S1;
		typedef typename StorageType<T2>::Type S2;
		typedef typename StorageType<T3>::Type S3;
		typedef typename StorageType<T4>::Type S4;
		typedef typename StorageType<T5>::Type S5;
		typedef typename StorageType<T6>::Type S6;
		detail::ArgList6<S1, S2, S3, S4, S5, S6> stored(x1, x2, x3, x4, x5, x6);
		connectEx(tracker, fastdelegate::MakeDelegate(obj, pmf), stored);
	}

	template<class T, class Y, class T1, class T2, class T3, class T4, class T5, class T6, class T7> void connect(ConnectionList * tracker, T * obj, Y pmf, T1 x1, T2 x2, T3 x3, T4 x4, T5 x5, T6 x6, T7 x7)
	{
		typedef typename StorageType<T1>::Type S1;
		typedef typename StorageType<T2>::Type S2;
		typedef typename StorageType<T3>::Type S3;
		typedef typename StorageType<T4>::Type S4;
		typedef typename StorageType<T5>::Type S5;
		typedef typename StorageType<T6>::Type S6;
		typedef typename StorageType<T7>::Type S7;
		detail::ArgList7<S1, S2, S3, S4, S5, S6, S7> stored(x1, x2, x3, x4, x5, x6, x7);
		connectEx(tracker, fastdelegate::MakeDelegate(obj, pmf), stored);
	}

	template<class T0, class T1> void connectEvent(ConnectionList * tracker, Event2<T0, T1> * ev)
	{
		connect(tracker, ev, &Event2<T0, T1>::fire);
	}
	template<class T0, class T1, class T2> void connectEvent(ConnectionList * tracker, Event3<T0, T1, T2> * ev, T0 x0)
	{
		connect(tracker, ev, &Event3<T0, T1, T2>::fire, x0);
	}
	template<class T0, class T1, class T2, class T3> void connectEvent(ConnectionList * tracker, Event4<T0, T1, T2, T3> * ev, T0 x0, T1 x1)
	{
		connect(tracker, ev, &Event4<T0, T1, T2, T3>::fire, x0, x1);
	}
	template<class T0, class T1, class T2, class T3, class T4> void connectEvent(ConnectionList * tracker, Event5<T0, T1, T2, T3, T4> * ev, T0 x0, T1 x1, T2 x2)
	{
		connect(tracker, ev, &Event5<T0, T1, T2, T3, T4>::fire, x0, x1, x2);
	}
	template<class T0, class T1, class T2, class T3, class T4, class T5> void connectEvent(ConnectionList * tracker, Event6<T0, T1, T2, T3, T4, T5> * ev, T0 x0, T1 x1, T2 x2, T3 x3)
	{
		connect(tracker, ev, &Event6<T0, T1, T2, T3, T4, T5>::fire, x0, x1, x2, x3);
	}
	template<class T0, class T1, class T2, class T3, class T4, class T5, class T6> void connectEvent(ConnectionList * tracker, Event7<T0, T1, T2, T3, T4, T5, T6> * ev, T0 x0, T1 x1, T2 x2, T3 x3, T4 x4)
	{
		connect(tracker, ev, &Event7<T0, T1, T2, T3, T4, T5, T6>::fire, x0, x1, x2, x3, x4);
	}
private:
	void addConnection(ConnectionList * tracker, ConnectionType * conn)
	{
		static_cast<EventType*>(senderEvent())->addConnection(tracker, conn);
	}

	template<class DelegateClass, class StoredListClass> void connectEx(ConnectionList * tracker, DelegateClass const & deleg, StoredListClass const & stored)
	{
		ConnectionType * conn = new ConnectionEx2<Param0, Param1, DelegateClass, StoredListClass>(
			deleg, stored
		);
		addConnection(tracker, conn);
	}
};

template<class Param0, class Param1> 
inline EventRef2<Param0, Param1> Event2<Param0, Param1>::ref()
{
	return EventRef2<Param0, Param1>(this);
}

template<class Param0, class Param1, class Param2> class Event3 : public AbstractEvent
{
public:
	typedef Connection3<Param0, Param1, Param2> ConnectionType;

	Event3() {}
	~Event3() {}

	inline EventRef3<Param0, Param1, Param2> ref();

	void addConnection(ConnectionList * tracker, ConnectionType * conn)
	{
		AbstractEvent::addConnection(tracker, conn);
	}
	
	void fire(Param0 p0, Param1 p1, Param2 p2) const
	{
		FireLock lock(this);
		ConnectionsVector const & conns = lock.connections();
		for(ConnectionsVector::const_iterator it = conns.begin(); it != conns.end(); ++it)
		{
			static_cast<ConnectionType const *>(*it)->invoke(p0, p1, p2);
		}
	}
};

template<class Param0, class Param1, class Param2> class EventRef3 : public AbstractEventRef
{
public:
	typedef Event3<Param0, Param1, Param2> EventType;
	typedef typename EventType::ConnectionType ConnectionType;

	explicit EventRef3(EventType * ev) : AbstractEventRef(ev) {}

	template<class T, class Y> void connect(ConnectionList * tracker, T * obj, void (Y::*pmf)(Param0 p0, Param1 p1, Param2 p2))
	{
		ConnectionType * conn = new ConnectionType(
			fastdelegate::MakeDelegate(obj, pmf)
		);
		addConnection(tracker, conn);
	}

	template<class T, class Y> void connect(ConnectionList * tracker, T const * obj, void (Y::*pmf)(Param0 p0, Param1 p1, Param2 p2) const)
	{
		ConnectionType * conn = new ConnectionType(
			fastdelegate::MakeDelegate(obj, pmf)
		);
		addConnection(tracker, conn);
	}

	template<class T, class Y> void connect(ConnectionList * tracker, T * obj, Y pmf)
	{
		detail::ArgList0 stored;
		connectEx(tracker, fastdelegate::MakeDelegate(obj, pmf), stored);
	}

	template<class T, class Y, class T1> void connect(ConnectionList * tracker, T * obj, Y pmf, T1 x1)
	{
		typedef typename StorageType<T1>::Type S1;
		detail::ArgList1<S1> stored(x1);
		connectEx(tracker, fastdelegate::MakeDelegate(obj, pmf), stored);
	}

	template<class T, class Y, class T1, class T2> void connect(ConnectionList * tracker, T * obj, Y pmf, T1 x1, T2 x2)
	{
		typedef typename StorageType<T1>::Type S1;
		typedef typename StorageType<T2>::Type S2;
		detail::ArgList2<S1, S2> stored(x1, x2);
		connectEx(tracker, fastdelegate::MakeDelegate(obj, pmf), stored);
	}

	template<class T, class Y, class T1, class T2, class T3> void connect(ConnectionList * tracker, T * obj, Y pmf, T1 x1, T2 x2, T3 x3)
	{
		typedef typename StorageType<T1>::Type S1;
		typedef typename StorageType<T2>::Type S2;
		typedef typename StorageType<T3>::Type S3;
		detail::ArgList3<S1, S2, S3> stored(x1, x2, x3);
		connectEx(tracker, fastdelegate::MakeDelegate(obj, pmf), stored);
	}

	template<class T, class Y, class T1, class T2, class T3, class T4> void connect(ConnectionList * tracker, T * obj, Y pmf, T1 x1, T2 x2, T3 x3, T4 x4)
	{
		typedef typename StorageType<T1>::Type S1;
		typedef typename StorageType<T2>::Type S2;
		typedef typename StorageType<T3>::Type S3;
		typedef typename StorageType<T4>::Type S4;
		detail::ArgList4<S1, S2, S3, S4> stored(x1, x2, x3, x4);
		connectEx(tracker, fastdelegate::MakeDelegate(obj, pmf), stored);
	}

	template<class T, class Y, class T1, class T2, class T3, class T4, class T5> void connect(ConnectionList * tracker, T * obj, Y pmf, T1 x1, T2 x2, T3 x3, T4 x4, T5 x5)
	{
		typedef typename StorageType<T1>::Type S1;
		typedef typename StorageType<T2>::Type S2;
		typedef typename StorageType<T3>::Type S3;
		typedef typename StorageType<T4>::Type S4;
		typedef typename StorageType<T5>::Type S5;
		detail::ArgList5<S1, S2, S3, S4, S5> stored(x1, x2, x3, x4, x5);
		connectEx(tracker, fastdelegate::MakeDelegate(obj, pmf), stored);
	}

	template<class T, class Y, class T1, class T2, class T3, class T4, class T5, class T6> void connect(ConnectionList * tracker, T * obj, Y pmf, T1 x1, T2 x2, T3 x3, T4 x4, T5 x5, T6 x6)
	{
		typedef typename StorageType<T1>::Type S1;
		typedef typename StorageType<T2>::Type S2;
		typedef typename StorageType<T3>::Type S3;
		typedef typename StorageType<T4>::Type S4;
		typedef typename StorageType<T5>::Type S5;
		typedef typename StorageType<T6>::Type S6;
		detail::ArgList6<S1, S2, S3, S4, S5, S6> stored(x1, x2, x3, x4, x5, x6);
		connectEx(tracker, fastdelegate::MakeDelegate(obj, pmf), stored);
	}

	template<class T, class Y, class T1, class T2, class T3, class T4, class T5, class T6, class T7> void connect(ConnectionList * tracker, T * obj, Y pmf, T1 x1, T2 x2, T3 x3, T4 x4, T5 x5, T6 x6, T7 x7)
	{
		typedef typename StorageType<T1>::Type S1;
		typedef typename StorageType<T2>::Type S2;
		typedef typename StorageType<T3>::Type S3;
		typedef typename StorageType<T4>::Type S4;
		typedef typename StorageType<T5>::Type S5;
		typedef typename StorageType<T6>::Type S6;
		typedef typename StorageType<T7>::Type S7;
		detail::ArgList7<S1, S2, S3, S4, S5, S6, S7> stored(x1, x2, x3, x4, x5, x6, x7);
		connectEx(tracker, fastdelegate::MakeDelegate(obj, pmf), stored);
	}

	template<class T0, class T1, class T2> void connectEvent(ConnectionList * tracker, Event3<T0, T1, T2> * ev)
	{
		connect(tracker, ev, &Event3<T0, T1, T2>::fire);
	}
	template<class T0, class T1, class T2, class T3> void connectEvent(ConnectionList * tracker, Event4<T0, T1, T2, T3> * ev, T0 x0)
	{
		connect(tracker, ev, &Event4<T0, T1, T2, T3>::fire, x0);
	}
	template<class T0, class T1, class T2, class T3, class T4> void connectEvent(ConnectionList * tracker, Event5<T0, T1, T2, T3, T4> * ev, T0 x0, T1 x1)
	{
		connect(tracker, ev, &Event5<T0, T1, T2, T3, T4>::fire, x0, x1);
	}
	template<class T0, class T1, class T2, class T3, class T4, class T5> void connectEvent(ConnectionList * tracker, Event6<T0, T1, T2, T3, T4, T5> * ev, T0 x0, T1 x1, T2 x2)
	{
		connect(tracker, ev, &Event6<T0, T1, T2, T3, T4, T5>::fire, x0, x1, x2);
	}
	template<class T0, class T1, class T2, class T3, class T4, class T5, class T6> void connectEvent(ConnectionList * tracker, Event7<T0, T1, T2, T3, T4, T5, T6> * ev, T0 x0, T1 x1, T2 x2, T3 x3)
	{
		connect(tracker, ev, &Event7<T0, T1, T2, T3, T4, T5, T6>::fire, x0, x1, x2, x3);
	}
private:
	void addConnection(ConnectionList * tracker, ConnectionType * conn)
	{
		static_cast<EventType*>(senderEvent())->addConnection(tracker, conn);
	}

	template<class DelegateClass, class StoredListClass> void connectEx(ConnectionList * tracker, DelegateClass const & deleg, StoredListClass const & stored)
	{
		ConnectionType * conn = new ConnectionEx3<Param0, Param1, Param2, DelegateClass, StoredListClass>(
			deleg, stored
		);
		addConnection(tracker, conn);
	}
};

template<class Param0, class Param1, class Param2> 
inline EventRef3<Param0, Param1, Param2> Event3<Param0, Param1, Param2>::ref()
{
	return EventRef3<Param0, Param1, Param2>(this);
}

template<class Param0, class Param1, class Param2, class Param3> class Event4 : public AbstractEvent
{
public:
	typedef Connection4<Param0, Param1, Param2, Param3> ConnectionType;

	Event4() {}
	~Event4() {}

	inline EventRef4<Param0, Param1, Param2, Param3> ref();

	void addConnection(ConnectionList * tracker, ConnectionType * conn)
	{
		AbstractEvent::addConnection(tracker, conn);
	}
	
	void fire(Param0 p0, Param1 p1, Param2 p2, Param3 p3) const
	{
		FireLock lock(this);
		ConnectionsVector const & conns = lock.connections();
		for(ConnectionsVector::const_iterator it = conns.begin(); it != conns.end(); ++it)
		{
			static_cast<ConnectionType const *>(*it)->invoke(p0, p1, p2, p3);
		}
	}
};

template<class Param0, class Param1, class Param2, class Param3> class EventRef4 : public AbstractEventRef
{
public:
	typedef Event4<Param0, Param1, Param2, Param3> EventType;
	typedef typename EventType::ConnectionType ConnectionType;

	explicit EventRef4(EventType * ev) : AbstractEventRef(ev) {}

	template<class T, class Y> void connect(ConnectionList * tracker, T * obj, void (Y::*pmf)(Param0 p0, Param1 p1, Param2 p2, Param3 p3))
	{
		ConnectionType * conn = new ConnectionType(
			fastdelegate::MakeDelegate(obj, pmf)
		);
		addConnection(tracker, conn);
	}

	template<class T, class Y> void connect(ConnectionList * tracker, T const * obj, void (Y::*pmf)(Param0 p0, Param1 p1, Param2 p2, Param3 p3) const)
	{
		ConnectionType * conn = new ConnectionType(
			fastdelegate::MakeDelegate(obj, pmf)
		);
		addConnection(tracker, conn);
	}

	template<class T, class Y> void connect(ConnectionList * tracker, T * obj, Y pmf)
	{
		detail::ArgList0 stored;
		connectEx(tracker, fastdelegate::MakeDelegate(obj, pmf), stored);
	}

	template<class T, class Y, class T1> void connect(ConnectionList * tracker, T * obj, Y pmf, T1 x1)
	{
		typedef typename StorageType<T1>::Type S1;
		detail::ArgList1<S1> stored(x1);
		connectEx(tracker, fastdelegate::MakeDelegate(obj, pmf), stored);
	}

	template<class T, class Y, class T1, class T2> void connect(ConnectionList * tracker, T * obj, Y pmf, T1 x1, T2 x2)
	{
		typedef typename StorageType<T1>::Type S1;
		typedef typename StorageType<T2>::Type S2;
		detail::ArgList2<S1, S2> stored(x1, x2);
		connectEx(tracker, fastdelegate::MakeDelegate(obj, pmf), stored);
	}

	template<class T, class Y, class T1, class T2, class T3> void connect(ConnectionList * tracker, T * obj, Y pmf, T1 x1, T2 x2, T3 x3)
	{
		typedef typename StorageType<T1>::Type S1;
		typedef typename StorageType<T2>::Type S2;
		typedef typename StorageType<T3>::Type S3;
		detail::ArgList3<S1, S2, S3> stored(x1, x2, x3);
		connectEx(tracker, fastdelegate::MakeDelegate(obj, pmf), stored);
	}

	template<class T, class Y, class T1, class T2, class T3, class T4> void connect(ConnectionList * tracker, T * obj, Y pmf, T1 x1, T2 x2, T3 x3, T4 x4)
	{
		typedef typename StorageType<T1>::Type S1;
		typedef typename StorageType<T2>::Type S2;
		typedef typename StorageType<T3>::Type S3;
		typedef typename StorageType<T4>::Type S4;
		detail::ArgList4<S1, S2, S3, S4> stored(x1, x2, x3, x4);
		connectEx(tracker, fastdelegate::MakeDelegate(obj, pmf), stored);
	}

	template<class T, class Y, class T1, class T2, class T3, class T4, class T5> void connect(ConnectionList * tracker, T * obj, Y pmf, T1 x1, T2 x2, T3 x3, T4 x4, T5 x5)
	{
		typedef typename StorageType<T1>::Type S1;
		typedef typename StorageType<T2>::Type S2;
		typedef typename StorageType<T3>::Type S3;
		typedef typename StorageType<T4>::Type S4;
		typedef typename StorageType<T5>::Type S5;
		detail::ArgList5<S1, S2, S3, S4, S5> stored(x1, x2, x3, x4, x5);
		connectEx(tracker, fastdelegate::MakeDelegate(obj, pmf), stored);
	}

	template<class T, class Y, class T1, class T2, class T3, class T4, class T5, class T6> void connect(ConnectionList * tracker, T * obj, Y pmf, T1 x1, T2 x2, T3 x3, T4 x4, T5 x5, T6 x6)
	{
		typedef typename StorageType<T1>::Type S1;
		typedef typename StorageType<T2>::Type S2;
		typedef typename StorageType<T3>::Type S3;
		typedef typename StorageType<T4>::Type S4;
		typedef typename StorageType<T5>::Type S5;
		typedef typename StorageType<T6>::Type S6;
		detail::ArgList6<S1, S2, S3, S4, S5, S6> stored(x1, x2, x3, x4, x5, x6);
		connectEx(tracker, fastdelegate::MakeDelegate(obj, pmf), stored);
	}

	template<class T, class Y, class T1, class T2, class T3, class T4, class T5, class T6, class T7> void connect(ConnectionList * tracker, T * obj, Y pmf, T1 x1, T2 x2, T3 x3, T4 x4, T5 x5, T6 x6, T7 x7)
	{
		typedef typename StorageType<T1>::Type S1;
		typedef typename StorageType<T2>::Type S2;
		typedef typename StorageType<T3>::Type S3;
		typedef typename StorageType<T4>::Type S4;
		typedef typename StorageType<T5>::Type S5;
		typedef typename StorageType<T6>::Type S6;
		typedef typename StorageType<T7>::Type S7;
		detail::ArgList7<S1, S2, S3, S4, S5, S6, S7> stored(x1, x2, x3, x4, x5, x6, x7);
		connectEx(tracker, fastdelegate::MakeDelegate(obj, pmf), stored);
	}

	template<class T0, class T1, class T2, class T3> void connectEvent(ConnectionList * tracker, Event4<T0, T1, T2, T3> * ev)
	{
		connect(tracker, ev, &Event4<T0, T1, T2, T3>::fire);
	}
	template<class T0, class T1, class T2, class T3, class T4> void connectEvent(ConnectionList * tracker, Event5<T0, T1, T2, T3, T4> * ev, T0 x0)
	{
		connect(tracker, ev, &Event5<T0, T1, T2, T3, T4>::fire, x0);
	}
	template<class T0, class T1, class T2, class T3, class T4, class T5> void connectEvent(ConnectionList * tracker, Event6<T0, T1, T2, T3, T4, T5> * ev, T0 x0, T1 x1)
	{
		connect(tracker, ev, &Event6<T0, T1, T2, T3, T4, T5>::fire, x0, x1);
	}
	template<class T0, class T1, class T2, class T3, class T4, class T5, class T6> void connectEvent(ConnectionList * tracker, Event7<T0, T1, T2, T3, T4, T5, T6> * ev, T0 x0, T1 x1, T2 x2)
	{
		connect(tracker, ev, &Event7<T0, T1, T2, T3, T4, T5, T6>::fire, x0, x1, x2);
	}
private:
	void addConnection(ConnectionList * tracker, ConnectionType * conn)
	{
		static_cast<EventType*>(senderEvent())->addConnection(tracker, conn);
	}

	template<class DelegateClass, class StoredListClass> void connectEx(ConnectionList * tracker, DelegateClass const & deleg, StoredListClass const & stored)
	{
		ConnectionType * conn = new ConnectionEx4<Param0, Param1, Param2, Param3, DelegateClass, StoredListClass>(
			deleg, stored
		);
		addConnection(tracker, conn);
	}
};

template<class Param0, class Param1, class Param2, class Param3> 
inline EventRef4<Param0, Param1, Param2, Param3> Event4<Param0, Param1, Param2, Param3>::ref()
{
	return EventRef4<Param0, Param1, Param2, Param3>(this);
}

template<class Param0, class Param1, class Param2, class Param3, class Param4> class Event5 : public AbstractEvent
{
public:
	typedef Connection5<Param0, Param1, Param2, Param3, Param4> ConnectionType;

	Event5() {}
	~Event5() {}

	inline EventRef5<Param0, Param1, Param2, Param3, Param4> ref();

	void addConnection(ConnectionList * tracker, ConnectionType * conn)
	{
		AbstractEvent::addConnection(tracker, conn);
	}
	
	void fire(Param0 p0, Param1 p1, Param2 p2, Param3 p3, Param4 p4) const
	{
		FireLock lock(this);
		ConnectionsVector const & conns = lock.connections();
		for(ConnectionsVector::const_iterator it = conns.begin(); it != conns.end(); ++it)
		{
			static_cast<ConnectionType const *>(*it)->invoke(p0, p1, p2, p3, p4);
		}
	}
};

template<class Param0, class Param1, class Param2, class Param3, class Param4> class EventRef5 : public AbstractEventRef
{
public:
	typedef Event5<Param0, Param1, Param2, Param3, Param4> EventType;
	typedef typename EventType::ConnectionType ConnectionType;

	explicit EventRef5(EventType * ev) : AbstractEventRef(ev) {}

	template<class T, class Y> void connect(ConnectionList * tracker, T * obj, void (Y::*pmf)(Param0 p0, Param1 p1, Param2 p2, Param3 p3, Param4 p4))
	{
		ConnectionType * conn = new ConnectionType(
			fastdelegate::MakeDelegate(obj, pmf)
		);
		addConnection(tracker, conn);
	}

	template<class T, class Y> void connect(ConnectionList * tracker, T const * obj, void (Y::*pmf)(Param0 p0, Param1 p1, Param2 p2, Param3 p3, Param4 p4) const)
	{
		ConnectionType * conn = new ConnectionType(
			fastdelegate::MakeDelegate(obj, pmf)
		);
		addConnection(tracker, conn);
	}

	template<class T, class Y> void connect(ConnectionList * tracker, T * obj, Y pmf)
	{
		detail::ArgList0 stored;
		connectEx(tracker, fastdelegate::MakeDelegate(obj, pmf), stored);
	}

	template<class T, class Y, class T1> void connect(ConnectionList * tracker, T * obj, Y pmf, T1 x1)
	{
		typedef typename StorageType<T1>::Type S1;
		detail::ArgList1<S1> stored(x1);
		connectEx(tracker, fastdelegate::MakeDelegate(obj, pmf), stored);
	}

	template<class T, class Y, class T1, class T2> void connect(ConnectionList * tracker, T * obj, Y pmf, T1 x1, T2 x2)
	{
		typedef typename StorageType<T1>::Type S1;
		typedef typename StorageType<T2>::Type S2;
		detail::ArgList2<S1, S2> stored(x1, x2);
		connectEx(tracker, fastdelegate::MakeDelegate(obj, pmf), stored);
	}

	template<class T, class Y, class T1, class T2, class T3> void connect(ConnectionList * tracker, T * obj, Y pmf, T1 x1, T2 x2, T3 x3)
	{
		typedef typename StorageType<T1>::Type S1;
		typedef typename StorageType<T2>::Type S2;
		typedef typename StorageType<T3>::Type S3;
		detail::ArgList3<S1, S2, S3> stored(x1, x2, x3);
		connectEx(tracker, fastdelegate::MakeDelegate(obj, pmf), stored);
	}

	template<class T, class Y, class T1, class T2, class T3, class T4> void connect(ConnectionList * tracker, T * obj, Y pmf, T1 x1, T2 x2, T3 x3, T4 x4)
	{
		typedef typename StorageType<T1>::Type S1;
		typedef typename StorageType<T2>::Type S2;
		typedef typename StorageType<T3>::Type S3;
		typedef typename StorageType<T4>::Type S4;
		detail::ArgList4<S1, S2, S3, S4> stored(x1, x2, x3, x4);
		connectEx(tracker, fastdelegate::MakeDelegate(obj, pmf), stored);
	}

	template<class T, class Y, class T1, class T2, class T3, class T4, class T5> void connect(ConnectionList * tracker, T * obj, Y pmf, T1 x1, T2 x2, T3 x3, T4 x4, T5 x5)
	{
		typedef typename StorageType<T1>::Type S1;
		typedef typename StorageType<T2>::Type S2;
		typedef typename StorageType<T3>::Type S3;
		typedef typename StorageType<T4>::Type S4;
		typedef typename StorageType<T5>::Type S5;
		detail::ArgList5<S1, S2, S3, S4, S5> stored(x1, x2, x3, x4, x5);
		connectEx(tracker, fastdelegate::MakeDelegate(obj, pmf), stored);
	}

	template<class T, class Y, class T1, class T2, class T3, class T4, class T5, class T6> void connect(ConnectionList * tracker, T * obj, Y pmf, T1 x1, T2 x2, T3 x3, T4 x4, T5 x5, T6 x6)
	{
		typedef typename StorageType<T1>::Type S1;
		typedef typename StorageType<T2>::Type S2;
		typedef typename StorageType<T3>::Type S3;
		typedef typename StorageType<T4>::Type S4;
		typedef typename StorageType<T5>::Type S5;
		typedef typename StorageType<T6>::Type S6;
		detail::ArgList6<S1, S2, S3, S4, S5, S6> stored(x1, x2, x3, x4, x5, x6);
		connectEx(tracker, fastdelegate::MakeDelegate(obj, pmf), stored);
	}

	template<class T, class Y, class T1, class T2, class T3, class T4, class T5, class T6, class T7> void connect(ConnectionList * tracker, T * obj, Y pmf, T1 x1, T2 x2, T3 x3, T4 x4, T5 x5, T6 x6, T7 x7)
	{
		typedef typename StorageType<T1>::Type S1;
		typedef typename StorageType<T2>::Type S2;
		typedef typename StorageType<T3>::Type S3;
		typedef typename StorageType<T4>::Type S4;
		typedef typename StorageType<T5>::Type S5;
		typedef typename StorageType<T6>::Type S6;
		typedef typename StorageType<T7>::Type S7;
		detail::ArgList7<S1, S2, S3, S4, S5, S6, S7> stored(x1, x2, x3, x4, x5, x6, x7);
		connectEx(tracker, fastdelegate::MakeDelegate(obj, pmf), stored);
	}

	template<class T0, class T1, class T2, class T3, class T4> void connectEvent(ConnectionList * tracker, Event5<T0, T1, T2, T3, T4> * ev)
	{
		connect(tracker, ev, &Event5<T0, T1, T2, T3, T4>::fire);
	}
	template<class T0, class T1, class T2, class T3, class T4, class T5> void connectEvent(ConnectionList * tracker, Event6<T0, T1, T2, T3, T4, T5> * ev, T0 x0)
	{
		connect(tracker, ev, &Event6<T0, T1, T2, T3, T4, T5>::fire, x0);
	}
	template<class T0, class T1, class T2, class T3, class T4, class T5, class T6> void connectEvent(ConnectionList * tracker, Event7<T0, T1, T2, T3, T4, T5, T6> * ev, T0 x0, T1 x1)
	{
		connect(tracker, ev, &Event7<T0, T1, T2, T3, T4, T5, T6>::fire, x0, x1);
	}
private:
	void addConnection(ConnectionList * tracker, ConnectionType * conn)
	{
		static_cast<EventType*>(senderEvent())->addConnection(tracker, conn);
	}

	template<class DelegateClass, class StoredListClass> void connectEx(ConnectionList * tracker, DelegateClass const & deleg, StoredListClass const & stored)
	{
		ConnectionType * conn = new ConnectionEx5<Param0, Param1, Param2, Param3, Param4, DelegateClass, StoredListClass>(
			deleg, stored
		);
		addConnection(tracker, conn);
	}
};

template<class Param0, class Param1, class Param2, class Param3, class Param4> 
inline EventRef5<Param0, Param1, Param2, Param3, Param4> Event5<Param0, Param1, Param2, Param3, Param4>::ref()
{
	return EventRef5<Param0, Param1, Param2, Param3, Param4>(this);
}

template<class Param0, class Param1, class Param2, class Param3, class Param4, class Param5> class Event6 : public AbstractEvent
{
public:
	typedef Connection6<Param0, Param1, Param2, Param3, Param4, Param5> ConnectionType;

	Event6() {}
	~Event6() {}

	inline EventRef6<Param0, Param1, Param2, Param3, Param4, Param5> ref();

	void addConnection(ConnectionList * tracker, ConnectionType * conn)
	{
		AbstractEvent::addConnection(tracker, conn);
	}
	
	void fire(Param0 p0, Param1 p1, Param2 p2, Param3 p3, Param4 p4, Param5 p5) const
	{
		FireLock lock(this);
		ConnectionsVector const & conns = lock.connections();
		for(ConnectionsVector::const_iterator it = conns.begin(); it != conns.end(); ++it)
		{
			static_cast<ConnectionType const *>(*it)->invoke(p0, p1, p2, p3, p4, p5);
		}
	}
};

template<class Param0, class Param1, class Param2, class Param3, class Param4, class Param5> class EventRef6 : public AbstractEventRef
{
public:
	typedef Event6<Param0, Param1, Param2, Param3, Param4, Param5> EventType;
	typedef typename EventType::ConnectionType ConnectionType;

	explicit EventRef6(EventType * ev) : AbstractEventRef(ev) {}

	template<class T, class Y> void connect(ConnectionList * tracker, T * obj, void (Y::*pmf)(Param0 p0, Param1 p1, Param2 p2, Param3 p3, Param4 p4, Param5 p5))
	{
		ConnectionType * conn = new ConnectionType(
			fastdelegate::MakeDelegate(obj, pmf)
		);
		addConnection(tracker, conn);
	}

	template<class T, class Y> void connect(ConnectionList * tracker, T const * obj, void (Y::*pmf)(Param0 p0, Param1 p1, Param2 p2, Param3 p3, Param4 p4, Param5 p5) const)
	{
		ConnectionType * conn = new ConnectionType(
			fastdelegate::MakeDelegate(obj, pmf)
		);
		addConnection(tracker, conn);
	}

	template<class T, class Y> void connect(ConnectionList * tracker, T * obj, Y pmf)
	{
		detail::ArgList0 stored;
		connectEx(tracker, fastdelegate::MakeDelegate(obj, pmf), stored);
	}

	template<class T, class Y, class T1> void connect(ConnectionList * tracker, T * obj, Y pmf, T1 x1)
	{
		typedef typename StorageType<T1>::Type S1;
		detail::ArgList1<S1> stored(x1);
		connectEx(tracker, fastdelegate::MakeDelegate(obj, pmf), stored);
	}

	template<class T, class Y, class T1, class T2> void connect(ConnectionList * tracker, T * obj, Y pmf, T1 x1, T2 x2)
	{
		typedef typename StorageType<T1>::Type S1;
		typedef typename StorageType<T2>::Type S2;
		detail::ArgList2<S1, S2> stored(x1, x2);
		connectEx(tracker, fastdelegate::MakeDelegate(obj, pmf), stored);
	}

	template<class T, class Y, class T1, class T2, class T3> void connect(ConnectionList * tracker, T * obj, Y pmf, T1 x1, T2 x2, T3 x3)
	{
		typedef typename StorageType<T1>::Type S1;
		typedef typename StorageType<T2>::Type S2;
		typedef typename StorageType<T3>::Type S3;
		detail::ArgList3<S1, S2, S3> stored(x1, x2, x3);
		connectEx(tracker, fastdelegate::MakeDelegate(obj, pmf), stored);
	}

	template<class T, class Y, class T1, class T2, class T3, class T4> void connect(ConnectionList * tracker, T * obj, Y pmf, T1 x1, T2 x2, T3 x3, T4 x4)
	{
		typedef typename StorageType<T1>::Type S1;
		typedef typename StorageType<T2>::Type S2;
		typedef typename StorageType<T3>::Type S3;
		typedef typename StorageType<T4>::Type S4;
		detail::ArgList4<S1, S2, S3, S4> stored(x1, x2, x3, x4);
		connectEx(tracker, fastdelegate::MakeDelegate(obj, pmf), stored);
	}

	template<class T, class Y, class T1, class T2, class T3, class T4, class T5> void connect(ConnectionList * tracker, T * obj, Y pmf, T1 x1, T2 x2, T3 x3, T4 x4, T5 x5)
	{
		typedef typename StorageType<T1>::Type S1;
		typedef typename StorageType<T2>::Type S2;
		typedef typename StorageType<T3>::Type S3;
		typedef typename StorageType<T4>::Type S4;
		typedef typename StorageType<T5>::Type S5;
		detail::ArgList5<S1, S2, S3, S4, S5> stored(x1, x2, x3, x4, x5);
		connectEx(tracker, fastdelegate::MakeDelegate(obj, pmf), stored);
	}

	template<class T, class Y, class T1, class T2, class T3, class T4, class T5, class T6> void connect(ConnectionList * tracker, T * obj, Y pmf, T1 x1, T2 x2, T3 x3, T4 x4, T5 x5, T6 x6)
	{
		typedef typename StorageType<T1>::Type S1;
		typedef typename StorageType<T2>::Type S2;
		typedef typename StorageType<T3>::Type S3;
		typedef typename StorageType<T4>::Type S4;
		typedef typename StorageType<T5>::Type S5;
		typedef typename StorageType<T6>::Type S6;
		detail::ArgList6<S1, S2, S3, S4, S5, S6> stored(x1, x2, x3, x4, x5, x6);
		connectEx(tracker, fastdelegate::MakeDelegate(obj, pmf), stored);
	}

	template<class T, class Y, class T1, class T2, class T3, class T4, class T5, class T6, class T7> void connect(ConnectionList * tracker, T * obj, Y pmf, T1 x1, T2 x2, T3 x3, T4 x4, T5 x5, T6 x6, T7 x7)
	{
		typedef typename StorageType<T1>::Type S1;
		typedef typename StorageType<T2>::Type S2;
		typedef typename StorageType<T3>::Type S3;
		typedef typename StorageType<T4>::Type S4;
		typedef typename StorageType<T5>::Type S5;
		typedef typename StorageType<T6>::Type S6;
		typedef typename StorageType<T7>::Type S7;
		detail::ArgList7<S1, S2, S3, S4, S5, S6, S7> stored(x1, x2, x3, x4, x5, x6, x7);
		connectEx(tracker, fastdelegate::MakeDelegate(obj, pmf), stored);
	}

	template<class T0, class T1, class T2, class T3, class T4, class T5> void connectEvent(ConnectionList * tracker, Event6<T0, T1, T2, T3, T4, T5> * ev)
	{
		connect(tracker, ev, &Event6<T0, T1, T2, T3, T4, T5>::fire);
	}
	template<class T0, class T1, class T2, class T3, class T4, class T5, class T6> void connectEvent(ConnectionList * tracker, Event7<T0, T1, T2, T3, T4, T5, T6> * ev, T0 x0)
	{
		connect(tracker, ev, &Event7<T0, T1, T2, T3, T4, T5, T6>::fire, x0);
	}
private:
	void addConnection(ConnectionList * tracker, ConnectionType * conn)
	{
		static_cast<EventType*>(senderEvent())->addConnection(tracker, conn);
	}

	template<class DelegateClass, class StoredListClass> void connectEx(ConnectionList * tracker, DelegateClass const & deleg, StoredListClass const & stored)
	{
		ConnectionType * conn = new ConnectionEx6<Param0, Param1, Param2, Param3, Param4, Param5, DelegateClass, StoredListClass>(
			deleg, stored
		);
		addConnection(tracker, conn);
	}
};

template<class Param0, class Param1, class Param2, class Param3, class Param4, class Param5> 
inline EventRef6<Param0, Param1, Param2, Param3, Param4, Param5> Event6<Param0, Param1, Param2, Param3, Param4, Param5>::ref()
{
	return EventRef6<Param0, Param1, Param2, Param3, Param4, Param5>(this);
}

template<class Param0, class Param1, class Param2, class Param3, class Param4, class Param5, class Param6> class Event7 : public AbstractEvent
{
public:
	typedef Connection7<Param0, Param1, Param2, Param3, Param4, Param5, Param6> ConnectionType;

	Event7() {}
	~Event7() {}

	inline EventRef7<Param0, Param1, Param2, Param3, Param4, Param5, Param6> ref();

	void addConnection(ConnectionList * tracker, ConnectionType * conn)
	{
		AbstractEvent::addConnection(tracker, conn);
	}
	
	void fire(Param0 p0, Param1 p1, Param2 p2, Param3 p3, Param4 p4, Param5 p5, Param6 p6) const
	{
		FireLock lock(this);
		ConnectionsVector const & conns = lock.connections();
		for(ConnectionsVector::const_iterator it = conns.begin(); it != conns.end(); ++it)
		{
			static_cast<ConnectionType const *>(*it)->invoke(p0, p1, p2, p3, p4, p5, p6);
		}
	}
};

template<class Param0, class Param1, class Param2, class Param3, class Param4, class Param5, class Param6> class EventRef7 : public AbstractEventRef
{
public:
	typedef Event7<Param0, Param1, Param2, Param3, Param4, Param5, Param6> EventType;
	typedef typename EventType::ConnectionType ConnectionType;

	explicit EventRef7(EventType * ev) : AbstractEventRef(ev) {}

	template<class T, class Y> void connect(ConnectionList * tracker, T * obj, void (Y::*pmf)(Param0 p0, Param1 p1, Param2 p2, Param3 p3, Param4 p4, Param5 p5, Param6 p6))
	{
		ConnectionType * conn = new ConnectionType(
			fastdelegate::MakeDelegate(obj, pmf)
		);
		addConnection(tracker, conn);
	}

	template<class T, class Y> void connect(ConnectionList * tracker, T const * obj, void (Y::*pmf)(Param0 p0, Param1 p1, Param2 p2, Param3 p3, Param4 p4, Param5 p5, Param6 p6) const)
	{
		ConnectionType * conn = new ConnectionType(
			fastdelegate::MakeDelegate(obj, pmf)
		);
		addConnection(tracker, conn);
	}

	template<class T, class Y> void connect(ConnectionList * tracker, T * obj, Y pmf)
	{
		detail::ArgList0 stored;
		connectEx(tracker, fastdelegate::MakeDelegate(obj, pmf), stored);
	}

	template<class T, class Y, class T1> void connect(ConnectionList * tracker, T * obj, Y pmf, T1 x1)
	{
		typedef typename StorageType<T1>::Type S1;
		detail::ArgList1<S1> stored(x1);
		connectEx(tracker, fastdelegate::MakeDelegate(obj, pmf), stored);
	}

	template<class T, class Y, class T1, class T2> void connect(ConnectionList * tracker, T * obj, Y pmf, T1 x1, T2 x2)
	{
		typedef typename StorageType<T1>::Type S1;
		typedef typename StorageType<T2>::Type S2;
		detail::ArgList2<S1, S2> stored(x1, x2);
		connectEx(tracker, fastdelegate::MakeDelegate(obj, pmf), stored);
	}

	template<class T, class Y, class T1, class T2, class T3> void connect(ConnectionList * tracker, T * obj, Y pmf, T1 x1, T2 x2, T3 x3)
	{
		typedef typename StorageType<T1>::Type S1;
		typedef typename StorageType<T2>::Type S2;
		typedef typename StorageType<T3>::Type S3;
		detail::ArgList3<S1, S2, S3> stored(x1, x2, x3);
		connectEx(tracker, fastdelegate::MakeDelegate(obj, pmf), stored);
	}

	template<class T, class Y, class T1, class T2, class T3, class T4> void connect(ConnectionList * tracker, T * obj, Y pmf, T1 x1, T2 x2, T3 x3, T4 x4)
	{
		typedef typename StorageType<T1>::Type S1;
		typedef typename StorageType<T2>::Type S2;
		typedef typename StorageType<T3>::Type S3;
		typedef typename StorageType<T4>::Type S4;
		detail::ArgList4<S1, S2, S3, S4> stored(x1, x2, x3, x4);
		connectEx(tracker, fastdelegate::MakeDelegate(obj, pmf), stored);
	}

	template<class T, class Y, class T1, class T2, class T3, class T4, class T5> void connect(ConnectionList * tracker, T * obj, Y pmf, T1 x1, T2 x2, T3 x3, T4 x4, T5 x5)
	{
		typedef typename StorageType<T1>::Type S1;
		typedef typename StorageType<T2>::Type S2;
		typedef typename StorageType<T3>::Type S3;
		typedef typename StorageType<T4>::Type S4;
		typedef typename StorageType<T5>::Type S5;
		detail::ArgList5<S1, S2, S3, S4, S5> stored(x1, x2, x3, x4, x5);
		connectEx(tracker, fastdelegate::MakeDelegate(obj, pmf), stored);
	}

	template<class T, class Y, class T1, class T2, class T3, class T4, class T5, class T6> void connect(ConnectionList * tracker, T * obj, Y pmf, T1 x1, T2 x2, T3 x3, T4 x4, T5 x5, T6 x6)
	{
		typedef typename StorageType<T1>::Type S1;
		typedef typename StorageType<T2>::Type S2;
		typedef typename StorageType<T3>::Type S3;
		typedef typename StorageType<T4>::Type S4;
		typedef typename StorageType<T5>::Type S5;
		typedef typename StorageType<T6>::Type S6;
		detail::ArgList6<S1, S2, S3, S4, S5, S6> stored(x1, x2, x3, x4, x5, x6);
		connectEx(tracker, fastdelegate::MakeDelegate(obj, pmf), stored);
	}

	template<class T, class Y, class T1, class T2, class T3, class T4, class T5, class T6, class T7> void connect(ConnectionList * tracker, T * obj, Y pmf, T1 x1, T2 x2, T3 x3, T4 x4, T5 x5, T6 x6, T7 x7)
	{
		typedef typename StorageType<T1>::Type S1;
		typedef typename StorageType<T2>::Type S2;
		typedef typename StorageType<T3>::Type S3;
		typedef typename StorageType<T4>::Type S4;
		typedef typename StorageType<T5>::Type S5;
		typedef typename StorageType<T6>::Type S6;
		typedef typename StorageType<T7>::Type S7;
		detail::ArgList7<S1, S2, S3, S4, S5, S6, S7> stored(x1, x2, x3, x4, x5, x6, x7);
		connectEx(tracker, fastdelegate::MakeDelegate(obj, pmf), stored);
	}

	template<class T0, class T1, class T2, class T3, class T4, class T5, class T6> void connectEvent(ConnectionList * tracker, Event7<T0, T1, T2, T3, T4, T5, T6> * ev)
	{
		connect(tracker, ev, &Event7<T0, T1, T2, T3, T4, T5, T6>::fire);
	}
private:
	void addConnection(ConnectionList * tracker, ConnectionType * conn)
	{
		static_cast<EventType*>(senderEvent())->addConnection(tracker, conn);
	}

	template<class DelegateClass, class StoredListClass> void connectEx(ConnectionList * tracker, DelegateClass const & deleg, StoredListClass const & stored)
	{
		ConnectionType * conn = new ConnectionEx7<Param0, Param1, Param2, Param3, Param4, Param5, Param6, DelegateClass, StoredListClass>(
			deleg, stored
		);
		addConnection(tracker, conn);
	}
};

template<class Param0, class Param1, class Param2, class Param3, class Param4, class Param5, class Param6> 
inline EventRef7<Param0, Param1, Param2, Param3, Param4, Param5, Param6> Event7<Param0, Param1, Param2, Param3, Param4, Param5, Param6>::ref()
{
	return EventRef7<Param0, Param1, Param2, Param3, Param4, Param5, Param6>(this);
}

#endif //__CPP_EVENTS__EVENTS_HPP