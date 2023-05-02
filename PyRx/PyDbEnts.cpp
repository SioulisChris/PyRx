#include "stdafx.h"
#include "PyDbEnts.h"
#include "PyDbObjectId.h"
#include "PyGeLinearEnt2d.h"
#include "PyGeLinearEnt3d.h"
#include "PyGeCurve2d.h"
#include "PyGeCurve3d.h"
#include "PyDbMText.h"

using namespace boost::python;


//-----------------------------------------------------------------------------------
//PyDbText
void makePyDbTextWrapper()
{
    class_<PyDbText, bases<PyDbEntity>>("Text")
        .def(init<>())
        .def(init<AcGePoint3d&, const std::string&>())
        .def(init<AcGePoint3d&, const std::string&, PyDbObjectId&, double, double>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode>())
        .def("position", &PyDbText::position)
        .def("setPosition", &PyDbText::setPosition)
        .def("alignmentPoint", &PyDbText::alignmentPoint)
        .def("setAlignmentPoint", &PyDbText::setAlignmentPoint)
        .def("isDefaultAlignment", &PyDbText::isDefaultAlignment)
        .def("normal", &PyDbText::normal)
        .def("setNormal", &PyDbText::setNormal)
        .def("thickness", &PyDbText::thickness)
        .def("setThickness", &PyDbText::setThickness)
        .def("oblique", &PyDbText::oblique)
        .def("setOblique", &PyDbText::setOblique)
        .def("rotation", &PyDbText::rotation)
        .def("setRotation", &PyDbText::setRotation)
        .def("height", &PyDbText::height)
        .def("setHeight", &PyDbText::setHeight)
        .def("widthFactor", &PyDbText::widthFactor)
        .def("setWidthFactor", &PyDbText::setWidthFactor)
        .def("textString", &PyDbText::textString)
        .def("setTextString", &PyDbText::setTextString)
        .def("textStyle", &PyDbText::textStyle)
        .def("setTextStyle", &PyDbText::setTextStyle)
        .def("isMirroredInX", &PyDbText::isMirroredInX)
        .def("mirrorInX", &PyDbText::mirrorInX)
        .def("isMirroredInY", &PyDbText::isMirroredInY)
        .def("mirrorInY", &PyDbText::mirrorInY)
        .def("horizontalMode", &PyDbText::horizontalMode)
        .def("setHorizontalMode", &PyDbText::setHorizontalMode)
        .def("verticalMode", &PyDbText::verticalMode)
        .def("setVerticalMode", &PyDbText::setVerticalMode)
        .def("correctSpelling", &PyDbText::correctSpelling)
        .def("adjustAlignment", &PyDbText::adjustAlignment)
        .def("convertFieldToText", &PyDbText::convertFieldToText)
        .def("hitTest", &PyDbText::hitTest)
        .def("getBoundingPoints", &PyDbText::getBoundingPoints)
        .def("className", &PyDbText::className).staticmethod("className")
        ;

    enum_<AcDbText::AcTextAlignment>("TextAlignment")
        .value("kTextAlignmentLeft", AcDbText::AcTextAlignment::kTextAlignmentLeft)
        .value("kTextAlignmentCenter", AcDbText::AcTextAlignment::kTextAlignmentCenter)
        .value("kTextAlignmentRight", AcDbText::AcTextAlignment::kTextAlignmentRight)
        .value("kTextAlignmentAligned", AcDbText::AcTextAlignment::kTextAlignmentAligned)
        .value("kTextAlignmentMiddle", AcDbText::AcTextAlignment::kTextAlignmentMiddle)
        .value("kTextAlignmentFit", AcDbText::AcTextAlignment::kTextAlignmentFit)
        .value("kTextAlignmentTopLeft", AcDbText::AcTextAlignment::kTextAlignmentTopLeft)
        .value("kTextAlignmentTopCenter", AcDbText::AcTextAlignment::kTextAlignmentTopCenter)
        .value("kTextAlignmentTopRight", AcDbText::AcTextAlignment::kTextAlignmentTopRight)
        .value("kTextAlignmentMiddleLeft", AcDbText::AcTextAlignment::kTextAlignmentMiddleLeft)
        .value("kTextAlignmentMiddleCenter", AcDbText::AcTextAlignment::kTextAlignmentMiddleCenter)
        .value("kTextAlignmentMiddleRight", AcDbText::AcTextAlignment::kTextAlignmentMiddleRight)
        .value("kTextAlignmentBottomLeft", AcDbText::AcTextAlignment::kTextAlignmentBottomLeft)
        .value("kTextAlignmentBottomCenter", AcDbText::AcTextAlignment::kTextAlignmentBottomCenter)
        .value("kTextAlignmentBottomRight", AcDbText::AcTextAlignment::kTextAlignmentBottomRight)
        .export_values()
        ;
}

PyDbText::PyDbText()
    : PyDbText::PyDbText(new AcDbText(), true)
{
}

PyDbText::PyDbText(const AcGePoint3d& position, const std::string& text)
    : PyDbText::PyDbText(new AcDbText(position, utf8_to_wstr(text).c_str()), true)
{
}

PyDbText::PyDbText(const AcGePoint3d& position, const std::string& text, PyDbObjectId& style, double height, double rotation)
    : PyDbText::PyDbText(new AcDbText(position, utf8_to_wstr(text).c_str(), style.m_id, height, rotation), true)
{
}

PyDbText::PyDbText(AcDbText* ptr, bool autoDelete)
    : PyDbEntity(ptr, autoDelete)
{
}

PyDbText::PyDbText(const PyDbObjectId& id, AcDb::OpenMode mode)
    : PyDbEntity(nullptr, false)
{
    AcDbText* pobj = nullptr;
    if (auto es = acdbOpenObject<AcDbText>(pobj, id.m_id, mode); es != eOk)
        throw PyAcadErrorStatus(es);
    this->resetImp(pobj, false, true);
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
}

AcGePoint3d PyDbText::position() const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->position();
}

Acad::ErrorStatus PyDbText::setPosition(const AcGePoint3d& val)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->setPosition(val);
}

AcGePoint3d PyDbText::alignmentPoint() const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->alignmentPoint();
}

Acad::ErrorStatus PyDbText::setAlignmentPoint(const AcGePoint3d& val)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->setAlignmentPoint(val);
}

Adesk::Boolean PyDbText::isDefaultAlignment() const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->isDefaultAlignment();
}

AcGeVector3d PyDbText::normal() const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->normal();
}

Acad::ErrorStatus PyDbText::setNormal(const AcGeVector3d& val)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->setNormal(val);
}

double PyDbText::thickness() const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->thickness();
}

Acad::ErrorStatus PyDbText::setThickness(double val)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->setThickness(val);
}

double PyDbText::oblique() const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->oblique();
}

Acad::ErrorStatus PyDbText::setOblique(double val)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->setOblique(val);
}

double PyDbText::rotation() const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->rotation();
}

Acad::ErrorStatus PyDbText::setRotation(double val)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->setRotation(val);
}

double PyDbText::height() const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->height();
}

Acad::ErrorStatus PyDbText::setHeight(double val)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->setHeight(val);
}

double PyDbText::widthFactor() const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->widthFactor();
}

Acad::ErrorStatus PyDbText::setWidthFactor(double val)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->setWidthFactor(val);
}

std::string PyDbText::textString() const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return wstr_to_utf8(imp->textStringConst());
}

Acad::ErrorStatus PyDbText::setTextString(std::string& val)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->setTextString(utf8_to_wstr(val).c_str());
}

PyDbObjectId PyDbText::textStyle() const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return PyDbObjectId(imp->textStyle());
}

Acad::ErrorStatus PyDbText::setTextStyle(const PyDbObjectId& val)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->setTextStyle(val.m_id);
}

Adesk::Boolean PyDbText::isMirroredInX() const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->isMirroredInX();
}

Acad::ErrorStatus PyDbText::mirrorInX(Adesk::Boolean val)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->mirrorInX(val);
}

Adesk::Boolean PyDbText::isMirroredInY() const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->isMirroredInY();
}

Acad::ErrorStatus PyDbText::mirrorInY(Adesk::Boolean val)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->mirrorInY(val);
}

AcDb::TextHorzMode PyDbText::horizontalMode() const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->horizontalMode();
}

Acad::ErrorStatus PyDbText::setHorizontalMode(AcDb::TextHorzMode val)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->setHorizontalMode(val);
}

AcDb::TextVertMode PyDbText::verticalMode() const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->verticalMode();
}

Acad::ErrorStatus PyDbText::setVerticalMode(AcDb::TextVertMode val)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->setVerticalMode(val);
}

int PyDbText::correctSpelling()
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->correctSpelling();
#endif
}

Acad::ErrorStatus PyDbText::adjustAlignment(const PyDbDatabase& pDb)
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->adjustAlignment(pDb.impObj());
#endif
}

Acad::ErrorStatus PyDbText::convertFieldToText()
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->convertFieldToText();
#endif
}

bool PyDbText::hitTest(const AcGePoint3d& ptHit) const
{
#ifdef ARXAPP
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->hitTest(ptHit);
#else
    throw PyNotimplementedByHost();
#endif // ARXAPP
}

boost::python::list PyDbText::getBoundingPoints() const
{
#ifdef ARXAPP
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    boost::python::list l;
    AcGePoint3dArray arr;
    imp->getBoundingPoints(arr);
    for (const auto& item : arr)
        l.append(item);
    return l;
#else
    throw PyNotimplementedByHost();
#endif // ARXAPP
}

AcDbText::AcTextAlignment PyDbText::justification() const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->justification();
}

Acad::ErrorStatus PyDbText::setJustification(AcDbText::AcTextAlignment val)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->setJustification(val);
}

std::string PyDbText::className()
{
    return "AcDbText";
}

AcDbText* PyDbText::impObj() const
{
    return static_cast<AcDbText*>(m_pImp.get());
}

//-----------------------------------------------------------------------------------
//PyDbAttributeDefinition
void makePyDbAttributeDefinitionWrapper()
{
    static auto wrapper = class_<PyDbAttributeDefinition, bases<PyDbText>>("AttributeDefinition")
        .def(init<>())
        .def(init<const AcGePoint3d&, const std::string&, const std::string&, const std::string&, const PyDbObjectId&>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode>())
        .def("prompt", &PyDbAttributeDefinition::prompt)
        .def("setPrompt", &PyDbAttributeDefinition::setPrompt)
        .def("tag", &PyDbAttributeDefinition::tag)
        .def("setTag", &PyDbAttributeDefinition::setTag)
        .def("isInvisible", &PyDbAttributeDefinition::isInvisible)
        .def("setInvisible", &PyDbAttributeDefinition::setInvisible)
        .def("isConstant", &PyDbAttributeDefinition::isConstant)
        .def("setConstant", &PyDbAttributeDefinition::setConstant)
        .def("isVerifiable", &PyDbAttributeDefinition::isVerifiable)
        .def("setVerifiable", &PyDbAttributeDefinition::setVerifiable)
        .def("isPreset", &PyDbAttributeDefinition::isPreset)
        .def("setPreset", &PyDbAttributeDefinition::setPreset)
        .def("fieldLength", &PyDbAttributeDefinition::fieldLength)
        .def("setFieldLength", &PyDbAttributeDefinition::setFieldLength)
        .def("adjustAlignment", &PyDbAttributeDefinition::adjustAlignment)
        .def("lockPositionInBlock", &PyDbAttributeDefinition::lockPositionInBlock)
        .def("setLockPositionInBlock", &PyDbAttributeDefinition::setLockPositionInBlock)
        .def("isMTextAttributeDefinition", &PyDbAttributeDefinition::isMTextAttributeDefinition)
        .def("convertIntoMTextAttributeDefinition", &PyDbAttributeDefinition::convertIntoMTextAttributeDefinition)
        .def("updateMTextAttributeDefinition", &PyDbAttributeDefinition::updateMTextAttributeDefinition)
        .def("getMTextAttributeDefinition", &PyDbAttributeDefinition::getMTextAttributeDefinition)
        .def("setMTextAttributeDefinition", &PyDbAttributeDefinition::setMTextAttributeDefinition)
        .def("className", &PyDbAttributeDefinition::className).staticmethod("className")
        ;
}

PyDbAttributeDefinition::PyDbAttributeDefinition()
    : PyDbText(new AcDbAttributeDefinition(), true)
{
}

PyDbAttributeDefinition::PyDbAttributeDefinition(const AcGePoint3d& position, const std::string& text, const std::string& tag, const std::string& prompt, const PyDbObjectId& style)
    : PyDbText(new AcDbAttributeDefinition(position, utf8_to_wstr(text).c_str(), utf8_to_wstr(tag).c_str(), utf8_to_wstr(prompt).c_str(), style.m_id), true)
{
}

PyDbAttributeDefinition::PyDbAttributeDefinition(AcDbAttributeDefinition* ptr, bool autoDelete)
    : PyDbText(ptr, autoDelete)
{
}

PyDbAttributeDefinition::PyDbAttributeDefinition(const PyDbObjectId& id, AcDb::OpenMode mode)
    : PyDbText(nullptr, false)
{
    AcDbAttributeDefinition* pobj = nullptr;
    if (auto es = acdbOpenObject<AcDbAttributeDefinition>(pobj, id.m_id, mode); es != eOk)
        throw PyAcadErrorStatus(es);
    this->resetImp(pobj, false, true);
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
}

std::string PyDbAttributeDefinition::prompt() const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return wstr_to_utf8(imp->promptConst());
}

Acad::ErrorStatus PyDbAttributeDefinition::setPrompt(const std::string& val)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->setPrompt(utf8_to_wstr(val).c_str());
}

std::string PyDbAttributeDefinition::tag() const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return wstr_to_utf8(imp->tagConst());
}

Acad::ErrorStatus PyDbAttributeDefinition::setTag(const std::string& val)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->setTag(utf8_to_wstr(val).c_str());
}

Adesk::Boolean PyDbAttributeDefinition::isInvisible() const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->isInvisible();
}

Acad::ErrorStatus PyDbAttributeDefinition::setInvisible(Adesk::Boolean val)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->setInvisible(val);
}

Adesk::Boolean PyDbAttributeDefinition::isConstant() const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->isConstant();
}

Acad::ErrorStatus PyDbAttributeDefinition::setConstant(Adesk::Boolean val)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->setConstant(val);
}

Adesk::Boolean PyDbAttributeDefinition::isVerifiable() const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->isVerifiable();
}

Acad::ErrorStatus PyDbAttributeDefinition::setVerifiable(Adesk::Boolean val)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->setVerifiable(val);
}

Adesk::Boolean PyDbAttributeDefinition::isPreset() const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->isPreset();
}

Acad::ErrorStatus PyDbAttributeDefinition::setPreset(Adesk::Boolean val)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->setPreset(val);
}

Adesk::UInt16 PyDbAttributeDefinition::fieldLength() const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->fieldLength();
}

Acad::ErrorStatus PyDbAttributeDefinition::setFieldLength(Adesk::UInt16 val)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->setFieldLength(val);
}

Acad::ErrorStatus PyDbAttributeDefinition::adjustAlignment(const PyDbDatabase& pDb)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->adjustAlignment(pDb.impObj());
}

bool PyDbAttributeDefinition::lockPositionInBlock() const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->lockPositionInBlock();
}

Acad::ErrorStatus PyDbAttributeDefinition::setLockPositionInBlock(bool bValue)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->setLockPositionInBlock(bValue);
}

bool PyDbAttributeDefinition::isMTextAttributeDefinition() const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->isMTextAttributeDefinition();
}

PyDbMText PyDbAttributeDefinition::getMTextAttributeDefinition() const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    AcDbMText* ptr = imp->getMTextAttributeDefinition();
    if(ptr == nullptr)
        throw PyNullObject();
    return PyDbMText(ptr,true);
}

Acad::ErrorStatus PyDbAttributeDefinition::setMTextAttributeDefinition(const PyDbMText& mt)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->setMTextAttributeDefinition(mt.impObj());
}

Acad::ErrorStatus PyDbAttributeDefinition::convertIntoMTextAttributeDefinition(Adesk::Boolean val)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->convertIntoMTextAttributeDefinition(val);
}

Acad::ErrorStatus PyDbAttributeDefinition::updateMTextAttributeDefinition()
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->updateMTextAttributeDefinition();
}

std::string PyDbAttributeDefinition::className()
{
    return "AcDbAttributeDefinition";
}

AcDbAttributeDefinition* PyDbAttributeDefinition::impObj() const
{
    return static_cast<AcDbAttributeDefinition*>(m_pImp.get());
}

//-----------------------------------------------------------------------------------
//PyDbAttribute
void makePyDbAttributeWrapper()
{
    static auto wrapper = class_<PyDbAttribute, bases<PyDbText>>("Attribute")
        .def(init<>())
        .def(init<const AcGePoint3d&, const std::string&, const std::string&, const PyDbObjectId&>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode>())
        .def("tag", &PyDbAttribute::tag)
        .def("setTag", &PyDbAttribute::setTag)
        .def("isInvisible", &PyDbAttribute::isInvisible)
        .def("setInvisible", &PyDbAttribute::setInvisible)
        .def("isConstant", &PyDbAttribute::isConstant)
        .def("isVerifiable", &PyDbAttribute::isVerifiable)
        .def("isPreset", &PyDbAttribute::isPreset)
        .def("fieldLength", &PyDbAttribute::fieldLength)
        .def("setFieldLength", &PyDbAttribute::setFieldLength)
        .def<Acad::ErrorStatus(PyDbAttribute::*)(const AcGeMatrix3d&)>("setAttributeFromBlock", &PyDbAttribute::setAttributeFromBlock)
        .def<Acad::ErrorStatus(PyDbAttribute::*)(const PyDbAttributeDefinition&, const AcGeMatrix3d&)>("setAttributeFromBlock", &PyDbAttribute::setAttributeFromBlock)
        .def("lockPositionInBlock", &PyDbAttribute::lockPositionInBlock)
        .def("setLockPositionInBlock", &PyDbAttribute::setLockPositionInBlock)
        .def("isMTextAttribute", &PyDbAttribute::isMTextAttribute)
        .def("getMTextAttribute", &PyDbAttribute::getMTextAttribute)
        .def("setMTextAttribute", &PyDbAttribute::setMTextAttribute)
        .def("convertIntoMTextAttribute", &PyDbAttribute::convertIntoMTextAttribute)
        .def("updateMTextAttribute", &PyDbAttribute::updateMTextAttribute)
        .def("isReallyLocked", &PyDbAttribute::isReallyLocked)
        .def("className", &PyDbAttributeDefinition::className).staticmethod("className")
        ;
}

PyDbAttribute::PyDbAttribute()
    : PyDbText(new AcDbAttribute(), true)
{
}

PyDbAttribute::PyDbAttribute(const AcGePoint3d& position, const std::string& text, const std::string& tag, const PyDbObjectId& style)
    : PyDbText(new AcDbAttribute(position, utf8_to_wstr(text).c_str(), utf8_to_wstr(tag).c_str(), style.m_id), true)
{
}

PyDbAttribute::PyDbAttribute(AcDbAttributeDefinition* ptr, bool autoDelete)
    : PyDbText(ptr, autoDelete)
{
}

PyDbAttribute::PyDbAttribute(const PyDbObjectId& id, AcDb::OpenMode mode)
    : PyDbText(nullptr, false)
{
    AcDbAttribute* pobj = nullptr;
    if (auto es = acdbOpenObject<AcDbAttribute>(pobj, id.m_id, mode); es != eOk)
        throw PyAcadErrorStatus(es);
    this->resetImp(pobj, false, true);
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
}

std::string PyDbAttribute::tag() const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return wstr_to_utf8(imp->tagConst());
}

Acad::ErrorStatus PyDbAttribute::setTag(const std::string& val)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->setTag(utf8_to_wstr(val).c_str());
}

Adesk::Boolean PyDbAttribute::isInvisible() const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->isInvisible();
}

Acad::ErrorStatus PyDbAttribute::setInvisible(Adesk::Boolean val)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->setInvisible(val);
}

Adesk::Boolean PyDbAttribute::isConstant() const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->isConstant();
}

Adesk::Boolean PyDbAttribute::isVerifiable() const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->isVerifiable();
}

Adesk::Boolean PyDbAttribute::isPreset() const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->isPreset();
}

Adesk::UInt16 PyDbAttribute::fieldLength() const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->isPreset();
}

Acad::ErrorStatus PyDbAttribute::setFieldLength(Adesk::UInt16 val)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->setFieldLength(val);
}

Acad::ErrorStatus PyDbAttribute::setAttributeFromBlock(const AcGeMatrix3d& blkXform)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->setAttributeFromBlock(blkXform);
}

Acad::ErrorStatus PyDbAttribute::setAttributeFromBlock(const PyDbAttributeDefinition& pAttdef, const AcGeMatrix3d& blkXform)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->setAttributeFromBlock(pAttdef.impObj(), blkXform);
}

bool PyDbAttribute::lockPositionInBlock() const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->lockPositionInBlock();
}

Acad::ErrorStatus PyDbAttribute::setLockPositionInBlock(bool bValue)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->setLockPositionInBlock(bValue);
}

bool PyDbAttribute::isMTextAttribute() const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->isMTextAttribute();
}

PyDbMText PyDbAttribute::getMTextAttribute() const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return PyDbMText(imp->getMTextAttribute(),true);
}

Acad::ErrorStatus PyDbAttribute::setMTextAttribute(PyDbMText& mt)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->setMTextAttribute(mt.impObj());
}

Acad::ErrorStatus PyDbAttribute::convertIntoMTextAttribute(Adesk::Boolean val)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->convertIntoMTextAttribute(val);
}

Acad::ErrorStatus PyDbAttribute::updateMTextAttribute()
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->updateMTextAttribute();
}

bool PyDbAttribute::isReallyLocked() const
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->isReallyLocked();
#endif
}

std::string PyDbAttribute::className()
{
    return "AcDbAttribute";
}

AcDbAttribute* PyDbAttribute::impObj() const
{
    return static_cast<AcDbAttribute*>(m_pImp.get());
}

//-----------------------------------------------------------------------------------
//PyDbBlockReference
void makeDbBlockReferenceWrapper()
{
    static auto wrapper = class_<PyDbBlockReference, bases<PyDbEntity>>("BlockReference")
        .def(init<>())
        .def(init<AcGePoint3d&, const PyDbObjectId&>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode>())
        .def("blockTableRecord", &PyDbBlockReference::blockTableRecord)
        .def("setBlockTableRecord", &PyDbBlockReference::setBlockTableRecord)
        .def("position", &PyDbBlockReference::position)
        .def("setPosition", &PyDbBlockReference::setPosition)
        .def("scaleFactors", &PyDbBlockReference::scaleFactors)
        .def("nonAnnotationScaleFactors", &PyDbBlockReference::nonAnnotationScaleFactors)
        .def("setScaleFactors", &PyDbBlockReference::setScaleFactors)
        .def("rotation", &PyDbBlockReference::rotation)
        .def("setRotation", &PyDbBlockReference::setRotation)
        .def("normal", &PyDbBlockReference::normal)
        .def("setNormal", &PyDbBlockReference::setNormal)
        .def("blockTransform", &PyDbBlockReference::blockTransform)
        .def("nonAnnotationBlockTransform", &PyDbBlockReference::nonAnnotationBlockTransform)
        .def("setBlockTransform", &PyDbBlockReference::setBlockTransform)
        .def("appendAttribute", &PyDbBlockReference::appendAttribute)
        .def("attributeIds", &PyDbBlockReference::attributeIds)
        .def("treatAsAcDbBlockRefForExplode", &PyDbBlockReference::treatAsAcDbBlockRefForExplode)
        .def("geomExtentsBestFit", &PyDbBlockReference::geomExtentsBestFit1)
        .def("geomExtentsBestFit", &PyDbBlockReference::geomExtentsBestFit2)
        .def("explodeToOwnerSpace", &PyDbBlockReference::explodeToOwnerSpace)
        .def("className", &PyDbBlockReference::className).staticmethod("className")
        ;
}

PyDbBlockReference::PyDbBlockReference()
    : PyDbBlockReference(new AcDbBlockReference(), true)
{
}

PyDbBlockReference::PyDbBlockReference(const AcGePoint3d& position, const PyDbObjectId& blockTableRec)
    : PyDbBlockReference(new AcDbBlockReference(position, blockTableRec.m_id), true)
{
}

PyDbBlockReference::PyDbBlockReference(AcDbBlockReference* ptr, bool autoDelete)
    : PyDbEntity(ptr, autoDelete)
{
}

PyDbBlockReference::PyDbBlockReference(const PyDbObjectId& id, AcDb::OpenMode mode)
    : PyDbEntity(nullptr, false)
{
    AcDbBlockReference* pobj = nullptr;
    if (auto es = acdbOpenObject<AcDbBlockReference>(pobj, id.m_id, mode); es != eOk)
        throw PyAcadErrorStatus(es);
    this->resetImp(pobj, false, true);
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
}

PyDbObjectId PyDbBlockReference::blockTableRecord() const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return PyDbObjectId(imp->blockTableRecord());
}

Acad::ErrorStatus PyDbBlockReference::setBlockTableRecord(const PyDbObjectId& val)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->setBlockTableRecord(val.m_id);
}

AcGePoint3d PyDbBlockReference::position() const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->position();
}

Acad::ErrorStatus PyDbBlockReference::setPosition(const AcGePoint3d& val)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->setPosition(val);
}

AcGeScale3d PyDbBlockReference::scaleFactors() const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->scaleFactors();
}

AcGeScale3d PyDbBlockReference::nonAnnotationScaleFactors() const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->nonAnnotationScaleFactors();
}

Acad::ErrorStatus PyDbBlockReference::setScaleFactors(const AcGeScale3d& scale)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->setScaleFactors(scale);
}

double PyDbBlockReference::rotation() const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->rotation();
}

Acad::ErrorStatus PyDbBlockReference::setRotation(double newVal)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->setRotation(newVal);
}

AcGeVector3d PyDbBlockReference::normal() const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->normal();
}

Acad::ErrorStatus PyDbBlockReference::setNormal(const AcGeVector3d& newVal)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->setNormal(newVal);
}

AcGeMatrix3d PyDbBlockReference::blockTransform() const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->blockTransform();
}

AcGeMatrix3d PyDbBlockReference::nonAnnotationBlockTransform() const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->nonAnnotationBlockTransform();
}

Acad::ErrorStatus PyDbBlockReference::setBlockTransform(const AcGeMatrix3d& val)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->setBlockTransform(val);
}

PyDbObjectId PyDbBlockReference::appendAttribute(PyDbAttribute& att)
{
    AcDbObjectId id;
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    if (auto es = imp->appendAttribute(id, att.impObj()); es != eOk)
        throw PyAcadErrorStatus(es);
    return PyDbObjectId(id);
}

boost::python::list PyDbBlockReference::attributeIds() const
{
    AcDbObjectId id;
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    boost::python::list ids;
    for (std::unique_ptr<AcDbObjectIterator> iter(imp->attributeIterator()); !iter->done(); iter->step())
        ids.append(PyDbObjectId(iter->objectId()));
    return ids;
}

Adesk::Boolean PyDbBlockReference::treatAsAcDbBlockRefForExplode() const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->treatAsAcDbBlockRefForExplode();
}

AcDbExtents PyDbBlockReference::geomExtentsBestFit1() const
{
    return geomExtentsBestFit2(AcGeMatrix3d::kIdentity);
}

AcDbExtents PyDbBlockReference::geomExtentsBestFit2(const AcGeMatrix3d& parentXform) const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    AcDbExtents ex;
    if (auto es = imp->geomExtentsBestFit(ex, parentXform); es != eOk)
        throw PyAcadErrorStatus(es);
    return ex;
}

Acad::ErrorStatus PyDbBlockReference::explodeToOwnerSpace() const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->explodeToOwnerSpace();
}

std::string PyDbBlockReference::className()
{
    return "AcDbBlockReference";
}

AcDbBlockReference* PyDbBlockReference::impObj() const
{
    return static_cast<AcDbBlockReference*>(m_pImp.get());
}

//-----------------------------------------------------------------------------------
//PyDbBlockReference
void makeDbMInsertBlockeWrapper()
{
    static auto wrapper = class_<PyDbMInsertBlock, bases<PyDbBlockReference>>("MInsertBlock")
        .def(init<>())
        .def(init<AcGePoint3d&, const PyDbObjectId&, Adesk::UInt16, Adesk::UInt16, double, double>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode>())
        .def("columns", &PyDbMInsertBlock::columns)
        .def("setColumns", &PyDbMInsertBlock::setColumns)
        .def("rows", &PyDbMInsertBlock::rows)
        .def("setRows", &PyDbMInsertBlock::setRows)
        .def("columnSpacing", &PyDbMInsertBlock::columnSpacing)
        .def("setColumnSpacing", &PyDbMInsertBlock::setColumnSpacing)
        .def("rowSpacing", &PyDbMInsertBlock::rowSpacing)
        .def("setRowSpacing", &PyDbMInsertBlock::setRowSpacing)
        .def("className", &PyDbMInsertBlock::className).staticmethod("className")
        ;
}

PyDbMInsertBlock::PyDbMInsertBlock()
    : PyDbMInsertBlock(new AcDbMInsertBlock(), true)
{
}

PyDbMInsertBlock::PyDbMInsertBlock(const AcGePoint3d& position, const PyDbObjectId& blockTableRec, Adesk::UInt16 columns, Adesk::UInt16 rows, double colSpacing, double rowSpacing)
    : PyDbMInsertBlock(new AcDbMInsertBlock(position, blockTableRec.m_id, columns, rows, colSpacing, rowSpacing), true)
{
}

PyDbMInsertBlock::PyDbMInsertBlock(AcDbMInsertBlock* ptr, bool autoDelete)
    : PyDbBlockReference(ptr, autoDelete)
{
}

PyDbMInsertBlock::PyDbMInsertBlock(const PyDbObjectId& id, AcDb::OpenMode mode)
    : PyDbBlockReference(nullptr, false)
{
    AcDbMInsertBlock* pobj = nullptr;
    if (auto es = acdbOpenObject<AcDbMInsertBlock>(pobj, id.m_id, mode); es != eOk)
        throw PyAcadErrorStatus(es);
    this->resetImp(pobj, false, true);
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
}

Adesk::UInt16 PyDbMInsertBlock::columns() const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->columns();
}

Acad::ErrorStatus PyDbMInsertBlock::setColumns(Adesk::UInt16 val)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->setColumns(val);
}

Adesk::UInt16 PyDbMInsertBlock::rows() const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->rows();
}

Acad::ErrorStatus PyDbMInsertBlock::setRows(Adesk::UInt16 val)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->setRows(val);
}

double PyDbMInsertBlock::columnSpacing() const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->columnSpacing();
}

Acad::ErrorStatus PyDbMInsertBlock::setColumnSpacing(double val)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->setColumnSpacing(val);
}

double PyDbMInsertBlock::rowSpacing() const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->rowSpacing();
}

Acad::ErrorStatus PyDbMInsertBlock::setRowSpacing(double val)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->setRowSpacing(val);
}

std::string PyDbMInsertBlock::className()
{
    return "AcDbMInsertBlock";
}

AcDbMInsertBlock* PyDbMInsertBlock::impObj() const
{
    return static_cast<AcDbMInsertBlock*>(m_pImp.get());
}

//-------------------------------------------------------------------------------------------------------------
//PyDbVertex
void makeAcDbVertexWrapper()
{
    static auto wrapper = class_<PyDbVertex, bases<PyDbEntity>>("Vertex", boost::python::no_init)
        .def(init<const PyDbObjectId&, AcDb::OpenMode>())
        .def("className", &PyDbVertex::className).staticmethod("className")
        ;
}

PyDbVertex::PyDbVertex(AcDbVertex* ptr, bool autoDelete)
    : PyDbEntity(ptr, autoDelete)
{
}

PyDbVertex::PyDbVertex(const PyDbObjectId& id, AcDb::OpenMode mode)
    : PyDbEntity(nullptr, false)
{
    AcDbVertex* pobj = nullptr;
    if (auto es = acdbOpenObject<AcDbVertex>(pobj, id.m_id, mode); es != eOk)
        throw PyAcadErrorStatus(es);
    this->resetImp(pobj, false, true);
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
}

std::string PyDbVertex::className()
{
    return "AcDbVertex";
}

AcDbVertex* PyDbVertex::impObj() const
{
    return static_cast<AcDbVertex*>(m_pImp.get());
}

//-------------------------------------------------------------------------------------------------------------
//PyDb2dVertex
void makePyDb2dVertexWrapper()
{
    static auto wrapper = class_<PyDb2dVertex, bases<PyDbVertex>>("Vertex2d")
        .def(init<>())
        .def(init<const AcGePoint3d&>())
#ifndef BRXAPP
        .def(init<const AcGePoint3d&, double, double, double, double, Adesk::Int32>())
#endif
        .def(init<const PyDbObjectId&, AcDb::OpenMode>())
        .def("vertexType", &PyDb2dVertex::vertexType)
        .def("position", &PyDb2dVertex::position)
        .def("setPosition", &PyDb2dVertex::setPosition)
        .def("startWidth", &PyDb2dVertex::startWidth)
        .def("setStartWidth", &PyDb2dVertex::setStartWidth)
        .def("endWidth", &PyDb2dVertex::endWidth)
        .def("setEndWidth", &PyDb2dVertex::setEndWidth)
        .def("bulge", &PyDb2dVertex::bulge)
        .def("setBulge", &PyDb2dVertex::setBulge)
        .def("isTangentUsed", &PyDb2dVertex::isTangentUsed)
        .def("useTangent", &PyDb2dVertex::useTangent)
        .def("ignoreTangent", &PyDb2dVertex::ignoreTangent)
        .def("setTangentUsed", &PyDb2dVertex::setTangentUsed)
        .def("tangent", &PyDb2dVertex::tangent)
        .def("setTangent", &PyDb2dVertex::setTangent)
        .def("setVertexIdentifier", &PyDb2dVertex::setVertexIdentifier)
        .def("vertexIdentifier", &PyDb2dVertex::vertexIdentifier)
        .def("className", &PyDb2dVertex::className).staticmethod("className")
        ;
}

PyDb2dVertex::PyDb2dVertex()
    : PyDb2dVertex(new AcDb2dVertex(), true)
{
}

PyDb2dVertex::PyDb2dVertex(const AcGePoint3d& pos)
    : PyDb2dVertex(new AcDb2dVertex(pos), true)
{
}

#ifndef BRXAPP
PyDb2dVertex::PyDb2dVertex(const AcGePoint3d& pos, double bulge, double startWidth, double endWidth, double tangent, Adesk::Int32 vertexIdentifier)
    : PyDb2dVertex(new AcDb2dVertex(pos, bulge, startWidth, endWidth, tangent, vertexIdentifier), true)
{
}
#endif // !BRXAPP

PyDb2dVertex::PyDb2dVertex(AcDb2dVertex* ptr, bool autoDelete)
    : PyDbVertex(ptr, autoDelete)
{
}

PyDb2dVertex::PyDb2dVertex(const PyDbObjectId& id, AcDb::OpenMode mode)
    : PyDbVertex(nullptr, false)
{
    AcDb2dVertex* pobj = nullptr;
    if (auto es = acdbOpenObject<AcDb2dVertex>(pobj, id.m_id, mode); es != eOk)
        throw PyAcadErrorStatus(es);
    this->resetImp(pobj, false, true);
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
}

AcDb::Vertex2dType PyDb2dVertex::vertexType() const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->vertexType();
}

AcGePoint3d PyDb2dVertex::position() const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->position();
}

Acad::ErrorStatus PyDb2dVertex::setPosition(const AcGePoint3d& val)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->setPosition(val);
}

double PyDb2dVertex::startWidth() const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->startWidth();
}

Acad::ErrorStatus PyDb2dVertex::setStartWidth(double newVal)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->setStartWidth(newVal);
}

double PyDb2dVertex::endWidth() const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->endWidth();
}

Acad::ErrorStatus PyDb2dVertex::setEndWidth(double newVal)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->setEndWidth(newVal);
}

double PyDb2dVertex::bulge() const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->bulge();
}

Acad::ErrorStatus PyDb2dVertex::setBulge(double newVal)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->setBulge(newVal);
}

Adesk::Boolean PyDb2dVertex::isTangentUsed() const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->isTangentUsed();
}

Acad::ErrorStatus PyDb2dVertex::useTangent()
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->useTangent();
}

Acad::ErrorStatus PyDb2dVertex::ignoreTangent()
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->ignoreTangent();
}

Acad::ErrorStatus PyDb2dVertex::setTangentUsed(Adesk::Boolean val)
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else // !BRXAPP
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->setTangentUsed(val);
#endif
}

double PyDb2dVertex::tangent() const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->tangent();
}

Acad::ErrorStatus PyDb2dVertex::setTangent(double newVal)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->setTangent(newVal);
}

Acad::ErrorStatus PyDb2dVertex::setVertexIdentifier(Adesk::Int32 suggestedValue)
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else // !BRXAPP
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->setVertexIdentifier(suggestedValue);
#endif
}

int PyDb2dVertex::vertexIdentifier() const
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else // !BRXAPP
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->vertexIdentifier();
#endif
}

std::string PyDb2dVertex::className()
{
    return "AcDb2dVertex";
}

AcDb2dVertex* PyDb2dVertex::impObj() const
{
    return static_cast<AcDb2dVertex*>(m_pImp.get());
}


//-------------------------------------------------------------------------------------------------------------
//AcDb3dPolylineVertex
void makePyAcDb3dPolylineVertexWrapper()
{
    static auto wrapper = class_<PyDb3dPolylineVertex, bases<PyDbVertex>>("Polyline3dVertex")
        .def(init<>())
        .def(init<const AcGePoint3d&>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode>())
        .def("vertexType", &PyDb3dPolylineVertex::vertexType)
        .def("position", &PyDb3dPolylineVertex::position)
        .def("setPosition", &PyDb3dPolylineVertex::setPosition)
        .def("className", &PyDb3dPolylineVertex::className).staticmethod("className")
        ;
}

PyDb3dPolylineVertex::PyDb3dPolylineVertex()
    : PyDb3dPolylineVertex(new AcDb3dPolylineVertex(), true)
{
}

PyDb3dPolylineVertex::PyDb3dPolylineVertex(const AcGePoint3d& pos)
    : PyDb3dPolylineVertex(new AcDb3dPolylineVertex(pos), true)
{
}

PyDb3dPolylineVertex::PyDb3dPolylineVertex(AcDb3dPolylineVertex* ptr, bool autoDelete)
    : PyDbVertex(ptr, autoDelete)
{
}

PyDb3dPolylineVertex::PyDb3dPolylineVertex(const PyDbObjectId& id, AcDb::OpenMode mode)
    : PyDbVertex(nullptr, false)
{
    AcDb3dPolylineVertex* pobj = nullptr;
    if (auto es = acdbOpenObject<AcDb3dPolylineVertex>(pobj, id.m_id, mode); es != eOk)
        throw PyAcadErrorStatus(es);
    this->resetImp(pobj, false, true);
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
}

AcDb::Vertex3dType PyDb3dPolylineVertex::vertexType() const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->vertexType();
}

AcGePoint3d PyDb3dPolylineVertex::position() const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->position();
}

Acad::ErrorStatus PyDb3dPolylineVertex::setPosition(const AcGePoint3d& val)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->setPosition(val);
}

std::string PyDb3dPolylineVertex::className()
{
    return "AcDb3dPolylineVertex";
}

AcDb3dPolylineVertex* PyDb3dPolylineVertex::impObj() const
{
    return static_cast<AcDb3dPolylineVertex*>(m_pImp.get());
}

//-------------------------------------------------------------------------------------------------------------
//AcDbPolygonMeshVertex
void makePyAcDbPolygonMeshVertexWrapper()
{
    static auto wrapper = class_<PyDbPolygonMeshVertex, bases<PyDbVertex>>("PolygonMeshVertex")
        .def(init<>())
        .def(init<const AcGePoint3d&>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode>())
        .def("vertexType", &PyDbPolygonMeshVertex::vertexType)
        .def("position", &PyDbPolygonMeshVertex::position)
        .def("setPosition", &PyDbPolygonMeshVertex::setPosition)
        .def("className", &PyDbPolygonMeshVertex::className).staticmethod("className")
        ;
}

PyDbPolygonMeshVertex::PyDbPolygonMeshVertex()
    : PyDbPolygonMeshVertex(new AcDbPolygonMeshVertex(), true)
{
}

PyDbPolygonMeshVertex::PyDbPolygonMeshVertex(const AcGePoint3d& pos)
    : PyDbPolygonMeshVertex(new AcDbPolygonMeshVertex(pos), true)
{
}

PyDbPolygonMeshVertex::PyDbPolygonMeshVertex(AcDbPolygonMeshVertex* ptr, bool autoDelete)
    : PyDbVertex(ptr, autoDelete)
{
}

PyDbPolygonMeshVertex::PyDbPolygonMeshVertex(const PyDbObjectId& id, AcDb::OpenMode mode)
    : PyDbVertex(nullptr, false)
{
    AcDbPolygonMeshVertex* pobj = nullptr;
    if (auto es = acdbOpenObject<AcDbPolygonMeshVertex>(pobj, id.m_id, mode); es != eOk)
        throw PyAcadErrorStatus(es);
    this->resetImp(pobj, false, true);
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
}

AcDb::Vertex3dType PyDbPolygonMeshVertex::vertexType() const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->vertexType();
}

AcGePoint3d PyDbPolygonMeshVertex::position() const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->position();
}

Acad::ErrorStatus PyDbPolygonMeshVertex::setPosition(const AcGePoint3d& val)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->setPosition(val);
}

std::string PyDbPolygonMeshVertex::className()
{
    return "AcDbPolygonMeshVertex";
}

AcDbPolygonMeshVertex* PyDbPolygonMeshVertex::impObj() const
{
    return static_cast<AcDbPolygonMeshVertex*>(m_pImp.get());
}

//-------------------------------------------------------------------------------------------------------------
//AcDbPolygonMeshVertex
void makePyDbPolyFaceMeshVertexWrapper()
{
    static auto wrapper = class_<PyDbPolyFaceMeshVertex, bases<PyDbVertex>>("PolyFaceMeshVertex")
        .def(init<>())
        .def(init<const AcGePoint3d&>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode>())
        .def("position", &PyDbPolyFaceMeshVertex::position)
        .def("setPosition", &PyDbPolyFaceMeshVertex::setPosition)
        .def("className", &PyDbPolyFaceMeshVertex::className).staticmethod("className")
        ;
}

PyDbPolyFaceMeshVertex::PyDbPolyFaceMeshVertex()
    : PyDbPolyFaceMeshVertex(new AcDbPolyFaceMeshVertex(), true)
{
}

PyDbPolyFaceMeshVertex::PyDbPolyFaceMeshVertex(const AcGePoint3d& pos)
    : PyDbPolyFaceMeshVertex(new AcDbPolyFaceMeshVertex(pos), true)
{
}

PyDbPolyFaceMeshVertex::PyDbPolyFaceMeshVertex(AcDbPolyFaceMeshVertex* ptr, bool autoDelete)
    : PyDbVertex(ptr, autoDelete)
{
}

PyDbPolyFaceMeshVertex::PyDbPolyFaceMeshVertex(const PyDbObjectId& id, AcDb::OpenMode mode)
    : PyDbVertex(nullptr, false)
{
    AcDbPolyFaceMeshVertex* pobj = nullptr;
    if (auto es = acdbOpenObject<AcDbPolyFaceMeshVertex>(pobj, id.m_id, mode); es != eOk)
        throw PyAcadErrorStatus(es);
    this->resetImp(pobj, false, true);
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
}

AcGePoint3d PyDbPolyFaceMeshVertex::position() const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->position();
}

Acad::ErrorStatus PyDbPolyFaceMeshVertex::setPosition(const AcGePoint3d& val)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->setPosition(val);
}

std::string PyDbPolyFaceMeshVertex::className()
{
    return "AcDbPolyFaceMeshVertex";
}

AcDbPolyFaceMeshVertex* PyDbPolyFaceMeshVertex::impObj() const
{
    return static_cast<AcDbPolyFaceMeshVertex*>(m_pImp.get());
}

//-------------------------------------------------------------------------------------------------------------
//AcDbFaceRecord

void makePyAcDbFaceRecordWrapper()
{
    static auto wrapper = class_<PyDbFaceRecord, bases<PyDbVertex>>("FaceRecord")
        .def(init<>())
        .def(init<Adesk::Int16, Adesk::Int16, Adesk::Int16, Adesk::Int16>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode>())
        .def("getVertexAt", &PyDbFaceRecord::getVertexAt)
        .def("setVertexAt", &PyDbFaceRecord::setVertexAt)
        .def("isEdgeVisibleAt", &PyDbFaceRecord::isEdgeVisibleAt)
        .def("makeEdgeVisibleAt", &PyDbFaceRecord::makeEdgeVisibleAt)
        .def("makeEdgeInvisibleAt", &PyDbFaceRecord::makeEdgeInvisibleAt)
        .def("className", &PyDbFaceRecord::className).staticmethod("className")
        ;
}

PyDbFaceRecord::PyDbFaceRecord()
    :PyDbFaceRecord(new AcDbFaceRecord(), true)
{
}

PyDbFaceRecord::PyDbFaceRecord(Adesk::Int16 vtx0, Adesk::Int16 vtx1, Adesk::Int16 vtx2, Adesk::Int16 vtx3)
    : PyDbFaceRecord(new AcDbFaceRecord(vtx0, vtx1, vtx2, vtx3), true)
{
}

PyDbFaceRecord::PyDbFaceRecord(AcDbFaceRecord* ptr, bool autoDelete)
    : PyDbVertex(ptr, autoDelete)
{
}

PyDbFaceRecord::PyDbFaceRecord(const PyDbObjectId& id, AcDb::OpenMode mode)
    : PyDbVertex(nullptr, false)
{
    AcDbFaceRecord* pobj = nullptr;
    if (auto es = acdbOpenObject<AcDbFaceRecord>(pobj, id.m_id, mode); es != eOk)
        throw PyAcadErrorStatus(es);
    this->resetImp(pobj, false, true);
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
}

Adesk::Int16 PyDbFaceRecord::getVertexAt(Adesk::UInt16 faceIdx) const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    Adesk::Int16 vtxIdx = 0;
    if (auto es = imp->getVertexAt(faceIdx, vtxIdx); es != eOk)
        throw PyAcadErrorStatus(es);
    return vtxIdx;
}

Acad::ErrorStatus PyDbFaceRecord::setVertexAt(Adesk::UInt16 faceIdx, Adesk::Int16 vtxIdx)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->setVertexAt(faceIdx, vtxIdx);
}

Adesk::Boolean PyDbFaceRecord::isEdgeVisibleAt(Adesk::UInt16 faceIndex) const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    Adesk::Boolean flag = false;
    if (auto es = imp->isEdgeVisibleAt(faceIndex, flag); es != eOk)
        throw PyAcadErrorStatus(es);
    return flag;
}

Acad::ErrorStatus PyDbFaceRecord::makeEdgeVisibleAt(Adesk::UInt16 faceIndex)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->makeEdgeVisibleAt(faceIndex);
}

Acad::ErrorStatus PyDbFaceRecord::makeEdgeInvisibleAt(Adesk::UInt16 faceIndex)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->makeEdgeInvisibleAt(faceIndex);
}

std::string PyDbFaceRecord::className()
{
    return "AcDbFaceRecord";
}

AcDbFaceRecord* PyDbFaceRecord::impObj() const
{
    return static_cast<AcDbFaceRecord*>(m_pImp.get());
}

//-----------------------------------------------------------------------------------
//PyDbPoint
void makePyDbPointWrapper()
{
    static auto wrapper = class_<PyDbPoint, bases<PyDbEntity>>("Point")
        .def(init<>())
        .def(init<AcGePoint3d&>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode>())
        .def("position", &PyDbPoint::position)
        .def("setPosition", &PyDbPoint::setPosition)
        .def("thickness", &PyDbPoint::thickness)
        .def("setThickness", &PyDbPoint::setThickness)
        .def("normal", &PyDbPoint::normal)
        .def("setNormal", &PyDbPoint::setNormal)
        .def("ecsRotation", &PyDbPoint::ecsRotation)
        .def("setEcsRotation", &PyDbPoint::setEcsRotation)
        .def("className", &PyDbPoint::className).staticmethod("className")
        ;
}

PyDbPoint::PyDbPoint()
    : PyDbPoint::PyDbPoint(new AcDbPoint(), true)
{
}

PyDbPoint::PyDbPoint(const AcGePoint3d& point)
    : PyDbPoint::PyDbPoint(new AcDbPoint(point), true)
{
}

PyDbPoint::PyDbPoint(AcDbPoint* ptr, bool autoDelete)
    : PyDbEntity(ptr, autoDelete)
{
}

PyDbPoint::PyDbPoint(const PyDbObjectId& id, AcDb::OpenMode mode)
    : PyDbEntity(nullptr, false)
{
    AcDbPoint* pobj = nullptr;
    if (auto es = acdbOpenObject<AcDbPoint>(pobj, id.m_id, mode); es != eOk)
        throw PyAcadErrorStatus(es);
    this->resetImp(pobj, false, true);
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
}

AcGePoint3d PyDbPoint::position() const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->position();
}

Acad::ErrorStatus PyDbPoint::setPosition(const AcGePoint3d& val)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->setPosition(val);
}

double PyDbPoint::thickness() const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->thickness();
}

Acad::ErrorStatus PyDbPoint::setThickness(double val)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->setThickness(val);
}

AcGeVector3d PyDbPoint::normal() const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->normal();
}

Acad::ErrorStatus PyDbPoint::setNormal(const AcGeVector3d& val)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->setNormal(val);
}

double PyDbPoint::ecsRotation() const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->ecsRotation();
}

Acad::ErrorStatus PyDbPoint::setEcsRotation(double val)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->setEcsRotation(val);
}

std::string PyDbPoint::className()
{
    return "AcDbPoint";
}

AcDbPoint* PyDbPoint::impObj() const
{
    return static_cast<AcDbPoint*>(m_pImp.get());
}

//-----------------------------------------------------------------------------------
//PyDb2dPolyline
AcGePoint3dArray& listToAcGePoint3dArrayRef(const boost::python::list& list)
{
    //TODO: maybe this can be done better
    auto vec = py_list_to_std_vector<AcGePoint3d>(list);
    static AcGePoint3dArray arr;
    arr.removeAll();
    for (const AcGePoint3d& pnt : vec)
        arr.append(pnt);
    return arr;
}

void makePyDb2dPolylineWrapper()
{
    static auto wrapper = class_<PyDb2dPolyline, bases<PyDbCurve>>("Polyline2d")
        .def(init<>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode>())
        .def(init<AcDb::Poly2dType, const boost::python::list&, Adesk::Boolean>())
        .def("polyType", &PyDb2dPolyline::polyType)
        .def("setPolyType", &PyDb2dPolyline::setPolyType)
        .def("convertToPolyType", &PyDb2dPolyline::convertToPolyType)
        .def("makeClosed", &PyDb2dPolyline::makeClosed)
        .def("makeOpen", &PyDb2dPolyline::makeOpen)
        .def("setClosed", &PyDb2dPolyline::setClosed)
        .def("constantWidth", &PyDb2dPolyline::constantWidth)
        .def("setConstantWidth", &PyDb2dPolyline::setConstantWidth)
        .def("length", &PyDb2dPolyline::length)
        .def("defaultStartWidth", &PyDb2dPolyline::defaultStartWidth)
        .def("setDefaultStartWidth", &PyDb2dPolyline::setDefaultStartWidth)
        .def("defaultEndWidth", &PyDb2dPolyline::defaultEndWidth)
        .def("setDefaultEndWidth", &PyDb2dPolyline::setDefaultEndWidth)
        .def("thickness", &PyDb2dPolyline::thickness)
        .def("setThickness", &PyDb2dPolyline::setThickness)
        .def("normal", &PyDb2dPolyline::normal)
        .def("setNormal", &PyDb2dPolyline::setNormal)
        .def("elevation", &PyDb2dPolyline::elevation)
        .def("setElevation", &PyDb2dPolyline::setElevation)
        .def("isLinetypeGenerationOn", &PyDb2dPolyline::isLinetypeGenerationOn)
        .def("setLinetypeGenerationOn", &PyDb2dPolyline::setLinetypeGenerationOn)
        .def("setLinetypeGenerationOff", &PyDb2dPolyline::setLinetypeGenerationOff)
        .def("straighten", &PyDb2dPolyline::straighten)

        .def<Acad::ErrorStatus(PyDb2dPolyline::*)(void)>("splineFit", &PyDb2dPolyline::splineFit)
        .def<Acad::ErrorStatus(PyDb2dPolyline::*)(AcDb::Poly2dType, Adesk::Int16)>("splineFit", &PyDb2dPolyline::splineFit)

        .def<Acad::ErrorStatus(PyDb2dPolyline::*)(const PyDb2dVertex&)>("appendVertex", &PyDb2dPolyline::appendVertex)
        .def<Acad::ErrorStatus(PyDb2dPolyline::*)(PyDbObjectId&, const PyDb2dVertex&)>("appendVertex", &PyDb2dPolyline::appendVertex)

        .def<Acad::ErrorStatus(PyDb2dPolyline::*)(const PyDb2dVertex&, PyDb2dVertex&)>("insertVertexAt", &PyDb2dPolyline::insertVertexAt)
        .def<Acad::ErrorStatus(PyDb2dPolyline::*)(PyDbObjectId&, const PyDbObjectId&, PyDb2dVertex&)>("insertVertexAt", &PyDb2dPolyline::insertVertexAt)

        .def("openVertex", &PyDb2dPolyline::openVertex)
        .def("openSequenceEnd", &PyDb2dPolyline::openSequenceEnd)
        .def("vertexIds", &PyDb2dPolyline::vertexIds)
        .def("vertexPosition", &PyDb2dPolyline::vertexPosition)
        .def("makeClosedIfStartAndEndVertexCoincide", &PyDb2dPolyline::makeClosedIfStartAndEndVertexCoincide)
        .def("className", &PyDb2dPolyline::className).staticmethod("className")
        ;
}

PyDb2dPolyline::PyDb2dPolyline()
    : PyDbCurve(new AcDb2dPolyline(), true)
{
}

PyDb2dPolyline::PyDb2dPolyline(AcDb2dPolyline* ptr, bool autoDelete)
    : PyDbCurve(ptr, autoDelete)
{
}

PyDb2dPolyline::PyDb2dPolyline(const PyDbObjectId& id, AcDb::OpenMode mode)
    : PyDbCurve(nullptr, false)
{
    AcDb2dPolyline* pobj = nullptr;
    if (auto es = acdbOpenObject<AcDb2dPolyline>(pobj, id.m_id, mode); es != eOk)
        throw PyAcadErrorStatus(es);
    this->resetImp(pobj, false, true);
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
}

PyDb2dPolyline::PyDb2dPolyline(AcDb::Poly2dType type, const boost::python::list& vertices, Adesk::Boolean closed)
    : PyDbCurve(new AcDb2dPolyline(type, listToAcGePoint3dArrayRef(vertices), 0.0, closed), true)
{

}

AcDb::Poly2dType PyDb2dPolyline::polyType() const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->polyType();
}

Acad::ErrorStatus PyDb2dPolyline::setPolyType(AcDb::Poly2dType val)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->setPolyType(val);
}

Acad::ErrorStatus PyDb2dPolyline::convertToPolyType(AcDb::Poly2dType val)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->convertToPolyType(val);
}

Acad::ErrorStatus PyDb2dPolyline::makeClosed()
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->makeClosed();
}

Acad::ErrorStatus PyDb2dPolyline::makeOpen()
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->makeOpen();
}

Acad::ErrorStatus PyDb2dPolyline::setClosed(Adesk::Boolean val)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->setClosed(val);
}

double PyDb2dPolyline::constantWidth() const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    double val;
    if (auto es = imp->constantWidth(val); es != eOk)
        throw PyAcadErrorStatus(es);
    return val;
}

Acad::ErrorStatus PyDb2dPolyline::setConstantWidth(double val)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->setConstantWidth(val);
}

double PyDb2dPolyline::length() const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    double val;
    if (auto es = imp->length(val); es != eOk)
        throw PyAcadErrorStatus(es);
    return val;
}

double PyDb2dPolyline::defaultStartWidth() const
{

    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->defaultStartWidth();
}

Acad::ErrorStatus PyDb2dPolyline::setDefaultStartWidth(double val)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->setDefaultStartWidth(val);
}

double PyDb2dPolyline::defaultEndWidth() const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->defaultEndWidth();
}

Acad::ErrorStatus PyDb2dPolyline::setDefaultEndWidth(double val)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->setDefaultEndWidth(val);
}

double PyDb2dPolyline::thickness() const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->thickness();
}

Acad::ErrorStatus PyDb2dPolyline::setThickness(double val)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->setThickness(val);
}

AcGeVector3d PyDb2dPolyline::normal() const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->normal();
}

Acad::ErrorStatus PyDb2dPolyline::setNormal(const AcGeVector3d& val)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->setNormal(val);
}

double PyDb2dPolyline::elevation() const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->elevation();
}

Acad::ErrorStatus PyDb2dPolyline::setElevation(double val)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->setElevation(val);
}

Adesk::Boolean PyDb2dPolyline::isLinetypeGenerationOn() const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->isLinetypeGenerationOn();
}

Acad::ErrorStatus PyDb2dPolyline::setLinetypeGenerationOn()
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->setLinetypeGenerationOn();
}

Acad::ErrorStatus PyDb2dPolyline::setLinetypeGenerationOff()
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->setLinetypeGenerationOff();
}

Acad::ErrorStatus PyDb2dPolyline::straighten()
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->straighten();
}

Acad::ErrorStatus PyDb2dPolyline::splineFit()
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->splineFit();
}

Acad::ErrorStatus PyDb2dPolyline::splineFit(AcDb::Poly2dType splineType, Adesk::Int16 splineSegs)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->splineFit(splineType, splineSegs);
}

Acad::ErrorStatus PyDb2dPolyline::appendVertex(const PyDb2dVertex& vt)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->appendVertex(vt.impObj());
}

Acad::ErrorStatus PyDb2dPolyline::appendVertex(PyDbObjectId& id, const PyDb2dVertex& vt)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->appendVertex(id.m_id, vt.impObj());
}

Acad::ErrorStatus PyDb2dPolyline::insertVertexAt(const PyDb2dVertex& pIndexVert, PyDb2dVertex& pNewVertex)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->insertVertexAt(pIndexVert.impObj(), pNewVertex.impObj());
}

Acad::ErrorStatus PyDb2dPolyline::insertVertexAt(PyDbObjectId& newVertId, const PyDbObjectId& indexVertId, PyDb2dVertex& pNewVertex)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->insertVertexAt(newVertId.m_id, indexVertId.m_id, pNewVertex.impObj());
}

Acad::ErrorStatus PyDb2dPolyline::openVertex(PyDb2dVertex& vt, const PyDbObjectId& vertId, AcDb::OpenMode mode) const
{
    vt = PyDb2dVertex(vertId, mode);
    return eOk;
}

Acad::ErrorStatus PyDb2dPolyline::openSequenceEnd(PyDbSequenceEnd& end, AcDb::OpenMode mode)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    AcDbSequenceEnd* pEnd = nullptr;
    auto es = imp->openSequenceEnd(pEnd, mode);
    if (es == eOk)
        end = PyDbSequenceEnd(pEnd, true);
    return es;
}

boost::python::list PyDb2dPolyline::vertexIds() const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    boost::python::list ids;
    for (std::unique_ptr<AcDbObjectIterator> iter(imp->vertexIterator()); !iter->done(); iter->step())
        ids.append(iter->objectId());
    return ids;
}

AcGePoint3d PyDb2dPolyline::vertexPosition(const AcDb2dVertex& vert) const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->vertexPosition(vert);
}

Acad::ErrorStatus PyDb2dPolyline::makeClosedIfStartAndEndVertexCoincide(double distTol)
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->makeClosedIfStartAndEndVertexCoincide(distTol);
#endif
}

std::string PyDb2dPolyline::className()
{
    return "AcDb2dPolyline";
}

AcDb2dPolyline* PyDb2dPolyline::impObj() const
{
    return static_cast<AcDb2dPolyline*>(m_pImp.get());
}

//-----------------------------------------------------------------------------------
//PyDb3dPolyline
void makePyDb3dPolylineWrapper()
{
    static auto wrapper = class_<PyDb3dPolyline, bases<PyDbCurve>>("Polyline3d")
        .def(init<>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode>())
        .def(init<AcDb::Poly3dType, const boost::python::list&, Adesk::Boolean>())
        .def("length", &PyDb3dPolyline::length)
        .def("setClosed", &PyDb3dPolyline::setClosed)
        .def("makeClosed", &PyDb3dPolyline::makeClosed)
        .def("makeOpen", &PyDb3dPolyline::makeOpen)
        .def("polyType", &PyDb3dPolyline::polyType)
        .def("setPolyType", &PyDb3dPolyline::setPolyType)
        .def("convertToPolyType", &PyDb3dPolyline::convertToPolyType)
        .def("straighten", &PyDb3dPolyline::straighten)
        .def<Acad::ErrorStatus(PyDb3dPolyline::*)(void)>("splineFit", &PyDb3dPolyline::splineFit)
        .def<Acad::ErrorStatus(PyDb3dPolyline::*)(AcDb::Poly3dType, Adesk::Int16)>("splineFit", &PyDb3dPolyline::splineFit)
        .def<Acad::ErrorStatus(PyDb3dPolyline::*)(const PyDb3dPolylineVertex&)>("appendVertex", &PyDb3dPolyline::appendVertex)
        .def<Acad::ErrorStatus(PyDb3dPolyline::*)(PyDbObjectId&, const PyDb3dPolylineVertex&)>("appendVertex", &PyDb3dPolyline::appendVertex)
        .def<Acad::ErrorStatus(PyDb3dPolyline::*)(const PyDb3dPolylineVertex&, PyDb3dPolylineVertex&)>("insertVertexAt", &PyDb3dPolyline::insertVertexAt)
        .def<Acad::ErrorStatus(PyDb3dPolyline::*)(PyDbObjectId&, const PyDbObjectId&, PyDb3dPolylineVertex&)>("insertVertexAt", &PyDb3dPolyline::insertVertexAt)
        .def("openVertex", &PyDb3dPolyline::openVertex)
        .def("openSequenceEnd", &PyDb3dPolyline::openSequenceEnd)
        .def("vertexIds", &PyDb3dPolyline::vertexIds)
        .def("className", &PyDb3dPolyline::className).staticmethod("className")
        ;
}

PyDb3dPolyline::PyDb3dPolyline()
    : PyDbCurve(new AcDb3dPolyline(), true)
{
}

PyDb3dPolyline::PyDb3dPolyline(AcDb3dPolyline* ptr, bool autoDelete)
    : PyDbCurve(ptr, true)
{
}

PyDb3dPolyline::PyDb3dPolyline(const PyDbObjectId& id, AcDb::OpenMode mode)
    : PyDbCurve(nullptr, false)
{
    AcDb3dPolyline* pobj = nullptr;
    if (auto es = acdbOpenObject<AcDb3dPolyline>(pobj, id.m_id, mode); es != eOk)
        throw PyAcadErrorStatus(es);
    this->resetImp(pobj, false, true);
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
}

PyDb3dPolyline::PyDb3dPolyline(AcDb::Poly3dType pt, const boost::python::list& vertices, Adesk::Boolean closed)
    : PyDbCurve(new AcDb3dPolyline(pt, listToAcGePoint3dArrayRef(vertices), closed), true)
{
}

double PyDb3dPolyline::length() const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    double val;
    if (auto es = imp->length(val); es != eOk)
        throw PyAcadErrorStatus(es);
    return val;
}

Acad::ErrorStatus PyDb3dPolyline::setClosed(Adesk::Boolean val)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->setClosed(val);
}

Acad::ErrorStatus PyDb3dPolyline::makeClosed()
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->makeClosed();
}

Acad::ErrorStatus PyDb3dPolyline::makeOpen()
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->makeOpen();
}

AcDb::Poly3dType PyDb3dPolyline::polyType() const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->polyType();
}

Acad::ErrorStatus PyDb3dPolyline::setPolyType(AcDb::Poly3dType val)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->setPolyType(val);
}

Acad::ErrorStatus PyDb3dPolyline::convertToPolyType(AcDb::Poly3dType val)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->convertToPolyType(val);
}

Acad::ErrorStatus PyDb3dPolyline::straighten()
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->straighten();
}

Acad::ErrorStatus PyDb3dPolyline::splineFit()
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->splineFit();
}

Acad::ErrorStatus PyDb3dPolyline::splineFit(AcDb::Poly3dType splineType, Adesk::Int16 splineSegs)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->splineFit(splineType, splineSegs);
}

Acad::ErrorStatus PyDb3dPolyline::appendVertex(const PyDb3dPolylineVertex& vt)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->appendVertex(vt.impObj());
}

Acad::ErrorStatus PyDb3dPolyline::appendVertex(PyDbObjectId& id, const PyDb3dPolylineVertex& vt)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->appendVertex(id.m_id, vt.impObj());
}

Acad::ErrorStatus PyDb3dPolyline::insertVertexAt(const PyDb3dPolylineVertex& pIndexVert, PyDb3dPolylineVertex& pNewVertex)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->insertVertexAt(pIndexVert.impObj(), pNewVertex.impObj());
}

Acad::ErrorStatus PyDb3dPolyline::insertVertexAt(PyDbObjectId& newVertId, const PyDbObjectId& indexVertId, PyDb3dPolylineVertex& pNewVertex)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->insertVertexAt(newVertId.m_id, indexVertId.m_id, pNewVertex.impObj());
}

Acad::ErrorStatus PyDb3dPolyline::openVertex(PyDb3dPolylineVertex& vt, const PyDbObjectId& vertId, AcDb::OpenMode mode) const
{
    vt = PyDb3dPolylineVertex(vertId, mode);
    return eOk;
}

Acad::ErrorStatus PyDb3dPolyline::openSequenceEnd(PyDbSequenceEnd& end, AcDb::OpenMode mode)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    AcDbSequenceEnd* pEnd = nullptr;
    auto es = imp->openSequenceEnd(pEnd, mode);
    if (es == eOk)
        end = PyDbSequenceEnd(pEnd, true);
    return es;
}

boost::python::list PyDb3dPolyline::vertexIds() const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    boost::python::list ids;
    for (std::unique_ptr<AcDbObjectIterator> iter(imp->vertexIterator()); !iter->done(); iter->step())
        ids.append(iter->objectId());
    return ids;
}

std::string PyDb3dPolyline::className()
{
    return "AcDb3dPolyline";
}

AcDb3dPolyline* PyDb3dPolyline::impObj() const
{
    return static_cast<AcDb3dPolyline*>(m_pImp.get());
}

//-----------------------------------------------------------------------------------
//PyDbArc
void makePyDbArcWrapper()
{
    static auto wrapper = class_<PyDbArc, bases<PyDbCurve>>("Arc")
        .def(init<>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode>())
        .def(init<const AcGePoint3d&, double, double, double>())
        .def(init<const AcGePoint3d&, const AcGeVector3d&, double, double, double>())
        .def("center", &PyDbArc::center)
        .def("setCenter", &PyDbArc::setCenter)
        .def("radius", &PyDbArc::radius)
        .def("setRadius", &PyDbArc::setRadius)
        .def("startAngle", &PyDbArc::startAngle)
        .def("setStartAngle", &PyDbArc::setStartAngle)
        .def("endAngle", &PyDbArc::endAngle)
        .def("setEndAngle", &PyDbArc::setEndAngle)
        .def("totalAngle", &PyDbArc::totalAngle)
        .def("length", &PyDbArc::length)
        .def("thickness", &PyDbArc::thickness)
        .def("setThickness", &PyDbArc::setThickness)
        .def("normal", &PyDbArc::normal)
        .def("setNormal", &PyDbArc::setNormal)
        .def("className", &PyDbArc::className).staticmethod("className")
        ;
}

PyDbArc::PyDbArc()
    : PyDbCurve(new AcDbArc(), true)
{
}

PyDbArc::PyDbArc(AcDbArc* ptr, bool autoDelete)
    : PyDbCurve(ptr, autoDelete)
{
}

PyDbArc::PyDbArc(const PyDbObjectId& id, AcDb::OpenMode mode)
    : PyDbCurve(nullptr, false)
{
    AcDbArc* pobj = nullptr;
    if (auto es = acdbOpenObject<AcDbArc>(pobj, id.m_id, mode); es != eOk)
        throw PyAcadErrorStatus(es);
    this->resetImp(pobj, false, true);
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
}

PyDbArc::PyDbArc(const AcGePoint3d& center, double radius, double startAngle, double endAngle)
    : PyDbCurve(new AcDbArc(center, radius, startAngle, endAngle), true)
{
}

PyDbArc::PyDbArc(const AcGePoint3d& center, const AcGeVector3d& normal, double radius, double startAngle, double endAngle)
    : PyDbCurve(new AcDbArc(center, normal, radius, startAngle, endAngle), true)
{
}

AcGePoint3d PyDbArc::center() const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->center();
}

Acad::ErrorStatus PyDbArc::setCenter(const AcGePoint3d& val)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->setCenter(val);
}

double PyDbArc::radius() const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->radius();
}

Acad::ErrorStatus PyDbArc::setRadius(double val)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->setRadius(val);
}

double PyDbArc::startAngle() const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->startAngle();
}

Acad::ErrorStatus PyDbArc::setStartAngle(double val)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->setStartAngle(val);
}

double PyDbArc::endAngle() const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->endAngle();
}

Acad::ErrorStatus PyDbArc::setEndAngle(double val)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->setEndAngle(val);
}

double PyDbArc::totalAngle() const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->totalAngle();
}

double PyDbArc::length() const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->length();
}

double PyDbArc::thickness() const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->thickness();
}

Acad::ErrorStatus PyDbArc::setThickness(double val)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->setThickness(val);
}

AcGeVector3d PyDbArc::normal() const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->normal();
}

Acad::ErrorStatus PyDbArc::setNormal(const AcGeVector3d& val)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->setNormal(val);
}

std::string PyDbArc::className()
{
    return "AcDbArc";
}

AcDbArc* PyDbArc::impObj() const
{
    return static_cast<AcDbArc*>(m_pImp.get());
}

//-----------------------------------------------------------------------------------
//PyDbCircle
void makPyDbCircleWrapper()
{
    static auto wrapper = class_<PyDbCircle, bases<PyDbCurve>>("Circle")
        .def(init<>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode>())
        .def(init<const AcGePoint3d&, const AcGeVector3d&, double>())
        .def("center", &PyDbCircle::center)
        .def("setCenter", &PyDbCircle::setCenter)
        .def("radius", &PyDbCircle::radius)
        .def("setRadius", &PyDbCircle::setRadius)
        .def("thickness", &PyDbCircle::thickness)
        .def("setThickness", &PyDbCircle::setThickness)
        .def("normal", &PyDbCircle::normal)
        .def("setNormal", &PyDbCircle::setNormal)
        .def("circumference", &PyDbCircle::circumference)
        .def("setCircumference", &PyDbCircle::setCircumference)
        .def("diameter", &PyDbCircle::diameter)
        .def("setDiameter", &PyDbCircle::setDiameter)
        .def("className", &PyDbCircle::className).staticmethod("className")
        ;
}

PyDbCircle::PyDbCircle()
    : PyDbCurve(new AcDbCircle(), true)
{
}

PyDbCircle::PyDbCircle(AcDbCircle* ptr, bool autoDelete)
    : PyDbCurve(ptr, autoDelete)
{
}

PyDbCircle::PyDbCircle(const PyDbObjectId& id, AcDb::OpenMode mode)
    : PyDbCurve(nullptr, false)
{
    AcDbCircle* pobj = nullptr;
    if (auto es = acdbOpenObject<AcDbCircle>(pobj, id.m_id, mode); es != eOk)
        throw PyAcadErrorStatus(es);
    this->resetImp(pobj, false, true);
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
}

PyDbCircle::PyDbCircle(const AcGePoint3d& cntr, const AcGeVector3d& nrm, double radius)
    : PyDbCurve(new AcDbCircle(cntr, nrm, radius), true)
{
}

AcGePoint3d PyDbCircle::center() const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->center();
}

Acad::ErrorStatus PyDbCircle::setCenter(const AcGePoint3d& val)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->setCenter(val);
}

double PyDbCircle::radius() const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->radius();
}

Acad::ErrorStatus PyDbCircle::setRadius(double val)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->setRadius(val);
}

double PyDbCircle::thickness() const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->thickness();
}

Acad::ErrorStatus PyDbCircle::setThickness(double val)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->setThickness(val);
}

AcGeVector3d PyDbCircle::normal() const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->normal();
}

Acad::ErrorStatus PyDbCircle::setNormal(const AcGeVector3d& val)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->setNormal(val);
}

double PyDbCircle::circumference() const
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->circumference();
#endif
}

Acad::ErrorStatus PyDbCircle::setCircumference(double val)
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->setCircumference(val);
#endif
}

double PyDbCircle::diameter() const
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->diameter();
#endif
}

Acad::ErrorStatus PyDbCircle::setDiameter(double val)
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->setDiameter(val);
#endif
}

std::string PyDbCircle::className()
{
    return "AcDbCircle";
}

AcDbCircle* PyDbCircle::impObj() const
{
    return static_cast<AcDbCircle*>(m_pImp.get());
}

//-----------------------------------------------------------------------------------
//PyDbLine
void makPyDbLineWrapper()
{
    static auto wrapper = class_<PyDbLine, bases<PyDbCurve>>("Line")
        .def(init<>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode>())
        .def(init<const AcGePoint3d&, const AcGePoint3d&>())
        .def("startPoint", &PyDbLine::startPoint)
        .def("setStartPoint", &PyDbLine::setStartPoint)
        .def("endPoint", &PyDbLine::endPoint)
        .def("setEndPoint", &PyDbLine::setEndPoint)
        .def("thickness", &PyDbLine::thickness)
        .def("setThickness", &PyDbLine::setThickness)
        .def("normal", &PyDbLine::normal)
        .def("setNormal", &PyDbLine::setNormal)
        .def("getOffsetCurvesGivenPlaneNormal", &PyDbLine::getOffsetCurvesGivenPlaneNormal)
        .def("className", &PyDbLine::className).staticmethod("className")
        ;
}

PyDbLine::PyDbLine()
    : PyDbCurve(new AcDbLine(), true)
{
}

PyDbLine::PyDbLine(AcDbLine* ptr, bool autoDelete)
    : PyDbCurve(ptr, autoDelete)
{
}

PyDbLine::PyDbLine(const PyDbObjectId& id, AcDb::OpenMode mode)
    : PyDbCurve(nullptr, false)
{
    AcDbLine* pobj = nullptr;
    if (auto es = acdbOpenObject<AcDbLine>(pobj, id.m_id, mode); es != eOk)
        throw PyAcadErrorStatus(es);
    this->resetImp(pobj, false, true);
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
}

PyDbLine::PyDbLine(const AcGePoint3d& start, const AcGePoint3d& end)
    : PyDbCurve(new AcDbLine(start, end), true)
{
}

AcGePoint3d PyDbLine::startPoint() const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->startPoint();
}

Acad::ErrorStatus PyDbLine::setStartPoint(const AcGePoint3d& val)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->setStartPoint(val);
}

AcGePoint3d PyDbLine::endPoint() const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->endPoint();
}

Acad::ErrorStatus PyDbLine::setEndPoint(const AcGePoint3d& val)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->setEndPoint(val);
}

double PyDbLine::thickness() const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->thickness();
}

Acad::ErrorStatus PyDbLine::setThickness(double val)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->setThickness(val);
}

AcGeVector3d PyDbLine::normal() const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->normal();
}

Acad::ErrorStatus PyDbLine::setNormal(const AcGeVector3d& val)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->setNormal(val);
}

boost::python::list PyDbLine::getOffsetCurvesGivenPlaneNormal(const AcGeVector3d& normal, double offsetDist) const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    boost::python::list curves;
    AcDbVoidPtrArray offsetCurves;
    if (auto es = imp->getOffsetCurvesGivenPlaneNormal(normal, offsetDist, offsetCurves); es != eOk)
        throw PyAcadErrorStatus(es);
    for (auto ptr : offsetCurves)
        curves.append(PyDbEntity(static_cast<AcDbEntity*>(ptr), true));
    return curves;
}

std::string PyDbLine::className()
{
    return "AcDbLine";
}

AcDbLine* PyDbLine::impObj() const
{
    return static_cast<AcDbLine*>(m_pImp.get());
}

//-----------------------------------------------------------------------------------
//PyDbPolyline
void makPyDbPolylineWrapper()
{
    static auto wrapper = class_<PyDbPolyline, bases<PyDbCurve>>("Polyline")
        .def(init<>())
        .def(init<unsigned int>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode>())
        .def("getPoint3dAt", &PyDbPolyline::getPoint3dAt)
        .def("getPoint2dAt", &PyDbPolyline::getPoint2dAt)
        .def("segType", &PyDbPolyline::segType)
        .def("onSegAt", &PyDbPolyline::onSegAt)
        .def("getLineSeg2dAt", &PyDbPolyline::getLineSeg2dAt)
        .def("getLineSeg3dAt", &PyDbPolyline::getLineSeg3dAt)
        .def("getArcSeg2dAt", &PyDbPolyline::getArcSeg2dAt)
        .def("getArcSeg3dAt", &PyDbPolyline::getArcSeg3dAt)
        .def("setClosed", &PyDbPolyline::setClosed)
        .def("setPlinegen", &PyDbPolyline::setPlinegen)
        .def("setElevation", &PyDbPolyline::setElevation)
        .def("setThickness", &PyDbPolyline::setThickness)
        .def("setConstantWidth", &PyDbPolyline::setConstantWidth)
        .def("setNormal", &PyDbPolyline::setNormal)
        .def("isOnlyLines", &PyDbPolyline::isOnlyLines)
        .def("hasPlinegen", &PyDbPolyline::hasPlinegen)
        .def("elevation", &PyDbPolyline::elevation)
        .def("thickness", &PyDbPolyline::thickness)
        .def("getConstantWidth", &PyDbPolyline::getConstantWidth)
        .def("normal", &PyDbPolyline::normal)
        .def("addVertexAt", &PyDbPolyline::addVertexAt1)
        .def("addVertexAt", &PyDbPolyline::addVertexAt2)
        .def("removeVertexAt", &PyDbPolyline::removeVertexAt)
        .def("numVerts", &PyDbPolyline::numVerts)
        .def("getBulgeAt", &PyDbPolyline::getBulgeAt)
        .def("getStartWidthAt", &PyDbPolyline::getStartWidthAt)
        .def("getEndWidthAt", &PyDbPolyline::getEndWidthAt)
        .def("setPointAt", &PyDbPolyline::setPointAt)
        .def("setBulgeAt", &PyDbPolyline::setBulgeAt)
        .def("setWidthsAt", &PyDbPolyline::setWidthsAt)
        .def("minimizeMemory", &PyDbPolyline::minimizeMemory)
        .def("maximizeMemory", &PyDbPolyline::maximizeMemory)
        .def("reset", &PyDbPolyline::reset)
        .def("hasBulges", &PyDbPolyline::hasBulges)
        .def("hasVertexIdentifiers", &PyDbPolyline::hasVertexIdentifiers)
        .def("hasWidth", &PyDbPolyline::hasWidth)
        .def("makeClosedIfStartAndEndVertexCoincide", &PyDbPolyline::makeClosedIfStartAndEndVertexCoincide)
        .def("getEcs", &PyDbPolyline::getEcs)
        .def("getEcs", &PyDbPolyline::getEcs)
        .def("className", &PyDbPolyline::className).staticmethod("className")
        ;
    enum_<AcDbPolyline::SegType>("SegType")
        .value("kLine", AcDbPolyline::SegType::kLine)
        .value("kArc", AcDbPolyline::SegType::kArc)
        .value("kCoincident", AcDbPolyline::SegType::kCoincident)
        .value("kPoint", AcDbPolyline::SegType::kPoint)
        .value("kEmpty", AcDbPolyline::SegType::kEmpty)
        ;
}

PyDbPolyline::PyDbPolyline()
    : PyDbCurve(new AcDbPolyline(), true)
{
}

PyDbPolyline::PyDbPolyline(unsigned int num_verts)
    : PyDbCurve(new AcDbPolyline(num_verts), true)
{
}

PyDbPolyline::PyDbPolyline(AcDbPolyline* ptr, bool autoDelete)
    : PyDbCurve(ptr, autoDelete)
{
}

PyDbPolyline::PyDbPolyline(const PyDbObjectId& id, AcDb::OpenMode mode)
    : PyDbCurve(nullptr, false)
{
    AcDbPolyline* pobj = nullptr;
    if (auto es = acdbOpenObject<AcDbPolyline>(pobj, id.m_id, mode); es != eOk)
        throw PyAcadErrorStatus(es);
    this->resetImp(pobj, false, true);
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
}

AcGePoint3d PyDbPolyline::getPoint3dAt(unsigned int idx) const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    AcGePoint3d pnt;
    if (auto es = imp->getPointAt(idx, pnt); es != eOk)
        throw PyAcadErrorStatus(es);
    return pnt;
}

AcGePoint2d PyDbPolyline::getPoint2dAt(unsigned int idx) const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    AcGePoint2d pnt;
    if (auto es = imp->getPointAt(idx, pnt); es != eOk)
        throw PyAcadErrorStatus(es);
    return pnt;
}

AcDbPolyline::SegType PyDbPolyline::segType(unsigned int index) const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->segType(index);
}

Adesk::Boolean PyDbPolyline::onSegAt(unsigned int index, const AcGePoint2d& pt2d, double param) const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    double _param = param;
    return imp->onSegAt(index, pt2d, _param);
}

PyGeLineSeg2d PyDbPolyline::getLineSeg2dAt(unsigned int index)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    AcGeLineSeg2d seg;
    if (auto es = imp->getLineSegAt(index, seg); es != eOk)
        throw PyAcadErrorStatus(es);
    return PyGeLineSeg2d(seg.copy());
}

PyGeLineSeg3d PyDbPolyline::getLineSeg3dAt(unsigned int index)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    AcGeLineSeg3d seg;
    if (auto es = imp->getLineSegAt(index, seg); es != eOk)
        throw PyAcadErrorStatus(es);
    return PyGeLineSeg3d(seg.copy());
}

PyGeCircArc2d PyDbPolyline::getArcSeg2dAt(unsigned int index)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    AcGeCircArc2d seg;
    if (auto es = imp->getArcSegAt(index, seg); es != eOk)
        throw PyAcadErrorStatus(es);
    return PyGeCircArc2d(seg.copy());
}

PyGeCircArc3d PyDbPolyline::getArcSeg3dAt(unsigned int index)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    AcGeCircArc3d seg;
    if (auto es = imp->getArcSegAt(index, seg); es != eOk)
        throw PyAcadErrorStatus(es);
    return PyGeCircArc3d(seg.copy());
}

void PyDbPolyline::setClosed(Adesk::Boolean val)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    imp->setClosed(val);
}

void PyDbPolyline::setPlinegen(Adesk::Boolean val)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    imp->setPlinegen(val);
}

void PyDbPolyline::setElevation(double val)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    imp->setElevation(val);
}

Acad::ErrorStatus PyDbPolyline::setThickness(double val)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->setThickness(val);
}

Acad::ErrorStatus PyDbPolyline::setConstantWidth(double val)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->setConstantWidth(val);
}

Acad::ErrorStatus PyDbPolyline::setNormal(const AcGeVector3d& val)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->setNormal(val);
}

Adesk::Boolean PyDbPolyline::isOnlyLines() const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->isOnlyLines();
}

Adesk::Boolean PyDbPolyline::hasPlinegen() const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->hasPlinegen();
}

double PyDbPolyline::elevation() const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->elevation();
}

double PyDbPolyline::thickness() const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->thickness();
}

double PyDbPolyline::getConstantWidth() const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    double w;
    if (auto es = imp->getConstantWidth(w); es != eOk)
        throw PyAcadErrorStatus(es);
    return w;
}

AcGeVector3d PyDbPolyline::normal() const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->normal();
}

Acad::ErrorStatus PyDbPolyline::addVertexAt1(unsigned int index, const AcGePoint2d& pnt)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->addVertexAt(index, pnt, 0.0, 0.0, 0.0);
}

Acad::ErrorStatus PyDbPolyline::addVertexAt2(unsigned int index, const AcGePoint2d& pnt, double bulge, double startWidth, double endWidth)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->addVertexAt(index, pnt, bulge, startWidth, endWidth);
}

Acad::ErrorStatus PyDbPolyline::removeVertexAt(unsigned int index)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->removeVertexAt(index);
}

unsigned int PyDbPolyline::numVerts() const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->numVerts();
}

double PyDbPolyline::getBulgeAt(unsigned int index) const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    double w;
    if (auto es = imp->getBulgeAt(index, w); es != eOk)
        throw PyAcadErrorStatus(es);
    return w;
}

double PyDbPolyline::getStartWidthAt(unsigned int index) const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    double s, e;
    if (auto es = imp->getWidthsAt(index, s, e); es != eOk)
        throw PyAcadErrorStatus(es);
    return s;
}

double PyDbPolyline::getEndWidthAt(unsigned int index) const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    double s, e;
    if (auto es = imp->getWidthsAt(index, s, e); es != eOk)
        throw PyAcadErrorStatus(es);
    return e;
}

Acad::ErrorStatus PyDbPolyline::setPointAt(unsigned int index, const AcGePoint2d& pt)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->setPointAt(index, pt);
}

Acad::ErrorStatus PyDbPolyline::setBulgeAt(unsigned int index, double bulge)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->setBulgeAt(index, bulge);
}

Acad::ErrorStatus PyDbPolyline::setWidthsAt(unsigned int index, double startWidth, double endWidth)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->setWidthsAt(index, startWidth, endWidth);
}

Acad::ErrorStatus PyDbPolyline::minimizeMemory()
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->minimizeMemory();
}

Acad::ErrorStatus PyDbPolyline::maximizeMemory()
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->maximizeMemory();
}

void PyDbPolyline::reset(Adesk::Boolean reuse, unsigned int numVerts)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    imp->reset(reuse, numVerts);
}

Adesk::Boolean PyDbPolyline::hasBulges() const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->hasBulges();
}

Adesk::Boolean PyDbPolyline::hasVertexIdentifiers() const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->hasVertexIdentifiers();
}

Adesk::Boolean PyDbPolyline::hasWidth() const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->hasWidth();
}

Acad::ErrorStatus PyDbPolyline::makeClosedIfStartAndEndVertexCoincide(double distTol)
{
#ifndef ARXAPP
    throw PyNotimplementedByHost();
#else
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->makeClosedIfStartAndEndVertexCoincide(distTol);
#endif
}

void PyDbPolyline::getEcs(AcGeMatrix3d& retVal) const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    imp->getEcs(retVal);
}

std::string PyDbPolyline::className()
{
    return "AcDbPolyline";
}

AcDbPolyline* PyDbPolyline::impObj() const
{
    return static_cast<AcDbPolyline*>(m_pImp.get());
}

//-----------------------------------------------------------------------------------
//PyDbDace
void makPyDbFaceWrapper()
{
    static auto wrapper = class_<PyDbFace, bases<PyDbEntity>>("Face")
        .def(init<>())
        .def(init<const AcGePoint3d&, const AcGePoint3d&, const AcGePoint3d&, Adesk::Boolean, Adesk::Boolean, Adesk::Boolean, Adesk::Boolean>())
        .def(init<const AcGePoint3d&, const AcGePoint3d&, const AcGePoint3d&, const AcGePoint3d&, Adesk::Boolean, Adesk::Boolean, Adesk::Boolean, Adesk::Boolean>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode>())
        .def("getVertexAt", &PyDbFace::getVertexAt)
        .def("setVertexAt", &PyDbFace::setVertexAt)
        .def("setVertexAt", &PyDbFace::setVertexAt)
        .def("isEdgeVisibleAt", &PyDbFace::isEdgeVisibleAt)
        .def("makeEdgeVisibleAt", &PyDbFace::makeEdgeVisibleAt)
        .def("makeEdgeInvisibleAt", &PyDbFace::makeEdgeInvisibleAt)
        .def("className", &PyDbPolyline::className).staticmethod("className")
        ;
}

PyDbFace::PyDbFace()
    : PyDbEntity(new AcDbFace(), true)
{
}

PyDbFace::PyDbFace(const AcGePoint3d& pt0, const AcGePoint3d& pt1, const AcGePoint3d& pt2, Adesk::Boolean e0vis, Adesk::Boolean e1vis, Adesk::Boolean e2vis, Adesk::Boolean e3vis)
    : PyDbEntity(new AcDbFace(pt0, pt1, pt2, e0vis, e1vis, e2vis, e3vis), true)
{
}

PyDbFace::PyDbFace(const AcGePoint3d& pt0, const AcGePoint3d& pt1, const AcGePoint3d& pt2, const AcGePoint3d& pt3, Adesk::Boolean e0vis, Adesk::Boolean e1vis, Adesk::Boolean e2vis, Adesk::Boolean e3vis)
    : PyDbEntity(new AcDbFace(pt0, pt1, pt2, pt3, e0vis, e1vis, e2vis, e3vis), true)
{
}

PyDbFace::PyDbFace(AcDbPolyline* ptr, bool autoDelete)
    : PyDbEntity(ptr, autoDelete)
{
}

PyDbFace::PyDbFace(const PyDbObjectId& id, AcDb::OpenMode mode)
    : PyDbEntity(nullptr, false)
{
    AcDbFace* pobj = nullptr;
    if (auto es = acdbOpenObject<AcDbFace>(pobj, id.m_id, mode); es != eOk)
        throw PyAcadErrorStatus(es);
    this->resetImp(pobj, false, true);
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
}

AcGePoint3d PyDbFace::getVertexAt(Adesk::UInt16 val) const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    AcGePoint3d rPoint;
    if (auto es = impObj()->getVertexAt(val, rPoint); es != eOk)
        throw PyAcadErrorStatus(es);
    return rPoint;
}

Acad::ErrorStatus PyDbFace::setVertexAt(Adesk::UInt16 val, const AcGePoint3d& pnt)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->setVertexAt(val, pnt);
}

Adesk::Boolean PyDbFace::isEdgeVisibleAt(Adesk::UInt16 val) const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    Adesk::Boolean rval;
    if (auto es = impObj()->isEdgeVisibleAt(val, rval); es != eOk)
        throw PyAcadErrorStatus(es);
    return rval;
}

Acad::ErrorStatus PyDbFace::makeEdgeVisibleAt(Adesk::UInt16 val)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->makeEdgeVisibleAt(val);
}

Acad::ErrorStatus PyDbFace::makeEdgeInvisibleAt(Adesk::UInt16 val)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->makeEdgeInvisibleAt(val);
}


std::string PyDbFace::className()
{
    return "AcDbFace";
}

AcDbFace* PyDbFace::impObj() const
{
    return static_cast<AcDbFace*>(m_pImp.get());
}
