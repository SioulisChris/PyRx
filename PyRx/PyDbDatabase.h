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
    PyDbDatabase(bool buildDefaultDrawing, bool noDocument);
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


    static AcDb::LineWeight getNearestLineWeight(int weight);

    boost::python::list getViewportArray() const;
    boost::python::list getVisualStyleList(); //TODO test

    PyDbObjectId globalMaterial() const;
    PyDbObjectId groupDictionaryId() const;

    Acad::ErrorStatus insert(PyDbObjectId& blockId, const std::string& pBlockName, PyDbDatabase& db, bool preserveSourceDatabase = true);
    Acad::ErrorStatus insert(PyDbObjectId& blockId, const std::string& pSourceBlockName, const std::string& pDestinationBlockName, PyDbDatabase& db, bool preserveSourceDatabase = true);
    Acad::ErrorStatus insert(const AcGeMatrix3d& xform, PyDbDatabase& db, bool preserveSourceDatabase = true);



    Adesk::UInt8 haloGap() const;
    //AcDbHandle handseed() const; TODO:
    bool hasClass(const PyRxClass& pClass) const;
    Adesk::UInt8 hideText() const;
    bool hpInherit() const;
    AcGePoint2d hpOrigin() const;
    Adesk::UInt8 indexctl() const;
    AcDb::UnitsValue insunits() const;

    PyDbObjectId interfereVpVisStyle() const;
    Adesk::UInt16 intersectColor() const;
    Adesk::UInt8 intersectDisplay() const;
    bool isBeingDestroyed() const;


    bool isEMR() const;
    static bool isObjectNonPersistent(const PyDbObjectId& id);

    Adesk::Int16 isolines() const;
    bool isPartiallyOpened() const;
    bool isPucsOrthographic(AcDb::OrthographicView& orthoView) const;
    bool isUcsOrthographic(AcDb::OrthographicView& orthoView) const;
    static bool isValidLineWeight(int weight);


    AcDb::JoinStyle joinStyle() const;
    AcDb::MaintenanceReleaseVersion lastSavedAsMaintenanceVersion() const;
    AcDb::AcDbDwgVersion lastSavedAsVersion() const;//TODO enum
    double latitude() const;
    Adesk::UInt8 layerEval() const;
    Adesk::Int16 layerNotify() const;
    PyDbObjectId layerTableId() const;
    PyDbObjectId layerZero() const;
    PyDbObjectId layoutDictionaryId()const;
    double lensLength() const;

    Adesk::UInt8 lightGlyphDisplay() const;
    Adesk::UInt8 lightingUnits() const;
    bool lightsInBlocks() const;
    bool limcheck() const;
    AcGePoint2d limmax() const;
    AcGePoint2d limmin() const;

    PyDbObjectId linetypeTableId() const;

    bool lineWeightDisplay() const;
    Acad::ErrorStatus loadLineTypeFile(const std::string& ltn, const std::string& filename);

    double loftAng1() const;
    double loftAng2() const;
    double loftMag1() const;
    double loftMag2() const;
    Adesk::UInt8 loftNormals() const;
    Adesk::UInt16 loftParam() const;
    double longitude() const;
    double ltscale() const;
    Adesk::Int16 lunits() const;
    Adesk::Int16 luprec() const;
    AcDb::MaintenanceReleaseVersion maintenanceReleaseVersion() const;

    static Acad::ErrorStatus markObjectNonPersistent(const PyDbObjectId &id,bool value);

    PyDbObjectId materialDictionaryId() const;
    Adesk::Int16 maxactvp() const;
    AcDb::MeasurementValue measurement() const;
    bool mirrtext() const;

    double mleaderscale() const;
    PyDbObjectId mleaderstyle() const;
    PyDbObjectId mleaderStyleDictionaryId() const;
    PyDbObjectId mLStyleDictionaryId() const;

    bool msltscale() const;
    double msOleScale() const;

    PyDbObjectId namedObjectsDictionaryId() const;
    bool needsRecovery() const;
    double northDirection() const;
    Adesk::Int32 numberOfSaves() const;

    //AcDbObjectContextManager* objectContextManager() const; TODO
    Adesk::UInt16 obscuredColor() const;
    Adesk::UInt8 obscuredLineType() const;
    bool oleStartUp() const;
    AcDb::MaintenanceReleaseVersion originalFileMaintenanceVersion() const;
    std::string originalFileName() const;
    AcDb::MaintenanceReleaseVersion originalFileSavedByMaintenanceVersion() const;//TODO: enum
    AcDb::AcDbDwgVersion originalFileSavedByVersion() const;
    AcDb::AcDbDwgVersion originalFileVersion() const;//TODO: enum
    bool orthomode() const;

    //AcDwgFileHandle* outputFiler() const; TODO:

    PyDbObjectId paperSpaceVportId() const;

    Adesk::Int8 pdfframe() const;
    Adesk::Int16 pdmode() const;
    double pdsize() const;
    double pelevation() const;
    AcGePoint3d pextmax() const;
    AcGePoint3d pextmin() const;
    Adesk::Int16 pickstyle() const;
    AcGePoint3d pinsbase() const;
    bool plimcheck() const;
    AcGePoint2d plimmax() const;
    AcGePoint2d plimmin() const;
    bool plineEllipse() const;
    bool plinegen() const;
    double plinewid() const;

    PyDbObjectId plotSettingsDictionaryId() const;
    bool plotStyleMode() const;
    PyDbObjectId plotStyleNameDictionaryId() const;


    Adesk::Int16 previewType() const;
    bool psltscale() const;
    double psolHeight() const;
    double psolWidth() const;

    PyDbObjectId pucsBase() const;
    PyDbObjectId pucsname() const;
    AcGePoint3d pucsorg() const;
    AcGeVector3d pucsxdir() const;
    AcGeVector3d pucsydir() const;

    //Acad::ErrorStatus purge(AcDbObjectIdArray& ids);TODO:
    bool qtextmode() const;

    Acad::ErrorStatus reclaimMemoryFromErasedObjects(const boost::python::list& erasedObjects);
    PyDbObjectId regAppTableId() const;
    bool regenmode() const;

    //Acad::ErrorStatus removeReactor(AcDbDatabaseReactor* pReactor) const; TODO:
    Acad::ErrorStatus registerApp(const std::string& pszAppName);
    Acad::ErrorStatus resetTimes();
    Acad::ErrorStatus restoreForwardingXrefSymbols();
    Acad::ErrorStatus restoreOriginalXrefSymbols();

    bool retainOriginalThumbnailBitmap() const;
    Adesk::Int16 saveproxygraphics() const;

    PyDbObjectId scaleListDictionaryId() const;
    PyDbObjectId sectionViewStyle() const;
    PyDbObjectId sectionViewStyleDictionaryId() const;

    Acad::ErrorStatus set3dDwfPrec(double DwfPrec);
    Acad::ErrorStatus setAngbase(double angle);
    Acad::ErrorStatus setAngdir(bool dir);
    Acad::ErrorStatus setAnnoAllVisible(bool allvis);
    Acad::ErrorStatus setAttdia(bool dia);
    Acad::ErrorStatus setAttmode(Adesk::Int16 mode);
    Acad::ErrorStatus setAttreq(bool req);
    Acad::ErrorStatus setAunits(Adesk::Int16 aunits);
    Acad::ErrorStatus setAuprec(Adesk::Int16 auprec);
    Acad::ErrorStatus setBlipmode(bool mode);
    Acad::ErrorStatus setCameraDisplay(bool cameraDisplay);
    Acad::ErrorStatus setCameraHeight(double cameraHeight);

    //Acad::ErrorStatus setCannoscale(AcDbAnnotationScale*); TODO:

    Acad::ErrorStatus setCDynDisplayMode(Adesk::Int16 val);

    //Acad::ErrorStatus setCecolor(const AcCmColor& color); TODO:
    Acad::ErrorStatus setCeltscale(double scale);
    Acad::ErrorStatus setCeltype(const PyDbObjectId& id);
    Acad::ErrorStatus setCelweight(AcDb::LineWeight weight);
    Acad::ErrorStatus setCePlotStyleName(AcDb::PlotStyleNameType, const PyDbObjectId& id);

    //Acad::ErrorStatus setCetransparency(const AcCmTransparency& transparency); TODO:

    Acad::ErrorStatus setChamfera(double val);
    Acad::ErrorStatus setChamferb(double val);
    Acad::ErrorStatus setChamferc(double val);
    Acad::ErrorStatus setChamferd(double val);
    Acad::ErrorStatus setClayer(const PyDbObjectId& id);
    Acad::ErrorStatus setCmaterial(const PyDbObjectId& id);
    Acad::ErrorStatus setCmljust(Adesk::Int16 just);
    Acad::ErrorStatus setCmlscale(double scale);
    Acad::ErrorStatus setCmlstyleID(const PyDbObjectId& id);
    Acad::ErrorStatus setCoords(Adesk::Int16 coords);
    Acad::ErrorStatus setCshadow(Adesk::UInt8 val);
    Acad::ErrorStatus setDelUsedObj(Adesk::Int16 deleteObj);
    Acad::ErrorStatus setDgnframe(Adesk::UInt8 val);
    Acad::ErrorStatus setDimaso(bool aso);
    Acad::ErrorStatus setDimAssoc(Adesk::UInt8 val);
    Acad::ErrorStatus setDimfit(int fit);
    Acad::ErrorStatus setDimsho(bool sho);
    Acad::ErrorStatus setDimstyle(const PyDbObjectId& id);

    //Acad::ErrorStatus setDimstyleData(AcDbDimStyleTableRecord* pRec);//TODO:

    Acad::ErrorStatus setDimstyleData(const PyDbObjectId& id);
    Acad::ErrorStatus setDimunit(int unit);
    Acad::ErrorStatus setDispSilh(bool silh);
    Acad::ErrorStatus setDragmode(Adesk::Int16 mode);
    Acad::ErrorStatus setDragVisStyle(const PyDbObjectId& id);
    Acad::ErrorStatus setDrawOrderCtl(Adesk::UInt8 val);
    Acad::ErrorStatus setDwfframe(Adesk::UInt8);
    Acad::ErrorStatus setElevation(double elev);
    Acad::ErrorStatus setEndCaps(AcDb::EndCaps type);
    Acad::ErrorStatus setExtmax(const AcGePoint3d& max);
    Acad::ErrorStatus setExtmin(const AcGePoint3d& min);
    Acad::ErrorStatus setFacetres(double _facetres);
    Acad::ErrorStatus setFilletrad(double radius);
    Acad::ErrorStatus setFillmode(bool mode);

    Acad::ErrorStatus saveAs(const std::string& fileName);  //TODO: enum

    Acad::ErrorStatus setFingerprintGuid(const std::string& newGuid);
    void setFullSaveRequired();

    Acad::ErrorStatus readDwgFile(const char* fileName);
    std::string getFilename();

    PyDbObjectId currentSpaceId() const;
    PyDbObjectId blockTableId() const;
    PyDbObjectId modelspaceId() const;


    Acad::ErrorStatus setGeoMarkerVisibility(bool value);
    Acad::ErrorStatus setHaloGap(Adesk::UInt8 val);

    //Acad::ErrorStatus setHandseed(const AcDbHandle& handle); TODO: AcDbHandle

    Acad::ErrorStatus setHideText(Adesk::UInt8 val);
    Acad::ErrorStatus setHpInherit(const bool inherit);
    Acad::ErrorStatus setHpOrigin(const AcGePoint2d& origin);
    Acad::ErrorStatus setHyperlinkBase(const std::string& val);
    Acad::ErrorStatus setIndexctl(Adesk::UInt8 val);
    Acad::ErrorStatus setInsbase(const AcGePoint3d& base);
    Acad::ErrorStatus setInsunits(const AcDb::UnitsValue units);

    //Acad::ErrorStatus setInterfereColor(const AcCmColor& color);//TODO: AcCmColor

    Acad::ErrorStatus setInterfereObjVisStyle(const PyDbObjectId& id);
    Acad::ErrorStatus setInterfereVpVisStyle(const PyDbObjectId& id);
    Acad::ErrorStatus setIntersectColor(Adesk::UInt16 val);
    Acad::ErrorStatus setIntersectDisplay(Adesk::UInt8 val);
    Acad::ErrorStatus setIsolines(Adesk::Int16 isolines);
    Acad::ErrorStatus setJoinStyle(AcDb::JoinStyle style);
    Acad::ErrorStatus setLatitude(double lat);
    Acad::ErrorStatus setLayerEval(Adesk::UInt8 val);
    Acad::ErrorStatus setLayerNotify(Adesk::Int16 val);
    Acad::ErrorStatus setLensLength(const double _lensLength);
    Acad::ErrorStatus setLightGlyphDisplay(Adesk::UInt8 val);
    Acad::ErrorStatus setLightingUnits(Adesk::UInt8 val);
    Acad::ErrorStatus setLightsInBlocks(bool val);
    Acad::ErrorStatus setLimcheck(bool check);
    Acad::ErrorStatus setLimmax(const AcGePoint2d& max);
    Acad::ErrorStatus setLimmin(const AcGePoint2d& min);
    Acad::ErrorStatus setLineWeightDisplay(bool display);
    Acad::ErrorStatus setLoftAng1(double ang1);
    Acad::ErrorStatus setLoftAng2(double ang2);
    Acad::ErrorStatus setLoftMag1(double mag1);
    Acad::ErrorStatus setLoftMag2(double mag2);
    Acad::ErrorStatus setLoftNormals(Adesk::UInt8 value);
    Acad::ErrorStatus setLoftParam(Adesk::UInt16 flags);
    Acad::ErrorStatus setLongitude(double lng);
    Acad::ErrorStatus setLtscale(double scale);
    Acad::ErrorStatus setLunits(Adesk::Int16 lunits);
    Acad::ErrorStatus setLuprec(Adesk::Int16 prec);
    Acad::ErrorStatus setMaxactvp(Adesk::Int16 max);
    Acad::ErrorStatus setMeasurement(AcDb::MeasurementValue type);
    Acad::ErrorStatus setMirrtext(bool mirror);
    Acad::ErrorStatus setMLeaderscale(double scale);
    Acad::ErrorStatus setMLeaderstyle(const PyDbObjectId& objId);
    Acad::ErrorStatus setMsltscale(bool val);
    Acad::ErrorStatus setMsOleScale(double val);
    Acad::ErrorStatus setNorthDirection(double northdir);
    Acad::ErrorStatus setObscuredColor(Adesk::UInt16 val);
    Acad::ErrorStatus setObscuredLineType(Adesk::UInt8 val);
    Acad::ErrorStatus setOleStartUp(bool val);
    Acad::ErrorStatus setOrthomode(bool mode);
    Acad::ErrorStatus setPdfframe(Adesk::Int8 val);
    Acad::ErrorStatus setPdmode(Adesk::Int16 mode);
    Acad::ErrorStatus setPdsize(double size);
    Acad::ErrorStatus setPelevation(double elev);
    Acad::ErrorStatus setPextmax(const AcGePoint3d& max);
    Acad::ErrorStatus setPextmin(const AcGePoint3d& min);
    Acad::ErrorStatus setPickstyle(Adesk::Int16 style);
    Acad::ErrorStatus setPinsbase(const AcGePoint3d& base);
    Acad::ErrorStatus setPlimcheck(bool check);
    Acad::ErrorStatus setPlimmax(const AcGePoint2d& max);
    Acad::ErrorStatus setPlimmin(const AcGePoint2d& min);
    Acad::ErrorStatus setPlineEllipse(bool pline);
    Acad::ErrorStatus setPlinegen(bool gen);
    Acad::ErrorStatus setPlinewid(double width);
    Acad::ErrorStatus setPreviewType(Adesk::Int16 val);
    Acad::ErrorStatus setProjectName(const std::string& val);
    Acad::ErrorStatus setPsltscale(bool scale);
    Acad::ErrorStatus setPsolHeight(double height);
    Acad::ErrorStatus setPsolWidth(double width);
    Acad::ErrorStatus setPucs(const AcGePoint3d& ucsOrigin,const AcGeVector3d& ucsXDir, const AcGeVector3d& ucsYDir);
    Acad::ErrorStatus setPucsBase(const PyDbObjectId& ucsid);
    Acad::ErrorStatus setPucsname(const PyDbObjectId& ucsRecId);
    Acad::ErrorStatus setQtextmode(bool mode);
    Acad::ErrorStatus setRealWorldScale(const bool realWorldScale);
    Acad::ErrorStatus setRegenmode(bool mode);
    void setRetainOriginalThumbnailBitmap(bool retain);
    Acad::ErrorStatus setSaveproxygraphics(Adesk::Int16 saveimg);
    Acad::ErrorStatus setSectionViewStyle(const PyDbObjectId& objId);
    //bool setSecurityParams(const SecurityParams* pSecParams,bool bSetDbMod = true);//TODO:

    Acad::ErrorStatus setShadedge(Adesk::Int16 mode);
    Acad::ErrorStatus setShadedif(Adesk::Int16 dif);
    Acad::ErrorStatus setShadowPlaneLocation(double val);
    Acad::ErrorStatus setShowHist(Adesk::UInt8 val);
    Acad::ErrorStatus setSketchinc(double inc);
    Acad::ErrorStatus setSkpoly(bool asPoly);
    Acad::ErrorStatus setSolidHist(Adesk::UInt8 val);
    Acad::ErrorStatus setSortEnts(Adesk::UInt8 sortEnts);
    Acad::ErrorStatus setSplframe(bool disp);
    Acad::ErrorStatus setSplinesegs(Adesk::Int16 segs);
    Acad::ErrorStatus setSplinetype(Adesk::Int16 type);
    Acad::ErrorStatus setStepSize(double stepSize);
    Acad::ErrorStatus setStepsPerSec(double stepsPerSec);
    Acad::ErrorStatus setStyleSheet(const std::string& val);
    Acad::ErrorStatus setSurftab1(Adesk::Int16 tab1);
    Acad::ErrorStatus setSurftab2(Adesk::Int16 tab2);
    Acad::ErrorStatus setSurftype(Adesk::Int16 type);
    Acad::ErrorStatus setSurfu(Adesk::Int16 v);
    Acad::ErrorStatus setSurfv(Adesk::Int16 v);
    Acad::ErrorStatus setTablestyle(const PyDbObjectId& objId);
    Acad::ErrorStatus setTextsize(double size);
    Acad::ErrorStatus setTextstyle(const PyDbObjectId& objId);
    Acad::ErrorStatus setThickness(double thickness);

    //Acad::ErrorStatus setThumbnailBitmap(void* pBmp);//TODO:
    //Acad::ErrorStatus setThumbnailImage(const Atil::Image* pPreviewImage);//TODO:

    Acad::ErrorStatus setTilemode(bool mode);
    Acad::ErrorStatus setTimeZone(AcDb::TimeZone tz);//TODO: enum
    Acad::ErrorStatus setTimeZoneAsUtcOffset(double offset);
    Acad::ErrorStatus setTracewid(double width);
    Acad::ErrorStatus setTreedepth(Adesk::Int16 depth);
    Acad::ErrorStatus setTStackAlign(int val);
    Acad::ErrorStatus setTStackSize(int val);
    Acad::ErrorStatus setUcs(const AcGePoint3d& ucsOrigin, const AcGeVector3d& ucsXDir, const AcGeVector3d& ucsYDir);
    Acad::ErrorStatus setUcsBase(const PyDbObjectId& ucsid);
    Acad::ErrorStatus setUcsname(const PyDbObjectId& ucsRecId);
    Acad::ErrorStatus setUnitmode(Adesk::Int16 mode);
    Acad::ErrorStatus setUpdateThumbnail(Adesk::UInt8 val);

    Acad::ErrorStatus setUseri1(Adesk::Int16 val);
    Acad::ErrorStatus setUseri2(Adesk::Int16 val);
    Acad::ErrorStatus setUseri3(Adesk::Int16 val);
    Acad::ErrorStatus setUseri4(Adesk::Int16 val);
    Acad::ErrorStatus setUseri5(Adesk::Int16 val);

    Acad::ErrorStatus setUserr1(double val);
    Acad::ErrorStatus setUserr2(double val);
    Acad::ErrorStatus setUserr3(double val);
    Acad::ErrorStatus setUserr4(double val);
    Acad::ErrorStatus setUserr5(double val);

    Acad::ErrorStatus setUsrtimer(bool timer);
    Acad::ErrorStatus setVersionGuid(const std::string& pNewGuid);
    Acad::ErrorStatus setViewportScaleDefault(double newDefaultVPScale);
    Acad::ErrorStatus setVisretain(bool retain);
    Acad::ErrorStatus setWorldPucsBaseOrigin(const AcGePoint3d& origin, AcDb::OrthographicView orthoView);
    Acad::ErrorStatus setWorldUcsBaseOrigin(const AcGePoint3d& origin, AcDb::OrthographicView orthoView);
    Acad::ErrorStatus setWorldview(bool view);
    Acad::ErrorStatus setXclipFrame(Adesk::UInt8 disp);
    Acad::ErrorStatus setXrefEditEnabled(bool enable);

    Adesk::Int16 shadedge() const;
    Adesk::Int16 shadedif() const;
    double shadowPlaneLocation() const;
    Adesk::UInt8 showHist() const;
    double sketchinc() const;
    bool skpoly() const;
    Adesk::UInt8 solidHist() const;
    Adesk::UInt8 sortEnts() const;
    bool splframe() const;
    Adesk::Int16 splinesegs() const;
    Adesk::Int16 splinetype() const;
    double stepSize() const;
    double stepsPerSec() const;
    Adesk::Int16 surftab1() const;
    Adesk::Int16 surftab2() const;
    Adesk::Int16 surftype() const;
    Adesk::Int16 surfu() const;
    Adesk::Int16 surfv() const;
    PyDbObjectId tablestyle() const;
    PyDbObjectId tableStyleDictionaryId() const;
    //const AcDbDate tdcreate() const;
    //const AcDbDate tdindwg() const;/TODO:
    //const AcDbDate tducreate() const;/TODO:
    //const AcDbDate tdupdate() const/TODO:
    //const AcDbDate tdusrtimer() const;/TODO:
    //const AcDbDate tduupdate() const;//TODO:
    double textsize() const;

    PyDbObjectId textstyle() const;
    PyDbObjectId textStyleTableId() const;
    double thickness() const;

    //void* thumbnailBitmap() const maybe  //TODO:
    //Acad::ErrorStatus thumbnailImage(Atil::Image*& pPreviewImage) const; probably never
    bool tilemode() const;
    Adesk::UInt8 tileModeLightSynch() const;
    //TODO: enum
    AcDb::TimeZone timeZone() const;
    double tracewid() const;

    //AcDbTransactionManager* transactionManager() const; //TODO:
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

    Acad::ErrorStatus updateDataLink(AcDb::UpdateDirection nDir, AcDb::UpdateOption nOption);
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
    Acad::ErrorStatus wblock(PyDbDatabase& pOutputDb, const boost::python::list& outObjIds, const AcGePoint3d& basePoint);
    Acad::ErrorStatus wblock(PyDbDatabase& pOutputDb, const PyDbObjectId& blockId);
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


