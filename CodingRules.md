# Project structure #

  1. Do not shorten file names.
  1. Use proper source file extensions according to programming language file is written in:
    * .h/.c - for pure C
    * .hpp/.cpp - for C++
    * .hh/.mm - for Objective-C++
    * .inl - for non-header files that should be included during preprocessing
  1. Include pure C headers into C++ code using helper C++ header (the same name, the same path if possible, different extension) that wraps pure C declarations into "extern C {}"-block.
  1. Put all sources that belong to one project into separate directory. Organize project sources into subdirectories according to project internal structure. Group multiple projects into higher-level directories according to solution structure.
  1. Include headers using paths relative to the solution root directory. Header paths should be taken into angle brackets, not in quotes. Do not use paths relative to current directory.
  1. Protect C/C++ headers by header guard, do not use "#pragma once" (it is not portable).
  1. Header guard should be generated from header path by the following algorithm:
    * All special characters ('.' and '/') are replaced by double underscore characters.
    * Single underscore character is inserted between separate words in path components.
    * All characters are converted to uppercase.
    * Double underscore is prepended.
  1. Use #import-statement for Objective-C headers.
  1. Module private declarations should be placed in auxiliary header file with suffix "-Private" (e.g. "MyClass-Private.hpp").
  1. If definition of nested class is moved to separate module, then this module should be named as "OuterClass.NestedClass".
  1. If precompiled header is used, it should be included into all header files as a first include, in order not to confuse code analysis tools.
  1. Precompiled header for dependent project should include precompiled headers of all used projects.
  1. Module private header should include corresponding public header as a first include.
  1. Include of the corresponding header (private if any, public otherwise) should be placed in the implementation file before all other includes except precompiled header, if any.
  1. Content and dependencies of header files should be minimized, forward declarations should be used whenever possible.
  1. TODO: What about paths for static libraries, DLLs and executables?
  1. TODO: What about paths for resources?

# Class design #
  1. Name classes in singular (wrong: `MyItems`, right: `MyItemList`).
  1. All member variables should be private if class has invariant, and public if class has not invariant. Do not use protected member variables.
  1. Do not return pointers/references to private data.
  1. Do not use default values for virtual functions, use inline non-virtual overloads instead.
  1. Destructor should be virtual, if class contains any virtual functions.
  1. Interface classes should have protected default constructor and protected virtual destructor.
  1. If class uses some compiler-generated members (default constructor, copy constructor, destructor, assignment operator) this should described in a comment.
  1. Never invoke virtual functions from constructor or destructor.
  1. Copy constructor and assignment operator should be disabled if class is not copyable.
  1. Use friends only for items that are logical parts of the class, but cannot be declared inside class. Do not use friend declarations for hacking access control.
  1. Use inner classes and inner enums, do not pollute global namespace.
  1. Don't use global variables and singletons. Use only global constants. Any use of singleton should be considered to be a dirty hack.
  1. Avoid half-alive object state. Do not use post-constructor initialization.
  1. Assignment operator should allow self-assignment.
  1. Assignment operator should return `*this`;
  1. Always perform mirror operations (open/close, show/hide, create/delete) at the same logical level

# Coding Rules #
  1. All identifiers, comments and string literals should be written in English and should be syntactically and grammatically correct. Never user transliteration for any purposes.
  1. Use function-style cast for value types and keyword-cast for pointers and references.
  1. Never use assignment inside expression
  1. Process exceptional conditions first. No not try to avoid multiple return points.
  1. Prefer prefix increment and decrement to postfix ones unless old value is needed.
  1. Avoid long expressions,  do not use long chains of member access operators (`a->b->c->d->e`). Use variables (preferably const) for intermediate results, extract subexpressions as separate functions.
  1. Do not declare variables beforehand. Declare variables when they can be initialized. If variable must be declared without initialization, then this should be noted in a brief comment.
  1. Pass output arguments by pointer or via custom reference class, not by reference.
  1. Write const-keyword after type name, not before (e.g. `QString const &`, but not `const QString &`).
  1. Do not use typedef struct and typedef enum in C++ code, only in plain C.
  1. Do not use `void` keyword for empty argument list.
  1. Do not use extra parenthesis in return statement (return is not a function).
  1. Put implementations of outlined function in the order of their declarations.
  1. Declare class members in the following order:
    1. Friends
    1. Special macros (Q\_OBJECT)
    1. Disabled members (copy constructor, assignment operation, destructor)
    1. Public members
    1. Qt signals
    1. Protected members
    1. Private members
  1. Declare members of each access group in the following order:
    1. Types and constants
    1. Static data
    1. Instance data
    1. Static functions
    1. Operators new/delete
    1. Constructors
    1. Destructor
    1. Assignment operator
    1. Other operators
    1. Properties (get/set methods)
    1. Other instance methods.
    1. Qt slots
  1. Outlined implementations should go in the same order as corresponding declarations.
  1. All fields and non-interface base classes should be explicitly initialized in initializer list, even if initialized with default constructor. But do pollute initializer list with initialization of interface base classes.
  1. Put items of initialization list in the declaration order. Base classes before fields.
  1. Initialize pointers to null value using default constructor syntax rather then explicitly initializing by "NULL" or "0".
  1. Always use single line comments ("//"-eol), do not use multi-line comments ("/**"-"**/"), because they cannot be nested.
  1. Do not compare boolean variables/expressions with boolean literals (wrong: `if(enabled == true) ...`, right: `if(enabled) ...`).
  1. Avoid implicit casting pointers and integers to boolean (wrong: `if(ptr) ...`, right: `if(ptr != null) ...`).
  1. Use `[NSObject respondsToSelector:]` only for checking for optional protocol methods.

# Code Formatting #
  1. Use tabs for logical indentation, use spaces for all other purposes.
  1. Indentation should be preserved for empty lines.
  1. All source files should end with empty line (configure IDE).
  1. Avoid extra spaces after line end.
  1. Do not try to align variable declarations into columns.
  1. Put space both before and after asterisk/ampersand in pointer/reference declarations. (wrong: `int *p = 0`, `int *p = 0`; right: `int * p = 0`).
  1. No space before column (labels, case statements, access keywords)
  1. No space before or after parenthesis (wrong: `( a + ( c * b ) )`; right: `(a + (c * b))`).
  1. No space after keywords **if**, **while** and **for** (before parenthesis).
  1. Space before and after binary operators.
  1. No space after prefix unary operator.
  1. No space before postfix unary operator.
  1. Space before and after '?' and ':' in ternary operator.
  1. No space before or after '.' or '->'.
  1. Do not indent namespace contents if entire file belongs to that namespace.
  1. Indent initializer list.
  1. Place initial colon and delimiting commas in initializer list at the beginning of the new line.