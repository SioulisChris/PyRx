#pragma once
#include "PyRxObject.h"

class PyDbObjectId;

void makeAcDbDatabaseWrapper();

class PyDbDatabase : public PyRxObject
{
public:
    PyDbDatabase();
    PyDbDatabase(AcDbDatabase* pDb);
    PyDbDatabase(AcDbDatabase* pDb, bool autoDelete);
    ~PyDbDatabase();
    double angbase() const;
    bool angdir() const;
    bool annoAllVisible() const;
    bool annotativeDwg() const;
    int approxNumObjects() const;
    Adesk::Int16 attmode() const;
    Adesk::Int16 aunits() const;
    Adesk::Int16 auprec() const;
    bool blipmode() const;
    PyDbObjectId byBlockLinetype() const;
    PyDbObjectId byBlockMaterial() const;
    PyDbObjectId byLayerLinetype() const;
    PyDbObjectId byLayerMaterial() const;
    bool cameraDisplay() const;
    double cameraHeight() const;
    Adesk::Int16 cDynDisplayMode() const;
    double celtscale() const;
    PyDbObjectId celtype() const;
    AcDb::LineWeight celweight() const; //TODO:: add  AcDb::LineWeight enum
    double chamfera() const;
    double chamferb() const;
    double chamferc() const;
    double chamferd() const;
    std::string classDxfName(const PyRxClass& pClass);
    PyDbObjectId clayer() const;
    Acad::ErrorStatus closeInput(bool bCloseFile);
    PyDbObjectId cmaterial() const;
    Adesk::Int16 cmljust() const;
    double cmlscale() const;
    PyDbObjectId cmlstyleID() const;
    PyDbObjectId colorDictionaryId() const;
    PyDbObjectId continuousLinetype() const;
    Adesk::Int16 coords() const;
    Adesk::UInt32 countEmptyObjects(const Adesk::UInt32 flags);
    PyDbObjectId detailViewStyle() const;
    PyDbObjectId detailViewStyleDictionaryId() const;
    bool dimaso() const;
    Adesk::UInt8 dimAssoc() const;
    int dimfit() const;
    bool dimsho() const;
    PyDbObjectId dimstyle() const;
    PyDbObjectId dimStyleTableId() const;
    int dimunit() const;
    void disablePartialOpen();
    void disableUndoRecording(bool disable);
    bool dispSilh() const;
    Adesk::Int16 dragmode() const;
    PyDbObjectId dragVisStyle() const;
    Adesk::UInt8 drawOrderCtl() const;
    Adesk::UInt8 dwfframe() const;
    bool dwgFileWasSavedByAutodeskSoftware() const;
    Acad::ErrorStatus dxfIn(const std::string& dxfFilename);
    Acad::ErrorStatus dxfOut(const std::string& dxfFilename);
    double elevation() const;
    Adesk::UInt32 eraseEmptyObjects(const Adesk::UInt32 flags);
    AcGePoint3d extmax() const;
    AcGePoint3d extmin() const;
    double facetres() const;
    double filletrad() const;
    bool fillmode() const;
    void forceWblockDatabaseCopy();
    std::string geoCoordinateSystemId() const;
    bool geoMarkerVisibility() const;
    double get3dDwfPrec() const;

    //TODO: Acad::ErrorStatus getAcDbObjectId
    AcDb::PlotStyleNameType getCePlotStyleNameId(PyDbObjectId& id) const;
    bool isAppRegistered(const std::string& pszAppName) const;
    std::string dimapost() const;
    PyDbObjectId dimblk() const;
    PyDbObjectId dimblk1() const;
    PyDbObjectId dimblk2() const;
    std::string  dimpost() const;

    PyDbObjectId getDimstyleParentId(PyDbObjectId& childStyle) const;
    PyDbObjectId groupDictionaryId() const;

    Acad::ErrorStatus insert(PyDbObjectId& blockId, const std::string& pBlockName, PyDbDatabase& db, bool preserveSourceDatabase = true);
    Acad::ErrorStatus insert(PyDbObjectId& blockId, const std::string& pSourceBlockName, const std::string& pDestinationBlockName, PyDbDatabase& db, bool preserveSourceDatabase = true);
    Acad::ErrorStatus insert(const AcGeMatrix3d& xform, PyDbDatabase& db, bool preserveSourceDatabase = true);

    //TODO: enum
    AcDb::UnitsValue insunits() const;
    bool isBeingDestroyed() const;
    PyDbObjectId layerTableId() const;
    PyDbObjectId layerZero() const;
    PyDbObjectId layoutDictionaryId()const;
    double lensLength() const;
    PyDbObjectId linetypeTableId() const;
    Acad::ErrorStatus registerApp(const std::string& pszAppName);
    PyDbObjectId materialDictionaryId() const;

    //TODO: enum
    AcDb::MeasurementValue measurement() const;
    bool mirrtext() const;
    double mleaderscale() const;
    PyDbObjectId mleaderstyle() const;
    PyDbObjectId mleaderStyleDictionaryId() const;
    PyDbObjectId mLStyleDictionaryId() const;
    bool msltscale() const;
    PyDbObjectId namedObjectsDictionaryId() const;
    bool needsRecovery() const;
    double northDirection() const;
    Adesk::Int32 numberOfSaves() const;
    bool orthomode() const;
    PyDbObjectId paperSpaceVportId() const;
    PyDbObjectId plotSettingsDictionaryId() const;
    bool plotStyleMode() const;
    PyDbObjectId plotStyleNameDictionaryId() const;
    PyDbObjectId regAppTableId() const;
    Acad::ErrorStatus restoreOriginalXrefSymbols();

    //TODO: enum
    Acad::ErrorStatus saveAs(const std::string& fileName);
    void setFullSaveRequired();

    Acad::ErrorStatus readDwgFile(const char* fileName);
    std::string getFilename();

    PyDbObjectId currentSpaceId() const;
    PyDbObjectId blockTableId() const;
    PyDbObjectId modelspaceId() const;





    double textsize() const;

    PyDbObjectId textstyle() const;
    PyDbObjectId textStyleTableId() const;
    double thickness() const;

    //TODO:
    //void* thumbnailBitmap() const maybe 
    //Acad::ErrorStatus thumbnailImage(Atil::Image*& pPreviewImage) const; probably never
    bool tilemode() const;
    Adesk::UInt8 tileModeLightSynch() const;
    //TODO: enum
    AcDb::TimeZone timeZone() const;
    double tracewid() const;

    //TODO:
    //AcDbTransactionManager* transactionManager() const;
    Adesk::Int16 treedepth() const;
    int tstackalign() const;
    int tstacksize() const;

    PyDbObjectId ucsBase() const;
    PyDbObjectId ucsname() const;
    AcGePoint3d ucsorg() const;
    PyDbObjectId UCSTableId() const;
    AcGeVector3d ucsxdir() const;
    AcGeVector3d ucsydir() const;
    bool undoRecording() const;
    Adesk::Int16 unitmode() const;

    Acad::ErrorStatus updateDataLink(AcDb::UpdateDirection nDir,AcDb::UpdateOption nOption);
    Acad::ErrorStatus updateExt(bool doBestFit);
    Adesk::UInt8 updateThumbnail() const;

    Adesk::Int16 useri1() const;
    Adesk::Int16 useri2() const;
    Adesk::Int16 useri3() const;
    Adesk::Int16 useri4() const;
    Adesk::Int16 useri5() const;

    double userr1() const;
    double userr2() const;
    double userr3() const;
    double userr4() const;
    double userr5() const;

    bool usrtimer() const;
    double viewportScaleDefault() const;
    PyDbObjectId viewportTableId() const;
    PyDbObjectId viewTableId() const;
    bool visretain() const;
    PyDbObjectId visualStyleDictionaryId() const;

    Acad::ErrorStatus wblock(PyDbDatabase& pOutputDb, const boost::python::list& outObjIds, const AcGePoint3d& basePoint, AcDb::DuplicateRecordCloning drc);
    Acad::ErrorStatus wblock(PyDbDatabase& pOutputDb, const boost::python::list& outObjIds,const AcGePoint3d& basePoint);
    Acad::ErrorStatus wblock(PyDbDatabase& pOutputDb,const PyDbObjectId& blockId);
    Acad::ErrorStatus wblock(PyDbDatabase& pOutputDb);

    //TODO: AcDbIdMapping
    //Acad::ErrorStatus wblockCloneObjects(const boost::python::list& objectIds, const AcDbObjectId& owner, AcDbIdMapping& idMap, AcDb::DuplicateRecordCloning drc, bool deferXlation = false);
    AcGePoint3d worldPucsBaseOrigin(AcDb::OrthographicView orthoView) const;
    AcGePoint3d worldUcsBaseOrigin(AcDb::OrthographicView orthoView) const;
    bool worldview() const;
    Adesk::UInt8 xclipFrame() const;
    PyDbObjectId xrefBlockId() const;
    bool xrefEditEnabled() const;
    //
    static std::string className();
private:
    AcDbDatabase* impObj() const;
};


