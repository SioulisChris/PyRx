#include "stdafx.h"
#include "PyDbMtext.h"
#include "PyDbObjectId.h"
using namespace boost::python;

int AcDbMTextFragmentCallBack(AcDbMTextFragment* frag, void* param);

enum class PyRxMTextFragmentType
{
    kLocation,
    kNormal,
    kDirection,
    kTextValue,
    kFont,
    kBigFont,
    kExtents,
    kCapsHeight,
    kWidthFactor,
    kObliqueAngle,
    kTrackingFactor,
    kColor,
    kStackTop,
    kStackBottom,
    kUnderlined,
    kOverlined,
    kStrikethrough,
    kUnderPoints,
    kOverPoints,
    kStrikePoints,
    kFontname,
    kBold,
    kItalic,
    kEndFragmentTypes,
};

void makePyDbMTextWrapper()
{
    PyDocString DS("MText");
    class_<PyDbMText, bases<PyDbEntity>>("MText")
        .def(init<>())
        .def(init<const PyDbObjectId&>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode, bool>(DS.ARGS({ "id: ObjectId", "mode: PyDb.OpenMode.kForRead", "erased: bool=False" })))
        .def("location", &PyDbMText::location, DS.ARGS(6885))
        .def("setLocation", &PyDbMText::setLocation, DS.ARGS({ "val : PyGe.Point3d" }, 6916))
        .def("normal", &PyDbMText::normal, DS.ARGS(6887))
        .def("setNormal", &PyDbMText::setNormal, DS.ARGS({ "val : PyGe.Vector3d" }, 6917))
        .def("direction", &PyDbMText::direction, DS.ARGS(6859))
        .def("setDirection", &PyDbMText::setDirection, DS.ARGS({ "val : PyGe.Vector3d" }, 6909))
        .def("rotation", &PyDbMText::rotation, DS.ARGS(6893))
        .def("setRotation", &PyDbMText::setRotation, DS.ARGS({ "val : float" }, 6918))
        .def("width", &PyDbMText::width, DS.ARGS(6939))
        .def("setWidth", &PyDbMText::setWidth, DS.ARGS({ "val : float" }, 6925))
        .def("ascent", &PyDbMText::ascent, DS.ARGS(6846))
        .def("descent", &PyDbMText::descent, DS.ARGS(6858))
        .def("textStyle", &PyDbMText::textStyle, DS.ARGS(6933))
        .def("setTextStyle", &PyDbMText::setTextStyle, DS.ARGS({ "val : PyDb.ObjectId" }, 6922))
        .def("textHeight", &PyDbMText::textHeight, DS.ARGS(6932))
        .def("setTextHeight", &PyDbMText::setTextHeight, DS.ARGS({ "val : float" }, 6921))
        .def("attachment", &PyDbMText::attachment, DS.ARGS(6847))
        .def("setAttachment", &PyDbMText::setAttachment, DS.ARGS({ "val : PyDb.MTextAttachmentPoint" }, 6894))
        .def("setAttachmentMovingLocation", &PyDbMText::setAttachmentMovingLocation, DS.ARGS({ "val: PyDb.MTextAttachmentPoint" }, 6895))
        .def("flowDirection", &PyDbMText::flowDirection, DS.ARGS(6861))
        .def("setFlowDirection", &PyDbMText::setFlowDirection, DS.ARGS({ "val : PyDb.MTextFlowDirection" }, 6912))
        .def("contents", &PyDbMText::contents, DS.ARGS(6854))
        .def("setContents", &PyDbMText::setContents, DS.ARGS({ "val : str" }, 6907))
        .def("contentsRTF", &PyDbMText::contentsRTF, DS.ARGS(6855))
        .def("setContentsRTF", &PyDbMText::setContentsRTF, DS.ARGS({ "val : str" }, 6908))
        .def("text", &PyDbMText::text, DS.ARGS(6931))
        .def("actualHeight", &PyDbMText::actualHeight, DS.ARGS(6843))
        .def("actualWidth", &PyDbMText::actualWidth, DS.ARGS(6844))
        .def("correctSpelling", &PyDbMText::correctSpelling, DS.ARGS(6857))
        .def("getBoundingPoints", &PyDbMText::getBoundingPoints, DS.ARGS(6867))
        .def("getBoundingPointsByLine", &PyDbMText::getBoundingPointsByLine, DS.ARGS(6868))
        .def("hitTest", &PyDbMText::hitTest, DS.ARGS({ "val : PyGe.Point3d" }, 6880))
        .def("setLineSpacingStyle", &PyDbMText::setLineSpacingStyle, DS.ARGS({ "val : PyDb.LineSpacingStyle" }, 6915))
        .def("lineSpacingStyle", &PyDbMText::lineSpacingStyle, DS.ARGS(6884))
        .def("setLineSpacingFactor", &PyDbMText::setLineSpacingFactor, DS.ARGS({ "val : float" }, 6914))
        .def("lineSpacingFactor", &PyDbMText::lineSpacingFactor, DS.ARGS(6883))
        .def("backgroundFillOn", &PyDbMText::backgroundFillOn, DS.ARGS(6849))
        .def("setBackgroundFill", &PyDbMText::setBackgroundFill, DS.ARGS({ "val : bool" }, 6896))
        .def("getBackgroundFillColor", &PyDbMText::getBackgroundFillColor, DS.ARGS(6864))
        .def("setBackgroundFillColor", &PyDbMText::setBackgroundFillColor, DS.ARGS({ "val : PyDb.AcCmColor" }, 6897))
        .def("getBackgroundScaleFactor", &PyDbMText::getBackgroundScaleFactor, DS.ARGS(6865))
        .def("setBackgroundScaleFactor", &PyDbMText::setBackgroundScaleFactor, DS.ARGS({ "val : float" }, 6898))
        .def("getBackgroundTransparency", &PyDbMText::getBackgroundTransparency, DS.ARGS(6866))
        .def("setBackgroundTransparency", &PyDbMText::setBackgroundTransparency, DS.ARGS({ "val : PyDb.AcCmTransparency" }, 6899))
        .def("useBackgroundColorOn", &PyDbMText::useBackgroundColorOn, DS.ARGS(6937))
        .def("setUseBackgroundColor", &PyDbMText::setUseBackgroundColor, DS.ARGS({ "val : bool" }, 6923))
        .def("setDynamicColumns", &PyDbMText::setDynamicColumns, DS.ARGS({ "width : float","gutter : float","autoHeight : bool" }, 6910))
        .def("setStaticColumns", &PyDbMText::setStaticColumns, DS.ARGS({ "width : float","gutter : float","count : int" }, 6920))
        .def("getColumnType", &PyDbMText::getColumnType, DS.ARGS(6874))
        .def("setColumnType", &PyDbMText::setColumnType, DS.ARGS({ "val : PyDb.MTextColumnType" }, 6905))
        .def("getColumnAutoHeight", &PyDbMText::getColumnAutoHeight, DS.ARGS(6869))
        .def("setColumnAutoHeight", &PyDbMText::setColumnAutoHeight, DS.ARGS({ "val : bool" }, 6900))
        .def("getColumnCount", &PyDbMText::getColumnCount, DS.ARGS(6900))
        .def("setColumnCount", &PyDbMText::setColumnCount, DS.ARGS({ "val : int" }, 6901))
        .def("getColumnWidth", &PyDbMText::getColumnWidth, DS.ARGS(6875))
        .def("setColumnWidth", &PyDbMText::setColumnWidth, DS.ARGS({ "val : float" }, 6906))
        .def("getColumnGutterWidth", &PyDbMText::getColumnGutterWidth, DS.ARGS(6872))
        .def("setColumnGutterWidth", &PyDbMText::setColumnGutterWidth, DS.ARGS({ "val : float" }, 6903))
        .def("getColumnFlowReversed", &PyDbMText::getColumnFlowReversed, DS.ARGS(6871))
        .def("setColumnFlowReversed", &PyDbMText::setColumnFlowReversed, DS.ARGS({ "val : bool" }, 6902))
        .def("getColumnHeight", &PyDbMText::getColumnHeight, DS.ARGS({ "idx : int" }, 6873))
        .def("setColumnHeight", &PyDbMText::setColumnHeight, DS.ARGS({ "idx : int", "val : float" }, 6904))
        .def("convertFieldToText", &PyDbMText::convertFieldToText, DS.ARGS(6856))
        .def("height", &PyDbMText::height, DS.ARGS(6878))
        .def("setHeight", &PyDbMText::setHeight, DS.ARGS({ "val : float" }, 6913))
        .def("getFragments", &PyDbMText::getFragments, DS.ARGS(6860))
        .def("className", &PyDbMText::className, DS.SARGS()).staticmethod("className")
        .def("desc", &PyDbMText::desc, DS.SARGS(15560)).staticmethod("desc")
        .def("cloneFrom", &PyDbMText::cloneFrom, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cloneFrom")
        .def("cast", &PyDbMText::cast, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cast")
        ;

    enum_<AcDbMText::AttachmentPoint>("MTextAttachmentPoint")
        .value("kTopLeft", AcDbMText::AttachmentPoint::kTopLeft)
        .value("kTopCenter", AcDbMText::AttachmentPoint::kTopCenter)
        .value("kTopRight", AcDbMText::AttachmentPoint::kTopRight)
        .value("kMiddleLeft", AcDbMText::AttachmentPoint::kMiddleLeft)
        .value("kMiddleCenter", AcDbMText::AttachmentPoint::kMiddleCenter)
        .value("kMiddleRight", AcDbMText::AttachmentPoint::kMiddleRight)
        .value("kBottomLeft", AcDbMText::AttachmentPoint::kBottomLeft)
        .value("kBottomCenter", AcDbMText::AttachmentPoint::kBottomCenter)
        .value("kBottomRight", AcDbMText::AttachmentPoint::kBottomRight)
        .value("kBaseLeft", AcDbMText::AttachmentPoint::kBaseLeft)
        .value("kBaseCenter", AcDbMText::AttachmentPoint::kBaseCenter)
        .value("kBaseRight", AcDbMText::AttachmentPoint::kBaseRight)
        .value("kBaseAlign", AcDbMText::AttachmentPoint::kBaseAlign)
        .value("kBottomAlign", AcDbMText::AttachmentPoint::kBottomAlign)
        .value("kMiddleAlign", AcDbMText::AttachmentPoint::kMiddleAlign)
        .value("kTopAlign", AcDbMText::AttachmentPoint::kTopAlign)
        .value("kBaseFit", AcDbMText::AttachmentPoint::kBaseFit)
        .value("kBottomFit", AcDbMText::AttachmentPoint::kBottomFit)
        .value("kMiddleFit", AcDbMText::AttachmentPoint::kMiddleFit)
        .value("kTopFit", AcDbMText::AttachmentPoint::kTopFit)
        .value("kBaseMid", AcDbMText::AttachmentPoint::kBaseMid)
        .value("kBottomMid", AcDbMText::AttachmentPoint::kBottomMid)
        .value("kMiddleMid", AcDbMText::AttachmentPoint::kMiddleMid)
        .value("kTopMid", AcDbMText::AttachmentPoint::kTopMid)
        .export_values()
        ;
    enum_<AcDbMText::FlowDirection>("MTextFlowDirection")
        .value("kLtoR", AcDbMText::FlowDirection::kLtoR)
        .value("kRtoL", AcDbMText::FlowDirection::kRtoL)
        .value("kTtoB", AcDbMText::FlowDirection::kTtoB)
        .value("kBtoT", AcDbMText::FlowDirection::kBtoT)
        .value("kByStyle", AcDbMText::FlowDirection::kByStyle)
        .export_values()
        ;
    enum_<AcDbMText::ColumnType>("MTextColumnType")
        .value("kNoColumns", AcDbMText::ColumnType::kNoColumns)
        .value("kStaticColumns", AcDbMText::ColumnType::kStaticColumns)
        .value("kDynamicColumns", AcDbMText::ColumnType::kDynamicColumns)
        .export_values()
        ;

    enum_<PyRxMTextFragmentType>("MTextFragmentType")
        .value("kLocation", PyRxMTextFragmentType::kLocation)
        .value("kNormal", PyRxMTextFragmentType::kNormal)
        .value("kDirection", PyRxMTextFragmentType::kDirection)
        .value("kTextValue", PyRxMTextFragmentType::kTextValue)
        .value("kFont", PyRxMTextFragmentType::kFont)
        .value("kBigFont", PyRxMTextFragmentType::kBigFont)
        .value("kExtents", PyRxMTextFragmentType::kExtents)
        .value("kCapsHeight", PyRxMTextFragmentType::kCapsHeight)
        .value("kWidthFactor", PyRxMTextFragmentType::kWidthFactor)
        .value("kObliqueAngle", PyRxMTextFragmentType::kObliqueAngle)
        .value("kTrackingFactor", PyRxMTextFragmentType::kTrackingFactor)
        .value("kColor", PyRxMTextFragmentType::kColor)
        .value("kStackTop", PyRxMTextFragmentType::kStackTop)
        .value("kStackBottom", PyRxMTextFragmentType::kStackBottom)
        .value("kUnderlined", PyRxMTextFragmentType::kUnderlined)
        .value("kOverlined", PyRxMTextFragmentType::kOverlined)
        .value("kStrikethrough", PyRxMTextFragmentType::kStrikethrough)
        .value("kUnderPoints", PyRxMTextFragmentType::kUnderPoints)
        .value("kOverPoints", PyRxMTextFragmentType::kOverPoints)
        .value("kStrikePoints", PyRxMTextFragmentType::kStrikePoints)
        .value("kFontname", PyRxMTextFragmentType::kFontname)
        .value("kBold", PyRxMTextFragmentType::kBold)
        .value("kItalic", PyRxMTextFragmentType::kItalic)
        .value("kEndFragmentTypes", PyRxMTextFragmentType::kEndFragmentTypes)
        .export_values()
        ;
}

PyDbMText::PyDbMText()
    : PyDbMText::PyDbMText(new AcDbMText(), true)
{
}

PyDbMText::PyDbMText(AcDbMText* ptr, bool autoDelete)
    : PyDbEntity(ptr, autoDelete)
{
}

PyDbMText::PyDbMText(const PyDbObjectId& id)
    : PyDbMText(openAcDbObject<AcDbMText>(id, AcDb::OpenMode::kForRead), false)
{
}

PyDbMText::PyDbMText(const PyDbObjectId& id, AcDb::OpenMode mode)
    : PyDbEntity(openAcDbObject<AcDbMText>(id, mode), false)
{
}

PyDbMText::PyDbMText(const PyDbObjectId& id, AcDb::OpenMode mode, bool erased)
    : PyDbEntity(openAcDbObject<AcDbMText>(id, mode), erased)
{
}

AcGePoint3d PyDbMText::location() const
{
    return impObj()->location();
}

void PyDbMText::setLocation(const AcGePoint3d& val)
{
    return PyThrowBadEs(impObj()->setLocation(val));
}

AcGeVector3d PyDbMText::normal() const
{
    return impObj()->normal();
}

void PyDbMText::setNormal(const AcGeVector3d& val)
{
    return PyThrowBadEs(impObj()->setNormal(val));
}

AcGeVector3d PyDbMText::direction() const
{
    return impObj()->direction();
}

void PyDbMText::setDirection(const AcGeVector3d& val)
{
    return PyThrowBadEs(impObj()->setDirection(val));
}

double PyDbMText::rotation() const
{
    return impObj()->rotation();
}

void PyDbMText::setRotation(double val)
{
    return PyThrowBadEs(impObj()->setRotation(val));
}

double PyDbMText::width() const
{
    return impObj()->width();
}

void PyDbMText::setWidth(double val)
{
    return PyThrowBadEs(impObj()->setWidth(val));
}

double PyDbMText::ascent() const
{
    return impObj()->ascent();
}

double PyDbMText::descent() const
{
    return impObj()->descent();
}

PyDbObjectId PyDbMText::textStyle() const
{
    return PyDbObjectId(impObj()->textStyle());
}

void PyDbMText::setTextStyle(const PyDbObjectId& val)
{
    return PyThrowBadEs(impObj()->setTextStyle(val.m_id));
}

double PyDbMText::textHeight() const
{
    return impObj()->textHeight();
}

void PyDbMText::setTextHeight(double val)
{
    return PyThrowBadEs(impObj()->setTextHeight(val));
}

AcDbMText::AttachmentPoint PyDbMText::attachment() const
{
    return impObj()->attachment();
}

void PyDbMText::setAttachment(AcDbMText::AttachmentPoint val)
{
    return PyThrowBadEs(impObj()->setAttachment(val));
}

void PyDbMText::setAttachmentMovingLocation(AcDbMText::AttachmentPoint val)
{
    return PyThrowBadEs(impObj()->setAttachmentMovingLocation(val));
}

AcDbMText::FlowDirection PyDbMText::flowDirection() const
{
    return impObj()->flowDirection();
}

void PyDbMText::setFlowDirection(AcDbMText::FlowDirection val)
{
    return PyThrowBadEs(impObj()->setFlowDirection(val));
}

std::string PyDbMText::contents() const
{
    AcString str;
    PyThrowBadEs(impObj()->contents(str));
    return wstr_to_utf8(str);
}

int PyDbMText::setContents(const std::string& str)
{
    return impObj()->setContents(utf8_to_wstr(str).c_str());
}

std::string PyDbMText::contentsRTF() const
{
    AcString str;
    PyThrowBadEs(impObj()->contentsRTF(str));
    return wstr_to_utf8(str);
}

int PyDbMText::setContentsRTF(const std::string& str)
{
    return impObj()->setContentsRTF(utf8_to_wstr(str).c_str());
}

std::string PyDbMText::text() const
{
    AcString str;
    PyThrowBadEs(impObj()->text(str));
    return wstr_to_utf8(str);
}

double PyDbMText::actualHeight() const
{
    return impObj()->actualHeight();
}

double PyDbMText::actualWidth() const
{
    return impObj()->actualWidth();
}

int PyDbMText::correctSpelling()
{
#if defined(_BRXTARGET) && _BRXTARGET <= 240
    throw PyNotimplementedByHost();
#else
    return impObj()->correctSpelling();
#endif
}

boost::python::list PyDbMText::getBoundingPoints() const
{
    AcGePoint3dArray arr;
    impObj()->getBoundingPoints(arr);
    return Point3dArrayToPyList(arr);
}

boost::python::list PyDbMText::getBoundingPointsByLine() const
{
#if _ZRXTARGET == 240 || _GRXTARGET == 240 || _BRXTARGET == 240
    throw PyNotimplementedByHost();
#else
    PyAutoLockGIL lock;
    AcArray<AcGePoint3dArray> data;
    impObj()->getBoundingPointsByLine(data);
    boost::python::list pylist;
    for (const auto& item : data)
        pylist.append(Point3dArrayToPyList(item));
    return pylist;
#endif
}

bool PyDbMText::hitTest(const AcGePoint3d& ptHit) const
{
#if _ZRXTARGET == 240 || _GRXTARGET == 240 || _BRXTARGET == 240
    throw PyNotimplementedByHost();
#else
    return impObj()->hitTest(ptHit);
#endif
}

void PyDbMText::setLineSpacingStyle(AcDb::LineSpacingStyle eStyle)
{
    return PyThrowBadEs(impObj()->setLineSpacingStyle(eStyle));
}

AcDb::LineSpacingStyle PyDbMText::lineSpacingStyle() const
{
    return impObj()->lineSpacingStyle();
}

void PyDbMText::setLineSpacingFactor(double dFactor)
{
    return PyThrowBadEs(impObj()->setLineSpacingFactor(dFactor));
}

double PyDbMText::lineSpacingFactor() const
{
    return impObj()->lineSpacingFactor();
}

bool PyDbMText::backgroundFillOn() const
{
    return impObj()->backgroundFillOn();
}

void PyDbMText::setBackgroundFill(bool enable)
{
    return PyThrowBadEs(impObj()->setBackgroundFill(enable));
}

AcCmColor PyDbMText::getBackgroundFillColor() const
{
    AcCmColor clr;
    PyThrowBadEs(impObj()->getBackgroundFillColor(clr));
    return clr;
}

void PyDbMText::setBackgroundFillColor(const AcCmColor& color)
{
    return PyThrowBadEs(impObj()->setBackgroundFillColor(color));
}

double PyDbMText::getBackgroundScaleFactor() const
{
    double val;
    PyThrowBadEs(impObj()->getBackgroundScaleFactor(val));
    return val;
}

void PyDbMText::setBackgroundScaleFactor(const double scale)
{
    return PyThrowBadEs(impObj()->setBackgroundScaleFactor(scale));
}

AcCmTransparency PyDbMText::getBackgroundTransparency() const
{
    AcCmTransparency val;
    PyThrowBadEs(impObj()->getBackgroundTransparency(val));
    return val;
}

void PyDbMText::setBackgroundTransparency(const AcCmTransparency& transp)
{
    return PyThrowBadEs(impObj()->setBackgroundTransparency(transp));
}

bool PyDbMText::useBackgroundColorOn() const
{
    return impObj()->useBackgroundColorOn();
}

void PyDbMText::setUseBackgroundColor(bool enable)
{
    return PyThrowBadEs(impObj()->setUseBackgroundColor(enable));
}

void PyDbMText::setDynamicColumns(double width, double gutter, bool auto_height)
{
    return PyThrowBadEs(impObj()->setDynamicColumns(width, gutter, auto_height));
}

void PyDbMText::setStaticColumns(double width, double gutter, int count)
{
    return PyThrowBadEs(impObj()->setStaticColumns(width, gutter, count));
}

AcDbMText::ColumnType PyDbMText::getColumnType() const
{
    AcDbMText::ColumnType  val;
    PyThrowBadEs(impObj()->getColumnType(val));
    return val;
}

void PyDbMText::setColumnType(AcDbMText::ColumnType val)
{
    return PyThrowBadEs(impObj()->setUseBackgroundColor(val));
}

bool PyDbMText::getColumnAutoHeight() const
{
    bool  val;
    PyThrowBadEs(impObj()->getColumnAutoHeight(val));
    return val;
}

void PyDbMText::setColumnAutoHeight(bool val)
{
    return PyThrowBadEs(impObj()->setColumnAutoHeight(val));
}

int PyDbMText::getColumnCount() const
{
    int  val;
    PyThrowBadEs(impObj()->getColumnCount(val));
    return val;
}

void PyDbMText::setColumnCount(int val)
{
    return PyThrowBadEs(impObj()->setColumnCount(val));
}

double PyDbMText::getColumnWidth() const
{
    double  val;
    PyThrowBadEs(impObj()->getColumnWidth(val));
    return val;
}

void PyDbMText::setColumnWidth(double val)
{
    return PyThrowBadEs(impObj()->setColumnWidth(val));
}

double PyDbMText::getColumnGutterWidth() const
{
    double  val;
    PyThrowBadEs(impObj()->getColumnGutterWidth(val));
    return val;
}

void PyDbMText::setColumnGutterWidth(double val)
{
    return PyThrowBadEs(impObj()->setColumnGutterWidth(val));
}

bool PyDbMText::getColumnFlowReversed() const
{
    bool  val;
    PyThrowBadEs(impObj()->getColumnFlowReversed(val));
    return val;
}

void PyDbMText::setColumnFlowReversed(bool val)
{
    return PyThrowBadEs(impObj()->setColumnFlowReversed(val));
}

double PyDbMText::getColumnHeight(int idx) const
{
    double  val;
    PyThrowBadEs(impObj()->getColumnHeight(idx, val));
    return val;
}

void PyDbMText::setColumnHeight(int idx, double val)
{
    return PyThrowBadEs(impObj()->setColumnHeight(idx, val));
}

void PyDbMText::convertFieldToText()
{
#if defined(_BRXTARGET) && _BRXTARGET <= 240
    throw PyNotimplementedByHost();
#else
    return PyThrowBadEs(impObj()->convertFieldToText());
#endif
}

double PyDbMText::height() const
{
    return impObj()->height();
}

void PyDbMText::setHeight(double val)
{
    return PyThrowBadEs(impObj()->setHeight(val));
}

boost::python::list PyDbMText::getFragments()
{
    PyAutoLockGIL lock;
    boost::python::list pylist;
    impObj()->explodeFragments(AcDbMTextFragmentCallBack, &pylist, nullptr);
    return pylist;
}

std::string PyDbMText::className()
{
    return "AcDbMText";
}

PyRxClass PyDbMText::desc()
{
    return PyRxClass(AcDbMText::desc(), false);
}

PyDbMText PyDbMText::cloneFrom(const PyRxObject& src)
{
    if (!src.impObj()->isKindOf(AcDbMText::desc()))
        throw PyAcadErrorStatus(eNotThatKindOfClass);
    return PyDbMText(static_cast<AcDbMText*>(src.impObj()->clone()), true);
}

PyDbMText PyDbMText::cast(const PyRxObject& src)
{
    return PyDbObjectCast<PyDbMText>(src);
}

AcDbMText* PyDbMText::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
        }
    return static_cast<AcDbMText*>(m_pyImp.get());
}

// preserve order!
int AcDbMTextFragmentCallBack(AcDbMTextFragment* frag, void* param)
{
    if (frag != nullptr && param != nullptr)
    {
        PyAutoLockGIL lock;
        boost::python::list* pylist = reinterpret_cast<boost::python::list*>(param);
        boost::python::list pysublist;

        pysublist.append(frag->location);
        pysublist.append(frag->normal);
        pysublist.append(frag->direction);

#if _GRXTARGET > 0 || _ZRXTARGET  > 0 || _BRXTARGET > 0
        if (frag->text != nullptr)
            pysublist.append(wstr_to_utf8(frag->text));
        else
            pysublist.append(boost::python::object());

        if (frag->font != nullptr)
            pysublist.append(wstr_to_utf8(frag->font));
        else
            pysublist.append(boost::python::object());

        if (frag->bigfont != nullptr)
            pysublist.append(wstr_to_utf8(frag->bigfont));
        else
            pysublist.append(boost::python::object());
#else
        if (!frag->msText.isEmpty())
            pysublist.append(wstr_to_utf8(frag->msText));
        else
            pysublist.append(boost::python::object());

        if (!frag->msFont.isEmpty())
            pysublist.append(wstr_to_utf8(frag->msFont));
        else
            pysublist.append(boost::python::object());

        if (!frag->msBigFont.isEmpty())
            pysublist.append(wstr_to_utf8(frag->msBigFont));
        else
            pysublist.append(boost::python::object());
#endif

        pysublist.append(frag->extents);
        pysublist.append(frag->capsHeight);
        pysublist.append(frag->widthFactor);
        pysublist.append(frag->obliqueAngle);
        pysublist.append(frag->trackingFactor);
        pysublist.append(frag->color);
        pysublist.append(frag->stackTop);
        pysublist.append(frag->stackBottom);
        pysublist.append(frag->underlined);
        pysublist.append(frag->overlined);
        pysublist.append(frag->strikethrough);

        boost::python::list underPoints;
        underPoints.append(frag->underPoints[0]);
        underPoints.append(frag->underPoints[1]);
        pysublist.append(underPoints);

        boost::python::list overPoints;
        overPoints.append(frag->overPoints[0]);
        overPoints.append(frag->overPoints[1]);
        pysublist.append(overPoints);

        boost::python::list strikePoints;
        strikePoints.append(frag->strikePoints[0]);
        strikePoints.append(frag->strikePoints[1]);
        pysublist.append(strikePoints);

#if _GRXTARGET > 0 ||_ZRXTARGET > 0 || _BRXTARGET > 0
        if (frag->fontname != nullptr)
            pysublist.append(wstr_to_utf8(frag->fontname));
        else
            pysublist.append(boost::python::object());
#else
        if (!frag->msFontName.isEmpty())
            pysublist.append(wstr_to_utf8(frag->msFontName));
        else
            pysublist.append(boost::python::object());
#endif

        pysublist.append(frag->bold);
        pysublist.append(frag->italic);

        //
        pylist->append(pysublist);
    }
    return 1;
}