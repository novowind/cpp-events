**Version 1.0.0 have been released!!!**

Events are powerful technique of the object-oriented design. They provide possibility to declare bidirectional object interfaces - public methods are used to send notifications to object and events are used to receive feedback.

I have found events (signals) extremely handy while working with Qt, and I was missing them much when programming in C++ without Qt. From the other hand, Qt's implementation of signal-slot mechanism has its own limitations - it does not support slot parametrization and usage of signals and slots in interfaces. Implementation provided by Boost.Signals is unsatisfactory as well. This motivated me to make my own implementation.

Features:
  * Thread-safe.
  * Six times faster than Boost.Signals.
  * Separate access specification for connection and firing the event.
  * Events can be virtual and pure virtual (can be used in interfaces).
  * Event chaining
  * Simple delegate binding
  * Non-intrusive connection tracking and automatic disconnecting.

Following features were intentionally disabled:
  * Static functions as delegates.
  * Managing return values, exceptions and invocation order of delegates.
  * Advanced delegate binding.
  * Support for old compilers.

I hope this library will be helpful to you. If you have any comments, questions, ideas or propositions please e-mail me. All feedback will be much appreciated.

> <p align='right'>Nickolas V. Pohilets</p>