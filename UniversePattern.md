# Introduction #

This pattern is not directly related to the topic of events, but since Singletons problem was mentioned in documentation several times, I decided to describe this pattern here.

# The Problem #

Very nice explanation of the problem can be found [here](http://blogs.msdn.com/scottdensmore/archive/2004/05/25/140827.aspx). I don't think I would write it better.

# Legal Singletons #

Are singletons perfectly evil? No, they are aren't. There are some cases when usage of singletons is perfectly safe and legal. But how to distinguish them? After some thinking about this topic I've found a nice formal rule that can be used to determine if usage of singleton is legal or not in some situation. The rule says **"Singletons should be stateless"**. The meaning of the _state_ may vary, but in the simplest case this means that all methods of the singleton should be const.

# The Pattern #
What is a singleton? It is an object that exists in singular in some scope. The key words here are _"in some scope"_. The idea of the pattern is to encapsulate that scope into an object and aggregate singleton into it. This object becomes a _Universe_ that provides miscellaneous services (formerly implemented as singletons) to its _citizens_.

Usually universe object has one interface for the external world and another (usually protected or private) for its citizens.

Pointer to the universe pattern is passed to the citizen in the constructor and is expected to be valid during all lifetime of the citizen (including destructor).

Very often universe object also serves as a factory for its citizens.

Citizens of the universe can be hidden from the external world or can be part of the interface with the external world.

The great benefit of the Universe pattern is that it clarifies all dependencies of the domain made from the Universe object with all its contents and concentrates them in the public interface of the Universe class. (This assumes that you do not spoil this effect by introducing back-door dependencies in the form of global variables, illegal singletons or something else).

# Example #
```
// Universe internal interface
class IUniverse
{
protected:
    IUniverse() {}
    virtual ~IUniverse() {}
public:
    virtual IService1 * service1() = 0;
    virtual IService2 * service2() = 0;
    //     ...             ...
    virtual IServiceN * serviceN() = 0;
};

// Base class for all object that reside inside the universe
class UniverseCitizen
{
public:
    UniverseCitizen(IUniverse * universe)
        : universe_(universe)
    {
        universe_->service2()->doSomething();
    }
protected:
    IUniverse * universe() { return universe_; }
private:
    IUniverse * universe_;
};

// Some subclass of the universe citizen.
class UniverseCitizenA : public UniverseCitizen
{
public:
    UniverseCitizenA(IUniverse * universe, SomeParams const & params)
        : UniverseCitizen(universe)
    {
        // ...
    }

    // ...
};

// Another subclass of the universe citizen.
class UniverseCitizenB : public UniverseCitizen
{
public:
    UniverseCitizenB(IUniverse * universe, AnotherParams const & params)
        : UniverseCitizen(universe)
    {
        // ...
    }

    // ...
};

// The universe class
class TheUniverse : public BaseClass, private IUniverse
{
public:
    TheUniverse(SomeParams const & p);
    ~TheUniverse();

    // Interface for the external world

    void helloFromExternalWorld();
    void goodbyeFromExternalWorld();

    // Factory method
    UniverseCitizen * createObject() { return new UniverseCitizen(this); }
private:
    virtual IService1 * service1();
    virtual IService2 * service2();
    //     ...             ...
    virtual IServiceN * serviceN();
};
```