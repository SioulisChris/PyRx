import PyRx
import PyGe
import PyGi
import PyGs
import PyDb
import PyAp
import PyEd
import PyPl

class CustomSizeResult:
    def __init__ (self, /, *args, **kwargs) :
      '''Initialize self.  See help(type(self)) for accurate signature.'''
    ...
    def as_integer_ratio (self, /) :
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
    def bit_count (self, /) :
      '''Number of ones in the binary representation of the absolute value of self.

Also known as the population count.

>>> bin(13)
'0b1101'
>>> (13).bit_count()
3'''
    ...
    def bit_length (self, /) :
      '''Number of bits necessary to represent self in binary.

>>> bin(37)
'0b100101'
>>> (37).bit_length()
6'''
    ...
    def conjugate (self, *args, **kwargs)-> None :
      '''Returns self, the complex conjugate of any int.'''
    ...
    def denominator (self, *args, **kwargs)-> None :
      '''the denominator of a rational number in lowest terms'''
    ...
    def eDeviceLoadFailed (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def eException (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def eMustCreatePC3 (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def ePC3DirReadOnly (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def ePC3FileReadOnly (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def ePMPDirMissing (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def ePMPDirReadOnly (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def ePMPFileReadOnly (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def ePossible (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def eRotationRequired (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def eSizeTooBig (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def eUnknownErrPC3File (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def eUnknownErrPMPDir (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def eUnknownErrPMPFile (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def eWidthAndHeightMustBePositive (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def from_bytes (bytes, byteorder, *, signed=False) :
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
    def imag (self, *args, **kwargs)-> None :
      '''the imaginary part of a complex number'''
    ...
    def name (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def names (self, *args, **kwargs)-> new empty dictionary
dict(mapping) -> new dictionary initialized from a mapping object's
    (key, value) pairs
dict(iterable) -> new dictionary initialized as if via :
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
    def numerator (self, *args, **kwargs)-> None :
      '''the numerator of a rational number in lowest terms'''
    ...
    def real (self, *args, **kwargs)-> None :
      '''the real part of a complex number'''
    ...
    def to_bytes (self, /, length, byteorder, *, signed=False) :
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
    def values (self, *args, **kwargs)-> new empty dictionary
dict(mapping) -> new dictionary initialized from a mapping object's
    (key, value) pairs
dict(iterable) -> new dictionary initialized as if via :
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

class DSDEntry:
    def NPS (self, *args, **kwargs)-> str :
      '''NPS( (DSDEntry)arg1) -> str :

    C++ signature :
        class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> > NPS(class PyPlDSDEntry {lvalue})'''
    ...
    def NPSSourceDWG (self, *args, **kwargs)-> str :
      '''NPSSourceDWG( (DSDEntry)arg1) -> str :

    C++ signature :
        class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> > NPSSourceDWG(class PyPlDSDEntry {lvalue})'''
    ...
    def __init__ (self, *args, **kwargs)-> None :
      '''__init__( (object)arg1) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64)'''
    ...
    def className ()-> str :
      '''                             '''
    ...
    def copyFrom (self: RxObject,other:PyRx.RxObject)-> None :
      '''                             '''
    ...
    def desc ()-> PyRx.RxClass :
      '''                             '''
    ...
    def dispose (self: RxObject)-> None :
      '''                             '''
    ...
    def dwgName (self, *args, **kwargs)-> str :
      '''dwgName( (DSDEntry)arg1) -> str :

    C++ signature :
        class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> > dwgName(class PyPlDSDEntry {lvalue})'''
    ...
    def has3dDwfSetup (self, *args, **kwargs)-> bool :
      '''has3dDwfSetup( (DSDEntry)arg1) -> bool :

    C++ signature :
        bool has3dDwfSetup(class PyPlDSDEntry {lvalue})'''
    ...
    def implRefCount (self: RxObject)-> int :
      '''                             '''
    ...
    def isA (self: RxObject)-> PyRx.RxClass :
      '''                             '''
    ...
    def isKindOf (self: RxObject,rhs:PyRx.RxClass)-> bool :
      '''                             '''
    ...
    def isNullObj (self: RxObject)-> bool :
      '''                             '''
    ...
    def keepAlive (self: RxObject,flag:bool)-> None :
      '''                             '''
    ...
    def layout (self, *args, **kwargs)-> str :
      '''layout( (DSDEntry)arg1) -> str :

    C++ signature :
        class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> > layout(class PyPlDSDEntry {lvalue})'''
    ...
    def orgSheetPath (self, *args, **kwargs)-> str :
      '''orgSheetPath( (DSDEntry)arg1) -> str :

    C++ signature :
        class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> > orgSheetPath(class PyPlDSDEntry {lvalue})'''
    ...
    def queryX (self: RxObject,rhs:PyRx.RxClass)-> PyRx.RxObject :
      '''                             '''
    ...
    def setDwgName (self, *args, **kwargs)-> None :
      '''setDwgName( (DSDEntry)arg1, (str)arg2) -> None :

    C++ signature :
        void setDwgName(class PyPlDSDEntry {lvalue},class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >)'''
    ...
    def setHas3dDwfSetup (self, *args, **kwargs)-> None :
      '''setHas3dDwfSetup( (DSDEntry)arg1, (bool)arg2) -> None :

    C++ signature :
        void setHas3dDwfSetup(class PyPlDSDEntry {lvalue},bool)'''
    ...
    def setLayout (self, *args, **kwargs)-> None :
      '''setLayout( (DSDEntry)arg1, (str)arg2) -> None :

    C++ signature :
        void setLayout(class PyPlDSDEntry {lvalue},class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> > {lvalue})'''
    ...
    def setNPS (self, *args, **kwargs)-> None :
      '''setNPS( (DSDEntry)arg1, (str)arg2) -> None :

    C++ signature :
        void setNPS(class PyPlDSDEntry {lvalue},class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >)'''
    ...
    def setNPSSourceDWG (self, *args, **kwargs)-> None :
      '''setNPSSourceDWG( (DSDEntry)arg1, (str)arg2) -> None :

    C++ signature :
        void setNPSSourceDWG(class PyPlDSDEntry {lvalue},class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >)'''
    ...
    def setSetupType (self, *args, **kwargs)-> None :
      '''setSetupType( (DSDEntry)arg1, (object)arg2) -> None :

    C++ signature :
        void setSetupType(class PyPlDSDEntry {lvalue},enum AcPlDSDEntry::SetupType)'''
    ...
    def setTitle (self, *args, **kwargs)-> None :
      '''setTitle( (DSDEntry)arg1, (str)arg2) -> None :

    C++ signature :
        void setTitle(class PyPlDSDEntry {lvalue},class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >)'''
    ...
    def setTraceSession (self, *args, **kwargs)-> None :
      '''setTraceSession( (DSDEntry)arg1, (str)arg2) -> None :

    C++ signature :
        void setTraceSession(class PyPlDSDEntry {lvalue},class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >)'''
    ...
    def setupType (self, *args, **kwargs)-> object :
      '''setupType( (DSDEntry)arg1) -> object :

    C++ signature :
        enum AcPlDSDEntry::SetupType setupType(class PyPlDSDEntry {lvalue})'''
    ...
    def title (self, *args, **kwargs)-> str :
      '''title( (DSDEntry)arg1) -> str :

    C++ signature :
        class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> > title(class PyPlDSDEntry {lvalue})'''
    ...
    def traceSession (self, *args, **kwargs)-> str :
      '''traceSession( (DSDEntry)arg1) -> str :

    C++ signature :
        class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> > traceSession(class PyPlDSDEntry {lvalue})'''
    ...

class MatchingPolicy:
    def __init__ (self, /, *args, **kwargs) :
      '''Initialize self.  See help(type(self)) for accurate signature.'''
    ...
    def as_integer_ratio (self, /) :
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
    def bit_count (self, /) :
      '''Number of ones in the binary representation of the absolute value of self.

Also known as the population count.

>>> bin(13)
'0b1101'
>>> (13).bit_count()
3'''
    ...
    def bit_length (self, /) :
      '''Number of bits necessary to represent self in binary.

>>> bin(37)
'0b100101'
>>> (37).bit_length()
6'''
    ...
    def conjugate (self, *args, **kwargs)-> None :
      '''Returns self, the complex conjugate of any int.'''
    ...
    def denominator (self, *args, **kwargs)-> None :
      '''the denominator of a rational number in lowest terms'''
    ...
    def from_bytes (bytes, byteorder, *, signed=False) :
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
    def imag (self, *args, **kwargs)-> None :
      '''the imaginary part of a complex number'''
    ...
    def kMatchDisabled (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def kMatchEnabled (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def kMatchEnabledCustom (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def kMatchEnabledTmpCustom (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def name (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def names (self, *args, **kwargs)-> new empty dictionary
dict(mapping) -> new dictionary initialized from a mapping object's
    (key, value) pairs
dict(iterable) -> new dictionary initialized as if via :
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
    def numerator (self, *args, **kwargs)-> None :
      '''the numerator of a rational number in lowest terms'''
    ...
    def real (self, *args, **kwargs)-> None :
      '''the real part of a complex number'''
    ...
    def to_bytes (self, /, length, byteorder, *, signed=False) :
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
    def values (self, *args, **kwargs)-> new empty dictionary
dict(mapping) -> new dictionary initialized from a mapping object's
    (key, value) pairs
dict(iterable) -> new dictionary initialized as if via :
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

class PlObject:
    def __init__ (self, *args, **kwargs)-> None :
      '''__init__( (object)arg1) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64)'''
    ...
    def categoryName (self, *args, **kwargs)-> str :
      '''categoryName( (PlObject)arg1) -> str :

    C++ signature :
        class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> > categoryName(class PyPlDSDData {lvalue})'''
    ...
    def className ()-> str :
      '''                             '''
    ...
    def copyFrom (self: RxObject,other:PyRx.RxObject)-> None :
      '''                             '''
    ...
    def currentPrecision (self, *args, **kwargs)-> str :
      '''currentPrecision( (PlObject)arg1) -> str :

    C++ signature :
        class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> > currentPrecision(class PyPlDSDData {lvalue})'''
    ...
    def desc ()-> PyRx.RxClass :
      '''                             '''
    ...
    def destinationName (self, *args, **kwargs)-> str :
      '''destinationName( (PlObject)arg1) -> str :

    C++ signature :
        class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> > destinationName(class PyPlDSDData {lvalue})'''
    ...
    def dispose (self: RxObject)-> None :
      '''                             '''
    ...
    def get3dDwfOptions (self, *args, **kwargs)-> tuple :
      '''get3dDwfOptions( (PlObject)arg1) -> tuple :

    C++ signature :
        class boost::python::tuple get3dDwfOptions(class PyPlDSDData {lvalue})'''
    ...
    def getDSDEntries (self, *args, **kwargs)-> list :
      '''getDSDEntries( (PlObject)arg1) -> list :

    C++ signature :
        class boost::python::list getDSDEntries(class PyPlDSDData {lvalue})'''
    ...
    def getPrecisionEntries (self, *args, **kwargs)-> list :
      '''getPrecisionEntries( (PlObject)arg1) -> list :

    C++ signature :
        class boost::python::list getPrecisionEntries(class PyPlDSDData {lvalue})'''
    ...
    def getUnrecognizedData (self, *args, **kwargs)-> None :
      '''getUnrecognizedData( (PlObject)arg1, (list)arg2, (list)arg3) -> None :

    C++ signature :
        void getUnrecognizedData(class PyPlDSDData {lvalue},class boost::python::list {lvalue},class boost::python::list {lvalue})'''
    ...
    def implRefCount (self: RxObject)-> int :
      '''                             '''
    ...
    def includeLayerInfo (self, *args, **kwargs)-> bool :
      '''includeLayerInfo( (PlObject)arg1) -> bool :

    C++ signature :
        bool includeLayerInfo(class PyPlDSDData {lvalue})'''
    ...
    def initializeLayouts (self, *args, **kwargs)-> bool :
      '''initializeLayouts( (PlObject)arg1) -> bool :

    C++ signature :
        bool initializeLayouts(class PyPlDSDData {lvalue})'''
    ...
    def isA (self: RxObject)-> PyRx.RxClass :
      '''                             '''
    ...
    def isHomogeneous (self, *args, **kwargs)-> bool :
      '''isHomogeneous( (PlObject)arg1) -> bool :

    C++ signature :
        bool isHomogeneous(class PyPlDSDData {lvalue})'''
    ...
    def isKindOf (self: RxObject,rhs:PyRx.RxClass)-> bool :
      '''                             '''
    ...
    def isNullObj (self: RxObject)-> bool :
      '''                             '''
    ...
    def isSheetSet (self, *args, **kwargs)-> bool :
      '''isSheetSet( (PlObject)arg1) -> bool :

    C++ signature :
        bool isSheetSet(class PyPlDSDData {lvalue})'''
    ...
    def keepAlive (self: RxObject,flag:bool)-> None :
      '''                             '''
    ...
    def lineMerge (self, *args, **kwargs)-> bool :
      '''lineMerge( (PlObject)arg1) -> bool :

    C++ signature :
        bool lineMerge(class PyPlDSDData {lvalue})'''
    ...
    def logFilePath (self, *args, **kwargs)-> str :
      '''logFilePath( (PlObject)arg1) -> str :

    C++ signature :
        class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> > logFilePath(class PyPlDSDData {lvalue})'''
    ...
    def majorVersion (self, *args, **kwargs)-> int :
      '''majorVersion( (PlObject)arg1) -> int :

    C++ signature :
        unsigned int majorVersion(class PyPlDSDData {lvalue})'''
    ...
    def minorVersion (self, *args, **kwargs)-> int :
      '''minorVersion( (PlObject)arg1) -> int :

    C++ signature :
        unsigned int minorVersion(class PyPlDSDData {lvalue})'''
    ...
    def noOfCopies (self, *args, **kwargs)-> int :
      '''noOfCopies( (PlObject)arg1) -> int :

    C++ signature :
        unsigned int noOfCopies(class PyPlDSDData {lvalue})'''
    ...
    def numberOfDSDEntries (self, *args, **kwargs)-> int :
      '''numberOfDSDEntries( (PlObject)arg1) -> int :

    C++ signature :
        int numberOfDSDEntries(class PyPlDSDData {lvalue})'''
    ...
    def password (self, *args, **kwargs)-> str :
      '''password( (PlObject)arg1) -> str :

    C++ signature :
        class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> > password(class PyPlDSDData {lvalue})'''
    ...
    def plotStampOn (self, *args, **kwargs)-> bool :
      '''plotStampOn( (PlObject)arg1) -> bool :

    C++ signature :
        bool plotStampOn(class PyPlDSDData {lvalue})'''
    ...
    def projectPath (self, *args, **kwargs)-> str :
      '''projectPath( (PlObject)arg1) -> str :

    C++ signature :
        class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> > projectPath(class PyPlDSDData {lvalue})'''
    ...
    def promptForDwfName (self, *args, **kwargs)-> bool :
      '''promptForDwfName( (PlObject)arg1) -> bool :

    C++ signature :
        bool promptForDwfName(class PyPlDSDData {lvalue})'''
    ...
    def promptForPassword (self, *args, **kwargs)-> bool :
      '''promptForPassword( (PlObject)arg1) -> bool :

    C++ signature :
        bool promptForPassword(class PyPlDSDData {lvalue})'''
    ...
    def pwdProtectPublishedDWF (self, *args, **kwargs)-> bool :
      '''pwdProtectPublishedDWF( (PlObject)arg1) -> bool :

    C++ signature :
        bool pwdProtectPublishedDWF(class PyPlDSDData {lvalue})'''
    ...
    def queryX (self: RxObject,rhs:PyRx.RxClass)-> PyRx.RxObject :
      '''                             '''
    ...
    def selectionSetName (self, *args, **kwargs)-> str :
      '''selectionSetName( (PlObject)arg1) -> str :

    C++ signature :
        class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> > selectionSetName(class PyPlDSDData {lvalue})'''
    ...
    def set3dDwfOptions (self, *args, **kwargs)-> None :
      '''set3dDwfOptions( (PlObject)arg1, (bool)arg2, (bool)arg3) -> None :

    C++ signature :
        void set3dDwfOptions(class PyPlDSDData {lvalue},bool,bool)'''
    ...
    def setCategoryName (self, *args, **kwargs)-> None :
      '''setCategoryName( (PlObject)arg1, (str)arg2) -> None :

    C++ signature :
        void setCategoryName(class PyPlDSDData {lvalue},class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >)'''
    ...
    def setCurrentPrecision (self, *args, **kwargs)-> None :
      '''setCurrentPrecision( (PlObject)arg1, (str)arg2) -> None :

    C++ signature :
        void setCurrentPrecision(class PyPlDSDData {lvalue},class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >)'''
    ...
    def setDSDEntries (self, *args, **kwargs)-> None :
      '''setDSDEntries( (PlObject)arg1, (list)arg2) -> None :

    C++ signature :
        void setDSDEntries(class PyPlDSDData {lvalue},class boost::python::list)'''
    ...
    def setDestinationName (self, *args, **kwargs)-> None :
      '''setDestinationName( (PlObject)arg1, (str)arg2) -> None :

    C++ signature :
        void setDestinationName(class PyPlDSDData {lvalue},class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >)'''
    ...
    def setIncludeLayerInfo (self, *args, **kwargs)-> None :
      '''setIncludeLayerInfo( (PlObject)arg1, (bool)arg2) -> None :

    C++ signature :
        void setIncludeLayerInfo(class PyPlDSDData {lvalue},bool)'''
    ...
    def setInitializeLayouts (self, *args, **kwargs)-> None :
      '''setInitializeLayouts( (PlObject)arg1, (bool)arg2) -> None :

    C++ signature :
        void setInitializeLayouts(class PyPlDSDData {lvalue},bool)'''
    ...
    def setIsHomogeneous (self, *args, **kwargs)-> None :
      '''setIsHomogeneous( (PlObject)arg1, (bool)arg2) -> None :

    C++ signature :
        void setIsHomogeneous(class PyPlDSDData {lvalue},bool)'''
    ...
    def setIsSheetSet (self, *args, **kwargs)-> None :
      '''setIsSheetSet( (PlObject)arg1, (bool)arg2) -> None :

    C++ signature :
        void setIsSheetSet(class PyPlDSDData {lvalue},bool)'''
    ...
    def setLineMerge (self, *args, **kwargs)-> None :
      '''setLineMerge( (PlObject)arg1, (bool)arg2) -> None :

    C++ signature :
        void setLineMerge(class PyPlDSDData {lvalue},bool)'''
    ...
    def setLogFilePath (self, *args, **kwargs)-> None :
      '''setLogFilePath( (PlObject)arg1, (str)arg2) -> None :

    C++ signature :
        void setLogFilePath(class PyPlDSDData {lvalue},class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >)'''
    ...
    def setMajorVersion (self, *args, **kwargs)-> None :
      '''setMajorVersion( (PlObject)arg1, (SubentType)arg2) -> None :

    C++ signature :
        void setMajorVersion(class PyPlDSDData {lvalue},unsigned int)'''
    ...
    def setMinorVersion (self, *args, **kwargs)-> None :
      '''setMinorVersion( (PlObject)arg1, (SubentType)arg2) -> None :

    C++ signature :
        void setMinorVersion(class PyPlDSDData {lvalue},unsigned int)'''
    ...
    def setNoOfCopies (self, *args, **kwargs)-> None :
      '''setNoOfCopies( (PlObject)arg1, (SubentType)arg2) -> None :

    C++ signature :
        void setNoOfCopies(class PyPlDSDData {lvalue},unsigned int)'''
    ...
    def setPassword (self, *args, **kwargs)-> None :
      '''setPassword( (PlObject)arg1, (str)arg2) -> None :

    C++ signature :
        void setPassword(class PyPlDSDData {lvalue},class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >)'''
    ...
    def setPlotStampOn (self, *args, **kwargs)-> None :
      '''setPlotStampOn( (PlObject)arg1, (bool)arg2) -> None :

    C++ signature :
        void setPlotStampOn(class PyPlDSDData {lvalue},bool)'''
    ...
    def setPrecisionEntries (self, *args, **kwargs)-> None :
      '''setPrecisionEntries( (PlObject)arg1, (list)arg2) -> None :

    C++ signature :
        void setPrecisionEntries(class PyPlDSDData {lvalue},class boost::python::list)'''
    ...
    def setProjectPath (self, *args, **kwargs)-> None :
      '''setProjectPath( (PlObject)arg1, (str)arg2) -> None :

    C++ signature :
        void setProjectPath(class PyPlDSDData {lvalue},class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >)'''
    ...
    def setPromptForDwfName (self, *args, **kwargs)-> None :
      '''setPromptForDwfName( (PlObject)arg1, (bool)arg2) -> None :

    C++ signature :
        void setPromptForDwfName(class PyPlDSDData {lvalue},bool)'''
    ...
    def setPromptForPassword (self, *args, **kwargs)-> None :
      '''setPromptForPassword( (PlObject)arg1, (bool)arg2) -> None :

    C++ signature :
        void setPromptForPassword(class PyPlDSDData {lvalue},bool)'''
    ...
    def setPwdProtectPublishedDWF (self, *args, **kwargs)-> None :
      '''setPwdProtectPublishedDWF( (PlObject)arg1, (bool)arg2) -> None :

    C++ signature :
        void setPwdProtectPublishedDWF(class PyPlDSDData {lvalue},bool)'''
    ...
    def setSelectionSetName (self, *args, **kwargs)-> None :
      '''setSelectionSetName( (PlObject)arg1, (str)arg2) -> None :

    C++ signature :
        void setSelectionSetName(class PyPlDSDData {lvalue},class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >)'''
    ...
    def setSheetSetName (self, *args, **kwargs)-> None :
      '''setSheetSetName( (PlObject)arg1, (str)arg2) -> None :

    C++ signature :
        void setSheetSetName(class PyPlDSDData {lvalue},class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >)'''
    ...
    def setSheetType (self, *args, **kwargs)-> None :
      '''setSheetType( (PlObject)arg1, (object)arg2) -> None :

    C++ signature :
        void setSheetType(class PyPlDSDData {lvalue},enum AcPlDSDEntry::SheetType)'''
    ...
    def setUnrecognizedData (self, *args, **kwargs)-> None :
      '''setUnrecognizedData( (PlObject)arg1, (str)arg2, (str)arg3) -> None :

    C++ signature :
        void setUnrecognizedData(class PyPlDSDData {lvalue},class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >,class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >)

setUnrecognizedData( (PlObject)arg1, (list)arg2, (list)arg3) -> None :

    C++ signature :
        void setUnrecognizedData(class PyPlDSDData {lvalue},class boost::python::list,class boost::python::list)'''
    ...
    def setViewFile (self, *args, **kwargs)-> None :
      '''setViewFile( (PlObject)arg1, (bool)arg2) -> None :

    C++ signature :
        void setViewFile(class PyPlDSDData {lvalue},bool)'''
    ...
    def sheetSetName (self, *args, **kwargs)-> str :
      '''sheetSetName( (PlObject)arg1) -> str :

    C++ signature :
        class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> > sheetSetName(class PyPlDSDData {lvalue})'''
    ...
    def sheetType (self, *args, **kwargs)-> object :
      '''sheetType( (PlObject)arg1) -> object :

    C++ signature :
        enum AcPlDSDEntry::SheetType sheetType(class PyPlDSDData {lvalue})'''
    ...
    def viewFile (self, *args, **kwargs)-> bool :
      '''viewFile( (PlObject)arg1) -> bool :

    C++ signature :
        bool viewFile(class PyPlDSDData {lvalue})'''
    ...

class PlotCancelStatus:
    def __init__ (self, /, *args, **kwargs) :
      '''Initialize self.  See help(type(self)) for accurate signature.'''
    ...
    def as_integer_ratio (self, /) :
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
    def bit_count (self, /) :
      '''Number of ones in the binary representation of the absolute value of self.

Also known as the population count.

>>> bin(13)
'0b1101'
>>> (13).bit_count()
3'''
    ...
    def bit_length (self, /) :
      '''Number of bits necessary to represent self in binary.

>>> bin(37)
'0b100101'
>>> (37).bit_length()
6'''
    ...
    def conjugate (self, *args, **kwargs)-> None :
      '''Returns self, the complex conjugate of any int.'''
    ...
    def denominator (self, *args, **kwargs)-> None :
      '''the denominator of a rational number in lowest terms'''
    ...
    def from_bytes (bytes, byteorder, *, signed=False) :
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
    def imag (self, *args, **kwargs)-> None :
      '''the imaginary part of a complex number'''
    ...
    def kPlotCancelStatusCount (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def kPlotCanceledByCaller (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def kPlotCanceledByCancelAllButton (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def kPlotContinue (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def name (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def names (self, *args, **kwargs)-> new empty dictionary
dict(mapping) -> new dictionary initialized from a mapping object's
    (key, value) pairs
dict(iterable) -> new dictionary initialized as if via :
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
    def numerator (self, *args, **kwargs)-> None :
      '''the numerator of a rational number in lowest terms'''
    ...
    def real (self, *args, **kwargs)-> None :
      '''the real part of a complex number'''
    ...
    def to_bytes (self, /, length, byteorder, *, signed=False) :
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
    def values (self, *args, **kwargs)-> new empty dictionary
dict(mapping) -> new dictionary initialized from a mapping object's
    (key, value) pairs
dict(iterable) -> new dictionary initialized as if via :
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

class PlotConfig:
    def __init__ (self, *args, **kwargs)-> None :
      '''Raises an exception
This class cannot be instantiated from Python'''
    ...
    def className ()-> str :
      '''                             '''
    ...
    def copyFrom (self: RxObject,other:PyRx.RxObject)-> None :
      '''                             '''
    ...
    def desc ()-> PyRx.RxClass :
      '''                             '''
    ...
    def dispose (self: RxObject)-> None :
      '''                             '''
    ...
    def implRefCount (self: RxObject)-> int :
      '''                             '''
    ...
    def isA (self: RxObject)-> PyRx.RxClass :
      '''                             '''
    ...
    def isKindOf (self: RxObject,rhs:PyRx.RxClass)-> bool :
      '''                             '''
    ...
    def isNullObj (self: RxObject)-> bool :
      '''                             '''
    ...
    def keepAlive (self: RxObject,flag:bool)-> None :
      '''                             '''
    ...
    def queryX (self: RxObject,rhs:PyRx.RxClass)-> PyRx.RxObject :
      '''                             '''
    ...

class PlotEngine:
    def __init__ (self, *args, **kwargs)-> None :
      '''Raises an exception
This class cannot be instantiated from Python'''
    ...
    def beginDocument (self, *args, **kwargs)-> None :
      '''beginDocument( (PlotEngine)arg1, (PlotInfo)arg2, (str)arg3, (int)arg4, (bool)arg5, (str)arg6) -> None :

    C++ signature :
        void beginDocument(class PyPlPlotEngine {lvalue},class PyPlPlotInfo {lvalue},class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >,int,bool,class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >)'''
    ...
    def beginGenerateGraphics (self, *args, **kwargs)-> None :
      '''beginGenerateGraphics( (PlotEngine)arg1) -> None :

    C++ signature :
        void beginGenerateGraphics(class PyPlPlotEngine {lvalue})'''
    ...
    def beginPage (self, *args, **kwargs)-> None :
      '''beginPage( (PlotEngine)arg1, (PlotPageInfo)arg2, (PlotInfo)arg3, (bool)arg4) -> None :

    C++ signature :
        void beginPage(class PyPlPlotEngine {lvalue},class PyPlPlotPageInfo {lvalue},class PyPlPlotInfo {lvalue},bool)'''
    ...
    def beginPlot (self, *args, **kwargs)-> None :
      '''beginPlot( (PlotEngine)arg1, (PlotProgressDialog)arg2) -> None :

    C++ signature :
        void beginPlot(class PyPlPlotEngine {lvalue},class PyPlPlotProgressDialog {lvalue})'''
    ...
    def className ()-> str :
      '''                             '''
    ...
    def destroy (self, *args, **kwargs)-> None :
      '''destroy( (PlotEngine)arg1) -> None :

    C++ signature :
        void destroy(class PyPlPlotEngine {lvalue})'''
    ...
    def endDocument (self, *args, **kwargs)-> None :
      '''endDocument( (PlotEngine)arg1) -> None :

    C++ signature :
        void endDocument(class PyPlPlotEngine {lvalue})'''
    ...
    def endGenerateGraphics (self, *args, **kwargs)-> None :
      '''endGenerateGraphics( (PlotEngine)arg1) -> None :

    C++ signature :
        void endGenerateGraphics(class PyPlPlotEngine {lvalue})'''
    ...
    def endPage (self, *args, **kwargs)-> None :
      '''endPage( (PlotEngine)arg1) -> None :

    C++ signature :
        void endPage(class PyPlPlotEngine {lvalue})'''
    ...
    def endPlot (self, *args, **kwargs)-> None :
      '''endPlot( (PlotEngine)arg1) -> None :

    C++ signature :
        void endPlot(class PyPlPlotEngine {lvalue})'''
    ...
    def isBackgroundPackaging (self, *args, **kwargs)-> bool :
      '''isBackgroundPackaging( (PlotEngine)arg1) -> bool :

    C++ signature :
        bool isBackgroundPackaging(class PyPlPlotEngine {lvalue})'''
    ...

class PlotFactory:
    def __init__ (self, *args, **kwargs)-> None :
      '''Raises an exception
This class cannot be instantiated from Python'''
    ...
    def className ()-> str :
      '''                             '''
    ...
    def createPreviewEngine (flags : int = default)-> PyPl.PlotEngine :
      '''                             '''
    ...
    def createPublishEngine ()-> PyPl.PlotEngine :
      '''                             '''
    ...
    def processPlotState ()-> PyPl.ProcessPlotState :
      '''                             '''
    ...

class PlotInfo:
    def OrgFilePath (self, *args, **kwargs)-> str :
      '''OrgFilePath( (PlotInfo)arg1) -> str :

    C++ signature :
        class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> > OrgFilePath(class PyPlPlotInfo {lvalue})'''
    ...
    def __init__ (self, *args, **kwargs)-> None :
      '''__init__( (object)arg1) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64)'''
    ...
    def className ()-> str :
      '''                             '''
    ...
    def copyFrom (self, *args, **kwargs)-> None :
      '''copyFrom( (PlotInfo)arg1, (RxObject)arg2) -> None :

    C++ signature :
        void copyFrom(class PyPlPlotInfo {lvalue},class PyRxObject)'''
    ...
    def desc ()-> PyRx.RxClass :
      '''                             '''
    ...
    def deviceOverride (self, *args, **kwargs)-> PyPl.PlotConfig :
      '''deviceOverride( (PlotInfo)arg1) -> PlotConfig :

    C++ signature :
        class PyPlPlotConfig deviceOverride(class PyPlPlotInfo {lvalue})'''
    ...
    def dispose (self: RxObject)-> None :
      '''                             '''
    ...
    def implRefCount (self: RxObject)-> int :
      '''                             '''
    ...
    def isA (self: RxObject)-> PyRx.RxClass :
      '''                             '''
    ...
    def isCompatibleDocument (self, *args, **kwargs)-> bool :
      '''isCompatibleDocument( (PlotInfo)arg1, (PlotInfo)arg2) -> bool :

    C++ signature :
        bool isCompatibleDocument(class PyPlPlotInfo {lvalue},class PyPlPlotInfo)'''
    ...
    def isKindOf (self: RxObject,rhs:PyRx.RxClass)-> bool :
      '''                             '''
    ...
    def isNullObj (self: RxObject)-> bool :
      '''                             '''
    ...
    def isValidated (self, *args, **kwargs)-> bool :
      '''isValidated( (PlotInfo)arg1) -> bool :

    C++ signature :
        bool isValidated(class PyPlPlotInfo {lvalue})'''
    ...
    def keepAlive (self: RxObject,flag:bool)-> None :
      '''                             '''
    ...
    def layout (self, *args, **kwargs)-> PyDb.ObjectId :
      '''layout( (PlotInfo)arg1) -> ObjectId :

    C++ signature :
        class PyDbObjectId layout(class PyPlPlotInfo {lvalue})'''
    ...
    def mergeStatus (self, *args, **kwargs)-> int :
      '''mergeStatus( (PlotInfo)arg1) -> int :

    C++ signature :
        unsigned long mergeStatus(class PyPlPlotInfo {lvalue})'''
    ...
    def overrideSettings (self, *args, **kwargs)-> PyDb.PlotSettings :
      '''overrideSettings( (PlotInfo)arg1) -> PlotSettings :

    C++ signature :
        class PyDbPlotSettings overrideSettings(class PyPlPlotInfo {lvalue})'''
    ...
    def queryX (self: RxObject,rhs:PyRx.RxClass)-> PyRx.RxObject :
      '''                             '''
    ...
    def setDeviceOverride (self, *args, **kwargs)-> None :
      '''setDeviceOverride( (PlotInfo)arg1, (PlotConfig)arg2) -> None :

    C++ signature :
        void setDeviceOverride(class PyPlPlotInfo {lvalue},class PyPlPlotConfig)'''
    ...
    def setLayout (self, *args, **kwargs)-> None :
      '''setLayout( (PlotInfo)arg1, (ObjectId)arg2) -> None :

    C++ signature :
        void setLayout(class PyPlPlotInfo {lvalue},class PyDbObjectId {lvalue})'''
    ...
    def setOverrideSettings (self, *args, **kwargs)-> None :
      '''setOverrideSettings( (PlotInfo)arg1, (PlotSettings)arg2) -> None :

    C++ signature :
        void setOverrideSettings(class PyPlPlotInfo {lvalue},class PyDbPlotSettings)'''
    ...
    def setValidatedConfig (self, *args, **kwargs)-> None :
      '''setValidatedConfig( (PlotInfo)arg1, (PlotConfig)arg2) -> None :

    C++ signature :
        void setValidatedConfig(class PyPlPlotInfo {lvalue},class PyPlPlotConfig)'''
    ...
    def setValidatedSettings (self, *args, **kwargs)-> None :
      '''setValidatedSettings( (PlotInfo)arg1, (PlotSettings)arg2) -> None :

    C++ signature :
        void setValidatedSettings(class PyPlPlotInfo {lvalue},class PyDbPlotSettings)'''
    ...
    def validatedConfig (self, *args, **kwargs)-> PyPl.PlotConfig :
      '''validatedConfig( (PlotInfo)arg1) -> PlotConfig :

    C++ signature :
        class PyPlPlotConfig validatedConfig(class PyPlPlotInfo {lvalue})'''
    ...
    def validatedSettings (self, *args, **kwargs)-> PyDb.PlotSettings :
      '''validatedSettings( (PlotInfo)arg1) -> PlotSettings :

    C++ signature :
        class PyDbPlotSettings validatedSettings(class PyPlPlotInfo {lvalue})'''
    ...

class PlotInfoValidator:
    def __init__ (self, *args, **kwargs)-> None :
      '''__init__( (object)arg1) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64)'''
    ...
    def className ()-> str :
      '''                             '''
    ...
    def copyFrom (self: RxObject,other:PyRx.RxObject)-> None :
      '''                             '''
    ...
    def desc ()-> PyRx.RxClass :
      '''                             '''
    ...
    def dimensionalWeight (self, *args, **kwargs)-> int :
      '''dimensionalWeight( (PlotInfoValidator)arg1) -> int :

    C++ signature :
        unsigned int dimensionalWeight(class PyPlPlotInfoValidator {lvalue})'''
    ...
    def dispose (self: RxObject)-> None :
      '''                             '''
    ...
    def implRefCount (self: RxObject)-> int :
      '''                             '''
    ...
    def isA (self: RxObject)-> PyRx.RxClass :
      '''                             '''
    ...
    def isCustomPossible (self, *args, **kwargs)-> PyPl.CustomSizeResult :
      '''isCustomPossible( (PlotInfoValidator)arg1, (PlotInfo)arg2) -> CustomSizeResult :

    C++ signature :
        enum AcPlPlotInfoValidator::eCustomSizeResult isCustomPossible(class PyPlPlotInfoValidator {lvalue},class PyPlPlotInfo {lvalue})'''
    ...
    def isKindOf (self: RxObject,rhs:PyRx.RxClass)-> bool :
      '''                             '''
    ...
    def isNullObj (self: RxObject)-> bool :
      '''                             '''
    ...
    def keepAlive (self: RxObject,flag:bool)-> None :
      '''                             '''
    ...
    def matchingPolicy (self, *args, **kwargs)-> PyPl.MatchingPolicy :
      '''matchingPolicy( (PlotInfoValidator)arg1) -> MatchingPolicy :

    C++ signature :
        enum AcPlPlotInfoValidator::MatchingPolicy matchingPolicy(class PyPlPlotInfoValidator {lvalue})'''
    ...
    def mediaBoundsWeight (self, *args, **kwargs)-> int :
      '''mediaBoundsWeight( (PlotInfoValidator)arg1) -> int :

    C++ signature :
        unsigned int mediaBoundsWeight(class PyPlPlotInfoValidator {lvalue})'''
    ...
    def mediaGroupWeight (self, *args, **kwargs)-> int :
      '''mediaGroupWeight( (PlotInfoValidator)arg1) -> int :

    C++ signature :
        unsigned int mediaGroupWeight(class PyPlPlotInfoValidator {lvalue})'''
    ...
    def mediaMatchingThreshold (self, *args, **kwargs)-> int :
      '''mediaMatchingThreshold( (PlotInfoValidator)arg1) -> int :

    C++ signature :
        unsigned int mediaMatchingThreshold(class PyPlPlotInfoValidator {lvalue})'''
    ...
    def printableBoundsWeight (self, *args, **kwargs)-> int :
      '''printableBoundsWeight( (PlotInfoValidator)arg1) -> int :

    C++ signature :
        unsigned int printableBoundsWeight(class PyPlPlotInfoValidator {lvalue})'''
    ...
    def queryX (self: RxObject,rhs:PyRx.RxClass)-> PyRx.RxObject :
      '''                             '''
    ...
    def setDefDimensionalWeight (self, *args, **kwargs)-> None :
      '''setDefDimensionalWeight( (PlotInfoValidator)arg1) -> None :

    C++ signature :
        void setDefDimensionalWeight(class PyPlPlotInfoValidator {lvalue})'''
    ...
    def setDefMediaBoundsWeight (self, *args, **kwargs)-> None :
      '''setDefMediaBoundsWeight( (PlotInfoValidator)arg1) -> None :

    C++ signature :
        void setDefMediaBoundsWeight(class PyPlPlotInfoValidator {lvalue})'''
    ...
    def setDefMediaGroupWeight (self, *args, **kwargs)-> None :
      '''setDefMediaGroupWeight( (PlotInfoValidator)arg1) -> None :

    C++ signature :
        void setDefMediaGroupWeight(class PyPlPlotInfoValidator {lvalue})'''
    ...
    def setDefMediaMatchingThreshold (self, *args, **kwargs)-> None :
      '''setDefMediaMatchingThreshold( (PlotInfoValidator)arg1) -> None :

    C++ signature :
        void setDefMediaMatchingThreshold(class PyPlPlotInfoValidator {lvalue})'''
    ...
    def setDefPrintableBoundsWeight (self, *args, **kwargs)-> None :
      '''setDefPrintableBoundsWeight( (PlotInfoValidator)arg1) -> None :

    C++ signature :
        void setDefPrintableBoundsWeight(class PyPlPlotInfoValidator {lvalue})'''
    ...
    def setDefSheetDimensionalWeight (self, *args, **kwargs)-> None :
      '''setDefSheetDimensionalWeight( (PlotInfoValidator)arg1) -> None :

    C++ signature :
        void setDefSheetDimensionalWeight(class PyPlPlotInfoValidator {lvalue})'''
    ...
    def setDefSheetMediaGroupWeight (self, *args, **kwargs)-> None :
      '''setDefSheetMediaGroupWeight( (PlotInfoValidator)arg1) -> None :

    C++ signature :
        void setDefSheetMediaGroupWeight(class PyPlPlotInfoValidator {lvalue})'''
    ...
    def setDimensionalWeight (self, *args, **kwargs)-> None :
      '''setDimensionalWeight( (PlotInfoValidator)arg1, (SubentType)arg2) -> None :

    C++ signature :
        void setDimensionalWeight(class PyPlPlotInfoValidator {lvalue},unsigned int)'''
    ...
    def setMediaBoundsWeight (self, *args, **kwargs)-> None :
      '''setMediaBoundsWeight( (PlotInfoValidator)arg1, (SubentType)arg2) -> None :

    C++ signature :
        void setMediaBoundsWeight(class PyPlPlotInfoValidator {lvalue},unsigned int)'''
    ...
    def setMediaGroupWeight (self, *args, **kwargs)-> None :
      '''setMediaGroupWeight( (PlotInfoValidator)arg1, (SubentType)arg2) -> None :

    C++ signature :
        void setMediaGroupWeight(class PyPlPlotInfoValidator {lvalue},unsigned int)'''
    ...
    def setMediaMatchingPolicy (self, *args, **kwargs)-> None :
      '''setMediaMatchingPolicy( (PlotInfoValidator)arg1, (MatchingPolicy)arg2) -> None :

    C++ signature :
        void setMediaMatchingPolicy(class PyPlPlotInfoValidator {lvalue},enum AcPlPlotInfoValidator::MatchingPolicy)'''
    ...
    def setMediaMatchingThreshold (self, *args, **kwargs)-> None :
      '''setMediaMatchingThreshold( (PlotInfoValidator)arg1, (SubentType)arg2) -> None :

    C++ signature :
        void setMediaMatchingThreshold(class PyPlPlotInfoValidator {lvalue},unsigned int)'''
    ...
    def setPrintableBoundsWeight (self, *args, **kwargs)-> None :
      '''setPrintableBoundsWeight( (PlotInfoValidator)arg1, (SubentType)arg2) -> None :

    C++ signature :
        void setPrintableBoundsWeight(class PyPlPlotInfoValidator {lvalue},unsigned int)'''
    ...
    def setSheetDimensionalWeight (self, *args, **kwargs)-> None :
      '''setSheetDimensionalWeight( (PlotInfoValidator)arg1, (SubentType)arg2) -> None :

    C++ signature :
        void setSheetDimensionalWeight(class PyPlPlotInfoValidator {lvalue},unsigned int)'''
    ...
    def setSheetMediaGroupWeight (self, *args, **kwargs)-> None :
      '''setSheetMediaGroupWeight( (PlotInfoValidator)arg1, (SubentType)arg2) -> None :

    C++ signature :
        void setSheetMediaGroupWeight(class PyPlPlotInfoValidator {lvalue},unsigned int)'''
    ...
    def sheetDimensionalWeight (self, *args, **kwargs)-> int :
      '''sheetDimensionalWeight( (PlotInfoValidator)arg1) -> int :

    C++ signature :
        unsigned int sheetDimensionalWeight(class PyPlPlotInfoValidator {lvalue})'''
    ...
    def sheetMediaGroupWeight (self, *args, **kwargs)-> int :
      '''sheetMediaGroupWeight( (PlotInfoValidator)arg1) -> int :

    C++ signature :
        unsigned int sheetMediaGroupWeight(class PyPlPlotInfoValidator {lvalue})'''
    ...
    def validate (self, *args, **kwargs)-> None :
      '''validate( (PlotInfoValidator)arg1, (PlotInfo)arg2) -> None :

    C++ signature :
        void validate(class PyPlPlotInfoValidator {lvalue},class PyPlPlotInfo {lvalue})'''
    ...

class PlotMSGIndex:
    def __init__ (self, /, *args, **kwargs) :
      '''Initialize self.  See help(type(self)) for accurate signature.'''
    ...
    def as_integer_ratio (self, /) :
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
    def bit_count (self, /) :
      '''Number of ones in the binary representation of the absolute value of self.

Also known as the population count.

>>> bin(13)
'0b1101'
>>> (13).bit_count()
3'''
    ...
    def bit_length (self, /) :
      '''Number of bits necessary to represent self in binary.

>>> bin(37)
'0b100101'
>>> (37).bit_length()
6'''
    ...
    def conjugate (self, *args, **kwargs)-> None :
      '''Returns self, the complex conjugate of any int.'''
    ...
    def denominator (self, *args, **kwargs)-> None :
      '''the denominator of a rational number in lowest terms'''
    ...
    def from_bytes (bytes, byteorder, *, signed=False) :
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
    def imag (self, *args, **kwargs)-> None :
      '''the imaginary part of a complex number'''
    ...
    def kCancelJobBtnMsg (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def kCancelSheetBtnMsg (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def kDialogTitle (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def kMsgCancelling (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def kMsgCancellingCurrent (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def kMsgCount (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def kSheetName (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def kSheetNameToolTip (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def kSheetProgressCaption (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def kSheetSetProgressCaption (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def kStatus (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def name (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def names (self, *args, **kwargs)-> new empty dictionary
dict(mapping) -> new dictionary initialized from a mapping object's
    (key, value) pairs
dict(iterable) -> new dictionary initialized as if via :
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
    def numerator (self, *args, **kwargs)-> None :
      '''the numerator of a rational number in lowest terms'''
    ...
    def real (self, *args, **kwargs)-> None :
      '''the real part of a complex number'''
    ...
    def to_bytes (self, /, length, byteorder, *, signed=False) :
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
    def values (self, *args, **kwargs)-> new empty dictionary
dict(mapping) -> new dictionary initialized from a mapping object's
    (key, value) pairs
dict(iterable) -> new dictionary initialized as if via :
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

class PlotPageInfo:
    def __init__ (self, *args, **kwargs)-> None :
      '''__init__( (object)arg1) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64)'''
    ...
    def className ()-> str :
      '''                             '''
    ...
    def copyFrom (self: RxObject,other:PyRx.RxObject)-> None :
      '''                             '''
    ...
    def desc ()-> PyRx.RxClass :
      '''                             '''
    ...
    def dispose (self: RxObject)-> None :
      '''                             '''
    ...
    def entityCount ()-> int :
      '''                             '''
    ...
    def gradientCount ()-> int :
      '''                             '''
    ...
    def implRefCount (self: RxObject)-> int :
      '''                             '''
    ...
    def isA (self: RxObject)-> PyRx.RxClass :
      '''                             '''
    ...
    def isKindOf (self: RxObject,rhs:PyRx.RxClass)-> bool :
      '''                             '''
    ...
    def isNullObj (self: RxObject)-> bool :
      '''                             '''
    ...
    def keepAlive (self: RxObject,flag:bool)-> None :
      '''                             '''
    ...
    def oleObjectCount ()-> int :
      '''                             '''
    ...
    def queryX (self: RxObject,rhs:PyRx.RxClass)-> PyRx.RxObject :
      '''                             '''
    ...
    def rasterCount ()-> int :
      '''                             '''
    ...
    def shadedViewportType ()-> int :
      '''                             '''
    ...

class PlotProgressDialog:
    def __init__ (self, *args, **kwargs)-> None :
      '''__init__( (object)arg1) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64)

__init__( (object)arg1) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64)

__init__( (object)arg1, (bool)arg2, (int)arg3, (bool)arg4) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64,bool,int,bool)

__init__( (object)arg1, (int)arg2, (bool)arg3, (int)arg4, (bool)arg5) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64,unsigned __int64,bool,int,bool)'''
    ...
    def className ()-> str :
      '''                             '''
    ...
    def destroy (self, *args, **kwargs)-> None :
      '''destroy( (PlotProgressDialog)arg1) -> None :

    C++ signature :
        void destroy(class PyPlPlotProgressDialog {lvalue})'''
    ...
    def getPlotMsgString (self, *args, **kwargs)-> str :
      '''getPlotMsgString( (PlotProgressDialog)arg1, (PlotMSGIndex)arg2) -> str :

    C++ signature :
        class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> > getPlotMsgString(class PyPlPlotProgressDialog {lvalue},enum AcPlPlotProgressDialog::PlotMSGIndex)'''
    ...
    def getPlotProgressRange (self, *args, **kwargs)-> tuple :
      '''getPlotProgressRange( (PlotProgressDialog)arg1) -> tuple :

    C++ signature :
        class boost::python::tuple getPlotProgressRange(class PyPlPlotProgressDialog {lvalue})'''
    ...
    def getSheetProgressRange (self, *args, **kwargs)-> tuple :
      '''getSheetProgressRange( (PlotProgressDialog)arg1) -> tuple :

    C++ signature :
        class boost::python::tuple getSheetProgressRange(class PyPlPlotProgressDialog {lvalue})'''
    ...
    def getStatusMsgString (self, *args, **kwargs)-> str :
      '''getStatusMsgString( (PlotProgressDialog)arg1) -> str :

    C++ signature :
        class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> > getStatusMsgString(class PyPlPlotProgressDialog {lvalue})'''
    ...
    def heartbeat (self, *args, **kwargs)-> None :
      '''heartbeat( (PlotProgressDialog)arg1) -> None :

    C++ signature :
        void heartbeat(class PyPlPlotProgressDialog {lvalue})'''
    ...
    def isPlotCancelled (self, *args, **kwargs)-> bool :
      '''isPlotCancelled( (PlotProgressDialog)arg1) -> bool :

    C++ signature :
        bool isPlotCancelled(class PyPlPlotProgressDialog {lvalue})'''
    ...
    def isSheetCancelled (self, *args, **kwargs)-> bool :
      '''isSheetCancelled( (PlotProgressDialog)arg1) -> bool :

    C++ signature :
        bool isSheetCancelled(class PyPlPlotProgressDialog {lvalue})'''
    ...
    def isSingleSheetPlot (self, *args, **kwargs)-> bool :
      '''isSingleSheetPlot( (PlotProgressDialog)arg1) -> bool :

    C++ signature :
        bool isSingleSheetPlot(class PyPlPlotProgressDialog {lvalue})'''
    ...
    def isVisible (self, *args, **kwargs)-> bool :
      '''isVisible( (PlotProgressDialog)arg1) -> bool :

    C++ signature :
        bool isVisible(class PyPlPlotProgressDialog {lvalue})'''
    ...
    def onBeginPlot (self, *args, **kwargs)-> bool :
      '''onBeginPlot( (PlotProgressDialog)arg1) -> bool :

    C++ signature :
        bool onBeginPlot(class PyPlPlotProgressDialog {lvalue})'''
    ...
    def onBeginSheet (self, *args, **kwargs)-> bool :
      '''onBeginSheet( (PlotProgressDialog)arg1) -> bool :

    C++ signature :
        bool onBeginSheet(class PyPlPlotProgressDialog {lvalue})'''
    ...
    def onEndPlot (self, *args, **kwargs)-> bool :
      '''onEndPlot( (PlotProgressDialog)arg1) -> bool :

    C++ signature :
        bool onEndPlot(class PyPlPlotProgressDialog {lvalue})'''
    ...
    def onEndSheet (self, *args, **kwargs)-> bool :
      '''onEndSheet( (PlotProgressDialog)arg1) -> bool :

    C++ signature :
        bool onEndSheet(class PyPlPlotProgressDialog {lvalue})'''
    ...
    def plotCancelStatus (self, *args, **kwargs)-> PyPl.PlotCancelStatus :
      '''plotCancelStatus( (PlotProgressDialog)arg1) -> PlotCancelStatus :

    C++ signature :
        enum AcPlPlotProgress::PlotCancelStatus plotCancelStatus(class PyPlPlotProgressDialog {lvalue})'''
    ...
    def plotProgressPos (self, *args, **kwargs)-> int :
      '''plotProgressPos( (PlotProgressDialog)arg1) -> int :

    C++ signature :
        int plotProgressPos(class PyPlPlotProgressDialog {lvalue})'''
    ...
    def setIsVisible (self, *args, **kwargs)-> bool :
      '''setIsVisible( (PlotProgressDialog)arg1, (bool)arg2) -> bool :

    C++ signature :
        bool setIsVisible(class PyPlPlotProgressDialog {lvalue},bool)'''
    ...
    def setPlotCancelStatus (self, *args, **kwargs)-> None :
      '''setPlotCancelStatus( (PlotProgressDialog)arg1, (PlotCancelStatus)arg2) -> None :

    C++ signature :
        void setPlotCancelStatus(class PyPlPlotProgressDialog {lvalue},enum AcPlPlotProgress::PlotCancelStatus)'''
    ...
    def setPlotMsgString (self, *args, **kwargs)-> bool :
      '''setPlotMsgString( (PlotProgressDialog)arg1, (PlotMSGIndex)arg2, (str)arg3) -> bool :

    C++ signature :
        bool setPlotMsgString(class PyPlPlotProgressDialog {lvalue},enum AcPlPlotProgressDialog::PlotMSGIndex,class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >)'''
    ...
    def setPlotProgressPos (self, *args, **kwargs)-> None :
      '''setPlotProgressPos( (PlotProgressDialog)arg1, (int)arg2) -> None :

    C++ signature :
        void setPlotProgressPos(class PyPlPlotProgressDialog {lvalue},int)'''
    ...
    def setPlotProgressRange (self, *args, **kwargs)-> None :
      '''setPlotProgressRange( (PlotProgressDialog)arg1, (int)arg2, (int)arg3) -> None :

    C++ signature :
        void setPlotProgressRange(class PyPlPlotProgressDialog {lvalue},int,int)'''
    ...
    def setSheetCancelStatus (self, *args, **kwargs)-> None :
      '''setSheetCancelStatus( (PlotProgressDialog)arg1, (SheetCancelStatus)arg2) -> None :

    C++ signature :
        void setSheetCancelStatus(class PyPlPlotProgressDialog {lvalue},enum AcPlPlotProgress::SheetCancelStatus)'''
    ...
    def setSheetProgressPos (self, *args, **kwargs)-> None :
      '''setSheetProgressPos( (PlotProgressDialog)arg1, (int)arg2) -> None :

    C++ signature :
        void setSheetProgressPos(class PyPlPlotProgressDialog {lvalue},int)'''
    ...
    def setSheetProgressRange (self, *args, **kwargs)-> None :
      '''setSheetProgressRange( (PlotProgressDialog)arg1, (int)arg2, (int)arg3) -> None :

    C++ signature :
        void setSheetProgressRange(class PyPlPlotProgressDialog {lvalue},int,int)'''
    ...
    def setStatusMsgString (self, *args, **kwargs)-> bool :
      '''setStatusMsgString( (PlotProgressDialog)arg1, (str)arg2) -> bool :

    C++ signature :
        bool setStatusMsgString(class PyPlPlotProgressDialog {lvalue},class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >)'''
    ...
    def sheetCancelStatus (self, *args, **kwargs)-> PyPl.SheetCancelStatus :
      '''sheetCancelStatus( (PlotProgressDialog)arg1) -> SheetCancelStatus :

    C++ signature :
        enum AcPlPlotProgress::SheetCancelStatus sheetCancelStatus(class PyPlPlotProgressDialog {lvalue})'''
    ...
    def sheetProgressPos (self, *args, **kwargs)-> int :
      '''sheetProgressPos( (PlotProgressDialog)arg1) -> int :

    C++ signature :
        int sheetProgressPos(class PyPlPlotProgressDialog {lvalue})'''
    ...

class ProcessPlotState:
    def __init__ (self, /, *args, **kwargs) :
      '''Initialize self.  See help(type(self)) for accurate signature.'''
    ...
    def as_integer_ratio (self, /) :
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
    def bit_count (self, /) :
      '''Number of ones in the binary representation of the absolute value of self.

Also known as the population count.

>>> bin(13)
'0b1101'
>>> (13).bit_count()
3'''
    ...
    def bit_length (self, /) :
      '''Number of bits necessary to represent self in binary.

>>> bin(37)
'0b100101'
>>> (37).bit_length()
6'''
    ...
    def conjugate (self, *args, **kwargs)-> None :
      '''Returns self, the complex conjugate of any int.'''
    ...
    def denominator (self, *args, **kwargs)-> None :
      '''the denominator of a rational number in lowest terms'''
    ...
    def from_bytes (bytes, byteorder, *, signed=False) :
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
    def imag (self, *args, **kwargs)-> None :
      '''the imaginary part of a complex number'''
    ...
    def kBackgroundPlotting (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def kForegroundPlotting (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def kNotPlotting (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def name (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def names (self, *args, **kwargs)-> new empty dictionary
dict(mapping) -> new dictionary initialized from a mapping object's
    (key, value) pairs
dict(iterable) -> new dictionary initialized as if via :
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
    def numerator (self, *args, **kwargs)-> None :
      '''the numerator of a rational number in lowest terms'''
    ...
    def real (self, *args, **kwargs)-> None :
      '''the real part of a complex number'''
    ...
    def to_bytes (self, /, length, byteorder, *, signed=False) :
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
    def values (self, *args, **kwargs)-> new empty dictionary
dict(mapping) -> new dictionary initialized from a mapping object's
    (key, value) pairs
dict(iterable) -> new dictionary initialized as if via :
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

class SheetCancelStatus:
    def __init__ (self, /, *args, **kwargs) :
      '''Initialize self.  See help(type(self)) for accurate signature.'''
    ...
    def as_integer_ratio (self, /) :
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
    def bit_count (self, /) :
      '''Number of ones in the binary representation of the absolute value of self.

Also known as the population count.

>>> bin(13)
'0b1101'
>>> (13).bit_count()
3'''
    ...
    def bit_length (self, /) :
      '''Number of bits necessary to represent self in binary.

>>> bin(37)
'0b100101'
>>> (37).bit_length()
6'''
    ...
    def conjugate (self, *args, **kwargs)-> None :
      '''Returns self, the complex conjugate of any int.'''
    ...
    def denominator (self, *args, **kwargs)-> None :
      '''the denominator of a rational number in lowest terms'''
    ...
    def from_bytes (bytes, byteorder, *, signed=False) :
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
    def imag (self, *args, **kwargs)-> None :
      '''the imaginary part of a complex number'''
    ...
    def kSheetCancelStatusCount (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def kSheetCanceledByCaller (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def kSheetCanceledByCancelAllButton (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def kSheetCanceledByCancelButton (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def kSheetContinue (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def name (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def names (self, *args, **kwargs)-> new empty dictionary
dict(mapping) -> new dictionary initialized from a mapping object's
    (key, value) pairs
dict(iterable) -> new dictionary initialized as if via :
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
    def numerator (self, *args, **kwargs)-> None :
      '''the numerator of a rational number in lowest terms'''
    ...
    def real (self, *args, **kwargs)-> None :
      '''the real part of a complex number'''
    ...
    def to_bytes (self, /, length, byteorder, *, signed=False) :
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
    def values (self, *args, **kwargs)-> new empty dictionary
dict(mapping) -> new dictionary initialized from a mapping object's
    (key, value) pairs
dict(iterable) -> new dictionary initialized as if via :
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

class __loader__:
    def _ORIGIN (self, *args, **kwargs)-> str
str(bytes_or_buffer[, encoding[, errors]]) -> str

Create a new string object from the given object. If encoding or
errors is specified, then the object must expose a data buffer
that will be decoded using the given encoding and error handler.
Otherwise, returns the result of object.__str__() (if defined)
or repr(object).
encoding defaults to sys.getdefaultencoding().
errors defaults to 'strict' :
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
    def __init__ (self, /, *args, **kwargs) :
      '''Initialize self.  See help(type(self)) for accurate signature.'''
    ...
    def create_module (spec) :
      '''Create a built-in module'''
    ...
    def exec_module (module) :
      '''Exec a built-in module'''
    ...
    def find_module (fullname, path=None) :
      '''Find the built-in module.

        If 'path' is ever specified then the search is considered a failure.

        This method is deprecated.  Use find_spec() instead.

        '''
    ...
    def find_spec (fullname, path=None, target=None) :
      '''None'''
    ...
    def get_code (fullname) :
      '''Return None as built-in modules do not have code objects.'''
    ...
    def get_source (fullname) :
      '''Return None as built-in modules do not have source code.'''
    ...
    def is_package (fullname) :
      '''Return False as built-in modules are never packages.'''
    ...
    def load_module (fullname) :
      '''Load the specified module into sys.modules and return it.

    This method is deprecated.  Use loader.exec_module() instead.

    '''
    ...
    def module_repr (module) :
      '''Return repr for the module.

        The method is deprecated.  The import machinery does the job itself.

        '''
    ...
