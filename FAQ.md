**1. Why "_events/delegates_" and not "_signals/slots_"?**

First of all for personal historical reasons - first time when I met this mechanism was short experience of GUI programming with old and dirty VB6. But finally I've decided to use Microsoft's terminology instead of Trolltech's one in order to avoid name conflicts with existing implementations.

**2. Why was support for static functions disabled?**

Usage of static functions as an event handlers is a symptom of a bad project design. In most cases (almost always) events handlers perform actions that require access to some state variables. In case of member functions, the `this` pointer is a legal way to supply function with access to state variables. In case of static functions state variables are accessed with use of global variables and non-stateless singletons. Both are considered to be dangerous and messy.

**3. Can I use events in global objects?**

Yes you can, but this is strongly discouraged. If your object fires or handles events then most likely it is not stateless and thus should not be global. Try to review your design, maybe UniversePattern will help you.

If you still wish to use events with global objects, then you should:
  1. Define you own singleton class that calls `Cpp::Threading::constructProcessData()` in constructor and `Cpp::Threading::destructProcessData()` in destructor (you can inherit from Cpp::Threading::ProcessInit or aggregate it).
  1. Define helper class that accesses singleton instance in constructor (this invokes singleton's constructor, if it has not been invoked yet).
  1. For all your global objects use this helper class as a base class or the first(!) field.

**4. What does MCS mean?**

Library is written in C++03 and does not use C++0x features. For generating
variadic templates custom preprocessor was written. It was named MCS, that
stands for Monkey Coding Script;) MCS is [hosted](http://code.google.com/p/monkey-coding-script) on Google Code as separate project. Repository of the MCS is included into repository of CppEvents via svn:externals in read-only mode.

**5. If an event is triggered from a thread A, and that event is connected to a delegate from a class instance created in thread B, where is that delegate executed? Thread A or thread B?**

Library have no knowledge about thread affinity of the objects. So it cannot know that event should be delivered in another thread. Also such mechanism would require event queue and run loop that are platform-dependent. So currently delegates are always executed in the same thread that triggered that event (thread A). If event should be handled in different thread, then it is responsibility of the delegate to enqueue required information into queue for processing in different thread.

**6. Are there any plans for queued delivery of the events?**

Yes, there are. This will be the goal of the version 1.1. Currently I'm not able to make any predictions about release date. Implementation will not contain any implementation of the event queue (except for unit-testing purposes), but instead provide an abstract interface that would allow writing adapter for concrete event queue system. Operations with event queue usually require thread synchronization, so they are pretty slow, virtual call won't create much overhead here. Also, it would be possible to invoke delegates via queue without need to connect them to events.