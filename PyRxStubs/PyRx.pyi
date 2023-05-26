
class LispDataType:
    def __add__ (self, value, /):
      '''Return self+value.'''
    ...
    def __eq__ (self, value, /):
      '''Return self==value.'''
    ...
    def __init__ (self, /, *args, **kwargs):
      '''Initialize self.  See help(type(self)) for accurate signature.'''
    ...
    def __mul__ (self, value, /):
      '''Return self*value.'''
    ...
    def __ne__ (self, value, /):
      '''Return self!=value.'''
    ...
    def __sub__ (self, value, /):
      '''Return self-value.'''
    ...
    def __truediv__ (self, value, /):
      '''Return self/value.'''
    ...
    def as_integer_ratio (self, /):
      '''Return integer ratio.

Return a pair of integers, whose ratio is exactly equal to the original int
and with a positive denominator.

>>> (10).as_integer_ratio()
(10, 1)
>>> (-10).as_integer_ratio()
(-10, 1)
>>> (0).as_integer_ratio()
(0, 1)'''
    ...
    def bit_count (self, /):
      '''Number of ones in the binary representation of the absolute value of self.

Also known as the population count.

>>> bin(13)
'0b1101'
>>> (13).bit_count()
3'''
    ...
    def bit_length (self, /):
      '''Number of bits necessary to represent self in binary.

>>> bin(37)
'0b100101'
>>> (37).bit_length()
6'''
    ...
    def conjugate (self, *args, **kwargs):
      '''Returns self, the complex conjugate of any int.'''
    ...
    def denominator (self, *args, **kwargs):
      '''the denominator of a rational number in lowest terms'''
    ...
    def from_bytes (bytes, byteorder, *, signed=False):
      '''Return the integer represented by the given array of bytes.

  bytes
    Holds the array of bytes to convert.  The argument must either
    support the buffer protocol or be an iterable object producing bytes.
    Bytes and bytearray are examples of built-in objects that support the
    buffer protocol.
  byteorder
    The byte order used to represent the integer.  If byteorder is 'big',
    the most significant byte is at the beginning of the byte array.  If
    byteorder is 'little', the most significant byte is at the end of the
    byte array.  To request the native byte order of the host system, use
    `sys.byteorder' as the byte order value.
  signed
    Indicates whether two's complement is used to represent the integer.'''
    ...
    def imag (self, *args, **kwargs):
      '''the imaginary part of a complex number'''
    ...
    def kAngle (self, *args, **kwargs):
      '''None'''
    ...
    def kDottedPair (self, *args, **kwargs):
      '''None'''
    ...
    def kDouble (self, *args, **kwargs):
      '''None'''
    ...
    def kInt16 (self, *args, **kwargs):
      '''None'''
    ...
    def kInt32 (self, *args, **kwargs):
      '''None'''
    ...
    def kListBegin (self, *args, **kwargs):
      '''None'''
    ...
    def kListEnd (self, *args, **kwargs):
      '''None'''
    ...
    def kNil (self, *args, **kwargs):
      '''None'''
    ...
    def kNone (self, *args, **kwargs):
      '''None'''
    ...
    def kObjectId (self, *args, **kwargs):
      '''None'''
    ...
    def kOrientation (self, *args, **kwargs):
      '''None'''
    ...
    def kPoint2d (self, *args, **kwargs):
      '''None'''
    ...
    def kPoint3d (self, *args, **kwargs):
      '''None'''
    ...
    def kT_atom (self, *args, **kwargs):
      '''None'''
    ...
    def kText (self, *args, **kwargs):
      '''None'''
    ...
    def kVoid (self, *args, **kwargs):
      '''None'''
    ...
    def name (self, *args, **kwargs):
      '''None'''
    ...
    def names (self, *args, **kwargs):
      '''dict() -> new empty dictionary
dict(mapping) -> new dictionary initialized from a mapping object's
    (key, value) pairs
dict(iterable) -> new dictionary initialized as if via:
    d = {}
    for k, v in iterable:
        d[k] = v
dict(**kwargs) -> new dictionary initialized with the name=value pairs
    in the keyword argument list.  For example:  dict(one=1, two=2)'''
    ...
    def numerator (self, *args, **kwargs):
      '''the numerator of a rational number in lowest terms'''
    ...
    def real (self, *args, **kwargs):
      '''the real part of a complex number'''
    ...
    def to_bytes (self, /, length, byteorder, *, signed=False):
      '''Return an array of bytes representing an integer.

  length
    Length of bytes object to use.  An OverflowError is raised if the
    integer is not representable with the given number of bytes.
  byteorder
    The byte order used to represent the integer.  If byteorder is 'big',
    the most significant byte is at the beginning of the byte array.  If
    byteorder is 'little', the most significant byte is at the end of the
    byte array.  To request the native byte order of the host system, use
    `sys.byteorder' as the byte order value.
  signed
    Determines whether two's complement is used to represent the integer.
    If signed is False and a negative integer is given, an OverflowError
    is raised.'''
    ...
    def values (self, *args, **kwargs):
      '''dict() -> new empty dictionary
dict(mapping) -> new dictionary initialized from a mapping object's
    (key, value) pairs
dict(iterable) -> new dictionary initialized as if via:
    d = {}
    for k, v in iterable:
        d[k] = v
dict(**kwargs) -> new dictionary initialized with the name=value pairs
    in the keyword argument list.  For example:  dict(one=1, two=2)'''
    ...

class Overrule:
    def __eq__ (self, *args, **kwargs):
      '''
__eq__( (RxObject)arg1, (RxObject)arg2) -> bool :

    C++ signature :
        bool __eq__(class PyRxObject {lvalue},class PyRxObject)'''
    ...
    def __init__ (self, *args, **kwargs):
      '''Raises an exception
This class cannot be instantiated from Python
'''
    ...
    def __ne__ (self, *args, **kwargs):
      '''
__ne__( (RxObject)arg1, (RxObject)arg2) -> bool :

    C++ signature :
        bool __ne__(class PyRxObject {lvalue},class PyRxObject)'''
    ...
    def addOverrule (self, *args, **kwargs):
      '''
addOverrule( (RxClass)arg1, (Overrule)arg2) -> ErrorStatus :

    C++ signature :
        enum Acad::ErrorStatus addOverrule(class PyRxClass {lvalue},class PyRxOverrule {lvalue})'''
    ...
    def addOverruleLast (self, *args, **kwargs):
      '''
addOverruleLast( (RxClass)arg1, (Overrule)arg2, (bool)arg3) -> ErrorStatus :

    C++ signature :
        enum Acad::ErrorStatus addOverruleLast(class PyRxClass {lvalue},class PyRxOverrule {lvalue},bool)'''
    ...
    def className (self, *args, **kwargs):
      '''
className() -> str :

    C++ signature :
        class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> > className()'''
    ...
    def desc (self, *args, **kwargs):
      '''
desc() -> RxClass :

    C++ signature :
        class PyRxClass desc()'''
    ...
    def hasOverrule (self, *args, **kwargs):
      '''
hasOverrule( (RxObject)arg1, (RxClass)arg2) -> bool :

    C++ signature :
        bool hasOverrule(class PyRxObject {lvalue},class PyRxClass {lvalue})'''
    ...
    def isA (self, *args, **kwargs):
      '''
isA( (RxObject)arg1) -> RxClass :

    C++ signature :
        class PyRxClass isA(class PyRxObject {lvalue})'''
    ...
    def isNull (self, *args, **kwargs):
      '''
isNull( (RxObject)arg1) -> bool :

    C++ signature :
        bool isNull(class PyRxObject {lvalue})'''
    ...
    def isOverruling (self, *args, **kwargs):
      '''
isOverruling() -> bool :

    C++ signature :
        bool isOverruling()'''
    ...
    def refCount (self, *args, **kwargs):
      '''
refCount( (RxObject)arg1) -> int :

    C++ signature :
        int refCount(class PyRxObject {lvalue})'''
    ...
    def removeOverrule (self, *args, **kwargs):
      '''
removeOverrule( (RxClass)arg1, (Overrule)arg2) -> ErrorStatus :

    C++ signature :
        enum Acad::ErrorStatus removeOverrule(class PyRxClass {lvalue},class PyRxOverrule {lvalue})'''
    ...
    def setIsOverruling (self, *args, **kwargs):
      '''
setIsOverruling( (bool)arg1) -> None :

    C++ signature :
        void setIsOverruling(bool)'''
    ...

class RxClass:
    def __eq__ (self, *args, **kwargs):
      '''
__eq__( (RxObject)arg1, (RxObject)arg2) -> bool :

    C++ signature :
        bool __eq__(class PyRxObject {lvalue},class PyRxObject)'''
    ...
    def __init__ (self, *args, **kwargs):
      '''Raises an exception
This class cannot be instantiated from Python
'''
    ...
    def __ne__ (self, *args, **kwargs):
      '''
__ne__( (RxObject)arg1, (RxObject)arg2) -> bool :

    C++ signature :
        bool __ne__(class PyRxObject {lvalue},class PyRxObject)'''
    ...
    def className (self, *args, **kwargs):
      '''
className() -> str :

    C++ signature :
        class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> > className()'''
    ...
    def desc (self, *args, **kwargs):
      '''
desc() -> RxClass :

    C++ signature :
        class PyRxClass desc()'''
    ...
    def isA (self, *args, **kwargs):
      '''
isA( (RxObject)arg1) -> RxClass :

    C++ signature :
        class PyRxClass isA(class PyRxObject {lvalue})'''
    ...
    def isDerivedFrom (self, *args, **kwargs):
      '''
isDerivedFrom( (RxClass)arg1, (RxClass)arg2) -> bool :

    C++ signature :
        bool isDerivedFrom(class PyRxClass {lvalue},class PyRxClass)'''
    ...
    def isNull (self, *args, **kwargs):
      '''
isNull( (RxObject)arg1) -> bool :

    C++ signature :
        bool isNull(class PyRxObject {lvalue})'''
    ...
    def name (self, *args, **kwargs):
      '''
name( (RxClass)arg1) -> str :

    C++ signature :
        class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> > name(class PyRxClass {lvalue})'''
    ...
    def refCount (self, *args, **kwargs):
      '''
refCount( (RxObject)arg1) -> int :

    C++ signature :
        int refCount(class PyRxObject {lvalue})'''
    ...

class RxObject:
    def __eq__ (self, *args, **kwargs):
      '''
__eq__( (RxObject)arg1, (RxObject)arg2) -> bool :

    C++ signature :
        bool __eq__(class PyRxObject {lvalue},class PyRxObject)'''
    ...
    def __init__ (self, *args, **kwargs):
      '''Raises an exception
This class cannot be instantiated from Python
'''
    ...
    def __ne__ (self, *args, **kwargs):
      '''
__ne__( (RxObject)arg1, (RxObject)arg2) -> bool :

    C++ signature :
        bool __ne__(class PyRxObject {lvalue},class PyRxObject)'''
    ...
    def className (self, *args, **kwargs):
      '''
className() -> str :

    C++ signature :
        class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> > className()'''
    ...
    def isA (self, *args, **kwargs):
      '''
isA( (RxObject)arg1) -> RxClass :

    C++ signature :
        class PyRxClass isA(class PyRxObject {lvalue})'''
    ...
    def isNull (self, *args, **kwargs):
      '''
isNull( (RxObject)arg1) -> bool :

    C++ signature :
        bool isNull(class PyRxObject {lvalue})'''
    ...
    def refCount (self, *args, **kwargs):
      '''
refCount( (RxObject)arg1) -> int :

    C++ signature :
        int refCount(class PyRxObject {lvalue})'''
    ...

class __loader__:
    def _ORIGIN (self, *args, **kwargs):
      '''str(object='') -> str
str(bytes_or_buffer[, encoding[, errors]]) -> str

Create a new string object from the given object. If encoding or
errors is specified, then the object must expose a data buffer
that will be decoded using the given encoding and error handler.
Otherwise, returns the result of object.__str__() (if defined)
or repr(object).
encoding defaults to sys.getdefaultencoding().
errors defaults to 'strict'.'''
    ...
    def __eq__ (self, value, /):
      '''Return self==value.'''
    ...
    def __init__ (self, /, *args, **kwargs):
      '''Initialize self.  See help(type(self)) for accurate signature.'''
    ...
    def __ne__ (self, value, /):
      '''Return self!=value.'''
    ...
    def create_module (spec):
      '''Create a built-in module'''
    ...
    def exec_module (module):
      '''Exec a built-in module'''
    ...
    def find_module (fullname, path=None):
      '''Find the built-in module.

        If 'path' is ever specified then the search is considered a failure.

        This method is deprecated.  Use find_spec() instead.

        '''
    ...
    def find_spec (fullname, path=None, target=None):
      '''None'''
    ...
    def get_code (fullname):
      '''Return None as built-in modules do not have code objects.'''
    ...
    def get_source (fullname):
      '''Return None as built-in modules do not have source code.'''
    ...
    def is_package (fullname):
      '''Return False as built-in modules are never packages.'''
    ...
    def load_module (fullname):
      '''Load the specified module into sys.modules and return it.

    This method is deprecated.  Use loader.exec_module() instead.

    '''
    ...
    def module_repr (module):
      '''Return repr for the module.

        The method is deprecated.  The import machinery does the job itself.

        '''
    ...

class stderr:
    def __eq__ (self, value, /):
      '''Return self==value.'''
    ...
    def __init__ (self, *args, **kwargs):
      '''
__init__( (object)arg1) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64)

__init__( (object)arg1) -> object :

    C++ signature :
        void * __ptr64 __init__(class boost::python::api::object)'''
    ...
    def __ne__ (self, value, /):
      '''Return self!=value.'''
    ...
    def flush (self, *args, **kwargs):
      '''
flush( (stderr)arg1) -> None :

    C++ signature :
        void flush(class py_redirector<2> {lvalue})'''
    ...
    def write (self, *args, **kwargs):
      '''
write( (stderr)arg1, (str)arg2) -> None :

    C++ signature :
        void write(class py_redirector<2> {lvalue},class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >)'''
    ...

class stdout:
    def __eq__ (self, value, /):
      '''Return self==value.'''
    ...
    def __init__ (self, *args, **kwargs):
      '''
__init__( (object)arg1) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64)

__init__( (object)arg1) -> object :

    C++ signature :
        void * __ptr64 __init__(class boost::python::api::object)'''
    ...
    def __ne__ (self, value, /):
      '''Return self!=value.'''
    ...
    def flush (self, *args, **kwargs):
      '''
flush( (stdout)arg1) -> None :

    C++ signature :
        void flush(class py_redirector<0> {lvalue})'''
    ...
    def write (self, *args, **kwargs):
      '''
write( (stdout)arg1, (str)arg2) -> None :

    C++ signature :
        void write(class py_redirector<0> {lvalue},class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >)'''
    ...
