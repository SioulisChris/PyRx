#include "stdafx.h"
#include "PyDbTable.h"
#include "PyDbObjectId.h"

PyDbTable::PyDbTable()
    : PyDbTable(new AcDbTable(), true)
{
}

PyDbTable::PyDbTable(AcDbTable* ptr, bool autoDelete)
    : PyDbBlockReference(ptr, autoDelete)
{
}

PyDbTable::PyDbTable(const PyDbObjectId& id, AcDb::OpenMode mode)
{
    AcDbTable* pobj = nullptr;
    if (auto es = acdbOpenObject<AcDbTable>(pobj, id.m_id, mode); es != eOk)
        throw PyAcadErrorStatus(es);
    this->resetImp(pobj, false, true);
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
}

PyDbObjectId PyDbTable::tableStyle() const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return PyDbObjectId(imp->tableStyle());
}

Acad::ErrorStatus PyDbTable::setTableStyle(const PyDbObjectId& id)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->setTableStyle(id.m_id);
}

AcGeVector3d PyDbTable::direction() const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->direction();
}

Acad::ErrorStatus PyDbTable::setDirection(const AcGeVector3d& horzVec)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->setDirection(horzVec);
}

Adesk::UInt32 PyDbTable::numRows() const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->numRows();
}

Adesk::UInt32 PyDbTable::numColumns() const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->numColumns();
}

double PyDbTable::width() const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->width();
}

Acad::ErrorStatus PyDbTable::setWidth(double width)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->setWidth(width);
}

double PyDbTable::columnWidth(int col) const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->columnWidth(col);
}

Acad::ErrorStatus PyDbTable::setColumnWidth1(int col, double width)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->setColumnWidth(col, width);
}

Acad::ErrorStatus PyDbTable::setColumnWidth2(double width)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->setColumnWidth(width);
}

double PyDbTable::height() const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->height();
}

Acad::ErrorStatus PyDbTable::setHeight(double height)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->setHeight(height);
}

double PyDbTable::rowHeight(int row) const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->rowHeight(row);
}

Acad::ErrorStatus PyDbTable::setRowHeight1(int row, double height)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->setRowHeight(row, height);
}

Acad::ErrorStatus PyDbTable::setRowHeight2(double height)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->setRowHeight(height);
}

double PyDbTable::minimumColumnWidth(int col) const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->minimumColumnWidth(col);
}

double PyDbTable::minimumRowHeight(int row) const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->minimumColumnWidth(row);
}

double PyDbTable::minimumTableWidth() const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->minimumTableWidth();
}

double PyDbTable::minimumTableHeight() const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->minimumTableHeight();
}

double PyDbTable::horzCellMargin() const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->horzCellMargin();
}

Acad::ErrorStatus PyDbTable::setHorzCellMargin(double gap)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->setHorzCellMargin(gap);
}

double PyDbTable::vertCellMargin() const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->vertCellMargin();
}

Acad::ErrorStatus PyDbTable::setVertCellMargin(double gap)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->setVertCellMargin(gap);
}

AcDb::FlowDirection PyDbTable::flowDirection() const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->flowDirection();
}

Acad::ErrorStatus PyDbTable::setFlowDirection(AcDb::FlowDirection flow)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->setFlowDirection(flow);
}

bool PyDbTable::isTitleSuppressed() const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->isTitleSuppressed();
}

Acad::ErrorStatus PyDbTable::suppressTitleRow(bool value)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->suppressTitleRow(value);
}

bool PyDbTable::isHeaderSuppressed() const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->isHeaderSuppressed();
}

Acad::ErrorStatus PyDbTable::suppressHeaderRow(bool value)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->suppressHeaderRow(value);
}

AcDb::CellAlignment PyDbTable::alignment(AcDb::RowType type) const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->alignment(type);
}

AcDb::CellAlignment PyDbTable::alignment2(int row, int col) const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->alignment(row, col);
}

Acad::ErrorStatus PyDbTable::setAlignment(AcDb::CellAlignment align, AcDb::RowType rowTypes)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->setAlignment(align, rowTypes);
}

Acad::ErrorStatus PyDbTable::setAlignment2(int row, int col, AcDb::CellAlignment align)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->setAlignment(row, col, align);
}

bool PyDbTable::isBackgroundColorNone(AcDb::RowType type) const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->isBackgroundColorNone(type);
}

bool PyDbTable::isBackgroundColorNone2(int row, int col) const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->isBackgroundColorNone(row, col);
}

Acad::ErrorStatus PyDbTable::setBackgroundColorNone(bool value, AcDb::RowType type)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->setBackgroundColorNone(value, type);
}

Acad::ErrorStatus PyDbTable::setBackgroundColorNone2(int row, int col, bool value)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->setBackgroundColorNone(row, col, value);
}

AcCmColor PyDbTable::backgroundColor(AcDb::RowType type) const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->backgroundColor(type);
}

Acad::ErrorStatus PyDbTable::setBackgroundColor(const AcCmColor& color, AcDb::RowType type)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->setBackgroundColor(color, type);
}

AcCmColor PyDbTable::contentColor(AcDb::RowType type) const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->contentColor(type);
}

AcCmColor PyDbTable::contentColor2(int row, int col) const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->contentColor(row, col);
}

Acad::ErrorStatus PyDbTable::setContentColor(const AcCmColor& color, AcDb::RowType type)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->setContentColor(color, type);
}

Acad::ErrorStatus PyDbTable::setContentColor2(int row, int col, const AcCmColor& color)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->setContentColor(row, col, color);
}

boost::python::list PyDbTable::cellStyleOverrides(int row, int col) const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    AcDbIntArray overrides;
    boost::python::list l;
    imp->cellStyleOverrides(row, col, overrides);
    for (auto item : overrides)
        l.append(item);
    return l;
}

void PyDbTable::clearCellOverrides(int row, int column)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->clearCellOverrides(row, column);
}

Acad::ErrorStatus PyDbTable::deleteCellContent(int row, int col)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->deleteCellContent(row, col);
}

AcDb::RowType PyDbTable::rowType(int row) const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->rowType(row);
}

boost::python::tuple PyDbTable::getDataType(AcDb::RowType type) const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    AcValue::DataType nDataType;
    AcValue::UnitType nUnitType;
    if (auto es = imp->getDataType(nDataType, nUnitType, type); es != eOk)
        throw PyAcadErrorStatus(es);
    return boost::python::make_tuple(nDataType, nUnitType);
}

boost::python::tuple PyDbTable::getDataType2(int row, int col) const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    AcValue::DataType nDataType;
    AcValue::UnitType nUnitType;
    if (auto es = imp->getDataType(row, col, nDataType, nUnitType); es != eOk)
        throw PyAcadErrorStatus(es);
    return boost::python::make_tuple(nDataType, nUnitType);
}


Acad::ErrorStatus PyDbTable::setDataType1(AcValue::DataType nDataType, AcValue::UnitType nUnitType)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->setDataType(nDataType, nUnitType);
}

Acad::ErrorStatus PyDbTable::setDataType2(AcValue::DataType nDataType, AcValue::UnitType nUnitType, AcDb::RowType type)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->setDataType(nDataType, nUnitType, type);
}

Acad::ErrorStatus PyDbTable::setDataType3(int row, int col, AcValue::DataType nDataType, AcValue::UnitType nUnitType)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->setDataType(row, col, nDataType, nUnitType);
}

Acad::ErrorStatus PyDbTable::setFormat(int row, int col, const std::string& pszFormat)
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->setFormat(row, col, utf8_to_wstr(pszFormat).c_str());
#endif

}

std::string PyDbTable::textString(int row, int col) const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return wstr_to_utf8(imp->textStringConst(row, col));
}


std::string PyDbTable::textString2(int row, int col, int nContent) const
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return wstr_to_utf8(imp->textString(row, col, nContent));
#endif
}

std::string PyDbTable::textString3(int row, int col, AcValue::FormatOption nOption) const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    AcString str;
    if (auto es = imp->textString(row, col, nOption, str); es != eOk)
        throw PyAcadErrorStatus(es);
    return wstr_to_utf8(str);
}

std::string PyDbTable::textString4(int row, int col, int nContent, AcValue::FormatOption nOption) const
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    AcString str;
    if (auto es = imp->textString(row, col, nContent, nOption, str); es != eOk)
        throw PyAcadErrorStatus(es);
    return wstr_to_utf8(str);
#endif
}

Acad::ErrorStatus PyDbTable::setTextString(int row, int col, const std::string& text)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->setTextString(row, col, utf8_to_wstr(text).c_str());
}

Acad::ErrorStatus PyDbTable::setTextString2(int row, int col, int nContent, const std::string& text)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->setTextString(row, col, nContent, utf8_to_wstr(text).c_str());
}

PyDbObjectId PyDbTable::textStyle(AcDb::RowType type) const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return PyDbObjectId(imp->textStyle(type));
}

PyDbObjectId PyDbTable::textStyle2(int row, int col) const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return PyDbObjectId(imp->textStyle(row, col));
}

Acad::ErrorStatus PyDbTable::setTextStyle(const PyDbObjectId& id, AcDb::RowType rowTypes)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->setTextStyle(id.m_id, rowTypes);
}

Acad::ErrorStatus PyDbTable::setTextStyle2(int row, int col, const PyDbObjectId& id)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->setTextStyle(row, col, id.m_id);
}

double PyDbTable::textHeight(AcDb::RowType type) const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->textHeight(type);
}

double PyDbTable::textHeight2(int row, int col) const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->textHeight(row, col);
}

Acad::ErrorStatus PyDbTable::setTextHeight(double height, AcDb::RowType rowTypes)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->setTextHeight(height, rowTypes);
}

Acad::ErrorStatus PyDbTable::setTextHeight2(int row, int col, double height)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->setTextHeight(row, col, height);
}

AcDb::LineWeight PyDbTable::gridLineWeight(AcDb::GridLineType gridlineType, AcDb::RowType type) const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->gridLineWeight(gridlineType, type);
}

AcDb::LineWeight PyDbTable::gridLineWeight2(int row, int col, AcDb::CellEdgeMask iEdge) const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->gridLineWeight(row, col, iEdge);
}

Acad::ErrorStatus PyDbTable::setGridLineWeight(AcDb::LineWeight lwt, int nBorders, int nRows)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->setGridLineWeight(lwt, nBorders, nRows);
}

Acad::ErrorStatus PyDbTable::setGridLineWeight2(int row, int col, AcDb::CellEdgeMask nEdges, AcDb::LineWeight value)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->setGridLineWeight(row, col, nEdges, value);
}

AcCmColor PyDbTable::gridColor(AcDb::GridLineType gridlineType, AcDb::RowType type) const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->gridColor(gridlineType, type);
}

AcCmColor PyDbTable::gridColor2(int row, int col, AcDb::CellEdgeMask iEdge) const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->gridColor(row, col, iEdge);
}

Acad::ErrorStatus PyDbTable::setGridColor(const AcCmColor& color, int nBorders, int nRows)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->setGridColor(color, nBorders, nRows);
}

Acad::ErrorStatus PyDbTable::setGridColor2(int row, int col, AcDb::CellEdgeMask nEdges, const AcCmColor& color)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->setGridColor(row, col, nEdges, color);
}

AcDb::Visibility PyDbTable::gridVisibility(AcDb::GridLineType gridlineType, AcDb::RowType type) const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->gridVisibility(gridlineType, type);
}

AcDb::Visibility PyDbTable::gridVisibility2(int row, int col, AcDb::CellEdgeMask iEdge) const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->gridVisibility(row, col, iEdge);
}

Acad::ErrorStatus PyDbTable::setGridVisibility(AcDb::Visibility visible, int nBorders, int nRows)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->setGridVisibility(visible, nBorders, nRows);
}

Acad::ErrorStatus PyDbTable::setGridVisibility2(int row, int col, AcDb::CellEdgeMask iEdge, AcDb::Visibility value)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->setGridVisibility(row, col, iEdge, value);
}

boost::python::list PyDbTable::tableStyleOverrides() const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    AcDbIntArray overrides;
    boost::python::list l;
    imp->tableStyleOverrides(overrides);
    for (auto item : overrides)
        l.append(item);
    return l;
}

void PyDbTable::clearTableStyleOverrides()
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    imp->clearTableStyleOverrides();
}

AcDb::CellType PyDbTable::cellType(int row, int col) const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->cellType(row, col);
}

Acad::ErrorStatus PyDbTable::setCellType(int row, int col, AcDb::CellType type)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->setCellType(row, col, type);
}

boost::python::list PyDbTable::getCellExtents(int row, int col, bool isOuterCell) const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    AcGePoint3dArray pts;
    boost::python::list l;
    if (auto es = imp->getCellExtents(row, col, isOuterCell, pts); es != eOk)
        throw PyAcadErrorStatus(es);
    for (const auto& item : pts)
        l.append(item);
    return l;
}

AcGePoint3d PyDbTable::attachmentPoint(int row, int col) const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->attachmentPoint(row, col);
}

PyDbObjectId PyDbTable::fieldId(int row, int col) const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return PyDbObjectId(imp->fieldId(row, col));
}


PyDbObjectId PyDbTable::fieldId2(int row, int col, int nContent) const
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return PyDbObjectId(imp->fieldId(row, col, nContent));
#endif
}

Acad::ErrorStatus PyDbTable::setFieldId(int row, int col, const PyDbObjectId& fieldId)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->setFieldId(row, col, fieldId.m_id);
}

Acad::ErrorStatus PyDbTable::setFieldId2(int row, int col, int nContent, const PyDbObjectId& fieldId, AcDb::CellOption nFlag)
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->setFieldId(row, col, nContent, fieldId.m_id, nFlag);
#endif
}

AcDb::RotationAngle PyDbTable::textRotation(int row, int col) const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->textRotation(row, col);
}

Acad::ErrorStatus PyDbTable::setTextRotation(int row, int col, AcDb::RotationAngle rot)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->setTextRotation(row, col, rot);
}

bool PyDbTable::isAutoScale(int row, int col) const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->isAutoScale(row, col);
}

Acad::ErrorStatus PyDbTable::setAutoScale(int row, int col, bool autoFit)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->setAutoScale(row, col, autoFit);
}

PyDbObjectId PyDbTable::blockTableRecordId(int row, int col) const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return PyDbObjectId(imp->blockTableRecordId(row, col));
}

PyDbObjectId PyDbTable::blockTableRecordId2(int row, int col, int nContent) const
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return PyDbObjectId(imp->blockTableRecordId(row, col, nContent));
#endif
}

Acad::ErrorStatus PyDbTable::setBlockTableRecordId(int row, int col, const PyDbObjectId& blkId, bool autoFit)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->setBlockTableRecordId(row, col, blkId.m_id, autoFit);
}

Acad::ErrorStatus PyDbTable::setBlockTableRecordId2(int row, int col, int nContent, const PyDbObjectId& blkId, bool autoFit)
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->setBlockTableRecordId(row, col, nContent, blkId.m_id, autoFit);
#endif
}

double PyDbTable::blockScale(int row, int col) const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->blockScale(row, col);
}

Acad::ErrorStatus PyDbTable::setBlockScale(int row, int col, double scale)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->setBlockScale(row, col, scale);
}

double PyDbTable::blockRotation(int row, int col) const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->blockRotation(row, col);
}

Acad::ErrorStatus PyDbTable::setBlockRotation(int row, int col, double rotAng)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->setBlockRotation(row, col, rotAng);
}

Acad::ErrorStatus PyDbTable::insertColumns(int col, double width, int nCols)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->insertColumns(col, width, nCols);
}

Acad::ErrorStatus PyDbTable::deleteColumns(int col, int nCols)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->deleteColumns(col, nCols);
}

Acad::ErrorStatus PyDbTable::insertRows(int row, double height, int nRows)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->insertRows(row, height, nRows);
}

Acad::ErrorStatus PyDbTable::deleteRows(int row, int nRows)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->deleteRows(row, nRows);
}

Acad::ErrorStatus PyDbTable::mergeCells(int minRow, int maxRow, int minCol, int maxCol)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->mergeCells(minRow, maxRow, minCol, maxCol);
}

Acad::ErrorStatus PyDbTable::unmergeCells(int minRow, int maxRow, int minCol, int maxCol)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->unmergeCells(minRow, maxRow, minCol, maxCol);
}

boost::python::tuple PyDbTable::isMergedCell(int row, int col)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    int minRow = -1;
    int maxRow = -1;
    int minCol = -1;
    int maxCol = -1;
    bool flag = imp->isMergedCell(row, col, &minRow, &maxRow, &minCol, &maxCol);
    return boost::python::make_tuple(flag, minRow, maxRow, minCol, maxCol);
}

Acad::ErrorStatus PyDbTable::generateLayout()
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->generateLayout();
}

Acad::ErrorStatus PyDbTable::recomputeTableBlock(bool forceUpdate)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->recomputeTableBlock(forceUpdate);
}

boost::python::tuple PyDbTable::hitTest(const AcGePoint3d& wpt, const AcGeVector3d& wviewVec, double wxaper, double wyaper)
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    int resultRowIndex = -1;
    int resultColumnIndex = -1;
    int contentIndex = -1;
    AcDb::TableHitItem nItem = AcDb::kTableHitNone;
    bool flag = imp->hitTest(wpt, wviewVec, wxaper, wyaper, resultRowIndex, resultColumnIndex, contentIndex, nItem);
    return boost::python::make_tuple(flag, resultRowIndex, resultColumnIndex, contentIndex, nItem);
#endif
}

AcCellRange PyDbTable::getSubSelection(void) const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->getSubSelection();
}

Acad::ErrorStatus PyDbTable::setSubSelection(const AcCellRange& range)
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->setSubSelection(range);
#endif
}

void PyDbTable::clearSubSelection()
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    imp->clearSubSelection();
}

bool PyDbTable::hasSubSelection() const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->hasSubSelection();
}

Acad::ErrorStatus PyDbTable::setPosition(const AcGePoint3d& newVal)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->setPosition(newVal);
}

Acad::ErrorStatus PyDbTable::setNormal(const AcGeVector3d& newVal)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->setNormal(newVal);
}

void PyDbTable::setRegen()
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    imp->setRegen();
}

void PyDbTable::suppressInvisibleGrid(bool value)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    imp->suppressInvisibleGrid(value);
}

bool PyDbTable::isRegenerateTableSuppressed() const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->isRegenerateTableSuppressed();
}

void PyDbTable::suppressRegenerateTable(bool bSuppress)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    imp->suppressRegenerateTable(bSuppress);
}

void PyDbTable::setRecomputeTableBlock(bool newVal)
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    imp->setRecomputeTableBlock(newVal);
#endif
}

Acad::ErrorStatus PyDbTable::setSize(int nRows, int nCols)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->setSize(nRows, nCols);
}

bool PyDbTable::canInsert(int nIndex, bool bRow) const
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->canInsert(nIndex, bRow);
#endif
}

Acad::ErrorStatus PyDbTable::insertRowsAndInherit(int nIndex, int nInheritFrom, int nNumRows)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->insertRowsAndInherit(nIndex, nInheritFrom, nNumRows);
}

Acad::ErrorStatus PyDbTable::insertColumnsAndInherit(int col, int nInheritFrom, int nNumCols)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->insertRowsAndInherit(col, nInheritFrom, nNumCols);
}

bool PyDbTable::canDelete(int nIndex, int nCount, bool bRow) const
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->canDelete(nIndex, nCount, bRow);
#endif
}

bool PyDbTable::isEmpty(int nRow, int nCol) const
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->isEmpty(nRow, nCol);
#endif
}

AcCellRange PyDbTable::getMergeRange(int nRow, int nCol) const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->getMergeRange(nRow, nCol);
}

bool PyDbTable::isContentEditable(int nRow, int nCol) const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->isContentEditable(nRow, nCol);
}

bool PyDbTable::isFormatEditable(int nRow, int nCol) const
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->isFormatEditable(nRow, nCol);
#endif
}

AcDb::CellState PyDbTable::cellState(int nRow, int nCol) const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->cellState(nRow, nCol);
}

Acad::ErrorStatus PyDbTable::setCellState(int nRow, int nCol, AcDb::CellState nLock)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->setCellState(nRow, nCol, nLock);
}

int PyDbTable::numContents(int nRow, int nCol) const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->numContents(nRow, nCol);
}

int PyDbTable::createContent(int nRow, int nCol, int nIndex)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->createContent(nRow, nCol, nIndex);
}

Acad::ErrorStatus PyDbTable::moveContent(int nRow, int nCol, int nFromIndex, int nToIndex)
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->moveContent(nRow, nCol, nFromIndex, nToIndex);
#endif
}

Acad::ErrorStatus PyDbTable::deleteContent1(int nRow, int nCol)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->deleteContent(nRow, nCol);
}

Acad::ErrorStatus PyDbTable::deleteContent2(int nRow, int nCol, int nIndex)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->deleteContent(nRow, nCol, nIndex);
}

Acad::ErrorStatus PyDbTable::deleteContent3(const AcCellRange& range)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->deleteContent(range);
}

AcDb::CellContentType PyDbTable::contentType1(int nRow, int nCol) const
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->contentType(nRow, nCol);
#endif
}

AcDb::CellContentType PyDbTable::contentType2(int nRow, int nCol, int nIndex) const
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->contentType(nRow, nCol, nIndex);
#endif
}

std::string PyDbTable::dataFormat1(int row, int col) const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return wstr_to_utf8(imp->dataFormat(row, row));
}

std::string PyDbTable::dataFormat2(int row, int col, int nContent) const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return wstr_to_utf8(imp->dataFormat(row, row, nContent));
}

Acad::ErrorStatus PyDbTable::setDataFormat1(int row, int col, const std::string& pszFormat)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->setDataFormat(row, col, utf8_to_wstr(pszFormat).c_str());
}

Acad::ErrorStatus PyDbTable::setDataFormat2(int row, int col, int nContent, const std::string& pszFormat)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->setDataFormat(row, col, nContent, utf8_to_wstr(pszFormat).c_str());
}

bool PyDbTable::hasFormula(int nRow, int nCol, int nContent) const
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->hasFormula(nRow, nCol, nContent);
#endif
}

std::string PyDbTable::getFormula(int nRow, int nCol, int nContent) const
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return wstr_to_utf8(imp->getFormula(nRow, nCol, nContent));
#endif
}

Acad::ErrorStatus PyDbTable::setFormula(int nRow, int nCol, int nContent, const std::string& pszFormula)
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->setFormula(nRow, nCol, nContent, utf8_to_wstr(pszFormula).c_str());
#endif
}

std::string PyDbTable::className()
{
    return "AcDbTable";
}

AcDbTable* PyDbTable::impObj() const
{
    return static_cast<AcDbTable*>(m_pImp.get());
}
