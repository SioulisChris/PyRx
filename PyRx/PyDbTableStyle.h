#pragma once
#include "PyDbObject.h"

class PyDbObjectId;

void makeAcDbTableStyleWrapper();

class PyDbTableStyle : public PyDbObject
{
public:
    PyDbTableStyle();
    PyDbTableStyle(AcDbObject* ptr, bool autoDelete);
    PyDbTableStyle(const PyDbObjectId& id, AcDb::OpenMode mode);
    virtual ~PyDbTableStyle() override = default;

    std::string getName();
    Acad::ErrorStatus setName(const std::string& pszName);

    std::string description(void) const;
    Acad::ErrorStatus  setDescription(const std::string& pszDescription);

    Adesk::UInt32       bitFlags() const;
    Acad::ErrorStatus   setBitFlags(Adesk::UInt32 flags);

    AcDb::FlowDirection flowDirection(void) const;
    Acad::ErrorStatus   setFlowDirection(AcDb::FlowDirection flow);

    virtual double horzCellMargin(void) const;
    Acad::ErrorStatus setHorzCellMargin(double dCellMargin);

    double vertCellMargin(void) const;
    Acad::ErrorStatus setVertCellMargin(double dCellMargin);

    bool isTitleSuppressed(void) const;
    Acad::ErrorStatus suppressTitleRow(bool bValue);

    bool isHeaderSuppressed(void) const;
    Acad::ErrorStatus suppressHeaderRow(bool bValue);

    PyDbObjectId        textStyle(AcDb::RowType rowType) const;
    Acad::ErrorStatus   setTextStyle(const PyDbObjectId& id, AcDb::RowType rowType);

    double              textHeight(AcDb::RowType rowType) const;
    Acad::ErrorStatus   setTextHeight(double dHeight, AcDb::RowType rowType);

    AcDb::CellAlignment alignment(AcDb::RowType rowType) const;
    Acad::ErrorStatus   setAlignment(AcDb::CellAlignment alignment, AcDb::RowType rowType);

    AcCmColor           color(AcDb::RowType rowType) const;
    Acad::ErrorStatus   setColor(const AcCmColor& color,AcDb::RowType rowType);

    AcCmColor           backgroundColor(AcDb::RowType rowType) const;
    Acad::ErrorStatus   setBackgroundColor(const AcCmColor& color, AcDb::RowType rowType);

    bool                isBackgroundColorNone(AcDb::RowType rowType ) const;
    Acad::ErrorStatus   setBackgroundColorNone(bool bValue, AcDb::RowType rowType);

    boost::python::tuple getDataType(AcDb::RowType type) const;

    Acad::ErrorStatus   setDataType1(AcValue::DataType nDataType, AcValue::UnitType nUnitType);
    Acad::ErrorStatus   setDataType2(AcValue::DataType nDataType, AcValue::UnitType nUnitType, AcDb::RowType type);

    std::string         format1(void) const;
    std::string         format2(AcDb::RowType rowType) const;

    Acad::ErrorStatus   setFormat1(const std::string& pszFormat);
    Acad::ErrorStatus   setFormat2(const std::string& pszFormat, AcDb::RowType type);

    AcDb::LineWeight    gridLineWeight(AcDb::GridLineType gridLineType, AcDb::RowType rowType) const;
    Acad::ErrorStatus   setGridLineWeight(AcDb::LineWeight lineWeight, AcDb::GridLineType gridLineType, AcDb::RowType rowType);

    AcCmColor           gridColor(AcDb::GridLineType gridLineType, AcDb::RowType rowType) const;
    Acad::ErrorStatus   setGridColor(const AcCmColor& color, AcDb::GridLineType gridLineType, AcDb::RowType rowType);

    AcDb::Visibility    gridVisibility(AcDb::GridLineType gridLineType,AcDb::RowType rowType) const;
    Acad::ErrorStatus   setGridVisibility(AcDb::Visibility visible, AcDb::GridLineType gridLineType, AcDb::RowType rowType);

    PyDbObjectId        postTableStyleToDb(PyDbDatabase& pDb, const std::string& styleName);

    std::string         createCellStyle1(void);
    Acad::ErrorStatus   createCellStyle2(const std::string& pszCellStyle);
    Acad::ErrorStatus   createCellStyle3(const std::string& pszCellStyle, const std::string& pszFromCellStyle);

    Acad::ErrorStatus   renameCellStyle(const std::string& pszOldName, const std::string& pszNewName);
    Acad::ErrorStatus   deleteCellStyle(const std::string& pszCellStyle);

    Acad::ErrorStatus   copyCellStyle(const std::string& pszSrcCellStyle, const std::string& pszTargetCellStyle);

    bool                isCellStyleInUse(const std::string& pszCellStyle) const;
    int                 numCellStyles(void) const;

    boost::python::list getCellStyles();

    PyDbObjectId        textStyle2(const std::string& pszCellStyle) const;
    Acad::ErrorStatus   setTextStyle2(const PyDbObjectId& id, const std::string& pszCellStyle);

    double              textHeight2(const std::string& pszCellStyle) const;
    Acad::ErrorStatus   setTextHeight2(double dHeight, const std::string& pszCellStyle);

    AcDb::CellAlignment alignment2(const std::string& pszCellStyle) const;
    Acad::ErrorStatus   setAlignment2(AcDb::CellAlignment alignment, const std::string& pszCellStyle);

    AcCmColor           color2(const std::string& pszCellStyle) const;
    Acad::ErrorStatus   setColor2(const AcCmColor& color, const std::string& pszCellStyle);

    AcCmColor           backgroundColor2(const std::string& pszCellStyle) const;
    Acad::ErrorStatus   setBackgroundColor2(const AcCmColor& color, const std::string& pszCellStyle);

    boost::python::tuple getDataType2(const std::string& pszCellStyle) const;
    Acad::ErrorStatus   setDataType3(AcValue::DataType nDataType, AcValue::UnitType nUnitType, const std::string& pszCellStyle);

    std::string         format3(const std::string& pszCellStyle) const;
    Acad::ErrorStatus   setFormat3(const std::string& pszFormat, const std::string& pszCellStyle);

    int                 cellClass(const std::string& pszCellStyle) const;
    Acad::ErrorStatus   setCellClass(int nClass, const std::string& pszCellStyle);

    double              rotation(const std::string& pszCellStyle) const;
    Acad::ErrorStatus   setRotation(double fRotation, const std::string& pszCellStyle);

    bool                isMergeAllEnabled(const std::string& pszCellStyle) const;
    Acad::ErrorStatus   enableMergeAll(bool bEnable, const std::string& pszCellStyle);

    double              margin(AcDb::CellMargin nMargin, const std::string& pszCellStyle) const;
    Acad::ErrorStatus   setMargin(AcDb::CellMargin nMargins, double fMargin, const std::string& pszCellStyle);

    AcDb::LineWeight    gridLineWeight2(AcDb::GridLineType gridLineType, const std::string& pszCellStyle) const;
    Acad::ErrorStatus   setGridLineWeight2(AcDb::LineWeight lineWeight, AcDb::GridLineType gridLineTypes, const std::string& pszCellStyle);

    AcCmColor           gridColor2(AcDb::GridLineType gridLineType, const std::string& pszCellStyle) const;
    Acad::ErrorStatus   setGridColor2(const AcCmColor& color,AcDb::GridLineType gridLineTypes, const std::string& pszCellStyle);

    AcDb::Visibility    gridVisibility2(AcDb::GridLineType gridLineType, const std::string& pszCellStyle) const;
    Acad::ErrorStatus   setGridVisibility2(AcDb::Visibility visible, AcDb::GridLineType gridLineTypes, const std::string& pszCellStyle);

    double              gridDoubleLineSpacing(AcDb::GridLineType gridLineType, const std::string& pszCellStyle) const;
    Acad::ErrorStatus   setGridDoubleLineSpacing(double fSpacing, AcDb::GridLineType gridLineTypes, const std::string& pszCellStyle);

    AcDb::GridLineStyle gridLineStyle(AcDb::GridLineType gridLineType, const std::string& pszCellStyle) const;
    Acad::ErrorStatus   setGridLineStyle(AcDb::GridLineStyle nLineStyle, AcDb::GridLineType gridLineTypes, const std::string& pszCellStyle);

    PyDbObjectId        gridLinetype(AcDb::GridLineType gridLineType, const std::string& pszCellStyle) const;
    Acad::ErrorStatus   setGridLinetype(const PyDbObjectId& id, AcDb::GridLineType gridLineTypes, const std::string& pszCellStyle);

    AcGridProperty      getGridProperty(AcDb::GridLineType nGridLineTypes, const std::string& pszCellStyle) const;
    Acad::ErrorStatus   setGridProperty(const AcGridProperty& gridProp, AcDb::GridLineType nGridLineTypes, const std::string& pszCellStyle);

    PyDbObjectId        getTemplate(void) const;
    Acad::ErrorStatus   setTemplate(const PyDbObjectId& templateId, AcDb::MergeCellStyleOption nOption);
    PyDbObjectId        removeTemplate(void);

    static std::string className();
    static PyRxClass desc();

public:
    AcDbTableStyle* impObj(const std::source_location& src = std::source_location::current()) const;
};

