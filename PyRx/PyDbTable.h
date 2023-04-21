#pragma once
#include "PyDbEnts.h"

class PyDbTable : public PyDbBlockReference
{
public:
    PyDbTable();
    PyDbTable(AcDbTable* ptr, bool autoDelete);
    PyDbTable(const PyDbObjectId& id, AcDb::OpenMode mode);

    PyDbObjectId        tableStyle() const;
    Acad::ErrorStatus   setTableStyle(const PyDbObjectId& id);

    AcGeVector3d        direction() const;
    Acad::ErrorStatus   setDirection(const AcGeVector3d& horzVec);

    Adesk::UInt32       numRows() const;
    Adesk::UInt32       numColumns() const;

    double              width() const;
    Acad::ErrorStatus   setWidth(double width);

    double              columnWidth(int col) const;
    Acad::ErrorStatus   setColumnWidth1(int col, double width);
    Acad::ErrorStatus   setColumnWidth2(double width);

    double              height() const;
    Acad::ErrorStatus   setHeight(double height);

    double              rowHeight(int row) const;
    Acad::ErrorStatus   setRowHeight1(int row, double height);
    Acad::ErrorStatus   setRowHeight2(double height);

    double              minimumColumnWidth(int col) const;
    double              minimumRowHeight(int row) const;
    double              minimumTableWidth() const;
    double              minimumTableHeight() const;

    double              horzCellMargin() const;
    Acad::ErrorStatus   setHorzCellMargin(double gap);

    virtual double      vertCellMargin() const;
    virtual Acad::ErrorStatus setVertCellMargin(double gap);

    AcDb::FlowDirection flowDirection() const;
    Acad::ErrorStatus   setFlowDirection(AcDb::FlowDirection flow);

    bool                isTitleSuppressed() const;
    Acad::ErrorStatus   suppressTitleRow(bool value);

    bool                isHeaderSuppressed() const;
    Acad::ErrorStatus   suppressHeaderRow(bool value);

    AcDb::CellAlignment alignment(AcDb::RowType type) const;
    Acad::ErrorStatus   setAlignment(AcDb::CellAlignment align, AcDb::RowType rowTypes);

    bool                isBackgroundColorNone(AcDb::RowType type) const;
    Acad::ErrorStatus   setBackgroundColorNone(bool value, AcDb::RowType type);

    AcCmColor           backgroundColor(AcDb::RowType type) const;
    Acad::ErrorStatus   setBackgroundColor(const AcCmColor& color, AcDb::RowType type);

    AcCmColor           contentColor(AcDb::RowType type) const;
    Acad::ErrorStatus   setContentColor(const AcCmColor& color, AcDb::RowType type);

    boost::python::tuple getDataType(AcDb::RowType type) const;
    Acad::ErrorStatus   setDataType1(AcValue::DataType nDataType, AcValue::UnitType nUnitType);
    Acad::ErrorStatus   setDataType2(AcValue::DataType nDataType, AcValue::UnitType nUnitType, AcDb::RowType type);

    PyDbObjectId        textStyle(AcDb::RowType type) const;
    Acad::ErrorStatus   setTextStyle(const PyDbObjectId& id, AcDb::RowType rowTypes);

    double              textHeight(AcDb::RowType type) const;
    Acad::ErrorStatus   setTextHeight(double height, AcDb::RowType rowTypes);

    AcDb::LineWeight    gridLineWeight(AcDb::GridLineType gridlineType, AcDb::RowType type) const;
    Acad::ErrorStatus   setGridLineWeight(AcDb::LineWeight lwt, int nBorders, int nRows);

    AcCmColor           gridColor(AcDb::GridLineType gridlineType, AcDb::RowType type) const;
    Acad::ErrorStatus   setGridColor(const AcCmColor& color, int nBorders, int nRows);

    AcDb::Visibility    gridVisibility(AcDb::GridLineType gridlineType, AcDb::RowType type) const;
    Acad::ErrorStatus   setGridVisibility(AcDb::Visibility visible, int nBorders, int nRows);

    boost::python::list tableStyleOverrides() const;
    void                clearTableStyleOverrides();

    AcDb::CellType      cellType(int row, int col) const;
    Acad::ErrorStatus   setCellType(int row, int col, AcDb::CellType type);

    boost::python::list getCellExtents(int row, int col, bool isOuterCell) const;

    AcGePoint3d         attachmentPoint(int row, int col) const;

    AcDb::CellAlignment alignment2(int row, int col) const;
    Acad::ErrorStatus   setAlignment2(int row, int col, AcDb::CellAlignment align);

    bool                isBackgroundColorNone2(int row, int col) const;
    Acad::ErrorStatus   setBackgroundColorNone2(int row, int col, bool value);

    AcCmColor           contentColor2(int row, int col) const;
    Acad::ErrorStatus   setContentColor2(int row, int col, const AcCmColor& color);

    boost::python::list cellStyleOverrides(int row, int col) const;
    void                clearCellOverrides(int row, int column);

    Acad::ErrorStatus   deleteCellContent(int row, int col);
    AcDb::RowType       rowType(int row) const;

    boost::python::tuple getDataType2(int row, int col) const;
    Acad::ErrorStatus    setDataType3(int row, int col, AcValue::DataType nDataType, AcValue::UnitType nUnitType);

    Acad::ErrorStatus    setFormat(int row, int col, const std::string& pszFormat);

    std::string          textString(int row, int col) const;
    std::string          textString3(int row, int col, AcValue::FormatOption nOption) const;

    Acad::ErrorStatus    setTextString(int row, int col, const std::string& text);

    PyDbObjectId         fieldId(int row, int col) const;
    Acad::ErrorStatus    setFieldId(int row, int col, const PyDbObjectId& fieldId);

    PyDbObjectId         textStyle2(int row, int col) const;
    Acad::ErrorStatus    setTextStyle2(int row, int col, const PyDbObjectId& id);

    double               textHeight2(int row, int col) const;
    Acad::ErrorStatus    setTextHeight2(int row, int col, double height);

    AcDb::RotationAngle textRotation(int row, int col) const;
    Acad::ErrorStatus   setTextRotation(int row, int col, AcDb::RotationAngle rot);

    bool                isAutoScale(int row, int col) const;
    Acad::ErrorStatus   setAutoScale(int row, int col, bool autoFit);

    PyDbObjectId        blockTableRecordId(int row, int col) const;
    Acad::ErrorStatus   setBlockTableRecordId(int row, int col, const PyDbObjectId& blkId, bool autoFit);

    double              blockScale(int row, int col) const;
    Acad::ErrorStatus   setBlockScale(int row, int col, double scale);

    double              blockRotation(int row, int col) const;
    Acad::ErrorStatus   setBlockRotation(int row, int col, double rotAng);

    AcCmColor           gridColor2(int row, int col, AcDb::CellEdgeMask iEdge) const;
    Acad::ErrorStatus   setGridColor2(int row, int col, AcDb::CellEdgeMask nEdges, const AcCmColor& color);

    AcDb::Visibility    gridVisibility2(int row, int col, AcDb::CellEdgeMask iEdge) const;
    Acad::ErrorStatus   setGridVisibility2(int row, int col, AcDb::CellEdgeMask iEdge, AcDb::Visibility value);

    AcDb::LineWeight    gridLineWeight2(int row, int col, AcDb::CellEdgeMask iEdge) const;
    Acad::ErrorStatus   setGridLineWeight2(int row, int col, AcDb::CellEdgeMask nEdges, AcDb::LineWeight value);

    Acad::ErrorStatus   insertColumns(int col, double width, int nCols);
    Acad::ErrorStatus   deleteColumns(int col, int nCols);

    Acad::ErrorStatus   insertRows(int row, double height, int nRows);
    Acad::ErrorStatus   deleteRows(int row, int nRows);

    Acad::ErrorStatus   mergeCells(int minRow, int maxRow, int minCol, int maxCol);
    Acad::ErrorStatus   unmergeCells(int minRow, int maxRow, int minCol, int maxCol);
    boost::python::tuple  isMergedCell(int row, int col);

    Acad::ErrorStatus   generateLayout();
    Acad::ErrorStatus   recomputeTableBlock(bool forceUpdate);

    boost::python::tuple  hitTest(const AcGePoint3d& wpt, const AcGeVector3d& wviewVec, double wxaper, double wyaper);

    AcCellRange         getSubSelection(void) const;
    Acad::ErrorStatus   setSubSelection(const AcCellRange& range);

    void                clearSubSelection();
    bool                hasSubSelection() const;

    Acad::ErrorStatus   setPosition(const AcGePoint3d& newVal);
    Acad::ErrorStatus   setNormal(const AcGeVector3d& newVal);

    void              setRegen();
    void              suppressInvisibleGrid(bool value);

    bool            isRegenerateTableSuppressed() const;
    void            suppressRegenerateTable(bool bSuppress);
    void            setRecomputeTableBlock(bool newVal);

    Acad::ErrorStatus setSize(int nRows, int nCols);
    bool              canInsert(int nIndex, bool bRow) const;

    Acad::ErrorStatus insertRowsAndInherit(int nIndex, int nInheritFrom, int nNumRows);
    Acad::ErrorStatus insertColumnsAndInherit(int col, int nInheritFrom, int nNumCols);
    bool              canDelete(int nIndex, int nCount, bool bRow) const;

    bool                isEmpty(int nRow, int nCol) const;
    AcCellRange         getMergeRange(int nRow, int nCol) const;

    //TODO; just return a list of AcCell?
    //AcDbTableIterator* getIterator(void) const;
    //AcDbTableIterator* getIterator(const AcCellRange* pRange, AcDb::TableIteratorOption nOption) const;

    bool            isContentEditable(int nRow, int nCol) const;
    bool            isFormatEditable(int nRow, int nCol) const;

    AcDb::CellState     cellState(int nRow, int nCol) const;
    Acad::ErrorStatus   setCellState(int nRow, int nCol, AcDb::CellState nLock);

    int               numContents(int nRow, int nCol) const;
    int               createContent(int nRow, int nCol, int nIndex);
    Acad::ErrorStatus moveContent(int nRow,int nCol,int nFromIndex,int nToIndex);

    Acad::ErrorStatus deleteContent1(int nRow, int nCol);
    Acad::ErrorStatus deleteContent2(int nRow,int nCol, int nIndex);
    Acad::ErrorStatus deleteContent3(const AcCellRange& range);

    AcDb::CellContentType contentType1(int nRow, int nCol) const;
    AcDb::CellContentType contentType2(int nRow, int nCol,int nIndex) const;

    //AcValue value(int row,int col,int nContent) const;
    //AcValue value(int row, int col, int nContent,AcValue::FormatOption nOption) const;
    //Acad::ErrorStatus setValue(int row,int col,int nContent, const AcValue& val);
    //Acad::ErrorStatus setValue(int row,int col,int nContent,const AcValue& val,AcValue::ParseOption nOption);
    //Acad::ErrorStatus setValue(int row,int col,int nContent,const wchar_t* pszText, AcValue::ParseOption nOption);

   std::string        dataFormat1(int row,int col) const;
   std::string        dataFormat2(int row,int col,int nContent) const;

   Acad::ErrorStatus setDataFormat1(int row, int col, const std::string& pszFormat);
   Acad::ErrorStatus setDataFormat2(int row, int col,int nContent, const std::string& pszFormat);

   std::string        textString2(int row,int col, int nContent) const;
   std::string        textString4(int row,int col,int nContent,AcValue::FormatOption nOption) const;

   Acad::ErrorStatus  setTextString2(int row,int col,int nContent, const  std::string& text);

   bool               hasFormula(int nRow,int nCol, int nContent) const;
   std::string        getFormula(int nRow,int nCol,int nContent) const;

   Acad::ErrorStatus  setFormula(int nRow,int nCol,int nContent,const  std::string& pszFormula);

   PyDbObjectId         fieldId2(int row,int col, int nContent) const;
   Acad::ErrorStatus    setFieldId2(int row,int col,int nContent, const PyDbObjectId& fieldId, AcDb::CellOption nFlag);

   PyDbObjectId         blockTableRecordId2(int row,int col, int nContent) const;
   Acad::ErrorStatus    setBlockTableRecordId2(int row,int col, int nContent, const PyDbObjectId& blkId, bool autoFit);




    static std::string className();
public:
    AcDbTable* impObj() const;
};

