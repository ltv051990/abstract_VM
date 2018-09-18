# Abstract_VM

   AbstractVM is a machine that uses a stack to compute simple arithmetic expressions.
These arithmetic expressions are provided to the machine as basic assembly programs.

<img width="490" alt="123" src="https://user-images.githubusercontent.com/26527567/45699478-ae50d900-bb72-11e8-88f9-ea0ab64263ec.png">

As for any assembly language, the language of AbstractVM is composed of a series of
instructions, with one instruction per line. However, AbstractVM’s assembly language
has a limited type system, which is a major difference from other real world assembly
languages.

<img width="500" alt="123" src="https://user-images.githubusercontent.com/26527567/45699535-d2141f00-bb72-11e8-9966-66dc70b8722f.png">

   When a computation involves two operands of different types, the value returned has
the type of the more precise operand. Please do note that because of the extensibility of
the machine, the precision question is not a trivial one. This is covered more in details
later in this document.

<img width="496" alt="123" src="https://user-images.githubusercontent.com/26527567/45699628-0ee01600-bb73-11e8-91dd-86c575b2e4e9.png">

   When one of the following cases is encountered, AbstractVM must raise an exception
and stop the execution of the program cleanly. It is forbidden to raise scalar exceptions.
Moreover your exception classes must inherit from std::exception.

   Your machine must be able to run programs from a file passed as a parameter and from
the standard input. When reading from the standard input, the end of the program is
indicated by the special symbol ";;" otherwise absent.

  AbstractVM uses 5 operand classes that you must declare and define:
• Int8 : Representation of a signed integer coded on 8bits.
• Int16 : Representation of a signed integer coded on 16bits.
• Int32 : Representation of a signed integer coded on 32bits.
• Float : Representation of a float.
• Double : Representation of a double.

<img width="478" alt="123" src="https://user-images.githubusercontent.com/26527567/45699688-39ca6a00-bb73-11e8-8853-f67d576ab740.png">

   When an operation happens between two operands of the same type, there is no problem.
However, what about when the types are different ? The usual method is to order types
using their precision. For this machine you should use the following order: Int8 < Int16
< Int32 < Float < Double. This order may be represented as an enum, as enum values
evaluate to integers

<img width="498" alt="123" src="https://user-images.githubusercontent.com/26527567/45699764-7007e980-bb73-11e8-8a79-b93a98346911.png">
   AbstractVM is a stack based virtual machine. Whereas the stack is an actual stack or
another container that behaves like a stack is up to you. Whatever the container, it MUST
only contain pointers to the abstract type IOperand.
