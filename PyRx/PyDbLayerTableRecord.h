#pragma once
#include "PyDbSymbolTableRecord.h"
class PyDbObjectId;
void makeAcDbLayerTableRecordWrapper();
class PyDbLayerTableRecord : public PyDbSymbolTableRecord
{
public:
    PyDbLayerTableRecord(AcDbSymbolTableRecord* ptr, bool autoDelete);
    PyDbLayerTableRecord(const PyDbObjectId& id, AcDb::OpenMode mode);
    virtual ~PyDbLayerTableRecord() override = default;
    bool              isFrozen() const;
    Acad::ErrorStatus setIsFrozen(bool frozen);
    bool              isOff() const;
    void              setIsOff(bool off);
    bool              VPDFLT() const;
    void              setVPDFLT(bool frozen);
    bool              isLocked() const;
    void              setIsLocked(bool locked);
    AcCmColor         color() const;
    void              setColor(const AcCmColor& color);
    AcCmEntityColor   entityColor(void) const;
    AcCmTransparency  transparency(void) const;
    Acad::ErrorStatus setTransparency(const AcCmTransparency& trans);
    PyDbObjectId      linetypeObjectId() const;
    Acad::ErrorStatus setLinetypeObjectId(const PyDbObjectId& id);
    PyDbObjectId      materialId() const;
    Acad::ErrorStatus setMaterialId(const PyDbObjectId& id);
    bool              isPlottable() const;
    Acad::ErrorStatus setIsPlottable(bool plot);
    AcDb::LineWeight  lineWeight() const;
    Acad::ErrorStatus setLineWeight(AcDb::LineWeight weight);
    std::string       plotStyleName() const;
    PyDbObjectId      plotStyleNameId() const;
    Acad::ErrorStatus setPlotStyleName(const std::string& newName);
    Acad::ErrorStatus setPlotStyleName(const PyDbObjectId& newId);
    bool              isInUse() const;
    std::string       description() const;
    Acad::ErrorStatus setDescription(const std::string& description);
    bool              isHidden() const;
    Acad::ErrorStatus setIsHidden(bool on);
    static bool       isHiddenS(const PyDbObjectId& id);
    AcCmColor         color(const PyDbObjectId& viewportId) const;
    Acad::ErrorStatus setColor(const AcCmColor& color, const PyDbObjectId& viewportId);
    AcDb::LineWeight  lineWeight(const PyDbObjectId& viewportId) const;
    Acad::ErrorStatus setLineWeight(AcDb::LineWeight weight, const PyDbObjectId& viewportId);
    std::string       plotStyleName(const PyDbObjectId& viewportId) const;
    PyDbObjectId      plotStyleNameId(const PyDbObjectId& viewportId) const;
    Acad::ErrorStatus setPlotStyleName(const std::string& newName, const PyDbObjectId& viewportId);
    Acad::ErrorStatus setPlotStyleName(const PyDbObjectId& newId, const PyDbObjectId& viewportId);
    AcCmTransparency  transparency(const PyDbObjectId& viewportId) const;
    Acad::ErrorStatus setTransparency(const AcCmTransparency& trans, const PyDbObjectId& viewportId);
    Acad::ErrorStatus removeColorOverride(const PyDbObjectId& viewportId);
    Acad::ErrorStatus removeLinetypeOverride(const PyDbObjectId& viewportId);
    Acad::ErrorStatus removeLineWeightOverride(const PyDbObjectId& viewportId);
    Acad::ErrorStatus removePlotStyleOverride(const PyDbObjectId& viewportId);
    Acad::ErrorStatus removeTransparencyOverride(const PyDbObjectId& viewportId);
    Acad::ErrorStatus removeViewportOverrides(const PyDbObjectId& viewportId);
    Acad::ErrorStatus removeAllOverrides();
    bool              hasOverrides(const PyDbObjectId& viewportId) const;
    bool              hasAnyOverrides() const;
    bool              isReconciled() const;
    Acad::ErrorStatus setIsReconciled(bool bReconcile);
    static bool       isReconciledS(const PyDbObjectId& id);
    static std::string className();
    static PyRxClass  desc();
public:
    AcDbLayerTableRecord* impObj(const std::source_location& src = std::source_location::current()) const;
};
